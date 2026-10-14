---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/data_structure/misc/dynamic_point_add_rectangle_sum.hpp
    title: src/data_structure/misc/dynamic_point_add_rectangle_sum.hpp
  - icon: ':warning:'
    path: src/data_structure/misc/dynamic_rectangle_add_point_get.hpp
    title: src/data_structure/misc/dynamic_rectangle_add_point_get.hpp
  - icon: ':warning:'
    path: src/data_structure/misc/static_point_add_rectangle_sum.hpp
    title: src/data_structure/misc/static_point_add_rectangle_sum.hpp
  - icon: ':warning:'
    path: src/data_structure/misc/static_rectangle_add_point_get.hpp
    title: src/data_structure/misc/static_rectangle_add_point_get.hpp
  - icon: ':warning:'
    path: src/data_structure/segtree/range_add_fenwick_tree_abelian_group.hpp
    title: src/data_structure/segtree/range_add_fenwick_tree_abelian_group.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/segtree/fenwick_tree_abelian_group.hpp\"\
    \n#include <cassert>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ Abelian_Group>\nstruct fenwick_tree {\n    using M = Abelian_Group;\n    using\
    \ S = typename M::S;\n    fenwick_tree() = default;\n    fenwick_tree(int _n)\
    \ : fenwick_tree(vector<S>(_n, M::e())) {}\n    fenwick_tree(const vector<S> &_v)\
    \ : n(_v.size()) {\n        d = vector<S>(n, M::e());\n        v = vector<S>(n,\
    \ M::e());\n        for (int i = 1; i <= n; i++) {\n            v[i - 1] = _v[i\
    \ - 1];\n            d[i - 1] += v[i - 1];\n            int j = i + (i & -i);\n\
    \            if (j <= n) d[j - 1] += d[i - 1];\n        }\n    }\n    void add(int\
    \ p, S x) {\n        assert(0 <= p && p < n);\n        v[p] = M::op(v[p], x);\n\
    \        for (p++; p <= n; p += p & -p) {\n            d[p - 1] = M::op(d[p -\
    \ 1], x);\n        }\n    }\n    void set(int p, S x) {\n        assert(0 <= p\
    \ && p < n);\n        add(p, M::op(x, M::inv(v[p])));\n    }\n    S prod(int l,\
    \ int r) const {\n        assert(0 <= l && l <= r && r <= n);\n        return\
    \ prod(r) - prod(l);\n    }\nprivate:\n    int n;\n    vector<S> d, v;\n    S\
    \ prod(int p) const {\n        S res = M::e();\n        for (; p > 0; p -= p &\
    \ -p) {\n            res = M::op(res, d[p - 1]);\n        }\n        return res;\n\
    \    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename Abelian_Group>\nstruct fenwick_tree {\n    using M = Abelian_Group;\n\
    \    using S = typename M::S;\n    fenwick_tree() = default;\n    fenwick_tree(int\
    \ _n) : fenwick_tree(vector<S>(_n, M::e())) {}\n    fenwick_tree(const vector<S>\
    \ &_v) : n(_v.size()) {\n        d = vector<S>(n, M::e());\n        v = vector<S>(n,\
    \ M::e());\n        for (int i = 1; i <= n; i++) {\n            v[i - 1] = _v[i\
    \ - 1];\n            d[i - 1] += v[i - 1];\n            int j = i + (i & -i);\n\
    \            if (j <= n) d[j - 1] += d[i - 1];\n        }\n    }\n    void add(int\
    \ p, S x) {\n        assert(0 <= p && p < n);\n        v[p] = M::op(v[p], x);\n\
    \        for (p++; p <= n; p += p & -p) {\n            d[p - 1] = M::op(d[p -\
    \ 1], x);\n        }\n    }\n    void set(int p, S x) {\n        assert(0 <= p\
    \ && p < n);\n        add(p, M::op(x, M::inv(v[p])));\n    }\n    S prod(int l,\
    \ int r) const {\n        assert(0 <= l && l <= r && r <= n);\n        return\
    \ prod(r) - prod(l);\n    }\nprivate:\n    int n;\n    vector<S> d, v;\n    S\
    \ prod(int p) const {\n        S res = M::e();\n        for (; p > 0; p -= p &\
    \ -p) {\n            res = M::op(res, d[p - 1]);\n        }\n        return res;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/segtree/fenwick_tree_abelian_group.hpp
  requiredBy:
  - src/data_structure/misc/static_rectangle_add_point_get.hpp
  - src/data_structure/misc/static_point_add_rectangle_sum.hpp
  - src/data_structure/misc/dynamic_rectangle_add_point_get.hpp
  - src/data_structure/misc/dynamic_point_add_rectangle_sum.hpp
  - src/data_structure/segtree/range_add_fenwick_tree_abelian_group.hpp
  timestamp: '2025-04-12 11:39:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/segtree/fenwick_tree_abelian_group.hpp
layout: document
redirect_from:
- /library/src/data_structure/segtree/fenwick_tree_abelian_group.hpp
- /library/src/data_structure/segtree/fenwick_tree_abelian_group.hpp.html
title: src/data_structure/segtree/fenwick_tree_abelian_group.hpp
---
