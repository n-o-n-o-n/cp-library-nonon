---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/graph/scc.hpp
    title: src/graph/scc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/misc/two_sat.hpp\"\n#include <cassert>\n#include <vector>\n\
    #line 2 \"src/graph/scc.hpp\"\n#include <algorithm>\n#line 5 \"src/graph/scc.hpp\"\
    \nusing namespace std;\n\nstruct scc_graph {\n    scc_graph(int _n = 0) : n(_n),\
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
    \ v : g_rev[u]) sfd(v, k);\n    }\n};\n#line 5 \"src/misc/two_sat.hpp\"\nusing\
    \ namespace std;\n\nstruct two_sat {\n    two_sat() : two_sat(0) {}\n    two_sat(int\
    \ _n) : n(_n), g(_n) {}\n    void add_clause(int i, bool f, int j, bool g) {\n\
    \        g[f * n + i].push_back((!g) * n + j);\n        g[g * n + j].push_back((!f)\
    \ * n + i);\n    }\n    vector<bool> solve() {\n        \n    }\n    int n;\n\
    \    vector<vector<int>> g;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../graph/scc.hpp\"\
    \nusing namespace std;\n\nstruct two_sat {\n    two_sat() : two_sat(0) {}\n  \
    \  two_sat(int _n) : n(_n), g(_n) {}\n    void add_clause(int i, bool f, int j,\
    \ bool g) {\n        g[f * n + i].push_back((!g) * n + j);\n        g[g * n +\
    \ j].push_back((!f) * n + i);\n    }\n    vector<bool> solve() {\n        \n \
    \   }\n    int n;\n    vector<vector<int>> g;\n};"
  dependsOn:
  - src/graph/scc.hpp
  isVerificationFile: false
  path: src/misc/two_sat.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/two_sat.hpp
layout: document
redirect_from:
- /library/src/misc/two_sat.hpp
- /library/src/misc/two_sat.hpp.html
title: src/misc/two_sat.hpp
---
