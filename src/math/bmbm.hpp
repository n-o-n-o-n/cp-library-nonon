#pragma once
#include <vector>
#include "../fps/fps.hpp"
#include "berlekamp_massey.hpp"
#include "bostan_mori.hpp"
using namespace std;

template<typename mint>
mint BMBM(const vector<mint> &x, long long k) {
    using FPS = Formal_Power_Series<mint>;
    auto tmp = Berlekamp_Massey(x);
    int n = tmp.size() - 1;
    FPS a(n), c(n);
    for (int i = 0; i < n; i++) {
        a[i] = x[i];
        c[i] = tmp[i + 1];
    }
    return linear_recurrence(a, c, k);
}