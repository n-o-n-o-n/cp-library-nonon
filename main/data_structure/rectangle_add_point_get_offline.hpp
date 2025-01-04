#pragma once
#include <algorithm>
#include <vector>
#include "segtree/dual_segtree.hpp"
using namespace std;

template<typename Monoid, typename T = int>
struct rectangle_add_point_get {
    using S = typename Monoid::S;
    rectangle_add_point_get(int n = 0, int q = 0) {
        xl.reserve(n);
        yl.reserve(n);
        xr.reserve(n);
        yr.reserve(n);
        xq.reserve(q);
        yq.reserve(q);
        xs.reserve(2 * n + q);
        ys.reserve(2 * n + q);
        w.reserve(n);
    }
    void add_rectangle(T _xl, T _yl, T _xr, T _yr, S _w) {
        xl.emplace_back(_xl);
        yl.emplace_back(_yl);
        xr.emplace_back(_xr);
        yr.emplace_back(_yr);
        w.emplace_back(_w);
        xs.emplace_back(_xl);
        xs.emplace_back(_xr);
        ys.emplace_back(_yl);
        ys.emplace_back(_yr);
    }
    void add_query(T x, T y) {
        xq.emplace_back(x);
        yq.emplace_back(y);
        xs.emplace_back(x);
        ys.emplace_back(y);
    }
    vector<S> run() {
        int n = xl.size(), q = xq.size();
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        vector<vector<pair<int, int>>> adds_y(xs.size());
        vector<vector<S>> adds_w(xs.size());
        for (int i = 0; i < n; i++) {
            int l = lower_bound(xs.begin(), xs.end(), xl[i]) - xs.begin();
            int r = lower_bound(xs.begin(), xs.end(), xr[i]) - xs.begin();
            int d = lower_bound(ys.begin(), ys.end(), yl[i]) - ys.begin();
            int u = lower_bound(ys.begin(), ys.end(), yr[i]) - ys.begin();
            adds_y[l].emplace_back(d, u);
            adds_w[l].emplace_back(w[i]);
            adds_y[r].emplace_back(d, u);
            adds_w[r].emplace_back(-w[i]);
        }
        vector<vector<pair<int, int>>> qs(xs.size());
        for (int i = 0; i < q; i++) {
            int x = lower_bound(xs.begin(), xs.end(), xq[i]) - xs.begin();
            int y = lower_bound(ys.begin(), ys.end(), yq[i]) - ys.begin();
            qs[x].emplace_back(y, i);
        }
        d.init(vector<S>(ys.size(), 0));
        vector<S> res(q);
        for (int x = 0; x < (int)xs.size(); x++) {
            for (int y = 0; y < (int)adds_y[x].size(); y++) {
                auto [l, r] = adds_y[x][y];
                auto w = adds_w[x][y];
                d.apply(l, r, w);
            }
            for (auto [y, i] : qs[x]) {
                res[i] = d.get(y);
            }
        }
        return res;
    }
private:
    vector<T> xl, yl, xr, yr, xq, yq, xs, ys;
    vector<S> w;
    struct OpMonoid {
        using S = typename Monoid::S;
        static S e() {
            return Monoid::e();
        }
        using F = typename Monoid::S;
        static F comp(F f, F g) {
            return f + g;
        }
        static F id() {
            return 0;
        }
        static S mapping(F f, S x) {
            return f + x;
        }
    };
    dual_segtree<OpMonoid> d;
};