---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree/diameter.test.cpp
    title: test/tree/diameter.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/diameter.hpp\"\n#include <algorithm>\n#include\
    \ <limits>\n#include <queue>\n#include <utility>\n#include <vector>\nusing namespace\
    \ std;\n\ntemplate<typename T>\npair<T, vector<int>> diameter(const vector<vector<pair<int,\
    \ T>>> &g) {\n    int n = g.size();\n    const T inf = numeric_limits<T>::max()\
    \ / 2;\n    auto bfs = [&](int root) -> vector<T> {\n        vector<T> dist(n,\
    \ inf);\n        dist[root] = 0;\n        queue<int> q;\n        q.push(root);\n\
    \        while (q.size()) {\n            int u = q.front();\n            q.pop();\n\
    \            for (auto[v, w] : g[u]) {\n                if (dist[v] > dist[u]\
    \ + w) {\n                    dist[v] = dist[u] + w;\n                    q.push(v);\n\
    \                }\n            }\n        }\n        return dist;\n    };\n \
    \   vector<T> d0 = bfs(0);\n    int l = max_element(d0.begin(), d0.end()) - d0.begin();\n\
    \    vector<T> dl = bfs(l);\n    int r = max_element(dl.begin(), dl.end()) - dl.begin();\n\
    \    T diam = dl[r];\n    vector<int> path = {r};\n    while (r != l) {\n    \
    \    for (auto[v, w] : g[r]) {\n            if (dl[v] + w == dl[r]) {\n      \
    \          r = v;\n                break;\n            }\n        }\n        path.emplace_back(r);\n\
    \    }\n    return make_pair(diam, path);\n}\n\npair<int, vector<int>> diameter(const\
    \ vector<vector<int>> &g) {\n    int n = g.size();\n    vector<vector<pair<int,\
    \ int>>> tmp(n);\n    for (int u = 0; u < n; u++) {\n        for (int v : g[u])\
    \ {\n            tmp[u].emplace_back(v, 1);\n        }\n    }\n    return diameter(tmp);\n\
    }\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <queue>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ T>\npair<T, vector<int>> diameter(const vector<vector<pair<int, T>>> &g) {\n\
    \    int n = g.size();\n    const T inf = numeric_limits<T>::max() / 2;\n    auto\
    \ bfs = [&](int root) -> vector<T> {\n        vector<T> dist(n, inf);\n      \
    \  dist[root] = 0;\n        queue<int> q;\n        q.push(root);\n        while\
    \ (q.size()) {\n            int u = q.front();\n            q.pop();\n       \
    \     for (auto[v, w] : g[u]) {\n                if (dist[v] > dist[u] + w) {\n\
    \                    dist[v] = dist[u] + w;\n                    q.push(v);\n\
    \                }\n            }\n        }\n        return dist;\n    };\n \
    \   vector<T> d0 = bfs(0);\n    int l = max_element(d0.begin(), d0.end()) - d0.begin();\n\
    \    vector<T> dl = bfs(l);\n    int r = max_element(dl.begin(), dl.end()) - dl.begin();\n\
    \    T diam = dl[r];\n    vector<int> path = {r};\n    while (r != l) {\n    \
    \    for (auto[v, w] : g[r]) {\n            if (dl[v] + w == dl[r]) {\n      \
    \          r = v;\n                break;\n            }\n        }\n        path.emplace_back(r);\n\
    \    }\n    return make_pair(diam, path);\n}\n\npair<int, vector<int>> diameter(const\
    \ vector<vector<int>> &g) {\n    int n = g.size();\n    vector<vector<pair<int,\
    \ int>>> tmp(n);\n    for (int u = 0; u < n; u++) {\n        for (int v : g[u])\
    \ {\n            tmp[u].emplace_back(v, 1);\n        }\n    }\n    return diameter(tmp);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/diameter.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree/diameter.test.cpp
documentation_of: src/tree/diameter.hpp
layout: document
redirect_from:
- /library/src/tree/diameter.hpp
- /library/src/tree/diameter.hpp.html
title: src/tree/diameter.hpp
---
