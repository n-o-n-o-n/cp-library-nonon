---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/number_theory/extended_gcd.hpp
    title: src/math/number_theory/extended_gcd.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/monoid/rolling_hash.hpp
    title: src/monoid/rolling_hash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/mod_inv.test.cpp
    title: test/math/number_theory/mod_inv.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/number_theory/mod_inv.hpp\"\n#include <cassert>\n\
    #line 2 \"src/math/number_theory/extended_gcd.hpp\"\n#include <utility>\nusing\
    \ namespace std;\n\n// find x, y s.t. ax + by = gcd(a, b) and return gcd(a, b)\n\
    template<typename T>\nT extended_gcd(T a, T b, T &x, T &y) {\n    T g = a;\n \
    \   if (b != 0) {\n        g = extended_gcd(b, a % b, y, x);\n        y -= (a\
    \ / b) * x;\n    } else {\n        x = 1;\n        y = 0;\n    }\n    return g;\n\
    }\n#line 4 \"src/math/number_theory/mod_inv.hpp\"\nusing namespace std;\n\nlong\
    \ long mod_inv(long long a, long long mod) {\n    long long inv, y;\n    assert(extended_gcd(a,\
    \ mod, inv, y) == 1);\n    inv %= mod;\n    return inv < 0 ? inv + mod : inv;\n\
    }\n"
  code: "#pragma once\n#include <cassert>\n#include \"extended_gcd.hpp\"\nusing namespace\
    \ std;\n\nlong long mod_inv(long long a, long long mod) {\n    long long inv,\
    \ y;\n    assert(extended_gcd(a, mod, inv, y) == 1);\n    inv %= mod;\n    return\
    \ inv < 0 ? inv + mod : inv;\n}"
  dependsOn:
  - src/math/number_theory/extended_gcd.hpp
  isVerificationFile: false
  path: src/math/number_theory/mod_inv.hpp
  requiredBy:
  - src/monoid/rolling_hash.hpp
  timestamp: '2025-08-07 20:30:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/number_theory/mod_inv.test.cpp
documentation_of: src/math/number_theory/mod_inv.hpp
layout: document
redirect_from:
- /library/src/math/number_theory/mod_inv.hpp
- /library/src/math/number_theory/mod_inv.hpp.html
title: src/math/number_theory/mod_inv.hpp
---
