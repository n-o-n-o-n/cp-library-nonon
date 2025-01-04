#pragma once
#include <limits>
using namespace std;

template<typename mint>
struct arithmetic_update_range_sum {
    static constexpr int inf = numeric_limits<int>::max() / 2;
    struct S {
        mint sm;
        int l, r;
        mint sum() const { return sm; }
        S() : S(0, numeric_limits<int>::max(), -numeric_limits<int>::max()) {}
        S(mint x, int p) : S(x, p, p + 1) {}
        S(mint _sm, int _l, int _r) : sm(_sm), l(_l), r(_r) {}
    };
    static S op(const S &a, const S &b) {
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
        mint a, b;
        F() : F(0, 0) {}
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
        y.sm = (f.a * (x.l + x.r - 1) + f.b * 2) * (x.r - x.l) / 2;
        y.l = x.l;
        y.r = x.r;
        return y;
    }
};