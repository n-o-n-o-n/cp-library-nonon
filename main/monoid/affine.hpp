#pragma once
using namespace std;

template<typename mint>
struct affine {
    using S = affine;
    mint a, b;
    affine() : a(1), b(0) {}
    affine(const mint &_a, const mint &_b) : a(_a), b(_b) {}
    mint operator()(const mint &x) const {
        return a * x + b;
    }
    affine operator()(const affine &f) const {
        mint c = a * f.a;
        mint d = a * f.b + b;
        return affine(c, d);
    }
    static affine op(const affine &f, const affine &g) {
        return g(f);
    }
    static affine e() { return affine(); }
};