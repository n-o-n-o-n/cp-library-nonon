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
  bundledCode: "#line 2 \"src/monoid/range_add_range_sum.hpp\"\n#include <utility>\n\
    using namespace std;\n\ntemplate<typename T>\nstruct range_add_range_sum {\n \
    \   using S = pair<T, int>;\n    static S op(S a, S b) {\n        a.first += b.first;\n\
    \        a.second += b.second;\n        return a;\n    }\n    static S e() { return\
    \ S{0, 0}; }\n    using F = T;\n    static F comp(F f, F g) { return f + g; }\n\
    \    static F id() { return 0; }\n    static S map(F f, S x) {\n        x.first\
    \ += f * x.second;\n        return x;\n    }\n};\n"
  code: "#pragma once\n#include <utility>\nusing namespace std;\n\ntemplate<typename\
    \ T>\nstruct range_add_range_sum {\n    using S = pair<T, int>;\n    static S\
    \ op(S a, S b) {\n        a.first += b.first;\n        a.second += b.second;\n\
    \        return a;\n    }\n    static S e() { return S{0, 0}; }\n    using F =\
    \ T;\n    static F comp(F f, F g) { return f + g; }\n    static F id() { return\
    \ 0; }\n    static S map(F f, S x) {\n        x.first += f * x.second;\n     \
    \   return x;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/monoid/range_add_range_sum.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/monoid/range_add_range_sum.hpp
layout: document
redirect_from:
- /library/src/monoid/range_add_range_sum.hpp
- /library/src/monoid/range_add_range_sum.hpp.html
title: src/monoid/range_add_range_sum.hpp
---
