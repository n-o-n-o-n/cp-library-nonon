#pragma once
#include <algorithm>
#include <vector>
#include "factorise.hpp"

template<typename T>
vector<T> enumerate_divisors(T m) {
    auto f = factorise(m);
    int n = f.size();
    vector<T> res;
    auto rec = [&] (const auto &rec, int i, T x) -> void {
        if (i == n) {
            res.push_back(x);
            return;
        }
        auto [p, k] = f[i];
        for (int j = 0; j <= k; j++) {
            rec(rec, i + 1, x);
            x *= p;
        }
    };
    rec(rec, 0, 1);
    sort(res.begin(), res.end());
    return res;
}