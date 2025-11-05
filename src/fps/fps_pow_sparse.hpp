#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename mint>
vector<mint> fps_pow_sparse(const vector<pair<int, mint>> &f_sub, int n, long long k) {
    vector<mint> g(n);
    if(f_sub.empty()) {
        if (k == 0) g[0] = mint::raw(1);
        return g;
    }
    auto [a0, c0] = f_sub[0];
    if(0 < a0) {
        if(k > (n - 1) / a0) return g;
        vector<pair<int, mint>> g_sub = f_sub;
        for (auto &[a,c] : g_sub) a -= a0;
        auto h = fps_pow_sparse(g_sub, n - k * a0, k);
        for (int i = 0; i < n - k * a0; i++) {
            g[i + k * a0] = h[i];
        }
        return g;
    }
    const int mod = mint::mod();
    vector<mint> inv(n);
    if (n >= 2) inv[1] = 1;
    g[0] = c0.pow(k);
    mint cef = c0.inv();
    for (int i = 1; i < n; i++) {
        for (auto [a, c] : f_sub) {
            if(0 < a && a <= i) {
                g[i] += c * g[i - a] * (mint(k + 1) * a - i);
            }
        }
        if(i >= 2) {
            inv[i] = -inv[mod % i] * (mod / i);
        }
        g[i] *= inv[i] * cef;
    }
    return g;
}