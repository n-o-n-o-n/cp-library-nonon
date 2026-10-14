---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/convolution/arbitrary_mod_convolution.hpp
    title: src/convolution/arbitrary_mod_convolution.hpp
  - icon: ':warning:'
    path: src/math/enumerative_combinatorics/subset_sum.hpp
    title: src/math/enumerative_combinatorics/subset_sum.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/convolution/arbitrary_mod_convolution.test.cpp
    title: test/convolution/arbitrary_mod_convolution.test.cpp
  - icon: ':x:'
    path: test/convolution/bitwise_and_convolution.test.cpp
    title: test/convolution/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/bitwise_or_convolution.test.cpp
    title: test/convolution/bitwise_or_convolution.test.cpp
  - icon: ':x:'
    path: test/convolution/bitwise_xor_convolution.test.cpp
    title: test/convolution/bitwise_xor_convolution.test.cpp
  - icon: ':x:'
    path: test/convolution/convolution.test.cpp
    title: test/convolution/convolution.test.cpp
  - icon: ':x:'
    path: test/convolution/gcd_convolution.test.cpp
    title: test/convolution/gcd_convolution.test.cpp
  - icon: ':x:'
    path: test/convolution/lcm_convolution.test.cpp
    title: test/convolution/lcm_convolution.test.cpp
  - icon: ':x:'
    path: test/convolution/middle_product.test.cpp
    title: test/convolution/middle_product.test.cpp
  - icon: ':x:'
    path: test/convolution/min_plus_convolution_convex_arbitrary.test.cpp
    title: test/convolution/min_plus_convolution_convex_arbitrary.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/relaxed_convolution.test.cpp
    title: test/convolution/relaxed_convolution.test.cpp
  - icon: ':x:'
    path: test/data_structure/segtree/dynamic_lazysegtree.test.cpp
    title: test/data_structure/segtree/dynamic_lazysegtree.test.cpp
  - icon: ':x:'
    path: test/data_structure/segtree/dynamic_segtree.test.cpp
    title: test/data_structure/segtree/dynamic_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_compositional_inverse.test.cpp
    title: test/fps/fps_compositional_inverse.test.cpp
  - icon: ':x:'
    path: test/fps/fps_composotion.test.cpp
    title: test/fps/fps_composotion.test.cpp
  - icon: ':x:'
    path: test/fps/fps_div_sparse.test.cpp
    title: test/fps/fps_div_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_exp.test.cpp
    title: test/fps/fps_exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_exp_sparse.test.cpp
    title: test/fps/fps_exp_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_inv.test.cpp
    title: test/fps/fps_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_inv_sparse.test.cpp
    title: test/fps/fps_inv_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_log.test.cpp
    title: test/fps/fps_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_log_sparse.test.cpp
    title: test/fps/fps_log_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_pow.test.cpp
    title: test/fps/fps_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_pow_sparse.test.cpp
    title: test/fps/fps_pow_sparse.test.cpp
  - icon: ':x:'
    path: test/fps/multipoint_evaluation.test.cpp
    title: test/fps/multipoint_evaluation.test.cpp
  - icon: ':x:'
    path: test/fps/polynomial_interpolation.test.cpp
    title: test/fps/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/polynomial_taylor_shift.test.cpp
    title: test/fps/polynomial_taylor_shift.test.cpp
  - icon: ':x:'
    path: test/fps/power_projection.test.cpp
    title: test/fps/power_projection.test.cpp
  - icon: ':x:'
    path: test/tree/hld.test.cpp
    title: test/tree/hld.test.cpp
  - icon: ':x:'
    path: test/tree/rerooting_dp.test.cpp
    title: test/tree/rerooting_dp.test.cpp
  - icon: ':x:'
    path: test/tree/static_tree.auxiliary_tree.test.cpp
    title: test/tree/static_tree.auxiliary_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/modint/modint.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\nusing namespace std;\n\ntemplate<int MOD>\nstruct modint {\n    constexpr\
    \ modint() : x(0) {}\n    constexpr modint(long long v) {\n        long long y\
    \ = v % m();\n        if (y < 0) y += m();\n        x = (unsigned int)(y);\n \
    \   }\n    static constexpr modint raw(int v) {\n        modint a;\n        a.x\
    \ = v;\n        return a;\n    }\n    static constexpr int mod() { return m();\
    \ }\n    constexpr unsigned int val() const { return x; }\n    constexpr modint&\
    \ operator++() {\n        x++;\n        if (x == m()) x = 0;\n        return *this;\n\
    \    }\n    constexpr modint& operator--() {\n        if (x == 0) x = m();\n \
    \       x--;\n        return *this;\n    }\n    constexpr modint operator++(int)\
    \ {\n        modint res = *this;\n        ++*this;\n        return res;\n    }\n\
    \    constexpr modint operator--(int) {\n        modint res = *this;\n       \
    \ --*this;\n        return res;\n    }\n    constexpr modint& operator+=(const\
    \ modint &r) {\n        x += r.x;\n        if (x >= m()) x -= m();\n        return\
    \ *this;\n    }\n    constexpr modint& operator-=(const modint &r) {\n       \
    \ x -= r.x;\n        if (x >= m()) x += m();\n        return *this;\n    }\n \
    \   constexpr modint& operator*=(const modint &r) {\n        unsigned long long\
    \ y = x;\n        y *= r.x;\n        x = (unsigned int)(y % m());\n        return\
    \ *this;\n    }\n    constexpr modint &operator/=(const modint &r) {\n       \
    \ return *this = *this * r.inv();\n    }\n    friend constexpr modint operator+(const\
    \ modint &a, const modint &b) {\n        return modint(a) += b;\n    }\n    friend\
    \ constexpr modint operator-(const modint &a, const modint &b) {\n        return\
    \ modint(a) -= b;\n    }\n    friend constexpr modint operator*(const modint &a,\
    \ const modint &b) {\n        return modint(a) *= b;\n    }\n    friend constexpr\
    \ modint operator/(const modint &a, const modint &b) {\n        return modint(a)\
    \ /= b;\n    }\n    friend constexpr bool operator==(const modint &a, const modint\
    \ &b) {\n        return a.x == b.x;\n    }\n    friend constexpr bool operator!=(const\
    \ modint &a, const modint &b) {\n        return a.x != b.x;\n    }\n    constexpr\
    \ modint operator+() const { return *this; }\n    constexpr modint operator-()\
    \ const { return modint() - *this; }\n    constexpr modint pow(long long k) const\
    \ {\n        assert(k >= 0);\n        modint a = *this;\n        modint res =\
    \ 1;\n        while (k > 0) {\n            if (k & 1) res *= a;\n            a\
    \ *= a;\n            k >>= 1;\n        }\n        return res;\n    }\n    constexpr\
    \ modint inv() const {\n        long long a = x, b = m(), u = 1, v = 0;\n    \
    \    while (b > 0) {\n            long long t = a / b;\n            a -= t * b;\n\
    \            swap(a, b);\n            u -= t * v;\n            swap(u, v);\n \
    \       }\n        return modint(u);\n    }\nprivate:\n    unsigned int x;\n \
    \   static constexpr unsigned int m() { return MOD; }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\nusing namespace std;\n\
    \ntemplate<int MOD>\nstruct modint {\n    constexpr modint() : x(0) {}\n    constexpr\
    \ modint(long long v) {\n        long long y = v % m();\n        if (y < 0) y\
    \ += m();\n        x = (unsigned int)(y);\n    }\n    static constexpr modint\
    \ raw(int v) {\n        modint a;\n        a.x = v;\n        return a;\n    }\n\
    \    static constexpr int mod() { return m(); }\n    constexpr unsigned int val()\
    \ const { return x; }\n    constexpr modint& operator++() {\n        x++;\n  \
    \      if (x == m()) x = 0;\n        return *this;\n    }\n    constexpr modint&\
    \ operator--() {\n        if (x == 0) x = m();\n        x--;\n        return *this;\n\
    \    }\n    constexpr modint operator++(int) {\n        modint res = *this;\n\
    \        ++*this;\n        return res;\n    }\n    constexpr modint operator--(int)\
    \ {\n        modint res = *this;\n        --*this;\n        return res;\n    }\n\
    \    constexpr modint& operator+=(const modint &r) {\n        x += r.x;\n    \
    \    if (x >= m()) x -= m();\n        return *this;\n    }\n    constexpr modint&\
    \ operator-=(const modint &r) {\n        x -= r.x;\n        if (x >= m()) x +=\
    \ m();\n        return *this;\n    }\n    constexpr modint& operator*=(const modint\
    \ &r) {\n        unsigned long long y = x;\n        y *= r.x;\n        x = (unsigned\
    \ int)(y % m());\n        return *this;\n    }\n    constexpr modint &operator/=(const\
    \ modint &r) {\n        return *this = *this * r.inv();\n    }\n    friend constexpr\
    \ modint operator+(const modint &a, const modint &b) {\n        return modint(a)\
    \ += b;\n    }\n    friend constexpr modint operator-(const modint &a, const modint\
    \ &b) {\n        return modint(a) -= b;\n    }\n    friend constexpr modint operator*(const\
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
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/modint/modint.hpp
  requiredBy:
  - src/convolution/arbitrary_mod_convolution.hpp
  - src/math/enumerative_combinatorics/subset_sum.hpp
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/fps/fps_log.test.cpp
  - test/fps/fps_exp_sparse.test.cpp
  - test/fps/fps_inv_sparse.test.cpp
  - test/fps/multipoint_evaluation.test.cpp
  - test/fps/fps_log_sparse.test.cpp
  - test/fps/fps_pow.test.cpp
  - test/fps/fps_composotion.test.cpp
  - test/fps/power_projection.test.cpp
  - test/fps/polynomial_interpolation.test.cpp
  - test/fps/fps_inv.test.cpp
  - test/fps/fps_div_sparse.test.cpp
  - test/fps/fps_compositional_inverse.test.cpp
  - test/fps/fps_pow_sparse.test.cpp
  - test/fps/fps_exp.test.cpp
  - test/fps/polynomial_taylor_shift.test.cpp
  - test/convolution/arbitrary_mod_convolution.test.cpp
  - test/convolution/bitwise_and_convolution.test.cpp
  - test/convolution/gcd_convolution.test.cpp
  - test/convolution/bitwise_xor_convolution.test.cpp
  - test/convolution/convolution.test.cpp
  - test/convolution/bitwise_or_convolution.test.cpp
  - test/convolution/relaxed_convolution.test.cpp
  - test/convolution/lcm_convolution.test.cpp
  - test/convolution/min_plus_convolution_convex_arbitrary.test.cpp
  - test/convolution/middle_product.test.cpp
  - test/data_structure/segtree/dynamic_lazysegtree.test.cpp
  - test/data_structure/segtree/dynamic_segtree.test.cpp
  - test/tree/rerooting_dp.test.cpp
  - test/tree/hld.test.cpp
  - test/tree/static_tree.auxiliary_tree.test.cpp
documentation_of: src/modint/modint.hpp
layout: document
redirect_from:
- /library/src/modint/modint.hpp
- /library/src/modint/modint.hpp.html
title: src/modint/modint.hpp
---
