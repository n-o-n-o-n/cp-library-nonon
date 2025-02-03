#pragma once
#include <vector>
#include "../math/matrix/matrix_mint.hpp"

template<typename mint>
mint matrix_tree_theorem(const vector<vector<int>> &g, int r = 0) {
    int n = g.size();
    if (n == 1) return 1;
    matrix<mint> l(n - 1, n - 1);
    for (int u = 0; u < n; u++) {
        if (u == r) continue;
        l[u - (u > r)][u - (u > r)] = g[u].size();
        for (int v : g[u]) {
            if (v == r) continue;
            l[u - (u > r)][v - (v > r)]--;
        }
    }
    return l.det();
}