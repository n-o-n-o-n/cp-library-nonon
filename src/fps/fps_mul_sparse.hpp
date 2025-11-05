#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename mint>
vector<mint> fps_mul_sparse(const vector<mint> &f, const vector<pair<int, mint>> &g_sub) {
    int n = f.size(), m = 0;
    for (auto [j, _] : g_sub) m = max(m, j);
    vector<mint> h(n + m);
    for (auto [j, b] : g_sub) {
        for (int i = 0; i < n; i++) h[i + j] += f[i] * b;
    }
    while (h.size() && h.back() == 0) h.pop_back();
    return h;
}