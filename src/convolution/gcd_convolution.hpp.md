---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/convolution/multiple_zmt.hpp
    title: src/convolution/multiple_zmt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/convolution/gcd_convolution.test.cpp
    title: test/convolution/gcd_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/convolution/gcd_convolution.hpp\"\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n#line 4 \"src/convolution/multiple_zmt.hpp\"\
    \nusing namespace std;\n\ntemplate<typename mint>\nvoid multiple_zmt(vector<mint>\
    \ &f, bool moebius = false) {\n    int n = f.size();\n    vector<bool> sieve(n,\
    \ true);\n    for (int i = 2; i < n; i++) {\n        if (sieve[i]) {\n       \
    \     if (moebius) {\n                for (int j = 1; i * j < n; j++) {\n    \
    \                sieve[i * j] = false;\n                    f[j] -= f[i * j];\n\
    \                }\n            } else {\n                for (int j = (n - 1)\
    \ / i; j > 0; j--) {\n                    sieve[i * j] = false;\n            \
    \        f[j] += f[i * j];\n                }\n            }\n        }\n    }\n\
    }\n#line 6 \"src/convolution/gcd_convolution.hpp\"\n\ntemplate<typename mint>\n\
    vector<mint> gcd_convolution(vector<mint> f, vector<mint> g) {\n    assert(f.size()\
    \ == g.size());\n    int n = f.size();\n    if (n == 0) return {};\n    multiple_zmt(f);\n\
    \    multiple_zmt(g);\n    for (int i = 0; i < n; i++) f[i] *= g[i];\n    multiple_zmt(f,\
    \ true);\n    return f;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    #include \"multiple_zmt.hpp\"\n\ntemplate<typename mint>\nvector<mint> gcd_convolution(vector<mint>\
    \ f, vector<mint> g) {\n    assert(f.size() == g.size());\n    int n = f.size();\n\
    \    if (n == 0) return {};\n    multiple_zmt(f);\n    multiple_zmt(g);\n    for\
    \ (int i = 0; i < n; i++) f[i] *= g[i];\n    multiple_zmt(f, true);\n    return\
    \ f;\n}"
  dependsOn:
  - src/convolution/multiple_zmt.hpp
  isVerificationFile: false
  path: src/convolution/gcd_convolution.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/convolution/gcd_convolution.test.cpp
documentation_of: src/convolution/gcd_convolution.hpp
layout: document
redirect_from:
- /library/src/convolution/gcd_convolution.hpp
- /library/src/convolution/gcd_convolution.hpp.html
title: src/convolution/gcd_convolution.hpp
---
