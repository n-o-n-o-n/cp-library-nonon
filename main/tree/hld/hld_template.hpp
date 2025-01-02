#pragma once
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
    S subtree_prod(int u) {
        assert(built);
        assert(0 <= u && u < n);
        return seg.prod(in[u] + edge, out[u]);
    }
private:
    int n, r, id;
    bool edge, built;
    SegTree<Monoid> seg;
    vector<vector<int>> g;
    vector<int> sub, depth, par, in, out, head, heavy;
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
};