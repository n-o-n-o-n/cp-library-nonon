#pragma once
#include <algorithm>
#include <array>
#include <cassert>
#include <numeric>
#include <vector>
#include "../random/utility.hpp"
using namespace std;

struct hash_on_tree {
    static long long base;
    static vector<long long> rds;
    static constexpr array<long long, 3> mod = {1000274903LL, 1000274927LL, 1000274953LL};
    static void set_base(int b) {
        assert(base == -1);
        assert(2 <= b && b <= int(1e9));
        base = b;
    }
    hash_on_tree(int _n, int r = 0) : n(_n), root(r), g(_n) {}
    void add_edge(int u, int v) {
        assert(base != -1);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    array<long long, 3> get_hash(int u) {
        assert(base != -1);
        assert(0 <= u && u < n);
        build();
        return hs[u];
    }
private:
    int n, root;
    vector<vector<int>> g;
    vector<array<long long, 3>> hs;
    void build() {
        if (hs.size()) return;
        hs = vector<array<long long, 3>>(n);
        auto dfs = [&] (const auto &dfs, int u, int p) -> int {
            int md = 0;
            hs[u].fill(1);
            for (int v : g[u]) {
                if (v != p) {
                    int d = dfs(dfs, v, u) + 1;
                    md = max(md, d + 1);
                    for (int j = 0; j < 3; j++) {
                        hs[u][j] = (hs[u][j] * (rd(d + 1) + hs[v][j])) % mod[j];
                    }
                }
            }
            return md;
        };
        dfs(dfs, root, -1);
    }
    static long long rd(int d) {
        int sz = rds.size();
        if (d >= sz) {
            int k = max(d + 1, 2 * sz);
            rds.resize(k);
            for (int i = sz; i < k; i++) {
                rds[i] = rng::randint(0LL, mod[0] - 1);
            }
        }
        return rds[d];
    }
};
inline long long hash_on_tree::base(-1);
inline vector<long long> hash_on_tree::rds(1, 1);