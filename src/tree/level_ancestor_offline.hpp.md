---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/level_ancestor_offline.test.cpp
    title: test/tree/level_ancestor_offline.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/level_ancestor_offline.hpp\"\n#include <cassert>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nstruct level_ancestor\
    \ {\n    level_ancestor(int n) : g(n), querys(n), q(0) {}\n    level_ancestor(const\
    \ vector<vector<int>> &_g) : g(_g), querys(_g.size()), q(0) {}\n    void add_edge(int\
    \ u, int v) {\n        assert(0 <= u && u < int(g.size()));\n        assert(0\
    \ <= v && v < int(g.size()));\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \    }\n    void add_query(int u, int k) {\n        assert(0 <= u && u < int(g.size()));\n\
    \        querys[u].emplace_back(k, q++);\n    }\n    vector<int> solve(int root\
    \ = 0) {\n        vector<int> ans(q);\n        vector<int> path;\n        auto\
    \ dfs = [&](const auto &dfs, int u, int p) -> void {\n            int d = path.size();\n\
    \            for (auto [k, i] : querys[u]) {\n                if (k > d) {\n \
    \                   ans[i] = -1;\n                } else {\n                 \
    \   ans[i] = path[d - k];\n                }\n            }\n            path.push_back(u);\n\
    \            for (int v : g[u]) {\n                if (v != p) {\n           \
    \         dfs(dfs, v, u);\n                }\n            }\n            path.pop_back();\n\
    \        };\n        dfs(dfs, root, -1);\n        return ans;\n    }\nprivate:\n\
    \    int q;\n    vector<vector<int>> g;\n    vector<vector<pair<int, int>>> querys;\n\
    };\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\nstruct level_ancestor {\n    level_ancestor(int n) : g(n),\
    \ querys(n), q(0) {}\n    level_ancestor(const vector<vector<int>> &_g) : g(_g),\
    \ querys(_g.size()), q(0) {}\n    void add_edge(int u, int v) {\n        assert(0\
    \ <= u && u < int(g.size()));\n        assert(0 <= v && v < int(g.size()));\n\
    \        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n    void add_query(int\
    \ u, int k) {\n        assert(0 <= u && u < int(g.size()));\n        querys[u].emplace_back(k,\
    \ q++);\n    }\n    vector<int> solve(int root = 0) {\n        vector<int> ans(q);\n\
    \        vector<int> path;\n        auto dfs = [&](const auto &dfs, int u, int\
    \ p) -> void {\n            int d = path.size();\n            for (auto [k, i]\
    \ : querys[u]) {\n                if (k > d) {\n                    ans[i] = -1;\n\
    \                } else {\n                    ans[i] = path[d - k];\n       \
    \         }\n            }\n            path.push_back(u);\n            for (int\
    \ v : g[u]) {\n                if (v != p) {\n                    dfs(dfs, v,\
    \ u);\n                }\n            }\n            path.pop_back();\n      \
    \  };\n        dfs(dfs, root, -1);\n        return ans;\n    }\nprivate:\n   \
    \ int q;\n    vector<vector<int>> g;\n    vector<vector<pair<int, int>>> querys;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/level_ancestor_offline.hpp
  requiredBy: []
  timestamp: '2025-12-29 11:10:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/level_ancestor_offline.test.cpp
documentation_of: src/tree/level_ancestor_offline.hpp
layout: document
redirect_from:
- /library/src/tree/level_ancestor_offline.hpp
- /library/src/tree/level_ancestor_offline.hpp.html
title: src/tree/level_ancestor_offline.hpp
---
