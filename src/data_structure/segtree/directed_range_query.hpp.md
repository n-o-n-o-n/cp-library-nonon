---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/hld.test.cpp
    title: test/tree/hld.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/segtree/directed_range_query.hpp\"\n\
    #include <cassert>\n#include <ranges>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename SegTree>\nstruct directed_range_query {\n    using M = typename\
    \ SegTree::M;\n    using S = typename M::S;\n    directed_range_query() = default;\n\
    \    directed_range_query(int _n) : n(_n), seg(_n), ges(_n) {}\n    directed_range_query(const\
    \ vector<S> &v) : n(v.size()), seg(v), ges(vector<S>(v.rbegin(), v.rend())) {}\n\
    \    void set(int p, const S &x) {\n        assert(0 <= p && p < n);\n       \
    \ seg.set(p, x);\n        ges.set(n - 1 - p, x);\n    }\n    template<typename\
    \ F>\n    void apply(int l, int r, const F &f) {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        seg.apply(l, r, f);\n        ges.apply(n - r, n - l,\
    \ f);\n    }\n    S get(int p) {\n        assert(0 <= p && p < n);\n        return\
    \ seg.get(p);\n    }\n    S prod(int l, int r) {\n        return l < r ? seg.prod(l,\
    \ r) : ges.prod(n - l, n - r);\n    }\n    template<typename C>\n    int max_right(int\
    \ l, bool rev, const C &check) {\n        return rev ? n - ges.min_left(n - l,\
    \ check) : seg.max_right(l, check);\n    }\n    template<typename C>\n    int\
    \ min_left(int r, bool rev, const C &check) {\n        return rev ? n - ges.max_right(n\
    \ - r, check) : seg.min_left(r, check);\n    }\nprivate:\n    int n;\n    SegTree\
    \ seg, ges;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <ranges>\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename SegTree>\nstruct directed_range_query\
    \ {\n    using M = typename SegTree::M;\n    using S = typename M::S;\n    directed_range_query()\
    \ = default;\n    directed_range_query(int _n) : n(_n), seg(_n), ges(_n) {}\n\
    \    directed_range_query(const vector<S> &v) : n(v.size()), seg(v), ges(vector<S>(v.rbegin(),\
    \ v.rend())) {}\n    void set(int p, const S &x) {\n        assert(0 <= p && p\
    \ < n);\n        seg.set(p, x);\n        ges.set(n - 1 - p, x);\n    }\n    template<typename\
    \ F>\n    void apply(int l, int r, const F &f) {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        seg.apply(l, r, f);\n        ges.apply(n - r, n - l,\
    \ f);\n    }\n    S get(int p) {\n        assert(0 <= p && p < n);\n        return\
    \ seg.get(p);\n    }\n    S prod(int l, int r) {\n        return l < r ? seg.prod(l,\
    \ r) : ges.prod(n - l, n - r);\n    }\n    template<typename C>\n    int max_right(int\
    \ l, bool rev, const C &check) {\n        return rev ? n - ges.min_left(n - l,\
    \ check) : seg.max_right(l, check);\n    }\n    template<typename C>\n    int\
    \ min_left(int r, bool rev, const C &check) {\n        return rev ? n - ges.max_right(n\
    \ - r, check) : seg.min_left(r, check);\n    }\nprivate:\n    int n;\n    SegTree\
    \ seg, ges;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/segtree/directed_range_query.hpp
  requiredBy: []
  timestamp: '2025-05-01 18:24:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/hld.test.cpp
documentation_of: src/data_structure/segtree/directed_range_query.hpp
layout: document
redirect_from:
- /library/src/data_structure/segtree/directed_range_query.hpp
- /library/src/data_structure/segtree/directed_range_query.hpp.html
title: src/data_structure/segtree/directed_range_query.hpp
---
