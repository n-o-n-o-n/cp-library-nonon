#pragma once
template<typename Monoid>
struct range_monoid {
    struct S {
        Monoid x;
        int size;
        Monoid val() const { return x; }
    };
    static S op(const S &a, const S &b) {
        return make_pair(Monoid::op(a.x, a.x), a.size + b.size);
    }
    static S e() { return make_pair(Monoid::e(), 0); }
};