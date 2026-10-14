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
  bundledCode: "#line 2 \"src/monoid/bracket.hpp\"\n#include <utility>\nusing namespace\
    \ std;\n\nstruct Bracket {\n    using S = pair<int, int>;\n    static S op(S a,\
    \ S b) {\n        int cumsum = a.first + b.first;\n        int cummin = min(a.second,\
    \ a.first + b.second);\n        return make_pair(cumsum, cummin);\n    }\n   \
    \ static S e() { return make_pair(0, 0); }\n    static S L() { return make_pair(1,\
    \ 0); }\n    static S R() { return make_pair(-1, -1); }\n    static S map(char\
    \ c) { return c == '(' ? L() : R(); }\n    static char flip(char c) { return c\
    \ == '(' ? ')' : '('; }\n};\n"
  code: "#pragma once\n#include <utility>\nusing namespace std;\n\nstruct Bracket\
    \ {\n    using S = pair<int, int>;\n    static S op(S a, S b) {\n        int cumsum\
    \ = a.first + b.first;\n        int cummin = min(a.second, a.first + b.second);\n\
    \        return make_pair(cumsum, cummin);\n    }\n    static S e() { return make_pair(0,\
    \ 0); }\n    static S L() { return make_pair(1, 0); }\n    static S R() { return\
    \ make_pair(-1, -1); }\n    static S map(char c) { return c == '(' ? L() : R();\
    \ }\n    static char flip(char c) { return c == '(' ? ')' : '('; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/monoid/bracket.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/monoid/bracket.hpp
layout: document
redirect_from:
- /library/src/monoid/bracket.hpp
- /library/src/monoid/bracket.hpp.html
title: src/monoid/bracket.hpp
---
