#pragma once
#include <algorithm>
#include <cassert>
using namespace std;

struct modint {
    modint() : x(0) {}
    modint(long long v) {
        long long y = v % m();
        if (y < 0) y += m();
        x = (unsigned int)(y);
    }
    static void set_mod(int _m) { MOD = _m; }
    static modint raw(int v) {
        modint a;
        a.x = v;
        return a;
    }
    static int mod() { return m(); }
    unsigned int val() const { return x; }
    modint& operator++() {
        x++;
        if (x == m()) x = 0;
        return *this;
    }
    modint& operator--() {
        if (x == 0) x = m();
        x--;
        return *this;
    }
    modint operator++(int) {
        modint res = *this;
        ++*this;
        return res;
    }
    modint operator--(int) {
        modint res = *this;
        --*this;
        return res;
    }
    modint& operator+=(const modint &r) {
        x += r.x;
        if (x >= m()) x -= m();
        return *this;
    }
    modint& operator-=(const modint &r) {
        x -= r.x;
        if (x >= m()) x += m();
        return *this;
    }
    modint& operator*=(const modint &r) {
        unsigned long long y = x;
        y *= r.x;
        x = (unsigned int)(y % m());
        return *this;
    }
    modint &operator/=(const modint &r) {
        return *this = *this * r.inv();
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
        return a.x == b.x;
    }
    friend bool operator!=(const modint &a, const modint &b) {
        return a.x != b.x;
    }
    modint operator+() const { return *this; }
    modint operator-() const { return modint() - *this; }
    modint pow(long long k) const {
        assert(k >= 0);
        modint a = *this;
        modint res = 1;
        while (k > 0) {
            if (k & 1) res *= a;
            a *= a;
            k >>= 1;
        }
        return res;
    }
    modint inv() const {
        long long a = x, b = m(), u = 1, v = 0;
        while (b > 0) {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        return modint(u);
    }
private:
    unsigned int x;
    static unsigned int MOD;
    static unsigned int m() { return MOD; }
};
unsigned int modint::MOD = -1;