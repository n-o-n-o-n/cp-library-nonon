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
  bundledCode: "#line 2 \"src/monoid/arithmetic_add_range_sum.hpp\"\n#include <limits>\n\
    using namespace std;\n\n// apply(l, r, F(a, b)): for i in [l, r); v[i] += a *\
    \ i + b\n// If you want to apply it for i in [0, k); v[i + l] += a * i + b,\n\
    // you should use apply(l, r, F(a, b - a * l))\ntemplate<typename T>\nstruct arithmetic_add_range_sum\
    \ {\n    static constexpr int inf = numeric_limits<int>::max() / 2;\n    struct\
    \ S {\n        T sm;\n        int l, r;\n        T sum() const { return sm; }\n\
    \        S() : S(0, inf, -inf) {}\n        S(T x, int p) : S(x, p, p + 1) {}\n\
    \        S(T _sm, int _l, int _r) : sm(_sm), l(_l), r(_r) {}\n    };\n    static\
    \ S op(const S&a, const S &b) {\n        S c;\n        c.sm = a.sum() + b.sum();\n\
    \        c.l = min(a.l, b.l);\n        c.r = max(a.r, b.r);\n        return c;\n\
    \    }\n    static S e() {\n        return S();\n    }\n    struct F {\n     \
    \   T a, b;\n        F() : F(0, 0) {}\n        F(T _a, T _b) : a(_a), b(_b) {}\n\
    \    };\n    static F comp(const F &f, const F &g) {\n        return F(f.a + g.a,\
    \ f.b + g.b);\n    }\n    static F id() {\n        return F();\n    }\n    static\
    \ S map(const F &f, const S &x) {\n        S y;\n        y.sm = x.sm + (f.a *\
    \ (x.l + x.r - 1) + f.b * 2) * (x.r - x.l) / 2;\n        y.l = x.l;\n        y.r\
    \ = x.r;\n        return y;\n    }\n};\n"
  code: "#pragma once\n#include <limits>\nusing namespace std;\n\n// apply(l, r, F(a,\
    \ b)): for i in [l, r); v[i] += a * i + b\n// If you want to apply it for i in\
    \ [0, k); v[i + l] += a * i + b,\n// you should use apply(l, r, F(a, b - a * l))\n\
    template<typename T>\nstruct arithmetic_add_range_sum {\n    static constexpr\
    \ int inf = numeric_limits<int>::max() / 2;\n    struct S {\n        T sm;\n \
    \       int l, r;\n        T sum() const { return sm; }\n        S() : S(0, inf,\
    \ -inf) {}\n        S(T x, int p) : S(x, p, p + 1) {}\n        S(T _sm, int _l,\
    \ int _r) : sm(_sm), l(_l), r(_r) {}\n    };\n    static S op(const S&a, const\
    \ S &b) {\n        S c;\n        c.sm = a.sum() + b.sum();\n        c.l = min(a.l,\
    \ b.l);\n        c.r = max(a.r, b.r);\n        return c;\n    }\n    static S\
    \ e() {\n        return S();\n    }\n    struct F {\n        T a, b;\n       \
    \ F() : F(0, 0) {}\n        F(T _a, T _b) : a(_a), b(_b) {}\n    };\n    static\
    \ F comp(const F &f, const F &g) {\n        return F(f.a + g.a, f.b + g.b);\n\
    \    }\n    static F id() {\n        return F();\n    }\n    static S map(const\
    \ F &f, const S &x) {\n        S y;\n        y.sm = x.sm + (f.a * (x.l + x.r -\
    \ 1) + f.b * 2) * (x.r - x.l) / 2;\n        y.l = x.l;\n        y.r = x.r;\n \
    \       return y;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/monoid/arithmetic_add_range_sum.hpp
  requiredBy: []
  timestamp: '2025-06-26 18:47:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/monoid/arithmetic_add_range_sum.hpp
layout: document
redirect_from:
- /library/src/monoid/arithmetic_add_range_sum.hpp
- /library/src/monoid/arithmetic_add_range_sum.hpp.html
title: src/monoid/arithmetic_add_range_sum.hpp
---
