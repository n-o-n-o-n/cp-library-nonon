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
  bundledCode: "#line 2 \"src/string/z_algorithm.hpp\"\n#include <vector>\nusing namespace\
    \ std;\n\n#line 6 \"src/string/z_algorithm.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ S> \nvector<int> z_algorithm(const vector<S> &v) {\n    const int n = v.size();\n\
    \    int p = 0;\n    vector<int> z(n);\n    for (int i = 1; i < n; i++) {\n  \
    \      int k = i - p;\n        if (i + z[k] < p + z[p]) {\n            z[i] =\
    \ z[k];\n        } else {\n            int j = max(0, p + z[p] - i);\n       \
    \     while (i + j < n && v[j] == v[i + j]) j++;\n            z[i] = j;\n    \
    \        p = i;\n        }\n    }\n    z[0] = n;\n    return z;\n}\n\nvector<int>\
    \ z_algorithm(const string &s) {\n    return z_algorithm(vector<char>(s.begin(),\
    \ s.end()));\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename S> \nvector<int> z_algorithm(const vector<S>\
    \ &v) {\n    const int n = v.size();\n    int p = 0;\n    vector<int> z(n);\n\
    \    for (int i = 1; i < n; i++) {\n        int k = i - p;\n        if (i + z[k]\
    \ < p + z[p]) {\n            z[i] = z[k];\n        } else {\n            int j\
    \ = max(0, p + z[p] - i);\n            while (i + j < n && v[j] == v[i + j]) j++;\n\
    \            z[i] = j;\n            p = i;\n        }\n    }\n    z[0] = n;\n\
    \    return z;\n}\n\nvector<int> z_algorithm(const string &s) {\n    return z_algorithm(vector<char>(s.begin(),\
    \ s.end()));\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/z_algorithm.hpp
layout: document
redirect_from:
- /library/src/string/z_algorithm.hpp
- /library/src/string/z_algorithm.hpp.html
title: src/string/z_algorithm.hpp
---
