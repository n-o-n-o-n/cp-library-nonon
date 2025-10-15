#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

struct scc_graph {
    scc_graph(int _n = 0) : n(_n), g(_n), g_rev(_n) {}
    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        g[u].push_back(v);
        g_rev[v].push_back(u);
    }
    vector<vector<int>> scc() {
        id = vector<int>(n, -1);
        vis = vector<bool>(n);
        ord.reserve(n);
        for (int i = 0; i < n; i++) dfs(i);
        reverse(ord.begin(), ord.end());
        int k = 0;
        for (int u : ord) {
            if (id[u] == -1) {
                sfd(u, k++);
            }
        }
        vector<vector<int>> res(k);
        for (int i = 0; i < n; i++) {
            res[id[i]].push_back(i);
        }
        return res;
    }
private:
    int n;
    vector<vector<int>> g, g_rev;
    vector<int> id, ord;
    vector<bool> vis;
    void dfs(int u) {
        if (vis[u]) return;
        vis[u] = true;
        for (int v : g[u]) dfs(v);
        ord.push_back(u);
    }
    void sfd(int u, int k) {
        if (id[u] != -1) return;
        id[u] = k;
        for (int v : g_rev[u]) sfd(v, k);
    }
};