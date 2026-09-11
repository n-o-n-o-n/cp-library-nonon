#pragma once
#include <vector>
#include "../../fps/fps.hpp"
#include "combination.hpp"
using namespace std;

template<typename mint>
vector<mint> stirling2(int n, int k) {
    fps<mint> f(n - k + 1);
    for (int i = 0; i <= n - k; i++) {
        f[i] = combination::finv<mint>(i + 1);
    }
    f = f.pow(k) * combination::finv<mint>(k);
    vector<mint> res(n + 1);
    for (int i = k; i <= n; i++) {
        res[i] = f[i - k] * combination::fac<mint>(i);
    }
    return res;
}