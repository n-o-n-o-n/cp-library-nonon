#pragma once
#include <algorithm>
#include <cassert>
#include <numeric>
using namespace std;

// p / q
template<typename T>
struct fraction {
    fraction() : fraction(0) {}
    fraction(T a) : fraction(a, 1) {}
    fraction(T a, T b) {
        assert(b);
        if (b < 0) {
            a = -a;
            b = -b;
        }
        T g = gcd(a, b);
        a /= g;
        b /= g;
        p = a;
        q = b;
    }
    pair<T, T> get() const {
        return make_pair(p, q);
    }
    T numerator() const { return p; }
    T denominator() const { return q; }
    fraction& operator+=(const fraction &r) {
        T nq = lcm(q, r.q);
        T np = p * (nq / q) + r.p * (nq / r.q);
        return *this = fraction(np, nq);
    }
    fraction& operator-=(const fraction &r) {
        T nq = lcm(q, r.q);
        T np = p * (nq / q) - r.p * (nq / r.q);
        return *this = fraction(np, nq);
    }
    fraction& operator*=(const fraction &r) {
        T g1 = gcd(p, r.q);
        T g2 = gcd(q, r.p);
        p /= g1;
        q /= g2;
        return *this = fraction(p * (r.p / g2), q * (r.q / g1));
    }
    fraction& operator/=(const fraction &r) {
        T g1 = gcd(p, r.p);
        T g2 = gcd(q, r.q);
        p /= g1;
        q /= g2;
        return *this = fraction(p * (r.q / g2), q * (r.p / g1));
    }
    friend fraction operator+(const fraction &a, const fraction &b) {
        return fraction(a) += b;
    }
    friend fraction operator-(const fraction &a, const fraction &b) {
        return fraction(a) -= b;
    }
    friend fraction operator*(const fraction &a, const fraction &b) {
        return fraction(a) *= b;
    }
    friend fraction operator/(const fraction &a, const fraction &b) {
        return fraction(a) /= b;
    }
    friend bool operator==(const fraction &a, const fraction &b) {
        return a.p == b.p && a.q == b.q;
    }
    friend bool operator!=(const fraction &a, const fraction &b) {
        return a.p != b.p || a.q != b.q;
    }
    friend bool operator<(const fraction &a, const fraction &b) {
        return (__int128_t)a.p * b.q < (__int128_t)a.q * b.p;
    }
    friend bool operator>(const fraction &a, const fraction &b) {
        return b < a;
    }
    friend bool operator<=(const fraction &a, const fraction &b) {
        return a == b || a < b;
    }
    friend bool operator>=(const fraction &a, const fraction &b) {
        return a == b || a > b;
    }
    fraction operator+() const { return *this; }
    fraction operator-() const { return fraction() - *this; }
private:
    T p, q;
};
