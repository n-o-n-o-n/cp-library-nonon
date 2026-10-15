---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/math/number_theory/enumerate_primes.hpp
    title: src/math/number_theory/enumerate_primes.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/enumerate_primes.test.cpp
    title: test/math/number_theory/enumerate_primes.test.cpp
  - icon: ':x:'
    path: test/math/number_theory/primality_table.test.cpp
    title: test/math/number_theory/primality_table.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/number_theory/primality_table.hpp\"\n#include <vector>\n\
    using namespace std;\n\nvector<bool> primality_table(int n) {\n    vector<bool>\
    \ res(n + 1, true);\n    res[0] = res[1] = false;\n    for (int i = 2; i <= n;\
    \ i++) {\n        if (res[i]) {\n            for (int j = i + i; j <= n; j +=\
    \ i) res[j] = false;\n        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\nvector<bool> primality_table(int\
    \ n) {\n    vector<bool> res(n + 1, true);\n    res[0] = res[1] = false;\n   \
    \ for (int i = 2; i <= n; i++) {\n        if (res[i]) {\n            for (int\
    \ j = i + i; j <= n; j += i) res[j] = false;\n        }\n    }\n    return res;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: src/math/number_theory/primality_table.hpp
  requiredBy:
  - src/math/number_theory/enumerate_primes.hpp
  timestamp: '2026-01-02 07:57:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/number_theory/enumerate_primes.test.cpp
  - test/math/number_theory/primality_table.test.cpp
documentation_of: src/math/number_theory/primality_table.hpp
layout: document
redirect_from:
- /library/src/math/number_theory/primality_table.hpp
- /library/src/math/number_theory/primality_table.hpp.html
title: src/math/number_theory/primality_table.hpp
---
