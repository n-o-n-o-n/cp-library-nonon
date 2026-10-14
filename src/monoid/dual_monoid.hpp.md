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
  bundledCode: "#line 2 \"src/monoid/dual_monoid.hpp\"\n\ntemplate<typename Monoid>\n\
    struct dual_monoid {\n    using S = pair<typename Monoid::S, typename Monoid::S>;\n\
    \    static S op(const S &a, const S &b) {\n        return make_pair(Monoid::op(a.first,\
    \ b.first), Monoid::op(a.second, b.second));\n    }\n    static S e() {\n    \
    \    return make_pair(Monoid::e(), Monoid::e());\n    }\n};\n"
  code: "#pragma once\n\ntemplate<typename Monoid>\nstruct dual_monoid {\n    using\
    \ S = pair<typename Monoid::S, typename Monoid::S>;\n    static S op(const S &a,\
    \ const S &b) {\n        return make_pair(Monoid::op(a.first, b.first), Monoid::op(a.second,\
    \ b.second));\n    }\n    static S e() {\n        return make_pair(Monoid::e(),\
    \ Monoid::e());\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/monoid/dual_monoid.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/monoid/dual_monoid.hpp
layout: document
redirect_from:
- /library/src/monoid/dual_monoid.hpp
- /library/src/monoid/dual_monoid.hpp.html
title: src/monoid/dual_monoid.hpp
---
