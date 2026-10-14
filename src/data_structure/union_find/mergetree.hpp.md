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
  bundledCode: "#line 2 \"src/data_structure/union_find/mergetree.hpp\"\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate<typename Monoid>\nstruct merge_tree\
    \ {\n    using S = Monoid::S;\n    merge_tree(int n) : p(n, -1), d(n, Monoid::e())\
    \ {}\n    merge_tree(const vector<S> &v) : p(v.size(), -1), d(v) {}\n    void\
    \ set(int u, const S &x) { d[u] = x; }\n    int leader(int u) const { return p[u]\
    \ < 0 ? u : leader(p[u]); }\n    bool same(int u, int v) const { return leader(u)\
    \ == leader(v); }\n    int size(int u) const { return -p[leader(u)]; }\n    S\
    \ get(int u) const { return d[leader(u)]; }\n    void merge(int u, int v) {\n\
    \        u = leader(u);\n        v = leader(v);\n        if (u == v) return;\n\
    \        if (size(u) < size(v)) swap(u, v);\n        p[u] += p[v];\n        p[v]\
    \ = u;\n        d[u] = Monoid::op(d[u], d[v]);\n        d[v] = Monoid::e();\n\
    \    }\nprivate:\n    vector<int> p;\n    vector<S> d;\n};\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ Monoid>\nstruct merge_tree {\n    using S = Monoid::S;\n    merge_tree(int n)\
    \ : p(n, -1), d(n, Monoid::e()) {}\n    merge_tree(const vector<S> &v) : p(v.size(),\
    \ -1), d(v) {}\n    void set(int u, const S &x) { d[u] = x; }\n    int leader(int\
    \ u) const { return p[u] < 0 ? u : leader(p[u]); }\n    bool same(int u, int v)\
    \ const { return leader(u) == leader(v); }\n    int size(int u) const { return\
    \ -p[leader(u)]; }\n    S get(int u) const { return d[leader(u)]; }\n    void\
    \ merge(int u, int v) {\n        u = leader(u);\n        v = leader(v);\n    \
    \    if (u == v) return;\n        if (size(u) < size(v)) swap(u, v);\n       \
    \ p[u] += p[v];\n        p[v] = u;\n        d[u] = Monoid::op(d[u], d[v]);\n \
    \       d[v] = Monoid::e();\n    }\nprivate:\n    vector<int> p;\n    vector<S>\
    \ d;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/union_find/mergetree.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/union_find/mergetree.hpp
layout: document
redirect_from:
- /library/src/data_structure/union_find/mergetree.hpp
- /library/src/data_structure/union_find/mergetree.hpp.html
title: src/data_structure/union_find/mergetree.hpp
---
