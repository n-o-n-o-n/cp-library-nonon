---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dp/kadane.hpp\"\n#include <algorithm>\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename T>\nT kadane(const vector<T> &v, bool\
    \ empty = false) {\n    int n = v.size();\n    T res = empty ? T(0) : *max_element(v.begin(),\
    \ v.end());\n    T s = 0;\n    for (int i = 0; i < n; i++) {\n        s = max(s,\
    \ T(0)) + v[i];\n        res = max(res, s);\n    } \n    return res;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename T>\nT kadane(const vector<T> &v, bool empty = false) {\n \
    \   int n = v.size();\n    T res = empty ? T(0) : *max_element(v.begin(), v.end());\n\
    \    T s = 0;\n    for (int i = 0; i < n; i++) {\n        s = max(s, T(0)) + v[i];\n\
    \        res = max(res, s);\n    } \n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/kadane.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/dp/kadane.hpp
layout: document
redirect_from:
- /library/src/dp/kadane.hpp
- /library/src/dp/kadane.hpp.html
title: src/dp/kadane.hpp
---
