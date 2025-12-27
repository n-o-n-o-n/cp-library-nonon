#pragma once
#include "convolution.hpp"

// h[k] = sum_i f[i+k]g[i]
template<typename mint>
vector<mint> middle_product(const vector<mint> &f, const vector<mint> &g) {
    int n = f.size(), m = g.size();
    auto h = convolution(f, vector<mint>(g.rbegin(), g.rend()));
    vector<mint> res(n);
    for (int i = 0; i < n; i++) res[i] = i + m - 1 < ssize(h) ? h[i + m - 1] : 0;
    return res;
}