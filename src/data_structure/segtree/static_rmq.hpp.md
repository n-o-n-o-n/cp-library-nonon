---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/data_structure/sparse_table/sparse_table.hpp
    title: src/data_structure/sparse_table/sparse_table.hpp
  _extendedRequiredBy:
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
    links:
    - https://judge.yosupo.jp/submission/200540
  bundledCode: "#line 2 \"src/data_structure/segtree/static_rmq.hpp\"\n#include <cassert>\n\
    #include <vector>\n#line 2 \"src/data_structure/sparse_table/sparse_table.hpp\"\
    \n#include <bit>\n#line 5 \"src/data_structure/sparse_table/sparse_table.hpp\"\
    \nusing namespace std;\n\ntemplate<typename Monoid>\nstruct sparse_table {\n \
    \   using M = Monoid;\n    using S = typename M::S;\n    sparse_table() = default;\n\
    \    sparse_table(const vector<S> &v) : n(v.size()), b(0), d(1, v) { build();\
    \ }\n    S prod(int l, int r) const {\n        assert(0 <= l && l <= r && r <=n);\n\
    \        if (l == r) return M::e();\n        int i = bit_width(unsigned(r - l))\
    \ - 1;\n        return M::op(d[i][l], d[i][r - (1 << i)]);\n    }\nprivate:\n\
    \    int n, b, e;\n    vector<vector<S>> d;\n    void build() {\n        b = bit_width(unsigned(n));\n\
    \        d.resize(b, vector<S>(n, M::e()));\n        for (int i = 1; i < b; i++)\
    \ {\n            for (int j = 0; j + (1 << i) <=n; j++) {\n                d[i][j]\
    \ = M::op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);\n            }\n       \
    \ }\n    }\n};\n#line 5 \"src/data_structure/segtree/static_rmq.hpp\"\nusing namespace\
    \ std;\n\n// \u53C2\u8003: https://judge.yosupo.jp/submission/200540\ntemplate<typename\
    \ Monoid>\nstruct static_rmq {\n    using M = Monoid;\n    using S = typename\
    \ M::S;\n    static_rmq() = default;\n    static_rmq(const vector<S> &_v) : n(_v.size()),\
    \ v(_v), pref(_v), suf(_v) { build(); }\n    S prod(int l, int r) const {\n  \
    \      assert(0 <= l && l <= r && r <= n);\n        if (l == r) return M::e();\n\
    \        r--;\n        int bl = l >> log, br = r >> log;\n        if (bl < br)\
    \ {\n            return M::op(M::op(pref[r], suf[l]), st.prod(bl + 1, br));\n\
    \        }\n        S p = M::e();\n        for (int i = l; i <= r; i++) p = M::op(p,\
    \ v[i]);\n        return p;\n    }\nprivate:\n    int n;\n    static constexpr\
    \ int log = 4, mask = 15;\n    vector<S> v, pref, suf;\n    sparse_table<M> st;\n\
    \    void build() {\n        for (int i = 1; i < n; i++) {\n            if (i\
    \ & mask) pref[i] = M::op(pref[i - 1], v[i]);\n        }\n        for (int i =\
    \ n - 1; i > 0; i--) {\n            if (i & mask) suf[i - 1] = M::op(suf[i], v[i\
    \ - 1]);\n        }\n        st = sparse_table<M>([&]{\n            vector<S>\
    \ a(n >> log);\n            for (int i = 0; i < (n >> log); i++) {\n         \
    \       a[i] = suf[i << log];\n            }\n            return a;\n        }());\n\
    \    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../sparse_table/sparse_table.hpp\"\
    \nusing namespace std;\n\n// \u53C2\u8003: https://judge.yosupo.jp/submission/200540\n\
    template<typename Monoid>\nstruct static_rmq {\n    using M = Monoid;\n    using\
    \ S = typename M::S;\n    static_rmq() = default;\n    static_rmq(const vector<S>\
    \ &_v) : n(_v.size()), v(_v), pref(_v), suf(_v) { build(); }\n    S prod(int l,\
    \ int r) const {\n        assert(0 <= l && l <= r && r <= n);\n        if (l ==\
    \ r) return M::e();\n        r--;\n        int bl = l >> log, br = r >> log;\n\
    \        if (bl < br) {\n            return M::op(M::op(pref[r], suf[l]), st.prod(bl\
    \ + 1, br));\n        }\n        S p = M::e();\n        for (int i = l; i <= r;\
    \ i++) p = M::op(p, v[i]);\n        return p;\n    }\nprivate:\n    int n;\n \
    \   static constexpr int log = 4, mask = 15;\n    vector<S> v, pref, suf;\n  \
    \  sparse_table<M> st;\n    void build() {\n        for (int i = 1; i < n; i++)\
    \ {\n            if (i & mask) pref[i] = M::op(pref[i - 1], v[i]);\n        }\n\
    \        for (int i = n - 1; i > 0; i--) {\n            if (i & mask) suf[i -\
    \ 1] = M::op(suf[i], v[i - 1]);\n        }\n        st = sparse_table<M>([&]{\n\
    \            vector<S> a(n >> log);\n            for (int i = 0; i < (n >> log);\
    \ i++) {\n                a[i] = suf[i << log];\n            }\n            return\
    \ a;\n        }());\n    }\n};"
  dependsOn:
  - src/data_structure/sparse_table/sparse_table.hpp
  isVerificationFile: false
  path: src/data_structure/segtree/static_rmq.hpp
  requiredBy:
  - src/tree/static_tree.hpp
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree/level_ancestor_offline.test.cpp
  - test/tree/static_tree.lca.test.cpp
  - test/tree/static_tree.jump.test.cpp
  - test/tree/centroid_decomposition.test.cpp
  - test/tree/static_tree.auxiliary_tree.test.cpp
documentation_of: src/data_structure/segtree/static_rmq.hpp
layout: document
redirect_from:
- /library/src/data_structure/segtree/static_rmq.hpp
- /library/src/data_structure/segtree/static_rmq.hpp.html
title: src/data_structure/segtree/static_rmq.hpp
---
