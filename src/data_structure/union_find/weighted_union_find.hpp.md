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
  bundledCode: "#line 2 \"src/data_structure/union_find/weighted_union_find.hpp\"\n\
    #include <cassert>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ Abelian_Group>\nstruct weighted_dsu {\n    using S = Abelian_Group::S;\n   \
    \ weighted_dsu(int _n) : n(_n), p(n, -1), d(n, Abelian_Group::e()) {}\n    int\
    \ leader(int u) {\n        assert(0 <= u && u < n);\n        if (p[u] < 0) return\
    \ u;\n        int r = leader(p[u]);\n        d[u] = Abelian_Group::op(d[u], d[p[u]]);\n\
    \        return p[u] = r;\n    }\n    S weight(int u) {\n        assert(0 <= u\
    \ && u < n);\n        leader(u);\n        return d[u];\n    }\n    bool same(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        return leader(u) == leader(v);\n    }\n    bool merge(int u, int\
    \ v, S w) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n\
    \        if (same(u, v)) {\n            return diff(u, v) == w;\n        }\n \
    \       w = Abelian_Group::op(w, weight(u));\n        w = Abelian_Group::op(w,\
    \ Abelian_Group::inv(weight(v)));\n        u = leader(u);\n        v = leader(v);\n\
    \        assert(u != v);\n        if (p[u] > p[v]) {\n            swap(u, v);\n\
    \            w = Abelian_Group::inv(w);\n        }\n        p[u] += p[v];\n  \
    \      p[v] = u;\n        d[v] = w;\n        return true;\n    }\n    S diff(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        return Abelian_Group::op(Abelian_Group::inv(weight(u)), weight(v));\n\
    \    }\n    int size(int u) {\n        assert(0 <= u && u < n);\n        return\
    \ -p[leader(u)];\n    }\nprivate:\n    int n;\n    vector<int> p;\n    vector<S>\
    \ d;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename Abelian_Group>\nstruct weighted_dsu {\n    using S = Abelian_Group::S;\n\
    \    weighted_dsu(int _n) : n(_n), p(n, -1), d(n, Abelian_Group::e()) {}\n   \
    \ int leader(int u) {\n        assert(0 <= u && u < n);\n        if (p[u] < 0)\
    \ return u;\n        int r = leader(p[u]);\n        d[u] = Abelian_Group::op(d[u],\
    \ d[p[u]]);\n        return p[u] = r;\n    }\n    S weight(int u) {\n        assert(0\
    \ <= u && u < n);\n        leader(u);\n        return d[u];\n    }\n    bool same(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        return leader(u) == leader(v);\n    }\n    bool merge(int u, int\
    \ v, S w) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n\
    \        if (same(u, v)) {\n            return diff(u, v) == w;\n        }\n \
    \       w = Abelian_Group::op(w, weight(u));\n        w = Abelian_Group::op(w,\
    \ Abelian_Group::inv(weight(v)));\n        u = leader(u);\n        v = leader(v);\n\
    \        assert(u != v);\n        if (p[u] > p[v]) {\n            swap(u, v);\n\
    \            w = Abelian_Group::inv(w);\n        }\n        p[u] += p[v];\n  \
    \      p[v] = u;\n        d[v] = w;\n        return true;\n    }\n    S diff(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        return Abelian_Group::op(Abelian_Group::inv(weight(u)), weight(v));\n\
    \    }\n    int size(int u) {\n        assert(0 <= u && u < n);\n        return\
    \ -p[leader(u)];\n    }\nprivate:\n    int n;\n    vector<int> p;\n    vector<S>\
    \ d;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/union_find/weighted_union_find.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/union_find/weighted_union_find.hpp
layout: document
redirect_from:
- /library/src/data_structure/union_find/weighted_union_find.hpp
- /library/src/data_structure/union_find/weighted_union_find.hpp.html
title: src/data_structure/union_find/weighted_union_find.hpp
---
