---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/number_theory/primality_test.hpp
    title: src/math/number_theory/primality_test.hpp
  - icon: ':question:'
    path: src/modint/dynamic_montgomery_modint.hpp
    title: src/modint/dynamic_montgomery_modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"test/math/number_theory/primality_test.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#line 2 \"src/math/number_theory/primality_test.hpp\"\
    \n#include <array>\n#line 2 \"src/modint/dynamic_montgomery_modint.hpp\"\n#include\
    \ <algorithm>\n#include <cassert>\nusing namespace std;\n\nstruct dynamic_montgomery_modint\
    \ {\n    using i64 = __uint64_t;\n    using i128 = __uint128_t;\n    using modint\
    \ = dynamic_montgomery_modint;\n    dynamic_montgomery_modint() : x(0) {}\n  \
    \  dynamic_montgomery_modint(long long v) : x(reduce((i128(v) + MOD) * R)) {}\n\
    \    static void set_mod(long long _m) {\n        MOD = _m;\n        R = -i128(MOD)\
    \ % MOD;\n        INV = get_inv_mod(); \n    }\n    static long long mod() { return\
    \ MOD; }\n    long long val() const {\n        i64 res = reduce(x);\n        return\
    \ res >= MOD ? res - MOD : res;\n    }\n    modint& operator+=(const modint &r)\
    \ {\n        x += r.x;\n        if (x >= (MOD << 1)) x -= (MOD << 1);\n      \
    \  return *this;\n    }\n    modint& operator-=(const modint &r) {\n        x\
    \ += (MOD << 1) - r.x;\n        if (x >= (MOD << 1)) x -= (MOD << 1);\n      \
    \  return *this;\n    }\n    modint& operator*=(const modint &r) {\n        x\
    \ = reduce(i128(x) * r.x);\n        return *this;\n    }\n    modint& operator/=(const\
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
    \ - *this; }\n    modint inv() const { return pow(MOD - 2); }\n    modint pow(i128\
    \ k) const {\n        modint a = *this;\n        modint res = 1;\n        while\
    \ (k > 0) {\n            if (k & 1) res *= a;\n            a *= a;\n         \
    \   k >>= 1;\n        }\n        return res;\n    }\nprivate:\n    i64 x;\n  \
    \  static i64 MOD, INV, R;\n    static i64 get_inv_mod() {\n        i64 res =\
    \ MOD;\n        for (int t = 0; t < 5; t++) res *= 2 - MOD * res;\n        return\
    \ res;\n    }\n    static i64 reduce(const i128 &v) {\n        return (v + i128(i64(v)\
    \ * i64(-INV)) * MOD) >> 64;\n    }\n};\ntypename dynamic_montgomery_modint::i64\n\
    dynamic_montgomery_modint::MOD,\ndynamic_montgomery_modint::INV,\ndynamic_montgomery_modint::R;\n\
    #line 4 \"src/math/number_theory/primality_test.hpp\"\nusing namespace std;\n\n\
    template<size_t size>\nbool miller_rabin(long long m, const array<int, size> &ps)\
    \ {\n    using mint = dynamic_montgomery_modint;\n    mint::set_mod(m);\n    long\
    \ long u = 0, v = m - 1;\n    while ((v & 1) == 0) u++, v >>= 1;\n    for (int\
    \ p : ps) {\n        if (m <= p) return true;\n        mint x = mint(p).pow(v);\n\
    \        if (x.val() != 1) {\n            long long w;\n            for (w = 0;\
    \ w < u; w++) {\n                if (x.val() == m - 1) break;\n              \
    \  x *= x;\n            }\n            if (w == u) return false;\n        }\n\
    \    }\n    return true;\n}\n\ninline bool miller_rabin_small(long long m) {\n\
    \    return miller_rabin(m, array<int, 3>{2, 7, 61});\n}\n\ninline bool miller_rabin_large(long\
    \ long m) {\n    return miller_rabin(m, array<int, 7>{2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022});\n}\n\ninline bool is_prime(long long m) {\n    if (m\
    \ <= 1) return false;\n    if (m == 2) return true;\n    if (m % 2 == 0) return\
    \ false;\n    return m < 4759123141LL ? miller_rabin_small(m) : miller_rabin_large(m);\n\
    }\n#line 4 \"test/math/number_theory/primality_test.test.cpp\"\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ Q;\n    cin >> Q;\n    for (long long N; Q--; ) {\n        cin >> N;\n     \
    \   cout << (is_prime(N) ? \"Yes\\n\" : \"No\\n\");\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#include\
    \ \"../../../src/math/number_theory/primality_test.hpp\"\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ Q;\n    cin >> Q;\n    for (long long N; Q--; ) {\n        cin >> N;\n     \
    \   cout << (is_prime(N) ? \"Yes\\n\" : \"No\\n\");\n    }\n}"
  dependsOn:
  - src/math/number_theory/primality_test.hpp
  - src/modint/dynamic_montgomery_modint.hpp
  isVerificationFile: true
  path: test/math/number_theory/primality_test.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:16:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/number_theory/primality_test.test.cpp
layout: document
redirect_from:
- /verify/test/math/number_theory/primality_test.test.cpp
- /verify/test/math/number_theory/primality_test.test.cpp.html
title: test/math/number_theory/primality_test.test.cpp
---
