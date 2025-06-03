#pragma once
#include <cassert>
#include <cmath>
#include <numeric>
using namespace std;

// floor( a ^ (1/k) )
template<typename T>
T floor_kth_root(T a, T k) {
    assert(0 <= a);
    if (a == 0 || a == 1 || k == 1) return a;
    if (64 <= k) return 1;
    if (k == 2) return sqrtl(a);
    constexpr T inf = numeric_limits<T>::max();
    if (a == inf) a--;
    auto mul = [&](T x, T y) -> T {
        return x <= inf / y ? x * y : inf;
    };
    auto pw = [&](T x, T n) -> T {
        T r = 1;
        while (n > 0) {
            if (n & 1) r = mul(r, x);
            x = mul(x, x);
            n >>= 1;
        }
        return r;
    };
    T res = (k == 3 ? cbrtl(a) - 1 : pow(a, nextafter(1.0 / k, 0)));
    while (pw(res + 1, k) <= a) res++;
    return res;
}