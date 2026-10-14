---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_inv_sparse.test.cpp
    title: test/fps/fps_inv_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/fps/fps_inv_sparse.hpp\"\n#include <cassert>\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate<typename mint>\nvector<mint> fps_inv_sparse(const\
    \ vector<pair<int, mint>> &f_sub, int n) {\n    assert(f_sub.size() && f_sub[0].first\
    \ == 0 && f_sub[0].second != 0);\n    mint cef = f_sub[0].second.inv();\n    vector<mint>\
    \ g(n);\n    g[0] = 1;\n    for (int i = 0; i < n; i++) {\n        if (g[i] !=\
    \ 0) {\n            g[i] *= cef;\n            for (auto [a,c] : f_sub) {\n   \
    \             if (0 < a && i + a < n) {\n                    g[i + a] -= g[i]\
    \ * c;\n                }\n            }\n        }\n    }\n    return g;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename mint>\nvector<mint> fps_inv_sparse(const vector<pair<int,\
    \ mint>> &f_sub, int n) {\n    assert(f_sub.size() && f_sub[0].first == 0 && f_sub[0].second\
    \ != 0);\n    mint cef = f_sub[0].second.inv();\n    vector<mint> g(n);\n    g[0]\
    \ = 1;\n    for (int i = 0; i < n; i++) {\n        if (g[i] != 0) {\n        \
    \    g[i] *= cef;\n            for (auto [a,c] : f_sub) {\n                if\
    \ (0 < a && i + a < n) {\n                    g[i + a] -= g[i] * c;\n        \
    \        }\n            }\n        }\n    }\n    return g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/fps/fps_inv_sparse.hpp
  requiredBy: []
  timestamp: '2025-11-05 13:37:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fps/fps_inv_sparse.test.cpp
documentation_of: src/fps/fps_inv_sparse.hpp
layout: document
redirect_from:
- /library/src/fps/fps_inv_sparse.hpp
- /library/src/fps/fps_inv_sparse.hpp.html
title: src/fps/fps_inv_sparse.hpp
---
