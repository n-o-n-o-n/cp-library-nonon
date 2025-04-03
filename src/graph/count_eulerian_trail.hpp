#pragma once
#include <vector>
#include "../math/enumerative_combinatorics/combination.hpp"
#include "best_theorem.hpp"
using namespace std;

template<typename mint>
mint count_eulerian_trail_adjacency(vector<vector<int>> a, bool edge_labeled = true) {
    int n = a.size();
    int s = -1, t = -1;
    mint res = 1;
    mint sum = 0;
    for (int u = 0; u < n; u++) {
        int in = 0, out = 0;
        for (int v = 0; v < n; v++) {
            in += a[v][u];
            out += a[u][v];
            sum += a[u][v];
            if (!edge_labeled) {
                res *= combination::finv<mint>(a[u][v]);
            }
        }
        if (in + 1 == out) {
            if (s != -1) return 0;
            s = u;
        } else if (in == out + 1) {
            if (t != -1) return 0;
            t = u;
        } else if (in != out) {
            return 0;
        }
    }
    if ((s == -1) ^ (t == -1)) return 0;
    if (s != -1) {
        a[t][s]++;
    } else {
        res *= sum;
    }
    return res * best_theorem_adjacency<mint>(a);
}

template<typename mint>
mint count_eulerian_trail(const vector<vector<int>> &g, bool edge_labeled = true) {
    int n = g.size();
    vector<vector<int>> a(n, vector<int>(n));
    for (int u = 0; u < n; u++) {
        for (int v : g[u]) a[u][v]++;
    }
    return count_eulerian_trail_adjacency<mint>(a, edge_labeled);
}