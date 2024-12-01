#pragma once
#include <vector>
#include "../fps/fps.hpp"
#include "combination.hpp"
using namespace std;

template<typename mint>
vector<mint> stirling2(int n, int k) {
    using FPS = Formal_Power_Series<mint>;
    combination<mint> C;
    FPS f(n - k + 1);
    for (int i = 0; i <= n - k; i++) {
        f[i] = C.finv(i + 1);
    }
    f = f.pow(k) * C.finv(k);
    vector<mint> res(n + 1);
    for (int i = k; i <= n; i++) {
        res[i] = f[i - k] * C.fac(i);
    }
    return res;
}