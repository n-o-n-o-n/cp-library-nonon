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
  bundledCode: "#line 2 \"src/monoid/arithmetic_update_range_sum.hpp\"\n#include <limits>\n\
    using namespace std;\n\ntemplate<typename mint>\nstruct arithmetic_update_range_sum\
    \ {\n    static constexpr int inf = numeric_limits<int>::max() / 2;\n    struct\
    \ S {\n        mint sm;\n        int l, r;\n        mint sum() const { return\
    \ sm; }\n        S() : S(0, numeric_limits<int>::max(), -numeric_limits<int>::max())\
    \ {}\n        S(mint x, int p) : S(x, p, p + 1) {}\n        S(mint _sm, int _l,\
    \ int _r) : sm(_sm), l(_l), r(_r) {}\n    };\n    static S op(const S &a, const\
    \ S &b) {\n        S c;\n        c.sm = a.sum() + b.sum();\n        c.l = min(a.l,\
    \ b.l);\n        c.r = max(a.r, b.r);\n        return c;\n    }\n    static S\
    \ e() {\n        return S();\n    }\n    struct F {\n        mint a, b;\n    \
    \    F() : F(0, 0) {}\n        F(T _a, T _b) : a(_a), b(_b) {}\n        bool operator==(F\
    \ f) {\n            return a == f.a && b == f.b;\n        }\n    };\n    static\
    \ F comp(const F &f, const F &g) {\n        return f == id() ? g : f;\n    }\n\
    \    static F id() {\n        return F();\n    }\n    static S mapping(const F\
    \ &f, const S &x) {\n        if (f == id()) return x;\n        S y;\n        y.sm\
    \ = (f.a * (x.l + x.r - 1) + f.b * 2) * (x.r - x.l) / 2;\n        y.l = x.l;\n\
    \        y.r = x.r;\n        return y;\n    }\n};\n"
  code: "#pragma once\n#include <limits>\nusing namespace std;\n\ntemplate<typename\
    \ mint>\nstruct arithmetic_update_range_sum {\n    static constexpr int inf =\
    \ numeric_limits<int>::max() / 2;\n    struct S {\n        mint sm;\n        int\
    \ l, r;\n        mint sum() const { return sm; }\n        S() : S(0, numeric_limits<int>::max(),\
    \ -numeric_limits<int>::max()) {}\n        S(mint x, int p) : S(x, p, p + 1) {}\n\
    \        S(mint _sm, int _l, int _r) : sm(_sm), l(_l), r(_r) {}\n    };\n    static\
    \ S op(const S &a, const S &b) {\n        S c;\n        c.sm = a.sum() + b.sum();\n\
    \        c.l = min(a.l, b.l);\n        c.r = max(a.r, b.r);\n        return c;\n\
    \    }\n    static S e() {\n        return S();\n    }\n    struct F {\n     \
    \   mint a, b;\n        F() : F(0, 0) {}\n        F(T _a, T _b) : a(_a), b(_b)\
    \ {}\n        bool operator==(F f) {\n            return a == f.a && b == f.b;\n\
    \        }\n    };\n    static F comp(const F &f, const F &g) {\n        return\
    \ f == id() ? g : f;\n    }\n    static F id() {\n        return F();\n    }\n\
    \    static S mapping(const F &f, const S &x) {\n        if (f == id()) return\
    \ x;\n        S y;\n        y.sm = (f.a * (x.l + x.r - 1) + f.b * 2) * (x.r -\
    \ x.l) / 2;\n        y.l = x.l;\n        y.r = x.r;\n        return y;\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/monoid/arithmetic_update_range_sum.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/monoid/arithmetic_update_range_sum.hpp
layout: document
redirect_from:
- /library/src/monoid/arithmetic_update_range_sum.hpp
- /library/src/monoid/arithmetic_update_range_sum.hpp.html
title: src/monoid/arithmetic_update_range_sum.hpp
---
