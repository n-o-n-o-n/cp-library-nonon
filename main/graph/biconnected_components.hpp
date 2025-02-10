#pragma once
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>
using namespace std;

struct Biconnected_Component {
    Biconnected_Component() = default;
    Biconnected_Component(int _n) : n(_n), idx(0), g(_n) {}
    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(u != v);
        g[u].emplace_back(v, idx);
        g[v].emplace_back(u, idx);
        idx++;
    }
    vector<vector<int>> components() {
        int k = 0;
        ord = vector<int>(n, -1);
        low = vector<int>(n, -1);
        for (int i = 0; i < n; i++) {
            if (ord[i] == -1) {
                k = dfs(i, k, -1);
            }
        }
        used = vector<bool>(n, false);
        memo = vector<int>();
        bcc = vector<vector<int>>();
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                decompose(i, -1);
            }
        }
        return bcc;
    }
private:
    int n, idx;
    vector<vector<pair<int, int>>> g;
    vector<int> ord, low;
    vector<bool> used;
    vector<int> memo;
    vector<vector<int>> bcc;
    int dfs(int u, int k, int p) {
        low[u] = (ord[u] = k++);
        int c = 0;
        bool sec = false;
        for (auto [v, _] : g[u]) {
            if (ord[v] == -1) {
                c++;
                k = dfs(v, k, u);
                low[u] = min(low[u], low[v]);
            } else if (v != p || sec) {
                low[u] = min(low[u], ord[v]);
            } else {
                sec = true;
            }
        }
        return k;
    }
    void decompose(int u, int p) {
        used[u] = true;
        bool flag = false;
        for (auto [v, i] : g[u]) {
            if (v == p && !exchange(flag, true)) continue;
            if (!used[v] || ord[v] < ord[u]) {
                memo.push_back(i);
            }
            if (!used[v]) {
                decompose(v, u);
                if (ord[u] <= low[v]) {
                    bcc.emplace_back();
                    while (memo.size()) {
                        auto e = memo.back();
                        memo.pop_back();
                        bcc.back().push_back(e);
                        if (e == i) break;
                    }
                }
            }
        }
    }
};