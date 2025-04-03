#pragma once
#include <vector>
using namespace std;

template<typename FPS, typename mint>
vector<mint> multipoint_evaluation(const FPS &f, const vector<mint> &xs) {
    int n = f.size(), m = xs.size();
    if (m == 0) return {};
    if (n == 0) return vector<mint>(m, 0);
    if (n == 1) return vector<mint>(m, f[0]);
    int sz = 1;
    while (sz < m) sz <<= 1;
    vector<FPS> d(2 * sz, FPS{1});
    for (int i = 0; i < m; i++) d[i + sz] = FPS{-xs[i], 1};
    for (int i = sz - 1; i >= 1; i--) {
        d[i] = d[2 * i] * d[2 * i + 1];
    }
    d[1] = f % d[1];
    for (int i = 2; i < m + sz; i++) d[i] = d[i >> 1] % d[i];
    vector<mint> y(m);
    for (int i = 0; i < m; i++) {
        if (d[i + sz].empty()) {
            y[i] = 0;
        } else {
            y[i] = d[i + sz][0];
        }
    }
    return y;
}