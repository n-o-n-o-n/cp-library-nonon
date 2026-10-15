---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/convolution/arbitrary_mod_convolution.hpp
    title: src/convolution/arbitrary_mod_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/number_theory/garner.hpp
    title: src/math/number_theory/garner.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/number_theory/mod_inv.hpp
    title: src/math/number_theory/mod_inv.hpp
  - icon: ':warning:'
    path: src/monoid/rolling_hash.hpp
    title: src/monoid/rolling_hash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/arbitrary_mod_convolution.test.cpp
    title: test/convolution/arbitrary_mod_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/extended_gcd.test.cpp
    title: test/math/number_theory/extended_gcd.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/garner.test.cpp
    title: test/math/number_theory/garner.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/mod_inv.test.cpp
    title: test/math/number_theory/mod_inv.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/number_theory/extended_gcd.hpp\"\n#include <utility>\n\
    using namespace std;\n\n// find x, y s.t. ax + by = gcd(a, b) and return gcd(a,\
    \ b)\ntemplate<typename T>\nT extended_gcd(T a, T b, T &x, T &y) {\n    T g =\
    \ a;\n    if (b != 0) {\n        g = extended_gcd(b, a % b, y, x);\n        y\
    \ -= (a / b) * x;\n    } else {\n        x = 1;\n        y = 0;\n    }\n    return\
    \ g;\n}\n"
  code: "#pragma once\n#include <utility>\nusing namespace std;\n\n// find x, y s.t.\
    \ ax + by = gcd(a, b) and return gcd(a, b)\ntemplate<typename T>\nT extended_gcd(T\
    \ a, T b, T &x, T &y) {\n    T g = a;\n    if (b != 0) {\n        g = extended_gcd(b,\
    \ a % b, y, x);\n        y -= (a / b) * x;\n    } else {\n        x = 1;\n   \
    \     y = 0;\n    }\n    return g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/number_theory/extended_gcd.hpp
  requiredBy:
  - src/convolution/arbitrary_mod_convolution.hpp
  - src/monoid/rolling_hash.hpp
  - src/math/number_theory/garner.hpp
  - src/math/number_theory/mod_inv.hpp
  timestamp: '2025-08-07 20:30:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/arbitrary_mod_convolution.test.cpp
  - test/math/number_theory/garner.test.cpp
  - test/math/number_theory/extended_gcd.test.cpp
  - test/math/number_theory/mod_inv.test.cpp
documentation_of: src/math/number_theory/extended_gcd.hpp
layout: document
redirect_from:
- /library/src/math/number_theory/extended_gcd.hpp
- /library/src/math/number_theory/extended_gcd.hpp.html
title: src/math/number_theory/extended_gcd.hpp
---
