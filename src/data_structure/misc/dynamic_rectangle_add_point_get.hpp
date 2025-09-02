#pragma once
#include "static_rectangle_add_point_get.hpp"

template<typename Abelian_Group, typename T = int>
struct dynamic_rectangle_add_point_get {
    using M = Abelian_Group;
    using S = typename M::S;
    dynamic_rectangle_add_point_get() = default;
    dynamic_rectangle_add_point_get(int n, int q) {
        types.reserve(n + q);
        rectangles.reserve(n);
        get_querys.reserve(q);
    }
    void rectangle_add_query(T xl, T yl, T xr, T yr, const S &w) {
        types.emplace_back(false);
        rectangles.emplace_back(xl, yl, xr, yr, w);
    }
    void point_get_query(T x, T y) {
        types.emplace_back(true);
        get_querys.emplace_back(x, y);
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
            static_rectangle_add_point_get<Abelian_Group, T> rs(tn, tq);
            for (int i = l; i < m; i++) {
                if (!types[i]) {
                    auto [xl, yl, xr, yr, w] = rectangles[inv[i]];
                    rs.add_rectangle(xl, yl, xr, yr, w);
                }
            }
            for (int i = m; i < r; i++) {
                if (types[i]) {
                    auto [x, y] = get_querys[inv[i]];
                    rs.add_query(x, y);
                }
            }
            auto sub = rs.solve();
            for (int i = m, j = 0; i < r; i++) {
                if (types[i]) {
                    res[inv[i]] = M::op(res[inv[i]], sub[j++]);
                }
            }
        };
        rec(rec, 0, sz);
        return res;
    }
private:
    vector<bool> types;
    vector<tuple<T, T, T, T, S>> rectangles;
    vector<tuple<T, T>> get_querys;
};