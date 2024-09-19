#pragma once
#include <vector>
#include "ntt.hpp"
using namespace std;

template<typename mint>
vector<mint> convolution(vector<mint> f, vector<mint> g, int deg = -1) {
    using NTT = Number_Theoretic_Transform<mint>;
    int n = f.size(), m = g.size();
    if (n == 0 || m == 0) return {};
    int sz = 1;
    while (sz < n + m - 1) sz <<= 1;
    f.resize(sz);
    NTT::ntt(f);
    g.resize(sz);
    NTT::ntt(g);
    for (int i = 0; i < sz; i++) f[i] *= g[i];
    NTT::intt(f);
    if (deg == -1) deg = n + m - 1;
    f.resize(deg);
    return f;
}