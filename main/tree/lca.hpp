#pragma once
#include <cassert>
#include <vector>
using namespace std;

struct lowest_common_ancestor {
    lowest_common_ancestor(int _n, int r = 0) : n(_n), root(r), g(vector<vector<int>>(_n)), built(false) {}
    lowest_common_ancestor(const vector<vector<int>> &_g, int r = 0) : n(int(_g.size())), root(r), g(_g) { build(); }
    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(!built);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int lca(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        build();
        if(dist[u] < dist[v]) swap(u, v);
        int k = table.size();
        for (int i = 0; i < k; i++) {
            if ((dist[u] - dist[v]) >> i & 1) {
                u = table[i][u];
            }
        }
        if (u == v) return u;
        for (int i = k - 1; i >= 0; i--) {
            if (table[i][u] != table[i][v]) {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }
private:
    int n, root;
    vector<vector<int>> g;
    bool built;
    vector<int> dist;
    vector<vector<int>> table;
    void dfs(int u, int p, int d) {
        table[0][u] = p;
        dist[u] = d;
        for(int v : g[u]) {
            if(v != p) dfs(v, u, d + 1);
        }
    }
    void build() {
        if (built) return;
        int k = 1;
        while ( (1 << k) < n) k++;
        table.assign(k, vector<int>(n, -1));
        dist.assign(n, -1);
        dfs(root, -1, 0);
        for(int i = 0; i < k - 1; i++) {
            for (int j = 0; j < n; j++) {
                if(table[i][j] < 0) {
                    table[i + 1][j] = -1;
                } else {
                    table[i + 1][j] = table[i][table[i][j]];
                }
            }
        }
        built = true;
    }
};