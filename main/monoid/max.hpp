#pragma once
#include <algorithm>
#include <limits>
using namespace std;

template <typename T>
struct max_monoid {
    using S = T;
    static S op(const S &a, const S &b) {
        return max(a, b);
    }
    static S e() { return numeric_limits<T>::min(); }
};