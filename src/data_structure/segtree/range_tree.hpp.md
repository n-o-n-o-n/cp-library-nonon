---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data_structure/segtree/segtree.hpp
    title: src/data_structure/segtree/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/segtree/range_tree.hpp\"\n#include <algorithm>\n\
    #include <vector>\nusing namespace std;\n#line 3 \"src/data_structure/segtree/segtree.hpp\"\
    \n#include <cassert>\nusing namespace std;\n\ntemplate <typename Monoid>\nstruct\
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
    \ * p], d[2 * p + 1]);\n    }\n};\n#line 6 \"src/data_structure/segtree/range_tree.hpp\"\
    \n\ntemplate<typename Monoid, typename T = int>\nstruct range_tree {\n    using\
    \ M = Monoid;\n    using S = typename M::S;\n    range_tree(int _n = 0) : n(-1)\
    \ { pts.reserve(_n); }\n    range_tree(const vector<tuple<T, T, S>> &p) : n(-1),\
    \ pts(p) {}\n    void add_point(T x, T y, const S &w = M::e()) {\n        pts.emplace_back(x,\
    \ y, w);\n    }\n    void set(T x, T y, const S &w) {\n        build();\n    \
    \    int i = lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n        assert(xs[i]\
    \ == x);\n        i += sz;\n        int j = lower_bound(ys[i].begin(), ys[i].end(),\
    \ y) - ys[i].begin();\n        segs[i].set(j, w);\n        while (i >>= 1) {\n\
    \            int j = lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();\n\
    \            segs[i].set(j, M::op(get_val(2 * i, y), get_val(2 * i + 1, y)));\n\
    \        }\n    }\n    S get(T x, T y) {\n        build();\n        int i = lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n        if (i >= (int)xs.size() || xs[i] != x) return\
    \ M::e();\n        i += sz;\n        int j = lower_bound(ys[i].begin(), ys[i].end(),\
    \ y) - ys[i].begin();\n        if (j >= (int)ys[i].size() || ys[i][j] != y) return\
    \ M::e();\n        return segs[i].get(j);\n    }\n    S prod(T xl, T yl, T xr,\
    \ T yr) {\n        build();\n        int il = lower_bound(xs.begin(), xs.end(),\
    \ xl) - xs.begin();\n        int ir = lower_bound(xs.begin(), xs.end(), xr) -\
    \ xs.begin();\n        il += sz;\n        ir += sz;\n        S p = M::e();\n \
    \       while (il < ir) {\n            if (il & 1) p = M::op(p, inner_prod(il++,\
    \ yl, yr));\n            if (ir & 1) p = M::op(p, inner_prod(--ir, yl, yr));\n\
    \            il >>= 1;\n            ir >>= 1;\n        }\n        return p;\n\
    \    }\nprivate:\n    int n, sz;\n    vector<tuple<T, T, S>> pts;\n    vector<T>\
    \ xs;\n    vector<vector<T>> ys;\n    vector<vector<pair<T, S>>> ws;\n    vector<segtree<M>>\
    \ segs;\n    S get_val(int i, T y) {\n        int j = lower_bound(ys[i].begin(),\
    \ ys[i].end(), y) - ys[i].begin();\n        return j < (int)ys[i].size() && ys[i][j]\
    \ == y ? segs[i].get(j) : M::e();\n    }\n    S inner_prod(int i, T yl, T yr)\
    \ {\n        int jl = lower_bound(ys[i].begin(), ys[i].end(), yl) - ys[i].begin();\n\
    \        int jr = lower_bound(ys[i].begin(), ys[i].end(), yr) - ys[i].begin();\n\
    \        return segs[i].prod(jl, jr);\n    }\n    void build() {\n        if (n\
    \ != -1) return;\n        for (const auto &[x, y, w] : pts) {\n            xs.emplace_back(x);\n\
    \        }\n        sort(xs.begin(), xs.end());\n        xs.erase(unique(xs.begin(),\
    \ xs.end()), xs.end());\n        n = xs.size();\n        sz = 1;\n        while\
    \ (sz < n) sz <<= 1;\n        ys = vector<vector<T>>(2 * sz);\n        ws = vector<vector<pair<T,\
    \ S>>>(2 * sz);\n        segs = vector<segtree<M>>(2 * sz);\n        for (const\
    \ auto &[x, y, w] : pts) {\n            int p = lower_bound(xs.begin(), xs.end(),\
    \ x) - xs.begin();\n            p += sz;\n            ys[p].emplace_back(y);\n\
    \            ws[p].emplace_back(y, w);\n        }\n        for (int i = sz; i\
    \ < sz + n; i++) {\n            sort(ys[i].begin(), ys[i].end());\n          \
    \  ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());\n           \
    \ vector<S> v(ys[i].size(), M::e());\n            for (const auto &[y, w] : ws[i])\
    \ {\n                int j = lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();\n\
    \                v[j] = M::op(v[j], w);\n                ws[i >> 1].emplace_back(y,\
    \ w);\n            }\n            segs[i] = segtree<M>(v);\n        }\n      \
    \  for (int i = sz - 1; i >= 1; i--) {\n            const auto &yl = ys[2 * i];\n\
    \            const auto &yr = ys[2 * i + 1];\n            merge(yl.begin(), yl.end(),\
    \ yr.begin(), yr.end(), back_inserter(ys[i]));\n            ys[i].erase(unique(ys[i].begin(),\
    \ ys[i].end()), ys[i].end());\n            vector<S> v(ys[i].size(), M::e());\n\
    \            for (const auto &[y, w] : ws[i]) {\n                int j = lower_bound(ys[i].begin(),\
    \ ys[i].end(), y) - ys[i].begin();\n                v[j] = M::op(v[j], w);\n \
    \               ws[i >> 1].emplace_back(y, w);\n            }\n            segs[i]\
    \ = segtree<M>(v);\n        }\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\nusing namespace std;\n\
    #include \"segtree.hpp\"\n\ntemplate<typename Monoid, typename T = int>\nstruct\
    \ range_tree {\n    using M = Monoid;\n    using S = typename M::S;\n    range_tree(int\
    \ _n = 0) : n(-1) { pts.reserve(_n); }\n    range_tree(const vector<tuple<T, T,\
    \ S>> &p) : n(-1), pts(p) {}\n    void add_point(T x, T y, const S &w = M::e())\
    \ {\n        pts.emplace_back(x, y, w);\n    }\n    void set(T x, T y, const S\
    \ &w) {\n        build();\n        int i = lower_bound(xs.begin(), xs.end(), x)\
    \ - xs.begin();\n        assert(xs[i] == x);\n        i += sz;\n        int j\
    \ = lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();\n        segs[i].set(j,\
    \ w);\n        while (i >>= 1) {\n            int j = lower_bound(ys[i].begin(),\
    \ ys[i].end(), y) - ys[i].begin();\n            segs[i].set(j, M::op(get_val(2\
    \ * i, y), get_val(2 * i + 1, y)));\n        }\n    }\n    S get(T x, T y) {\n\
    \        build();\n        int i = lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n\
    \        if (i >= (int)xs.size() || xs[i] != x) return M::e();\n        i += sz;\n\
    \        int j = lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();\n\
    \        if (j >= (int)ys[i].size() || ys[i][j] != y) return M::e();\n       \
    \ return segs[i].get(j);\n    }\n    S prod(T xl, T yl, T xr, T yr) {\n      \
    \  build();\n        int il = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();\n\
    \        int ir = lower_bound(xs.begin(), xs.end(), xr) - xs.begin();\n      \
    \  il += sz;\n        ir += sz;\n        S p = M::e();\n        while (il < ir)\
    \ {\n            if (il & 1) p = M::op(p, inner_prod(il++, yl, yr));\n       \
    \     if (ir & 1) p = M::op(p, inner_prod(--ir, yl, yr));\n            il >>=\
    \ 1;\n            ir >>= 1;\n        }\n        return p;\n    }\nprivate:\n \
    \   int n, sz;\n    vector<tuple<T, T, S>> pts;\n    vector<T> xs;\n    vector<vector<T>>\
    \ ys;\n    vector<vector<pair<T, S>>> ws;\n    vector<segtree<M>> segs;\n    S\
    \ get_val(int i, T y) {\n        int j = lower_bound(ys[i].begin(), ys[i].end(),\
    \ y) - ys[i].begin();\n        return j < (int)ys[i].size() && ys[i][j] == y ?\
    \ segs[i].get(j) : M::e();\n    }\n    S inner_prod(int i, T yl, T yr) {\n   \
    \     int jl = lower_bound(ys[i].begin(), ys[i].end(), yl) - ys[i].begin();\n\
    \        int jr = lower_bound(ys[i].begin(), ys[i].end(), yr) - ys[i].begin();\n\
    \        return segs[i].prod(jl, jr);\n    }\n    void build() {\n        if (n\
    \ != -1) return;\n        for (const auto &[x, y, w] : pts) {\n            xs.emplace_back(x);\n\
    \        }\n        sort(xs.begin(), xs.end());\n        xs.erase(unique(xs.begin(),\
    \ xs.end()), xs.end());\n        n = xs.size();\n        sz = 1;\n        while\
    \ (sz < n) sz <<= 1;\n        ys = vector<vector<T>>(2 * sz);\n        ws = vector<vector<pair<T,\
    \ S>>>(2 * sz);\n        segs = vector<segtree<M>>(2 * sz);\n        for (const\
    \ auto &[x, y, w] : pts) {\n            int p = lower_bound(xs.begin(), xs.end(),\
    \ x) - xs.begin();\n            p += sz;\n            ys[p].emplace_back(y);\n\
    \            ws[p].emplace_back(y, w);\n        }\n        for (int i = sz; i\
    \ < sz + n; i++) {\n            sort(ys[i].begin(), ys[i].end());\n          \
    \  ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());\n           \
    \ vector<S> v(ys[i].size(), M::e());\n            for (const auto &[y, w] : ws[i])\
    \ {\n                int j = lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();\n\
    \                v[j] = M::op(v[j], w);\n                ws[i >> 1].emplace_back(y,\
    \ w);\n            }\n            segs[i] = segtree<M>(v);\n        }\n      \
    \  for (int i = sz - 1; i >= 1; i--) {\n            const auto &yl = ys[2 * i];\n\
    \            const auto &yr = ys[2 * i + 1];\n            merge(yl.begin(), yl.end(),\
    \ yr.begin(), yr.end(), back_inserter(ys[i]));\n            ys[i].erase(unique(ys[i].begin(),\
    \ ys[i].end()), ys[i].end());\n            vector<S> v(ys[i].size(), M::e());\n\
    \            for (const auto &[y, w] : ws[i]) {\n                int j = lower_bound(ys[i].begin(),\
    \ ys[i].end(), y) - ys[i].begin();\n                v[j] = M::op(v[j], w);\n \
    \               ws[i >> 1].emplace_back(y, w);\n            }\n            segs[i]\
    \ = segtree<M>(v);\n        }\n    }\n};"
  dependsOn:
  - src/data_structure/segtree/segtree.hpp
  isVerificationFile: false
  path: src/data_structure/segtree/range_tree.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/segtree/range_tree.hpp
layout: document
redirect_from:
- /library/src/data_structure/segtree/range_tree.hpp
- /library/src/data_structure/segtree/range_tree.hpp.html
title: src/data_structure/segtree/range_tree.hpp
---
