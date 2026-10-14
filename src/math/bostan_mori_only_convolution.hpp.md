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
  bundledCode: "#line 2 \"src/math/bostan_mori_only_convolution.hpp\"\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n\ntemplate<typename mint, typename C>\n\
    mint Bostan_Mori(vector<mint> p, vector<mint> q, long long k, const C &conv) {\n\
    \    assert(p.size() && q.size());\n    if (k == 0) return p[0] / q[0];\n    auto\
    \ sub = [&] (const vector<mint> &f, bool odd = false) -> vector<mint> {\n    \
    \    int n = (f.size() + !odd) / 2;\n        vector<mint> g(n);\n        for (int\
    \ i = odd; i < ssize(f); i += 2) {\n            g[i / 2] = f[i];\n        }\n\
    \        return g;\n    };\n    while (k > 0) {\n        auto q2 = q;\n      \
    \  for (int i = 1; i < ssize(q2); i += 2) {\n            q2[i] = -q2[i];\n   \
    \     }\n        p = sub(conv(p, q2), k & 1);\n        q = sub(conv(q, q2));\n\
    \        k >>= 1;\n    }\n    return p[0];\n}\n\ntemplate<typename mint, typename\
    \ C>\nmint linear_recurrence(vector<mint> a, vector<mint> c, long long k, const\
    \ C &conv) {\n    assert(a.size() == c.size());\n    int n = a.size();\n    for\
    \ (auto &e : c) e = -e;\n    c.insert(c.begin(), 1);\n    a = conv(a, c);\n  \
    \  a.resize(n);\n    return Bostan_Mori<mint, C>(a, c, k, conv);\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename mint, typename C>\nmint Bostan_Mori(vector<mint> p, vector<mint>\
    \ q, long long k, const C &conv) {\n    assert(p.size() && q.size());\n    if\
    \ (k == 0) return p[0] / q[0];\n    auto sub = [&] (const vector<mint> &f, bool\
    \ odd = false) -> vector<mint> {\n        int n = (f.size() + !odd) / 2;\n   \
    \     vector<mint> g(n);\n        for (int i = odd; i < ssize(f); i += 2) {\n\
    \            g[i / 2] = f[i];\n        }\n        return g;\n    };\n    while\
    \ (k > 0) {\n        auto q2 = q;\n        for (int i = 1; i < ssize(q2); i +=\
    \ 2) {\n            q2[i] = -q2[i];\n        }\n        p = sub(conv(p, q2), k\
    \ & 1);\n        q = sub(conv(q, q2));\n        k >>= 1;\n    }\n    return p[0];\n\
    }\n\ntemplate<typename mint, typename C>\nmint linear_recurrence(vector<mint>\
    \ a, vector<mint> c, long long k, const C &conv) {\n    assert(a.size() == c.size());\n\
    \    int n = a.size();\n    for (auto &e : c) e = -e;\n    c.insert(c.begin(),\
    \ 1);\n    a = conv(a, c);\n    a.resize(n);\n    return Bostan_Mori<mint, C>(a,\
    \ c, k, conv);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/bostan_mori_only_convolution.hpp
  requiredBy: []
  timestamp: '2025-10-16 08:43:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/bostan_mori_only_convolution.hpp
layout: document
redirect_from:
- /library/src/math/bostan_mori_only_convolution.hpp
- /library/src/math/bostan_mori_only_convolution.hpp.html
title: src/math/bostan_mori_only_convolution.hpp
---
