---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/math/number_theory/enumerate_quotients.hpp
    title: src/math/number_theory/enumerate_quotients.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_quotients
    links:
    - https://judge.yosupo.jp/problem/enumerate_quotients
  bundledCode: "#line 1 \"test/math/number_theory/enumerate_quotient.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\n#line\
    \ 2 \"src/math/number_theory/enumerate_quotients.hpp\"\n#include <vector>\nusing\
    \ namespace std;\n\n// for all m in [l, r), floor(n/m) = q\ntemplate<typename\
    \ T>\nvector<tuple<T, T, T>> enumerate_quotients(T n) {\n    vector<tuple<T, T,\
    \ T>> res;\n    for (T l = 1, r, q; l <= n; l = r) {\n        q = n / l;\n   \
    \     r = n / q + 1;\n        res.emplace_back(l, r, q);\n    }\n    return res;\n\
    }\n#line 4 \"test/math/number_theory/enumerate_quotient.test.cpp\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    long long N;\n    cin >> N;\n    vector<long long>\
    \ ans;\n    for (auto [_, __, q] : enumerate_quotients(N)) ans.push_back(q);\n\
    \    reverse(ans.begin(), ans.end());\n    cout << ans.size() << '\\n';\n    for\
    \ (int i = 0; i < ssize(ans); i++) cout << ans[i] << \" \\n\"[i + 1 == ssize(ans)];\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\
    \n#include \"../../../src/math/number_theory/enumerate_quotients.hpp\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    long long N;\n    cin >> N;\n    vector<long long>\
    \ ans;\n    for (auto [_, __, q] : enumerate_quotients(N)) ans.push_back(q);\n\
    \    reverse(ans.begin(), ans.end());\n    cout << ans.size() << '\\n';\n    for\
    \ (int i = 0; i < ssize(ans); i++) cout << ans[i] << \" \\n\"[i + 1 == ssize(ans)];\n\
    }"
  dependsOn:
  - src/math/number_theory/enumerate_quotients.hpp
  isVerificationFile: true
  path: test/math/number_theory/enumerate_quotient.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:06:06+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/number_theory/enumerate_quotient.test.cpp
layout: document
redirect_from:
- /verify/test/math/number_theory/enumerate_quotient.test.cpp
- /verify/test/math/number_theory/enumerate_quotient.test.cpp.html
title: test/math/number_theory/enumerate_quotient.test.cpp
---
