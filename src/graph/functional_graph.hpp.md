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
  bundledCode: "#line 2 \"src/graph/functional_graph.hpp\"\n#include <cassert>\n#include\
    \ <vector>\nusing namespace std;\n\nstruct functional_graph {\n    functional_graph(int\
    \ _n) : functional_graph(vector<int>(_n, -1)) {}\n    functional_graph(const vector<int>\
    \ &a) : n(a.size()), f(1, a) {}\n    void add_edge(int u, int v) {\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        assert(f[0][u] ==\
    \ -1);\n        f[0][u] = v;\n    }\n    int steps(int u, long long k) {\n   \
    \     assert(0 <= u && u < n);\n        doubling(k);\n        for (int i = 0;\
    \ (1LL << i) <= k; i++) {\n            if (k >> i & 1) u = f[i][u];\n        }\n\
    \        return u;\n    }\n    vector<int> table(long long k) {\n        doubling(k);\n\
    \        vector<int> g(n);\n        iota(g.begin(), g.end(), 0);\n        for\
    \ (int i = 0; (1LL << i) <= k; i++) {\n            if (k >> i & 1) {\n       \
    \         for (int j = 0; j < n; j++) {\n                    g[j] = f[i][g[j]];\n\
    \                }\n            }\n        }\n        return g;\n    }\n    template<typename\
    \ C>\n    pair<int, int> binary_search(int u, const C &check) {\n        assert(0\
    \ <= u && u < n);\n        assert(check(u));\n        doubling(n + 1);\n     \
    \   int k = 0;\n        while ((1 << k) <= n) k++;\n        int r = 0;\n     \
    \   for (k-- ; k >= 0; k--) {\n            int v = f[k][u];\n            if (check(v))\
    \ u = v, r += 1 << k;\n        }\n        return make_pair(r, u);\n    }\nprivate:\n\
    \    int n;\n    vector<vector<int>> f;\n    void doubling(long long k) {\n  \
    \      while (1LL << int(f.size()) <= k) {\n            vector<int> tf(n);\n \
    \           const vector<int> &g = f.back();\n            for (int i = 0; i <\
    \ n; i++) tf[i] = g[g[i]];\n            f.push_back(tf);\n        }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \nstruct functional_graph {\n    functional_graph(int _n) : functional_graph(vector<int>(_n,\
    \ -1)) {}\n    functional_graph(const vector<int> &a) : n(a.size()), f(1, a) {}\n\
    \    void add_edge(int u, int v) {\n        assert(0 <= u && u < n);\n       \
    \ assert(0 <= v && v < n);\n        assert(f[0][u] == -1);\n        f[0][u] =\
    \ v;\n    }\n    int steps(int u, long long k) {\n        assert(0 <= u && u <\
    \ n);\n        doubling(k);\n        for (int i = 0; (1LL << i) <= k; i++) {\n\
    \            if (k >> i & 1) u = f[i][u];\n        }\n        return u;\n    }\n\
    \    vector<int> table(long long k) {\n        doubling(k);\n        vector<int>\
    \ g(n);\n        iota(g.begin(), g.end(), 0);\n        for (int i = 0; (1LL <<\
    \ i) <= k; i++) {\n            if (k >> i & 1) {\n                for (int j =\
    \ 0; j < n; j++) {\n                    g[j] = f[i][g[j]];\n                }\n\
    \            }\n        }\n        return g;\n    }\n    template<typename C>\n\
    \    pair<int, int> binary_search(int u, const C &check) {\n        assert(0 <=\
    \ u && u < n);\n        assert(check(u));\n        doubling(n + 1);\n        int\
    \ k = 0;\n        while ((1 << k) <= n) k++;\n        int r = 0;\n        for\
    \ (k-- ; k >= 0; k--) {\n            int v = f[k][u];\n            if (check(v))\
    \ u = v, r += 1 << k;\n        }\n        return make_pair(r, u);\n    }\nprivate:\n\
    \    int n;\n    vector<vector<int>> f;\n    void doubling(long long k) {\n  \
    \      while (1LL << int(f.size()) <= k) {\n            vector<int> tf(n);\n \
    \           const vector<int> &g = f.back();\n            for (int i = 0; i <\
    \ n; i++) tf[i] = g[g[i]];\n            f.push_back(tf);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/functional_graph.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/functional_graph.hpp
layout: document
redirect_from:
- /library/src/graph/functional_graph.hpp
- /library/src/graph/functional_graph.hpp.html
title: src/graph/functional_graph.hpp
---
