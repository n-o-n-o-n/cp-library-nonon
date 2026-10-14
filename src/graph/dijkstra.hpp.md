---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/shortst_path_weighted.hpp
    title: src/graph/shortst_path_weighted.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/dijkstra.hpp\"\n#include <queue>\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename T1, typename T2 = int>\npair<vector<T1>,\
    \ vector<int>> dijkstra(const vector<vector<pair<int, T2>>> &g, int s) {\n   \
    \ int n = g.size();\n    vector<T1> dist(n, 1LL << 60);\n    dist[s] = 0;\n  \
    \  priority_queue<pair<T1, int>> q;\n    q.emplace(0, s);\n    vector<int> par(n,\
    \ -1);\n    while (q.size()) {\n        auto [d, u] = q.top();\n        d = -d;\n\
    \        q.pop();\n        if (dist[u] < d) continue;\n        for (auto [v, w]\
    \ : g[u]) {\n            if (dist[v] > d + w) {\n                dist[v] = d +\
    \ w;\n                par[v] = u;\n                q.emplace(-dist[v], v);\n \
    \           }\n        }\n    }\n    return make_pair(dist, par);\n}\n"
  code: "#pragma once\n#include <queue>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename T1, typename T2 = int>\npair<vector<T1>, vector<int>> dijkstra(const\
    \ vector<vector<pair<int, T2>>> &g, int s) {\n    int n = g.size();\n    vector<T1>\
    \ dist(n, 1LL << 60);\n    dist[s] = 0;\n    priority_queue<pair<T1, int>> q;\n\
    \    q.emplace(0, s);\n    vector<int> par(n, -1);\n    while (q.size()) {\n \
    \       auto [d, u] = q.top();\n        d = -d;\n        q.pop();\n        if\
    \ (dist[u] < d) continue;\n        for (auto [v, w] : g[u]) {\n            if\
    \ (dist[v] > d + w) {\n                dist[v] = d + w;\n                par[v]\
    \ = u;\n                q.emplace(-dist[v], v);\n            }\n        }\n  \
    \  }\n    return make_pair(dist, par);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/dijkstra.hpp
  requiredBy:
  - src/graph/shortst_path_weighted.hpp
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/src/graph/dijkstra.hpp
- /library/src/graph/dijkstra.hpp.html
title: src/graph/dijkstra.hpp
---
