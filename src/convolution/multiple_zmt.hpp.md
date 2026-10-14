---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/convolution/gcd_convolution.hpp
    title: src/convolution/gcd_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/convolution/gcd_convolution.test.cpp
    title: test/convolution/gcd_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/convolution/multiple_zmt.hpp\"\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n\ntemplate<typename mint>\nvoid multiple_zmt(vector<mint>\
    \ &f, bool moebius = false) {\n    int n = f.size();\n    vector<bool> sieve(n,\
    \ true);\n    for (int i = 2; i < n; i++) {\n        if (sieve[i]) {\n       \
    \     if (moebius) {\n                for (int j = 1; i * j < n; j++) {\n    \
    \                sieve[i * j] = false;\n                    f[j] -= f[i * j];\n\
    \                }\n            } else {\n                for (int j = (n - 1)\
    \ / i; j > 0; j--) {\n                    sieve[i * j] = false;\n            \
    \        f[j] += f[i * j];\n                }\n            }\n        }\n    }\n\
    }\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename mint>\nvoid multiple_zmt(vector<mint> &f, bool moebius = false)\
    \ {\n    int n = f.size();\n    vector<bool> sieve(n, true);\n    for (int i =\
    \ 2; i < n; i++) {\n        if (sieve[i]) {\n            if (moebius) {\n    \
    \            for (int j = 1; i * j < n; j++) {\n                    sieve[i *\
    \ j] = false;\n                    f[j] -= f[i * j];\n                }\n    \
    \        } else {\n                for (int j = (n - 1) / i; j > 0; j--) {\n \
    \                   sieve[i * j] = false;\n                    f[j] += f[i * j];\n\
    \                }\n            }\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/convolution/multiple_zmt.hpp
  requiredBy:
  - src/convolution/gcd_convolution.hpp
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/convolution/gcd_convolution.test.cpp
documentation_of: src/convolution/multiple_zmt.hpp
layout: document
redirect_from:
- /library/src/convolution/multiple_zmt.hpp
- /library/src/convolution/multiple_zmt.hpp.html
title: src/convolution/multiple_zmt.hpp
---
