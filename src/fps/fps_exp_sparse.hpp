#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename mint>
vector<mint> fps_exp_sparse(const vector<pair<int, mint>> &f_sub, int n) {
    vector<mint> g(n), inv(n);
    if (f_sub.empty()) {
        g[0] = 1;
        return g;
    }
    assert(f_sub[0].first > 0);
    const int mod = mint::mod();
    g[0] = 1;
    if (n > 1) inv[1] = mint::raw(1);
    for (int i = 1; i < n; i++) {
        for (auto [a, c] : f_sub) {
            if (a <= i) {
                g[i] += a * c * g[i - a];
            }
        }
        if (i >= 2) {
            inv[i] = -inv[mod % i] * (mod / i);
            g[i] *= inv[i];
        }
    }
    return g;
}