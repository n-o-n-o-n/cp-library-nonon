---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/number_theory/extended_gcd.hpp
    title: src/math/number_theory/extended_gcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=jp
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=jp
  bundledCode: "#line 1 \"test/math/number_theory/extended_gcd.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=jp\"\
    \n\n#line 2 \"src/math/number_theory/extended_gcd.hpp\"\n#include <utility>\n\
    using namespace std;\n\n// find x, y s.t. ax + by = gcd(a, b) and return gcd(a,\
    \ b)\ntemplate<typename T>\nT extended_gcd(T a, T b, T &x, T &y) {\n    T g =\
    \ a;\n    if (b != 0) {\n        g = extended_gcd(b, a % b, y, x);\n        y\
    \ -= (a / b) * x;\n    } else {\n        x = 1;\n        y = 0;\n    }\n    return\
    \ g;\n}\n#line 4 \"test/math/number_theory/extended_gcd.test.cpp\"\n\n#include\
    \ <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int A, B, X, Y;\n    cin >> A >> B >> X >> Y;\n    extended_gcd(A, B, X,\
    \ Y);\n    cout << X << ' ' << Y << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=jp\"\
    \n\n#include \"../../../src/math/number_theory/extended_gcd.hpp\"\n\n#include\
    \ <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int A, B, X, Y;\n    cin >> A >> B >> X >> Y;\n    extended_gcd(A, B, X,\
    \ Y);\n    cout << X << ' ' << Y << '\\n';\n}"
  dependsOn:
  - src/math/number_theory/extended_gcd.hpp
  isVerificationFile: true
  path: test/math/number_theory/extended_gcd.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:06:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/number_theory/extended_gcd.test.cpp
layout: document
redirect_from:
- /verify/test/math/number_theory/extended_gcd.test.cpp
- /verify/test/math/number_theory/extended_gcd.test.cpp.html
title: test/math/number_theory/extended_gcd.test.cpp
---
