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
  bundledCode: "#line 2 \"src/data_structure/sparse_table/disjoint_sparse_table.hpp\"\
    \n#include <bit>\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename Monoid>\nstruct disjoint_sparse_table {\n    using M = Monoid;\n\
    \    using S = typename M::S;\n    disjoint_sparse_table() = default;\n    disjoint_sparse_table(int\
    \ _n) : n(_n), b(0), d(1, vector<S>(_n, M::e())) {}\n    disjoint_sparse_table(const\
    \ vector<S> &v) : n(v.size()), b(0), d(1, v) { build(); }\n    void set(int p,\
    \ S x) {\n        assert(0 <= p && p < n);\n        assert(b == 0);\n        d[0][p]\
    \ = x;\n    }\n    S get(int p) {\n        assert(0 <= p && p < n);\n        return\
    \ d[0][p];\n    }\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r\
    \ && r <=n);\n        build();\n        if (l == r) return M::e();\n        if\
    \ (l + 1 == r) return d[0][l];\n        int i = bit_width(unsigned(l ^ (r - 1)));\n\
    \        return M::op(d[i][l], d[i][r - 1]);\n    }\nprivate:\n    int n, b;\n\
    \    vector<vector<S>> d;\n    void build() {\n        if (b > 0) return;\n  \
    \      b = bit_width((unsigned)n);\n        d.resize(b + 1, vector<S>(n, M::e()));\n\
    \        for (int i = 1; i <= b; i++) {\n            int len = 1 << i;\n     \
    \       int l = len >> 1;\n            for (int k = 0; l < n; k += len, l += len)\
    \ {\n                d[i][l - 1] = d[0][l - 1];\n                for (int j =\
    \ l - 2; j >= k; j--) {\n                    d[i][j] = M::op(d[0][j], d[i][j +\
    \ 1]);\n                }\n                d[i][l] = d[0][l];\n              \
    \  for (int j = l + 1; j < n && j < k + len; j++) {\n                    d[i][j]\
    \ = M::op(d[i][j - 1], d[0][j]);\n                }\n            }\n        }\n\
    \    }\n};\n"
  code: "#pragma once\n#include <bit>\n#include <cassert>\n#include <vector>\nusing\
    \ namespace std;\n\ntemplate<typename Monoid>\nstruct disjoint_sparse_table {\n\
    \    using M = Monoid;\n    using S = typename M::S;\n    disjoint_sparse_table()\
    \ = default;\n    disjoint_sparse_table(int _n) : n(_n), b(0), d(1, vector<S>(_n,\
    \ M::e())) {}\n    disjoint_sparse_table(const vector<S> &v) : n(v.size()), b(0),\
    \ d(1, v) { build(); }\n    void set(int p, S x) {\n        assert(0 <= p && p\
    \ < n);\n        assert(b == 0);\n        d[0][p] = x;\n    }\n    S get(int p)\
    \ {\n        assert(0 <= p && p < n);\n        return d[0][p];\n    }\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <=n);\n        build();\n\
    \        if (l == r) return M::e();\n        if (l + 1 == r) return d[0][l];\n\
    \        int i = bit_width(unsigned(l ^ (r - 1)));\n        return M::op(d[i][l],\
    \ d[i][r - 1]);\n    }\nprivate:\n    int n, b;\n    vector<vector<S>> d;\n  \
    \  void build() {\n        if (b > 0) return;\n        b = bit_width((unsigned)n);\n\
    \        d.resize(b + 1, vector<S>(n, M::e()));\n        for (int i = 1; i <=\
    \ b; i++) {\n            int len = 1 << i;\n            int l = len >> 1;\n  \
    \          for (int k = 0; l < n; k += len, l += len) {\n                d[i][l\
    \ - 1] = d[0][l - 1];\n                for (int j = l - 2; j >= k; j--) {\n  \
    \                  d[i][j] = M::op(d[0][j], d[i][j + 1]);\n                }\n\
    \                d[i][l] = d[0][l];\n                for (int j = l + 1; j < n\
    \ && j < k + len; j++) {\n                    d[i][j] = M::op(d[i][j - 1], d[0][j]);\n\
    \                }\n            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/sparse_table/disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2025-05-01 17:24:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/sparse_table/disjoint_sparse_table.hpp
layout: document
redirect_from:
- /library/src/data_structure/sparse_table/disjoint_sparse_table.hpp
- /library/src/data_structure/sparse_table/disjoint_sparse_table.hpp.html
title: src/data_structure/sparse_table/disjoint_sparse_table.hpp
---
