#pragma once
#include <algorithm>
#include <cassert>
using namespace std;

struct montgomery_modint {
    using int64 = uint64_t;
    using int128 = __uint128_t;
    using modint = montgomery_modint;
    montgomery_modint() : x(0) {}
    montgomery_modint(long long v) : x(reduce((int128(v) + MOD) * R)) {}
    static void set_mod(long long _m) {
        MOD = _m;
        R = -int128(MOD) % MOD;
        INV = get_inv_mod(); 
    }
    static long long mod() { return MOD; }
    long long val() const {
        int64 res = reduce(x);
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
        x = reduce(int128(x) * r.x);
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
    modint pow(int128 k) const {
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
    int64 x;
    static int64 MOD, INV, R;
    static int64 get_inv_mod() {
        int64 res = MOD;
        for (int t = 0; t < 5; t++) res *= 2 - MOD * res;
        return res;
    }
    static int64 reduce(const int128 &v) {
        return (v + int128(int64(v) * int64(-INV)) * MOD) >> 64;
    }
};
typename montgomery_modint::int64
montgomery_modint::MOD, montgomery_modint::INV, montgomery_modint::R;
