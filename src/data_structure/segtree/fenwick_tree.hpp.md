---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/data_structure/segtree/range_add_fenwick_tree.hpp
    title: src/data_structure/segtree/range_add_fenwick_tree.hpp
  - icon: ':warning:'
    path: src/misc/inversion_number.hpp
    title: src/misc/inversion_number.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/segtree/fenwick_tree.hpp\"\n#include\
    \ <cassert>\n#include <vector>\nusing namespace std;\n\ntemplate<typename T>\n\
    struct fenwick_tree {\n    fenwick_tree() = default;\n    fenwick_tree(int _n)\
    \ : fenwick_tree(vector<T>(_n, 0)) {}\n    fenwick_tree(const vector<T> &_v) :\
    \ n(_v.size()) {\n        d = vector<T>(n, 0);\n        v = vector<T>(n, 0);\n\
    \        for (int i = 1; i <= n; i++) {\n            v[i - 1] = _v[i - 1];\n \
    \           d[i - 1] += v[i - 1];\n            int j = i + (i & -i);\n       \
    \     if (j <= n) d[j - 1] += d[i - 1];\n        }\n    }\n    void add(int p,\
    \ T x) {\n        assert(0 <= p && p < n);\n        v[p] += x;\n        for (p++;\
    \ p <= n; p += p & -p) {\n            d[p - 1] += x;\n        }\n    }\n    void\
    \ update(int p, T x) {\n        assert(0 <= p && p < n);\n        add(p, x - v[p]);\n\
    \    }\n    T get(int p) const {\n        assert(0 <= p && p < n);\n        return\
    \ v[p];\n    }\n    T sum(int l, int r) const {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        return sum(r) - sum(l);\n    }\n    // max{ r | sum(r)\
    \ < x }\n    int lower_bound(T x) const {\n        int r = 0, p = 1;\n       \
    \ while ((p << 1) <= n) p <<= 1;\n        while (p > 0) {\n            if (r +\
    \ p <= n && d[r + p - 1] < x) {\n                r += p;\n                x -=\
    \ d[r - 1];\n            }\n            p >>= 1;\n        }\n        return r;\n\
    \    }\nprivate:\n    int n;\n    vector<T> d, v;\n    T sum(int p) const {\n\
    \        T res = 0;\n        for (; p > 0; p -= p & -p) {\n            res +=\
    \ d[p - 1];\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename T>\nstruct fenwick_tree {\n    fenwick_tree() = default;\n\
    \    fenwick_tree(int _n) : fenwick_tree(vector<T>(_n, 0)) {}\n    fenwick_tree(const\
    \ vector<T> &_v) : n(_v.size()) {\n        d = vector<T>(n, 0);\n        v = vector<T>(n,\
    \ 0);\n        for (int i = 1; i <= n; i++) {\n            v[i - 1] = _v[i - 1];\n\
    \            d[i - 1] += v[i - 1];\n            int j = i + (i & -i);\n      \
    \      if (j <= n) d[j - 1] += d[i - 1];\n        }\n    }\n    void add(int p,\
    \ T x) {\n        assert(0 <= p && p < n);\n        v[p] += x;\n        for (p++;\
    \ p <= n; p += p & -p) {\n            d[p - 1] += x;\n        }\n    }\n    void\
    \ update(int p, T x) {\n        assert(0 <= p && p < n);\n        add(p, x - v[p]);\n\
    \    }\n    T get(int p) const {\n        assert(0 <= p && p < n);\n        return\
    \ v[p];\n    }\n    T sum(int l, int r) const {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        return sum(r) - sum(l);\n    }\n    // max{ r | sum(r)\
    \ < x }\n    int lower_bound(T x) const {\n        int r = 0, p = 1;\n       \
    \ while ((p << 1) <= n) p <<= 1;\n        while (p > 0) {\n            if (r +\
    \ p <= n && d[r + p - 1] < x) {\n                r += p;\n                x -=\
    \ d[r - 1];\n            }\n            p >>= 1;\n        }\n        return r;\n\
    \    }\nprivate:\n    int n;\n    vector<T> d, v;\n    T sum(int p) const {\n\
    \        T res = 0;\n        for (; p > 0; p -= p & -p) {\n            res +=\
    \ d[p - 1];\n        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/segtree/fenwick_tree.hpp
  requiredBy:
  - src/misc/inversion_number.hpp
  - src/data_structure/segtree/range_add_fenwick_tree.hpp
  timestamp: '2025-05-05 08:34:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/segtree/fenwick_tree.hpp
layout: document
redirect_from:
- /library/src/data_structure/segtree/fenwick_tree.hpp
- /library/src/data_structure/segtree/fenwick_tree.hpp.html
title: src/data_structure/segtree/fenwick_tree.hpp
---
