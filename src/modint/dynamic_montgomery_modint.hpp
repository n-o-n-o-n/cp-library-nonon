#pragma once
#include <algorithm>
#include <cassert>
using namespace std;

struct dynamic_montgomery_modint {
    using i64 = __uint64_t;
    using i128 = __uint128_t;
    using modint = dynamic_montgomery_modint;
    dynamic_montgomery_modint() : x(0) {}
    dynamic_montgomery_modint(long long v) : x(reduce((i128(v) + MOD) * R)) {}
    static void set_mod(long long _m) {
        MOD = _m;
        R = -i128(MOD) % MOD;
        INV = get_inv_mod(); 
    }
    static long long mod() { return MOD; }
    long long val() const {
        i64 res = reduce(x);
        return res >= MOD ? res - MOD : res;
    }
    modint& operator+=(const modint &r) {
        x += r.x;
        if (x >= (MOD << 1)) x -= (MOD << 1);
        return *this;
    }
    modint& operator-=(const modint &r) {
        x += (MOD << 1) - r.x;
        if (x >= (MOD << 1)) x -= (MOD << 1);
        return *this;
    }
    modint& operator*=(const modint &r) {
        x = reduce(i128(x) * r.x);
        return *this;
    }
    modint& operator/=(const modint &r) {
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
    modint inv() const { return pow(MOD - 2); }
    modint pow(i128 k) const {
        modint a = *this;
        modint res = 1;
        while (k > 0) {
            if (k & 1) res *= a;
            a *= a;
            k >>= 1;
        }
        return res;
    }
private:
    i64 x;
    static i64 MOD, INV, R;
    static i64 get_inv_mod() {
        i64 res = MOD;
        for (int t = 0; t < 5; t++) res *= 2 - MOD * res;
        return res;
    }
    static i64 reduce(const i128 &v) {
        return (v + i128(i64(v) * i64(-INV)) * MOD) >> 64;
    }
};
typename dynamic_montgomery_modint::i64
dynamic_montgomery_modint::MOD,
dynamic_montgomery_modint::INV,
dynamic_montgomery_modint::R;
