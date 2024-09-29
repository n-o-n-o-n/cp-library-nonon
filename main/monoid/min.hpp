#pragma once
#include <algorithm>
#include <limits>
using namespace std;

template <typename T>
struct min_monoid {
    using S = T;
    static S op(const S &a, const S &b) {
        return min(a, b);
    }
    static S e() { return numeric_limits<S>::max(); }
};