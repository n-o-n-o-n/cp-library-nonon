#pragma once
#include <algorithm>
#include <limits>
using namespace std;

template<typename T, T E = numeric_limits<T>::max()>
struct range_add_range_min {
    using S = T;
    static S op(const S &a, const S &b) {
        return min(a, b);
    }
    static S e() { return E; }
    using F = T;
    static F comp(const F &f, const F &g) {
        return f + g;
    }
    static F id() { return 0; }
    static F map(const F &f, const S &x) {
        return f + x;
    }
};