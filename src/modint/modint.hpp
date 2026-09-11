#pragma once
#include <algorithm>
#include <cassert>
using namespace std;

template<int MOD>
struct modint {
    constexpr modint() : x(0) {}
    constexpr modint(long long v) {
        long long y = v % m();
        if (y < 0) y += m();
        x = (unsigned int)(y);
    }
    static constexpr modint raw(int v) {
        modint a;
        a.x = v;
        return a;
    }
    static constexpr int mod() { return m(); }
    constexpr unsigned int val() const { return x; }
    constexpr modint& operator++() {
        x++;
        if (x == m()) x = 0;
        return *this;
    }
    constexpr modint& operator--() {
        if (x == 0) x = m();
        x--;
        return *this;
    }
    constexpr modint operator++(int) {
        modint res = *this;
        ++*this;
        return res;
    }
    constexpr modint operator--(int) {
        modint res = *this;
        --*this;
        return res;
    }
    constexpr modint& operator+=(const modint &r) {
        x += r.x;
        if (x >= m()) x -= m();
        return *this;
    }
    constexpr modint& operator-=(const modint &r) {
        x -= r.x;
        if (x >= m()) x += m();
        return *this;
    }
    constexpr modint& operator*=(const modint &r) {
        unsigned long long y = x;
        y *= r.x;
        x = (unsigned int)(y % m());
        return *this;
    }
    constexpr modint &operator/=(const modint &r) {
        return *this = *this * r.inv();
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
        return a.x == b.x;
    }
    friend constexpr bool operator!=(const modint &a, const modint &b) {
        return a.x != b.x;
    }
    constexpr modint operator+() const { return *this; }
    constexpr modint operator-() const { return modint() - *this; }
    constexpr modint pow(long long k) const {
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
    constexpr modint inv() const {
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
    static constexpr unsigned int m() { return MOD; }
};