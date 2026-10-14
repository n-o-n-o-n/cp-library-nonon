---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/tree/cartesian_tree.hpp
    title: src/tree/cartesian_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"test/tree/cartesian_tree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#line 2 \"src/tree/cartesian_tree.hpp\"\
    \n#include <stack>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ T>\nvector<int> cartesian_tree(const vector<T> &a) {\n    int n = a.size();\n\
    \    vector<int> p(n, -1);\n    stack<int> st;\n    for (int i = 0, j; i < n;\
    \ i++) {\n        j = -1;\n        while (st.size() && a[st.top()] >= a[i]) {\n\
    \            j = st.top();\n            st.pop();\n        }\n        if (st.size())\
    \ p[i] = st.top();\n        if (j != -1) p[j] = i;\n        st.push(i);\n    }\n\
    \    return p;\n}\n#line 4 \"test/tree/cartesian_tree.test.cpp\"\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N;\n    cin >> N;\n    vector<int> A(N);\n    for (auto &e : A) cin >> e;\n\
    \    auto P = cartesian_tree(A);\n    for (int i = 0; i < N; i++) cout << (P[i]\
    \ == -1 ? i : P[i]) << \" \\n\"[i + 1 == N];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include\
    \ \"../../src/tree/cartesian_tree.hpp\"\n\n#include <iostream>\n\nint main() {\n\
    \    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N;\n    cin\
    \ >> N;\n    vector<int> A(N);\n    for (auto &e : A) cin >> e;\n    auto P =\
    \ cartesian_tree(A);\n    for (int i = 0; i < N; i++) cout << (P[i] == -1 ? i\
    \ : P[i]) << \" \\n\"[i + 1 == N];\n}"
  dependsOn:
  - src/tree/cartesian_tree.hpp
  isVerificationFile: true
  path: test/tree/cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:06:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/test/tree/cartesian_tree.test.cpp
- /verify/test/tree/cartesian_tree.test.cpp.html
title: test/tree/cartesian_tree.test.cpp
---
