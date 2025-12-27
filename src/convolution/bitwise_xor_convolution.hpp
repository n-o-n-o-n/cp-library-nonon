#pragma once
#include <cassert>
#include <vector>
using namespace std;
#include "fwht.hpp"

template<typename mint>
vector<mint> bitwise_xor_convolution(vector<mint> f, vector<mint> g) {
    assert(f.size() == g.size());
    int n = f.size();
    assert((n & (n - 1)) == 0);
    if (n == 0) return {};
    fwht(f);
    fwht(g);
    for (int i = 0; i < n; i++) f[i] *= g[i];
    fwht(f, true);
    return f;
}