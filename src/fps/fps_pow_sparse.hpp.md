---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_pow_sparse.test.cpp
    title: test/fps/fps_pow_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/fps/fps_pow_sparse.hpp\"\n#include <cassert>\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate<typename mint>\nvector<mint> fps_pow_sparse(const\
    \ vector<pair<int, mint>> &f_sub, int n, long long k) {\n    vector<mint> g(n);\n\
    \    if(f_sub.empty()) {\n        if (k == 0) g[0] = mint::raw(1);\n        return\
    \ g;\n    }\n    auto [a0, c0] = f_sub[0];\n    if(0 < a0) {\n        if(k > (n\
    \ - 1) / a0) return g;\n        vector<pair<int, mint>> g_sub = f_sub;\n     \
    \   for (auto &[a,c] : g_sub) a -= a0;\n        auto h = fps_pow_sparse(g_sub,\
    \ n - k * a0, k);\n        for (int i = 0; i < n - k * a0; i++) {\n          \
    \  g[i + k * a0] = h[i];\n        }\n        return g;\n    }\n    const int mod\
    \ = mint::mod();\n    vector<mint> inv(n);\n    if (n >= 2) inv[1] = 1;\n    g[0]\
    \ = c0.pow(k);\n    mint cef = c0.inv();\n    for (int i = 1; i < n; i++) {\n\
    \        for (auto [a, c] : f_sub) {\n            if(0 < a && a <= i) {\n    \
    \            g[i] += c * g[i - a] * (mint(k + 1) * a - i);\n            }\n  \
    \      }\n        if(i >= 2) {\n            inv[i] = -inv[mod % i] * (mod / i);\n\
    \        }\n        g[i] *= inv[i] * cef;\n    }\n    return g;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename mint>\nvector<mint> fps_pow_sparse(const vector<pair<int,\
    \ mint>> &f_sub, int n, long long k) {\n    vector<mint> g(n);\n    if(f_sub.empty())\
    \ {\n        if (k == 0) g[0] = mint::raw(1);\n        return g;\n    }\n    auto\
    \ [a0, c0] = f_sub[0];\n    if(0 < a0) {\n        if(k > (n - 1) / a0) return\
    \ g;\n        vector<pair<int, mint>> g_sub = f_sub;\n        for (auto &[a,c]\
    \ : g_sub) a -= a0;\n        auto h = fps_pow_sparse(g_sub, n - k * a0, k);\n\
    \        for (int i = 0; i < n - k * a0; i++) {\n            g[i + k * a0] = h[i];\n\
    \        }\n        return g;\n    }\n    const int mod = mint::mod();\n    vector<mint>\
    \ inv(n);\n    if (n >= 2) inv[1] = 1;\n    g[0] = c0.pow(k);\n    mint cef =\
    \ c0.inv();\n    for (int i = 1; i < n; i++) {\n        for (auto [a, c] : f_sub)\
    \ {\n            if(0 < a && a <= i) {\n                g[i] += c * g[i - a] *\
    \ (mint(k + 1) * a - i);\n            }\n        }\n        if(i >= 2) {\n   \
    \         inv[i] = -inv[mod % i] * (mod / i);\n        }\n        g[i] *= inv[i]\
    \ * cef;\n    }\n    return g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/fps/fps_pow_sparse.hpp
  requiredBy: []
  timestamp: '2025-11-05 13:37:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fps/fps_pow_sparse.test.cpp
documentation_of: src/fps/fps_pow_sparse.hpp
layout: document
redirect_from:
- /library/src/fps/fps_pow_sparse.hpp
- /library/src/fps/fps_pow_sparse.hpp.html
title: src/fps/fps_pow_sparse.hpp
---
