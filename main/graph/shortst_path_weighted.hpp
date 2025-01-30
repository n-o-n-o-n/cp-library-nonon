#pragma once
#include <limits>
#include <vector>
#include "dijkstra.hpp"
using namespace std;

template<typename T1, typename T2 = int>
pair<T1, vector<int>> shortest_path(const vector<vector<pair<int, T2>>> &g, int s, int t) {
    int n = g.size();
    vector<vector<pair<int, T2>>> h(n);
    for (int u = 0; u < n; u++) {
        for (auto [v, w] : g[u]) {
            h[v].emplace_back(u, w);
        }
    }
    auto [dist, par] = dijkstra<T1>(h, t);
    if (dist[s] == numeric_limits<T1>::max()) return make_pair(-1, vector<int>{});
    vector<int> res;
    T1 d = dist[s];
    while (s != t) {
        res.push_back(s);
        s = par[s];
    }
    res.push_back(t);
    return make_pair(d, res);
}