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
  bundledCode: "#line 2 \"src/data_structure/segtree/xor_segtree_commutative.hpp\"\
    \n#include <vector>\n#include <cassert>\nusing namespace std;\n\ntemplate<typename\
    \ Monoid>\nstruct xor_segtree {\n    using S = Monoid::S;\n    xor_segtree() :\
    \ xor_segtree(0) {}\n    xor_segtree(int _n) : xor_segtree(vector<S>(_n, Monoid::e()))\
    \ {}\n    xor_segtree(const vector<S> &v) : n(v.size()) {\n        log = 1;\n\
    \        while ((1 << log) < n) log++;\n        sz = 1 << log;\n        d = vector<S>(2\
    \ * sz, Monoid::e());\n        for (int i = 0; i < n; i++) d[i + sz] = v[i];\n\
    \        for (int i = sz - 1; i >= 1; i--) update(i);\n    }\n    void set(int\
    \ p, const S &x) {\n        assert(0 <= p && p < n);\n        p += sz;\n     \
    \   d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\
    \    S get(int p) const {\n        assert(0 <= p && p < n);\n        return d[p\
    \ + sz];\n    }\n    S prod(int l, int r, int x) const {\n        assert(0 <=\
    \ l && l <= r && r <= n);\n        l += sz;\n        r += sz;\n        S res =\
    \ Monoid::e();\n        while (l < r) {\n            if (l & 1) res = Monoid::op(res,\
    \ d[l++ ^ x]);\n            if (r & 1) res = Monoid::op(d[--r ^ x], res);\n  \
    \          l >>= 1;\n            r >>= 1;\n            x >>= 1;\n        }\n \
    \       return res;\n    }\n    S all_prod() const { return d[1]; }\nprivate:\n\
    \    int n, log, sz;\n    vector<S> d;\n    void update(int p) {\n        d[p]\
    \ = Monoid::op(d[2 * p], d[2 * p + 1]);\n    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\nusing namespace std;\n\
    \ntemplate<typename Monoid>\nstruct xor_segtree {\n    using S = Monoid::S;\n\
    \    xor_segtree() : xor_segtree(0) {}\n    xor_segtree(int _n) : xor_segtree(vector<S>(_n,\
    \ Monoid::e())) {}\n    xor_segtree(const vector<S> &v) : n(v.size()) {\n    \
    \    log = 1;\n        while ((1 << log) < n) log++;\n        sz = 1 << log;\n\
    \        d = vector<S>(2 * sz, Monoid::e());\n        for (int i = 0; i < n; i++)\
    \ d[i + sz] = v[i];\n        for (int i = sz - 1; i >= 1; i--) update(i);\n  \
    \  }\n    void set(int p, const S &x) {\n        assert(0 <= p && p < n);\n  \
    \      p += sz;\n        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n    S get(int p) const {\n        assert(0 <= p && p < n);\n\
    \        return d[p + sz];\n    }\n    S prod(int l, int r, int x) const {\n \
    \       assert(0 <= l && l <= r && r <= n);\n        l += sz;\n        r += sz;\n\
    \        S res = Monoid::e();\n        while (l < r) {\n            if (l & 1)\
    \ res = Monoid::op(res, d[l++ ^ x]);\n            if (r & 1) res = Monoid::op(d[--r\
    \ ^ x], res);\n            l >>= 1;\n            r >>= 1;\n            x >>= 1;\n\
    \        }\n        return res;\n    }\n    S all_prod() const { return d[1];\
    \ }\nprivate:\n    int n, log, sz;\n    vector<S> d;\n    void update(int p) {\n\
    \        d[p] = Monoid::op(d[2 * p], d[2 * p + 1]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/segtree/xor_segtree_commutative.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/segtree/xor_segtree_commutative.hpp
layout: document
redirect_from:
- /library/src/data_structure/segtree/xor_segtree_commutative.hpp
- /library/src/data_structure/segtree/xor_segtree_commutative.hpp.html
title: src/data_structure/segtree/xor_segtree_commutative.hpp
---
