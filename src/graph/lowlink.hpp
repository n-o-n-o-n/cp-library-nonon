#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

struct LowLink {
    LowLink(int _n) : n(_n), g(_n), built(false) {}
    LowLink(const vector<vector<int>> &_g) : n(_g.size()), g(_g), built(false) {}
    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        g[u].push_back(v);
        g[v].push_back(u);
        built = false;
    }
    vector<int> Articulation_Point() {
        if (!built) build();
        return articulation_point;
    }
    vector<pair<int, int>> Bridge() {
        if (!built) build();
        return bridge;
    }
private:
    int n;
    vector<vector<int>> g;
    bool built;
    vector<int> ord, low, articulation_point;
    vector<pair<int, int>> bridge;
    int dfs(int u, int k, int p) {
        low[u] = (ord[u] = k++);
        int c = 0;
        bool art = false, sec = false;
        for (int v : g[u]) {
            if (ord[v] == -1) {
                c++;
                k = dfs(v, k, u);
                low[u] = min(low[u], low[v]);
                art |= (p != -1) && (low[v] >= ord[u]);
                if (ord[u] < low[v]) {
                    bridge.push_back(minmax(u, v));
                }
            } else if (v != p || sec) {
                low[u] = min(low[u], ord[v]);
            } else {
                sec = true;
            }
        }
        art |= (p == -1) && (c > 1);
        if (art) articulation_point.push_back(u);
        return k;
    }
    void build() {
        assert(!built);
        int k = 0;
        ord = vector<int>(n, -1);
        low = vector<int>(n, -1);
        for (int i = 0; i < n; i++) {
            if (ord[i] == -1) {
                k = dfs(i, k, -1);
            }
        }
        built = true;
    }
};