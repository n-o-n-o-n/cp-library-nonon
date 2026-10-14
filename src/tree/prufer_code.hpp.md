---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/random/graph.hpp
    title: src/random/graph.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree/centroid_decomposition.test.cpp
    title: test/tree/centroid_decomposition.test.cpp
  - icon: ':x:'
    path: test/tree/level_ancestor_offline.test.cpp
    title: test/tree/level_ancestor_offline.test.cpp
  - icon: ':x:'
    path: test/tree/prufer_code.test.cpp
    title: test/tree/prufer_code.test.cpp
  - icon: ':x:'
    path: test/tree/static_tree.auxiliary_tree.test.cpp
    title: test/tree/static_tree.auxiliary_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/prufer_code.hpp\"\n#include <queue>\n#include <vector>\n\
    using namespace std;\n\nvector<int> prufer_code_compress(const vector<vector<int>>\
    \ &t) {\n    int n = t.size();\n    if (n <= 2) return {};\n    vector<int> deg(n);\n\
    \    priority_queue<int, vector<int>, greater<int>> q;\n    for (int i = 0; i\
    \ < n; i++) {\n        deg[i] = t[i].size();\n        if (deg[i] == 1) {\n   \
    \         q.push(i);\n        }\n    }\n    vector<int> p;\n    p.reserve(n -\
    \ 2);\n    while ((int)p.size() < n - 2) {\n        int u = q.top();\n       \
    \ q.pop();\n        for (int v : t[u]) {\n            if (deg[v] > 0) {\n    \
    \            p.push_back(v);\n                deg[v]--;\n                if (deg[v]\
    \ == 1) q.push(v);\n                break;\n            }\n        }\n       \
    \ deg[u]--;\n    }\n    return p;\n}\n\nvector<vector<int>> prufer_code_expansion(const\
    \ vector<int> &p) {\n    int n = p.size() + 2;\n    vector<int> deg(n, 1);\n \
    \   for (int u : p) deg[u]++;\n    priority_queue<int, vector<int>, greater<int>>\
    \ q;\n    for (int i = 0; i < n; i++) {\n        if (deg[i] == 1) q.push(i);\n\
    \    }\n    vector<vector<int>> t(n);\n    for (int i = 0; i < n - 2; i++) {\n\
    \        int u = p[i];\n        int v = q.top();\n        q.pop();\n        t[u].push_back(v);\n\
    \        t[v].push_back(u);\n        deg[u]--, deg[v]--;\n        if (deg[u] ==\
    \ 1) q.push(u);\n    }\n    for (int i = 0; i < n; i++) {\n        if (deg[i]\
    \ == 1) {\n            for (int j = 0; j < n; j++) {\n                if (j !=\
    \ i && deg[j] == 1) {\n                    t[i].push_back(j);\n              \
    \      t[j].push_back(i);\n                    deg[i]--, deg[j]--;\n         \
    \           break;\n                }\n            }\n            break;\n   \
    \     }\n    }\n    return t;\n}\n"
  code: "#pragma once\n#include <queue>\n#include <vector>\nusing namespace std;\n\
    \nvector<int> prufer_code_compress(const vector<vector<int>> &t) {\n    int n\
    \ = t.size();\n    if (n <= 2) return {};\n    vector<int> deg(n);\n    priority_queue<int,\
    \ vector<int>, greater<int>> q;\n    for (int i = 0; i < n; i++) {\n        deg[i]\
    \ = t[i].size();\n        if (deg[i] == 1) {\n            q.push(i);\n       \
    \ }\n    }\n    vector<int> p;\n    p.reserve(n - 2);\n    while ((int)p.size()\
    \ < n - 2) {\n        int u = q.top();\n        q.pop();\n        for (int v :\
    \ t[u]) {\n            if (deg[v] > 0) {\n                p.push_back(v);\n  \
    \              deg[v]--;\n                if (deg[v] == 1) q.push(v);\n      \
    \          break;\n            }\n        }\n        deg[u]--;\n    }\n    return\
    \ p;\n}\n\nvector<vector<int>> prufer_code_expansion(const vector<int> &p) {\n\
    \    int n = p.size() + 2;\n    vector<int> deg(n, 1);\n    for (int u : p) deg[u]++;\n\
    \    priority_queue<int, vector<int>, greater<int>> q;\n    for (int i = 0; i\
    \ < n; i++) {\n        if (deg[i] == 1) q.push(i);\n    }\n    vector<vector<int>>\
    \ t(n);\n    for (int i = 0; i < n - 2; i++) {\n        int u = p[i];\n      \
    \  int v = q.top();\n        q.pop();\n        t[u].push_back(v);\n        t[v].push_back(u);\n\
    \        deg[u]--, deg[v]--;\n        if (deg[u] == 1) q.push(u);\n    }\n   \
    \ for (int i = 0; i < n; i++) {\n        if (deg[i] == 1) {\n            for (int\
    \ j = 0; j < n; j++) {\n                if (j != i && deg[j] == 1) {\n       \
    \             t[i].push_back(j);\n                    t[j].push_back(i);\n   \
    \                 deg[i]--, deg[j]--;\n                    break;\n          \
    \      }\n            }\n            break;\n        }\n    }\n    return t;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/prufer_code.hpp
  requiredBy:
  - src/random/graph.hpp
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree/level_ancestor_offline.test.cpp
  - test/tree/prufer_code.test.cpp
  - test/tree/centroid_decomposition.test.cpp
  - test/tree/static_tree.auxiliary_tree.test.cpp
documentation_of: src/tree/prufer_code.hpp
layout: document
redirect_from:
- /library/src/tree/prufer_code.hpp
- /library/src/tree/prufer_code.hpp.html
title: src/tree/prufer_code.hpp
---
