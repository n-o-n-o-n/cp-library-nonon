---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/monoid/add.test.cpp
    title: test/monoid/add.test.cpp
  - icon: ':x:'
    path: test/tree/hld.commutative.test.cpp
    title: test/tree/hld.commutative.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/range_contour_aggregator.test.cpp
    title: test/tree/range_contour_aggregator.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/monoid/add.hpp\"\nusing namespace std;\n\ntemplate <typename\
    \ T>\nstruct add_monoid {\n    using S = T;\n    static S op(const S &a, const\
    \ S &b) {\n        return a + b;\n    }\n    static S e() { return 0; }\n    static\
    \ S inv(const S &x) {\n        return -x;\n    }\n    static S pow(const S &x,\
    \ long long k) {\n        return x * k;\n    }\n};\n"
  code: "#pragma once\nusing namespace std;\n\ntemplate <typename T>\nstruct add_monoid\
    \ {\n    using S = T;\n    static S op(const S &a, const S &b) {\n        return\
    \ a + b;\n    }\n    static S e() { return 0; }\n    static S inv(const S &x)\
    \ {\n        return -x;\n    }\n    static S pow(const S &x, long long k) {\n\
    \        return x * k;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/monoid/add.hpp
  requiredBy: []
  timestamp: '2025-09-04 12:06:31+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/monoid/add.test.cpp
  - test/tree/hld.commutative.test.cpp
  - test/tree/range_contour_aggregator.test.cpp
documentation_of: src/monoid/add.hpp
layout: document
redirect_from:
- /library/src/monoid/add.hpp
- /library/src/monoid/add.hpp.html
title: src/monoid/add.hpp
---
