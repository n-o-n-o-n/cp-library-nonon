---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/convolution/fwht.hpp
    title: src/convolution/fwht.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/bitwise_xor_convolution.test.cpp
    title: test/convolution/bitwise_xor_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/convolution/bitwise_xor_convolution.hpp\"\n#include\
    \ <cassert>\n#include <vector>\nusing namespace std;\n#line 4 \"src/convolution/fwht.hpp\"\
    \nusing namespace std;\n\ntemplate<typename mint>\nvoid fwht(vector<mint> &f,\
    \ bool inv = false) {\n    int n = f.size();\n    assert((n & (n - 1)) == 0);\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n\
    \            if (i & j) continue;\n            mint s = f[j], t = f[i | j];\n\
    \            f[j] = s + t, f[i | j] = s - t;\n        }\n    }\n    if (inv) {\n\
    \        mint cef = mint(n).inv();\n        for (mint &c : f) c *= cef;\n    }\n\
    }\n#line 6 \"src/convolution/bitwise_xor_convolution.hpp\"\n\ntemplate<typename\
    \ mint>\nvector<mint> bitwise_xor_convolution(vector<mint> f, vector<mint> g)\
    \ {\n    assert(f.size() == g.size());\n    int n = f.size();\n    assert((n &\
    \ (n - 1)) == 0);\n    if (n == 0) return {};\n    fwht(f);\n    fwht(g);\n  \
    \  for (int i = 0; i < n; i++) f[i] *= g[i];\n    fwht(f, true);\n    return f;\n\
    }\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    #include \"fwht.hpp\"\n\ntemplate<typename mint>\nvector<mint> bitwise_xor_convolution(vector<mint>\
    \ f, vector<mint> g) {\n    assert(f.size() == g.size());\n    int n = f.size();\n\
    \    assert((n & (n - 1)) == 0);\n    if (n == 0) return {};\n    fwht(f);\n \
    \   fwht(g);\n    for (int i = 0; i < n; i++) f[i] *= g[i];\n    fwht(f, true);\n\
    \    return f;\n}"
  dependsOn:
  - src/convolution/fwht.hpp
  isVerificationFile: false
  path: src/convolution/bitwise_xor_convolution.hpp
  requiredBy: []
  timestamp: '2025-12-27 09:40:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/bitwise_xor_convolution.test.cpp
documentation_of: src/convolution/bitwise_xor_convolution.hpp
layout: document
redirect_from:
- /library/src/convolution/bitwise_xor_convolution.hpp
- /library/src/convolution/bitwise_xor_convolution.hpp.html
title: src/convolution/bitwise_xor_convolution.hpp
---
