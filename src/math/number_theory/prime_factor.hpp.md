---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/number_theory/primality_test.hpp
    title: src/math/number_theory/primality_test.hpp
  - icon: ':question:'
    path: src/modint/dynamic_montgomery_modint.hpp
    title: src/modint/dynamic_montgomery_modint.hpp
  - icon: ':question:'
    path: src/random/xor_shift.hpp
    title: src/random/xor_shift.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/convolution/arbitrary_mod_convolution.hpp
    title: src/convolution/arbitrary_mod_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: src/convolution/convolution.hpp
    title: src/convolution/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: src/convolution/middle_product.hpp
    title: src/convolution/middle_product.hpp
  - icon: ':heavy_check_mark:'
    path: src/convolution/ntt.hpp
    title: src/convolution/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: src/convolution/relaxed_convolution.hpp
    title: src/convolution/relaxed_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/fps.hpp
    title: src/fps/fps.hpp
  - icon: ':warning:'
    path: src/fps/fps_all.hpp
    title: src/fps/fps_all.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/fps_compositional_inverse.hpp
    title: src/fps/fps_compositional_inverse.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/fps_composotion.hpp
    title: src/fps/fps_composotion.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/fps_exp.hpp
    title: src/fps/fps_exp.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/fps_inv.hpp
    title: src/fps/fps_inv.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/fps_log.hpp
    title: src/fps/fps_log.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/fps_pow.hpp
    title: src/fps/fps_pow.hpp
  - icon: ':warning:'
    path: src/fps/fps_product.hpp
    title: src/fps/fps_product.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/multipoint_evaluation.hpp
    title: src/fps/multipoint_evaluation.hpp
  - icon: ':warning:'
    path: src/fps/multipoint_evaluation_geometric.hpp
    title: src/fps/multipoint_evaluation_geometric.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/polynomial_interpolation.hpp
    title: src/fps/polynomial_interpolation.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/polynomial_taylor_shift.hpp
    title: src/fps/polynomial_taylor_shift.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/power_projection.hpp
    title: src/fps/power_projection.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/rational_sum.hpp
    title: src/fps/rational_sum.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/subprod_tree.hpp
    title: src/fps/subprod_tree.hpp
  - icon: ':warning:'
    path: src/math/bmbm.hpp
    title: src/math/bmbm.hpp
  - icon: ':warning:'
    path: src/math/bostan_mori.hpp
    title: src/math/bostan_mori.hpp
  - icon: ':warning:'
    path: src/math/enumerative_combinatorics/enumerate_powers_of_sums.hpp
    title: src/math/enumerative_combinatorics/enumerate_powers_of_sums.hpp
  - icon: ':warning:'
    path: src/math/enumerative_combinatorics/partition.hpp
    title: src/math/enumerative_combinatorics/partition.hpp
  - icon: ':warning:'
    path: src/math/enumerative_combinatorics/power_sum.hpp
    title: src/math/enumerative_combinatorics/power_sum.hpp
  - icon: ':warning:'
    path: src/math/enumerative_combinatorics/stirling2_k_fixed.hpp
    title: src/math/enumerative_combinatorics/stirling2_k_fixed.hpp
  - icon: ':warning:'
    path: src/math/enumerative_combinatorics/stirling2_n_fixed.hpp
    title: src/math/enumerative_combinatorics/stirling2_n_fixed.hpp
  - icon: ':warning:'
    path: src/math/enumerative_combinatorics/subset_sum.hpp
    title: src/math/enumerative_combinatorics/subset_sum.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/number_theory/enumerate_divisors.hpp
    title: src/math/number_theory/enumerate_divisors.hpp
  - icon: ':question:'
    path: src/math/number_theory/factorise.hpp
    title: src/math/number_theory/factorise.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/number_theory/primitive_root.hpp
    title: src/math/number_theory/primitive_root.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/number_theory/totient_function.hpp
    title: src/math/number_theory/totient_function.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/arbitrary_mod_convolution.test.cpp
    title: test/convolution/arbitrary_mod_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/convolution.test.cpp
    title: test/convolution/convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/middle_product.test.cpp
    title: test/convolution/middle_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/relaxed_convolution.test.cpp
    title: test/convolution/relaxed_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_compositional_inverse.test.cpp
    title: test/fps/fps_compositional_inverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_composotion.test.cpp
    title: test/fps/fps_composotion.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_div_sparse.test.cpp
    title: test/fps/fps_div_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_exp.test.cpp
    title: test/fps/fps_exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_inv.test.cpp
    title: test/fps/fps_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_log.test.cpp
    title: test/fps/fps_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_pow.test.cpp
    title: test/fps/fps_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/multipoint_evaluation.test.cpp
    title: test/fps/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/polynomial_interpolation.test.cpp
    title: test/fps/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/polynomial_taylor_shift.test.cpp
    title: test/fps/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/power_projection.test.cpp
    title: test/fps/power_projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/enumerate_divisors.test.cpp
    title: test/math/number_theory/enumerate_divisors.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/factorise.test.cpp
    title: test/math/number_theory/factorise.test.cpp
  - icon: ':x:'
    path: test/math/number_theory/garner.test.cpp
    title: test/math/number_theory/garner.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/prime_factor.test.cpp
    title: test/math/number_theory/prime_factor.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/primitive_root.test.cpp
    title: test/math/number_theory/primitive_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/totient_function.test.cpp
    title: test/math/number_theory/totient_function.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/number_theory/prime_factor.hpp\"\n#include <numeric>\n\
    #include <vector>\n#line 2 \"src/modint/dynamic_montgomery_modint.hpp\"\n#include\
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
    #line 2 \"src/random/xor_shift.hpp\"\n#include <cstdint>\n#include <type_traits>\n\
    using namespace std;\n\ntemplate<typename T>\nstruct xor_shift {\n    using U\
    \ = typename make_unsigned<T>::type;\n    constexpr xor_shift(U seed) : x(seed\
    \ == 0 ? 987139873 : seed) {}\n    constexpr U operator()() {\n        if constexpr\
    \ (sizeof(T) <= 4) {\n            x ^= x << 13;\n            x ^= x >> 17;\n \
    \           x ^= x << 5;\n        } else {\n            x ^= x << 13;\n      \
    \      x ^= x >> 7;\n            x ^= x << 17;\n        }\n        return x;\n\
    \    }\n    constexpr T operator()(T low, T hi) {\n        return low + (*this)()\
    \ % (hi - low + 1);\n    }\nprivate:\n    U x;\n};\n#line 2 \"src/math/number_theory/primality_test.hpp\"\
    \n#include <array>\n#line 4 \"src/math/number_theory/primality_test.hpp\"\nusing\
    \ namespace std;\n\ntemplate<size_t size>\nbool miller_rabin(long long m, const\
    \ array<int, size> &ps) {\n    using mint = dynamic_montgomery_modint;\n    mint::set_mod(m);\n\
    \    long long u = 0, v = m - 1;\n    while ((v & 1) == 0) u++, v >>= 1;\n   \
    \ for (int p : ps) {\n        if (m <= p) return true;\n        mint x = mint(p).pow(v);\n\
    \        if (x.val() != 1) {\n            long long w;\n            for (w = 0;\
    \ w < u; w++) {\n                if (x.val() == m - 1) break;\n              \
    \  x *= x;\n            }\n            if (w == u) return false;\n        }\n\
    \    }\n    return true;\n}\n\ninline bool miller_rabin_small(long long m) {\n\
    \    return miller_rabin(m, array<int, 3>{2, 7, 61});\n}\n\ninline bool miller_rabin_large(long\
    \ long m) {\n    return miller_rabin(m, array<int, 7>{2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022});\n}\n\ninline bool is_prime(long long m) {\n    if (m\
    \ <= 1) return false;\n    if (m == 2) return true;\n    if (m % 2 == 0) return\
    \ false;\n    return m < 4759123141LL ? miller_rabin_small(m) : miller_rabin_large(m);\n\
    }\n#line 7 \"src/math/number_theory/prime_factor.hpp\"\nusing namespace std;\n\
    \ntemplate<typename T>\nT rho(T n) {\n    for (int p : {2, 3, 5, 7}) {\n     \
    \   if (n % p == 0) return p;\n    }\n    using mint = dynamic_montgomery_modint;\n\
    \    mint::set_mod(n);\n    xor_shift<T> eng(n);\n    while (true) {\n       \
    \ mint u = eng(2, n - 1);\n        mint v = u;\n        mint c = eng(1, n - 1);\n\
    \        T d = 1;\n        while (d == 1) {\n            u = u * u - c;\n    \
    \        v = v * v - c;\n            v = v * v - c;\n            d = gcd((u -\
    \ v).val(), n);\n        }\n        if (d < n) return d;\n    }\n    return -1;\n\
    }\n\ntemplate<typename T>\nvector<T> prime_factor(T n) {\n    if (n <= 1) return\
    \ {};\n    if (is_prime(n)) return {n};\n    vector<T> res;\n    T d = rho(n);\n\
    \    auto a = prime_factor(d);\n    auto b = prime_factor(n / d);\n    merge(a.begin(),\
    \ a.end(), b.begin(), b.end(), back_inserter(res));\n    res.erase(unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\n#include \"../../modint/dynamic_montgomery_modint.hpp\"\
    \n#include \"../../random/xor_shift.hpp\"\n#include \"primality_test.hpp\"\nusing\
    \ namespace std;\n\ntemplate<typename T>\nT rho(T n) {\n    for (int p : {2, 3,\
    \ 5, 7}) {\n        if (n % p == 0) return p;\n    }\n    using mint = dynamic_montgomery_modint;\n\
    \    mint::set_mod(n);\n    xor_shift<T> eng(n);\n    while (true) {\n       \
    \ mint u = eng(2, n - 1);\n        mint v = u;\n        mint c = eng(1, n - 1);\n\
    \        T d = 1;\n        while (d == 1) {\n            u = u * u - c;\n    \
    \        v = v * v - c;\n            v = v * v - c;\n            d = gcd((u -\
    \ v).val(), n);\n        }\n        if (d < n) return d;\n    }\n    return -1;\n\
    }\n\ntemplate<typename T>\nvector<T> prime_factor(T n) {\n    if (n <= 1) return\
    \ {};\n    if (is_prime(n)) return {n};\n    vector<T> res;\n    T d = rho(n);\n\
    \    auto a = prime_factor(d);\n    auto b = prime_factor(n / d);\n    merge(a.begin(),\
    \ a.end(), b.begin(), b.end(), back_inserter(res));\n    res.erase(unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}"
  dependsOn:
  - src/modint/dynamic_montgomery_modint.hpp
  - src/random/xor_shift.hpp
  - src/math/number_theory/primality_test.hpp
  isVerificationFile: false
  path: src/math/number_theory/prime_factor.hpp
  requiredBy:
  - src/fps/fps_product.hpp
  - src/fps/fps.hpp
  - src/fps/fps_exp.hpp
  - src/fps/fps_composotion.hpp
  - src/fps/multipoint_evaluation_geometric.hpp
  - src/fps/fps_all.hpp
  - src/fps/fps_inv.hpp
  - src/fps/subprod_tree.hpp
  - src/fps/polynomial_interpolation.hpp
  - src/fps/power_projection.hpp
  - src/fps/multipoint_evaluation.hpp
  - src/fps/polynomial_taylor_shift.hpp
  - src/fps/fps_log.hpp
  - src/fps/fps_pow.hpp
  - src/fps/fps_compositional_inverse.hpp
  - src/fps/rational_sum.hpp
  - src/convolution/convolution.hpp
  - src/convolution/arbitrary_mod_convolution.hpp
  - src/convolution/ntt.hpp
  - src/convolution/relaxed_convolution.hpp
  - src/convolution/middle_product.hpp
  - src/math/bmbm.hpp
  - src/math/number_theory/factorise.hpp
  - src/math/number_theory/primitive_root.hpp
  - src/math/number_theory/totient_function.hpp
  - src/math/number_theory/enumerate_divisors.hpp
  - src/math/bostan_mori.hpp
  - src/math/enumerative_combinatorics/subset_sum.hpp
  - src/math/enumerative_combinatorics/stirling2_n_fixed.hpp
  - src/math/enumerative_combinatorics/power_sum.hpp
  - src/math/enumerative_combinatorics/partition.hpp
  - src/math/enumerative_combinatorics/stirling2_k_fixed.hpp
  - src/math/enumerative_combinatorics/enumerate_powers_of_sums.hpp
  timestamp: '2026-10-14 23:16:02+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/fps/fps_log.test.cpp
  - test/fps/multipoint_evaluation.test.cpp
  - test/fps/fps_pow.test.cpp
  - test/fps/fps_composotion.test.cpp
  - test/fps/power_projection.test.cpp
  - test/fps/polynomial_interpolation.test.cpp
  - test/fps/fps_inv.test.cpp
  - test/fps/fps_div_sparse.test.cpp
  - test/fps/fps_compositional_inverse.test.cpp
  - test/fps/fps_exp.test.cpp
  - test/fps/polynomial_taylor_shift.test.cpp
  - test/convolution/arbitrary_mod_convolution.test.cpp
  - test/convolution/convolution.test.cpp
  - test/convolution/relaxed_convolution.test.cpp
  - test/convolution/middle_product.test.cpp
  - test/math/number_theory/factorise.test.cpp
  - test/math/number_theory/enumerate_divisors.test.cpp
  - test/math/number_theory/garner.test.cpp
  - test/math/number_theory/prime_factor.test.cpp
  - test/math/number_theory/totient_function.test.cpp
  - test/math/number_theory/primitive_root.test.cpp
documentation_of: src/math/number_theory/prime_factor.hpp
layout: document
redirect_from:
- /library/src/math/number_theory/prime_factor.hpp
- /library/src/math/number_theory/prime_factor.hpp.html
title: src/math/number_theory/prime_factor.hpp
---
