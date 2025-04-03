#pragma once
#include <vector>
#include <queue>
using namespace std;

struct tree_matching {
    tree_matching(int n) : g(n) {}
    tree_matching(const vector<vector<int>> &_g) : g(_g) {}
    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<pair<int, int>> matching() {
        int n = g.size();
        par = vector<int>(n);
        auto dfs = [&](const auto &dfs, int u, int p) -> void {
            par[u] = p;
            for (int v : g[u]) {
                if (v != p) {
                    dfs(dfs, v, u);
                }
            }
        };
        dfs(dfs, 0, -1);
        queue<int> q;
        deg = vector<int>(n);
        for (int i = 0; i < n; i++) {
            deg[i] = g[i].size();
            if (deg[i] == 1) {
                q.push(i);
            }
        }
        used = vector<bool>(n, false);
        vector<pair<int, int>> res;
        res.reserve(n / 2);
        while (q.size()) {
            int u = q.front();
            q.pop();
            int p = par[u];
            if (p >= 0) {
                deg[p]--;
                if (deg[p] == 1) q.push(p);
                if (used[u] || used[p]) continue;
                used[p] = used[u] = true;
                res.emplace_back(p, u);
            }
        }
        return res;
    }
private:
    vector<vector<int>> g;
    vector<int> par, deg;
    vector<bool> used;
};