---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/data_structure/segtree/range_tree.hpp
    title: src/data_structure/segtree/range_tree.hpp
  - icon: ':warning:'
    path: src/dp/triangular_transition.hpp
    title: src/dp/triangular_transition.hpp
  - icon: ':warning:'
    path: src/string/numeric_rolling_hash_dynamic.hpp
    title: src/string/numeric_rolling_hash_dynamic.hpp
  - icon: ':warning:'
    path: src/string/rolling_hash_dynamic.hpp
    title: src/string/rolling_hash_dynamic.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/monoid/add.test.cpp
    title: test/monoid/add.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/hld.commutative.test.cpp
    title: test/tree/hld.commutative.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/hld.test.cpp
    title: test/tree/hld.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/range_contour_aggregator.test.cpp
    title: test/tree/range_contour_aggregator.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/segtree/segtree.hpp\"\n#include <vector>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <typename Monoid>\nstruct\
    \ segtree {\n    using M = Monoid;\n    using S = typename M::S;\n    segtree()\
    \ : segtree(0) {}\n    segtree(int _n) : segtree(vector<S>(_n, M::e())) {}\n \
    \   segtree(const vector<S> &v) : n(v.size()) {\n        log = 1;\n        while\
    \ ((1 << log) < n) log++;\n        sz = 1 << log;\n        d = vector<S>(2 * sz,\
    \ M::e());\n        for (int i = 0; i < n; i++) d[i + sz] = v[i];\n        for\
    \ (int i = sz - 1; i >= 1; i--) update(i);\n    }\n    void set(int p, const S\
    \ &x) {\n        assert(0 <= p && p < n);\n        p += sz;\n        d[p] = x;\n\
    \        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n    void apply(int\
    \ p, const S &x) {\n        assert(0 <= p && p < n);\n        set(p, M::op(x,\
    \ d[p + sz]));\n    }\n    S get(int p) const {\n        assert(0 <= p && p <\
    \ n);\n        return d[p + sz];\n    }\n    S prod(int l, int r) const {\n  \
    \      assert(0 <= l && l <= r && r <= n);\n        l += sz;\n        r += sz;\n\
    \        S pl = M::e(), pr = M::e();\n        while (l < r) {\n            if\
    \ (l & 1) pl = M::op(pl, d[l++]);\n            if (r & 1) pr = M::op(d[--r], pr);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n        return M::op(pl,\
    \ pr);\n    }\n    S all_prod() const { return d[1]; }\n    template<typename\
    \ C>\n    int max_right(int l, const C &check) const {\n        assert(0 <= l\
    \ && l <= n);\n        assert(check(M::e()));\n        if (l == n) return l;\n\
    \        l += sz;\n        S p = M::e();\n        do {\n            while (!(l\
    \ & 1)) l >>= 1;\n            S np = M::op(p, d[l]);\n            if (!check(np))\
    \ {\n                while (l < sz) {\n                    l <<= 1;\n        \
    \            np = M::op(p, d[l]);\n                    if (check(np)) {\n    \
    \                    p = np;\n                        l++;\n                 \
    \   }\n                }\n                return l - sz;\n            }\n    \
    \        p = np;\n            l++;\n        } while ((l & -l) != l);\n       \
    \ return n;\n    }\n    template<typename C>\n    int max_right(const C &check)\
    \ const {\n        return max_right(0, check);\n    }\n    template<typename C>\n\
    \    int min_left(int r, const C &check) const {\n        assert(0 <= r && r <=\
    \ n);\n        assert(check(M::e()));\n        if (r == 0) return r;\n       \
    \ r += sz;\n        S p = M::e();\n        do {\n            r--;\n          \
    \  while (r > 1 && r & 1) r >>= 1;\n            S np = M::op(d[r], p);\n     \
    \       if (!check(np)) {\n                while (r < sz) {\n                \
    \    (r <<= 1)++;\n                    np = M::op(d[r], p);\n                \
    \    if (check(np)) {\n                        p = np;\n                     \
    \   r--;\n                    }\n                }\n                return r +\
    \ 1 - sz;\n            }\n            p = np;\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n    template<typename C>\n    int min_left(const C\
    \ &check) const {\n        return min_left(n, check);\n    }\nprivate:\n    int\
    \ n, log, sz;\n    vector<S> d;\n    void update(int p) {\n        d[p] = M::op(d[2\
    \ * p], d[2 * p + 1]);\n    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\nusing namespace std;\n\
    \ntemplate <typename Monoid>\nstruct segtree {\n    using M = Monoid;\n    using\
    \ S = typename M::S;\n    segtree() : segtree(0) {}\n    segtree(int _n) : segtree(vector<S>(_n,\
    \ M::e())) {}\n    segtree(const vector<S> &v) : n(v.size()) {\n        log =\
    \ 1;\n        while ((1 << log) < n) log++;\n        sz = 1 << log;\n        d\
    \ = vector<S>(2 * sz, M::e());\n        for (int i = 0; i < n; i++) d[i + sz]\
    \ = v[i];\n        for (int i = sz - 1; i >= 1; i--) update(i);\n    }\n    void\
    \ set(int p, const S &x) {\n        assert(0 <= p && p < n);\n        p += sz;\n\
    \        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n \
    \   }\n    void apply(int p, const S &x) {\n        assert(0 <= p && p < n);\n\
    \        set(p, M::op(x, d[p + sz]));\n    }\n    S get(int p) const {\n     \
    \   assert(0 <= p && p < n);\n        return d[p + sz];\n    }\n    S prod(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n        l +=\
    \ sz;\n        r += sz;\n        S pl = M::e(), pr = M::e();\n        while (l\
    \ < r) {\n            if (l & 1) pl = M::op(pl, d[l++]);\n            if (r &\
    \ 1) pr = M::op(d[--r], pr);\n            l >>= 1;\n            r >>= 1;\n   \
    \     }\n        return M::op(pl, pr);\n    }\n    S all_prod() const { return\
    \ d[1]; }\n    template<typename C>\n    int max_right(int l, const C &check)\
    \ const {\n        assert(0 <= l && l <= n);\n        assert(check(M::e()));\n\
    \        if (l == n) return l;\n        l += sz;\n        S p = M::e();\n    \
    \    do {\n            while (!(l & 1)) l >>= 1;\n            S np = M::op(p,\
    \ d[l]);\n            if (!check(np)) {\n                while (l < sz) {\n  \
    \                  l <<= 1;\n                    np = M::op(p, d[l]);\n      \
    \              if (check(np)) {\n                        p = np;\n           \
    \             l++;\n                    }\n                }\n               \
    \ return l - sz;\n            }\n            p = np;\n            l++;\n     \
    \   } while ((l & -l) != l);\n        return n;\n    }\n    template<typename\
    \ C>\n    int max_right(const C &check) const {\n        return max_right(0, check);\n\
    \    }\n    template<typename C>\n    int min_left(int r, const C &check) const\
    \ {\n        assert(0 <= r && r <= n);\n        assert(check(M::e()));\n     \
    \   if (r == 0) return r;\n        r += sz;\n        S p = M::e();\n        do\
    \ {\n            r--;\n            while (r > 1 && r & 1) r >>= 1;\n         \
    \   S np = M::op(d[r], p);\n            if (!check(np)) {\n                while\
    \ (r < sz) {\n                    (r <<= 1)++;\n                    np = M::op(d[r],\
    \ p);\n                    if (check(np)) {\n                        p = np;\n\
    \                        r--;\n                    }\n                }\n    \
    \            return r + 1 - sz;\n            }\n            p = np;\n        }\
    \ while ((r & -r) != r);\n        return 0;\n    }\n    template<typename C>\n\
    \    int min_left(const C &check) const {\n        return min_left(n, check);\n\
    \    }\nprivate:\n    int n, log, sz;\n    vector<S> d;\n    void update(int p)\
    \ {\n        d[p] = M::op(d[2 * p], d[2 * p + 1]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/segtree/segtree.hpp
  requiredBy:
  - src/data_structure/segtree/range_tree.hpp
  - src/dp/triangular_transition.hpp
  - src/string/numeric_rolling_hash_dynamic.hpp
  - src/string/rolling_hash_dynamic.hpp
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/monoid/add.test.cpp
  - test/tree/hld.test.cpp
  - test/tree/hld.commutative.test.cpp
  - test/tree/range_contour_aggregator.test.cpp
