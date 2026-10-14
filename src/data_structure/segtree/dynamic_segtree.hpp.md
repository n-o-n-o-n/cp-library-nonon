---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/data_structure/segtree/dynamic_segtree.test.cpp
    title: test/data_structure/segtree/dynamic_segtree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/segtree/dynamic_segtree.hpp\"\n#include\
    \ <cassert>\n#include <vector>\nusing namespace std;\n\ntemplate<typename Monoid,\
    \ integral T = int>\nstruct dynamic_segtree {\n    using M = Monoid;\n    using\
    \ S = typename M::S;\n    dynamic_segtree(T _n = 0, int q = 0) : n(_n) {\n   \
    \     int log = 1;\n        while (T(1) << log < n) log++;\n        d.reserve(1\
    \ + 2 * q * log);\n        root = new_node();\n    }\n    void set(T p, const\
    \ S &x) {\n        assert(0 <= p && p < n);\n        set(root, 0, n, p, x);\n\
    \    }\n    S get(T p) const {\n        assert(0 <= p && p < n);\n        return\
    \ get(root, 0, n, p);\n    }\n    S prod(T l, T r) const {\n        assert(0 <=\
    \ l && l <= r && r <= n);\n        return prod(root, 0, n, l, r);\n    }\n   \
    \ S all_prod() const {\n        return d[root].x;\n    }\nprivate:\n    struct\
    \ node {\n        S x;\n        int l, r;\n        node() : x(M::e()), l(-1),\
    \ r(-1) {}\n    };\n    T n;\n    int root;\n    vector<node> d;\n    int new_node()\
    \ {\n        int res = d.size();\n        d.emplace_back();\n        return res;\n\
    \    }\n    void update(int t) {\n        int l = d[t].l, r = d[t].r;\n      \
    \  const S pl = l == -1 ? M::e() : d[l].x;\n        const S pr = r == -1 ? M::e()\
    \ : d[r].x;\n        d[t].x = M::op(pl, pr);\n    }\n    void set(int t, T l,\
    \ T r, T p, const S &x) {\n        if (l + 1 == r) {\n            d[t].x = x;\n\
    \            return;\n        }\n        T m = (l + r) / 2;\n        if (p < m)\
    \ {\n            if (d[t].l == -1) d[t].l = new_node();\n            set(d[t].l,\
    \ l, m, p, x);\n        } else {\n            if (d[t].r == -1) d[t].r = new_node();\n\
    \            set(d[t].r, m, r, p, x);\n        }\n        update(t);\n    }\n\
    \    S get(int t, T l, T r, T p) const {\n        if (t == -1) return M::e();\n\
    \        if (l + 1 == r) return d[t].x;\n        T m = (l + r) / 2;\n        return\
    \ p < m ? get(d[t].l, l, m, p) : get(d[t].r, m, r, p);\n    }\n    S prod(int\
    \ t, T l, T r, T ql, T qr) const {\n        if (t == -1 || r <= ql || qr <= l)\
    \ return M::e();\n        if (ql <= l && r <= qr) return d[t].x;\n        T m\
    \ = (l + r) / 2;\n        return M::op(prod(d[t].l, l, m, ql, qr), prod(d[t].r,\
    \ m, r, ql, qr));\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename Monoid, integral T = int>\nstruct dynamic_segtree {\n    using\
    \ M = Monoid;\n    using S = typename M::S;\n    dynamic_segtree(T _n = 0, int\
    \ q = 0) : n(_n) {\n        int log = 1;\n        while (T(1) << log < n) log++;\n\
    \        d.reserve(1 + 2 * q * log);\n        root = new_node();\n    }\n    void\
    \ set(T p, const S &x) {\n        assert(0 <= p && p < n);\n        set(root,\
    \ 0, n, p, x);\n    }\n    S get(T p) const {\n        assert(0 <= p && p < n);\n\
    \        return get(root, 0, n, p);\n    }\n    S prod(T l, T r) const {\n   \
    \     assert(0 <= l && l <= r && r <= n);\n        return prod(root, 0, n, l,\
    \ r);\n    }\n    S all_prod() const {\n        return d[root].x;\n    }\nprivate:\n\
    \    struct node {\n        S x;\n        int l, r;\n        node() : x(M::e()),\
    \ l(-1), r(-1) {}\n    };\n    T n;\n    int root;\n    vector<node> d;\n    int\
    \ new_node() {\n        int res = d.size();\n        d.emplace_back();\n     \
    \   return res;\n    }\n    void update(int t) {\n        int l = d[t].l, r =\
    \ d[t].r;\n        const S pl = l == -1 ? M::e() : d[l].x;\n        const S pr\
    \ = r == -1 ? M::e() : d[r].x;\n        d[t].x = M::op(pl, pr);\n    }\n    void\
    \ set(int t, T l, T r, T p, const S &x) {\n        if (l + 1 == r) {\n       \
    \     d[t].x = x;\n            return;\n        }\n        T m = (l + r) / 2;\n\
    \        if (p < m) {\n            if (d[t].l == -1) d[t].l = new_node();\n  \
    \          set(d[t].l, l, m, p, x);\n        } else {\n            if (d[t].r\
    \ == -1) d[t].r = new_node();\n            set(d[t].r, m, r, p, x);\n        }\n\
    \        update(t);\n    }\n    S get(int t, T l, T r, T p) const {\n        if\
    \ (t == -1) return M::e();\n        if (l + 1 == r) return d[t].x;\n        T\
    \ m = (l + r) / 2;\n        return p < m ? get(d[t].l, l, m, p) : get(d[t].r,\
    \ m, r, p);\n    }\n    S prod(int t, T l, T r, T ql, T qr) const {\n        if\
    \ (t == -1 || r <= ql || qr <= l) return M::e();\n        if (ql <= l && r <=\
    \ qr) return d[t].x;\n        T m = (l + r) / 2;\n        return M::op(prod(d[t].l,\
    \ l, m, ql, qr), prod(d[t].r, m, r, ql, qr));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/segtree/dynamic_segtree.hpp
  requiredBy: []
  timestamp: '2026-10-14 23:16:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/data_structure/segtree/dynamic_segtree.test.cpp
documentation_of: src/data_structure/segtree/dynamic_segtree.hpp
layout: document
redirect_from:
- /library/src/data_structure/segtree/dynamic_segtree.hpp
- /library/src/data_structure/segtree/dynamic_segtree.hpp.html
title: src/data_structure/segtree/dynamic_segtree.hpp
---
