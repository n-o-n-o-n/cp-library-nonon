#pragma once
#include <vector>
using namespace std;

#include "../main/fps/fps.hpp"

template<typename mint>
vector<mint> power_sum(int k, long long n) {
    using FPS = Formal_Power_Series<mint>;
    vector<mint> fac(k + 2), finv(k + 2);
    fac[0] = 1;
    for (int i = 1; i <= k + 1; i++) {
        fac[i] = i * fac[i - 1];
    }
    finv[k + 1] = fac[k + 1].inv();
    for (int i = k + 1; i >= 1; i--) {
        finv[i - 1] = i * finv[i];
    }
    mint pown = n + 1;
    FPS f(k + 1), g(k + 1);
    for (int i = 0; i <= k; i++) {
        f[i] = pown * finv[i + 1];
        g[i] = finv[i + 1];
        pown *= n + 1;
    }
    f /= g;
    vector<mint> res(k + 1);
    res[0] = n + 1;
    for (int i = 1; i <= k; i++) {
        res[i] = f[i] * fac[i];
    }
    return res;
}