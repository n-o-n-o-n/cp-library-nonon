---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/string/longest_common_substring.hpp
    title: src/string/longest_common_substring.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/lcp_array.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <string>\nusing namespace std;\n\n\n// lcp[i] = lcp(S[\
    \ sa[i-1] : N ], S[ sa[i] : N ])\ntemplate<typename S>\nvector<int> lcp_array(const\
    \ vector<S> &v, const vector<int> &sa) {\n    int n = v.size();\n    vector<int>\
    \ lcp(n), rank(n);\n    for (int i = 0; i < n; i++) rank[ sa[i] ] = i;\n    for(int\
    \ i = 0, h = 0; i < n; i++) {\n        if(rank[i] + 1 < n) {\n            int\
    \ j = sa[ rank[i] + 1 ];\n            while (i + h < n && j + h < n && v[i + h]\
    \ == v[j + h]) h++;\n            lcp[ rank[i] + 1 ] = h;\n            if (h >\
    \ 0) h--;\n        }\n    }\n    return lcp;\n}\n\nvector<int> lcp_array(const\
    \ string &s, const vector<int> &sa) {\n    return lcp_array(vector<char>(s.begin(),\
    \ s.end()), sa);\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <string>\n\
    using namespace std;\n\n\n// lcp[i] = lcp(S[ sa[i-1] : N ], S[ sa[i] : N ])\n\
    template<typename S>\nvector<int> lcp_array(const vector<S> &v, const vector<int>\
    \ &sa) {\n    int n = v.size();\n    vector<int> lcp(n), rank(n);\n    for (int\
    \ i = 0; i < n; i++) rank[ sa[i] ] = i;\n    for(int i = 0, h = 0; i < n; i++)\
    \ {\n        if(rank[i] + 1 < n) {\n            int j = sa[ rank[i] + 1 ];\n \
    \           while (i + h < n && j + h < n && v[i + h] == v[j + h]) h++;\n    \
    \        lcp[ rank[i] + 1 ] = h;\n            if (h > 0) h--;\n        }\n   \
    \ }\n    return lcp;\n}\n\nvector<int> lcp_array(const string &s, const vector<int>\
    \ &sa) {\n    return lcp_array(vector<char>(s.begin(), s.end()), sa);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/string/lcp_array.hpp
  requiredBy:
  - src/string/longest_common_substring.hpp
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/lcp_array.hpp
layout: document
redirect_from:
- /library/src/string/lcp_array.hpp
- /library/src/string/lcp_array.hpp.html
title: src/string/lcp_array.hpp
---
