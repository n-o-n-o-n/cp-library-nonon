#pragma once
#include <queue>
#include <vector>
using namespace std;

vector<int> prufer_code_compress(const vector<vector<int>> &t) {
    int n = t.size();
    if (n <= 2) return {};
    vector<int> deg(n);
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) {
        deg[i] = t[i].size();
        if (deg[i] == 1) {
            q.push(i);
        }
    }
    vector<int> p;
    p.reserve(n - 2);
    while ((int)p.size() < n - 2) {
        int u = q.top();
        q.pop();
        for (int v : t[u]) {
            if (deg[v] > 0) {
                p.push_back(v);
                deg[v]--;
                if (deg[v] == 1) q.push(v);
                break;
            }
        }
        deg[u]--;
    }
    return p;
}

vector<vector<int>> prufer_code_expansion(const vector<int> &p) {
    int n = p.size() + 2;
    vector<int> deg(n, 1);
    for (int u : p) deg[u]++;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) q.push(i);
    }
    vector<vector<int>> t(n);
    for (int i = 0; i < n - 2; i++) {
        int u = p[i];
        int v = q.top();
        q.pop();
        t[u].push_back(v);
        t[v].push_back(u);
        deg[u]--, deg[v]--;
        if (deg[u] == 1) q.push(u);
    }
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) {
            for (int j = 0; j < n; j++) {
                if (j != i && deg[j] == 1) {
                    t[i].push_back(j);
                    t[j].push_back(i);
                    deg[i]--, deg[j]--;
                    break;
                }
            }
            break;
        }
    }
    return t;
}