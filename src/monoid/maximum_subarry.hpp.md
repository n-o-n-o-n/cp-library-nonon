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
  bundledCode: "#line 2 \"src/monoid/maximum_subarry.hpp\"\n#include <algorithm>\n\
    #include <limits>\n\ntemplate<typename T>\nstruct maximum_subarray_monoid {\n\
    \    static constexpr T inf = numeric_limits<T>::max() / 2;\n    struct S {\n\
    \        T left, right, max, sum;\n        T val() const { return max; }\n   \
    \     S() : S(0) {}\n        S(T x) : S(x, x, x, x) {}\n        S(T l, T r, T\
    \ m, T s) : left(l), right(r), max(m), sum(s) {}\n    };\n    static S op(S a,\
    \ S b) {\n        T new_left = max(a.left, a.sum + b.left);\n        T new_right\
    \ = max(b.right, b.sum + a.right);\n        T new_max = max(max(a.max, b.max),\
    \ a.right + b.left);\n        T new_sum = a.sum + b.sum;\n        return S(new_left,\
    \ new_right, new_max, new_sum);\n    }\n    static S e() {\n        return S(-inf,\
    \ -inf, -inf, 0);\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n\ntemplate<typename\
    \ T>\nstruct maximum_subarray_monoid {\n    static constexpr T inf = numeric_limits<T>::max()\
    \ / 2;\n    struct S {\n        T left, right, max, sum;\n        T val() const\
    \ { return max; }\n        S() : S(0) {}\n        S(T x) : S(x, x, x, x) {}\n\
    \        S(T l, T r, T m, T s) : left(l), right(r), max(m), sum(s) {}\n    };\n\
    \    static S op(S a, S b) {\n        T new_left = max(a.left, a.sum + b.left);\n\
    \        T new_right = max(b.right, b.sum + a.right);\n        T new_max = max(max(a.max,\
    \ b.max), a.right + b.left);\n        T new_sum = a.sum + b.sum;\n        return\
    \ S(new_left, new_right, new_max, new_sum);\n    }\n    static S e() {\n     \
    \   return S(-inf, -inf, -inf, 0);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/monoid/maximum_subarry.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/monoid/maximum_subarry.hpp
layout: document
redirect_from:
- /library/src/monoid/maximum_subarry.hpp
- /library/src/monoid/maximum_subarry.hpp.html
title: src/monoid/maximum_subarry.hpp
---
