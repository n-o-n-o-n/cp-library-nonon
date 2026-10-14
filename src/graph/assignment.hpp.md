---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/graph/assignment.cpp
    title: test/graph/assignment.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/assignment.hpp\"\n#include <numeric>\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate<typename T>\nvector<int> hungarian(const\
    \ vector<vector<T>> &a) {\n    if (a.empty()) return {};\n    const T inf = numeric_limits<T>::max();\n\
    \    int h = a.size(), w = a[0].size();\n    vector<int> p(w), way(w);\n    vector<T>\
    \ u(h, T(0)), v(w, T(0)), min_v;\n    vector<bool> used;\n    for (int r = 1;\
    \ r < h; r++) {\n        p[0] = r;\n        min_v = vector<T>(w, inf);\n     \
    \   used = vector<bool>(w, false);\n        int j = 0;\n        while (p[j] !=\
    \ 0) {\n            int i = p[j], k = 0;\n            used[j] = true;\n      \
    \      T d = inf;\n            for (int c = 1; c < w; c++) {\n               \
    \ if (used[c]) continue;\n                T cur = a[i][c] - u[i] - v[c];\n   \
    \             if (cur < min_v[c]) min_v[c] = cur, way[c] = j;\n              \
    \  if (min_v[c] < d) d = min_v[c], k = c;\n            }\n            for (int\
    \ c = 0; c < w; c++) {\n                if (used[c]) u[p[c]] += d, v[c] -= d;\n\
    \                else min_v[c] -= d;\n            }\n            j = k;\n    \
    \    }\n        do {\n            p[j] = p[way[j]];\n            j = way[j];\n\
    \        } while (j != 0);\n    }\n    vector<int> res(w - 1);\n    for (int i\
    \ = 0; i < w - 1; i++) res[i] = p[i + 1] - 1;\n    return res;\n}\n\ntemplate<typename\
    \ T>\nvector<int> assignment(const vector<vector<T>> &a) {\n    int h = a.size(),\
    \ w = a[0].size();\n    vector<vector<T>> b(h + 1, vector<T>(w + 1, 0));\n   \
    \ for (int i = 0; i < h; i++) {\n        for (int j = 0; j < w; j++) b[i + 1][j\
    \ + 1] = a[i][j];\n    }\n    return hungarian(b);\n}\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename T>\nvector<int> hungarian(const vector<vector<T>> &a) {\n\
    \    if (a.empty()) return {};\n    const T inf = numeric_limits<T>::max();\n\
    \    int h = a.size(), w = a[0].size();\n    vector<int> p(w), way(w);\n    vector<T>\
    \ u(h, T(0)), v(w, T(0)), min_v;\n    vector<bool> used;\n    for (int r = 1;\
    \ r < h; r++) {\n        p[0] = r;\n        min_v = vector<T>(w, inf);\n     \
    \   used = vector<bool>(w, false);\n        int j = 0;\n        while (p[j] !=\
    \ 0) {\n            int i = p[j], k = 0;\n            used[j] = true;\n      \
    \      T d = inf;\n            for (int c = 1; c < w; c++) {\n               \
    \ if (used[c]) continue;\n                T cur = a[i][c] - u[i] - v[c];\n   \
    \             if (cur < min_v[c]) min_v[c] = cur, way[c] = j;\n              \
    \  if (min_v[c] < d) d = min_v[c], k = c;\n            }\n            for (int\
    \ c = 0; c < w; c++) {\n                if (used[c]) u[p[c]] += d, v[c] -= d;\n\
    \                else min_v[c] -= d;\n            }\n            j = k;\n    \
    \    }\n        do {\n            p[j] = p[way[j]];\n            j = way[j];\n\
    \        } while (j != 0);\n    }\n    vector<int> res(w - 1);\n    for (int i\
    \ = 0; i < w - 1; i++) res[i] = p[i + 1] - 1;\n    return res;\n}\n\ntemplate<typename\
    \ T>\nvector<int> assignment(const vector<vector<T>> &a) {\n    int h = a.size(),\
    \ w = a[0].size();\n    vector<vector<T>> b(h + 1, vector<T>(w + 1, 0));\n   \
    \ for (int i = 0; i < h; i++) {\n        for (int j = 0; j < w; j++) b[i + 1][j\
    \ + 1] = a[i][j];\n    }\n    return hungarian(b);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/assignment.hpp
  requiredBy:
  - test/graph/assignment.cpp
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/assignment.hpp
layout: document
redirect_from:
- /library/src/graph/assignment.hpp
- /library/src/graph/assignment.hpp.html
title: src/graph/assignment.hpp
---
