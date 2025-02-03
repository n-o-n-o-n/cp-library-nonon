#pragma once
#include <vector>
#include "../math/matrix/matrix_mint.hpp"

template<typename mint>
mint matrix_tree_theorem_adjacency(const vector<vector<int>> &a, int r = 0) {
    int n = a.size();
    if (n == 1) return 1;
    auto p = [&](int u) -> int {
        return u - (u > r);
    };
    matrix<mint> b(n - 1, n - 1);
    for (int u = 0; u < n; u++) {
        if (u == r) continue;
        for (int v = 0; v < n; v++) {
            b[p(u)][p(u)] += a[u][v];
            if (v != r) {
                b[p(u)][p(v)] -= a[u][v];
            }
        }
    }
    return b.det();
}

template<typename mint>
mint matrix_tree_theorem(const vector<vector<int>> &g, int r = 0) {
    int n = g.size();
    vector<vector<int>> a(n, vector<int>(n));
    for (int u = 0; u < n; u++) {
        for (int v : g[u]) a[u][v]++;
    }
    return matrix_tree_theorem_adjacency<mint>(a, r);
}