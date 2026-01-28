#pragma once
#include "fps_log.hpp"
#include "fps_exp.hpp"
#include "power_projection.hpp"

// https://judge.yosupo.jp/submission/307652
template<typename mint>
fps<mint> fps<mint>::compositional_inverse(int deg) const {
    auto f = *this;
    assert(f.size() >= 2 && f[1] != 0);
    if (deg == -1) deg = f.size();
    if (deg < 2) return fps<mint>{0, f[1].inv()}.pre(deg);
    int n = deg - 1;
    auto h = power_projection<mint>(f, {1}, n, n + 1) * n;
    for (int k = 1; k <= n; k++) h[k] *= combination::mod_inv<mint>(k);
    h = h.rev();
    h *= h[0].inv();
    auto g = (h.log() * mint(-n).inv()).exp();
    g *= f[1].inv();
    return (g << 1).pre(deg);
}