documentation_of: src/data_structure/segtree/segtree.hpp
layout: document
title: segtree
---

セグ木. 

## Constructor
```
segtree<Monoid> seg(int n)
```
- 長さ $n$ のセグ木を作る
- モノイド定義する必要がある
    - モノイドの内部で型 `S`, 二項演算 `op`, 単位元 `e` を定義する必要がある
- 計算量は $O(n)$

```
segtree<Monoid> seg(vector<S> v)
```
- `v` で初期化セグ木を作る
- 長さで初期化して 1 つずつ `set` するよりも速い
- 計算量は $O(n)$

## set
```
void set(int p, S x)
```
- $p$ 番目の要素を $x$ に変更する
- 計算量は $O(\log n)$

## get
```
S get(int p)
```
- $p$ 番目の要素を返す
- 計算量は $O(1)$

## prod
```
S set(int l, int r)
```
- 開区間 $[l, r)$ に対する総積を計算する
- 計算量は $O(\log n)$

## all_prod
```
S all_prod()
```
- 全体の総積を返す
- 計算量は $O(1)$

## max_right
```
int max_right(int l, const C &check)
```
- 右側へのセグ木上の二分探索を行う
- $\text{check}(\text{prod}(l, r))$ が `true` となる $r$ の最大値が返る
- $\text{check}(e)$ が `true` である必要がある
- 計算量は $O(\log n)$

## min_left
```
int min_left(int r, const C &check)
```
- 左側へのセグ木上の二分探索を行う
- $\text{check}(\text{prod}(l, r))$ が `true` となる $l$ の最小値が返る
- $\text{check}(e)$ が `true` である必要がある
- 計算量は $O(\log n)$