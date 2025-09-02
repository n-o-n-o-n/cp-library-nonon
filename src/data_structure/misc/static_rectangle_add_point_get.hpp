#pragma once
#include <numeric>
#include <ranges>
#include <vector>
#include "../../misc/merge_and_unique.hpp"
#include "../segtree/range_add_fenwick_tree_abelian_group.hpp"
using namespace std;

template<typename Abelian_Group, typename T = int>
struct static_rectangle_add_point_get {
    using M = Abelian_Group;
    using S = typename M::S;
    static_rectangle_add_point_get() = default;
    static_rectangle_add_point_get(int n, int q) {
        xls.reserve(n);
        yls.reserve(n);
        xrs.reserve(n);
        yrs.reserve(n);
        ws.reserve(n);
        xs.reserve(q);
        ys.reserve(q);
    }
    void add_rectangle(T xl, T yl, T xr, T yr, const S &w) {
        xls.emplace_back(xl);
        yls.emplace_back(yl);
        xrs.emplace_back(xr);
        yrs.emplace_back(yr);
        ws.emplace_back(w);
    }
    void add_query(T x, T y) {
        xs.emplace_back(x);
        ys.emplace_back(y);
    }
    vector<S> solve() {
        int n = xls.size(), q = xs.size();
        auto yb = merge_and_unique(ys);
        vector<tuple<int, int, T, S>> rs;
        rs.reserve(2 * n);
        for (int i = 0; i < n; i++) {
            int l = lower_bound(yb.begin(), yb.end(), yls[i]) - yb.begin();
            int r = lower_bound(yb.begin(), yb.end(), yrs[i]) - yb.begin();
            rs.emplace_back(l, r, xls[i], ws[i]);
            rs.emplace_back(l, r, xrs[i], M::inv(ws[i]));
        }
        sort(rs.begin(), rs.end(), [&] (auto a, auto b) {
            return get<2>(a) < get<2>(b);
        });
        vector<int> ord(q);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&] (int i, int j) {
            return xs[i] < xs[j];
        });
        range_add_fenwick_tree<Abelian_Group> fw(yb.size());
        vector<S> res(q);
        int j = 0;
        for (int i : ord) {
            while (j < 2 * n && get<2>(rs[j]) <= xs[i]) {
                auto [l, r, _, w] = rs[j++];
                fw.add(l, r, w);
            }
            int y = lower_bound(yb.begin(), yb.end(), ys[i]) - yb.begin();
            res[i] = fw.prod(y, y + 1);
        }
        return res;
    }
private:
    vector<T> xls, yls, xrs, yrs, xs, ys;
    vector<S> ws;
};