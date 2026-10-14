---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/data_structure/segtree/fenwick_tree_abelian_group.hpp
    title: src/data_structure/segtree/fenwick_tree_abelian_group.hpp
  - icon: ':warning:'
    path: src/misc/merge_and_unique.hpp
    title: src/misc/merge_and_unique.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/data_structure/misc/dynamic_point_add_rectangle_sum.hpp
    title: src/data_structure/misc/dynamic_point_add_rectangle_sum.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/misc/static_point_add_rectangle_sum.hpp\"\
    \n#include <cassert>\n#include <numeric>\n#include <ranges>\n#include <vector>\n\
    #line 2 \"src/misc/merge_and_unique.hpp\"\n#include <algorithm>\n#line 4 \"src/misc/merge_and_unique.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T, typename... Ts>\nvector<T> merge_and_unique(const\
    \ vector<T> &a, const Ts &...z) {\n    vector<T> res = a;\n    (res.insert(res.end(),\
    \ z.begin(), z.end()), ...);\n    sort(res.begin(), res.end());\n    res.erase(unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n#line 4 \"src/data_structure/segtree/fenwick_tree_abelian_group.hpp\"\
    \nusing namespace std;\n\ntemplate<typename Abelian_Group>\nstruct fenwick_tree\
    \ {\n    using M = Abelian_Group;\n    using S = typename M::S;\n    fenwick_tree()\
    \ = default;\n    fenwick_tree(int _n) : fenwick_tree(vector<S>(_n, M::e())) {}\n\
    \    fenwick_tree(const vector<S> &_v) : n(_v.size()) {\n        d = vector<S>(n,\
    \ M::e());\n        v = vector<S>(n, M::e());\n        for (int i = 1; i <= n;\
    \ i++) {\n            v[i - 1] = _v[i - 1];\n            d[i - 1] += v[i - 1];\n\
    \            int j = i + (i & -i);\n            if (j <= n) d[j - 1] += d[i -\
    \ 1];\n        }\n    }\n    void add(int p, S x) {\n        assert(0 <= p &&\
    \ p < n);\n        v[p] = M::op(v[p], x);\n        for (p++; p <= n; p += p &\
    \ -p) {\n            d[p - 1] = M::op(d[p - 1], x);\n        }\n    }\n    void\
    \ set(int p, S x) {\n        assert(0 <= p && p < n);\n        add(p, M::op(x,\
    \ M::inv(v[p])));\n    }\n    S prod(int l, int r) const {\n        assert(0 <=\
    \ l && l <= r && r <= n);\n        return prod(r) - prod(l);\n    }\nprivate:\n\
    \    int n;\n    vector<S> d, v;\n    S prod(int p) const {\n        S res = M::e();\n\
    \        for (; p > 0; p -= p & -p) {\n            res = M::op(res, d[p - 1]);\n\
    \        }\n        return res;\n    }\n};\n#line 8 \"src/data_structure/misc/static_point_add_rectangle_sum.hpp\"\
    \nusing namespace std;\n\ntemplate<typename Abelian_Group, typename T = int>\n\
    struct static_point_add_rectangle_sum {\n    using M = Abelian_Group;\n    using\
    \ S = typename M::S;\n    static_point_add_rectangle_sum() = default;\n    static_point_add_rectangle_sum(int\
    \ n, int q) {\n        xs.reserve(n);\n        ys.reserve(n);\n        ws.reserve(n);\n\
    \        xls.reserve(q);\n        yls.reserve(q);\n        xrs.reserve(q);\n \
    \       yrs.reserve(q);\n    }\n    void add_point(T x, T y, S w) {\n        xs.emplace_back(x);\n\
    \        ys.emplace_back(y);\n        ws.emplace_back(w);\n    }\n    void add_query(T\
    \ xl, T yl, T xr, T yr) {\n        xls.emplace_back(xl);\n        yls.emplace_back(yl);\n\
    \        xrs.emplace_back(xr);\n        yrs.emplace_back(yr);\n    }\n    vector<S>\
    \ solve() {\n        int n = xs.size(), q = xls.size();\n        if (n == 0 ||\
    \ q == 0) return vector<S>(q, M::e());\n        auto yb = merge_and_unique(ys);\n\
    \        for (T &y : ys) {\n            y = lower_bound(yb.begin(), yb.end(),\
    \ y) - yb.begin();\n        }\n        vector<int> ord_pts(n), ord_query(2 * q);\n\
    \        iota(ord_pts.begin(), ord_pts.end(), 0);\n        iota(ord_query.begin(),\
    \ ord_query.end(), 0);\n        ranges::sort(ord_pts, {}, [&](int i) { return\
    \ xs[i]; });\n        ranges::sort(ord_query, {}, [&](int i) { return i < q ?\
    \ xls[i] : xrs[i - q]; });\n        fenwick_tree<M> fw(yb.size());\n        vector<S>\
    \ res(q);\n        int j = 0;\n        for (int i : ord_query) {\n           \
    \ T x = (i < q ? xls[i] : xrs[i - q]);\n            while (j < n && xs[ord_pts[j]]\
    \ < x) {\n                fw.add(ys[ord_pts[j]], ws[ord_pts[j]]);\n          \
    \      j++;\n            }\n            if (i < q) {\n                int yl =\
    \ lower_bound(yb.begin(), yb.end(), yls[i]) - yb.begin();\n                int\
    \ yr = lower_bound(yb.begin(), yb.end(), yrs[i]) - yb.begin();\n             \
    \   res[i] = M::op(res[i], M::inv(fw.prod(yl, yr)));\n            } else {\n \
    \               i -= q;\n                int yl = lower_bound(yb.begin(), yb.end(),\
    \ yls[i]) - yb.begin();\n                int yr = lower_bound(yb.begin(), yb.end(),\
    \ yrs[i]) - yb.begin();\n                res[i] = M::op(res[i], fw.prod(yl, yr));\n\
    \            }\n        }\n        return res;\n    }\nprivate:\n    vector<T>\
    \ xs, ys, xls, yls, xrs, yrs;\n    vector<S> ws;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <numeric>\n#include <ranges>\n\
    #include <vector>\n#include \"../../misc/merge_and_unique.hpp\"\n#include \"../segtree/fenwick_tree_abelian_group.hpp\"\
    \nusing namespace std;\n\ntemplate<typename Abelian_Group, typename T = int>\n\
    struct static_point_add_rectangle_sum {\n    using M = Abelian_Group;\n    using\
    \ S = typename M::S;\n    static_point_add_rectangle_sum() = default;\n    static_point_add_rectangle_sum(int\
    \ n, int q) {\n        xs.reserve(n);\n        ys.reserve(n);\n        ws.reserve(n);\n\
    \        xls.reserve(q);\n        yls.reserve(q);\n        xrs.reserve(q);\n \
    \       yrs.reserve(q);\n    }\n    void add_point(T x, T y, S w) {\n        xs.emplace_back(x);\n\
    \        ys.emplace_back(y);\n        ws.emplace_back(w);\n    }\n    void add_query(T\
    \ xl, T yl, T xr, T yr) {\n        xls.emplace_back(xl);\n        yls.emplace_back(yl);\n\
    \        xrs.emplace_back(xr);\n        yrs.emplace_back(yr);\n    }\n    vector<S>\
    \ solve() {\n        int n = xs.size(), q = xls.size();\n        if (n == 0 ||\
    \ q == 0) return vector<S>(q, M::e());\n        auto yb = merge_and_unique(ys);\n\
    \        for (T &y : ys) {\n            y = lower_bound(yb.begin(), yb.end(),\
    \ y) - yb.begin();\n        }\n        vector<int> ord_pts(n), ord_query(2 * q);\n\
    \        iota(ord_pts.begin(), ord_pts.end(), 0);\n        iota(ord_query.begin(),\
    \ ord_query.end(), 0);\n        ranges::sort(ord_pts, {}, [&](int i) { return\
    \ xs[i]; });\n        ranges::sort(ord_query, {}, [&](int i) { return i < q ?\
    \ xls[i] : xrs[i - q]; });\n        fenwick_tree<M> fw(yb.size());\n        vector<S>\
    \ res(q);\n        int j = 0;\n        for (int i : ord_query) {\n           \
    \ T x = (i < q ? xls[i] : xrs[i - q]);\n            while (j < n && xs[ord_pts[j]]\
    \ < x) {\n                fw.add(ys[ord_pts[j]], ws[ord_pts[j]]);\n          \
    \      j++;\n            }\n            if (i < q) {\n                int yl =\
    \ lower_bound(yb.begin(), yb.end(), yls[i]) - yb.begin();\n                int\
    \ yr = lower_bound(yb.begin(), yb.end(), yrs[i]) - yb.begin();\n             \
    \   res[i] = M::op(res[i], M::inv(fw.prod(yl, yr)));\n            } else {\n \
    \               i -= q;\n                int yl = lower_bound(yb.begin(), yb.end(),\
    \ yls[i]) - yb.begin();\n                int yr = lower_bound(yb.begin(), yb.end(),\
    \ yrs[i]) - yb.begin();\n                res[i] = M::op(res[i], fw.prod(yl, yr));\n\
    \            }\n        }\n        return res;\n    }\nprivate:\n    vector<T>\
    \ xs, ys, xls, yls, xrs, yrs;\n    vector<S> ws;\n};"
  dependsOn:
  - src/misc/merge_and_unique.hpp
  - src/data_structure/segtree/fenwick_tree_abelian_group.hpp
  isVerificationFile: false
  path: src/data_structure/misc/static_point_add_rectangle_sum.hpp
  requiredBy:
  - src/data_structure/misc/dynamic_point_add_rectangle_sum.hpp
  timestamp: '2025-09-03 07:13:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/misc/static_point_add_rectangle_sum.hpp
layout: document
redirect_from:
- /library/src/data_structure/misc/static_point_add_rectangle_sum.hpp
- /library/src/data_structure/misc/static_point_add_rectangle_sum.hpp.html
title: src/data_structure/misc/static_point_add_rectangle_sum.hpp
---
