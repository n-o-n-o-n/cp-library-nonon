#pragma once
#include <cassert>
#include <vector>
#include "rectangle_sum.hpp"

template<typename Abelian_Group, typename T = int>
struct point_add_rectangle_sum {
    using M = Abelian_Group;
    using S = typename M::S;
    point_add_rectangle_sum() : point_add_rectangle_sum(0, 0) {}
    point_add_rectangle_sum(int n, int q) {
        types.reserve(n + q);
        update_querys.reserve(n);
        sum_querys.reserve(q);
    }
    void add_update_querys(T x, T y, const S &w) {
        types.emplace_back(false);
        update_querys.emplace_back(x, y, w);
    }
    void add_sum_query(T xl, T yl, T xr, T yr) {
        assert(xl <= xr);
        assert(yl <= yr);
        types.emplace_back(true);
        sum_querys.emplace_back(xl, yl, xr, yr);
    }
    vector<S> solve() {
        int sz = types.size(), n = 0, q = 0;
        vector<int> inv(sz, -1);
        for (int i = 0; i < sz; i++) {
            inv[i] = (types[i] ? q++ : n++);
        }
        vector<S> res(q, M::e());
        auto rec = [&] (const auto &rec, int l, int r) -> void {
            if (l + 1 >= r) return;
            int m = (l + r) / 2;
            rec(rec, l, m);
            rec(rec, m, r);
            int tn = 0, tq = 0;
            for (int i = l; i < r; i++) {
                (types[i] ? tq : tn)++;
            }
            rectangle_sum<Abelian_Group, T> rs(tn, tq);
            for (int i = l; i < m; i++) {
                if (!types[i]) {
                    auto [x, y, w] = update_querys[inv[i]];
                    rs.add_point(x, y, w);
                }
            }
            for (int i = m; i < r; i++) {
                if (types[i]) {
                    auto [xl, yl, xr, yr] = sum_querys[inv[i]];
                    rs.add_query(xl, yl, xr, yr);
                }
            }
            auto sub = rs.solve();
            for (int i = m, j = 0; i < r; i++) {
                if (types[i]) {
                    assert(inv[i] != -1);
                    res[inv[i]] += sub[j++];
                }
            }
        };
        rec(rec, 0, sz);
        return res;
    }
private:
    int n, q;
    vector<bool> types;
    vector<tuple<T, T, S>> update_querys;
    vector<tuple<T, T, T, T>> sum_querys;
};