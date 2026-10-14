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
  bundledCode: "#line 2 \"src/geometry/manhattan_mst.hpp\"\n#include <algorithm>\n\
    #include <map>\n#include <numeric>\n#include <vector>\nusing namespace std;\n\n\
    template<typename T>\nvector<tuple<T, int, int>> manhattan_mst(vector<T> xs, vector<T>\
    \ ys) {\n    int n = xs.size();\n    vector<int> ord(n);\n    iota(ord.begin(),\
    \ ord.end(), 0);\n    vector<tuple<T, int, int>> res;\n    res.reserve(4 * n);\n\
    \    for (auto _ : {0, 1}) {\n        for (auto _ : {0, 1}) {\n            sort(ord.begin(),\
    \ ord.end(), [&](int i, int j) {\n                return xs[i] + ys[i] < xs[j]\
    \ + ys[j];\n            });\n            map<T, int, greater<T>> mp;\n       \
    \     for (int i : ord) {\n                for (auto it = mp.lower_bound(ys[i]);\
    \ it != mp.end(); it = mp.erase(it)) {\n                    int j = it->second;\n\
    \                    T dx = xs[i] - xs[j], dy = ys[i] - ys[j];\n             \
    \       if (dx < dy) break;\n                    res.emplace_back(dx + dy, i,\
    \ j);\n                }\n                mp[ys[i]] = i;\n            }\n    \
    \        for (T &x : xs) x = -x;\n        }\n        swap(xs, ys);\n    }\n  \
    \  sort(res.begin(), res.end());\n    return res;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <map>\n#include <numeric>\n\
    #include <vector>\nusing namespace std;\n\ntemplate<typename T>\nvector<tuple<T,\
    \ int, int>> manhattan_mst(vector<T> xs, vector<T> ys) {\n    int n = xs.size();\n\
    \    vector<int> ord(n);\n    iota(ord.begin(), ord.end(), 0);\n    vector<tuple<T,\
    \ int, int>> res;\n    res.reserve(4 * n);\n    for (auto _ : {0, 1}) {\n    \
    \    for (auto _ : {0, 1}) {\n            sort(ord.begin(), ord.end(), [&](int\
    \ i, int j) {\n                return xs[i] + ys[i] < xs[j] + ys[j];\n       \
    \     });\n            map<T, int, greater<T>> mp;\n            for (int i : ord)\
    \ {\n                for (auto it = mp.lower_bound(ys[i]); it != mp.end(); it\
    \ = mp.erase(it)) {\n                    int j = it->second;\n               \
    \     T dx = xs[i] - xs[j], dy = ys[i] - ys[j];\n                    if (dx <\
    \ dy) break;\n                    res.emplace_back(dx + dy, i, j);\n         \
    \       }\n                mp[ys[i]] = i;\n            }\n            for (T &x\
    \ : xs) x = -x;\n        }\n        swap(xs, ys);\n    }\n    sort(res.begin(),\
    \ res.end());\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/manhattan_mst.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/manhattan_mst.hpp
layout: document
redirect_from:
- /library/src/geometry/manhattan_mst.hpp
- /library/src/geometry/manhattan_mst.hpp.html
title: src/geometry/manhattan_mst.hpp
---
