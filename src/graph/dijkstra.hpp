#pragma once
#include <queue>
#include <vector>
using namespace std;

template<typename T1, typename T2 = int>
pair<vector<T1>, vector<int>> dijkstra(const vector<vector<pair<int, T2>>> &g, int s) {
    int n = g.size();
    vector<T1> dist(n, 1LL << 60);
    dist[s] = 0;
    priority_queue<pair<T1, int>> q;
    q.emplace(0, s);
    vector<int> par(n, -1);
    while (q.size()) {
        auto [d, u] = q.top();
        d = -d;
        q.pop();
        if (dist[u] < d) continue;
        for (auto [v, w] : g[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                par[v] = u;
                q.emplace(-dist[v], v);
            }
        }
    }
    return make_pair(dist, par);
}