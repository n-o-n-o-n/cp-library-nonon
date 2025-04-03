#pragma once
#include <cassert>
#include <vector>
using namespace std;
#include "multiple_zmt.hpp"

template<typename mint>
vector<mint> gcd_convolution(vector<mint> f, vector<mint> g) {
    assert(f.size() == g.size());
    int n = f.size();
    if (n == 0) return {};
    multiple_zmt(f);
    multiple_zmt(g);
    for (int i = 0; i < n; i++) f[i] *= g[i];
    multiple_zmt(f, true);
    return f;
}