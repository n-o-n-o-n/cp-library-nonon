#pragma once
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>
using namespace std;

struct lowlink {
    lowlink(int _n = 0, int m = 0) : n(_n), g(_n), built(false) {
        edges.reserve(m);
    }
    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        g[u].emplace_back(v, edges.size());
        g[v].emplace_back(u, edges.size());
        edges.emplace_back(u, v);
        built = false;
    }
    vector<int> operator[](int p) const {
        vector<int> res;
        res.reserve(g[p].size());
        for (auto [v, _] : g[p]) res.emplace_back(v);
        return res;
    }
    vector<int> articulation_point() {
        build();
        return ap;
    }
    vector<pair<int, int>> bridge() {
        build();
        return bg;
    }
    bool is_bridge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        build();
        if (ord[u] > ord[v]) swap(u, v);
        return ord[u] < low[v];
    }
    vector<vector<int>> biconnected_components() {
        build();
        vector<bool> used(n, false);
        vector<int> memo;
        vector<vector<int>> bccs;
        auto decompose = [&] (const auto &decompose, int u, int p) -> void {
            used[u] = true;
            bool flag = false;
            for (auto [v, i] : g[u]) {
                if (v == p && !exchange(flag, true)) continue;
                if (!used[v] || ord[v] < ord[u]) memo.push_back(i);
                if (!used[v]) {
                    decompose(decompose, v, u);
                    if (ord[u] <= low[v]) {
                        bccs.emplace_back();
                        while (memo.size()) {
                            auto j = memo.back();
                            memo.pop_back();
                            bccs.back().push_back(j);
                            if (i == j) break;
                        }
                    }
                }
            }
        };
        for (int i = 0; i < n; i++) {
            if (!used[i]) decompose(decompose, i, - 1);
        }
        vector<vector<int>> res;
        vector<bool> check(n, false), seen(n, false);
        auto insert = [&] (int u) -> void {
            if (!check[u]) {
                check[u] = true;
                seen[u] = true;
                res.back().push_back(u);
            }
        };
        for (auto bcc : bccs) {
            res.emplace_back();
            for (int i : bcc) {
                auto [u, v] = edges[i];
                insert(u);
                insert(v);
            }
            for (int u : res.back()) check[u] = false;
        }
        for (int i = 0; i < n; i++) {
            if (!seen[i]) res.emplace_back(1, i);
        }
        return res;
    }
    vector<vector<int>> two_edge_connected_components() {
        build();
        int k = 0;
        vector<int> tecc(n, -1);
        auto decompose = [&] (const auto &decompose, int u) -> void {
            tecc[u] = k;
            for (auto [v, _] : g[u]) {
                if (tecc[v] == -1 && !is_bridge(u, v)) decompose(decompose, v);
            }
        };
        for (int i = 0; i < n; i++) {
            if (tecc[i] == -1) {
                decompose(decompose, i);
                k++;
            }
        }
        vector<vector<int>> res(k);
        for (int i = 0; i < n; i++) {
            res[tecc[i]].push_back(i);
        }
        return res;
    }
private:
    int n;
    vector<vector<pair<int, int>>> g;
    vector<pair<int, int>> edges;
    bool built;
    vector<int> ord, low, ap;
    vector<pair<int, int>> bg;
    int dfs(int u, int k, int p) {
        low[u] = (ord[u] = k++);
        int c = 0;
        bool art = false, sec = false;
        for (auto [v, _] : g[u]) {
            if (ord[v] == -1) {
                c++;
                k = dfs(v, k, u);
                low[u] = min(low[u], low[v]);
                art |= (p != -1) && (low[v] >= ord[u]);
                if (ord[u] < low[v]) {
                    bg.push_back(minmax(u, v));
                }
            } else if (v != p || sec) {
                low[u] = min(low[u], ord[v]);
            } else {
                sec = true;
            }
        }
        art |= (p == -1) && (c > 1);
        if (art) ap.push_back(u);
        return k;
    }
    void build() {
        if (built) return;
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