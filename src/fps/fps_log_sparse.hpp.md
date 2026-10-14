---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_log_sparse.test.cpp
    title: test/fps/fps_log_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/fps/fps_log_sparse.hpp\"\n#include <cassert>\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate<typename mint>\nvector<mint> fps_log_sparse(const\
    \ vector<pair<int, mint>> &f_sub, int n) {\n    assert(f_sub.size() && f_sub[0]\
    \ == make_pair(0, mint::raw(1)));\n    const int mod = mint::mod();\n    vector<mint>\
    \ g(n), inv(n);\n    for (auto [a, c] : f_sub) {\n        if(a > 0) g[a] = c;\n\
    \    }\n    if (n > 1) inv[1] = mint::raw(1);\n    for (int i = 1; i < n; i++)\
    \ {\n        mint sum = 0;\n        for (auto [a, c] : f_sub) {\n            if(0\
    \ < a && a <= i) {\n                sum += c * (i - a) * g[i - a];\n         \
    \   }\n        }\n        if (i >= 2) {\n            inv[i] = -inv[mod % i] *\
    \ (mod / i);\n            sum *= inv[i];\n        }\n        g[i] -= sum;\n  \
    \  }\n    return g;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename mint>\nvector<mint> fps_log_sparse(const vector<pair<int,\
    \ mint>> &f_sub, int n) {\n    assert(f_sub.size() && f_sub[0] == make_pair(0,\
    \ mint::raw(1)));\n    const int mod = mint::mod();\n    vector<mint> g(n), inv(n);\n\
    \    for (auto [a, c] : f_sub) {\n        if(a > 0) g[a] = c;\n    }\n    if (n\
    \ > 1) inv[1] = mint::raw(1);\n    for (int i = 1; i < n; i++) {\n        mint\
    \ sum = 0;\n        for (auto [a, c] : f_sub) {\n            if(0 < a && a <=\
    \ i) {\n                sum += c * (i - a) * g[i - a];\n            }\n      \
    \  }\n        if (i >= 2) {\n            inv[i] = -inv[mod % i] * (mod / i);\n\
    \            sum *= inv[i];\n        }\n        g[i] -= sum;\n    }\n    return\
    \ g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/fps/fps_log_sparse.hpp
  requiredBy: []
  timestamp: '2025-11-05 13:37:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fps/fps_log_sparse.test.cpp
documentation_of: src/fps/fps_log_sparse.hpp
layout: document
redirect_from:
- /library/src/fps/fps_log_sparse.hpp
- /library/src/fps/fps_log_sparse.hpp.html
title: src/fps/fps_log_sparse.hpp
---
