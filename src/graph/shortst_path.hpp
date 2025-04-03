#pragma once
#include <limits>
#include <vector>
#include "bfs.hpp"
using namespace std;

vector<int> shortest_path(const vector<vector<int>> &g, int s, int t) {
    int n = g.size();
    vector<vector<int>> h(n);
    for (int u = 0; u < n; u++) {
        for (int v : g[u]) {
            h[v].emplace_back(u);
        }
    }
    auto [dist, par] = bfs(g, t);
    if (dist[s] == numeric_limits<int>::max()) return {};
    vector<int> res;
    while (s != t) {
        res.push_back(s);
        s = par[s];
    }
    res.push_back(t);
    return res;
}