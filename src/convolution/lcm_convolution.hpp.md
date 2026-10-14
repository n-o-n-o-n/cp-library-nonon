---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/convolution/divisor_zmt.hpp
    title: src/convolution/divisor_zmt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/convolution/lcm_convolution.test.cpp
    title: test/convolution/lcm_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/convolution/lcm_convolution.hpp\"\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n#line 4 \"src/convolution/divisor_zmt.hpp\"\
    \nusing namespace std;\n\ntemplate<typename mint>\nvoid divisor_zmt(vector<mint>\
    \ &f, bool moebius = false) {\n    int n = f.size();\n    vector<bool> sieve(n,\
    \ true);\n    for (int i = 2; i < n; i++) {\n        if (sieve[i]) {\n       \
    \     if (moebius) {\n                for (int j = (n - 1) / i; j > 0; j--) {\n\
    \                    sieve[i * j] = false;\n                    f[i * j] -= f[j];\n\
    \                }\n            } else {\n                for (int j = 1; i *\
    \ j < n; j++) {\n                    sieve[i * j] = false;\n                 \
    \   f[i * j] += f[j];\n                }\n            }\n        }\n    }\n}\n\
    #line 6 \"src/convolution/lcm_convolution.hpp\"\n\ntemplate<typename mint>\nvector<mint>\
    \ lcm_convolution(vector<mint> f, vector<mint> g) {\n    assert(f.size() == g.size());\n\
    \    int n = f.size();\n    if (n == 0) return {};\n    divisor_zmt(f);\n    divisor_zmt(g);\n\
    \    for (int i = 0; i < n; i++) f[i] *= g[i];\n    divisor_zmt(f, true);\n  \
    \  return f;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    #include \"divisor_zmt.hpp\"\n\ntemplate<typename mint>\nvector<mint> lcm_convolution(vector<mint>\
    \ f, vector<mint> g) {\n    assert(f.size() == g.size());\n    int n = f.size();\n\
    \    if (n == 0) return {};\n    divisor_zmt(f);\n    divisor_zmt(g);\n    for\
    \ (int i = 0; i < n; i++) f[i] *= g[i];\n    divisor_zmt(f, true);\n    return\
    \ f;\n}"
  dependsOn:
  - src/convolution/divisor_zmt.hpp
  isVerificationFile: false
  path: src/convolution/lcm_convolution.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/convolution/lcm_convolution.test.cpp
documentation_of: src/convolution/lcm_convolution.hpp
layout: document
redirect_from:
- /library/src/convolution/lcm_convolution.hpp
- /library/src/convolution/lcm_convolution.hpp.html
title: src/convolution/lcm_convolution.hpp
---
