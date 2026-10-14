---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/number_theory/mod_pow.test.cpp
    title: test/math/number_theory/mod_pow.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/number_theory/mod_pow.hpp\"\nusing namespace std;\n\
    \nlong long mod_pow(long long a, long long n, long long mod) {\n    a %= mod;\n\
    \    long long res = 1;\n    while (n > 0) {\n        if (n & 1) res = __int128_t(res)\
    \ * a % mod;\n        a = __int128_t(a) * a % mod;\n        n >>= 1;\n    }\n\
    \    return res;\n}\n"
  code: "#pragma once\nusing namespace std;\n\nlong long mod_pow(long long a, long\
    \ long n, long long mod) {\n    a %= mod;\n    long long res = 1;\n    while (n\
    \ > 0) {\n        if (n & 1) res = __int128_t(res) * a % mod;\n        a = __int128_t(a)\
    \ * a % mod;\n        n >>= 1;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/number_theory/mod_pow.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/number_theory/mod_pow.test.cpp
documentation_of: src/math/number_theory/mod_pow.hpp
layout: document
redirect_from:
- /library/src/math/number_theory/mod_pow.hpp
- /library/src/math/number_theory/mod_pow.hpp.html
title: src/math/number_theory/mod_pow.hpp
---
