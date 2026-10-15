---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/centroid_decomposition.test.cpp
    title: test/tree/centroid_decomposition.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/centroid_decomposition.hpp\"\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n\nstruct centroid_decomposition {\n \
    \   centroid_decomposition() = default;\n    centroid_decomposition(int _n) :\
    \ n(_n), e(0), g(_n) {\n        if (n == 1) build();\n    }\n    centroid_decomposition(const\
    \ vector<vector<int>> &_g) : n(_g.size()), g(_g) {\n        build();\n    }\n\
    \    void add_edge(int u, int v) {\n        assert(0 <= u && u < n);\n       \
    \ assert(0 <= v && v < n);\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \        if (++e == n - 1) build();\n    }\n    vector<int> operator[](int u)\
    \ const { return g[u]; }\n    int level(int u) const { return lv[u]; }\n    int\
    \ sub_size(int u) const { return sub[u]; }\n    int parent(int u) const { return\
    \ par[u]; }\n    vector<int> level_vector() const { return lv; }\n    vector<int>\
    \ sub_size_vector() const { return sub; }\n    vector<int> parent_vector() const\
    \ { return par; }\nprivate:\n    int n, e;\n    vector<vector<int>> g;\n    vector<int>\
    \ sz, lv, sub, par;\n    int dfs_size(int u, int p) {\n        sz[u] = 1;\n  \
    \      for (int v : g[u]) {\n            if (v != p && lv[v] == -1) {\n      \
    \          sz[u] += dfs_size(v, u);\n            }\n        }\n        return\
    \ sz[u];\n    }\n    int dfs_centroid(int u, int p, int s) {\n        for (int\
    \ v : g[u]) {\n            if (v != p && lv[v] == -1 && sz[v] > s / 2) {\n   \
    \             return dfs_centroid(v, u, s);\n            }\n        }\n      \
    \  return u;\n    }\n    void decompose(int u, int p, int k) {\n        int s\
    \ = dfs_size(u, -1);\n        int c = dfs_centroid(u, -1, s);\n        lv[c] =\
    \ k;\n        sub[c] = s;\n        par[c] = p;\n        for (int v : g[c]) {\n\
    \            if (lv[v] == -1) {\n                decompose(v, c, k + 1);\n   \
    \         }\n        }\n    }\n    void build() {\n        sz = lv = sub = par\
    \ = vector<int>(n, -1);\n        decompose(0, -1, 0);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \nstruct centroid_decomposition {\n    centroid_decomposition() = default;\n \
    \   centroid_decomposition(int _n) : n(_n), e(0), g(_n) {\n        if (n == 1)\
    \ build();\n    }\n    centroid_decomposition(const vector<vector<int>> &_g) :\
    \ n(_g.size()), g(_g) {\n        build();\n    }\n    void add_edge(int u, int\
    \ v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n \
    \       g[u].push_back(v);\n        g[v].push_back(u);\n        if (++e == n -\
    \ 1) build();\n    }\n    vector<int> operator[](int u) const { return g[u]; }\n\
    \    int level(int u) const { return lv[u]; }\n    int sub_size(int u) const {\
    \ return sub[u]; }\n    int parent(int u) const { return par[u]; }\n    vector<int>\
    \ level_vector() const { return lv; }\n    vector<int> sub_size_vector() const\
    \ { return sub; }\n    vector<int> parent_vector() const { return par; }\nprivate:\n\
    \    int n, e;\n    vector<vector<int>> g;\n    vector<int> sz, lv, sub, par;\n\
    \    int dfs_size(int u, int p) {\n        sz[u] = 1;\n        for (int v : g[u])\
    \ {\n            if (v != p && lv[v] == -1) {\n                sz[u] += dfs_size(v,\
    \ u);\n            }\n        }\n        return sz[u];\n    }\n    int dfs_centroid(int\
    \ u, int p, int s) {\n        for (int v : g[u]) {\n            if (v != p &&\
    \ lv[v] == -1 && sz[v] > s / 2) {\n                return dfs_centroid(v, u, s);\n\
    \            }\n        }\n        return u;\n    }\n    void decompose(int u,\
    \ int p, int k) {\n        int s = dfs_size(u, -1);\n        int c = dfs_centroid(u,\
    \ -1, s);\n        lv[c] = k;\n        sub[c] = s;\n        par[c] = p;\n    \
    \    for (int v : g[c]) {\n            if (lv[v] == -1) {\n                decompose(v,\
    \ c, k + 1);\n            }\n        }\n    }\n    void build() {\n        sz\
    \ = lv = sub = par = vector<int>(n, -1);\n        decompose(0, -1, 0);\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/centroid_decomposition.test.cpp
documentation_of: src/tree/centroid_decomposition.hpp
layout: document
redirect_from:
- /library/src/tree/centroid_decomposition.hpp
- /library/src/tree/centroid_decomposition.hpp.html
title: src/tree/centroid_decomposition.hpp
---
