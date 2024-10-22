#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename Monoid>
struct hld_template {
    using S = typename Monoid::S;
    hld_template() = default;
    hld_template(int _n, bool _e, int r = 0) : n(_n), root(r), edge(_e), built(false) {}
    void add_edge(int u, int v, const S &w) {
        assert(!built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        edges.emplace_back(u, v, w);
    }
    vector<S> rearrange(vector<S> a) {
        build();
        if (a.empty()) {
            a.resize(n, Monoid::e());
            for (const auto &[u, v, w] : edges) {
                a[idx(u, v)] = w;
            }
            return a;
        }
        vector<S> b(n);
        for (int i = 0; i < n; i++) b[idx(i)] = a[i];
        return b;
    }
    int idx(int u) {
        build();
        return in[u];
    }
    int idx(int u, int v) {
        build();
        return max(in[u], in[v]);
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
private:
    int n, root, id;
    bool edge, built;
    vector<vector<int>> g;
    vector<int> sub, depth, par, in, out, head, heavy;
    vector<tuple<int, int, S>> edges;
    void dfs(int u, int p) {
        par[u] = p;
        sub[u] = 1;
        int sub_max = 0;
        for (int v : g[u]) {
            if (v == p) continue;
            dfs(v, u);
            sub[u] += sub[v];
            if (sub[v] > sub_max) {
                sub_max = sub[v];
                heavy[u] = v;
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
        g.resize(n);
        sub.resize(n);
        depth.resize(n);
        par.resize(n, -1);
        in.resize(n);
        out.resize(n);
        head.resize(n);
        heavy.resize(n, -1);
        if (edges.size()) {
            assert(int(edges.size()) + 1 == n);
            for (auto [u, v, w] : edges) {
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        id = 0;
        dfs(root, root);
        decompose(root, root);
        built = true;
    }
};