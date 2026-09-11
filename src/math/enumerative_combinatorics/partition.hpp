#pragma once
#include "../../fps/fps.hpp"

template<typename mint>
vector<mint> partition(int n) {
    fps<mint> f(n + 1);
    f[0] = 1;
    for (int i = 1; i * (3 * i - 1) / 2 <= n; i++) {
        for (int j : {i * (3 * i - 1) / 2, i * (3 * i + 1) / 2}) {
            if (j <= n) f[j] += (i & 1 ? -1 : 1);
        }
    }
    return f.inv();
}