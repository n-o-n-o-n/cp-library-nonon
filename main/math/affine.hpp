#pragma once
using namespace std;

template<typename mint>
struct affine {
    mint a, b;
    affine() : a(1), b(0) {}
    affine(const mint &_a, const mint &_b) : a(_a), b(_b) {}
    mint operator()(const mint &x) {
        return a * x + b;
    }
    affine operator()(const affine &f) {
        mint c = a * f.a;
        mint d = a * f.b + b;
        return affine(c, d);
    }
};