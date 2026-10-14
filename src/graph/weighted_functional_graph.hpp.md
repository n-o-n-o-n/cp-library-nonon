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
  bundledCode: "#line 2 \"src/graph/weighted_functional_graph.hpp\"\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n\ntemplate<typename Monoid, bool edge>\n\
    struct weighted_functional_graph {\n    using M = Monoid;\n    using S = typename\
    \ M::S;\n    weighted_functional_graph(int _n) : weighted_functional_graph(vector<int>(_n,\
    \ -1), vector<S>(_n, M::e())) {}\n    weighted_functional_graph(const vector<int>\
    \ &a, const vector<S> &w) : n(a.size()), f(1, a), d(1, w) {}\n    void add_edge(int\
    \ u, int v, const S &w = M::e()) {\n        assert(0 <= u && u < n);\n       \
    \ assert(0 <= v && v < n);\n        assert(f[0][u] == -1);\n        f[0][u] =\
    \ v;\n        if (edge) d[0][u] = w;\n    }\n    void set(int u, S x) {\n    \
    \    assert(!edge);\n        assert(0 <= u && u < n);\n        d[0][u] = x;\n\
    \    }\n    pair<int, S> steps(int u, long long k) {\n        assert(0 <= u &&\
    \ u < n);\n        doubling(k);\n        S p = M::e();\n        for (int i = 0;\
    \ (1LL << i) <= k; i++) {\n            if (k >> i & 1) {\n                p =\
    \ M::op(p, d[i][u]);\n                u = f[i][u];\n            }\n        }\n\
    \        if (!edge) p = M::op(p, d[0][u]);\n        return make_pair(u, p);\n\
    \    }\n    template<typename C>\n    pair<int, S> binary_search(int u, long long\
    \ k, const C &check) {\n        assert(0 <= u && u < n);\n        assert(check(M::e()));\n\
    \        doubling(k);\n        int r = 0;\n        while ((1LL << r) <= k) r++;\n\
    \        S p = M::e();\n        for (r-- ; r >= 0; r--) {\n            S np =\
    \ M::op(p, d[r][u]);\n            if ((1LL << r) <= k && check(np)) {\n      \
    \          u = f[r][u];\n                p = np;\n                k -= 1LL <<\
    \ r;\n            }\n        }\n        return make_pair(u, p);\n    }\nprivate:\n\
    \    int n;\n    vector<vector<int>> f;\n    vector<vector<S>> d;\n    void doubling(long\
    \ long k) {\n        while (1LL << int(f.size()) <= k) {\n            vector<int>\
    \ tf(n);\n            vector<S> td(n);\n            const vector<int> &g = f.back();\n\
    \            const vector<S> &w = d.back();\n            for (int j = 0; j < n;\
    \ j++) {\n                tf[j] = g[g[j]];\n                td[j] = M::op(w[j],\
    \ w[g[j]]);\n            }\n            f.push_back(tf);\n            d.push_back(td);\n\
    \        }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename Monoid, bool edge>\nstruct weighted_functional_graph {\n \
    \   using M = Monoid;\n    using S = typename M::S;\n    weighted_functional_graph(int\
    \ _n) : weighted_functional_graph(vector<int>(_n, -1), vector<S>(_n, M::e()))\
    \ {}\n    weighted_functional_graph(const vector<int> &a, const vector<S> &w)\
    \ : n(a.size()), f(1, a), d(1, w) {}\n    void add_edge(int u, int v, const S\
    \ &w = M::e()) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v\
    \ < n);\n        assert(f[0][u] == -1);\n        f[0][u] = v;\n        if (edge)\
    \ d[0][u] = w;\n    }\n    void set(int u, S x) {\n        assert(!edge);\n  \
    \      assert(0 <= u && u < n);\n        d[0][u] = x;\n    }\n    pair<int, S>\
    \ steps(int u, long long k) {\n        assert(0 <= u && u < n);\n        doubling(k);\n\
    \        S p = M::e();\n        for (int i = 0; (1LL << i) <= k; i++) {\n    \
    \        if (k >> i & 1) {\n                p = M::op(p, d[i][u]);\n         \
    \       u = f[i][u];\n            }\n        }\n        if (!edge) p = M::op(p,\
    \ d[0][u]);\n        return make_pair(u, p);\n    }\n    template<typename C>\n\
    \    pair<int, S> binary_search(int u, long long k, const C &check) {\n      \
    \  assert(0 <= u && u < n);\n        assert(check(M::e()));\n        doubling(k);\n\
    \        int r = 0;\n        while ((1LL << r) <= k) r++;\n        S p = M::e();\n\
    \        for (r-- ; r >= 0; r--) {\n            S np = M::op(p, d[r][u]);\n  \
    \          if ((1LL << r) <= k && check(np)) {\n                u = f[r][u];\n\
    \                p = np;\n                k -= 1LL << r;\n            }\n    \
    \    }\n        return make_pair(u, p);\n    }\nprivate:\n    int n;\n    vector<vector<int>>\
    \ f;\n    vector<vector<S>> d;\n    void doubling(long long k) {\n        while\
    \ (1LL << int(f.size()) <= k) {\n            vector<int> tf(n);\n            vector<S>\
    \ td(n);\n            const vector<int> &g = f.back();\n            const vector<S>\
    \ &w = d.back();\n            for (int j = 0; j < n; j++) {\n                tf[j]\
    \ = g[g[j]];\n                td[j] = M::op(w[j], w[g[j]]);\n            }\n \
    \           f.push_back(tf);\n            d.push_back(td);\n        }\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/weighted_functional_graph.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/weighted_functional_graph.hpp
layout: document
redirect_from:
- /library/src/graph/weighted_functional_graph.hpp
- /library/src/graph/weighted_functional_graph.hpp.html
title: src/graph/weighted_functional_graph.hpp
---
