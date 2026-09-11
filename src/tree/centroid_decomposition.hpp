#pragma once
#include <cassert>
#include <vector>
using namespace std;

struct centroid_decomposition {
    centroid_decomposition() = default;
    centroid_decomposition(int _n) : n(_n), e(0), g(_n) {
        if (n == 1) build();
    }
    centroid_decomposition(const vector<vector<int>> &_g) : n(_g.size()), g(_g) {
        build();
    }
    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        g[u].push_back(v);
        g[v].push_back(u);
        if (++e == n - 1) build();
    }
    vector<int> operator[](int u) const { return g[u]; }
    int level(int u) const { return lv[u]; }
    int sub_size(int u) const { return sub[u]; }
    int parent(int u) const { return par[u]; }
    vector<int> level_vector() const { return lv; }
    vector<int> sub_size_vector() const { return sub; }
    vector<int> parent_vector() const { return par; }
private:
    int n, e;
    vector<vector<int>> g;
    vector<int> sz, lv, sub, par;
    int dfs_size(int u, int p) {
        sz[u] = 1;
        for (int v : g[u]) {
            if (v != p && lv[v] == -1) {
                sz[u] += dfs_size(v, u);
            }
        }
        return sz[u];
    }
    int dfs_centroid(int u, int p, int s) {
        for (int v : g[u]) {
            if (v != p && lv[v] == -1 && sz[v] > s / 2) {
                return dfs_centroid(v, u, s);
            }
        }
        return u;
    }
    void decompose(int u, int p, int k) {
        int s = dfs_size(u, -1);
        int c = dfs_centroid(u, -1, s);
        lv[c] = k;
        sub[c] = s;
        par[c] = p;
        for (int v : g[c]) {
            if (lv[v] == -1) {
                decompose(v, c, k + 1);
            }
        }
    }
    void build() {
        sz = lv = sub = par = vector<int>(n, -1);
        decompose(0, -1, 0);
    }
};