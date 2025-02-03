#pragma once
#include <vector>
#include "../math/matrix/matrix_mint.hpp"
#include "../math/enumerative_combinatorics/combination.hpp"
#include "matrix_tree_theorem.hpp"
using namespace std;

template<typename mint>
mint best_theorem(const vector<vector<int>> &g) {
    int n = g.size();
    vector<vector<int>> a(n, vector<int>(n));
    for (int u = 0; u < n; u++) {
        for (int v : g[u]) a[u][v]++;
    }
    vector<int> idx;
    idx.reserve(n);
    mint res = 1;
    for (int u = 0; u < n; u++) {
        int d = 0;
        for (int v = 0; v < n; v++) {
            d += a[u][v] - a[v][u];
        }
        if (d != 0) return 0;
        d = 0;
        for (int v = 0; v < n; v++) {
            d += a[u][v];
        }
        if (d > 0) {
            idx.push_back(u);
            res *= combination::fac<mint>(d - 1);
        }
    }
    n = idx.size();
    if (n == 0) return 1;
    vector<vector<int>> h(n);
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            while (a[idx[u]][idx[v]]--) h[u].push_back(v);
        }
    }
    return res * matrix_tree_theorem<mint>(h);
}