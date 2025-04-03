#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;
#include "../data_structure/sparse_table/sparse_table.hpp"

struct static_tree {
    static_tree() = default;
    static_tree(int _n, int r = 0) : n(_n), root(r), g(_n), built(false) {}
    void add_edge(int u, int v) {
        assert(!built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> &operator[](int u) {
        return g[u];
    }
    int depth(int u) {
        build();
        return d[u];
    }
    int lca(int u, int v, int r = -1) {
        build();
        if (r == -1) {
            auto [l, r] = minmax({in[u], in[v]});
            return st.prod(l, r + 1).second;
        }
        return lca(u, v) ^ lca(v, r) ^ lca(r, u);
    }
    int dist(int u, int v) {
        build();
        int w = lca(u, v);
        return d[u] + d[v] - 2 * d[w];
    }
    int jump(int u, int v, int k) {
        build();
        int w = lca(u, v);
        if (d[u] + d[v] - 2 * d[w] < k) return -1;
        if (d[u] - d[w] < k) {
            swap(u, v);
            k = d[u] + d[v] - 2 * d[w] - k;
        }
        k = d[u] - k;
        return *prev(upper_bound(list[k].begin(), list[k].end(), u, [&](int i, int j) {
            return in[i] < in[j];
        }));
    }
private:
    struct Monoid {
        using S = pair<int, int>;
        static S op(S a, S b) {
            return min(a, b);
        }
        static S e() {
            return make_pair(1 << 30, -1);
        }
    };
    int n, root;
    vector<vector<int>> g, list;
    bool built;
    vector<int> d, ord, in;
    sparse_table<Monoid> st;
    void dfs(int u, int p) {
        ord.push_back(u);
        list[d[u]].push_back(u);
        for (int v : g[u]) {
            if (v != p) {
                d[v] = d[u] + 1;
                dfs(v, u);
                ord.push_back(u);
            }
        }
    }
    void build() {
        if (built) return;
        d = vector<int>(n, 0);
        ord.reserve(2 * n);
        list = vector<vector<int>>(n);
        dfs(root, root);
        in = vector<int>(n, -1);
        st = sparse_table<Monoid>(ord.size());
        for (int i = 0; i < (int)ord.size(); i++) {
            int u = ord[i];
            if (in[u] == -1) in[u] = i;
            st.set(i, make_pair(d[u], u));
        }
        built = true;
    }
};