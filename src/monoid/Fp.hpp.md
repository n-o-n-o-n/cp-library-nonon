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
  bundledCode: "#line 2 \"src/monoid/Fp.hpp\"\nusing namespace std;\n\nstruct Fp_64\
    \ {\n    using S = long long;\n    using F = long long;\n    static long long\
    \ m;\n    static void set_mod(long long _m) { m = _m; }\n    static F comp(F f,\
    \ F g) {\n        return (__int128_t(f) * g) % m;\n    }\n    static F id() {\n\
    \        return m == 1 ? 0 : 1;\n    }\n    static S mapping(F f, S x) {\n   \
    \     return (__int128_t(f) * x) % m;\n    }\n};\nlong long Fp_64::m = 0;\n"
  code: "#pragma once\nusing namespace std;\n\nstruct Fp_64 {\n    using S = long\
    \ long;\n    using F = long long;\n    static long long m;\n    static void set_mod(long\
    \ long _m) { m = _m; }\n    static F comp(F f, F g) {\n        return (__int128_t(f)\
    \ * g) % m;\n    }\n    static F id() {\n        return m == 1 ? 0 : 1;\n    }\n\
    \    static S mapping(F f, S x) {\n        return (__int128_t(f) * x) % m;\n \
    \   }\n};\nlong long Fp_64::m = 0;"
  dependsOn: []
  isVerificationFile: false
  path: src/monoid/Fp.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/monoid/Fp.hpp
layout: document
redirect_from:
- /library/src/monoid/Fp.hpp
- /library/src/monoid/Fp.hpp.html
title: src/monoid/Fp.hpp
---
