---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/convolution/bitwise_or_convolution.hpp
    title: src/convolution/bitwise_or_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/bitwise_or_convolution.test.cpp
    title: test/convolution/bitwise_or_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/convolution/subset_zmt.hpp\"\n#include <cassert>\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate<typename mint>\nvoid subset_zmt(vector<mint>\
    \ &f, bool moebius = false) {\n    int n = f.size();\n    assert((n & (n - 1))\
    \ == 0);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if (i & j) continue;\n            f[i | j] += moebius ?\
    \ -f[j] : f[j];\n        }\n    }\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename mint>\nvoid subset_zmt(vector<mint> &f, bool moebius = false)\
    \ {\n    int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for (int i =\
    \ 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if\
    \ (i & j) continue;\n            f[i | j] += moebius ? -f[j] : f[j];\n       \
    \ }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/convolution/subset_zmt.hpp
  requiredBy:
  - src/convolution/bitwise_or_convolution.hpp
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/bitwise_or_convolution.test.cpp
documentation_of: src/convolution/subset_zmt.hpp
layout: document
redirect_from:
- /library/src/convolution/subset_zmt.hpp
- /library/src/convolution/subset_zmt.hpp.html
title: src/convolution/subset_zmt.hpp
---
