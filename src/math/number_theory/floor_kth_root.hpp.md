---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/floor_kth_root.test.cpp
    title: test/math/number_theory/floor_kth_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/number_theory/floor_kth_root.hpp\"\n#include <cassert>\n\
    #include <cmath>\n#include <numeric>\nusing namespace std;\n\n// floor( a ^ (1/k)\
    \ )\ntemplate<typename T>\nT floor_kth_root(T a, T k) {\n    assert(0 <= a);\n\
    \    if (a == 0 || a == 1 || k == 1) return a;\n    if (64 <= k) return 1;\n \
    \   constexpr T inf = numeric_limits<T>::max();\n    if (a == inf) a--;\n    auto\
    \ mul = [&](T x, T y) -> T {\n        return x <= inf / y ? x * y : inf;\n   \
    \ };\n    auto pw = [&](T x, T n) -> T {\n        T r = 1;\n        while (n >\
    \ 0) {\n            if (n & 1) r = mul(r, x);\n            x = mul(x, x);\n  \
    \          n >>= 1;\n        }\n        return r;\n    };\n    T res = (k == 2\
    \ ? sqrtl(a) - 1 : k == 3 ? cbrtl(a) - 1 : pow(a, nextafter(1.0 / k, 0)));\n \
    \   while (pw(res + 1, k) <= a) res++;\n    return res;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <cmath>\n#include <numeric>\n\
    using namespace std;\n\n// floor( a ^ (1/k) )\ntemplate<typename T>\nT floor_kth_root(T\
    \ a, T k) {\n    assert(0 <= a);\n    if (a == 0 || a == 1 || k == 1) return a;\n\
    \    if (64 <= k) return 1;\n    constexpr T inf = numeric_limits<T>::max();\n\
    \    if (a == inf) a--;\n    auto mul = [&](T x, T y) -> T {\n        return x\
    \ <= inf / y ? x * y : inf;\n    };\n    auto pw = [&](T x, T n) -> T {\n    \
    \    T r = 1;\n        while (n > 0) {\n            if (n & 1) r = mul(r, x);\n\
    \            x = mul(x, x);\n            n >>= 1;\n        }\n        return r;\n\
    \    };\n    T res = (k == 2 ? sqrtl(a) - 1 : k == 3 ? cbrtl(a) - 1 : pow(a, nextafter(1.0\
    \ / k, 0)));\n    while (pw(res + 1, k) <= a) res++;\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/number_theory/floor_kth_root.hpp
  requiredBy: []
  timestamp: '2026-01-02 07:57:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/number_theory/floor_kth_root.test.cpp
documentation_of: src/math/number_theory/floor_kth_root.hpp
layout: document
redirect_from:
- /library/src/math/number_theory/floor_kth_root.hpp
- /library/src/math/number_theory/floor_kth_root.hpp.html
title: src/math/number_theory/floor_kth_root.hpp
---
