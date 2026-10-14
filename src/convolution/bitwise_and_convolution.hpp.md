---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/convolution/superset_zmt.hpp
    title: src/convolution/superset_zmt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/convolution/bitwise_and_convolution.test.cpp
    title: test/convolution/bitwise_and_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/convolution/bitwise_and_convolution.hpp\"\n#include\
    \ <cassert>\n#include <vector>\nusing namespace std;\n#line 4 \"src/convolution/superset_zmt.hpp\"\
    \nusing namespace std;\n\ntemplate<typename mint>\nvoid superset_zmt(vector<mint>\
    \ &f, bool moebius = false) {\n    int n = f.size();\n    assert((n & (n - 1))\
    \ == 0);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if (i & j) continue;\n            f[j] += moebius ? -f[i\
    \ | j] : f[i | j];\n        }\n    }\n}\n#line 6 \"src/convolution/bitwise_and_convolution.hpp\"\
    \n\ntemplate<typename mint>\nvector<mint> bitwise_and_convolution(vector<mint>\
    \ f, vector<mint> g) {\n    assert(f.size() == g.size());\n    int n = f.size();\n\
    \    assert((n & (n - 1)) == 0);\n    if (n == 0) return {};\n    superset_zmt(f);\n\
    \    superset_zmt(g);\n    for (int i = 0; i < n; i++) f[i] *= g[i];\n    superset_zmt(f,\
    \ true);\n    return f;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    #include \"superset_zmt.hpp\"\n\ntemplate<typename mint>\nvector<mint> bitwise_and_convolution(vector<mint>\
    \ f, vector<mint> g) {\n    assert(f.size() == g.size());\n    int n = f.size();\n\
    \    assert((n & (n - 1)) == 0);\n    if (n == 0) return {};\n    superset_zmt(f);\n\
    \    superset_zmt(g);\n    for (int i = 0; i < n; i++) f[i] *= g[i];\n    superset_zmt(f,\
    \ true);\n    return f;\n}"
  dependsOn:
  - src/convolution/superset_zmt.hpp
  isVerificationFile: false
  path: src/convolution/bitwise_and_convolution.hpp
  requiredBy: []
  timestamp: '2025-12-27 09:40:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/convolution/bitwise_and_convolution.test.cpp
documentation_of: src/convolution/bitwise_and_convolution.hpp
layout: document
redirect_from:
- /library/src/convolution/bitwise_and_convolution.hpp
- /library/src/convolution/bitwise_and_convolution.hpp.html
title: src/convolution/bitwise_and_convolution.hpp
---
