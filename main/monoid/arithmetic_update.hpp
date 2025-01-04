#pragma once
#include <limits>
using namespace std;

template<typename T>
struct arithmetic_update {
    static constexpr T inf = numeric_limits<T>::max() / 2;
    struct S {
        T mn, mx, sm;
        int l, r;
        T min() const { return mn; }
        T max() const { return mx; }
        T sum() const { return sm; }
        S() : S(inf, -inf, 0, numeric_limits<int>::max(), -numeric_limits<int>::max()) {}
        S(T x, int p) : S(x, x, x, p, p + 1) {}
        S(T _mn, T _mx, T _sm, int _l, int _r) : mn(_mn), mx(_mx), sm(_sm), l(_l), r(_r) {}
    };
    static S op(const S &a, const S &b) {
        S c;
        c.mn = min(a.min(), b.min());
        c.mx = max(a.max(), b.max());
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
        F() : F(inf, inf) {}
        F(T _a, T _b) : a(_a), b(_b) {}
        bool operator==(F f) {
            return a == f.a && b == f.b;
        }
    };
    static F comp(const F &f, const F &g) {
        return f == id() ? g : f;
    }
    static F id() {
        return F();
    }
    static S mapping(const F &f, const S &x) {
        if (f == id()) return x;
        S y;
        y.mn = min(f.a * x.l, f.a * (x.r - 1)) + f.b;
        y.mx = max(f.a * x.l, f.a * (x.r - 1)) + f.b;
        y.sm = (f.a * (x.l + x.r - 1) + f.b * 2) * (x.r - x.l) / 2;
        y.l = x.l;
        y.r = x.r;
        return y;
    }
};
