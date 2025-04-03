#pragma once
#include <algorithm>
#include <limits>

template<typename T>
struct maximum_subarray_monoid {
    static constexpr T inf = numeric_limits<T>::max() / 2;
    struct S {
        T left, right, max, sum;
        T val() const { return max; }
        S() : S(0) {}
        S(T x) : S(x, x, x, x) {}
        S(T l, T r, T m, T s) : left(l), right(r), max(m), sum(s) {}
    };
    static S op(S a, S b) {
        T new_left = max(a.left, a.sum + b.left);
        T new_right = max(b.right, b.sum + a.right);
        T new_max = max(max(a.max, b.max), a.right + b.left);
        T new_sum = a.sum + b.sum;
        return S(new_left, new_right, new_max, new_sum);
    }
    static S e() {
        return S(-inf, -inf, -inf, 0);
    }
};