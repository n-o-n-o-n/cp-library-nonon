#pragma once
#include <limits>
#include <queue>
#include <vector>
using namespace std;

pair<vector<int>, vector<int>> bfs(const vector<vector<int>> &g, int s) {
    int n = g.size();
    vector<int> dist(n, numeric_limits<int>::max());
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    vector<int> par(n, -1);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] > dist[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
    return make_pair(dist, par);
}