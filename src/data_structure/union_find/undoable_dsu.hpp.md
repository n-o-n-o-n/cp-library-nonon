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
  bundledCode: "#line 2 \"src/data_structure/union_find/undoable_dsu.hpp\"\n#include\
    \ <cassert>\n#include <numeric>\n#include <stack>\n#include <tuple>\n#include\
    \ <vector>\nusing namespace std;\n\nstruct undoable_dsu {\n    undoable_dsu()\
    \ = default;\n    undoable_dsu(int n) : p(n, -1), cyc(n) {\n        iota(cyc.begin(),\
    \ cyc.end(), 0);\n    }\n    int leader(int u) const {\n        assert(0 <= u\
    \ && u < ssize(p));\n        return p[u] < 0 ? u : leader(p[u]);\n    }\n    bool\
    \ same(int u, int v) const {\n        assert(0 <= u && u < ssize(p));\n      \
    \  assert(0 <= v && v < ssize(p));\n        return leader(u) == leader(v);\n \
    \   }\n    void merge(int u, int v) {\n        assert(0 <= u && u < ssize(p));\n\
    \        assert(0 <= v && v < ssize(p));\n        u = leader(u);\n        v =\
    \ leader(v);\n        his.emplace(u, p[u], cyc[u]);\n        his.emplace(v, p[v],\
    \ cyc[v]);\n        if (u == v) return;\n        if (p[u] > p[v]) swap(u, v);\n\
    \        p[u] += p[v];\n        p[v] = u;\n        swap(cyc[u], cyc[v]);\n   \
    \ }\n    int size(int u) const {\n        assert(0 <= u && u < ssize(p));\n  \
    \      return -p[leader(u)];\n    }\n    vector<int> group(int u) const {\n  \
    \      vector<int> res = {u};\n        int v = cyc[u];\n        while (v != u)\
    \ {\n            res.push_back(v);\n            v = cyc[v];\n        }\n     \
    \   return res;\n    }\n    void undo() {\n        assert(his.size());\n     \
    \   for (auto _ : {0, 1}) {\n            auto [u, pu, cu] = his.top();\n     \
    \       his.pop();\n            p[u] = pu;\n            cyc[u] = cu;\n       \
    \ }\n    }\nprivate:\n    vector<int> p, cyc;\n    stack<tuple<int, int, int>>\
    \ his;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <numeric>\n#include <stack>\n\
    #include <tuple>\n#include <vector>\nusing namespace std;\n\nstruct undoable_dsu\
    \ {\n    undoable_dsu() = default;\n    undoable_dsu(int n) : p(n, -1), cyc(n)\
    \ {\n        iota(cyc.begin(), cyc.end(), 0);\n    }\n    int leader(int u) const\
    \ {\n        assert(0 <= u && u < ssize(p));\n        return p[u] < 0 ? u : leader(p[u]);\n\
    \    }\n    bool same(int u, int v) const {\n        assert(0 <= u && u < ssize(p));\n\
    \        assert(0 <= v && v < ssize(p));\n        return leader(u) == leader(v);\n\
    \    }\n    void merge(int u, int v) {\n        assert(0 <= u && u < ssize(p));\n\
    \        assert(0 <= v && v < ssize(p));\n        u = leader(u);\n        v =\
    \ leader(v);\n        his.emplace(u, p[u], cyc[u]);\n        his.emplace(v, p[v],\
    \ cyc[v]);\n        if (u == v) return;\n        if (p[u] > p[v]) swap(u, v);\n\
    \        p[u] += p[v];\n        p[v] = u;\n        swap(cyc[u], cyc[v]);\n   \
    \ }\n    int size(int u) const {\n        assert(0 <= u && u < ssize(p));\n  \
    \      return -p[leader(u)];\n    }\n    vector<int> group(int u) const {\n  \
    \      vector<int> res = {u};\n        int v = cyc[u];\n        while (v != u)\
    \ {\n            res.push_back(v);\n            v = cyc[v];\n        }\n     \
    \   return res;\n    }\n    void undo() {\n        assert(his.size());\n     \
    \   for (auto _ : {0, 1}) {\n            auto [u, pu, cu] = his.top();\n     \
    \       his.pop();\n            p[u] = pu;\n            cyc[u] = cu;\n       \
    \ }\n    }\nprivate:\n    vector<int> p, cyc;\n    stack<tuple<int, int, int>>\
    \ his;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/union_find/undoable_dsu.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/union_find/undoable_dsu.hpp
layout: document
redirect_from:
- /library/src/data_structure/union_find/undoable_dsu.hpp
- /library/src/data_structure/union_find/undoable_dsu.hpp.html
title: src/data_structure/union_find/undoable_dsu.hpp
---
