#pragma once
#include <vector>
using namespace std;

struct dsu {
    dsu(int n) : p(n, -1) {}
    int leader(int u) { return p[u] < 0 ? u : leader(p[u]); }
    bool same(int u, int v) { return leader(u) == leader(v); }
    void merge(int u, int v) {
        u = leader(u);
        v = leader(v);
        if (u == v) return;
        if (p[u] > p[v]) swap(u, v);
        p[u] += p[v];
        p[v] = u;
    }
    int size(int u) { return -p[leader(u)]; }
    vector<vector<int>> groups() {
        int n = p.size();
        vector<vector<int>> V(n);
        for (int i = 0; i < n; i++) {
            V[leader(i)].push_back(i);
        }
        vector<vector<int>> res;
        for (auto v : V) {
            if (v.size()) res.push_back(v);
        }
        return res;
    }
private:
    vector<int> p;
};