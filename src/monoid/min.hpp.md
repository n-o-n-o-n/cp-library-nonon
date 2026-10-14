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
  bundledCode: "#line 2 \"src/monoid/min.hpp\"\n#include <algorithm>\n#include <limits>\n\
    using namespace std;\n\ntemplate <typename T, T E = numeric_limits<T>::max()>\n\
    struct min_monoid {\n    using S = T;\n    static S op(const S &a, const S &b)\
    \ {\n        return min(a, b);\n    }\n    static S e() { return E; }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\nusing namespace std;\n\
    \ntemplate <typename T, T E = numeric_limits<T>::max()>\nstruct min_monoid {\n\
    \    using S = T;\n    static S op(const S &a, const S &b) {\n        return min(a,\
    \ b);\n    }\n    static S e() { return E; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/monoid/min.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/monoid/min.hpp
layout: document
redirect_from:
- /library/src/monoid/min.hpp
- /library/src/monoid/min.hpp.html
title: src/monoid/min.hpp
---
