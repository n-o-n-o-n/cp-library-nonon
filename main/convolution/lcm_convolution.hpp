#pragma once
#include <cassert>
#include <vector>
using namespace std;
#include "divisor_zmt.hpp"

template<typename mint>
vector<mint> lcm_convolution(vector<mint> f, vector<mint> g) {
    assert(f.size() == g.size());
    int n = f.size();
    if (n == 0) return {};
    divisor_zmt(f);
    divisor_zmt(g);
    for (int i = 0; i < n; i++) f[i] *= g[i];
    divisor_zmt(f, true);
    return f;
}