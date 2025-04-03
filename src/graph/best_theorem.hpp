#pragma once
#include <vector>
#include "../math/matrix/matrix_mint.hpp"
#include "../math/enumerative_combinatorics/combination.hpp"
#include "matrix_tree_theorem.hpp"
using namespace std;

template<typename mint>
mint best_theorem_adjacency(const vector<vector<int>> &a, bool edge_labeled = true) {
    int n = a.size();
    vector<int> idx;
    idx.reserve(n);
    mint res = 1;
    for (int u = 0; u < n; u++) {
        int in = 0, out = 0;
        for (int v = 0; v < n; v++) {
            in += a[v][u];
            out += a[u][v];
            if (!edge_labeled) res *= combination::finv<mint>(a[u][v]);
        }
        if (in != out) return 0;
        if (in > 0) {
            idx.push_back(u);
            res *= combination::fac<mint>(in - 1);
        }
    }
    n = idx.size();
    if (n == 0) return 1;
    vector<vector<int>> b(n, vector<int>(n));
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            b[u][v] = a[idx[u]][idx[v]];
        }
    }
    return res * matrix_tree_theorem_adjacency<mint>(b);
}

template<typename mint>
mint best_theorem(const vector<vector<int>> &g, bool edge_labeled = true) {
    int n = g.size();
    vector<vector<int>> a(n, vector<int>(n));
    for (int u = 0; u < n; u++) {
        for (int v : g[u]) a[u][v]++;
    }
    return best_theorem_adjacency<mint>(a, edge_labeled);
}