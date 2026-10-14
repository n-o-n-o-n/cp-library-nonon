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
  bundledCode: "#line 2 \"src/string/rle.hpp\"\n#include <string>\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename T>\nvector<pair<T, int>> run_length_encoding(const\
    \ vector<T> &v) {\n    vector<pair<T, int>> res;\n    for (const auto &x : v)\
    \ {\n        if (res.empty() || res.back().first != x) {\n            res.emplace_back(x,\
    \ 0);\n        }\n        res.back().second++;\n    }\n    return res;\n}\n\n\
    vector<pair<char, int>> run_length_encoding(const string &s) {\n    return run_length_encoding(vector<char>(s.begin(),\
    \ s.end()));\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename T>\nvector<pair<T, int>> run_length_encoding(const vector<T>\
    \ &v) {\n    vector<pair<T, int>> res;\n    for (const auto &x : v) {\n      \
    \  if (res.empty() || res.back().first != x) {\n            res.emplace_back(x,\
    \ 0);\n        }\n        res.back().second++;\n    }\n    return res;\n}\n\n\
    vector<pair<char, int>> run_length_encoding(const string &s) {\n    return run_length_encoding(vector<char>(s.begin(),\
    \ s.end()));\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/string/rle.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/rle.hpp
layout: document
redirect_from:
- /library/src/string/rle.hpp
- /library/src/string/rle.hpp.html
title: src/string/rle.hpp
---
