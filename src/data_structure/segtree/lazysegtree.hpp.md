---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/data_structure/misc/area_of_union_of_rectangles.hpp
    title: src/data_structure/misc/area_of_union_of_rectangles.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/segtree/lazysegtree.hpp\"\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n\ntemplate<typename ActMonoid>\nstruct\
    \ lazy_segtree {\n    using M = ActMonoid;\n    using S = typename M::S;\n   \
    \ using F = typename M::F;\n    lazy_segtree() : lazy_segtree(0) {}\n    lazy_segtree(int\
    \ _n) : lazy_segtree(vector<S>(_n, M::e())) {}\n    lazy_segtree(const vector<S>\
    \ &v) { init(v); }\n    void set(const vector<S> &v) { init(v); }\n    void set(int\
    \ p, const S &x) {\n        assert(0 <= p && p < n);\n        p += sz;\n     \
    \   inner_push(p);\n        d[p] = x;\n        inner_update(p);\n    }\n    void\
    \ apply(int p, const F &f) {\n        assert(0 <= p && p < n);\n        p += sz;\n\
    \        inner_push(p);\n        d[p] = M::map(f, d[p]);\n        inner_update(p);\n\
    \    }\n    void apply(int l, int r, const F &f) {\n        assert(0 <= l && l\
    \ <=r && r <= n);\n        l += sz;\n        r += sz;\n        for (int i = log;\
    \ i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n      \
    \      if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n        int l2\
    \ = l, r2 = r;\n        while (l < r) {\n            if (l & 1) all_apply(l++,\
    \ f);\n            if (r & 1) all_apply(--r, f);\n            l >>= 1;\n     \
    \       r >>= 1;\n        }\n        l = l2, r = r2;\n        for (int i = 1;\
    \ i <= log; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n  \
    \          if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\
    \    S get(int p) {\n        assert(0 <= p && p < n);\n        p += sz;\n    \
    \    inner_push(p);\n        return d[p];\n    }\n    S prod(int l, int r) {\n\
    \        assert(0 <= l && l <=r && r <= n);\n        l += sz;\n        r += sz;\n\
    \        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
    \ l) push(l >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \        }\n        S pl = M::e(), pr = M::e();\n        while (l < r) {\n   \
    \         if (l & 1) pl = M::op(pl, d[l++]);\n            if (r & 1) pr = M::op(d[--r],\
    \ pr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ M::op(pl, pr);\n    }\n    S all_prod() const { return d[1]; }\n    template<typename\
    \ C>\n    int max_right(int l, const C &check) {\n        assert(0 <= l && l <=\
    \ n);\n        assert(check(M::e()));\n        if (l == n) return l;\n       \
    \ l += sz;\n        inner_push(l);\n        S p = M::e();\n        do {\n    \
    \        while (!(l & 1)) l >>= 1;\n            S np = M::op(p, d[l]);\n     \
    \       if (!check(np)) {\n                while (l < sz) {\n                \
    \    push(l);\n                    l <<= 1;\n                    np = M::op(p,\
    \ d[l]);\n                    if (check(np)) {\n                        p = np;\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - sz;\n            }\n            p = np;\n            l++;\n\
    \        } while ((l & -l) != l);\n        return n;\n    }\n    template<typename\
    \ C>\n    int max_right(const C &check) {\n        return max_right(0, check);\n\
    \    }\n    template<typename C>\n    int min_left(int r, const C &check) {\n\
    \        assert(0 <= r && r <= n);\n        assert(check(M::e()));\n        if\
    \ (r == 0) return 0;\n        r += sz;\n        inner_push(r - 1);\n        S\
    \ p = M::e();\n        do {\n            r--;\n            while (r > 1 && r &\
    \ 1) r >>= 1;\n            S np = M::op(d[r], p);\n            if (!check(np))\
    \ {\n                while (r < sz) {\n                    push(r);\n        \
    \            (r <<= 1)++;\n                    np = M::op(d[r], p);\n        \
    \            if (check(np)) {\n                        p = np;\n             \
    \           r--;\n                    }\n                }\n                return\
    \ r + 1 - sz;\n            }\n            p = np;\n        } while ((r & -r) !=\
    \ r);\n        return 0;\n    }\n    template<typename C>\n    int min_left(const\
    \ C &check) {\n        return min_left(n, check);\n    }\nprivate:\n    int n,\
    \ log, sz;\n    vector<S> d;\n    vector<F> lz;\n    void init(const vector<S>\
    \ &v) {\n        n = v.size();\n        log = 1;\n        while ((1 << log) <\
    \ n) log++;\n        sz = 1 << log;\n        d = vector<S>(2 * sz, M::e());\n\
    \        lz = vector<F>(sz, M::id());\n        for (int i = 0; i < n; i++) d[i\
    \ + sz] = v[i];\n        for (int i = sz - 1; i >= 1; i--) update(i);\n    }\n\
    \    void update(int p) {\n        d[p] = M::op(d[2 * p], d[2 * p + 1]);\n   \
    \ }\n    void all_apply(int p, const F &f) {\n        d[p] = M::map(f, d[p]);\n\
    \        if (p < sz) lz[p] = M::comp(f, lz[p]);\n    }\n    void push(int p) {\n\
    \        all_apply(2 * p, lz[p]);\n        all_apply(2 * p + 1, lz[p]);\n    \
    \    lz[p] = M::id();\n    }\n    void inner_update(int p) {\n        for (int\
    \ i = 1; i <= log; i++) update(p >> i);\n    }\n    void inner_push(int p) {\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename ActMonoid>\nstruct lazy_segtree {\n    using M = ActMonoid;\n\
    \    using S = typename M::S;\n    using F = typename M::F;\n    lazy_segtree()\
    \ : lazy_segtree(0) {}\n    lazy_segtree(int _n) : lazy_segtree(vector<S>(_n,\
    \ M::e())) {}\n    lazy_segtree(const vector<S> &v) { init(v); }\n    void set(const\
    \ vector<S> &v) { init(v); }\n    void set(int p, const S &x) {\n        assert(0\
    \ <= p && p < n);\n        p += sz;\n        inner_push(p);\n        d[p] = x;\n\
    \        inner_update(p);\n    }\n    void apply(int p, const F &f) {\n      \
    \  assert(0 <= p && p < n);\n        p += sz;\n        inner_push(p);\n      \
    \  d[p] = M::map(f, d[p]);\n        inner_update(p);\n    }\n    void apply(int\
    \ l, int r, const F &f) {\n        assert(0 <= l && l <=r && r <= n);\n      \
    \  l += sz;\n        r += sz;\n        for (int i = log; i >= 1; i--) {\n    \
    \        if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) <<\
    \ i) != r) push((r - 1) >> i);\n        }\n        int l2 = l, r2 = r;\n     \
    \   while (l < r) {\n            if (l & 1) all_apply(l++, f);\n            if\
    \ (r & 1) all_apply(--r, f);\n            l >>= 1;\n            r >>= 1;\n   \
    \     }\n        l = l2, r = r2;\n        for (int i = 1; i <= log; i++) {\n \
    \           if (((l >> i) << i) != l) update(l >> i);\n            if (((r >>\
    \ i) << i) != r) update((r - 1) >> i);\n        }\n    }\n    S get(int p) {\n\
    \        assert(0 <= p && p < n);\n        p += sz;\n        inner_push(p);\n\
    \        return d[p];\n    }\n    S prod(int l, int r) {\n        assert(0 <=\
    \ l && l <=r && r <= n);\n        l += sz;\n        r += sz;\n        for (int\
    \ i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n      \
    \  S pl = M::e(), pr = M::e();\n        while (l < r) {\n            if (l & 1)\
    \ pl = M::op(pl, d[l++]);\n            if (r & 1) pr = M::op(d[--r], pr);\n  \
    \          l >>= 1;\n            r >>= 1;\n        }\n        return M::op(pl,\
    \ pr);\n    }\n    S all_prod() const { return d[1]; }\n    template<typename\
    \ C>\n    int max_right(int l, const C &check) {\n        assert(0 <= l && l <=\
    \ n);\n        assert(check(M::e()));\n        if (l == n) return l;\n       \
    \ l += sz;\n        inner_push(l);\n        S p = M::e();\n        do {\n    \
    \        while (!(l & 1)) l >>= 1;\n            S np = M::op(p, d[l]);\n     \
    \       if (!check(np)) {\n                while (l < sz) {\n                \
    \    push(l);\n                    l <<= 1;\n                    np = M::op(p,\
    \ d[l]);\n                    if (check(np)) {\n                        p = np;\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - sz;\n            }\n            p = np;\n            l++;\n\
    \        } while ((l & -l) != l);\n        return n;\n    }\n    template<typename\
    \ C>\n    int max_right(const C &check) {\n        return max_right(0, check);\n\
    \    }\n    template<typename C>\n    int min_left(int r, const C &check) {\n\
    \        assert(0 <= r && r <= n);\n        assert(check(M::e()));\n        if\
    \ (r == 0) return 0;\n        r += sz;\n        inner_push(r - 1);\n        S\
    \ p = M::e();\n        do {\n            r--;\n            while (r > 1 && r &\
    \ 1) r >>= 1;\n            S np = M::op(d[r], p);\n            if (!check(np))\
    \ {\n                while (r < sz) {\n                    push(r);\n        \
    \            (r <<= 1)++;\n                    np = M::op(d[r], p);\n        \
    \            if (check(np)) {\n                        p = np;\n             \
    \           r--;\n                    }\n                }\n                return\
    \ r + 1 - sz;\n            }\n            p = np;\n        } while ((r & -r) !=\
    \ r);\n        return 0;\n    }\n    template<typename C>\n    int min_left(const\
    \ C &check) {\n        return min_left(n, check);\n    }\nprivate:\n    int n,\
    \ log, sz;\n    vector<S> d;\n    vector<F> lz;\n    void init(const vector<S>\
    \ &v) {\n        n = v.size();\n        log = 1;\n        while ((1 << log) <\
    \ n) log++;\n        sz = 1 << log;\n        d = vector<S>(2 * sz, M::e());\n\
    \        lz = vector<F>(sz, M::id());\n        for (int i = 0; i < n; i++) d[i\
    \ + sz] = v[i];\n        for (int i = sz - 1; i >= 1; i--) update(i);\n    }\n\
    \    void update(int p) {\n        d[p] = M::op(d[2 * p], d[2 * p + 1]);\n   \
    \ }\n    void all_apply(int p, const F &f) {\n        d[p] = M::map(f, d[p]);\n\
    \        if (p < sz) lz[p] = M::comp(f, lz[p]);\n    }\n    void push(int p) {\n\
    \        all_apply(2 * p, lz[p]);\n        all_apply(2 * p + 1, lz[p]);\n    \
    \    lz[p] = M::id();\n    }\n    void inner_update(int p) {\n        for (int\
    \ i = 1; i <= log; i++) update(p >> i);\n    }\n    void inner_push(int p) {\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/segtree/lazysegtree.hpp
  requiredBy:
  - src/data_structure/misc/area_of_union_of_rectangles.hpp
  timestamp: '2025-09-04 12:06:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/segtree/lazysegtree.hpp
layout: document
redirect_from:
- /library/src/data_structure/segtree/lazysegtree.hpp
- /library/src/data_structure/segtree/lazysegtree.hpp.html
title: src/data_structure/segtree/lazysegtree.hpp
---
