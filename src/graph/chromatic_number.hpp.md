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
  bundledCode: "#line 2 \"src/graph/chromatic_number.hpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint chromatic_number(const vector<vector<int>> &g) {\n\
    \    int n = g.size();\n    vector<vector<int>> a(n, vector<int>(n, 0));\n   \
    \ for (int u = 0; u < n; u++) {\n        for (int v : g[u]) {\n            if\
    \ (u != v) {\n                a[u][v] = a[v][u] = 1;\n            }\n        }\n\
    \    }\n    vector<int> e(n);\n    for (int i = 0; i < n; i++) {\n        for\
    \ (int j = 0; j < n; j++) {\n            e[i] |= a[i][j] << j;\n        }\n  \
    \  }\n    vector<int> ind(1 << n);\n    ind[0] = 1;\n    for (int i = 1; i < 1\
    \ << n; i++) {\n        int u = __builtin_ctz(i);\n        ind[i] = ind[i ^ (1\
    \ << u)] + ind[(i ^ (1 << u)) & ~e[u]];\n    }\n    auto ind2 = ind;\n    int\
    \ k = 1, l = 0;\n    while (true) {\n        l = 0;\n        for (int i = 0; i\
    \ < 1 << n; i++) {\n            l += (__builtin_parity(i) ? -1 : 1) * ind2[i];\n\
    \        }\n        if (l != 0) break;\n        for (int i = 1; i < 1 << n; i++)\
    \ {\n            ind2[i] *= ind[i];\n        }\n        k++;\n    }\n    return\
    \ k;\n}\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\n\nint chromatic_number(const\
    \ vector<vector<int>> &g) {\n    int n = g.size();\n    vector<vector<int>> a(n,\
    \ vector<int>(n, 0));\n    for (int u = 0; u < n; u++) {\n        for (int v :\
    \ g[u]) {\n            if (u != v) {\n                a[u][v] = a[v][u] = 1;\n\
    \            }\n        }\n    }\n    vector<int> e(n);\n    for (int i = 0; i\
    \ < n; i++) {\n        for (int j = 0; j < n; j++) {\n            e[i] |= a[i][j]\
    \ << j;\n        }\n    }\n    vector<int> ind(1 << n);\n    ind[0] = 1;\n   \
    \ for (int i = 1; i < 1 << n; i++) {\n        int u = __builtin_ctz(i);\n    \
    \    ind[i] = ind[i ^ (1 << u)] + ind[(i ^ (1 << u)) & ~e[u]];\n    }\n    auto\
    \ ind2 = ind;\n    int k = 1, l = 0;\n    while (true) {\n        l = 0;\n   \
    \     for (int i = 0; i < 1 << n; i++) {\n            l += (__builtin_parity(i)\
    \ ? -1 : 1) * ind2[i];\n        }\n        if (l != 0) break;\n        for (int\
    \ i = 1; i < 1 << n; i++) {\n            ind2[i] *= ind[i];\n        }\n     \
    \   k++;\n    }\n    return k;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/chromatic_number.hpp
  requiredBy: []
  timestamp: '2025-07-04 14:35:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/chromatic_number.hpp
layout: document
redirect_from:
- /library/src/graph/chromatic_number.hpp
- /library/src/graph/chromatic_number.hpp.html
title: src/graph/chromatic_number.hpp
---
