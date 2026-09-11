#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

struct offline_dag_reachability {
    offline_dag_reachability(int _n) : n(_n), q(0), g(_n), g_rev(_n), qs(_n) {}
    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        g[u].push_back(v);
        g_rev[v].push_back(u);
    }
    void add_query(int u, int v) {
        qs[u].emplace_back(v, q++);
    }
    vector<bool> solve() {
        scc_build();
        vector<vector<int>> h(m);
        for (int u = 0; u < n; u++) {
            for (int v : g[u]) {
                if (id[u] != id[v]) h[id[u]].push_back(id[v]);
            }
        }
        for (auto &e : h) {
            sort(e.begin(), e.end());
            e.erase(unique(e.begin(), e.end()), e.end());
        }
        vector<vector<pair<int, int>>> qs2(m);
        for (int i = 0; i < n; i++) {
            for (auto [j, k] : qs[i]) {
                qs2[id[j]].emplace_back(id[i], k);
            }
        }
        vector<bool> res(q);
        for (int l = 0; l < m; l += w) {
            int r = min(l + w, m);
            vector<unsigned long long> dp(m);
            for (int i = m - 1; i >= 0; i--) {
                if (l <= i && i < r) dp[i] |= 1ULL << (i - l);
                for (int j : h[i]) dp[i] |= dp[j];
            }
            for (int i = l; i < r; i++) {
                for (auto [j, k] : qs2[i]) {
                    res[k] = dp[j] >> (i - l) & 1;
                }
            }
        }
        return res;
    }
private:
    static constexpr int w = 64;
    int n, q, m;
    vector<vector<int>> g, g_rev;
    vector<int> id, ord;
    vector<bool> vis;
    vector<vector<pair<int, int>>> qs;
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
    void scc_build() {
        id = vector<int>(n, -1);
        vis = vector<bool>(n);
        ord.reserve(n);
        for (int i = 0; i < n; i++) dfs(i);
        reverse(ord.begin(), ord.end());
        m = 0;
        for (int u : ord) {
            if (id[u] == -1) {
                sfd(u, m++);
            }
        }
    }
};