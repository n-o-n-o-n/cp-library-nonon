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
  bundledCode: "#line 2 \"src/modint/montgomery_modint.hpp\"\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate<uint64_t MOD>\nstruct montgomery_modint\
    \ {\n    using i64 = __uint64_t;\n    using i128 = __uint128_t;\n    using modint\
    \ = montgomery_modint;\n    montgomery_modint() : x(0) {}\n    montgomery_modint(long\
    \ long v) : x(reduce((i128(v) * MOD) * R)) {}\n    static i64 mod() { return m();\
    \ }\n    static modint raw(long long v) { return modint(v); }\n    long long val()\
    \ const {\n        auto res = reduce(x);\n        return res >= m() ? res - m()\
    \ : res;\n    }\n    modint& operator+=(const modint &r) {\n        x += r.x;\n\
    \        if (x >= (m() << 1)) x -= m() << 1;\n        return *this;\n    }\n \
    \   modint& operator-=(const modint &r) {\n        x += (m() << 1) - r.x;\n  \
    \      if (x >= (m() << 1)) x -= m() << 1;\n        return *this;\n    }\n   \
    \ modint& operator*=(const modint &r) {\n        x = reduce(i128(x) * r.x);\n\
    \        return *this;\n    }\n    modint &operator/=(const modint &r) {\n   \
    \     *this *= r.inv();\n        return *this;\n    }\n    friend modint operator+(const\
    \ modint &a, const modint &b) {\n        return modint(a) += b;\n    }\n    friend\
    \ modint operator-(const modint &a, const modint &b) {\n        return modint(a)\
    \ -= b;\n    }\n    friend modint operator*(const modint &a, const modint &b)\
    \ {\n        return modint(a) *= b;\n    }\n    friend modint operator/(const\
    \ modint &a, const modint &b) {\n        return modint(a) /= b;\n    }\n    friend\
    \ bool operator==(const modint &a, const modint &b) {\n        return a.val()\
    \ == b.val();\n    }\n    friend bool operator!=(const modint &a, const modint\
    \ &b) {\n        return a.val() != b.val();\n    }\n    modint operator+() const\
    \ { return *this; }\n    modint operator-() const { return modint() - *this; }\n\
    \    modint inv() const { return pow(m() - 2); }\n    modint pow(long long k)\
    \ const {\n        modint a = *this, res = 1;\n        while (k > 0) {\n     \
    \       if (k & 1) res *= a;\n            a *= a;\n            k >>= 1;\n    \
    \    }\n        return res;\n    }\nprivate:\n    i64 x;\n    static constexpr\
    \ i64 INV = [] {\n        i64 res = MOD;\n        for (int t = 0; t < 5; t++)\
    \ res *= 2 - MOD * res;\n        return res;\n    } ();\n    static constexpr\
    \ i64 R = -i128(MOD) % MOD;\n    static constexpr i64 m() { return MOD; }\n  \
    \  static constexpr i64 i() { return INV; }\n    static constexpr i64 r() { return\
    \ R; }\n    static i64 reduce(const i128 &v) {\n        return (v + i128(i64(v)\
    \ * i64(-i())) * m()) >> 64;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\nusing namespace std;\n\
    \ntemplate<uint64_t MOD>\nstruct montgomery_modint {\n    using i64 = __uint64_t;\n\
    \    using i128 = __uint128_t;\n    using modint = montgomery_modint;\n    montgomery_modint()\
    \ : x(0) {}\n    montgomery_modint(long long v) : x(reduce((i128(v) * MOD) * R))\
    \ {}\n    static i64 mod() { return m(); }\n    static modint raw(long long v)\
    \ { return modint(v); }\n    long long val() const {\n        auto res = reduce(x);\n\
    \        return res >= m() ? res - m() : res;\n    }\n    modint& operator+=(const\
    \ modint &r) {\n        x += r.x;\n        if (x >= (m() << 1)) x -= m() << 1;\n\
    \        return *this;\n    }\n    modint& operator-=(const modint &r) {\n   \
    \     x += (m() << 1) - r.x;\n        if (x >= (m() << 1)) x -= m() << 1;\n  \
    \      return *this;\n    }\n    modint& operator*=(const modint &r) {\n     \
    \   x = reduce(i128(x) * r.x);\n        return *this;\n    }\n    modint &operator/=(const\
    \ modint &r) {\n        *this *= r.inv();\n        return *this;\n    }\n    friend\
    \ modint operator+(const modint &a, const modint &b) {\n        return modint(a)\
    \ += b;\n    }\n    friend modint operator-(const modint &a, const modint &b)\
    \ {\n        return modint(a) -= b;\n    }\n    friend modint operator*(const\
    \ modint &a, const modint &b) {\n        return modint(a) *= b;\n    }\n    friend\
    \ modint operator/(const modint &a, const modint &b) {\n        return modint(a)\
    \ /= b;\n    }\n    friend bool operator==(const modint &a, const modint &b) {\n\
    \        return a.val() == b.val();\n    }\n    friend bool operator!=(const modint\
    \ &a, const modint &b) {\n        return a.val() != b.val();\n    }\n    modint\
    \ operator+() const { return *this; }\n    modint operator-() const { return modint()\
    \ - *this; }\n    modint inv() const { return pow(m() - 2); }\n    modint pow(long\
    \ long k) const {\n        modint a = *this, res = 1;\n        while (k > 0) {\n\
    \            if (k & 1) res *= a;\n            a *= a;\n            k >>= 1;\n\
    \        }\n        return res;\n    }\nprivate:\n    i64 x;\n    static constexpr\
    \ i64 INV = [] {\n        i64 res = MOD;\n        for (int t = 0; t < 5; t++)\
    \ res *= 2 - MOD * res;\n        return res;\n    } ();\n    static constexpr\
    \ i64 R = -i128(MOD) % MOD;\n    static constexpr i64 m() { return MOD; }\n  \
    \  static constexpr i64 i() { return INV; }\n    static constexpr i64 r() { return\
    \ R; }\n    static i64 reduce(const i128 &v) {\n        return (v + i128(i64(v)\
    \ * i64(-i())) * m()) >> 64;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/modint/montgomery_modint.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/modint/montgomery_modint.hpp
layout: document
redirect_from:
- /library/src/modint/montgomery_modint.hpp
- /library/src/modint/montgomery_modint.hpp.html
title: src/modint/montgomery_modint.hpp
---
