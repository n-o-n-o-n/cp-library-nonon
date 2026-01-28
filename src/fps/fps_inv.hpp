#pragma once
#include "fps.hpp"

template<typename mint>
fps<mint> fps<mint>::inv(int deg) const {
    int n = this->size();
    assert(n > 0);
    mint c = (*this)[0];
    assert(c != 0);
    if (deg == -1) deg = n;
    fps res(deg);
    res[0] = c.inv();
    for (int d = 1; d < deg; d <<= 1) {
        fps f(d << 1), g(d << 1);
        for (int i = 0; i < n && i < d << 1; i++) f[i] = (*this)[i];
        for (int i = 0; i < d; i++) g[i] = res[i];
        f.ntt();
        g.ntt();
        for (int i = 0; i < d << 1; i++) f[i] *= g[i];
        f.intt();
        for (int i = 0; i < d; i++) f[i] = 0;
        f.ntt();
        for (int i = 0; i < d << 1; i++) f[i] *= g[i];
        f.intt();
        for (int i = d; i < deg && i < d << 1; i++) res[i] -= f[i];
    }
    return res;
}