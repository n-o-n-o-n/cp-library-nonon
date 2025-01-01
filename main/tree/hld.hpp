#pragma once
#include <vector>
using namespace std;

template<typename D>
struct heavy_light_decomposition {
    template<template<typename> class SegTree, typename Monoid>
    static Monoid deduce_monoid(SegTree<Monoid>*) {
        return Monoid{};
    }
    using Monoid = decltype(deduce_monoid(static_cast<D*>(nullptr)));
    using S = typename Monoid::S;
    heavy_light_decomposition() = default;
    heavy_light_decomposition(int _n, bool _e, int r = 0) : n(_n), root(r), edge(_e), built(false), seg(n) {
        edges.reserve(n - 1);
    }
    void add_edge(int u, int v, const S &w = Monoid::e()) {
        edges.emplace_back(u, v, w);
    }
    vector<tuple<int, int, bool>> path_decompose(int u, int v) {
        build();
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        int hu = head[u], hv = head[v];
        vector<tuple<int, int, bool>> res;
        while (hu != hv) {
            bool flip = false;
            if (in[hu] > in[hv]) {
                swap(u, v);
                swap(hu, hv);
                flip = true;
            }
            res.emplace_back(in[hv], in[v] + 1, flip);
            v = par[hv];
            hu = head[u];
            hv = head[v];
        }
        bool flip = false;
        if (in[u] > in[v]) {
            swap(u, v);
            flip = true;
        }
        res.emplace_back(in[u] + edge, in[v] + 1, flip);
        return res;
    }
    int lca(int u, int v) {
        build();
        while (true) {
            if (in[u] > in[v]) swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
        return -1;
    }
    void set(int u, const S &w) {
        build();
        seg.set(idx(u), w);
    }
    void set(int u, int v, const S &w) {
        build();
        seg.set(idx(u, v), w);
    }
    template<typename F>
    void apply(int u, int v, const F &f) {
        build();
        for (const auto &[l, r, _] : path_decompose(u, v)) {
            seg.apply(l, r, f);
        }
    }
    S get(int u) {
        build();
        return seg.get(idx(u));
    }
    S get(int u, int v) {
        build();
        return seg.get(idx(u, v));
    }
    template<typename L>
    S prod(int u, int v, const L &rev) {
        build();
        S pl = Monoid::e(), pr = Monoid::e();
        bool flip = false;
        for (const auto &[l, r, flag] : path_decompose(u, v)) {
            if (flag) {
                flip = !flip;
                swap(pl, pr);
            }
            pr = Monoid::op(seg.prod(l, r), pr);
        }
        pr = Monoid::op(rev(pl), pr);
        return flip ? rev(pr) : pr;
    }
    S prod(int u, int v) {
        return prod(u, v, [&](const S &w){ return w; });
    }
private:
    int n, root, id;
    bool edge, built;
    D seg;
    vector<vector<int>> g;
    vector<int> sub, depth, par, in, out, head, heavy;
    vector<tuple<int, int, S>> edges;
    int idx(int u) {
        return in[u];
    }
    int idx(int u, int v) {
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
        if (heavy[u] != -1) decompose(heavy[u], h);
        for (int v : g[u]) {
            if (v != par[u] && v != heavy[u]) {
                decompose(v, v);
            }
        }
        out[u] = id;
    }
    void build() {
        if (built) return;
        g = vector<vector<int>>(n);
        sub = vector<int>(n);
        depth = vector<int>(n);
        par = vector<int>(n, -1);
        in = vector<int>(n);
        out = vector<int>(n);
        head = vector<int>(n);
        heavy = vector<int>(n, -1);
        for (const auto &[u, v, _] : edges) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        id = 0;
        dfs(root, root);
        decompose(root, root);
        if (edge) {
            for (const auto &[u, v, w] : edges) {
                seg.set(idx(u, v), w);
            }
        }
        built = true;
    }
};