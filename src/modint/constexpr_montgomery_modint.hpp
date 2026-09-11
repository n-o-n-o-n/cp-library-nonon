#pragma once
#include <algorithm>
#include <cassert>
using namespace std;

template<long long MOD>
struct static_montgomery_modint {
    using i64 = uint64_t;
    using i128 = __uint128_t;
    using modint = static_montgomery_modint;
    constexpr static_montgomery_modint() : x(0) {}
    constexpr static_montgomery_modint(long long v) : x(reduce((i128(v) + m()) * r())) {}
    static constexpr long long mod() { return m(); }
    constexpr long long val() const {
        i64 res = reduce(x);
        return res >= m() ? res - m() : res;
    }
    constexpr modint& operator+=(const modint &r) {
        x += r.x;
        if (x >= (m() << 1)) x -= m() << 1;
        return *this;
    }
    constexpr modint& operator-=(const modint &r) {
        x += (m() << 1) - r.x;
        if (x >= (m() << 1)) x -= m() << 1;
        return *this;
    }
    constexpr modint& operator*=(const modint &r) {
        x = reduce(i128(x) * r.x);
        return *this;
    }
    constexpr modint& operator/=(const modint &r) {
        *this *= r.inv();
        return *this;
    }
    friend constexpr modint operator+(const modint &a, const modint &b) {
        return modint(a) += b;
    }
    friend constexpr modint operator-(const modint &a, const modint &b) {
        return modint(a) -= b;
    }
    friend constexpr modint operator*(const modint &a, const modint &b) {
        return modint(a) *= b;
    }
    friend constexpr modint operator/(const modint &a, const modint &b) {
        return modint(a) /= b;
    }
    friend constexpr bool operator==(const modint &a, const modint &b) {
        return a.val() == b.val();
    }
    friend constexpr bool operator!=(const modint &a, const modint &b) {
        return a.val() != b.val();
    }
    constexpr modint operator+() const { return *this; }
    constexpr modint operator-() const { return modint() - *this; }
    constexpr modint inv() const { return pow(m() - 2); }
    constexpr modint pow(i128 k) const {
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
    static constexpr i64 m() { return MOD; }
    static constexpr i64 _r = -i128(m()) % m();
    static constexpr i64 _i = [] constexpr {
        i64 r = m();
        for (int t = 0; t < 5; t++) r *= 2 - m() * r;
        return r;
    } ();
    static constexpr i64 r() { return _r; }
    static constexpr i64 i() { return _i; }
    static constexpr  i64 reduce(const i128 &v) {
        return (v + i128(-i() * i64(v)) * m()) >> 64;
    }
};