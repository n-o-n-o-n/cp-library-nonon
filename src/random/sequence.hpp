#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
#include "utility.hpp"
#include "../misc/even_distribution_array.hpp"
using namespace std;

namespace rng {

template<typename T>
void shuffle(vector<T> &v) {
    std::shuffle(v.begin(), v.end(), eng);
}

template<integral T>
inline vector<T> random_sequence(int n, T lo, T hi) {
    assert(n >= 0);
    vector<T> res(n);
    for (int i = 0; i < n; i++) res[i] = randint(lo, hi);
    return res;
}

template<integral T>
inline vector<T> random_increasing_sequence(int n, T lo, T hi, bool strict = false) {
    assert(n >= 0);
    if (n == 0) return {};
    assert(lo + (n - 1) * strict <= hi);
    vector<T> res = random_sequence(n, lo, hi - (n - 1) * strict);
    sort(res.begin(), res.end());
    for (int i = 0; i < n; i++) res[i] += i * strict;
    return res;
}

template<integral T>
inline vector<T> random_decreasing_sequence(int n, T lo, T hi, bool strict = false) {
    vector<T> res = random_increasing_sequence(n, lo, hi, strict);
    reverse(res.begin(), res.end());
    return res;
}

template<integral T>
inline vector<T> random_permutation(int n, T val = 0) {
    vector<T> res(n);
    iota(res.begin(), res.end(), val);
    shuffle(res);
    return res;
}

inline string random_string(int n, char a, char z) {
    assert(a <= z);
    string s(n, a);
    for (auto &c : s) c = randint((int)a, (int)z);
    return s;
}

} // namespace rng