#pragma once
#include <algorithm>
#include <vector>
using namespace std;
#include "segtree.hpp"

template<typename Monoid, typename T = int>
struct range_tree {
    using M = Monoid;
    using S = typename M::S;
    range_tree(int _n = 0) : n(-1) { pts.reserve(_n); }
    range_tree(const vector<tuple<T, T, S>> &p) : n(-1), pts(p) {}
    void add_point(T x, T y, const S &w = M::e()) {
        pts.emplace_back(x, y, w);
    }
    void set(T x, T y, const S &w) {
        build();
        int i = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        assert(xs[i] == x);
        i += sz;
        int j = lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();
        segs[i].set(j, w);
        while (i >>= 1) {
            int j = lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();
            segs[i].set(j, M::op(get_val(2 * i, y), get_val(2 * i + 1, y)));
        }
    }
    S get(T x, T y) {
        build();
        int i = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        if (i >= (int)xs.size() || xs[i] != x) return M::e();
        i += sz;
        int j = lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();
        if (j >= (int)ys[i].size() || ys[i][j] != y) return M::e();
        return segs[i].get(j);
    }
    S prod(T xl, T yl, T xr, T yr) {
        build();
        int il = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();
        int ir = lower_bound(xs.begin(), xs.end(), xr) - xs.begin();
        il += sz;
        ir += sz;
        S p = M::e();
        while (il < ir) {
            if (il & 1) p = M::op(p, inner_prod(il++, yl, yr));
            if (ir & 1) p = M::op(p, inner_prod(--ir, yl, yr));
            il >>= 1;
            ir >>= 1;
        }
        return p;
    }
private:
    int n, sz;
    vector<tuple<T, T, S>> pts;
    vector<T> xs;
    vector<vector<T>> ys;
    vector<vector<pair<T, S>>> ws;
    vector<segtree<M>> segs;
    S get_val(int i, T y) {
        int j = lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();
        return j < (int)ys[i].size() && ys[i][j] == y ? segs[i].get(j) : M::e();
    }
    S inner_prod(int i, T yl, T yr) {
        int jl = lower_bound(ys[i].begin(), ys[i].end(), yl) - ys[i].begin();
        int jr = lower_bound(ys[i].begin(), ys[i].end(), yr) - ys[i].begin();
        return segs[i].prod(jl, jr);
    }
    void build() {
        if (n != -1) return;
        for (const auto &[x, y, w] : pts) {
            xs.emplace_back(x);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        n = xs.size();
        sz = 1;
        while (sz < n) sz <<= 1;
        ys = vector<vector<T>>(2 * sz);
        ws = vector<vector<pair<T, S>>>(2 * sz);
        segs = vector<segtree<M>>(2 * sz);
        for (const auto &[x, y, w] : pts) {
            int p = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
            p += sz;
            ys[p].emplace_back(y);
            ws[p].emplace_back(y, w);
        }
        for (int i = sz; i < sz + n; i++) {
            sort(ys[i].begin(), ys[i].end());
            ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());
            vector<S> v(ys[i].size(), M::e());
            for (const auto &[y, w] : ws[i]) {
                int j = lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();
                v[j] = M::op(v[j], w);
                ws[i >> 1].emplace_back(y, w);
            }
            segs[i] = segtree<M>(v);
        }
        for (int i = sz - 1; i >= 1; i--) {
            const auto &yl = ys[2 * i];
            const auto &yr = ys[2 * i + 1];
            merge(yl.begin(), yl.end(), yr.begin(), yr.end(), back_inserter(ys[i]));
            ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());
            vector<S> v(ys[i].size(), M::e());
            for (const auto &[y, w] : ws[i]) {
                int j = lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();
                v[j] = M::op(v[j], w);
                ws[i >> 1].emplace_back(y, w);
            }
            segs[i] = segtree<M>(v);
        }
    }
};