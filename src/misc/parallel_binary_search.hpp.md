---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/past20-open/submissions/71648427
  bundledCode: "#line 2 \"src/misc/parallel_binary_search.hpp\"\n#include <vector>\n\
    using namespace std;\n\n// \u4F7F\u3044\u65B9\u306F\u3053\u308C\u3092\u53C2\u7167\
    : https://atcoder.jp/contests/past20-open/submissions/71648427 \ntemplate<typename\
    \ A, typename Q, typename R>\nvector<int> parallel_binary_search(int t, int q,\
    \ const A &act, const Q &query, const R &reset) {\n    vector<int> l(q, -1), r(q,\
    \ t);\n    for (int p = 1; p <= t; p *= 2) {\n        reset();\n        vector<int>\
    \ m(q);\n        vector<vector<int>> qs(t);\n        for (int j = 0; j < q; j++)\
    \ {\n            m[j] = (l[j] + r[j]) / 2;\n            qs[m[j]].push_back(j);\n\
    \        }\n        for (int i = 0; i < t; i++) {\n            act(i);\n     \
    \       for (int j : qs[i]) (query(j) ? r[j] : l[j]) = m[j];\n        }\n    }\n\
    \    return r;\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\n// \u4F7F\u3044\u65B9\
    \u306F\u3053\u308C\u3092\u53C2\u7167: https://atcoder.jp/contests/past20-open/submissions/71648427\
    \ \ntemplate<typename A, typename Q, typename R>\nvector<int> parallel_binary_search(int\
    \ t, int q, const A &act, const Q &query, const R &reset) {\n    vector<int> l(q,\
    \ -1), r(q, t);\n    for (int p = 1; p <= t; p *= 2) {\n        reset();\n   \
    \     vector<int> m(q);\n        vector<vector<int>> qs(t);\n        for (int\
    \ j = 0; j < q; j++) {\n            m[j] = (l[j] + r[j]) / 2;\n            qs[m[j]].push_back(j);\n\
    \        }\n        for (int i = 0; i < t; i++) {\n            act(i);\n     \
    \       for (int j : qs[i]) (query(j) ? r[j] : l[j]) = m[j];\n        }\n    }\n\
    \    return r;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/parallel_binary_search.hpp
  requiredBy: []
  timestamp: '2025-12-13 18:54:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/parallel_binary_search.hpp
layout: document
redirect_from:
- /library/src/misc/parallel_binary_search.hpp
- /library/src/misc/parallel_binary_search.hpp.html
title: src/misc/parallel_binary_search.hpp
---
