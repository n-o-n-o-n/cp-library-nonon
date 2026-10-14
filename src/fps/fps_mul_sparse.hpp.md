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
  bundledCode: "#line 2 \"src/fps/fps_mul_sparse.hpp\"\n#include <cassert>\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate<typename mint>\nvector<mint> fps_mul_sparse(const\
    \ vector<mint> &f, const vector<pair<int, mint>> &g_sub) {\n    int n = f.size(),\
    \ m = 0;\n    for (auto [j, _] : g_sub) m = max(m, j);\n    vector<mint> h(n +\
    \ m);\n    for (auto [j, b] : g_sub) {\n        for (int i = 0; i < n; i++) h[i\
    \ + j] += f[i] * b;\n    }\n    while (h.size() && h.back() == 0) h.pop_back();\n\
    \    return h;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename mint>\nvector<mint> fps_mul_sparse(const vector<mint> &f,\
    \ const vector<pair<int, mint>> &g_sub) {\n    int n = f.size(), m = 0;\n    for\
    \ (auto [j, _] : g_sub) m = max(m, j);\n    vector<mint> h(n + m);\n    for (auto\
    \ [j, b] : g_sub) {\n        for (int i = 0; i < n; i++) h[i + j] += f[i] * b;\n\
    \    }\n    while (h.size() && h.back() == 0) h.pop_back();\n    return h;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/fps/fps_mul_sparse.hpp
  requiredBy: []
  timestamp: '2025-11-05 13:37:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/fps/fps_mul_sparse.hpp
layout: document
redirect_from:
- /library/src/fps/fps_mul_sparse.hpp
- /library/src/fps/fps_mul_sparse.hpp.html
title: src/fps/fps_mul_sparse.hpp
---
