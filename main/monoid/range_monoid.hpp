#pragma once
template<typename Monoid>
struct range_monoid {
    struct S {
        Monoid::S x;
        int size;
        Monoid::S val() const { return x; }
        S() : S(Monoid::e(), 0) {}
        S(const Monoid::S &y) : S(y ,1) {}
        S(const Monoid::S &y, int t) : x(y), size(t) {}
    };
    static S op(const S &a, const S &b) {
        return S(Monoid::op(a.x, b.x), a.size + b.size);
    }
    static S e() { return S(Monoid::e(), 0); }
};