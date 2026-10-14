---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/math/number_theory/primality_table.hpp
    title: src/math/number_theory/primality_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/number_theory/enumerate_primes.test.cpp
    title: test/math/number_theory/enumerate_primes.test.cpp
  - icon: ':x:'
    path: test/math/number_theory/primality_table.test.cpp
    title: test/math/number_theory/primality_table.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/number_theory/enumerate_primes.hpp\"\n#include\
    \ <algorithm>\n#include <vector>\n#line 3 \"src/math/number_theory/primality_table.hpp\"\
    \nusing namespace std;\n\nvector<bool> primality_table(int n) {\n    vector<bool>\
    \ res(n + 1, true);\n    res[0] = res[1] = false;\n    for (int i = 2; i <= n;\
    \ i++) {\n        if (res[i]) {\n            for (int j = i + i; j <= n; j +=\
    \ i) res[j] = false;\n        }\n    }\n    return res;\n}\n#line 5 \"src/math/number_theory/enumerate_primes.hpp\"\
    \nusing namespace std;\n\nvector<int> enumerate_primes(int n) {\n    auto tbl\
    \ = primality_table(n);\n    vector<int> res;\n    res.reserve(count(tbl.begin(),\
    \ tbl.end(), true));\n    for (int i = 2; i <= n; i++) {\n        if (tbl[i])\
    \ res.emplace_back(i);\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include \"primality_table.hpp\"\
    \nusing namespace std;\n\nvector<int> enumerate_primes(int n) {\n    auto tbl\
    \ = primality_table(n);\n    vector<int> res;\n    res.reserve(count(tbl.begin(),\
    \ tbl.end(), true));\n    for (int i = 2; i <= n; i++) {\n        if (tbl[i])\
    \ res.emplace_back(i);\n    }\n    return res;\n}"
  dependsOn:
  - src/math/number_theory/primality_table.hpp
  isVerificationFile: false
  path: src/math/number_theory/enumerate_primes.hpp
  requiredBy: []
  timestamp: '2026-01-02 07:57:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/number_theory/enumerate_primes.test.cpp
  - test/math/number_theory/primality_table.test.cpp
documentation_of: src/math/number_theory/enumerate_primes.hpp
layout: document
redirect_from:
- /library/src/math/number_theory/enumerate_primes.hpp
- /library/src/math/number_theory/enumerate_primes.hpp.html
title: src/math/number_theory/enumerate_primes.hpp
---
