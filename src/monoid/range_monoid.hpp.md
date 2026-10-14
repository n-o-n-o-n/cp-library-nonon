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
  bundledCode: "#line 2 \"src/monoid/range_monoid.hpp\"\ntemplate<typename Monoid>\n\
    struct range_monoid {\n    struct S {\n        Monoid::S x;\n        int size;\n\
    \        Monoid::S val() const { return x; }\n        S() : S(Monoid::e(), 0)\
    \ {}\n        S(const Monoid::S &y) : S(y ,1) {}\n        S(const Monoid::S &y,\
    \ int t) : x(y), size(t) {}\n    };\n    static S op(const S &a, const S &b) {\n\
    \        return S(Monoid::op(a.x, b.x), a.size + b.size);\n    }\n    static S\
    \ e() { return S(Monoid::e(), 0); }\n};\n"
  code: "#pragma once\ntemplate<typename Monoid>\nstruct range_monoid {\n    struct\
    \ S {\n        Monoid::S x;\n        int size;\n        Monoid::S val() const\
    \ { return x; }\n        S() : S(Monoid::e(), 0) {}\n        S(const Monoid::S\
    \ &y) : S(y ,1) {}\n        S(const Monoid::S &y, int t) : x(y), size(t) {}\n\
    \    };\n    static S op(const S &a, const S &b) {\n        return S(Monoid::op(a.x,\
    \ b.x), a.size + b.size);\n    }\n    static S e() { return S(Monoid::e(), 0);\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/monoid/range_monoid.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/monoid/range_monoid.hpp
layout: document
redirect_from:
- /library/src/monoid/range_monoid.hpp
- /library/src/monoid/range_monoid.hpp.html
title: src/monoid/range_monoid.hpp
---
