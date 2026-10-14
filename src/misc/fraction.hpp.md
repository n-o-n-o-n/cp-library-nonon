---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/misc/fraction.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <numeric>\nusing namespace std;\n\n// p / q\ntemplate<typename\
    \ T>\nstruct fraction {\n    fraction() : fraction(0) {}\n    fraction(T a) :\
    \ fraction(a, 1) {}\n    fraction(T a, T b) {\n        assert(b);\n        if\
    \ (b < 0) {\n            a = -a;\n            b = -b;\n        }\n        T g\
    \ = gcd(a, b);\n        a /= g;\n        b /= g;\n        p = a;\n        q =\
    \ b;\n    }\n    pair<T, T> get() const {\n        return make_pair(p, q);\n \
    \   }\n    T numerator() const { return p; }\n    T denominator() const { return\
    \ q; }\n    fraction& operator+=(const fraction &r) {\n        T nq = lcm(q, r.q);\n\
    \        T np = p * (nq / q) + r.p * (nq / r.q);\n        return *this = fraction(np,\
    \ nq);\n    }\n    fraction& operator-=(const fraction &r) {\n        T nq = lcm(q,\
    \ r.q);\n        T np = p * (nq / q) - r.p * (nq / r.q);\n        return *this\
    \ = fraction(np, nq);\n    }\n    fraction& operator*=(const fraction &r) {\n\
    \        T g1 = gcd(p, r.q);\n        T g2 = gcd(q, r.p);\n        p /= g1;\n\
    \        q /= g2;\n        return *this = fraction(p * (r.p / g2), q * (r.q /\
    \ g1));\n    }\n    fraction& operator/=(const fraction &r) {\n        T g1 =\
    \ gcd(p, r.p);\n        T g2 = gcd(q, r.q);\n        p /= g1;\n        q /= g2;\n\
    \        return *this = fraction(p * (r.q / g2), q * (r.p / g1));\n    }\n   \
    \ friend fraction operator+(const fraction &a, const fraction &b) {\n        return\
    \ fraction(a) += b;\n    }\n    friend fraction operator-(const fraction &a, const\
    \ fraction &b) {\n        return fraction(a) -= b;\n    }\n    friend fraction\
    \ operator*(const fraction &a, const fraction &b) {\n        return fraction(a)\
    \ *= b;\n    }\n    friend fraction operator/(const fraction &a, const fraction\
    \ &b) {\n        return fraction(a) /= b;\n    }\n    friend bool operator==(const\
    \ fraction &a, const fraction &b) {\n        return a.p == b.p && a.q == b.q;\n\
    \    }\n    friend bool operator!=(const fraction &a, const fraction &b) {\n \
    \       return a.p != b.p || a.q != b.q;\n    }\n    friend bool operator<(const\
    \ fraction &a, const fraction &b) {\n        return (__int128_t)a.p * b.q < (__int128_t)a.q\
    \ * b.p;\n    }\n    friend bool operator>(const fraction &a, const fraction &b)\
    \ {\n        return b < a;\n    }\n    friend bool operator<=(const fraction &a,\
    \ const fraction &b) {\n        return a == b || a < b;\n    }\n    friend bool\
    \ operator>=(const fraction &a, const fraction &b) {\n        return a == b ||\
    \ a > b;\n    }\n    fraction operator+() const { return *this; }\n    fraction\
    \ operator-() const { return fraction() - *this; }\nprivate:\n    T p, q;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n\
    using namespace std;\n\n// p / q\ntemplate<typename T>\nstruct fraction {\n  \
    \  fraction() : fraction(0) {}\n    fraction(T a) : fraction(a, 1) {}\n    fraction(T\
    \ a, T b) {\n        assert(b);\n        if (b < 0) {\n            a = -a;\n \
    \           b = -b;\n        }\n        T g = gcd(a, b);\n        a /= g;\n  \
    \      b /= g;\n        p = a;\n        q = b;\n    }\n    pair<T, T> get() const\
    \ {\n        return make_pair(p, q);\n    }\n    T numerator() const { return\
    \ p; }\n    T denominator() const { return q; }\n    fraction& operator+=(const\
    \ fraction &r) {\n        T nq = lcm(q, r.q);\n        T np = p * (nq / q) + r.p\
    \ * (nq / r.q);\n        return *this = fraction(np, nq);\n    }\n    fraction&\
    \ operator-=(const fraction &r) {\n        T nq = lcm(q, r.q);\n        T np =\
    \ p * (nq / q) - r.p * (nq / r.q);\n        return *this = fraction(np, nq);\n\
    \    }\n    fraction& operator*=(const fraction &r) {\n        T g1 = gcd(p, r.q);\n\
    \        T g2 = gcd(q, r.p);\n        p /= g1;\n        q /= g2;\n        return\
    \ *this = fraction(p * (r.p / g2), q * (r.q / g1));\n    }\n    fraction& operator/=(const\
    \ fraction &r) {\n        T g1 = gcd(p, r.p);\n        T g2 = gcd(q, r.q);\n \
    \       p /= g1;\n        q /= g2;\n        return *this = fraction(p * (r.q /\
    \ g2), q * (r.p / g1));\n    }\n    friend fraction operator+(const fraction &a,\
    \ const fraction &b) {\n        return fraction(a) += b;\n    }\n    friend fraction\
    \ operator-(const fraction &a, const fraction &b) {\n        return fraction(a)\
    \ -= b;\n    }\n    friend fraction operator*(const fraction &a, const fraction\
    \ &b) {\n        return fraction(a) *= b;\n    }\n    friend fraction operator/(const\
    \ fraction &a, const fraction &b) {\n        return fraction(a) /= b;\n    }\n\
    \    friend bool operator==(const fraction &a, const fraction &b) {\n        return\
    \ a.p == b.p && a.q == b.q;\n    }\n    friend bool operator!=(const fraction\
    \ &a, const fraction &b) {\n        return a.p != b.p || a.q != b.q;\n    }\n\
    \    friend bool operator<(const fraction &a, const fraction &b) {\n        return\
    \ (__int128_t)a.p * b.q < (__int128_t)a.q * b.p;\n    }\n    friend bool operator>(const\
    \ fraction &a, const fraction &b) {\n        return b < a;\n    }\n    friend\
    \ bool operator<=(const fraction &a, const fraction &b) {\n        return a ==\
    \ b || a < b;\n    }\n    friend bool operator>=(const fraction &a, const fraction\
    \ &b) {\n        return a == b || a > b;\n    }\n    fraction operator+() const\
    \ { return *this; }\n    fraction operator-() const { return fraction() - *this;\
    \ }\nprivate:\n    T p, q;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/fraction.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/fraction.hpp
layout: document
redirect_from:
- /library/src/misc/fraction.hpp
- /library/src/misc/fraction.hpp.html
title: src/misc/fraction.hpp
---
