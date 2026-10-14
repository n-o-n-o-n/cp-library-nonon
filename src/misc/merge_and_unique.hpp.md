---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/data_structure/misc/area_of_union_of_rectangles.hpp
    title: src/data_structure/misc/area_of_union_of_rectangles.hpp
  - icon: ':warning:'
    path: src/data_structure/misc/dynamic_point_add_rectangle_sum.hpp
    title: src/data_structure/misc/dynamic_point_add_rectangle_sum.hpp
  - icon: ':warning:'
    path: src/data_structure/misc/dynamic_rectangle_add_point_get.hpp
    title: src/data_structure/misc/dynamic_rectangle_add_point_get.hpp
  - icon: ':warning:'
    path: src/data_structure/misc/static_point_add_rectangle_sum.hpp
    title: src/data_structure/misc/static_point_add_rectangle_sum.hpp
  - icon: ':warning:'
    path: src/data_structure/misc/static_rectangle_add_point_get.hpp
    title: src/data_structure/misc/static_rectangle_add_point_get.hpp
  - icon: ':warning:'
    path: src/dp/lis.hpp
    title: src/dp/lis.hpp
  - icon: ':warning:'
    path: src/misc/compress.hpp
    title: src/misc/compress.hpp
  - icon: ':warning:'
    path: src/misc/inversion_number.hpp
    title: src/misc/inversion_number.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/misc/merge_and_unique.hpp\"\n#include <algorithm>\n\
    #include <vector>\nusing namespace std;\n\ntemplate<typename T, typename... Ts>\n\
    vector<T> merge_and_unique(const vector<T> &a, const Ts &...z) {\n    vector<T>\
    \ res = a;\n    (res.insert(res.end(), z.begin(), z.end()), ...);\n    sort(res.begin(),\
    \ res.end());\n    res.erase(unique(res.begin(), res.end()), res.end());\n   \
    \ return res;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename T, typename... Ts>\nvector<T> merge_and_unique(const vector<T>\
    \ &a, const Ts &...z) {\n    vector<T> res = a;\n    (res.insert(res.end(), z.begin(),\
    \ z.end()), ...);\n    sort(res.begin(), res.end());\n    res.erase(unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/merge_and_unique.hpp
  requiredBy:
  - src/misc/inversion_number.hpp
  - src/misc/compress.hpp
  - src/data_structure/misc/static_rectangle_add_point_get.hpp
  - src/data_structure/misc/static_point_add_rectangle_sum.hpp
  - src/data_structure/misc/dynamic_rectangle_add_point_get.hpp
  - src/data_structure/misc/dynamic_point_add_rectangle_sum.hpp
  - src/data_structure/misc/area_of_union_of_rectangles.hpp
  - src/dp/lis.hpp
  timestamp: '2025-07-03 13:57:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/merge_and_unique.hpp
layout: document
redirect_from:
- /library/src/misc/merge_and_unique.hpp
- /library/src/misc/merge_and_unique.hpp.html
title: src/misc/merge_and_unique.hpp
---
