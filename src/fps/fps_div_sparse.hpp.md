---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/fps/fps_div_sparse.test.cpp
    title: test/fps/fps_div_sparse.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/fps/fps_div_sparse.hpp\"\n#include <cassert>\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate<typename mint>\nvector<mint> fps_div_sparse(vector<mint>\
    \ f, const vector<pair<int, mint>> &g_sub) {\n    assert(g_sub.size() && g_sub[0].first\
    \ == 0 && g_sub[0].second != 0);\n    int n = f.size();\n    mint cef = g_sub[0].second.inv();\n\
    \    for (int i = 0; i < n; i++) {\n        f[i] *= cef;\n        for (auto [a,\
    \ c] : g_sub) {\n            if (0 < a && i + a < n) {\n                f[i +\
    \ a] -= f[i] * c;\n            }\n        }\n    }\n    return f;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename mint>\nvector<mint> fps_div_sparse(vector<mint> f, const vector<pair<int,\
    \ mint>> &g_sub) {\n    assert(g_sub.size() && g_sub[0].first == 0 && g_sub[0].second\
    \ != 0);\n    int n = f.size();\n    mint cef = g_sub[0].second.inv();\n    for\
    \ (int i = 0; i < n; i++) {\n        f[i] *= cef;\n        for (auto [a, c] :\
    \ g_sub) {\n            if (0 < a && i + a < n) {\n                f[i + a] -=\
    \ f[i] * c;\n            }\n        }\n    }\n    return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/fps/fps_div_sparse.hpp
  requiredBy: []
  timestamp: '2025-11-05 13:37:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/fps/fps_div_sparse.test.cpp
documentation_of: src/fps/fps_div_sparse.hpp
layout: document
redirect_from:
- /library/src/fps/fps_div_sparse.hpp
- /library/src/fps/fps_div_sparse.hpp.html
title: src/fps/fps_div_sparse.hpp
---
