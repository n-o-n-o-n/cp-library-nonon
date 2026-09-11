#pragma once
#include <vector>
#include "../../modint/modint.hpp"
#include "../../fps/fps.hpp"
#include "../../fps/fps_exp.hpp"
using namespace std;


template<typename mint>
vector<mint> subset_sum(const vector<int> &a, int m, bool neg = false) {
    const int mod = mint::mod();
    vector<int> cnt(m + 1, 0);
    for (int c : a) {
        if (c <= m) cnt[c]++;
    }
    vector<mint> inv(m + 1, 1);
    for (int i = 2; i <= m; i++) inv[i] = -inv[mod % i] * (mod / i);
    fps<mint> f(m + 1);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; i * j <= m; j++) {
            if (j & 1 && !neg) {
                f[i * j] += cnt[i] * inv[j];
            } else {
                f[i * j] -= cnt[i] * inv[j];
            }
        }
    }
    f = f.exp();
    return vector<mint>(f.begin(), f.end());
}
