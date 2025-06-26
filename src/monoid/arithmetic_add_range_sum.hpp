#pragma once
#include <limits>
using namespace std;

// apply(l, r, F(a, b)): for i in [l, r); v[i] += a * i + b
// If you want to apply it for i in [0, k); v[i + l] += a * i + b,
// you should use apply(l, r, F(a, b - a * l))
template<typename T>
struct arithmetic_add_range_sum {
    static constexpr int inf = numeric_limits<int>::max() / 2;
    struct S {
        T sm;
        int l, r;
        T sum() const { return sm; }
        S() : S(0, inf, -inf) {}
        S(T x, int p) : S(x, p, p + 1) {}
        S(T _sm, int _l, int _r) : sm(_sm), l(_l), r(_r) {}
    };
    static S op(const S&a, const S &b) {
        S c;
        c.sm = a.sum() + b.sum();
        c.l = min(a.l, b.l);
        c.r = max(a.r, b.r);
        return c;
    }
    static S e() {
        return S();
    }
    struct F {
        T a, b;
        F() : F(0, 0) {}
        F(T _a, T _b) : a(_a), b(_b) {}
    };
    static F comp(const F &f, const F &g) {
        return F(f.a + g.a, f.b + g.b);
    }
    static F id() {
        return F();
    }
    static S map(const F &f, const S &x) {
        S y;
        y.sm = x.sm + (f.a * (x.l + x.r - 1) + f.b * 2) * (x.r - x.l) / 2;
        y.l = x.l;
        y.r = x.r;
        return y;
    }
};