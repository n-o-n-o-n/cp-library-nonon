#pragma once
#include "fps.hpp"

template<typename mint>
fps<mint> fps<mint>::taylor_shift(mint c) const {
    int n = this->size();
    fps f = *this;
    for (int i = 0; i < n; i++) f[i] *= combination::fac<mint>(i);
    reverse(f.begin(), f.end());
    fps g(n);
    mint pw = 1;
    for (int i = 0; i < n; i++) {
        g[i] = pw * combination::finv<mint>(i);
        pw *= c;
    }
    f *= g;
    f.resize(n);
    reverse(f.begin(), f.end());
    for (int i = 0; i < n; i++) f[i] *= combination::finv<mint>(i);
    return f;
}