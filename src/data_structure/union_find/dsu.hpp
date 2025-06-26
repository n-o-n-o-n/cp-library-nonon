#pragma once
#include <cassert>
#include <vector>
using namespace std;

struct dsu {
    dsu(int n) : p(n, -1) {}
    int leader(int u) const {
        assert(0 <= u && u < ssize(p));
        return p[u] < 0 ? u : leader(p[u]);
    }
    bool same(int u, int v) const {
        assert(0 <= u && u < ssize(p));
        assert(0 <= v && v < ssize(p));
        return leader(u) == leader(v);
    }
    void merge(int u, int v) {
        assert(0 <= u && u < ssize(p));
        assert(0 <= v && v < ssize(p));
        u = leader(u);
        v = leader(v);
        if (u == v) return;
        if (p[u] > p[v]) swap(u, v);
        p[u] += p[v];
        p[v] = u;
    }
    int size(int u) const {
        assert(0 <= u && u < ssize(p));
        return -p[leader(u)];
    }
    vector<vector<int>> groups() const {
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