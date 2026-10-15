---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/number_theory/primality_test.hpp
    title: src/math/number_theory/primality_test.hpp
  - icon: ':question:'
    path: src/modint/dynamic_montgomery_modint.hpp
    title: src/modint/dynamic_montgomery_modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/modint/modint.hpp
    title: src/modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://maspypy.com/o1-mod-inv-mod-pow
  bundledCode: "#line 2 \"src/modint/Fp.hpp\"\n#include <array>\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n#line 2 \"src/modint/modint.hpp\"\n#include\
    \ <algorithm>\n#line 4 \"src/modint/modint.hpp\"\nusing namespace std;\n\ntemplate<int\
    \ MOD>\nstruct modint {\n    constexpr modint() : x(0) {}\n    constexpr modint(long\
    \ long v) {\n        long long y = v % m();\n        if (y < 0) y += m();\n  \
    \      x = (unsigned int)(y);\n    }\n    static constexpr modint raw(int v) {\n\
    \        modint a;\n        a.x = v;\n        return a;\n    }\n    static constexpr\
    \ int mod() { return m(); }\n    constexpr unsigned int val() const { return x;\
    \ }\n    constexpr modint& operator++() {\n        x++;\n        if (x == m())\
    \ x = 0;\n        return *this;\n    }\n    constexpr modint& operator--() {\n\
    \        if (x == 0) x = m();\n        x--;\n        return *this;\n    }\n  \
    \  constexpr modint operator++(int) {\n        modint res = *this;\n        ++*this;\n\
    \        return res;\n    }\n    constexpr modint operator--(int) {\n        modint\
    \ res = *this;\n        --*this;\n        return res;\n    }\n    constexpr modint&\
    \ operator+=(const modint &r) {\n        x += r.x;\n        if (x >= m()) x -=\
    \ m();\n        return *this;\n    }\n    constexpr modint& operator-=(const modint\
    \ &r) {\n        x -= r.x;\n        if (x >= m()) x += m();\n        return *this;\n\
    \    }\n    constexpr modint& operator*=(const modint &r) {\n        unsigned\
    \ long long y = x;\n        y *= r.x;\n        x = (unsigned int)(y % m());\n\
    \        return *this;\n    }\n    constexpr modint &operator/=(const modint &r)\
    \ {\n        return *this = *this * r.inv();\n    }\n    friend constexpr modint\
    \ operator+(const modint &a, const modint &b) {\n        return modint(a) += b;\n\
    \    }\n    friend constexpr modint operator-(const modint &a, const modint &b)\
    \ {\n        return modint(a) -= b;\n    }\n    friend constexpr modint operator*(const\
    \ modint &a, const modint &b) {\n        return modint(a) *= b;\n    }\n    friend\
    \ constexpr modint operator/(const modint &a, const modint &b) {\n        return\
    \ modint(a) /= b;\n    }\n    friend constexpr bool operator==(const modint &a,\
    \ const modint &b) {\n        return a.x == b.x;\n    }\n    friend constexpr\
    \ bool operator!=(const modint &a, const modint &b) {\n        return a.x != b.x;\n\
    \    }\n    constexpr modint operator+() const { return *this; }\n    constexpr\
    \ modint operator-() const { return modint() - *this; }\n    constexpr modint\
    \ pow(long long k) const {\n        assert(k >= 0);\n        modint a = *this;\n\
    \        modint res = 1;\n        while (k > 0) {\n            if (k & 1) res\
    \ *= a;\n            a *= a;\n            k >>= 1;\n        }\n        return\
    \ res;\n    }\n    constexpr modint inv() const {\n        long long a = x, b\
    \ = m(), u = 1, v = 0;\n        while (b > 0) {\n            long long t = a /\
    \ b;\n            a -= t * b;\n            swap(a, b);\n            u -= t * v;\n\
    \            swap(u, v);\n        }\n        return modint(u);\n    }\nprivate:\n\
    \    unsigned int x;\n    static constexpr unsigned int m() { return MOD; }\n\
    };\n#line 4 \"src/modint/dynamic_montgomery_modint.hpp\"\nusing namespace std;\n\
    \nstruct dynamic_montgomery_modint {\n    using i64 = __uint64_t;\n    using i128\
    \ = __uint128_t;\n    using modint = dynamic_montgomery_modint;\n    dynamic_montgomery_modint()\
    \ : x(0) {}\n    dynamic_montgomery_modint(long long v) : x(reduce((i128(v) +\
    \ MOD) * R)) {}\n    static void set_mod(long long _m) {\n        MOD = _m;\n\
    \        R = -i128(MOD) % MOD;\n        INV = get_inv_mod(); \n    }\n    static\
    \ long long mod() { return MOD; }\n    long long val() const {\n        i64 res\
    \ = reduce(x);\n        return res >= MOD ? res - MOD : res;\n    }\n    modint&\
    \ operator+=(const modint &r) {\n        x += r.x;\n        if (x >= (MOD << 1))\
    \ x -= (MOD << 1);\n        return *this;\n    }\n    modint& operator-=(const\
    \ modint &r) {\n        x += (MOD << 1) - r.x;\n        if (x >= (MOD << 1)) x\
    \ -= (MOD << 1);\n        return *this;\n    }\n    modint& operator*=(const modint\
    \ &r) {\n        x = reduce(i128(x) * r.x);\n        return *this;\n    }\n  \
    \  modint& operator/=(const modint &r) {\n        *this *= r.inv();\n        return\
    \ *this;\n    }\n    friend modint operator+(const modint &a, const modint &b)\
    \ {\n        return modint(a) += b;\n    }\n    friend modint operator-(const\
    \ modint &a, const modint &b) {\n        return modint(a) -= b;\n    }\n    friend\
    \ modint operator*(const modint &a, const modint &b) {\n        return modint(a)\
    \ *= b;\n    }\n    friend modint operator/(const modint &a, const modint &b)\
    \ {\n        return modint(a) /= b;\n    }\n    friend bool operator==(const modint\
    \ &a, const modint &b) {\n        return a.val() == b.val();\n    }\n    friend\
    \ bool operator!=(const modint &a, const modint &b) {\n        return a.val()\
    \ != b.val();\n    }\n    modint operator+() const { return *this; }\n    modint\
    \ operator-() const { return modint() - *this; }\n    modint inv() const { return\
    \ pow(MOD - 2); }\n    modint pow(i128 k) const {\n        modint a = *this;\n\
    \        modint res = 1;\n        while (k > 0) {\n            if (k & 1) res\
    \ *= a;\n            a *= a;\n            k >>= 1;\n        }\n        return\
    \ res;\n    }\nprivate:\n    i64 x;\n    static i64 MOD, INV, R;\n    static i64\
    \ get_inv_mod() {\n        i64 res = MOD;\n        for (int t = 0; t < 5; t++)\
    \ res *= 2 - MOD * res;\n        return res;\n    }\n    static i64 reduce(const\
    \ i128 &v) {\n        return (v + i128(i64(v) * i64(-INV)) * MOD) >> 64;\n   \
    \ }\n};\ntypename dynamic_montgomery_modint::i64\ndynamic_montgomery_modint::MOD,\n\
    dynamic_montgomery_modint::INV,\ndynamic_montgomery_modint::R;\n#line 4 \"src/math/number_theory/primality_test.hpp\"\
    \nusing namespace std;\n\ntemplate<size_t size>\nbool miller_rabin(long long m,\
    \ const array<int, size> &ps) {\n    using mint = dynamic_montgomery_modint;\n\
    \    mint::set_mod(m);\n    long long u = 0, v = m - 1;\n    while ((v & 1) ==\
    \ 0) u++, v >>= 1;\n    for (int p : ps) {\n        if (m <= p) return true;\n\
    \        mint x = mint(p).pow(v);\n        if (x.val() != 1) {\n            long\
    \ long w;\n            for (w = 0; w < u; w++) {\n                if (x.val()\
    \ == m - 1) break;\n                x *= x;\n            }\n            if (w\
    \ == u) return false;\n        }\n    }\n    return true;\n}\n\ninline bool miller_rabin_small(long\
    \ long m) {\n    return miller_rabin(m, array<int, 3>{2, 7, 61});\n}\n\ninline\
    \ bool miller_rabin_large(long long m) {\n    return miller_rabin(m, array<int,\
    \ 7>{2, 325, 9375, 28178, 450775, 9780504, 1795265022});\n}\n\ninline bool is_prime(long\
    \ long m) {\n    if (m <= 1) return false;\n    if (m == 2) return true;\n   \
    \ if (m % 2 == 0) return false;\n    return m < 4759123141LL ? miller_rabin_small(m)\
    \ : miller_rabin_large(m);\n}\n#line 8 \"src/modint/Fp.hpp\"\n\n// https://maspypy.com/o1-mod-inv-mod-pow\
    \ \nnamespace Fp {\n\nstatic constexpr int n = 1 << 10;\nstatic constexpr int\
    \ sz = 1 << 21;\n\ntemplate<int p>\nstruct container {\n    static_assert((int)1e8\
    \ < p && p < (1 << 30));\n    using mint = modint<p>;\n    inline static array<mint,\
    \ sz + 1> fac, finv;\n    inline static array<mint, 2 * sz + 1> inv;\n    inline\
    \ static array<pair<int, int>, n * n + 1> frac;\n    inline static bool built\
    \ = false;\n    static void build_inv() {\n        fac[0] = 1;\n        for (int\
    \ i = 1; i <= sz; i++) fac[i] = i * fac[i - 1];\n        finv[sz] = fac[sz].inv();\n\
    \        for (int i = sz; i >= 1; i--) finv[i - 1] = i * finv[i];\n        for\
    \ (int i = 1; i <= sz; i++) {\n            inv[sz + i] = finv[i] * fac[i - 1];\n\
    \            inv[sz - i] = -inv[sz + i];\n        }\n    }\n    static void build_frac()\
    \ {\n        vector<tuple<int, int, int, int>> st;\n        st.reserve(2 * n);\n\
    \        st.emplace_back(0, 1, 1, 1);\n        while (st.size()) {\n         \
    \   auto [a, b, c, d] = st.back();\n            st.pop_back();\n            if\
    \ (b + d < 2 * n) {\n                st.emplace_back(a + c, b + d, c, d);\n  \
    \              st.emplace_back(a, b, a + c, b + d);\n            } else {\n  \
    \              int l = (long long)a * p / (b << 10);\n                int r =\
    \ (long long)c * p / (d << 10);\n                frac[l] = {a, b};\n         \
    \       frac[r] = {c, d};\n                a = min(a, c);\n                b =\
    \ min(b, d);\n                for (int i = l + 1; i < r; i++) frac[i] = {a, b};\n\
    \            }\n        }\n    }\n    static void build() {\n        if (built)\
    \ return;\n        built = true;\n        build_inv();\n        build_frac();\n\
    \    }\n};\n\ntemplate<int p>\nint inv(int x) {\n    container<p>::build();\n\
    \    assert(0 < x && x < p);\n    auto [c, b] = container<p>::frac[x >> 10];\n\
    \    int a = (long long)b * x - (long long)c * p;\n    return (container<p>::inv[sz\
    \ + a] * b).val();\n}\n\n} // namespace Fp\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <vector>\nusing\
    \ namespace std;\n#include \"../modint/modint.hpp\"\n#include \"../math/number_theory/primality_test.hpp\"\
    \n\n// https://maspypy.com/o1-mod-inv-mod-pow \nnamespace Fp {\n\nstatic constexpr\
    \ int n = 1 << 10;\nstatic constexpr int sz = 1 << 21;\n\ntemplate<int p>\nstruct\
    \ container {\n    static_assert((int)1e8 < p && p < (1 << 30));\n    using mint\
    \ = modint<p>;\n    inline static array<mint, sz + 1> fac, finv;\n    inline static\
    \ array<mint, 2 * sz + 1> inv;\n    inline static array<pair<int, int>, n * n\
    \ + 1> frac;\n    inline static bool built = false;\n    static void build_inv()\
    \ {\n        fac[0] = 1;\n        for (int i = 1; i <= sz; i++) fac[i] = i * fac[i\
    \ - 1];\n        finv[sz] = fac[sz].inv();\n        for (int i = sz; i >= 1; i--)\
    \ finv[i - 1] = i * finv[i];\n        for (int i = 1; i <= sz; i++) {\n      \
    \      inv[sz + i] = finv[i] * fac[i - 1];\n            inv[sz - i] = -inv[sz\
    \ + i];\n        }\n    }\n    static void build_frac() {\n        vector<tuple<int,\
    \ int, int, int>> st;\n        st.reserve(2 * n);\n        st.emplace_back(0,\
    \ 1, 1, 1);\n        while (st.size()) {\n            auto [a, b, c, d] = st.back();\n\
    \            st.pop_back();\n            if (b + d < 2 * n) {\n              \
    \  st.emplace_back(a + c, b + d, c, d);\n                st.emplace_back(a, b,\
    \ a + c, b + d);\n            } else {\n                int l = (long long)a *\
    \ p / (b << 10);\n                int r = (long long)c * p / (d << 10);\n    \
    \            frac[l] = {a, b};\n                frac[r] = {c, d};\n          \
    \      a = min(a, c);\n                b = min(b, d);\n                for (int\
    \ i = l + 1; i < r; i++) frac[i] = {a, b};\n            }\n        }\n    }\n\
    \    static void build() {\n        if (built) return;\n        built = true;\n\
    \        build_inv();\n        build_frac();\n    }\n};\n\ntemplate<int p>\nint\
    \ inv(int x) {\n    container<p>::build();\n    assert(0 < x && x < p);\n    auto\
    \ [c, b] = container<p>::frac[x >> 10];\n    int a = (long long)b * x - (long\
    \ long)c * p;\n    return (container<p>::inv[sz + a] * b).val();\n}\n\n} // namespace\
    \ Fp"
  dependsOn:
  - src/modint/modint.hpp
  - src/math/number_theory/primality_test.hpp
  - src/modint/dynamic_montgomery_modint.hpp
  isVerificationFile: false
  path: src/modint/Fp.hpp
  requiredBy: []
  timestamp: '2026-10-15 11:47:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/modint/Fp.hpp
layout: document
redirect_from:
- /library/src/modint/Fp.hpp
- /library/src/modint/Fp.hpp.html
title: src/modint/Fp.hpp
---
