---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/data_structure/segtree/fenwick_tree_abelian_group.hpp
    title: src/data_structure/segtree/fenwick_tree_abelian_group.hpp
  - icon: ':warning:'
    path: src/data_structure/segtree/range_add_fenwick_tree_abelian_group.hpp
    title: src/data_structure/segtree/range_add_fenwick_tree_abelian_group.hpp
  - icon: ':warning:'
    path: src/misc/merge_and_unique.hpp
    title: src/misc/merge_and_unique.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/data_structure/misc/dynamic_rectangle_add_point_get.hpp
    title: src/data_structure/misc/dynamic_rectangle_add_point_get.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/misc/static_rectangle_add_point_get.hpp\"\
    \n#include <numeric>\n#include <ranges>\n#include <vector>\n#line 2 \"src/misc/merge_and_unique.hpp\"\
    \n#include <algorithm>\n#line 4 \"src/misc/merge_and_unique.hpp\"\nusing namespace\
    \ std;\n\ntemplate<typename T, typename... Ts>\nvector<T> merge_and_unique(const\
    \ vector<T> &a, const Ts &...z) {\n    vector<T> res = a;\n    (res.insert(res.end(),\
    \ z.begin(), z.end()), ...);\n    sort(res.begin(), res.end());\n    res.erase(unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n#line 2 \"src/data_structure/segtree/fenwick_tree_abelian_group.hpp\"\
    \n#include <cassert>\n#line 4 \"src/data_structure/segtree/fenwick_tree_abelian_group.hpp\"\
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
    \        }\n        return res;\n    }\n};\n#line 3 \"src/data_structure/segtree/range_add_fenwick_tree_abelian_group.hpp\"\
    \n\ntemplate<typename Abelian_Group>\nstruct range_add_fenwick_tree {\n    using\
    \ M = Abelian_Group;\n    using S = typename M::S;\n    range_add_fenwick_tree()\
    \ = default;\n    range_add_fenwick_tree(int n) : fw1(n + 1), fw2(n + 1) {}\n\
    \    void add(int p, const S &x) {\n        add(p, p + 1, x);\n    }\n    void\
    \ add(int l, int r, const S &x) {\n        fw1.add(l, M::inv(M::pow(x, l)));\n\
    \        fw1.add(r, M::pow(x, r));\n        fw2.add(l, x);\n        fw2.add(r,\
    \ M::inv(x));\n    }\n    S prod(int l, int r) const {\n        return M::op(prod(r),\
    \ M::inv(prod(l)));\n    }\nprivate:\n    fenwick_tree<Abelian_Group> fw1, fw2;\n\
    \    S prod(int p) const {\n        S res1 = fw1.prod(0, p);\n        S res2 =\
    \ fw2.prod(0, p);\n        return M::op(res1, M::pow(res2, p));\n    }\n};\n#line\
    \ 7 \"src/data_structure/misc/static_rectangle_add_point_get.hpp\"\nusing namespace\
    \ std;\n\ntemplate<typename Abelian_Group, typename T = int>\nstruct static_rectangle_add_point_get\
    \ {\n    using M = Abelian_Group;\n    using S = typename M::S;\n    static_rectangle_add_point_get()\
    \ = default;\n    static_rectangle_add_point_get(int n, int q) {\n        xls.reserve(n);\n\
    \        yls.reserve(n);\n        xrs.reserve(n);\n        yrs.reserve(n);\n \
    \       ws.reserve(n);\n        xs.reserve(q);\n        ys.reserve(q);\n    }\n\
    \    void add_rectangle(T xl, T yl, T xr, T yr, const S &w) {\n        xls.emplace_back(xl);\n\
    \        yls.emplace_back(yl);\n        xrs.emplace_back(xr);\n        yrs.emplace_back(yr);\n\
    \        ws.emplace_back(w);\n    }\n    void add_query(T x, T y) {\n        xs.emplace_back(x);\n\
    \        ys.emplace_back(y);\n    }\n    vector<S> solve() {\n        int n =\
    \ xls.size(), q = xs.size();\n        auto yb = merge_and_unique(ys);\n      \
    \  vector<tuple<int, int, T, S>> rs;\n        rs.reserve(2 * n);\n        for\
    \ (int i = 0; i < n; i++) {\n            int l = lower_bound(yb.begin(), yb.end(),\
    \ yls[i]) - yb.begin();\n            int r = lower_bound(yb.begin(), yb.end(),\
    \ yrs[i]) - yb.begin();\n            rs.emplace_back(l, r, xls[i], ws[i]);\n \
    \           rs.emplace_back(l, r, xrs[i], M::inv(ws[i]));\n        }\n       \
    \ sort(rs.begin(), rs.end(), [&] (auto a, auto b) {\n            return get<2>(a)\
    \ < get<2>(b);\n        });\n        vector<int> ord(q);\n        iota(ord.begin(),\
    \ ord.end(), 0);\n        sort(ord.begin(), ord.end(), [&] (int i, int j) {\n\
    \            return xs[i] < xs[j];\n        });\n        range_add_fenwick_tree<Abelian_Group>\
    \ fw(yb.size());\n        vector<S> res(q);\n        int j = 0;\n        for (int\
    \ i : ord) {\n            while (j < 2 * n && get<2>(rs[j]) <= xs[i]) {\n    \
    \            auto [l, r, _, w] = rs[j++];\n                fw.add(l, r, w);\n\
    \            }\n            int y = lower_bound(yb.begin(), yb.end(), ys[i]) -\
    \ yb.begin();\n            res[i] = fw.prod(y, y + 1);\n        }\n        return\
    \ res;\n    }\nprivate:\n    vector<T> xls, yls, xrs, yrs, xs, ys;\n    vector<S>\
    \ ws;\n};\n"
  code: "#pragma once\n#include <numeric>\n#include <ranges>\n#include <vector>\n\
    #include \"../../misc/merge_and_unique.hpp\"\n#include \"../segtree/range_add_fenwick_tree_abelian_group.hpp\"\
    \nusing namespace std;\n\ntemplate<typename Abelian_Group, typename T = int>\n\
    struct static_rectangle_add_point_get {\n    using M = Abelian_Group;\n    using\
    \ S = typename M::S;\n    static_rectangle_add_point_get() = default;\n    static_rectangle_add_point_get(int\
    \ n, int q) {\n        xls.reserve(n);\n        yls.reserve(n);\n        xrs.reserve(n);\n\
    \        yrs.reserve(n);\n        ws.reserve(n);\n        xs.reserve(q);\n   \
    \     ys.reserve(q);\n    }\n    void add_rectangle(T xl, T yl, T xr, T yr, const\
    \ S &w) {\n        xls.emplace_back(xl);\n        yls.emplace_back(yl);\n    \
    \    xrs.emplace_back(xr);\n        yrs.emplace_back(yr);\n        ws.emplace_back(w);\n\
    \    }\n    void add_query(T x, T y) {\n        xs.emplace_back(x);\n        ys.emplace_back(y);\n\
    \    }\n    vector<S> solve() {\n        int n = xls.size(), q = xs.size();\n\
    \        auto yb = merge_and_unique(ys);\n        vector<tuple<int, int, T, S>>\
    \ rs;\n        rs.reserve(2 * n);\n        for (int i = 0; i < n; i++) {\n   \
    \         int l = lower_bound(yb.begin(), yb.end(), yls[i]) - yb.begin();\n  \
    \          int r = lower_bound(yb.begin(), yb.end(), yrs[i]) - yb.begin();\n \
    \           rs.emplace_back(l, r, xls[i], ws[i]);\n            rs.emplace_back(l,\
    \ r, xrs[i], M::inv(ws[i]));\n        }\n        sort(rs.begin(), rs.end(), [&]\
    \ (auto a, auto b) {\n            return get<2>(a) < get<2>(b);\n        });\n\
    \        vector<int> ord(q);\n        iota(ord.begin(), ord.end(), 0);\n     \
    \   sort(ord.begin(), ord.end(), [&] (int i, int j) {\n            return xs[i]\
    \ < xs[j];\n        });\n        range_add_fenwick_tree<Abelian_Group> fw(yb.size());\n\
    \        vector<S> res(q);\n        int j = 0;\n        for (int i : ord) {\n\
    \            while (j < 2 * n && get<2>(rs[j]) <= xs[i]) {\n                auto\
    \ [l, r, _, w] = rs[j++];\n                fw.add(l, r, w);\n            }\n \
    \           int y = lower_bound(yb.begin(), yb.end(), ys[i]) - yb.begin();\n \
    \           res[i] = fw.prod(y, y + 1);\n        }\n        return res;\n    }\n\
    private:\n    vector<T> xls, yls, xrs, yrs, xs, ys;\n    vector<S> ws;\n};"
  dependsOn:
  - src/misc/merge_and_unique.hpp
  - src/data_structure/segtree/range_add_fenwick_tree_abelian_group.hpp
  - src/data_structure/segtree/fenwick_tree_abelian_group.hpp
  isVerificationFile: false
  path: src/data_structure/misc/static_rectangle_add_point_get.hpp
  requiredBy:
  - src/data_structure/misc/dynamic_rectangle_add_point_get.hpp
  timestamp: '2025-09-03 07:13:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/misc/static_rectangle_add_point_get.hpp
layout: document
redirect_from:
- /library/src/data_structure/misc/static_rectangle_add_point_get.hpp
- /library/src/data_structure/misc/static_rectangle_add_point_get.hpp.html
title: src/data_structure/misc/static_rectangle_add_point_get.hpp
---
