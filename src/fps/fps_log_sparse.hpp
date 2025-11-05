#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename mint>
vector<mint> fps_log_sparse(const vector<pair<int, mint>> &f_sub, int n) {
    assert(f_sub.size() && f_sub[0] == make_pair(0, mint::raw(1)));
    const int mod = mint::mod();
    vector<mint> g(n), inv(n);
    for (auto [a, c] : f_sub) {
        if(a > 0) g[a] = c;
    }
    if (n > 1) inv[1] = mint::raw(1);
    for (int i = 1; i < n; i++) {
        mint sum = 0;
        for (auto [a, c] : f_sub) {
            if(0 < a && a <= i) {
                sum += c * (i - a) * g[i - a];
            }
        }
        if (i >= 2) {
            inv[i] = -inv[mod % i] * (mod / i);
            sum *= inv[i];
        }
        g[i] -= sum;
    }
    return g;
}