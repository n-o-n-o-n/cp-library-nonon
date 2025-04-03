#pragma once
#include <algorithm>
#include <limits>
using namespace std;

template <typename T, T E = numeric_limits<T>::max()>
struct min_monoid {
    using S = T;
    static S op(const S &a, const S &b) {
        return min(a, b);
    }
    static S e() { return E; }
};