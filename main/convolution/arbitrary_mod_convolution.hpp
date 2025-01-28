#pragma once
#include <vector>
#include "../modint/modint.hpp"
#include "convolution.hpp"
#include "../math/number_theory/garner.hpp"
using namespace std;

template<typename mint>
vector<mint> arbitrary_mod_convolution(const vector<mint> &f, const vector<mint> &g) {
    constexpr int m1 = 167772161, m2 = 469762049, m3 = 754974721;
    constexpr int mod = mint::mod();
    const vector<long long> mods = {m1, m2, m3};
    using mint1 = modint<m1>;
    using mint2 = modint<m2>;
    using mint3 = modint<m3>;
    int n = f.size(), m = g.size();
    vector<mint1> f1(n), g1(m);
    vector<mint2> f2(n), g2(m);
    vector<mint3> f3(n), g3(m);
    for (int i = 0; i < n; i++) {
        f1[i] = f[i].val();
        f2[i] = f[i].val();
        f3[i] = f[i].val();
    }
    for (int i = 0; i < m; i++) {
        g1[i] = g[i].val();
        g2[i] = g[i].val();
        g3[i] = g[i].val();
    }
    auto h1 = convolution(f1, g1);
    auto h2 = convolution(f2, g2);
    auto h3 = convolution(f3, g3);
    vector<mint> h(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        h[i] = garner({h1[i].val(), h2[i].val(), h3[i].val()}, mods, mod);
    }
    return h;
}