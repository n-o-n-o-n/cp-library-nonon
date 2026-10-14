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
  bundledCode: "#line 2 \"src/monoid/range_add_range_min.hpp\"\n#include <algorithm>\n\
    #include <limits>\nusing namespace std;\n\ntemplate<typename T, T E = numeric_limits<T>::max()>\n\
    struct range_add_range_min {\n    using S = T;\n    static S op(const S &a, const\
    \ S &b) {\n        return min(a, b);\n    }\n    static S e() { return E; }\n\
    \    using F = T;\n    static F comp(const F &f, const F &g) {\n        return\
    \ f + g;\n    }\n    static F id() { return 0; }\n    static F map(const F &f,\
    \ const S &x) {\n        return f + x;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\nusing namespace std;\n\
    \ntemplate<typename T, T E = numeric_limits<T>::max()>\nstruct range_add_range_min\
    \ {\n    using S = T;\n    static S op(const S &a, const S &b) {\n        return\
    \ min(a, b);\n    }\n    static S e() { return E; }\n    using F = T;\n    static\
    \ F comp(const F &f, const F &g) {\n        return f + g;\n    }\n    static F\
    \ id() { return 0; }\n    static F map(const F &f, const S &x) {\n        return\
    \ f + x;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/monoid/range_add_range_min.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/monoid/range_add_range_min.hpp
layout: document
redirect_from:
- /library/src/monoid/range_add_range_min.hpp
- /library/src/monoid/range_add_range_min.hpp.html
title: src/monoid/range_add_range_min.hpp
---
