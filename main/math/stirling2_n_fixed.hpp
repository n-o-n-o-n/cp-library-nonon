#pragma once
#include <vector>
#include "../math/combination.hpp"
#include "../convolution/convolution.hpp"
using namespace std;

template<typename mint>
vector<mint> stirling2(int n) {
    vector<mint> f(n + 1), g(n + 1);
    int sgn = 1;
    for (int i = 0; i <= n; i++) {
        f[i] = finv<mint>(i) * sgn;
        g[i] = finv<mint>(i) * mint::raw(i).pow(n);
        sgn *= -1;
    }
    return convolution(f, g, n + 1);
}