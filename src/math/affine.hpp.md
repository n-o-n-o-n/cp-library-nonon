---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/segtree/dynamic_lazysegtree.test.cpp
    title: test/data_structure/segtree/dynamic_lazysegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/segtree/dynamic_segtree.test.cpp
    title: test/data_structure/segtree/dynamic_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/discrete_logarithm.test.cpp
    title: test/math/number_theory/discrete_logarithm.test.cpp
  - icon: ':x:'
    path: test/tree/hld.test.cpp
    title: test/tree/hld.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/affine.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ mint>\nstruct affine {\n    mint a, b;\n    affine() : a(1), b(0) {}\n    affine(const\
    \ mint &_a, const mint &_b) : a(_a), b(_b) {}\n    mint operator()(const mint\
    \ &x) const {\n        return a * x + b;\n    }\n    affine operator()(const affine\
    \ &f) const {\n        mint c = a * f.a;\n        mint d = a * f.b + b;\n    \
    \    return affine(c, d);\n    }\n};\n"
  code: "#pragma once\nusing namespace std;\n\ntemplate<typename mint>\nstruct affine\
    \ {\n    mint a, b;\n    affine() : a(1), b(0) {}\n    affine(const mint &_a,\
    \ const mint &_b) : a(_a), b(_b) {}\n    mint operator()(const mint &x) const\
    \ {\n        return a * x + b;\n    }\n    affine operator()(const affine &f)\
    \ const {\n        mint c = a * f.a;\n        mint d = a * f.b + b;\n        return\
    \ affine(c, d);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/math/affine.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/data_structure/segtree/dynamic_lazysegtree.test.cpp
  - test/data_structure/segtree/dynamic_segtree.test.cpp
  - test/math/number_theory/discrete_logarithm.test.cpp
  - test/tree/hld.test.cpp
documentation_of: src/math/affine.hpp
layout: document
redirect_from:
- /library/src/math/affine.hpp
- /library/src/math/affine.hpp.html
title: src/math/affine.hpp
---
