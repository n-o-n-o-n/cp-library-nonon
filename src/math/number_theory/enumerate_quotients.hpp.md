---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/number_theory/enumerate_quotient.test.cpp
    title: test/math/number_theory/enumerate_quotient.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/number_theory/enumerate_quotients.hpp\"\n#include\
    \ <vector>\nusing namespace std;\n\n// for all m in [l, r), floor(n/m) = q\ntemplate<typename\
    \ T>\nvector<tuple<T, T, T>> enumerate_quotients(T n) {\n    vector<tuple<T, T,\
    \ T>> res;\n    for (T l = 1, r, q; l <= n; l = r) {\n        q = n / l;\n   \
    \     r = n / q + 1;\n        res.emplace_back(l, r, q);\n    }\n    return res;\n\
    }\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\n// for all m in\
    \ [l, r), floor(n/m) = q\ntemplate<typename T>\nvector<tuple<T, T, T>> enumerate_quotients(T\
    \ n) {\n    vector<tuple<T, T, T>> res;\n    for (T l = 1, r, q; l <= n; l = r)\
    \ {\n        q = n / l;\n        r = n / q + 1;\n        res.emplace_back(l, r,\
    \ q);\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/number_theory/enumerate_quotients.hpp
  requiredBy: []
  timestamp: '2025-09-03 07:15:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/number_theory/enumerate_quotient.test.cpp
documentation_of: src/math/number_theory/enumerate_quotients.hpp
layout: document
redirect_from:
- /library/src/math/number_theory/enumerate_quotients.hpp
- /library/src/math/number_theory/enumerate_quotients.hpp.html
title: src/math/number_theory/enumerate_quotients.hpp
---
