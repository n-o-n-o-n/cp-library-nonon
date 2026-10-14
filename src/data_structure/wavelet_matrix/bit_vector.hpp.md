---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/data_structure/wavelet_matrix/wavelet_matrix.hpp
    title: src/data_structure/wavelet_matrix/wavelet_matrix.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/wavelet_matrix/bit_vector.hpp\"\n#include\
    \ <cassert>\n#include <vector>\nusing namespace std;\n\nstruct bit_vector {\n\
    \    bit_vector() = default;\n    bit_vector(const vector<bool> &v) {\n      \
    \  int n = v.size();\n        int m = n / b + 1;\n        d = vector<unsigned>(m);\n\
    \        sum = vector<int>(m + 1);\n        for (int i = 0; i < n; i++) {\n  \
    \          d[i / b] |= v[i] << (i % b);\n        }\n        for (int i = 0; i\
    \ < m; i++) {\n            sum[i + 1] = sum[i] + __builtin_popcount(d[i]);\n \
    \       }\n    }\n    bool operator[](int i) const { return d[i / b] >> (i % b)\
    \ & 1; }\n    int rank(int i, bool flag = false) const {\n        int mask = (1U\
    \ << (i % b)) - 1;\n        int r = sum[i / b] + __builtin_popcount(d[i / b] &\
    \ mask);\n        return flag ? r : i - r;\n    }\n    int select(int i, bool\
    \ flag) const {\n        int l = 0, r = d.size();\n        while (r - l > 1) {\n\
    \            int m = (l + r) >> 1;\n            (rank(i, flag) < i ? l : r) =\
    \ m;\n        }\n        return l;\n    }\nprivate:\n    static constexpr int\
    \ b = 32;\n    vector<unsigned> d;\n    vector<int> sum;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \nstruct bit_vector {\n    bit_vector() = default;\n    bit_vector(const vector<bool>\
    \ &v) {\n        int n = v.size();\n        int m = n / b + 1;\n        d = vector<unsigned>(m);\n\
    \        sum = vector<int>(m + 1);\n        for (int i = 0; i < n; i++) {\n  \
    \          d[i / b] |= v[i] << (i % b);\n        }\n        for (int i = 0; i\
    \ < m; i++) {\n            sum[i + 1] = sum[i] + __builtin_popcount(d[i]);\n \
    \       }\n    }\n    bool operator[](int i) const { return d[i / b] >> (i % b)\
    \ & 1; }\n    int rank(int i, bool flag = false) const {\n        int mask = (1U\
    \ << (i % b)) - 1;\n        int r = sum[i / b] + __builtin_popcount(d[i / b] &\
    \ mask);\n        return flag ? r : i - r;\n    }\n    int select(int i, bool\
    \ flag) const {\n        int l = 0, r = d.size();\n        while (r - l > 1) {\n\
    \            int m = (l + r) >> 1;\n            (rank(i, flag) < i ? l : r) =\
    \ m;\n        }\n        return l;\n    }\nprivate:\n    static constexpr int\
    \ b = 32;\n    vector<unsigned> d;\n    vector<int> sum;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/wavelet_matrix/bit_vector.hpp
  requiredBy:
  - src/data_structure/wavelet_matrix/wavelet_matrix.hpp
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/wavelet_matrix/bit_vector.hpp
layout: document
redirect_from:
- /library/src/data_structure/wavelet_matrix/bit_vector.hpp
- /library/src/data_structure/wavelet_matrix/bit_vector.hpp.html
title: src/data_structure/wavelet_matrix/bit_vector.hpp
---
