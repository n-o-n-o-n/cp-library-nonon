---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/misc/compress.hpp
    title: src/misc/compress.hpp
  - icon: ':warning:'
    path: src/misc/merge_and_unique.hpp
    title: src/misc/merge_and_unique.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dp/lis.hpp\"\n#include <algorithm>\n#include <vector>\n\
    #line 4 \"src/misc/merge_and_unique.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ T, typename... Ts>\nvector<T> merge_and_unique(const vector<T> &a, const Ts\
    \ &...z) {\n    vector<T> res = a;\n    (res.insert(res.end(), z.begin(), z.end()),\
    \ ...);\n    sort(res.begin(), res.end());\n    res.erase(unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n#line 5 \"src/misc/compress.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T>\nvector<int> compress(const vector<T>\
    \ &v) {\n    auto zip = merge_and_unique(v);\n    vector<int> res;\n    res.reserve(v.size());\n\
    \    for (const T &e : v) {\n        res.push_back(lower_bound(zip.begin(), zip.end(),\
    \ e) - zip.begin());\n    }\n    return res;\n}\n\ntemplate<typename T, typename...\
    \ Ts>\nauto compress(const vector<T> &a, const Ts &...z) {\n    auto zip = merge_and_unique(a,\
    \ z...);\n    auto f = [&] (const vector<T> &v) -> vector<int> {\n        vector<int>\
    \ res;\n        res.reserve(v.size());\n        for (const T &e : v) {\n     \
    \       res.push_back(lower_bound(zip.begin(), zip.end(), e) - zip.begin());\n\
    \        }\n        return res;\n    };\n    return make_tuple(f(a), f(z)...);\n\
    }\n\ntemplate<typename T, typename... Ts>\nint compress_inplace(vector<T> &a,\
    \ Ts &...z) {\n    auto zip = merge_and_unique(a, z...);\n    auto f = [&] (vector<T>\
    \ &v) -> void {\n        for (T &e : v) {\n            e = lower_bound(zip.begin(),\
    \ zip.end(), e) - zip.begin();\n        }\n    };\n    (f(a), ..., f(z));\n  \
    \  return (int)zip.size();\n}\n#line 5 \"src/dp/lis.hpp\"\nusing namespace std;\n\
    \ntemplate<typename S>\nvector<int> longest_increasing_subsequence(const vector<S>\
    \ &v, bool strict = true) {\n    if (v.empty()) return {};\n    vector<int> a\
    \ = compress(v);\n    int n = v.size();\n    vector<int> dp(n, 1 << 30), idx(n,\
    \ -1);\n    for (int i = 0; i < n; i++) {\n        int j;\n        if (strict)\
    \ {\n            j = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();\n \
    \       } else {\n            j = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();\n\
    \        }\n        dp[j] = a[i];\n        idx[i] = j;\n    }\n    int m = *max_element(idx.begin(),\
    \ idx.end());\n    vector<int> res(m + 1);\n    for (int i = n - 1; i >= 0; i--)\
    \ {\n        if (idx[i] == m) {\n            res[m] = i;\n            m--;\n \
    \       }\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include \"../misc/compress.hpp\"\
    \nusing namespace std;\n\ntemplate<typename S>\nvector<int> longest_increasing_subsequence(const\
    \ vector<S> &v, bool strict = true) {\n    if (v.empty()) return {};\n    vector<int>\
    \ a = compress(v);\n    int n = v.size();\n    vector<int> dp(n, 1 << 30), idx(n,\
    \ -1);\n    for (int i = 0; i < n; i++) {\n        int j;\n        if (strict)\
    \ {\n            j = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();\n \
    \       } else {\n            j = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();\n\
    \        }\n        dp[j] = a[i];\n        idx[i] = j;\n    }\n    int m = *max_element(idx.begin(),\
    \ idx.end());\n    vector<int> res(m + 1);\n    for (int i = n - 1; i >= 0; i--)\
    \ {\n        if (idx[i] == m) {\n            res[m] = i;\n            m--;\n \
    \       }\n    }\n    return res;\n}"
  dependsOn:
  - src/misc/compress.hpp
  - src/misc/merge_and_unique.hpp
  isVerificationFile: false
  path: src/dp/lis.hpp
  requiredBy: []
  timestamp: '2025-08-12 07:19:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/dp/lis.hpp
layout: document
redirect_from:
- /library/src/dp/lis.hpp
- /library/src/dp/lis.hpp.html
title: src/dp/lis.hpp
---
