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
  bundledCode: "#line 2 \"src/data_structure/union_find/dsu.hpp\"\n#include <cassert>\n\
    #include <iterator>\n#include <vector>\nusing namespace std;\n\nstruct dsu {\n\
    \    dsu(int n) : p(n, -1) {}\n    int leader(int u) const {\n        assert(0\
    \ <= u && u < ssize(p));\n        return p[u] < 0 ? u : leader(p[u]);\n    }\n\
    \    bool same(int u, int v) const {\n        assert(0 <= u && u < ssize(p));\n\
    \        assert(0 <= v && v < ssize(p));\n        return leader(u) == leader(v);\n\
    \    }\n    void merge(int u, int v) {\n        assert(0 <= u && u < ssize(p));\n\
    \        assert(0 <= v && v < ssize(p));\n        u = leader(u);\n        v =\
    \ leader(v);\n        if (u == v) return;\n        if (p[u] > p[v]) swap(u, v);\n\
    \        p[u] += p[v];\n        p[v] = u;\n    }\n    int size(int u) const {\n\
    \        assert(0 <= u && u < ssize(p));\n        return -p[leader(u)];\n    }\n\
    \    vector<vector<int>> groups() const {\n        int n = p.size();\n       \
    \ vector<vector<int>> tmp(n);\n        for (int i = 0; i < n; i++) {\n       \
    \     tmp[leader(i)].push_back(i);\n        }\n        vector<vector<int>> res;\n\
    \        for (auto v : tmp) {\n            if (v.size()) res.push_back(v);\n \
    \       }\n        return res;\n    }\nprivate:\n    vector<int> p;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <iterator>\n#include <vector>\n\
    using namespace std;\n\nstruct dsu {\n    dsu(int n) : p(n, -1) {}\n    int leader(int\
    \ u) const {\n        assert(0 <= u && u < ssize(p));\n        return p[u] < 0\
    \ ? u : leader(p[u]);\n    }\n    bool same(int u, int v) const {\n        assert(0\
    \ <= u && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n        return\
    \ leader(u) == leader(v);\n    }\n    void merge(int u, int v) {\n        assert(0\
    \ <= u && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n        u =\
    \ leader(u);\n        v = leader(v);\n        if (u == v) return;\n        if\
    \ (p[u] > p[v]) swap(u, v);\n        p[u] += p[v];\n        p[v] = u;\n    }\n\
    \    int size(int u) const {\n        assert(0 <= u && u < ssize(p));\n      \
    \  return -p[leader(u)];\n    }\n    vector<vector<int>> groups() const {\n  \
    \      int n = p.size();\n        vector<vector<int>> tmp(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            tmp[leader(i)].push_back(i);\n        }\n\
    \        vector<vector<int>> res;\n        for (auto v : tmp) {\n            if\
    \ (v.size()) res.push_back(v);\n        }\n        return res;\n    }\nprivate:\n\
    \    vector<int> p;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/union_find/dsu.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/union_find/dsu.hpp
layout: document
redirect_from:
- /library/src/data_structure/union_find/dsu.hpp
- /library/src/data_structure/union_find/dsu.hpp.html
title: src/data_structure/union_find/dsu.hpp
---
