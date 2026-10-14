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
  bundledCode: "#line 2 \"src/tree/tree_matching.hpp\"\n#include <vector>\n#include\
    \ <queue>\nusing namespace std;\n\nstruct tree_matching {\n    tree_matching(int\
    \ n) : g(n) {}\n    tree_matching(const vector<vector<int>> &_g) : g(_g) {}\n\
    \    void add_edge(int u, int v) {\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \    }\n    vector<pair<int, int>> matching() {\n        int n = g.size();\n \
    \       par = vector<int>(n);\n        auto dfs = [&](const auto &dfs, int u,\
    \ int p) -> void {\n            par[u] = p;\n            for (int v : g[u]) {\n\
    \                if (v != p) {\n                    dfs(dfs, v, u);\n        \
    \        }\n            }\n        };\n        dfs(dfs, 0, -1);\n        queue<int>\
    \ q;\n        deg = vector<int>(n);\n        for (int i = 0; i < n; i++) {\n \
    \           deg[i] = g[i].size();\n            if (deg[i] == 1) {\n          \
    \      q.push(i);\n            }\n        }\n        used = vector<bool>(n, false);\n\
    \        vector<pair<int, int>> res;\n        res.reserve(n / 2);\n        while\
    \ (q.size()) {\n            int u = q.front();\n            q.pop();\n       \
    \     int p = par[u];\n            if (p >= 0) {\n                deg[p]--;\n\
    \                if (deg[p] == 1) q.push(p);\n                if (used[u] || used[p])\
    \ continue;\n                used[p] = used[u] = true;\n                res.emplace_back(p,\
    \ u);\n            }\n        }\n        return res;\n    }\nprivate:\n    vector<vector<int>>\
    \ g;\n    vector<int> par, deg;\n    vector<bool> used;\n};\n"
  code: "#pragma once\n#include <vector>\n#include <queue>\nusing namespace std;\n\
    \nstruct tree_matching {\n    tree_matching(int n) : g(n) {}\n    tree_matching(const\
    \ vector<vector<int>> &_g) : g(_g) {}\n    void add_edge(int u, int v) {\n   \
    \     g[u].push_back(v);\n        g[v].push_back(u);\n    }\n    vector<pair<int,\
    \ int>> matching() {\n        int n = g.size();\n        par = vector<int>(n);\n\
    \        auto dfs = [&](const auto &dfs, int u, int p) -> void {\n           \
    \ par[u] = p;\n            for (int v : g[u]) {\n                if (v != p) {\n\
    \                    dfs(dfs, v, u);\n                }\n            }\n     \
    \   };\n        dfs(dfs, 0, -1);\n        queue<int> q;\n        deg = vector<int>(n);\n\
    \        for (int i = 0; i < n; i++) {\n            deg[i] = g[i].size();\n  \
    \          if (deg[i] == 1) {\n                q.push(i);\n            }\n   \
    \     }\n        used = vector<bool>(n, false);\n        vector<pair<int, int>>\
    \ res;\n        res.reserve(n / 2);\n        while (q.size()) {\n            int\
    \ u = q.front();\n            q.pop();\n            int p = par[u];\n        \
    \    if (p >= 0) {\n                deg[p]--;\n                if (deg[p] == 1)\
    \ q.push(p);\n                if (used[u] || used[p]) continue;\n            \
    \    used[p] = used[u] = true;\n                res.emplace_back(p, u);\n    \
    \        }\n        }\n        return res;\n    }\nprivate:\n    vector<vector<int>>\
    \ g;\n    vector<int> par, deg;\n    vector<bool> used;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/tree_matching.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/tree/tree_matching.hpp
layout: document
redirect_from:
- /library/src/tree/tree_matching.hpp
- /library/src/tree/tree_matching.hpp.html
title: src/tree/tree_matching.hpp
---
