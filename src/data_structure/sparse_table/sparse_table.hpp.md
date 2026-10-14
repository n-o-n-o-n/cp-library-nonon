---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/data_structure/segtree/static_rmq.hpp
    title: src/data_structure/segtree/static_rmq.hpp
  - icon: ':x:'
    path: src/tree/static_tree.hpp
    title: src/tree/static_tree.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree/centroid_decomposition.test.cpp
    title: test/tree/centroid_decomposition.test.cpp
  - icon: ':x:'
    path: test/tree/level_ancestor_offline.test.cpp
    title: test/tree/level_ancestor_offline.test.cpp
  - icon: ':x:'
    path: test/tree/static_tree.auxiliary_tree.test.cpp
    title: test/tree/static_tree.auxiliary_tree.test.cpp
  - icon: ':x:'
    path: test/tree/static_tree.jump.test.cpp
    title: test/tree/static_tree.jump.test.cpp
  - icon: ':x:'
    path: test/tree/static_tree.lca.test.cpp
    title: test/tree/static_tree.lca.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/sparse_table/sparse_table.hpp\"\n#include\
    \ <bit>\n#include <cassert>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ Monoid>\nstruct sparse_table {\n    using M = Monoid;\n    using S = typename\
    \ M::S;\n    sparse_table() = default;\n    sparse_table(const vector<S> &v) :\
    \ n(v.size()), b(0), d(1, v) { build(); }\n    S prod(int l, int r) const {\n\
    \        assert(0 <= l && l <= r && r <=n);\n        if (l == r) return M::e();\n\
    \        int i = bit_width(unsigned(r - l)) - 1;\n        return M::op(d[i][l],\
    \ d[i][r - (1 << i)]);\n    }\nprivate:\n    int n, b, e;\n    vector<vector<S>>\
    \ d;\n    void build() {\n        b = bit_width(unsigned(n));\n        d.resize(b,\
    \ vector<S>(n, M::e()));\n        for (int i = 1; i < b; i++) {\n            for\
    \ (int j = 0; j + (1 << i) <=n; j++) {\n                d[i][j] = M::op(d[i -\
    \ 1][j], d[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include <bit>\n#include <cassert>\n#include <vector>\nusing\
    \ namespace std;\n\ntemplate<typename Monoid>\nstruct sparse_table {\n    using\
    \ M = Monoid;\n    using S = typename M::S;\n    sparse_table() = default;\n \
    \   sparse_table(const vector<S> &v) : n(v.size()), b(0), d(1, v) { build(); }\n\
    \    S prod(int l, int r) const {\n        assert(0 <= l && l <= r && r <=n);\n\
    \        if (l == r) return M::e();\n        int i = bit_width(unsigned(r - l))\
    \ - 1;\n        return M::op(d[i][l], d[i][r - (1 << i)]);\n    }\nprivate:\n\
    \    int n, b, e;\n    vector<vector<S>> d;\n    void build() {\n        b = bit_width(unsigned(n));\n\
    \        d.resize(b, vector<S>(n, M::e()));\n        for (int i = 1; i < b; i++)\
    \ {\n            for (int j = 0; j + (1 << i) <=n; j++) {\n                d[i][j]\
    \ = M::op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);\n            }\n       \
    \ }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/sparse_table/sparse_table.hpp
  requiredBy:
  - src/data_structure/segtree/static_rmq.hpp
  - src/tree/static_tree.hpp
  timestamp: '2025-06-26 18:46:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree/level_ancestor_offline.test.cpp
  - test/tree/static_tree.lca.test.cpp
  - test/tree/static_tree.jump.test.cpp
  - test/tree/centroid_decomposition.test.cpp
  - test/tree/static_tree.auxiliary_tree.test.cpp
documentation_of: src/data_structure/sparse_table/sparse_table.hpp
layout: document
redirect_from:
- /library/src/data_structure/sparse_table/sparse_table.hpp
- /library/src/data_structure/sparse_table/sparse_table.hpp.html
title: src/data_structure/sparse_table/sparse_table.hpp
---
