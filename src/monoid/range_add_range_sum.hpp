#pragma once
#include <utility>
using namespace std;

template<typename T>
struct range_add_range_sum {
    using S = pair<T, int>;
    static S op(S a, S b) {
        a.first += b.first;
        a.second += b.second;
        return a;
    }
    static S e() { return S{0, 0}; }
    using F = T;
    static F comp(F f, F g) { return f + g; }
    static F id() { return 0; }
    static S map(F f, S x) {
        x.first += f * x.second;
        return x;
    }
};