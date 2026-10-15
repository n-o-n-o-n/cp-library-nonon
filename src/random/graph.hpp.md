---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/misc/even_distribution_array.hpp
    title: src/misc/even_distribution_array.hpp
  - icon: ':question:'
    path: src/random/sequence.hpp
    title: src/random/sequence.hpp
  - icon: ':question:'
    path: src/random/utility.hpp
    title: src/random/utility.hpp
  - icon: ':x:'
    path: src/tree/prufer_code.hpp
    title: src/tree/prufer_code.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree/centroid_decomposition.test.cpp
    title: test/tree/centroid_decomposition.test.cpp
  - icon: ':x:'
    path: test/tree/level_ancestor_offline.test.cpp
    title: test/tree/level_ancestor_offline.test.cpp
  - icon: ':x:'
    path: test/tree/prufer_code.test.cpp
    title: test/tree/prufer_code.test.cpp
  - icon: ':x:'
    path: test/tree/static_tree.auxiliary_tree.test.cpp
    title: test/tree/static_tree.auxiliary_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/random/graph.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <set>\n#include <vector>\n#line 3 \"src/random/utility.hpp\"\n#include\
    \ <concepts>\n#include <random>\nusing namespace std;\n\nnamespace rng {\n\ninline\
    \ random_device seed;\ninline mt19937 eng(seed());\n\ntemplate<typename T>\nvoid\
    \ set_seed(const T &sd) {\n    eng.seed(sd);\n}\n\ntemplate<integral T>\ninline\
    \ T randint(T lo, T hi) {\n    assert(lo <= hi);\n    uniform_int_distribution<T>\
    \ dist(lo, hi);\n    return dist(eng);\n}\n\ntemplate<integral T>\ninline pair<T,\
    \ T> randpair(T lo, T hi, bool strict = false) {\n    assert(lo + strict <= hi);\n\
    \    T l = randint(lo, hi - strict);\n    T r = randint(l + strict, hi);\n   \
    \ return make_pair(l, r);\n}\n\n} // namespace rng\n#line 3 \"src/misc/even_distribution_array.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T>\nvector<T> even_distribution_array(const\
    \ vector<T> &v) {\n    int n = v.size();\n    long long sum = 0;\n    for (int\
    \ i = 0; i < n; i++) {\n        sum += v[i];\n    }\n    T q = sum / n, r = sum\
    \ % n;\n    vector<T> res(n, q);\n    for (int i = n - r; i < n; i++) res[i]++;\n\
    \    return res;\n}\n#line 7 \"src/random/sequence.hpp\"\nusing namespace std;\n\
    \nnamespace rng {\n\ntemplate<typename T>\nvoid shuffle(vector<T> &v) {\n    std::shuffle(v.begin(),\
    \ v.end(), eng);\n}\n\ntemplate<integral T>\ninline vector<T> random_sequence(int\
    \ n, T lo, T hi) {\n    assert(n >= 0);\n    vector<T> res(n);\n    for (int i\
    \ = 0; i < n; i++) res[i] = randint(lo, hi);\n    return res;\n}\n\ntemplate<integral\
    \ T>\ninline vector<T> random_increasing_sequence(int n, T lo, T hi, bool strict\
    \ = false) {\n    assert(n >= 0);\n    if (n == 0) return {};\n    assert(lo +\
    \ (n - 1) * strict <= hi);\n    vector<T> res = random_sequence(n, lo, hi - (n\
    \ - 1) * strict);\n    sort(res.begin(), res.end());\n    for (int i = 0; i <\
    \ n; i++) res[i] += i * strict;\n    return res;\n}\n\ntemplate<integral T>\n\
    inline vector<T> random_decreasing_sequence(int n, T lo, T hi, bool strict = false)\
    \ {\n    vector<T> res = random_increasing_sequence(n, lo, hi, strict);\n    reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n\ntemplate<integral T>\ninline vector<T> random_permutation(int\
    \ n, T val = 0) {\n    vector<T> res(n);\n    iota(res.begin(), res.end(), val);\n\
    \    shuffle(res);\n    return res;\n}\n\ninline string random_string(int n, char\
    \ a, char z) {\n    assert(a <= z);\n    string s(n, a);\n    for (auto &c : s)\
    \ c = randint((int)a, (int)z);\n    return s;\n}\n\n} // namespace rng\n#line\
    \ 2 \"src/tree/prufer_code.hpp\"\n#include <queue>\n#line 4 \"src/tree/prufer_code.hpp\"\
    \nusing namespace std;\n\nvector<int> prufer_code_compress(const vector<vector<int>>\
    \ &t) {\n    int n = t.size();\n    if (n <= 2) return {};\n    vector<int> deg(n);\n\
    \    priority_queue<int, vector<int>, greater<int>> q;\n    for (int i = 0; i\
    \ < n; i++) {\n        deg[i] = t[i].size();\n        if (deg[i] == 1) {\n   \
    \         q.push(i);\n        }\n    }\n    vector<int> p;\n    p.reserve(n -\
    \ 2);\n    while ((int)p.size() < n - 2) {\n        int u = q.top();\n       \
    \ q.pop();\n        for (int v : t[u]) {\n            if (deg[v] > 0) {\n    \
    \            p.push_back(v);\n                deg[v]--;\n                if (deg[v]\
    \ == 1) q.push(v);\n                break;\n            }\n        }\n       \
    \ deg[u]--;\n    }\n    return p;\n}\n\nvector<vector<int>> prufer_code_expansion(const\
    \ vector<int> &p) {\n    int n = p.size() + 2;\n    vector<int> deg(n, 1);\n \
    \   for (int u : p) deg[u]++;\n    priority_queue<int, vector<int>, greater<int>>\
    \ q;\n    for (int i = 0; i < n; i++) {\n        if (deg[i] == 1) q.push(i);\n\
    \    }\n    vector<vector<int>> t(n);\n    for (int i = 0; i < n - 2; i++) {\n\
    \        int u = p[i];\n        int v = q.top();\n        q.pop();\n        t[u].push_back(v);\n\
    \        t[v].push_back(u);\n        deg[u]--, deg[v]--;\n        if (deg[u] ==\
    \ 1) q.push(u);\n    }\n    for (int i = 0; i < n; i++) {\n        if (deg[i]\
    \ == 1) {\n            for (int j = 0; j < n; j++) {\n                if (j !=\
    \ i && deg[j] == 1) {\n                    t[i].push_back(j);\n              \
    \      t[j].push_back(i);\n                    deg[i]--, deg[j]--;\n         \
    \           break;\n                }\n            }\n            break;\n   \
    \     }\n    }\n    return t;\n}\n#line 9 \"src/random/graph.hpp\"\nusing namespace\
    \ std;\n\nnamespace rng {\n\ninline vector<pair<int, int>> random_star(int n)\
    \ {\n    assert(n >= 0);\n    if (n <= 1) return {};\n    if (n == 2) return {make_pair(0,\
    \ 1)};\n    int r = randint(0, n - 1);\n    vector<pair<int, int>> res;\n    for\
    \ (int i = 0; i < n; i++) {\n        if (r != i) res.push_back(minmax(r, i));\n\
    \    }\n    return res;\n}\n\ninline vector<pair<int, int>> random_path(int n)\
    \ {\n    assert(n >= 0);\n    if (n <= 1) return {};\n    if (n == 2) return {make_pair(0,\
    \ 1)};\n    auto p = random_permutation(n, 0);\n    vector<pair<int, int>> res;\n\
    \    for (int i = 1; i < n; i++) {\n        res.emplace_back(minmax(p[i - 1],\
    \ p[i]));\n    }\n    shuffle(res);\n    return res;\n}\n\ninline vector<pair<int,\
    \ int>> random_binary_tree(int n) {\n    assert(n >= 0);\n    if (n <= 1) return\
    \ {};\n    if (n == 2) return {make_pair(0, 1)};\n    auto p = random_permutation(n,\
    \ 0);\n    vector<pair<int, int>> res;\n    for (int i = 1; i < n; i++) {\n  \
    \      res.emplace_back(minmax(p[(i - 1) / 2], p[i]));\n    }\n    shuffle(res);\n\
    \    return res;\n}\n\ninline vector<pair<int, int>> random_broom(int n) {\n \
    \   assert(n >= 0);\n    if (n <= 1) return {};\n    if (n == 2) return {make_pair(0,\
    \ 1)};\n    auto p = random_permutation(n, 0);\n    int m = randint(1, n);\n \
    \   vector<pair<int, int>> res;\n    for (int i = 1; i < n; i++) {\n        res.emplace_back(minmax(p[min(m,\
    \ i - 1)], p[i]));\n    }\n    shuffle(res);\n    return res;\n}\n\ninline vector<pair<int,\
    \ int>> random_caterpillar(int n) {\n    assert(n >= 0);\n    if (n <= 1) return\
    \ {};\n    if (n == 2) return {make_pair(0, 1)};\n    auto p = random_permutation(n,\
    \ 0);\n    int m = randint(1, n);\n    vector<pair<int, int>> res;\n    for (int\
    \ i = 1; i < n; i++) {\n        if (i < m) res.emplace_back(minmax(p[i - 1], p[i]));\n\
    \        else res.emplace_back(minmax(p[randint(0, m - 1)], p[i]));\n    }\n \
    \   shuffle(res);\n    return res;\n}\n\ninline vector<pair<int, int>> random_tree(int\
    \ n, bool corner = false) {\n    assert(n >= 0);\n    if (n <= 1) return {};\n\
    \    if (n == 2) return {make_pair(0, 1)};\n    if (corner) {\n        int type\
    \ = randint(1, 6);\n        if (type == 1) return random_star(n);\n        if\
    \ (type == 2) return random_path(n);\n        if (type == 3) return random_binary_tree(n);\n\
    \        if (type == 4) return random_broom(n);\n        if (type == 5) return\
    \ random_caterpillar(n);\n    }\n    vector<int> p(n - 2);\n    for (int &e :\
    \ p) e = randint(0, n - 1);\n    auto t = prufer_code_expansion(p);\n    vector<pair<int,\
    \ int>> res;\n    for (int u = 0; u < n; u++) {\n        for (int v : t[u]) {\n\
    \            if (u < v) res.emplace_back(u, v);\n        }\n    }\n    return\
    \ res;\n}\n\ninline vector<pair<int, int>> random_simple_graph(int n, int m) {\n\
    \    assert(n >= 0);\n    assert(m >= 0);\n    assert((long long)m <= (long long)n\
    \ * (n - 1) / 2);\n    if (n <= 3000) {\n        vector<pair<int, int>> edges;\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = i + 1; j < n;\
    \ j++) {\n                edges.emplace_back(i, j);\n            }\n        }\n\
    \        shuffle(edges);\n        return vector<pair<int, int>>(edges.begin(),\
    \ edges.begin() + m);\n    }\n    set<pair<int, int>> edges;\n    while ((int)edges.size()\
    \ < m) {\n        auto [u, v] = randpair(0, n - 1, true);\n        edges.emplace(u,\
    \ v);\n    }\n    return vector<pair<int, int>>(edges.begin(), edges.end());\n\
    }\n\ninline vector<pair<int, int>> random_connected_graph(int n, int m) {\n  \
    \  assert(n >= 0);\n    assert(m >= n - 1);\n    assert((long long)m <= (long\
    \ long)n * (n - 1) / 2);\n    auto t = random_tree(n, true);\n    if (n <= 3000)\
    \ {\n        vector<vector<bool>> used(n, vector<bool>(n, false));\n        for\
    \ (auto [u, v] : t) used[u][v] = true;\n        vector<pair<int, int>> edges;\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = i + 1; j < n;\
    \ j++) {\n                if (!used[i][j]) edges.emplace_back(i, j);\n       \
    \     }\n        }\n        shuffle(edges);\n        m -= n - 1;\n        while\
    \ ((int)edges.size() > m) edges.pop_back();\n        for (auto p : t) edges.push_back(p);\n\
    \        return edges;\n    }\n    set<pair<int, int>> edges(t.begin(), t.end());\n\
    \    while ((int)edges.size() < m) {\n        auto [u, v] = randpair(0, n - 1,\
    \ true);\n        edges.emplace(u, v);\n    }\n    return vector<pair<int, int>>(edges.begin(),\
    \ edges.end());\n}\n\n} // namespace rng\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <set>\n\
    #include <vector>\n#include \"utility.hpp\"\n#include \"sequence.hpp\"\n#include\
    \ \"../tree/prufer_code.hpp\"\nusing namespace std;\n\nnamespace rng {\n\ninline\
    \ vector<pair<int, int>> random_star(int n) {\n    assert(n >= 0);\n    if (n\
    \ <= 1) return {};\n    if (n == 2) return {make_pair(0, 1)};\n    int r = randint(0,\
    \ n - 1);\n    vector<pair<int, int>> res;\n    for (int i = 0; i < n; i++) {\n\
    \        if (r != i) res.push_back(minmax(r, i));\n    }\n    return res;\n}\n\
    \ninline vector<pair<int, int>> random_path(int n) {\n    assert(n >= 0);\n  \
    \  if (n <= 1) return {};\n    if (n == 2) return {make_pair(0, 1)};\n    auto\
    \ p = random_permutation(n, 0);\n    vector<pair<int, int>> res;\n    for (int\
    \ i = 1; i < n; i++) {\n        res.emplace_back(minmax(p[i - 1], p[i]));\n  \
    \  }\n    shuffle(res);\n    return res;\n}\n\ninline vector<pair<int, int>> random_binary_tree(int\
    \ n) {\n    assert(n >= 0);\n    if (n <= 1) return {};\n    if (n == 2) return\
    \ {make_pair(0, 1)};\n    auto p = random_permutation(n, 0);\n    vector<pair<int,\
    \ int>> res;\n    for (int i = 1; i < n; i++) {\n        res.emplace_back(minmax(p[(i\
    \ - 1) / 2], p[i]));\n    }\n    shuffle(res);\n    return res;\n}\n\ninline vector<pair<int,\
    \ int>> random_broom(int n) {\n    assert(n >= 0);\n    if (n <= 1) return {};\n\
    \    if (n == 2) return {make_pair(0, 1)};\n    auto p = random_permutation(n,\
    \ 0);\n    int m = randint(1, n);\n    vector<pair<int, int>> res;\n    for (int\
    \ i = 1; i < n; i++) {\n        res.emplace_back(minmax(p[min(m, i - 1)], p[i]));\n\
    \    }\n    shuffle(res);\n    return res;\n}\n\ninline vector<pair<int, int>>\
    \ random_caterpillar(int n) {\n    assert(n >= 0);\n    if (n <= 1) return {};\n\
    \    if (n == 2) return {make_pair(0, 1)};\n    auto p = random_permutation(n,\
    \ 0);\n    int m = randint(1, n);\n    vector<pair<int, int>> res;\n    for (int\
    \ i = 1; i < n; i++) {\n        if (i < m) res.emplace_back(minmax(p[i - 1], p[i]));\n\
    \        else res.emplace_back(minmax(p[randint(0, m - 1)], p[i]));\n    }\n \
    \   shuffle(res);\n    return res;\n}\n\ninline vector<pair<int, int>> random_tree(int\
    \ n, bool corner = false) {\n    assert(n >= 0);\n    if (n <= 1) return {};\n\
    \    if (n == 2) return {make_pair(0, 1)};\n    if (corner) {\n        int type\
    \ = randint(1, 6);\n        if (type == 1) return random_star(n);\n        if\
    \ (type == 2) return random_path(n);\n        if (type == 3) return random_binary_tree(n);\n\
    \        if (type == 4) return random_broom(n);\n        if (type == 5) return\
    \ random_caterpillar(n);\n    }\n    vector<int> p(n - 2);\n    for (int &e :\
    \ p) e = randint(0, n - 1);\n    auto t = prufer_code_expansion(p);\n    vector<pair<int,\
    \ int>> res;\n    for (int u = 0; u < n; u++) {\n        for (int v : t[u]) {\n\
    \            if (u < v) res.emplace_back(u, v);\n        }\n    }\n    return\
    \ res;\n}\n\ninline vector<pair<int, int>> random_simple_graph(int n, int m) {\n\
    \    assert(n >= 0);\n    assert(m >= 0);\n    assert((long long)m <= (long long)n\
    \ * (n - 1) / 2);\n    if (n <= 3000) {\n        vector<pair<int, int>> edges;\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = i + 1; j < n;\
    \ j++) {\n                edges.emplace_back(i, j);\n            }\n        }\n\
    \        shuffle(edges);\n        return vector<pair<int, int>>(edges.begin(),\
    \ edges.begin() + m);\n    }\n    set<pair<int, int>> edges;\n    while ((int)edges.size()\
    \ < m) {\n        auto [u, v] = randpair(0, n - 1, true);\n        edges.emplace(u,\
    \ v);\n    }\n    return vector<pair<int, int>>(edges.begin(), edges.end());\n\
    }\n\ninline vector<pair<int, int>> random_connected_graph(int n, int m) {\n  \
    \  assert(n >= 0);\n    assert(m >= n - 1);\n    assert((long long)m <= (long\
    \ long)n * (n - 1) / 2);\n    auto t = random_tree(n, true);\n    if (n <= 3000)\
    \ {\n        vector<vector<bool>> used(n, vector<bool>(n, false));\n        for\
    \ (auto [u, v] : t) used[u][v] = true;\n        vector<pair<int, int>> edges;\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = i + 1; j < n;\
    \ j++) {\n                if (!used[i][j]) edges.emplace_back(i, j);\n       \
    \     }\n        }\n        shuffle(edges);\n        m -= n - 1;\n        while\
    \ ((int)edges.size() > m) edges.pop_back();\n        for (auto p : t) edges.push_back(p);\n\
    \        return edges;\n    }\n    set<pair<int, int>> edges(t.begin(), t.end());\n\
    \    while ((int)edges.size() < m) {\n        auto [u, v] = randpair(0, n - 1,\
    \ true);\n        edges.emplace(u, v);\n    }\n    return vector<pair<int, int>>(edges.begin(),\
    \ edges.end());\n}\n\n} // namespace rng"
  dependsOn:
  - src/random/utility.hpp
  - src/random/sequence.hpp
  - src/misc/even_distribution_array.hpp
  - src/tree/prufer_code.hpp
  isVerificationFile: false
  path: src/random/graph.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree/level_ancestor_offline.test.cpp
  - test/tree/prufer_code.test.cpp
  - test/tree/centroid_decomposition.test.cpp
  - test/tree/static_tree.auxiliary_tree.test.cpp
documentation_of: src/random/graph.hpp
layout: document
redirect_from:
- /library/src/random/graph.hpp
- /library/src/random/graph.hpp.html
title: src/random/graph.hpp
---
