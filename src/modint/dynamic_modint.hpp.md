---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/number_theory/mod_log.hpp
    title: src/math/number_theory/mod_log.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/discrete_logarithm.test.cpp
    title: test/math/number_theory/discrete_logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/mod_log.test.cpp
    title: test/math/number_theory/mod_log.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/modint/dynamic_modint.hpp\"\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\n\nstruct modint {\n    modint() : x(0)\
    \ {}\n    modint(long long v) {\n        long long y = v % m();\n        if (y\
    \ < 0) y += m();\n        x = (unsigned int)(y);\n    }\n    static void set_mod(int\
    \ _m) { MOD = _m; }\n    static modint raw(int v) {\n        modint a;\n     \
    \   a.x = v;\n        return a;\n    }\n    static int mod() { return m(); }\n\
    \    unsigned int val() const { return x; }\n    modint& operator++() {\n    \
    \    x++;\n        if (x == m()) x = 0;\n        return *this;\n    }\n    modint&\
    \ operator--() {\n        if (x == 0) x = m();\n        x--;\n        return *this;\n\
    \    }\n    modint operator++(int) {\n        modint res = *this;\n        ++*this;\n\
    \        return res;\n    }\n    modint operator--(int) {\n        modint res\
    \ = *this;\n        --*this;\n        return res;\n    }\n    modint& operator+=(const\
    \ modint &r) {\n        x += r.x;\n        if (x >= m()) x -= m();\n        return\
    \ *this;\n    }\n    modint& operator-=(const modint &r) {\n        x -= r.x;\n\
    \        if (x >= m()) x += m();\n        return *this;\n    }\n    modint& operator*=(const\
    \ modint &r) {\n        unsigned long long y = x;\n        y *= r.x;\n       \
    \ x = (unsigned int)(y % m());\n        return *this;\n    }\n    modint &operator/=(const\
    \ modint &r) {\n        return *this = *this * r.inv();\n    }\n    friend modint\
    \ operator+(const modint &a, const modint &b) {\n        return modint(a) += b;\n\
    \    }\n    friend modint operator-(const modint &a, const modint &b) {\n    \
    \    return modint(a) -= b;\n    }\n    friend modint operator*(const modint &a,\
    \ const modint &b) {\n        return modint(a) *= b;\n    }\n    friend modint\
    \ operator/(const modint &a, const modint &b) {\n        return modint(a) /= b;\n\
    \    }\n    friend bool operator==(const modint &a, const modint &b) {\n     \
    \   return a.x == b.x;\n    }\n    friend bool operator!=(const modint &a, const\
    \ modint &b) {\n        return a.x != b.x;\n    }\n    modint operator+() const\
    \ { return *this; }\n    modint operator-() const { return modint() - *this; }\n\
    \    modint pow(long long k) const {\n        assert(k >= 0);\n        modint\
    \ a = *this;\n        modint res = 1;\n        while (k > 0) {\n            if\
    \ (k & 1) res *= a;\n            a *= a;\n            k >>= 1;\n        }\n  \
    \      return res;\n    }\n    modint inv() const {\n        long long a = x,\
    \ b = m(), u = 1, v = 0;\n        while (b > 0) {\n            long long t = a\
    \ / b;\n            a -= t * b;\n            swap(a, b);\n            u -= t *\
    \ v;\n            swap(u, v);\n        }\n        return modint(u);\n    }\nprivate:\n\
    \    unsigned int x;\n    static unsigned int MOD;\n    static unsigned int m()\
    \ { return MOD; }\n};\nunsigned int modint::MOD = -1;\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\nusing namespace std;\n\
    \nstruct modint {\n    modint() : x(0) {}\n    modint(long long v) {\n       \
    \ long long y = v % m();\n        if (y < 0) y += m();\n        x = (unsigned\
    \ int)(y);\n    }\n    static void set_mod(int _m) { MOD = _m; }\n    static modint\
    \ raw(int v) {\n        modint a;\n        a.x = v;\n        return a;\n    }\n\
    \    static int mod() { return m(); }\n    unsigned int val() const { return x;\
    \ }\n    modint& operator++() {\n        x++;\n        if (x == m()) x = 0;\n\
    \        return *this;\n    }\n    modint& operator--() {\n        if (x == 0)\
    \ x = m();\n        x--;\n        return *this;\n    }\n    modint operator++(int)\
    \ {\n        modint res = *this;\n        ++*this;\n        return res;\n    }\n\
    \    modint operator--(int) {\n        modint res = *this;\n        --*this;\n\
    \        return res;\n    }\n    modint& operator+=(const modint &r) {\n     \
    \   x += r.x;\n        if (x >= m()) x -= m();\n        return *this;\n    }\n\
    \    modint& operator-=(const modint &r) {\n        x -= r.x;\n        if (x >=\
    \ m()) x += m();\n        return *this;\n    }\n    modint& operator*=(const modint\
    \ &r) {\n        unsigned long long y = x;\n        y *= r.x;\n        x = (unsigned\
    \ int)(y % m());\n        return *this;\n    }\n    modint &operator/=(const modint\
    \ &r) {\n        return *this = *this * r.inv();\n    }\n    friend modint operator+(const\
    \ modint &a, const modint &b) {\n        return modint(a) += b;\n    }\n    friend\
    \ modint operator-(const modint &a, const modint &b) {\n        return modint(a)\
    \ -= b;\n    }\n    friend modint operator*(const modint &a, const modint &b)\
    \ {\n        return modint(a) *= b;\n    }\n    friend modint operator/(const\
    \ modint &a, const modint &b) {\n        return modint(a) /= b;\n    }\n    friend\
    \ bool operator==(const modint &a, const modint &b) {\n        return a.x == b.x;\n\
    \    }\n    friend bool operator!=(const modint &a, const modint &b) {\n     \
    \   return a.x != b.x;\n    }\n    modint operator+() const { return *this; }\n\
    \    modint operator-() const { return modint() - *this; }\n    modint pow(long\
    \ long k) const {\n        assert(k >= 0);\n        modint a = *this;\n      \
    \  modint res = 1;\n        while (k > 0) {\n            if (k & 1) res *= a;\n\
    \            a *= a;\n            k >>= 1;\n        }\n        return res;\n \
    \   }\n    modint inv() const {\n        long long a = x, b = m(), u = 1, v =\
    \ 0;\n        while (b > 0) {\n            long long t = a / b;\n            a\
    \ -= t * b;\n            swap(a, b);\n            u -= t * v;\n            swap(u,\
    \ v);\n        }\n        return modint(u);\n    }\nprivate:\n    unsigned int\
    \ x;\n    static unsigned int MOD;\n    static unsigned int m() { return MOD;\
    \ }\n};\nunsigned int modint::MOD = -1;"
  dependsOn: []
  isVerificationFile: false
  path: src/modint/dynamic_modint.hpp
  requiredBy:
  - src/math/number_theory/mod_log.hpp
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/number_theory/discrete_logarithm.test.cpp
  - test/math/number_theory/mod_log.test.cpp
documentation_of: src/modint/dynamic_modint.hpp
layout: document
redirect_from:
- /library/src/modint/dynamic_modint.hpp
- /library/src/modint/dynamic_modint.hpp.html
title: src/modint/dynamic_modint.hpp
---
