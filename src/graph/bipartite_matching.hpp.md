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
  bundledCode: "#line 2 \"src/graph/bipartite_matching.hpp\"\n#include <queue>\n#include\
    \ <vector>\nusing namespace std;\n\nstruct bipartite_matching {\n    int n, m;\n\
    \    bipartite_matching(int _n, int _m) : n(_n), m(_m), g(_n), match(_m, -1),\
    \ used(_n) {}\n    void add_edge(int u, int v) {\n        g[u].push_back(v);\n\
    \    }\n    vector<pair<int, int>> matching() {\n        build();\n        vector<pair<int,\
    \ int>> res;\n        for (int i = 0; i < m; i++) {\n            if (match[i]\
    \ != -1) {\n                res.emplace_back(match[i], i);\n            }\n  \
    \      }\n        return res;\n    }\nprivate:\n    vector<vector<int>> g;\n \
    \   vector<int> match, dist;\n    vector<bool> vis, used;\n    void bfs() {\n\
    \        dist = vector<int>(n, 1 << 30);\n        queue<int> q;\n        for (int\
    \ i = 0; i < n; i++) {\n            if (!used[i]) {\n                q.push(i);\n\
    \                dist[i] = 0;\n            }\n        }\n        while (q.size())\
    \ {\n            int u = q.front();\n            q.pop();\n            for (int\
    \ v : g[u]) {\n                int w = match[v];\n                if (0 <= w &&\
    \ dist[w] == 1 << 30) {\n                    dist[w] = dist[u] + 1;\n        \
    \            q.push(w);\n                }\n            }\n        }\n    }\n\
    \    bool dfs(int u) {\n        vis[u] = true;\n        for (int v : g[u]) {\n\
    \            int w = match[v];\n            if (w < 0 || (!vis[w] && dist[w] ==\
    \ dist[u] + 1 && dfs(w))) {\n                match[v] = u;\n                used[u]\
    \ = true;\n                return true;\n            }\n        }\n        return\
    \ false;\n    }\n    void build() {\n        while (true) {\n            bfs();\n\
    \            vis = vector<bool>(n, false);\n            int flow = 0;\n      \
    \      for (int i = 0; i < n; i++) {\n                flow += (!used[i] && dfs(i));\n\
    \            }\n            if (flow == 0) break;\n        }\n    }\n};\n"
  code: "#pragma once\n#include <queue>\n#include <vector>\nusing namespace std;\n\
    \nstruct bipartite_matching {\n    int n, m;\n    bipartite_matching(int _n, int\
    \ _m) : n(_n), m(_m), g(_n), match(_m, -1), used(_n) {}\n    void add_edge(int\
    \ u, int v) {\n        g[u].push_back(v);\n    }\n    vector<pair<int, int>> matching()\
    \ {\n        build();\n        vector<pair<int, int>> res;\n        for (int i\
    \ = 0; i < m; i++) {\n            if (match[i] != -1) {\n                res.emplace_back(match[i],\
    \ i);\n            }\n        }\n        return res;\n    }\nprivate:\n    vector<vector<int>>\
    \ g;\n    vector<int> match, dist;\n    vector<bool> vis, used;\n    void bfs()\
    \ {\n        dist = vector<int>(n, 1 << 30);\n        queue<int> q;\n        for\
    \ (int i = 0; i < n; i++) {\n            if (!used[i]) {\n                q.push(i);\n\
    \                dist[i] = 0;\n            }\n        }\n        while (q.size())\
    \ {\n            int u = q.front();\n            q.pop();\n            for (int\
    \ v : g[u]) {\n                int w = match[v];\n                if (0 <= w &&\
    \ dist[w] == 1 << 30) {\n                    dist[w] = dist[u] + 1;\n        \
    \            q.push(w);\n                }\n            }\n        }\n    }\n\
    \    bool dfs(int u) {\n        vis[u] = true;\n        for (int v : g[u]) {\n\
    \            int w = match[v];\n            if (w < 0 || (!vis[w] && dist[w] ==\
    \ dist[u] + 1 && dfs(w))) {\n                match[v] = u;\n                used[u]\
    \ = true;\n                return true;\n            }\n        }\n        return\
    \ false;\n    }\n    void build() {\n        while (true) {\n            bfs();\n\
    \            vis = vector<bool>(n, false);\n            int flow = 0;\n      \
    \      for (int i = 0; i < n; i++) {\n                flow += (!used[i] && dfs(i));\n\
    \            }\n            if (flow == 0) break;\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/bipartite_matching.hpp
  requiredBy: []
  timestamp: '2025-09-03 07:15:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/bipartite_matching.hpp
layout: document
redirect_from:
- /library/src/graph/bipartite_matching.hpp
- /library/src/graph/bipartite_matching.hpp.html
title: src/graph/bipartite_matching.hpp
---
