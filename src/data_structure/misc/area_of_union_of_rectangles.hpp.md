---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/data_structure/segtree/lazysegtree.hpp
    title: src/data_structure/segtree/lazysegtree.hpp
  - icon: ':warning:'
    path: src/misc/merge_and_unique.hpp
    title: src/misc/merge_and_unique.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/misc/area_of_union_of_rectangles.hpp\"\
    \n#include <numeric>\n#include <vector>\n#line 2 \"src/misc/merge_and_unique.hpp\"\
    \n#include <algorithm>\n#line 4 \"src/misc/merge_and_unique.hpp\"\nusing namespace\
    \ std;\n\ntemplate<typename T, typename... Ts>\nvector<T> merge_and_unique(const\
    \ vector<T> &a, const Ts &...z) {\n    vector<T> res = a;\n    (res.insert(res.end(),\
    \ z.begin(), z.end()), ...);\n    sort(res.begin(), res.end());\n    res.erase(unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n#line 2 \"src/data_structure/segtree/lazysegtree.hpp\"\
    \n#include <cassert>\n#line 4 \"src/data_structure/segtree/lazysegtree.hpp\"\n\
    using namespace std;\n\ntemplate<typename ActMonoid>\nstruct lazy_segtree {\n\
    \    using M = ActMonoid;\n    using S = typename M::S;\n    using F = typename\
    \ M::F;\n    lazy_segtree() : lazy_segtree(0) {}\n    lazy_segtree(int _n) : lazy_segtree(vector<S>(_n,\
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
    \        for (int i = log; i >= 1; i--) push(p >> i);\n    }\n};\n#line 6 \"src/data_structure/misc/area_of_union_of_rectangles.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T>\nstruct ActMonoid {\n    using\
    \ S = pair<T, T>;\n    static S op(const S &a, const S &b) {\n        if (a.first\
    \ == b.first) {\n            return make_pair(a.first, a.second + b.second);\n\
    \        }\n        return min(a, b);\n    }\n    static constexpr S e() {\n \
    \       return make_pair(numeric_limits<T>::max(), 0);\n    }\n    using F = T;\n\
    \    static F comp(F f, F g) {\n        return f + g;\n    }\n    static F id()\
    \ {\n        return 0;\n    }\n    static S map(F f, S x) {\n        x.first +=\
    \ f;\n        return x;\n    }\n};\n\ntemplate<typename T>\nT area_of_union_of_rectangles(const\
    \ vector<tuple<T, T, T, T>> &rectangles) {\n    int n = rectangles.size();\n \
    \   if (n == 0) return 0;\n    vector<T> xs, ys;\n    xs.reserve(2 * n);\n   \
    \ ys.reserve(2 * n);\n    for (auto [l, d, r, u] : rectangles) {\n        xs.emplace_back(l);\n\
    \        xs.emplace_back(r);\n        ys.emplace_back(d);\n        ys.emplace_back(u);\n\
    \    }\n    xs = merge_and_unique(xs);\n    ys = merge_and_unique(ys);\n    int\
    \ w = xs.size(), h = ys.size();\n    vector<vector<tuple<int, int, int>>> range(w);\n\
    \    for (auto [l, d, r, u] : rectangles) {\n        int il = lower_bound(xs.begin(),\
    \ xs.end(), l) - xs.begin();\n        int ir = lower_bound(xs.begin(), xs.end(),\
    \ r) - xs.begin();\n        int id = lower_bound(ys.begin(), ys.end(), d) - ys.begin();\n\
    \        int iu = lower_bound(ys.begin(), ys.end(), u) - ys.begin();\n       \
    \ range[il].emplace_back(id, iu, 1);\n        range[ir].emplace_back(id, iu, -1);\n\
    \    }\n    lazy_segtree<ActMonoid<T>> seg(h - 1);\n    for (int i = 0; i + 1\
    \ < h; i++) {\n        seg.set(i, make_pair(0, ys[i + 1] - ys[i]));\n    }\n \
    \   T range_y = ys.back() - ys.front();\n    T res = 0;\n    for (int i = 0; i\
    \ + 1 < w; i++) {\n        for (auto [d, u, t] : range[i]) {\n            seg.apply(d,\
    \ u, t);\n        }\n        auto [val, cnt] = seg.all_prod();\n        T x =\
    \ xs[i + 1] - xs[i];\n        T y = range_y - (val == 0 ? cnt : 0);\n        res\
    \ += x * y;\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\n#include \"../../misc/merge_and_unique.hpp\"\
    \n#include \"../segtree/lazysegtree.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ T>\nstruct ActMonoid {\n    using S = pair<T, T>;\n    static S op(const S &a,\
    \ const S &b) {\n        if (a.first == b.first) {\n            return make_pair(a.first,\
    \ a.second + b.second);\n        }\n        return min(a, b);\n    }\n    static\
    \ constexpr S e() {\n        return make_pair(numeric_limits<T>::max(), 0);\n\
    \    }\n    using F = T;\n    static F comp(F f, F g) {\n        return f + g;\n\
    \    }\n    static F id() {\n        return 0;\n    }\n    static S map(F f, S\
    \ x) {\n        x.first += f;\n        return x;\n    }\n};\n\ntemplate<typename\
    \ T>\nT area_of_union_of_rectangles(const vector<tuple<T, T, T, T>> &rectangles)\
    \ {\n    int n = rectangles.size();\n    if (n == 0) return 0;\n    vector<T>\
    \ xs, ys;\n    xs.reserve(2 * n);\n    ys.reserve(2 * n);\n    for (auto [l, d,\
    \ r, u] : rectangles) {\n        xs.emplace_back(l);\n        xs.emplace_back(r);\n\
    \        ys.emplace_back(d);\n        ys.emplace_back(u);\n    }\n    xs = merge_and_unique(xs);\n\
    \    ys = merge_and_unique(ys);\n    int w = xs.size(), h = ys.size();\n    vector<vector<tuple<int,\
    \ int, int>>> range(w);\n    for (auto [l, d, r, u] : rectangles) {\n        int\
    \ il = lower_bound(xs.begin(), xs.end(), l) - xs.begin();\n        int ir = lower_bound(xs.begin(),\
    \ xs.end(), r) - xs.begin();\n        int id = lower_bound(ys.begin(), ys.end(),\
    \ d) - ys.begin();\n        int iu = lower_bound(ys.begin(), ys.end(), u) - ys.begin();\n\
    \        range[il].emplace_back(id, iu, 1);\n        range[ir].emplace_back(id,\
    \ iu, -1);\n    }\n    lazy_segtree<ActMonoid<T>> seg(h - 1);\n    for (int i\
    \ = 0; i + 1 < h; i++) {\n        seg.set(i, make_pair(0, ys[i + 1] - ys[i]));\n\
    \    }\n    T range_y = ys.back() - ys.front();\n    T res = 0;\n    for (int\
    \ i = 0; i + 1 < w; i++) {\n        for (auto [d, u, t] : range[i]) {\n      \
    \      seg.apply(d, u, t);\n        }\n        auto [val, cnt] = seg.all_prod();\n\
    \        T x = xs[i + 1] - xs[i];\n        T y = range_y - (val == 0 ? cnt : 0);\n\
    \        res += x * y;\n    }\n    return res;\n}"
  dependsOn:
  - src/misc/merge_and_unique.hpp
  - src/data_structure/segtree/lazysegtree.hpp
  isVerificationFile: false
  path: src/data_structure/misc/area_of_union_of_rectangles.hpp
  requiredBy: []
  timestamp: '2025-09-04 12:06:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/misc/area_of_union_of_rectangles.hpp
layout: document
redirect_from:
- /library/src/data_structure/misc/area_of_union_of_rectangles.hpp
- /library/src/data_structure/misc/area_of_union_of_rectangles.hpp.html
title: src/data_structure/misc/area_of_union_of_rectangles.hpp
---
