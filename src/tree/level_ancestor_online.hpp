#pragma once
#include <algorithm>
#include <vector>
using namespace std;

struct level_ancestor {
    level_ancestor(int _n, int r = 0) : n(_n), root(r), g(_n), built(false) {}
    level_ancestor(const vector<vector<int>> &_g, int r = 0) : n(_g.size()), root(r), g(_g), built(false) { build(); }
    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int depth(int u) {
        build();
        return d[u];
    }
    int query(int u, int k) {
        build();
        if (k > d[u]) return -1;
        k = d[u] - k;
        return *prev(upper_bound(list[k].begin(), list[k].end(), u, [&](int i, int j) {
            return in[i] < in[j];
        }));
    }
private:
    int n, root, cnt;
    vector<vector<int>> g;
    vector<int> d, in;
    vector<vector<int>> list;
    bool built;
    void build() {
        if (built) return;
        d.resize(n);
        in.resize(n);
        list.resize(n);
        auto dfs = [&](const auto &dfs, int u, int p) -> void {
            in[u] = cnt++;
            list[d[u]].push_back(u);
            for (int v : g[u]) {
                if (v != p) {
                    d[v] = d[u] + 1;
                    dfs(dfs, v, u);
                }
            }
        };
        cnt = 0;
        d[root] = 0;
        dfs(dfs, root, -1);
        built = true;
    }
};