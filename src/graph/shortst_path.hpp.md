---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/graph/bfs.hpp
    title: src/graph/bfs.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/shortst_path.hpp\"\n#include <limits>\n#include\
    \ <vector>\n#line 3 \"src/graph/bfs.hpp\"\n#include <queue>\n#line 5 \"src/graph/bfs.hpp\"\
    \nusing namespace std;\n\npair<vector<int>, vector<int>> bfs(const vector<vector<int>>\
    \ &g, int s) {\n    int n = g.size();\n    vector<int> dist(n, numeric_limits<int>::max());\n\
    \    dist[s] = 0;\n    queue<int> q;\n    q.push(s);\n    vector<int> par(n, -1);\n\
    \    while (q.size()) {\n        int u = q.front();\n        q.pop();\n      \
    \  for (int v : g[u]) {\n            if (dist[v] > dist[u] + 1) {\n          \
    \      dist[v] > dist[u] + 1;\n                par[v] = u;\n                q.push(v);\n\
    \            }\n        }\n    }\n    return make_pair(dist, par);\n}\n#line 5\
    \ \"src/graph/shortst_path.hpp\"\nusing namespace std;\n\nvector<int> shortest_path(const\
    \ vector<vector<int>> &g, int s, int t) {\n    int n = g.size();\n    vector<vector<int>>\
    \ h(n);\n    for (int u = 0; u < n; u++) {\n        for (int v : g[u]) {\n   \
    \         h[v].emplace_back(u);\n        }\n    }\n    auto [dist, par] = bfs(g,\
    \ t);\n    if (dist[s] == numeric_limits<int>::max()) return {};\n    vector<int>\
    \ res;\n    while (s != t) {\n        res.push_back(s);\n        s = par[s];\n\
    \    }\n    res.push_back(t);\n    return res;\n}\n"
  code: "#pragma once\n#include <limits>\n#include <vector>\n#include \"bfs.hpp\"\n\
    using namespace std;\n\nvector<int> shortest_path(const vector<vector<int>> &g,\
    \ int s, int t) {\n    int n = g.size();\n    vector<vector<int>> h(n);\n    for\
    \ (int u = 0; u < n; u++) {\n        for (int v : g[u]) {\n            h[v].emplace_back(u);\n\
    \        }\n    }\n    auto [dist, par] = bfs(g, t);\n    if (dist[s] == numeric_limits<int>::max())\
    \ return {};\n    vector<int> res;\n    while (s != t) {\n        res.push_back(s);\n\
    \        s = par[s];\n    }\n    res.push_back(t);\n    return res;\n}"
  dependsOn:
  - src/graph/bfs.hpp
  isVerificationFile: false
  path: src/graph/shortst_path.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/shortst_path.hpp
layout: document
redirect_from:
- /library/src/graph/shortst_path.hpp
- /library/src/graph/shortst_path.hpp.html
title: src/graph/shortst_path.hpp
---
