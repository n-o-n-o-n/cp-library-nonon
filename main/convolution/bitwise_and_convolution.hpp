#pragma once
#include <cassert>
#include <vector>
using namespace std;
#include "superset_zmt.hpp"

template<typename mint>
vector<mint> bitwise_and_convolution(vector<mint> f, vector<mint> g) {
    assert(f.size() == g.size());
    int n = f.size();
    if (n == 0) return {};
    superset_zmt(f);
    superset_zmt(g);
    for (int i = 0; i < n; i++) f[i] *= g[i];
    superset_zmt(f, true);
    return f;
}