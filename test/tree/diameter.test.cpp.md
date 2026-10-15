---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/tree/diameter.hpp
    title: src/tree/diameter.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/tree/diameter.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\
    \n\n#line 2 \"src/tree/diameter.hpp\"\n#include <algorithm>\n#include <limits>\n\
    #include <queue>\n#include <utility>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename T>\npair<T, vector<int>> diameter(const vector<vector<pair<int,\
    \ T>>> &g) {\n    int n = g.size();\n    const T inf = numeric_limits<T>::max()\
    \ / 2;\n    auto bfs = [&](int root) -> vector<T> {\n        vector<T> dist(n,\
    \ inf);\n        dist[root] = 0;\n        queue<int> q;\n        q.push(root);\n\
    \        while (q.size()) {\n            int u = q.front();\n            q.pop();\n\
    \            for (auto[v, w] : g[u]) {\n                if (dist[v] > dist[u]\
    \ + w) {\n                    dist[v] = dist[u] + w;\n                    q.push(v);\n\
    \                }\n            }\n        }\n        return dist;\n    };\n \
    \   vector<T> d0 = bfs(0);\n    int l = max_element(d0.begin(), d0.end()) - d0.begin();\n\
    \    vector<T> dl = bfs(l);\n    int r = max_element(dl.begin(), dl.end()) - dl.begin();\n\
    \    T diam = dl[r];\n    vector<int> path = {r};\n    while (r != l) {\n    \
    \    for (auto[v, w] : g[r]) {\n            if (dl[v] + w == dl[r]) {\n      \
    \          r = v;\n                break;\n            }\n        }\n        path.emplace_back(r);\n\
    \    }\n    return make_pair(diam, path);\n}\n\npair<int, vector<int>> diameter(const\
    \ vector<vector<int>> &g) {\n    int n = g.size();\n    vector<vector<pair<int,\
    \ int>>> tmp(n);\n    for (int u = 0; u < n; u++) {\n        for (int v : g[u])\
    \ {\n            tmp[u].emplace_back(v, 1);\n        }\n    }\n    return diameter(tmp);\n\
    }\n#line 4 \"test/tree/diameter.test.cpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N;\n   \
    \ cin >> N;\n    vector<vector<pair<int, long long>>> G(N);\n    for (int i =\
    \ 1, a, b, c; i < N; i++) {\n        cin >> a >> b >> c;\n        G[a].emplace_back(b,\
    \ c);\n        G[b].emplace_back(a, c);\n    }\n    auto [W, P] = diameter(G);\n\
    \    cout << W << ' ' << P.size() << '\\n';\n    for (int i = 0; i < ssize(P);\
    \ i++) cout << P[i] << \" \\n\"[i + 1 == ssize(P)];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ \"../../src/tree/diameter.hpp\"\n\n#include <iostream>\n\nint main() {\n   \
    \ ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N;\n    cin >>\
    \ N;\n    vector<vector<pair<int, long long>>> G(N);\n    for (int i = 1, a, b,\
    \ c; i < N; i++) {\n        cin >> a >> b >> c;\n        G[a].emplace_back(b,\
    \ c);\n        G[b].emplace_back(a, c);\n    }\n    auto [W, P] = diameter(G);\n\
    \    cout << W << ' ' << P.size() << '\\n';\n    for (int i = 0; i < ssize(P);\
    \ i++) cout << P[i] << \" \\n\"[i + 1 == ssize(P)];\n}"
  dependsOn:
  - src/tree/diameter.hpp
  isVerificationFile: true
  path: test/tree/diameter.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:06:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/diameter.test.cpp
layout: document
redirect_from:
- /verify/test/tree/diameter.test.cpp
- /verify/test/tree/diameter.test.cpp.html
title: test/tree/diameter.test.cpp
---
