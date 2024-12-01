#pragma once
#include <queue>
#include <vector>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

struct bipartite_matching {
    int n, m;
    bipartite_matching(int _n, int _m) : n(_n), m(_m), g(_n), match(_m, -1), used(_n) {}
    void add_edge(int u, int v) {
        g[u].push_back(v);
    }
    vector<pair<int, int>> matching() {
        build();
        vector<pair<int, int>> res;
        for (int i = 0; i < m; i++) {
            if (match[i] != -1) {
                res.emplace_back(match[i], i);
            }
        }
        return res;
    }
private:
    vector<vector<int>> g;
    vector<int> match, dist;
    vector<bool> vis, used;
    void bfs() {
        dist = vector<int>(n, 1 << 30);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                q.push(i);
                dist[i] = 0;
            }
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                int w = match[v];
                if (0 <= w && dist[w] == 1 << 30) {
                    dist[w] = dist[u] + 1;
                    q.push(w);
                }
            }
        }
    }
    bool dfs(int u) {
        vis[u] = true;
        for (int v : g[u]) {
            int w = match[v];
            if (w < 0 || (!vis[w] && dist[w] == dist[u] + 1 && dfs(w))) {
                match[v] = u;
                used[u] = true;
                return true;
            }
        }
        return false;
    }
    void build() {
        while (true) {
            bfs();
            vis = vector<bool>(n, false);
            int flow = 0;
            for (int i = 0; i < n; i++) {
                flow += (!used[i] && dfs(i));
            }
            if (flow == 0) break;
        }
    }
};