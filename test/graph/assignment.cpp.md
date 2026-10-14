---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/graph/assignment.hpp
    title: src/graph/assignment.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"test/graph/assignment.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\
    \n\n#line 2 \"src/graph/assignment.hpp\"\n#include <numeric>\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename T>\nvector<int> hungarian(const vector<vector<T>>\
    \ &a) {\n    if (a.empty()) return {};\n    const T inf = numeric_limits<T>::max();\n\
    \    int h = a.size(), w = a[0].size();\n    vector<int> p(w), way(w);\n    vector<T>\
    \ u(h, T(0)), v(w, T(0)), min_v;\n    vector<bool> used;\n    for (int r = 1;\
    \ r < h; r++) {\n        p[0] = r;\n        min_v = vector<T>(w, inf);\n     \
    \   used = vector<bool>(w, false);\n        int j = 0;\n        while (p[j] !=\
    \ 0) {\n            int i = p[j], k = 0;\n            used[j] = true;\n      \
    \      T d = inf;\n            for (int c = 1; c < w; c++) {\n               \
    \ if (used[c]) continue;\n                T cur = a[i][c] - u[i] - v[c];\n   \
    \             if (cur < min_v[c]) min_v[c] = cur, way[c] = j;\n              \
    \  if (min_v[c] < d) d = min_v[c], k = c;\n            }\n            for (int\
    \ c = 0; c < w; c++) {\n                if (used[c]) u[p[c]] += d, v[c] -= d;\n\
    \                else min_v[c] -= d;\n            }\n            j = k;\n    \
    \    }\n        do {\n            p[j] = p[way[j]];\n            j = way[j];\n\
    \        } while (j != 0);\n    }\n    vector<int> res(w - 1);\n    for (int i\
    \ = 0; i < w - 1; i++) res[i] = p[i + 1] - 1;\n    return res;\n}\n\ntemplate<typename\
    \ T>\nvector<int> assignment(const vector<vector<T>> &a) {\n    int h = a.size(),\
    \ w = a[0].size();\n    vector<vector<T>> b(h + 1, vector<T>(w + 1, 0));\n   \
    \ for (int i = 0; i < h; i++) {\n        for (int j = 0; j < w; j++) b[i + 1][j\
    \ + 1] = a[i][j];\n    }\n    return hungarian(b);\n}\n#line 4 \"test/graph/assignment.cpp\"\
    \n\n#include <iostream>\nusing namespace std;\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    int N;\n    cin >> N;\n    vector<vector<long long>>\
    \ A(N, vector<long long>(N));\n    for (int i = 0; i < N; i++) {\n        for\
    \ (int j = 0; j < N; j++) cin >> A[i][j];\n    }\n    auto P = assignment(A);\n\
    \    long long sum = 0;\n    for (int i = 0; i < N; i++) sum += A[i][P[i]];\n\
    \    cout << sum << '\\n';\n    for (int i = 0; i < N; i++) cout << A[i][P[i]]\
    \ << \" \\n\"[i + 1 == N];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n\n#include\
    \ \"../../src/graph/assignment.hpp\"\n\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N;\n    cin >> N;\n    vector<vector<long long>> A(N, vector<long long>(N));\n\
    \    for (int i = 0; i < N; i++) {\n        for (int j = 0; j < N; j++) cin >>\
    \ A[i][j];\n    }\n    auto P = assignment(A);\n    long long sum = 0;\n    for\
    \ (int i = 0; i < N; i++) sum += A[i][P[i]];\n    cout << sum << '\\n';\n    for\
    \ (int i = 0; i < N; i++) cout << A[i][P[i]] << \" \\n\"[i + 1 == N];\n}"
  dependsOn:
  - src/graph/assignment.hpp
  isVerificationFile: false
  path: test/graph/assignment.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:06:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/graph/assignment.cpp
layout: document
redirect_from:
- /library/test/graph/assignment.cpp
- /library/test/graph/assignment.cpp.html
title: test/graph/assignment.cpp
---
