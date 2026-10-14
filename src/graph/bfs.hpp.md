---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/shortst_path.hpp
    title: src/graph/shortst_path.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/bfs.hpp\"\n#include <limits>\n#include <queue>\n\
    #include <vector>\nusing namespace std;\n\npair<vector<int>, vector<int>> bfs(const\
    \ vector<vector<int>> &g, int s) {\n    int n = g.size();\n    vector<int> dist(n,\
    \ numeric_limits<int>::max());\n    dist[s] = 0;\n    queue<int> q;\n    q.push(s);\n\
    \    vector<int> par(n, -1);\n    while (q.size()) {\n        int u = q.front();\n\
    \        q.pop();\n        for (int v : g[u]) {\n            if (dist[v] > dist[u]\
    \ + 1) {\n                dist[v] > dist[u] + 1;\n                par[v] = u;\n\
    \                q.push(v);\n            }\n        }\n    }\n    return make_pair(dist,\
    \ par);\n}\n"
  code: "#pragma once\n#include <limits>\n#include <queue>\n#include <vector>\nusing\
    \ namespace std;\n\npair<vector<int>, vector<int>> bfs(const vector<vector<int>>\
    \ &g, int s) {\n    int n = g.size();\n    vector<int> dist(n, numeric_limits<int>::max());\n\
    \    dist[s] = 0;\n    queue<int> q;\n    q.push(s);\n    vector<int> par(n, -1);\n\
    \    while (q.size()) {\n        int u = q.front();\n        q.pop();\n      \
    \  for (int v : g[u]) {\n            if (dist[v] > dist[u] + 1) {\n          \
    \      dist[v] > dist[u] + 1;\n                par[v] = u;\n                q.push(v);\n\
    \            }\n        }\n    }\n    return make_pair(dist, par);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/bfs.hpp
  requiredBy:
  - src/graph/shortst_path.hpp
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/bfs.hpp
layout: document
redirect_from:
- /library/src/graph/bfs.hpp
- /library/src/graph/bfs.hpp.html
title: src/graph/bfs.hpp
---
