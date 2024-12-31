#pragma once
#include <numeric>
#include <vector>
#include "../dp/monotone_minima.hpp"
using namespace std;

// a must be convex
template<typename T>
vector<T> min_plus_convolution(const vector<T> &a, const vector<T> &b) {
    static constexpr T inf = numeric_limits<T>::max();
    auto f = [&](int i, int j) -> T {
        return i < j || (int)a.size() <= i - j ? inf : a[i - j] + b[j];
    };
    auto comp = [&](T x, T y) -> bool {
        return x < y;
    };
    int n = a.size() + b.size() - 1;
    auto id = monotone_minima(n, b.size(), f, comp);
    vector<T> res(n);
    for (int i = 0; i < n; i++) res[i] = f(i, id[i]);
    return res;
}