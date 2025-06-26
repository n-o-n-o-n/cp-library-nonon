#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

template<typename SegTree, bool edge, bool commutative>
struct heavy_light_decomposition {
    using M = typename SegTree::M;
    using S = typename M::S;
    heavy_light_decomposition() = default;
    heavy_light_decomposition(int _n, int _r = 0) : n(_n), r(_r), id(0), built(false) {
        edges.reserve(n - 1);
        if (n <= 1) build();
    }
    void add_edge(int u, int v, const S &w = M::e()) {
        assert(!built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(u != v);
        edges.emplace_back(u, v, w);
        if (ssize(edges) + 1 == n) build();
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
        assert(u != v);
        seg.set(idx(u, v), w);
    }
    template<typename F>
    void apply(int u, int v, const F &f) {
        assert(built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        for (auto [l, r] : path_decompose(u, v)) {
            if (l > r) swap(l, r);
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
        assert(u != v);
        return seg.get(idx(u, v));
    }
    S prod(int u, int v) {
        assert(built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        S p = M::e();
        for (auto [l, r] : path_decompose(u, v)) {
            p = M::op(p, inner_prod(l, r));
        }
        return p;
    }
    S subtree_prod(int u) {
        assert(built);
        assert(0 <= u && u < n);
        return seg.prod(in[u] + edge, out[u]);
    }
    template<typename C>
    int binary_search(int u, int v, const C &check) {
        assert(built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        S p = M::e();
        for (auto [l, r] : path_decompose(u, v)) {
            S np = M::op(p, inner_prod(l, r));
            if (l < r) {
                if (!check(np)) {
                    return check(M::op(p, seg.get(l))) ? inv[
                        (commutative ? seg.max_right(l, [&](const S &x) {
                            return check(M::op(p, x));
                        }) : seg.max_right(l, false, [&](const S &x) {
                            return check(M::op(p, x));
                        })) - 1
                    ] : u;
                }
                p = np;
                u = inv[r - 1];
            } else {
                swap(l, r);
                if (!check(np)) {
                    return check(M::op(p, seg.get(r - 1))) ? inv[
                        commutative ? seg.min_left(r, [&](const S &x) {
                            return check(M::op(p, x));
                        }) : seg.min_left(r, true, [&](const S &x) {
                            return check(M::op(p, x));
                        })
                    ] : u;
                }
                p = np;
                u = inv[l];
            }
        }
        return v;
    }
private:
    int n, r, id;
    bool built;
    SegTree seg;
    vector<vector<int>> g;
    vector<int> sub, depth, par, in, out, inv, head, heavy;
    vector<tuple<int, int, S>> edges;
    int idx(int u) const {
        assert(built);
        return in[u];
    }
    int idx(int u, int v) const {
        assert(built);
        return max(in[u], in[v]);
    }
    S inner_prod(int l, int r) {
        if (commutative && l > r) swap(l, r);
        return seg.prod(l, r);
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
        sub = depth = in = inv = out = head = vector<int>(n);
        par = heavy = vector<int>(n, -1);
        for (const auto &[u, v, _] : edges) {
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(r, r);
        decompose(r, r);
        built = true;
        if (edge) {
            vector<S> a(n, M::e());
            for (const auto &[u, v, w] : edges) {
                a[idx(u, v)] = w;
            }
            seg = SegTree(a);
        } else {
            seg = SegTree(n);
        }
    }
    vector<pair<int, int>> path_decompose(int u, int v) const {
        assert(built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        int hu = head[u], hv = head[v];
        vector<pair<int, int>> resl, resr;
        bool flip = true;
        while (hu != hv) {
            if (in[hu] > in[hv]) {
                flip = !flip;
                swap(u, v);
                swap(hu, hv);
                swap(resl, resr);
            }
            resl.emplace_back(in[hv], in[v] + 1);
            v = par[hv];
            hu = head[u];
            hv = head[v];
        }
        if (in[u] > in[v]) {
            flip = !flip;
            swap(u, v);
            swap(resl, resr);
        }
        resl.emplace_back(in[u] + edge, in[v] + 1);
        if (flip) swap(resl, resr);
        reverse(resr.begin(), resr.end());
        vector<pair<int, int>> res;
        for (auto [l, r] : resl) res.emplace_back(r, l);
        for (auto [l, r] : resr) res.emplace_back(l, r);
        return res;
    }
};