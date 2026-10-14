---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/graph/dijkstra.hpp
    title: src/graph/dijkstra.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/shortst_path_weighted.hpp\"\n#include <limits>\n\
    #include <vector>\n#line 2 \"src/graph/dijkstra.hpp\"\n#include <queue>\n#line\
    \ 4 \"src/graph/dijkstra.hpp\"\nusing namespace std;\n\ntemplate<typename T1,\
    \ typename T2 = int>\npair<vector<T1>, vector<int>> dijkstra(const vector<vector<pair<int,\
    \ T2>>> &g, int s) {\n    int n = g.size();\n    vector<T1> dist(n, 1LL << 60);\n\
    \    dist[s] = 0;\n    priority_queue<pair<T1, int>> q;\n    q.emplace(0, s);\n\
    \    vector<int> par(n, -1);\n    while (q.size()) {\n        auto [d, u] = q.top();\n\
    \        d = -d;\n        q.pop();\n        if (dist[u] < d) continue;\n     \
    \   for (auto [v, w] : g[u]) {\n            if (dist[v] > d + w) {\n         \
    \       dist[v] = d + w;\n                par[v] = u;\n                q.emplace(-dist[v],\
    \ v);\n            }\n        }\n    }\n    return make_pair(dist, par);\n}\n\
    #line 5 \"src/graph/shortst_path_weighted.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ T1, typename T2 = int>\npair<T1, vector<int>> shortest_path(const vector<vector<pair<int,\
    \ T2>>> &g, int s, int t) {\n    int n = g.size();\n    vector<vector<pair<int,\
    \ T2>>> h(n);\n    for (int u = 0; u < n; u++) {\n        for (auto [v, w] : g[u])\
    \ {\n            h[v].emplace_back(u, w);\n        }\n    }\n    auto [dist, par]\
    \ = dijkstra<T1>(h, t);\n    if (dist[s] == numeric_limits<T1>::max()) return\
    \ make_pair(-1, vector<int>{});\n    vector<int> res;\n    T1 d = dist[s];\n \
    \   while (s != t) {\n        res.push_back(s);\n        s = par[s];\n    }\n\
    \    res.push_back(t);\n    return make_pair(d, res);\n}\n"
  code: "#pragma once\n#include <limits>\n#include <vector>\n#include \"dijkstra.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T1, typename T2 = int>\npair<T1, vector<int>>\
    \ shortest_path(const vector<vector<pair<int, T2>>> &g, int s, int t) {\n    int\
    \ n = g.size();\n    vector<vector<pair<int, T2>>> h(n);\n    for (int u = 0;\
    \ u < n; u++) {\n        for (auto [v, w] : g[u]) {\n            h[v].emplace_back(u,\
    \ w);\n        }\n    }\n    auto [dist, par] = dijkstra<T1>(h, t);\n    if (dist[s]\
    \ == numeric_limits<T1>::max()) return make_pair(-1, vector<int>{});\n    vector<int>\
    \ res;\n    T1 d = dist[s];\n    while (s != t) {\n        res.push_back(s);\n\
    \        s = par[s];\n    }\n    res.push_back(t);\n    return make_pair(d, res);\n\
    }"
  dependsOn:
  - src/graph/dijkstra.hpp
  isVerificationFile: false
  path: src/graph/shortst_path_weighted.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/shortst_path_weighted.hpp
layout: document
redirect_from:
- /library/src/graph/shortst_path_weighted.hpp
- /library/src/graph/shortst_path_weighted.hpp.html
title: src/graph/shortst_path_weighted.hpp
---
