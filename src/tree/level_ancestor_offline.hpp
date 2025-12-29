#pragma once
#include <cassert>
#include <utility>
#include <vector>
using namespace std;

struct level_ancestor {
    level_ancestor(int n) : g(n), querys(n), q(0) {}
    level_ancestor(const vector<vector<int>> &_g) : g(_g), querys(_g.size()), q(0) {}
    void add_edge(int u, int v) {
        assert(0 <= u && u < int(g.size()));
        assert(0 <= v && v < int(g.size()));
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void add_query(int u, int k) {
        assert(0 <= u && u < int(g.size()));
        querys[u].emplace_back(k, q++);
    }
    vector<int> solve(int root = 0) {
        vector<int> ans(q);
        vector<int> path;
        auto dfs = [&](const auto &dfs, int u, int p) -> void {
            int d = path.size();
            for (auto [k, i] : querys[u]) {
                if (k > d) {
                    ans[i] = -1;
                } else {
                    ans[i] = path[d - k];
                }
            }
            path.push_back(u);
            for (int v : g[u]) {
                if (v != p) {
                    dfs(dfs, v, u);
                }
            }
            path.pop_back();
        };
        dfs(dfs, root, -1);
        return ans;
    }
private:
    int q;
    vector<vector<int>> g;
    vector<vector<pair<int, int>>> querys;
};