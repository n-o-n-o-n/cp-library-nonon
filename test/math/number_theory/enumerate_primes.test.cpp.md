---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/number_theory/enumerate_primes.hpp
    title: src/math/number_theory/enumerate_primes.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/number_theory/primality_table.hpp
    title: src/math/number_theory/primality_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/math/number_theory/enumerate_primes.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#line 2 \"src/math/number_theory/enumerate_primes.hpp\"\
    \n#include <algorithm>\n#include <vector>\n#line 3 \"src/math/number_theory/primality_table.hpp\"\
    \nusing namespace std;\n\nvector<bool> primality_table(int n) {\n    vector<bool>\
    \ res(n + 1, true);\n    res[0] = res[1] = false;\n    for (int i = 2; i <= n;\
    \ i++) {\n        if (res[i]) {\n            for (int j = i + i; j <= n; j +=\
    \ i) res[j] = false;\n        }\n    }\n    return res;\n}\n#line 5 \"src/math/number_theory/enumerate_primes.hpp\"\
    \nusing namespace std;\n\nvector<int> enumerate_primes(int n) {\n    auto tbl\
    \ = primality_table(n);\n    vector<int> res;\n    res.reserve(count(tbl.begin(),\
    \ tbl.end(), true));\n    for (int i = 2; i <= n; i++) {\n        if (tbl[i])\
    \ res.emplace_back(i);\n    }\n    return res;\n}\n#line 4 \"test/math/number_theory/enumerate_primes.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N, A, B;\n    cin >> N >> A >> B;\n    auto P =\
    \ enumerate_primes(N);\n    vector<int> ans;\n    ans.reserve((int)1e6);\n   \
    \ for (int i = B; i < ssize(P); i += A) ans.push_back(P[i]);\n    cout << P.size()\
    \ << ' ' << ans.size() << '\\n';\n    for (int i = 0; i < ssize(ans); i++) cout\
    \ << ans[i] << \" \\n\"[i + 1 == ssize(ans)];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include \"../../../src/math/number_theory/enumerate_primes.hpp\"\n\n#include\
    \ <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N, A, B;\n    cin >> N >> A >> B;\n    auto P = enumerate_primes(N);\n\
    \    vector<int> ans;\n    ans.reserve((int)1e6);\n    for (int i = B; i < ssize(P);\
    \ i += A) ans.push_back(P[i]);\n    cout << P.size() << ' ' << ans.size() << '\\\
    n';\n    for (int i = 0; i < ssize(ans); i++) cout << ans[i] << \" \\n\"[i + 1\
    \ == ssize(ans)];\n}"
  dependsOn:
  - src/math/number_theory/enumerate_primes.hpp
  - src/math/number_theory/primality_table.hpp
  isVerificationFile: true
  path: test/math/number_theory/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:06:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/number_theory/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/test/math/number_theory/enumerate_primes.test.cpp
- /verify/test/math/number_theory/enumerate_primes.test.cpp.html
title: test/math/number_theory/enumerate_primes.test.cpp
---
