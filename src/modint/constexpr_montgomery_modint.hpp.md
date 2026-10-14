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
  bundledCode: "#line 2 \"src/modint/constexpr_montgomery_modint.hpp\"\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate<long long MOD>\nstruct static_montgomery_modint\
    \ {\n    using i64 = uint64_t;\n    using i128 = __uint128_t;\n    using modint\
    \ = static_montgomery_modint;\n    constexpr static_montgomery_modint() : x(0)\
    \ {}\n    constexpr static_montgomery_modint(long long v) : x(reduce((i128(v)\
    \ + m()) * r())) {}\n    static constexpr long long mod() { return m(); }\n  \
    \  constexpr long long val() const {\n        i64 res = reduce(x);\n        return\
    \ res >= m() ? res - m() : res;\n    }\n    constexpr modint& operator+=(const\
    \ modint &r) {\n        x += r.x;\n        if (x >= (m() << 1)) x -= m() << 1;\n\
    \        return *this;\n    }\n    constexpr modint& operator-=(const modint &r)\
    \ {\n        x += (m() << 1) - r.x;\n        if (x >= (m() << 1)) x -= m() <<\
    \ 1;\n        return *this;\n    }\n    constexpr modint& operator*=(const modint\
    \ &r) {\n        x = reduce(i128(x) * r.x);\n        return *this;\n    }\n  \
    \  constexpr modint& operator/=(const modint &r) {\n        *this *= r.inv();\n\
    \        return *this;\n    }\n    friend constexpr modint operator+(const modint\
    \ &a, const modint &b) {\n        return modint(a) += b;\n    }\n    friend constexpr\
    \ modint operator-(const modint &a, const modint &b) {\n        return modint(a)\
    \ -= b;\n    }\n    friend constexpr modint operator*(const modint &a, const modint\
    \ &b) {\n        return modint(a) *= b;\n    }\n    friend constexpr modint operator/(const\
    \ modint &a, const modint &b) {\n        return modint(a) /= b;\n    }\n    friend\
    \ constexpr bool operator==(const modint &a, const modint &b) {\n        return\
    \ a.val() == b.val();\n    }\n    friend constexpr bool operator!=(const modint\
    \ &a, const modint &b) {\n        return a.val() != b.val();\n    }\n    constexpr\
    \ modint operator+() const { return *this; }\n    constexpr modint operator-()\
    \ const { return modint() - *this; }\n    constexpr modint inv() const { return\
    \ pow(m() - 2); }\n    constexpr modint pow(i128 k) const {\n        modint a\
    \ = *this, res = 1;\n        while (k > 0) {\n            if (k & 1) res *= a;\n\
    \            a *= a;\n            k >>= 1;\n        }\n        return res;\n \
    \   }\nprivate:\n    i64 x;\n    static constexpr i64 m() { return MOD; }\n  \
    \  static constexpr i64 _r = -i128(m()) % m();\n    static constexpr i64 _i =\
    \ [] constexpr {\n        i64 r = m();\n        for (int t = 0; t < 5; t++) r\
    \ *= 2 - m() * r;\n        return r;\n    } ();\n    static constexpr i64 r()\
    \ { return _r; }\n    static constexpr i64 i() { return _i; }\n    static constexpr\
    \  i64 reduce(const i128 &v) {\n        return (v + i128(-i() * i64(v)) * m())\
    \ >> 64;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\nusing namespace std;\n\
    \ntemplate<long long MOD>\nstruct static_montgomery_modint {\n    using i64 =\
    \ uint64_t;\n    using i128 = __uint128_t;\n    using modint = static_montgomery_modint;\n\
    \    constexpr static_montgomery_modint() : x(0) {}\n    constexpr static_montgomery_modint(long\
    \ long v) : x(reduce((i128(v) + m()) * r())) {}\n    static constexpr long long\
    \ mod() { return m(); }\n    constexpr long long val() const {\n        i64 res\
    \ = reduce(x);\n        return res >= m() ? res - m() : res;\n    }\n    constexpr\
    \ modint& operator+=(const modint &r) {\n        x += r.x;\n        if (x >= (m()\
    \ << 1)) x -= m() << 1;\n        return *this;\n    }\n    constexpr modint& operator-=(const\
    \ modint &r) {\n        x += (m() << 1) - r.x;\n        if (x >= (m() << 1)) x\
    \ -= m() << 1;\n        return *this;\n    }\n    constexpr modint& operator*=(const\
    \ modint &r) {\n        x = reduce(i128(x) * r.x);\n        return *this;\n  \
    \  }\n    constexpr modint& operator/=(const modint &r) {\n        *this *= r.inv();\n\
    \        return *this;\n    }\n    friend constexpr modint operator+(const modint\
    \ &a, const modint &b) {\n        return modint(a) += b;\n    }\n    friend constexpr\
    \ modint operator-(const modint &a, const modint &b) {\n        return modint(a)\
    \ -= b;\n    }\n    friend constexpr modint operator*(const modint &a, const modint\
    \ &b) {\n        return modint(a) *= b;\n    }\n    friend constexpr modint operator/(const\
    \ modint &a, const modint &b) {\n        return modint(a) /= b;\n    }\n    friend\
    \ constexpr bool operator==(const modint &a, const modint &b) {\n        return\
    \ a.val() == b.val();\n    }\n    friend constexpr bool operator!=(const modint\
    \ &a, const modint &b) {\n        return a.val() != b.val();\n    }\n    constexpr\
    \ modint operator+() const { return *this; }\n    constexpr modint operator-()\
    \ const { return modint() - *this; }\n    constexpr modint inv() const { return\
    \ pow(m() - 2); }\n    constexpr modint pow(i128 k) const {\n        modint a\
    \ = *this, res = 1;\n        while (k > 0) {\n            if (k & 1) res *= a;\n\
    \            a *= a;\n            k >>= 1;\n        }\n        return res;\n \
    \   }\nprivate:\n    i64 x;\n    static constexpr i64 m() { return MOD; }\n  \
    \  static constexpr i64 _r = -i128(m()) % m();\n    static constexpr i64 _i =\
    \ [] constexpr {\n        i64 r = m();\n        for (int t = 0; t < 5; t++) r\
    \ *= 2 - m() * r;\n        return r;\n    } ();\n    static constexpr i64 r()\
    \ { return _r; }\n    static constexpr i64 i() { return _i; }\n    static constexpr\
    \  i64 reduce(const i128 &v) {\n        return (v + i128(-i() * i64(v)) * m())\
    \ >> 64;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/modint/constexpr_montgomery_modint.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/modint/constexpr_montgomery_modint.hpp
layout: document
redirect_from:
- /library/src/modint/constexpr_montgomery_modint.hpp
- /library/src/modint/constexpr_montgomery_modint.hpp.html
title: src/modint/constexpr_montgomery_modint.hpp
---
