---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/random/graph.hpp
    title: src/random/graph.hpp
  - icon: ':x:'
    path: src/random/sequence.hpp
    title: src/random/sequence.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/fps/power_projection.test.cpp
    title: test/fps/power_projection.test.cpp
  - icon: ':x:'
    path: test/tree/centroid_decomposition.test.cpp
    title: test/tree/centroid_decomposition.test.cpp
  - icon: ':x:'
    path: test/tree/level_ancestor_offline.test.cpp
    title: test/tree/level_ancestor_offline.test.cpp
  - icon: ':x:'
    path: test/tree/prufer_code.test.cpp
    title: test/tree/prufer_code.test.cpp
  - icon: ':x:'
    path: test/tree/static_tree.auxiliary_tree.test.cpp
    title: test/tree/static_tree.auxiliary_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/misc/even_distribution_array.hpp\"\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename T>\nvector<T> even_distribution_array(const\
    \ vector<T> &v) {\n    int n = v.size();\n    long long sum = 0;\n    for (int\
    \ i = 0; i < n; i++) {\n        sum += v[i];\n    }\n    T q = sum / n, r = sum\
    \ % n;\n    vector<T> res(n, q);\n    for (int i = n - r; i < n; i++) res[i]++;\n\
    \    return res;\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ T>\nvector<T> even_distribution_array(const vector<T> &v) {\n    int n = v.size();\n\
    \    long long sum = 0;\n    for (int i = 0; i < n; i++) {\n        sum += v[i];\n\
    \    }\n    T q = sum / n, r = sum % n;\n    vector<T> res(n, q);\n    for (int\
    \ i = n - r; i < n; i++) res[i]++;\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/even_distribution_array.hpp
  requiredBy:
  - src/random/sequence.hpp
  - src/random/graph.hpp
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/fps/power_projection.test.cpp
  - test/tree/level_ancestor_offline.test.cpp
  - test/tree/prufer_code.test.cpp
  - test/tree/centroid_decomposition.test.cpp
  - test/tree/static_tree.auxiliary_tree.test.cpp
documentation_of: src/misc/even_distribution_array.hpp
layout: document
redirect_from:
- /library/src/misc/even_distribution_array.hpp
- /library/src/misc/even_distribution_array.hpp.html
title: src/misc/even_distribution_array.hpp
---
