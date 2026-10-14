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
  bundledCode: "#line 2 \"src/data_structure/segtree/xor_segtree_static.hpp\"\n#include\
    \ <cassert>\n#include <vector>\nusing namespace std;\n\ntemplate<typename Monoid>\n\
    struct xor_segtree {\n    using S = Monoid::S;\n    xor_segtree() : xor_segtree(0)\
    \ {}\n    xor_segtree(int _n) : xor_segtree(vector<S>(_n, Monoid::e())) {}\n \
    \   xor_segtree(const vector<S> &v) : n(v.size()) {\n        log = 1;\n      \
    \  while ((1 << log) < n) log++;\n        sz = 1 << log;\n        d = vector<vector<S>>(log\
    \ + 1, vector<S>(sz, Monoid::e()));\n        for (int i = 0; i < n; i++) d[0][i]\
    \ = v[i];\n        for (int j = 0; j < log; j++) {\n            for (int i = 0;\
    \ i < sz; i++) update(j, i);\n        }\n    }\n    S get(int p) const {\n   \
    \     assert(0 <= p && p < n);\n        return d[0][p];\n    }\n    S prod(int\
    \ l, int r, int x) const {\n        assert(0 <= l && l <= r && r <= n);\n    \
    \    assert(0 <= x && x < sz);\n        S pl = Monoid::e(), pr = Monoid::e();\n\
    \        int k = 0;\n        while (l < r) {\n            if (l & 1) pl = Monoid::op(pl,\
    \ d[k][((l++) << k) ^ x]);\n            if (r & 1) pr = Monoid::op(d[k][((--r)\
    \ << k) ^ x], pr);\n            l >>= 1;\n            r >>= 1;\n            k++;\n\
    \        }\n        return Monoid::op(pl, pr);\n    }\nprivate:\n    int n, log,\
    \ sz;\n    vector<vector<S>> d;\n    void update(int p, int q) {\n        d[p\
    \ + 1][q] = Monoid::op(d[p][q], d[p][q ^ (1 << p)]);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename Monoid>\nstruct xor_segtree {\n    using S = Monoid::S;\n\
    \    xor_segtree() : xor_segtree(0) {}\n    xor_segtree(int _n) : xor_segtree(vector<S>(_n,\
    \ Monoid::e())) {}\n    xor_segtree(const vector<S> &v) : n(v.size()) {\n    \
    \    log = 1;\n        while ((1 << log) < n) log++;\n        sz = 1 << log;\n\
    \        d = vector<vector<S>>(log + 1, vector<S>(sz, Monoid::e()));\n       \
    \ for (int i = 0; i < n; i++) d[0][i] = v[i];\n        for (int j = 0; j < log;\
    \ j++) {\n            for (int i = 0; i < sz; i++) update(j, i);\n        }\n\
    \    }\n    S get(int p) const {\n        assert(0 <= p && p < n);\n        return\
    \ d[0][p];\n    }\n    S prod(int l, int r, int x) const {\n        assert(0 <=\
    \ l && l <= r && r <= n);\n        assert(0 <= x && x < sz);\n        S pl = Monoid::e(),\
    \ pr = Monoid::e();\n        int k = 0;\n        while (l < r) {\n           \
    \ if (l & 1) pl = Monoid::op(pl, d[k][((l++) << k) ^ x]);\n            if (r &\
    \ 1) pr = Monoid::op(d[k][((--r) << k) ^ x], pr);\n            l >>= 1;\n    \
    \        r >>= 1;\n            k++;\n        }\n        return Monoid::op(pl,\
    \ pr);\n    }\nprivate:\n    int n, log, sz;\n    vector<vector<S>> d;\n    void\
    \ update(int p, int q) {\n        d[p + 1][q] = Monoid::op(d[p][q], d[p][q ^ (1\
    \ << p)]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/segtree/xor_segtree_static.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/segtree/xor_segtree_static.hpp
layout: document
redirect_from:
- /library/src/data_structure/segtree/xor_segtree_static.hpp
- /library/src/data_structure/segtree/xor_segtree_static.hpp.html
title: src/data_structure/segtree/xor_segtree_static.hpp
---
