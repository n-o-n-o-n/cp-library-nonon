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
  bundledCode: "#line 2 \"src/data_structure/segtree/dual_segtree.hpp\"\n#include\
    \ <cassert>\n#include <vector>\nusing namespace std;\n\ntemplate<typename ActSet>\n\
    struct dual_segtree {\n    using M = ActSet;\n    using S = typename M::S;\n \
    \   using F = typename M::F;\n    dual_segtree() : dual_segtree(0) {}\n    dual_segtree(int\
    \ _n) : dual_segtree(vector<S>(_n, M::e())) {}\n    dual_segtree(const vector<S>\
    \ &v) { init(v); }\n    void init(const vector<S> &v) {\n        n = v.size();\n\
    \        log = 0;\n        while ((1 << log) < n) log++;\n        sz = 1 << log;\n\
    \        d = vector<S>(sz, M::e());\n        for (int i = 0; i < n; i++) d[i]\
    \ = v[i];\n        lz = vector<F>(sz, M::id());\n    }\n    void set(int p, const\
    \ S &x) {\n        assert(0 <= p && p < n);\n        inner_push(p + sz);\n   \
    \     d[p] = x;\n    }\n    void apply(int l, int r, const F &f) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        if (l == r) return;\n        l += sz, r\
    \ += sz;\n        inner_push(l);\n        inner_push(r - 1);\n        while (l\
    \ < r) {\n            if (l & 1) all_apply(l++, f);\n            if (r & 1) all_apply(--r,\
    \ f);\n            l >>= 1;\n            r >>= 1;\n        }\n    }\n    S get(int\
    \ p) {\n        assert(0 <= p && p < n);\n        inner_push(p + sz);\n      \
    \  return d[p];\n    }\nprivate:\n    int n, log, sz;\n    vector<S> d;\n    vector<F>\
    \ lz;\n    void all_apply(int p, const F &f) {\n        if (p < sz) {\n      \
    \      lz[p] = M::comp(f, lz[p]);\n        } else {\n            d[p - sz] = M::map(f,\
    \ d[p - sz]);\n        }\n    }\n    void push(int p) {\n        all_apply(2 *\
    \ p, lz[p]);\n        all_apply(2 * p + 1, lz[p]);\n        lz[p] = M::id();\n\
    \    }\n    void inner_push(int p) {\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename ActSet>\nstruct dual_segtree {\n    using M = ActSet;\n  \
    \  using S = typename M::S;\n    using F = typename M::F;\n    dual_segtree()\
    \ : dual_segtree(0) {}\n    dual_segtree(int _n) : dual_segtree(vector<S>(_n,\
    \ M::e())) {}\n    dual_segtree(const vector<S> &v) { init(v); }\n    void init(const\
    \ vector<S> &v) {\n        n = v.size();\n        log = 0;\n        while ((1\
    \ << log) < n) log++;\n        sz = 1 << log;\n        d = vector<S>(sz, M::e());\n\
    \        for (int i = 0; i < n; i++) d[i] = v[i];\n        lz = vector<F>(sz,\
    \ M::id());\n    }\n    void set(int p, const S &x) {\n        assert(0 <= p &&\
    \ p < n);\n        inner_push(p + sz);\n        d[p] = x;\n    }\n    void apply(int\
    \ l, int r, const F &f) {\n        assert(0 <= l && l <= r && r <= n);\n     \
    \   if (l == r) return;\n        l += sz, r += sz;\n        inner_push(l);\n \
    \       inner_push(r - 1);\n        while (l < r) {\n            if (l & 1) all_apply(l++,\
    \ f);\n            if (r & 1) all_apply(--r, f);\n            l >>= 1;\n     \
    \       r >>= 1;\n        }\n    }\n    S get(int p) {\n        assert(0 <= p\
    \ && p < n);\n        inner_push(p + sz);\n        return d[p];\n    }\nprivate:\n\
    \    int n, log, sz;\n    vector<S> d;\n    vector<F> lz;\n    void all_apply(int\
    \ p, const F &f) {\n        if (p < sz) {\n            lz[p] = M::comp(f, lz[p]);\n\
    \        } else {\n            d[p - sz] = M::map(f, d[p - sz]);\n        }\n\
    \    }\n    void push(int p) {\n        all_apply(2 * p, lz[p]);\n        all_apply(2\
    \ * p + 1, lz[p]);\n        lz[p] = M::id();\n    }\n    void inner_push(int p)\
    \ {\n        for (int i = log; i >= 1; i--) push(p >> i);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/segtree/dual_segtree.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/segtree/dual_segtree.hpp
layout: document
redirect_from:
- /library/src/data_structure/segtree/dual_segtree.hpp
- /library/src/data_structure/segtree/dual_segtree.hpp.html
title: src/data_structure/segtree/dual_segtree.hpp
---
