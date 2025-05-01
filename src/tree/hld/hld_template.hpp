#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

template<template<typename> class SegTree, typename Monoid>
struct hld_template {
    using S = typename Monoid::S;
    hld_template() = default;
    hld_template(int _n, bool _e, int _r) : n(_n), r(_r), edge(_e), built(false), seg(_n) {
        edges.reserve(n - 1);
        if (n <= 1) build();
    }
    void add_edge(int u, int v, const S &w = Monoid::e()) {
        assert(!built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        edges.emplace_back(u, v, w);
        if ((int)edges.size() == n - 1) build();
    }
    int lca(int u, int v) {
        assert(built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        while (true) {
            if (in[u] > in[v]) swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
        return -1;
    }
    void set(int u, const S &w) {
        assert(built);
        assert(0 <= u && u < n);
        seg.set(idx(u), w);
    }
    void set(int u, int v, const S &w) {
        assert(built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        seg.set(idx(u, v), w);
    }
    template<typename F>
    void apply(int u, int v, const F &f) {
        assert(built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        for (const auto &[l, r, _] : path_decompose(u, v)) {
            seg.apply(l, r, f);
        }
    }
    template<typename F>
    void subtree_apply(int u, const F &f) {
        assert(built);
        assert(0 <= u && u < n);
        seg.apply(in[u] + edge, out[u], f);
    }
    S get(int u) {
        assert(built);
        assert(0 <= u && u < n);
        return seg.get(idx(u));
    }
    S get(int u, int v) {
        assert(built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        return seg.get(idx(u, v));
    }
    template<typename L>
    S prod(int u, int v, const L &rev) {
        assert(built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        S p = Monoid::e();
        for (auto [l, r, flag] : path_decompose(u, v)) {
            cout << l << ' ' << r << ' ' << flag << endl;
            S sub_p = seg.prod(l, r);
            auto q = flag ? rev(sub_p) : sub_p;
            cout << q.first.a.val() << ' ' << q.first.b.val() << endl;
            p = Monoid::op(p, flag ? rev(sub_p) : sub_p);
            cout << p.first.a.val() << ' ' << p.first.b.val() << endl;
        }
        return p;
    }
    S subtree_prod(int u) {
        assert(built);
        assert(0 <= u && u < n);
        return seg.prod(in[u] + edge, out[u]);
    }
    template<typename C, typename L>
    int binary_search(int u, int v, const C &check, const L &rev) {
        assert(built);
        assert(check(Monoid::e()));
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        S p = Monoid::e();
        for (auto [l, r, flag] : path_decompose(u, v)) {
            if (flag) {
                S np = Monoid::op(p, rev(seg.prod(l, r)));
                if (!check(np)) {
                    if (!check(Monoid::op(p, rev(seg.get(r - 1))))) {
                        return u;
                    }
                    return inv[
                        seg.min_left(r, [&](const S &x) {
                            return check(Monoid::op(p, rev(x)));
                        })
                    ];
                }
                p = np;
                u = inv[l];
            } else {
                S np = Monoid::op(p, seg.prod(l, r));
                if (!check(np)) {
                    if (!check(Monoid::op(p, seg.get(l)))) {
                        return u;
                    }
                    return inv[
                        seg.max_right(l, [&](const S &x) {
                            return check(Monoid::op(p, x));
                        }) - 1
                    ];
                }
                p = np;
                u = inv[r - 1];
            }
        }
        return v;
    }
private:
    int n, r, id;
    bool edge, built;
    SegTree<Monoid> seg;
    vector<vector<int>> g;
    vector<int> sub, depth, par, in, inv, out, head, heavy;
    vector<tuple<int, int, S>> edges;
    int idx(int u) {
        assert(built);
        return in[u];
    }
    int idx(int u, int v) const {
        assert(built);
        return max(in[u], in[v]);
    }
    void dfs(int u, int p) {
        par[u] = p;
        sub[u] = 1;
        int sub_max = 0;
        for (int v : g[u]) {
            if (v != p) {
                dfs(v, u);
                sub[u] += sub[v];
                if (sub[v] > sub_max) {
                    sub_max = sub[v];
                    heavy[u] = v;
                }
            }
        }
    }
    void decompose(int u, int h) {
        head[u] = h;
        in[u] = id++;
        inv[in[u]] = u;
        if (heavy[u] != -1) decompose(heavy[u], h);
        for (int v : g[u]) {
            if (v != par[u] && v != heavy[u]) {
                decompose(v, v);
            }
        }
        out[u] = id;
    }
    void build() {
        g = vector<vector<int>>(n);
        sub = vector<int>(n);
        depth = vector<int>(n);
        par = vector<int>(n, -1);
        in = vector<int>(n);
        inv = vector<int>(n);
        out = vector<int>(n);
        head = vector<int>(n);
        heavy = vector<int>(n, -1);
        for (const auto &[u, v, _] : edges) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        id = 0;
        dfs(r, r);
        decompose(r, r);
        built = true;
        if (edge) {
            for (const auto &[u, v, w] : edges) {
                seg.set(idx(u, v), w);
            }
        }
    }
    vector<tuple<int, int, bool>> path_decompose(int u, int v) {
        assert(built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        int hu = head[u], hv = head[v];
        vector<tuple<int, int>> resl, resr;
        bool flip = true;
        while (hu != hv) {
            bool flag = false;
            if (in[hu] > in[hv]) {
                swap(u, v);
                swap(hu, hv);
                flag = true;
            }
            if (flag) {
                flip = !flip;
                swap(resl, resr);
            }
            resl.emplace_back(in[hv], in[v] + 1);
            v = par[hv];
            hu = head[u];
            hv = head[v];
        }
        bool flag = false;
        if (in[u] > in[v]) {
            swap(u, v);
            flag = true;
        }
        if (flag) {
            flip = !flip;
            swap(resl, resr);
        }
        resl.emplace_back(in[u] + edge, in[v] + 1);
        if (flip) swap(resl, resr);
        reverse(resr.begin(), resr.end());
        vector<tuple<int, int, bool>> res;
        for (auto [l, r] : resl) res.emplace_back(l, r, true);
        for (auto [l, r] : resr) res.emplace_back(l, r, false);
        return res;
    }
};