---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/misc/two_sat.hpp
    title: src/misc/two_sat.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/scc.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n\nstruct scc_graph {\n    scc_graph(int\
    \ _n = 0) : n(_n), g(_n), g_rev(_n) {}\n    void add_edge(int u, int v) {\n  \
    \      assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        g[u].push_back(v);\n\
    \        g_rev[v].push_back(u);\n    }\n    vector<vector<int>> scc() {\n    \
    \    id = vector<int>(n, -1);\n        vis = vector<bool>(n);\n        ord.reserve(n);\n\
    \        for (int i = 0; i < n; i++) dfs(i);\n        reverse(ord.begin(), ord.end());\n\
    \        int k = 0;\n        for (int u : ord) {\n            if (id[u] == -1)\
    \ {\n                sfd(u, k++);\n            }\n        }\n        vector<vector<int>>\
    \ res(k);\n        for (int i = 0; i < n; i++) {\n            res[id[i]].push_back(i);\n\
    \        }\n        return res;\n    }\nprivate:\n    int n;\n    vector<vector<int>>\
    \ g, g_rev;\n    vector<int> id, ord;\n    vector<bool> vis;\n    void dfs(int\
    \ u) {\n        if (vis[u]) return;\n        vis[u] = true;\n        for (int\
    \ v : g[u]) dfs(v);\n        ord.push_back(u);\n    }\n    void sfd(int u, int\
    \ k) {\n        if (id[u] != -1) return;\n        id[u] = k;\n        for (int\
    \ v : g_rev[u]) sfd(v, k);\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    using namespace std;\n\nstruct scc_graph {\n    scc_graph(int _n = 0) : n(_n),\
    \ g(_n), g_rev(_n) {}\n    void add_edge(int u, int v) {\n        assert(0 <=\
    \ u && u < n);\n        assert(0 <= v && v < n);\n        g[u].push_back(v);\n\
    \        g_rev[v].push_back(u);\n    }\n    vector<vector<int>> scc() {\n    \
    \    id = vector<int>(n, -1);\n        vis = vector<bool>(n);\n        ord.reserve(n);\n\
    \        for (int i = 0; i < n; i++) dfs(i);\n        reverse(ord.begin(), ord.end());\n\
    \        int k = 0;\n        for (int u : ord) {\n            if (id[u] == -1)\
    \ {\n                sfd(u, k++);\n            }\n        }\n        vector<vector<int>>\
    \ res(k);\n        for (int i = 0; i < n; i++) {\n            res[id[i]].push_back(i);\n\
    \        }\n        return res;\n    }\nprivate:\n    int n;\n    vector<vector<int>>\
    \ g, g_rev;\n    vector<int> id, ord;\n    vector<bool> vis;\n    void dfs(int\
    \ u) {\n        if (vis[u]) return;\n        vis[u] = true;\n        for (int\
    \ v : g[u]) dfs(v);\n        ord.push_back(u);\n    }\n    void sfd(int u, int\
    \ k) {\n        if (id[u] != -1) return;\n        id[u] = k;\n        for (int\
    \ v : g_rev[u]) sfd(v, k);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/scc.hpp
  requiredBy:
  - src/misc/two_sat.hpp
  timestamp: '2025-10-16 08:42:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/scc.hpp
layout: document
redirect_from:
- /library/src/graph/scc.hpp
- /library/src/graph/scc.hpp.html
title: src/graph/scc.hpp
---
