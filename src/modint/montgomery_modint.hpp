#pragma once
#include <algorithm>
#include <cassert>
using namespace std;

template<uint64_t MOD>
struct montgomery_modint {
    using i64 = __uint64_t;
    using i128 = __uint128_t;
    using modint = montgomery_modint;
    montgomery_modint() : x(0) {}
    montgomery_modint(long long v) : x(reduce((i128(v) * MOD) * R)) {}
    static i64 mod() { return m(); }
    static modint raw(long long v) { return modint(v); }
    long long val() const {
        auto res = reduce(x);
        return res >= m() ? res - m() : res;
    }
    modint& operator+=(const modint &r) {
        x += r.x;
        if (x >= (m() << 1)) x -= m() << 1;
        return *this;
    }
    modint& operator-=(const modint &r) {
        x += (m() << 1) - r.x;
        if (x >= (m() << 1)) x -= m() << 1;
        return *this;
    }
    modint& operator*=(const modint &r) {
        x = reduce(i128(x) * r.x);
        return *this;
    }
    modint &operator/=(const modint &r) {
        *this *= r.inv();
        return *this;
    }
    friend modint operator+(const modint &a, const modint &b) {
        return modint(a) += b;
    }
    friend modint operator-(const modint &a, const modint &b) {
        return modint(a) -= b;
    }
    friend modint operator*(const modint &a, const modint &b) {
        return modint(a) *= b;
    }
    friend modint operator/(const modint &a, const modint &b) {
        return modint(a) /= b;
    }
    friend bool operator==(const modint &a, const modint &b) {
        return a.val() == b.val();
    }
    friend bool operator!=(const modint &a, const modint &b) {
        return a.val() != b.val();
    }
    modint operator+() const { return *this; }
    modint operator-() const { return modint() - *this; }
    modint inv() const { return pow(m() - 2); }
    modint pow(long long k) const {
        modint a = *this, res = 1;
        while (k > 0) {
            if (k & 1) res *= a;
            a *= a;
            k >>= 1;
        }
        return res;
    }
private:
    i64 x;
    static constexpr i64 INV = [] {
        i64 res = MOD;
        for (int t = 0; t < 5; t++) res *= 2 - MOD * res;
        return res;
    } ();
    static constexpr i64 R = -i128(MOD) % MOD;
    static constexpr i64 m() { return MOD; }
    static constexpr i64 i() { return INV; }
    static constexpr i64 r() { return R; }
    static i64 reduce(const i128 &v) {
        return (v + i128(i64(v) * i64(-i())) * m()) >> 64;
    }
};