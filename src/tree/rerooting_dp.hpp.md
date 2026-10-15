---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/rerooting_dp.test.cpp
    title: test/tree/rerooting_dp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/rerooting_dp.hpp\"\n#include <vector>\nusing namespace\
    \ std;\n\ntemplate<typename Monoid>\nstruct rerooting_dp {\n    using S = Monoid::S;\n\
    \    rerooting_dp(int n) : g(n), pos(0) {}\n    void add_edge(int u, int v) {\n\
    \        g[u].emplace_back(v, pos);\n        g[v].emplace_back(u, pos);\n    \
    \    pos++;\n    }\n    template<typename L1, typename L2>\n    vector<S> run(const\
    \ L1 &apply_vertex, const L2 &apply_edge) {\n        vector<S> memo(g.size(),\
    \ Monoid::e()), dp(g.size(), Monoid::e());\n        auto dfs = [&](const auto\
    \ &dfs, int u, int p) -> void {\n            for (const auto &[v, i] : g[u]) {\n\
    \                if (v != p) {\n                    dfs(dfs, v, u);\n        \
    \            memo[u] = Monoid::op(memo[u], apply_edge(memo[v], i));\n        \
    \        }\n            }\n            memo[u] = apply_vertex(memo[u], u);\n \
    \       };\n        auto reroot = [&](const auto &reroot, int u, int p, const\
    \ S &x) -> void {\n            vector<S> d = {x};\n            for (const auto\
    \ &[v, i] : g[u]) {\n                if (v != p) {\n                    d.push_back(apply_edge(memo[v],\
    \ i));\n                }\n            }\n            int n = d.size();\n    \
    \        vector<S> pre(n + 1, Monoid::e()), suf(n + 1, Monoid::e());\n       \
    \     for (int i = 0; i < n; i++) {\n                pre[i + 1] = Monoid::op(pre[i],\
    \ d[i]);\n            }\n            for (int i = n; i > 0; i--) {\n         \
    \       suf[i - 1] = Monoid::op(suf[i], d[i - 1]);\n            }\n          \
    \  dp[u] = apply_vertex(pre[n], u);\n            int k = 1;\n            for (const\
    \ auto &[v, i] : g[u]) {\n                if (v != p) {\n                    S\
    \ y = Monoid::op(pre[k], suf[k + 1]);\n                    reroot(reroot, v, u,\
    \ apply_edge(apply_vertex(y, u), i));\n                    k++;\n            \
    \    }\n            }\n        };\n        dfs(dfs, 0, -1);\n        reroot(reroot,\
    \ 0, -1, Monoid::e());\n        return dp;\n    }\nprivate:\n    vector<vector<pair<int,\
    \ int>>> g;\n    int pos;\n};\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ Monoid>\nstruct rerooting_dp {\n    using S = Monoid::S;\n    rerooting_dp(int\
    \ n) : g(n), pos(0) {}\n    void add_edge(int u, int v) {\n        g[u].emplace_back(v,\
    \ pos);\n        g[v].emplace_back(u, pos);\n        pos++;\n    }\n    template<typename\
    \ L1, typename L2>\n    vector<S> run(const L1 &apply_vertex, const L2 &apply_edge)\
    \ {\n        vector<S> memo(g.size(), Monoid::e()), dp(g.size(), Monoid::e());\n\
    \        auto dfs = [&](const auto &dfs, int u, int p) -> void {\n           \
    \ for (const auto &[v, i] : g[u]) {\n                if (v != p) {\n         \
    \           dfs(dfs, v, u);\n                    memo[u] = Monoid::op(memo[u],\
    \ apply_edge(memo[v], i));\n                }\n            }\n            memo[u]\
    \ = apply_vertex(memo[u], u);\n        };\n        auto reroot = [&](const auto\
    \ &reroot, int u, int p, const S &x) -> void {\n            vector<S> d = {x};\n\
    \            for (const auto &[v, i] : g[u]) {\n                if (v != p) {\n\
    \                    d.push_back(apply_edge(memo[v], i));\n                }\n\
    \            }\n            int n = d.size();\n            vector<S> pre(n + 1,\
    \ Monoid::e()), suf(n + 1, Monoid::e());\n            for (int i = 0; i < n; i++)\
    \ {\n                pre[i + 1] = Monoid::op(pre[i], d[i]);\n            }\n \
    \           for (int i = n; i > 0; i--) {\n                suf[i - 1] = Monoid::op(suf[i],\
    \ d[i - 1]);\n            }\n            dp[u] = apply_vertex(pre[n], u);\n  \
    \          int k = 1;\n            for (const auto &[v, i] : g[u]) {\n       \
    \         if (v != p) {\n                    S y = Monoid::op(pre[k], suf[k +\
    \ 1]);\n                    reroot(reroot, v, u, apply_edge(apply_vertex(y, u),\
    \ i));\n                    k++;\n                }\n            }\n        };\n\
    \        dfs(dfs, 0, -1);\n        reroot(reroot, 0, -1, Monoid::e());\n     \
    \   return dp;\n    }\nprivate:\n    vector<vector<pair<int, int>>> g;\n    int\
    \ pos;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/rerooting_dp.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/rerooting_dp.test.cpp
documentation_of: src/tree/rerooting_dp.hpp
layout: document
redirect_from:
- /library/src/tree/rerooting_dp.hpp
- /library/src/tree/rerooting_dp.hpp.html
title: src/tree/rerooting_dp.hpp
---
