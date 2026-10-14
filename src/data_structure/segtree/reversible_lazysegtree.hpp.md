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
  bundledCode: "#line 2 \"src/data_structure/segtree/reversible_lazysegtree.hpp\"\n\
    #include <cassert>\n#include <tuple>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename ActMonoid>\nstruct reversible_lazysegtree {\n    using M =\
    \ ActMonoid;\n    using S = typename M::S;\n    using F = typename M::F;\n   \
    \ reversible_lazysegtree() : reversible_lazysegtree(0) { d.emplace_back(); }\n\
    \    reversible_lazysegtree(int n, int q = 0) : root(0) {\n        d.reserve(n\
    \ + q + 1);\n        d.emplace_back();\n    }\n    reversible_lazysegtree(const\
    \ vector<S> &v, int q = 0) : root(0) {\n        d.reserve(ssize(v) + q + 1);\n\
    \        d.emplace_back();\n        for (const auto &e : v) {\n            root\
    \ = merge(root, new_node(e));\n        }\n    }\n    void set(int p, const S &x)\
    \ {\n        assert(0 <= p && p < size(root));\n        auto [pl, pm, pr] = split(root,\
    \ p, p + 1);\n        d[pm].val = x;\n        update(pm);\n        root = merge(pl,\
    \ pm, pr);\n    }\n    void apply(int l, int r, const F &f) {\n        assert(0\
    \ <= l && l <= r && r <= size(root));\n        auto [pl, pm, pr] = split(root,\
    \ l, r);\n        all_apply(pm, f);\n        root = merge(pl, pm, pr);\n    }\n\
    \    void reverse(int l, int r) {\n        assert(0 <= l && l <= r && r <= size(root));\n\
    \        auto [pl, pm, pr] = split(root, l, r);\n        toggle(pm);\n       \
    \ root = merge(pl, pm, pr);\n    }\n    void insert(int p, const S &x) {\n   \
    \     assert(0 <= p && p <= size(root));\n        auto [pl, pr] = split(root,\
    \ p);\n        root = merge(pl, new_node(x), pr);\n    }\n    void push_back(const\
    \ S &x) {\n        root = merge(root, new_node(x));\n    }\n    void push_front(const\
    \ S &x) {\n        root = merge(new_node(x), root);\n    }\n    void erase(int\
    \ p) {\n        assert(0 <= p && p < size(root));\n        auto [pl, pm, pr] =\
    \ split(root, p, p + 1);\n        root = merge(pl, pr);\n    }\n    void pop_back()\
    \ {\n        assert(size(root));\n        erase(size(root) - 1);\n    }\n    void\
    \ pop_front() {\n        assert(size(root));\n        erase(0);\n    }\n    S\
    \ get(int p) {\n        assert(0 <= p && p < size(root));\n        auto [pl, pm,\
    \ pr] = split(root, p, p + 1);\n        auto res = d[pm].val;\n        root =\
    \ merge(pl, pm, pr);\n        return res;\n    }\n    S prod(int l, int r) {\n\
    \        assert(0 <= l && l <= r && r <= size(root));\n        auto [pl, pm, pr]\
    \ = split(root, l, r);\n        auto res = d[pm].sum;\n        root = merge(pl,\
    \ pm, pr);\n        return res;\n    }\nprivate:\n    struct node {\n        int\
    \ l, r, sz;\n        S val, sum, mus;\n        F f;\n        bool rev;\n     \
    \   unsigned int pri;\n        node() : l(0), r(0), sz(0), val(M::e()), sum(M::e()),\
    \ mus(M::e()), f(M::id()), rev(false) {}\n        node(const S &x) : l(0), r(0),\
    \ sz(1), val(x), sum(x), mus(x), f(M::id()), rev(false) {\n            pri = xor_shift();\n\
    \        }\n    };\n    vector<node> d;\n    int root;\n    int size(int p) {\
    \ return d[p].sz; }\n    S val(int p) { return d[p].val; }\n    S sum(int p) {\
    \ return d[p].sum; }\n    S mus(int p) { return d[p].mus; }\n    int new_node(const\
    \ S &x = M::e()) {\n        int r = d.size();\n        d.emplace_back(x);\n  \
    \      return r;\n    }\n    inline void toggle(int p) {\n        if (!p) return;\n\
    \        swap(d[p].l, d[p].r);\n        swap(d[p].sum, d[p].mus);\n        d[p].rev\
    \ ^= true;\n    }\n    void all_apply(int p, const F &f) {\n        if (!p) return;\n\
    \        d[p].f = M::comp(f, d[p].f);\n        d[p].val = M::map(f, d[p].val);\n\
    \        d[p].sum = M::map(f, d[p].sum);\n        d[p].mus = M::map(f, d[p].mus);\n\
    \    }\n    void update(int p) {\n        if (!p) return;\n        d[p].sz = size(d[p].l)\
    \ + size(d[p].r) + 1;\n        d[p].sum = M::op(d[d[p].l].sum, M::op(d[p].val,\
    \ d[d[p].r].sum));\n        d[p].mus = M::op(d[d[p].r].mus, M::op(d[p].val, d[d[p].l].mus));\n\
    \    }\n    void push(int p) {\n        if (!p) return;\n        all_apply(d[p].l,\
    \ d[p].f);\n        all_apply(d[p].r, d[p].f);\n        d[p].f = M::id();\n  \
    \      if (d[p].rev) {\n            toggle(d[p].l);\n            toggle(d[p].r);\n\
    \            d[p].rev = false;\n        }\n    }\n    int merge(int l, int r)\
    \ {\n        if (!l) return r;\n        if (!r) return l;\n        if (d[l].pri\
    \ > d[r].pri) {\n            push(l);\n            d[l].r = merge(d[l].r, r);\n\
    \            update(l);\n            return l;\n        } else {\n           \
    \ push(r);\n            d[r].l = merge(l, d[r].l);\n            update(r);\n \
    \           return r;\n        }\n    }\n    int merge(int l, int m, int r)  {\n\
    \        return merge(l, merge(m, r));\n    }\n    pair<int, int> split(int p,\
    \ int k) {\n        int pl = 0, pr = 0;\n        if (!p) return {pl, pr};\n  \
    \      push(p);\n        int ls = size(d[p].l);\n        if (k <= ls) {\n    \
    \        tie(pl, d[p].l) = split(d[p].l, k);\n            update(p);\n       \
    \     pr = p;\n        } else {\n            tie(d[p].r, pr) = split(d[p].r, k\
    \ - ls - 1);\n            update(p);\n            pl = p;\n        }\n       \
    \ return {pl, pr};\n    }\n    tuple<int, int, int> split(int p, int l, int r)\
    \ {\n        auto [plm, pr] = split(p, r);\n        auto [pl, pm] = split(plm,\
    \ l);\n        return {pl, pm, pr};\n    }\n    static unsigned int xor_shift()\
    \ {\n        static unsigned int x = 123456789;\n        static unsigned int y\
    \ = 362436069;\n        static unsigned int z = 521288629;\n        static unsigned\
    \ int w = 88675123;\n        unsigned int t = x ^ (x << 11);\n        x = y, y\
    \ = z, z = w;\n        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <tuple>\n#include <vector>\nusing\
    \ namespace std;\n\ntemplate<typename ActMonoid>\nstruct reversible_lazysegtree\
    \ {\n    using M = ActMonoid;\n    using S = typename M::S;\n    using F = typename\
    \ M::F;\n    reversible_lazysegtree() : reversible_lazysegtree(0) { d.emplace_back();\
    \ }\n    reversible_lazysegtree(int n, int q = 0) : root(0) {\n        d.reserve(n\
    \ + q + 1);\n        d.emplace_back();\n    }\n    reversible_lazysegtree(const\
    \ vector<S> &v, int q = 0) : root(0) {\n        d.reserve(ssize(v) + q + 1);\n\
    \        d.emplace_back();\n        for (const auto &e : v) {\n            root\
    \ = merge(root, new_node(e));\n        }\n    }\n    void set(int p, const S &x)\
    \ {\n        assert(0 <= p && p < size(root));\n        auto [pl, pm, pr] = split(root,\
    \ p, p + 1);\n        d[pm].val = x;\n        update(pm);\n        root = merge(pl,\
    \ pm, pr);\n    }\n    void apply(int l, int r, const F &f) {\n        assert(0\
    \ <= l && l <= r && r <= size(root));\n        auto [pl, pm, pr] = split(root,\
    \ l, r);\n        all_apply(pm, f);\n        root = merge(pl, pm, pr);\n    }\n\
    \    void reverse(int l, int r) {\n        assert(0 <= l && l <= r && r <= size(root));\n\
    \        auto [pl, pm, pr] = split(root, l, r);\n        toggle(pm);\n       \
    \ root = merge(pl, pm, pr);\n    }\n    void insert(int p, const S &x) {\n   \
    \     assert(0 <= p && p <= size(root));\n        auto [pl, pr] = split(root,\
    \ p);\n        root = merge(pl, new_node(x), pr);\n    }\n    void push_back(const\
    \ S &x) {\n        root = merge(root, new_node(x));\n    }\n    void push_front(const\
    \ S &x) {\n        root = merge(new_node(x), root);\n    }\n    void erase(int\
    \ p) {\n        assert(0 <= p && p < size(root));\n        auto [pl, pm, pr] =\
    \ split(root, p, p + 1);\n        root = merge(pl, pr);\n    }\n    void pop_back()\
    \ {\n        assert(size(root));\n        erase(size(root) - 1);\n    }\n    void\
    \ pop_front() {\n        assert(size(root));\n        erase(0);\n    }\n    S\
    \ get(int p) {\n        assert(0 <= p && p < size(root));\n        auto [pl, pm,\
    \ pr] = split(root, p, p + 1);\n        auto res = d[pm].val;\n        root =\
    \ merge(pl, pm, pr);\n        return res;\n    }\n    S prod(int l, int r) {\n\
    \        assert(0 <= l && l <= r && r <= size(root));\n        auto [pl, pm, pr]\
    \ = split(root, l, r);\n        auto res = d[pm].sum;\n        root = merge(pl,\
    \ pm, pr);\n        return res;\n    }\nprivate:\n    struct node {\n        int\
    \ l, r, sz;\n        S val, sum, mus;\n        F f;\n        bool rev;\n     \
    \   unsigned int pri;\n        node() : l(0), r(0), sz(0), val(M::e()), sum(M::e()),\
    \ mus(M::e()), f(M::id()), rev(false) {}\n        node(const S &x) : l(0), r(0),\
    \ sz(1), val(x), sum(x), mus(x), f(M::id()), rev(false) {\n            pri = xor_shift();\n\
    \        }\n    };\n    vector<node> d;\n    int root;\n    int size(int p) {\
    \ return d[p].sz; }\n    S val(int p) { return d[p].val; }\n    S sum(int p) {\
    \ return d[p].sum; }\n    S mus(int p) { return d[p].mus; }\n    int new_node(const\
    \ S &x = M::e()) {\n        int r = d.size();\n        d.emplace_back(x);\n  \
    \      return r;\n    }\n    inline void toggle(int p) {\n        if (!p) return;\n\
    \        swap(d[p].l, d[p].r);\n        swap(d[p].sum, d[p].mus);\n        d[p].rev\
    \ ^= true;\n    }\n    void all_apply(int p, const F &f) {\n        if (!p) return;\n\
    \        d[p].f = M::comp(f, d[p].f);\n        d[p].val = M::map(f, d[p].val);\n\
    \        d[p].sum = M::map(f, d[p].sum);\n        d[p].mus = M::map(f, d[p].mus);\n\
    \    }\n    void update(int p) {\n        if (!p) return;\n        d[p].sz = size(d[p].l)\
    \ + size(d[p].r) + 1;\n        d[p].sum = M::op(d[d[p].l].sum, M::op(d[p].val,\
    \ d[d[p].r].sum));\n        d[p].mus = M::op(d[d[p].r].mus, M::op(d[p].val, d[d[p].l].mus));\n\
    \    }\n    void push(int p) {\n        if (!p) return;\n        all_apply(d[p].l,\
    \ d[p].f);\n        all_apply(d[p].r, d[p].f);\n        d[p].f = M::id();\n  \
    \      if (d[p].rev) {\n            toggle(d[p].l);\n            toggle(d[p].r);\n\
    \            d[p].rev = false;\n        }\n    }\n    int merge(int l, int r)\
    \ {\n        if (!l) return r;\n        if (!r) return l;\n        if (d[l].pri\
    \ > d[r].pri) {\n            push(l);\n            d[l].r = merge(d[l].r, r);\n\
    \            update(l);\n            return l;\n        } else {\n           \
    \ push(r);\n            d[r].l = merge(l, d[r].l);\n            update(r);\n \
    \           return r;\n        }\n    }\n    int merge(int l, int m, int r)  {\n\
    \        return merge(l, merge(m, r));\n    }\n    pair<int, int> split(int p,\
    \ int k) {\n        int pl = 0, pr = 0;\n        if (!p) return {pl, pr};\n  \
    \      push(p);\n        int ls = size(d[p].l);\n        if (k <= ls) {\n    \
    \        tie(pl, d[p].l) = split(d[p].l, k);\n            update(p);\n       \
    \     pr = p;\n        } else {\n            tie(d[p].r, pr) = split(d[p].r, k\
    \ - ls - 1);\n            update(p);\n            pl = p;\n        }\n       \
    \ return {pl, pr};\n    }\n    tuple<int, int, int> split(int p, int l, int r)\
    \ {\n        auto [plm, pr] = split(p, r);\n        auto [pl, pm] = split(plm,\
    \ l);\n        return {pl, pm, pr};\n    }\n    static unsigned int xor_shift()\
    \ {\n        static unsigned int x = 123456789;\n        static unsigned int y\
    \ = 362436069;\n        static unsigned int z = 521288629;\n        static unsigned\
    \ int w = 88675123;\n        unsigned int t = x ^ (x << 11);\n        x = y, y\
    \ = z, z = w;\n        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/segtree/reversible_lazysegtree.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/segtree/reversible_lazysegtree.hpp
layout: document
redirect_from:
- /library/src/data_structure/segtree/reversible_lazysegtree.hpp
- /library/src/data_structure/segtree/reversible_lazysegtree.hpp.html
title: src/data_structure/segtree/reversible_lazysegtree.hpp
---
