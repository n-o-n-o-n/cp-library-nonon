#pragma once
#include <cassert>
#include <vector>
using namespace std;
#include "subset_zmt.hpp"

template<typename mint>
vector<mint> bitwise_or_convolution(vector<mint> f, vector<mint> g) {
    assert(f.size() == g.size());
    int n = f.size();
    if (n == 0) return {};
    subset_zmt(f);
    subset_zmt(g);
    for (int i = 0; i < n; i++) f[i] *= g[i];
    subset_zmt(f, true);
    return f;
}