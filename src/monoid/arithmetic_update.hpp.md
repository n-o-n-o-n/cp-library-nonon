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
  bundledCode: "#line 2 \"src/monoid/arithmetic_update.hpp\"\n#include <limits>\n\
    using namespace std;\n\ntemplate<typename T>\nstruct arithmetic_update {\n   \
    \ static constexpr T inf = numeric_limits<T>::max() / 2;\n    struct S {\n   \
    \     T mn, mx, sm;\n        int l, r;\n        T min() const { return mn; }\n\
    \        T max() const { return mx; }\n        T sum() const { return sm; }\n\
    \        S() : S(inf, -inf, 0, numeric_limits<int>::max(), -numeric_limits<int>::max())\
    \ {}\n        S(T x, int p) : S(x, x, x, p, p + 1) {}\n        S(T _mn, T _mx,\
    \ T _sm, int _l, int _r) : mn(_mn), mx(_mx), sm(_sm), l(_l), r(_r) {}\n    };\n\
    \    static S op(const S &a, const S &b) {\n        S c;\n        c.mn = min(a.min(),\
    \ b.min());\n        c.mx = max(a.max(), b.max());\n        c.sm = a.sum() + b.sum();\n\
    \        c.l = min(a.l, b.l);\n        c.r = max(a.r, b.r);\n        return c;\n\
    \    }\n    static S e() {\n        return S();\n    }\n    struct F {\n     \
    \   T a, b;\n        F() : F(inf, inf) {}\n        F(T _a, T _b) : a(_a), b(_b)\
    \ {}\n        bool operator==(F f) {\n            return a == f.a && b == f.b;\n\
    \        }\n    };\n    static F comp(const F &f, const F &g) {\n        return\
    \ f == id() ? g : f;\n    }\n    static F id() {\n        return F();\n    }\n\
    \    static S mapping(const F &f, const S &x) {\n        if (f == id()) return\
    \ x;\n        S y;\n        y.mn = min(f.a * x.l, f.a * (x.r - 1)) + f.b;\n  \
    \      y.mx = max(f.a * x.l, f.a * (x.r - 1)) + f.b;\n        y.sm = (f.a * (x.l\
    \ + x.r - 1) + f.b * 2) * (x.r - x.l) / 2;\n        y.l = x.l;\n        y.r =\
    \ x.r;\n        return y;\n    }\n};\n"
  code: "#pragma once\n#include <limits>\nusing namespace std;\n\ntemplate<typename\
    \ T>\nstruct arithmetic_update {\n    static constexpr T inf = numeric_limits<T>::max()\
    \ / 2;\n    struct S {\n        T mn, mx, sm;\n        int l, r;\n        T min()\
    \ const { return mn; }\n        T max() const { return mx; }\n        T sum()\
    \ const { return sm; }\n        S() : S(inf, -inf, 0, numeric_limits<int>::max(),\
    \ -numeric_limits<int>::max()) {}\n        S(T x, int p) : S(x, x, x, p, p + 1)\
    \ {}\n        S(T _mn, T _mx, T _sm, int _l, int _r) : mn(_mn), mx(_mx), sm(_sm),\
    \ l(_l), r(_r) {}\n    };\n    static S op(const S &a, const S &b) {\n       \
    \ S c;\n        c.mn = min(a.min(), b.min());\n        c.mx = max(a.max(), b.max());\n\
    \        c.sm = a.sum() + b.sum();\n        c.l = min(a.l, b.l);\n        c.r\
    \ = max(a.r, b.r);\n        return c;\n    }\n    static S e() {\n        return\
    \ S();\n    }\n    struct F {\n        T a, b;\n        F() : F(inf, inf) {}\n\
    \        F(T _a, T _b) : a(_a), b(_b) {}\n        bool operator==(F f) {\n   \
    \         return a == f.a && b == f.b;\n        }\n    };\n    static F comp(const\
    \ F &f, const F &g) {\n        return f == id() ? g : f;\n    }\n    static F\
    \ id() {\n        return F();\n    }\n    static S mapping(const F &f, const S\
    \ &x) {\n        if (f == id()) return x;\n        S y;\n        y.mn = min(f.a\
    \ * x.l, f.a * (x.r - 1)) + f.b;\n        y.mx = max(f.a * x.l, f.a * (x.r - 1))\
    \ + f.b;\n        y.sm = (f.a * (x.l + x.r - 1) + f.b * 2) * (x.r - x.l) / 2;\n\
    \        y.l = x.l;\n        y.r = x.r;\n        return y;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/monoid/arithmetic_update.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/monoid/arithmetic_update.hpp
layout: document
redirect_from:
- /library/src/monoid/arithmetic_update.hpp
- /library/src/monoid/arithmetic_update.hpp.html
title: src/monoid/arithmetic_update.hpp
---
