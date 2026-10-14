#pragma once
#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#include "../data_structure/segtree/static_rmq.hpp"

struct static_tree {
    static_tree() = default;
    static_tree(int _n, int r = 0) : n(_n), e(0), root(r), g(_n), built(false) {
        if (n <= 1) build();
    }
    void set_root(int r) {
        assert(0 <= r && r < n);
        root = r;
        built = false;
        build();
    }
    void add_edge(int u, int v) {
        assert(!built);
        assert(e < n - 1);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        g[u].push_back(v);
        g[v].push_back(u);
        if (++e == n - 1) build();
    }
    void read_edges(bool idx = 1) {
        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            u -= idx;
            v -= idx;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        build();
    }
    vector<int> &operator[](int u) {
        assert(0 <= u && u < n);
        return g[u];
    }
    int depth(int u) const {
        assert(built);
        assert(0 <= u && u < n);
        return d[u];
    }
    int lca(int u, int v, int r = -1) const {
        assert(built);
        assert(0 <= u && u < n);
        if (r == -1) {
            auto [kl, kr] = minmax(in[u], in[v]);
            return get<2>(st.prod(kl, kr + 1));
        }
        assert(0 <= r && r < n);
        return lca(u, v) ^ lca(v, r) ^ lca(r, u);
    }
    int dist(int u, int v) const {
        assert(built);
        int w = lca(u, v);
        return d[u] + d[v] - 2 * d[w];
    }
    int jump(int u, int v, int k) const {
        assert(built);
        int w = lca(u, v);
        if (d[u] + d[v] - 2 * d[w] < k) return -1;
        if (d[u] - d[w] < k) {
            swap(u, v);
            k = d[u] + d[v] - 2 * d[w] - k;
        }
        k = d[u] - k;
        return *prev(upper_bound(list[k].begin(), list[k].end(), u, [&] (int i, int j) {
            return in[i] < in[j];
        }));
    }
    bool is_on_path(int w, int u, int v) const {
        assert(built);
        assert(0 <= w && w < n);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        return lca(u, v, w) == w;
    }
    int sub_size(int u, int r = -1) const {
        assert(built);
        assert(0 <= u && u < n);
        if (r == -1) r = root;
        assert(0 <= r && r < n);
        if (r == u) return n;
        if (lca(u, r) != u) return sz[u];
        auto [kl, kr] = minmax(in[u], in[r]);
        return n - sz[ord[1 - get<1>(st.prod(kl, kr + 1))]];
    }
    vector<int> path(int u, int v) const {
        assert(built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        int w = lca(u, v);
        vector<int> pu, pv;
        while (u != w) {
            pu.push_back(u);
            u = ord[in[u] - 1];
        }
        while (v != w) {
            pv.push_back(v);
            v = ord[in[v] - 1];
        }
        reverse(pv.begin(), pv.end());
        pu.push_back(w);
        pu.insert(pu.end(), pv.begin(), pv.end());
        return pu;
    }
    vector<pair<int, int>> auxiliary_tree(vector<int> vs) const {
        if (vs.empty()) return {};
        sort(vs.begin(), vs.end(), [&] (int u, int v) {
            return in[u] < in[v];
        });
        vs.erase(unique(vs.begin(), vs.end()), vs.end());
        vector<pair<int, int>> res;
        stack<int> st;
        st.push(vs[0]);
        for (int i = 1; i < ssize(vs); i++) {
            int w = lca(vs[i - 1], vs[i]);
            if (w != vs[i - 1]) {
                int u = st.top();
                st.pop();
                while (st.size() && d[w] < d[st.top()]) {
                    res.emplace_back(u, st.top());
                    u = st.top();
                    st.pop();
                }
                res.emplace_back(u, w);
                if (st.empty() || st.top() != w) st.push(w);
            }
            st.push(vs[i]);
        }
        while (st.size() > 1) {
            int u = st.top();
            st.pop();
            res.emplace_back(u, st.top());
        }
        return res;
    }
private:
    struct Monoid {
        using S = tuple<int, int, int>;
        static S op(S a, S b) {
            return min(a, b);
        }
        static S e() {
            return make_tuple(1 << 30, 1 << 30, -1);
        }
    };
    int n, e, root;
    vector<vector<int>> g, list;
    bool built;
    vector<int> d, ord, in, sz;
    static_rmq<Monoid> st;
    int dfs(int u, int p) {
        ord.push_back(u);
        list[d[u]].push_back(u);
        for (int v : g[u]) {
            if (v != p) {
                d[v] = d[u] + 1;
                sz[u] += dfs(v, u);
                ord.push_back(u);
            }
        }
        return ++sz[u];
    }
    void build() {
        if (built) return;
        d = vector<int>(n, 0);
        sz = vector<int>(n, 0);
        ord.reserve(2 * n);
        list = vector<vector<int>>(n);
        dfs(root, root);
        in = vector<int>(n, -1);
        st = static_rmq<Monoid>([&]{
            vector<Monoid::S> a(ord.size());
            for (int i = 0; i < ssize(ord); i++) {
                int u = ord[i];
                if (in[u] == -1) in[u] = i;
                a[i] = make_tuple(d[u], -i, u);
            }
            return a;
        }());
        built = true;
    }
};