---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/number_theory/extended_gcd.hpp
    title: src/math/number_theory/extended_gcd.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/convolution/arbitrary_mod_convolution.hpp
    title: src/convolution/arbitrary_mod_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/convolution/arbitrary_mod_convolution.test.cpp
    title: test/convolution/arbitrary_mod_convolution.test.cpp
  - icon: ':x:'
    path: test/math/number_theory/garner.test.cpp
    title: test/math/number_theory/garner.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/number_theory/garner.hpp\"\n#include <vector>\n\
    #line 2 \"src/math/number_theory/extended_gcd.hpp\"\n#include <utility>\nusing\
    \ namespace std;\n\n// find x, y s.t. ax + by = gcd(a, b) and return gcd(a, b)\n\
    template<typename T>\nT extended_gcd(T a, T b, T &x, T &y) {\n    T g = a;\n \
    \   if (b != 0) {\n        g = extended_gcd(b, a % b, y, x);\n        y -= (a\
    \ / b) * x;\n    } else {\n        x = 1;\n        y = 0;\n    }\n    return g;\n\
    }\n#line 4 \"src/math/number_theory/garner.hpp\"\nusing namespace std;\n\nlong\
    \ long garner(const vector<long long> &rems, vector<long long> mods, long long\
    \ mod) {\n    mods.push_back(mod);\n    int n = mods.size();\n    vector<long\
    \ long> c1(n, 1), c2(n, 0);\n    for (int i = 0; i < n - 1; i++) {\n        long\
    \ long m = mods[i], a = c1[i], b = (rems[i] - c2[i]) % m;\n        if (b < 0)\
    \ b += m;\n        long long x, y;\n        long long g = extended_gcd(a, m, x,\
    \ y);\n        if (b % g != 0) return -1;\n        m /= g, b /= g;\n        x\
    \ %= m;\n        if (x < 0) x += m;\n        long long t = x * b % m;\n      \
    \  for (int j = i + 1; j < n; j++) {\n            c2[j] = (t * c1[j] + c2[j])\
    \ % mods[j];\n            c1[j] = c1[j] * m % mods[j];\n        }\n    }\n   \
    \ return c2.back();\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"extended_gcd.hpp\"\nusing namespace\
    \ std;\n\nlong long garner(const vector<long long> &rems, vector<long long> mods,\
    \ long long mod) {\n    mods.push_back(mod);\n    int n = mods.size();\n    vector<long\
    \ long> c1(n, 1), c2(n, 0);\n    for (int i = 0; i < n - 1; i++) {\n        long\
    \ long m = mods[i], a = c1[i], b = (rems[i] - c2[i]) % m;\n        if (b < 0)\
    \ b += m;\n        long long x, y;\n        long long g = extended_gcd(a, m, x,\
    \ y);\n        if (b % g != 0) return -1;\n        m /= g, b /= g;\n        x\
    \ %= m;\n        if (x < 0) x += m;\n        long long t = x * b % m;\n      \
    \  for (int j = i + 1; j < n; j++) {\n            c2[j] = (t * c1[j] + c2[j])\
    \ % mods[j];\n            c1[j] = c1[j] * m % mods[j];\n        }\n    }\n   \
    \ return c2.back();\n}\n"
  dependsOn:
  - src/math/number_theory/extended_gcd.hpp
  isVerificationFile: false
  path: src/math/number_theory/garner.hpp
  requiredBy:
  - src/convolution/arbitrary_mod_convolution.hpp
  timestamp: '2026-01-02 07:57:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/convolution/arbitrary_mod_convolution.test.cpp
  - test/math/number_theory/garner.test.cpp
documentation_of: src/math/number_theory/garner.hpp
layout: document
redirect_from:
- /library/src/math/number_theory/garner.hpp
- /library/src/math/number_theory/garner.hpp.html
title: src/math/number_theory/garner.hpp
---
