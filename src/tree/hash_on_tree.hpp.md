---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/random/utility.hpp
    title: src/random/utility.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/hash_on_tree.test.cpp
    title: test/tree/hash_on_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/hash_on_tree.hpp\"\n#include <algorithm>\n#include\
    \ <array>\n#include <cassert>\n#include <numeric>\n#include <vector>\n#line 3\
    \ \"src/random/utility.hpp\"\n#include <concepts>\n#include <random>\nusing namespace\
    \ std;\n\nnamespace rng {\n\ninline random_device seed;\ninline mt19937 eng(seed());\n\
    \ntemplate<typename T>\nvoid set_seed(const T &sd) {\n    eng.seed(sd);\n}\n\n\
    template<integral T>\ninline T randint(T lo, T hi) {\n    assert(lo <= hi);\n\
    \    uniform_int_distribution<T> dist(lo, hi);\n    return dist(eng);\n}\n\ntemplate<integral\
    \ T>\ninline pair<T, T> randpair(T lo, T hi, bool strict = false) {\n    assert(lo\
    \ + strict <= hi);\n    T l = randint(lo, hi - strict);\n    T r = randint(l +\
    \ strict, hi);\n    return make_pair(l, r);\n}\n\n} // namespace rng\n#line 8\
    \ \"src/tree/hash_on_tree.hpp\"\nusing namespace std;\n\nstruct hash_on_tree {\n\
    \    static long long base;\n    static vector<long long> rds;\n    static constexpr\
    \ array<long long, 3> mod = {1000274903LL, 1000274927LL, 1000274953LL};\n    static\
    \ void set_base(int b) {\n        assert(base == -1);\n        assert(2 <= b &&\
    \ b <= int(1e9));\n        base = b;\n    }\n    hash_on_tree(int _n, int r =\
    \ 0) : n(_n), root(r), g(_n) {}\n    void add_edge(int u, int v) {\n        assert(base\
    \ != -1);\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n\
    \        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n    array<long\
    \ long, 3> get_hash(int u) {\n        assert(base != -1);\n        assert(0 <=\
    \ u && u < n);\n        build();\n        return hs[u];\n    }\nprivate:\n   \
    \ int n, root;\n    vector<vector<int>> g;\n    vector<array<long long, 3>> hs;\n\
    \    void build() {\n        if (hs.size()) return;\n        hs = vector<array<long\
    \ long, 3>>(n);\n        auto dfs = [&] (const auto &dfs, int u, int p) -> int\
    \ {\n            int md = 0;\n            hs[u].fill(1);\n            for (int\
    \ v : g[u]) {\n                if (v != p) {\n                    int d = dfs(dfs,\
    \ v, u) + 1;\n                    md = max(md, d + 1);\n                    for\
    \ (int j = 0; j < 3; j++) {\n                        hs[u][j] = (hs[u][j] * (rd(d\
    \ + 1) + hs[v][j])) % mod[j];\n                    }\n                }\n    \
    \        }\n            return md;\n        };\n        dfs(dfs, root, -1);\n\
    \    }\n    static long long rd(int d) {\n        int sz = rds.size();\n     \
    \   if (d >= sz) {\n            int k = max(d + 1, 2 * sz);\n            rds.resize(k);\n\
    \            for (int i = sz; i < k; i++) {\n                rds[i] = rng::randint(0LL,\
    \ mod[0] - 1);\n            }\n        }\n        return rds[d];\n    }\n};\n\
    inline long long hash_on_tree::base(-1);\ninline vector<long long> hash_on_tree::rds(1,\
    \ 1);\n"
  code: "#pragma once\n#include <algorithm>\n#include <array>\n#include <cassert>\n\
    #include <numeric>\n#include <vector>\n#include \"../random/utility.hpp\"\nusing\
    \ namespace std;\n\nstruct hash_on_tree {\n    static long long base;\n    static\
    \ vector<long long> rds;\n    static constexpr array<long long, 3> mod = {1000274903LL,\
    \ 1000274927LL, 1000274953LL};\n    static void set_base(int b) {\n        assert(base\
    \ == -1);\n        assert(2 <= b && b <= int(1e9));\n        base = b;\n    }\n\
    \    hash_on_tree(int _n, int r = 0) : n(_n), root(r), g(_n) {}\n    void add_edge(int\
    \ u, int v) {\n        assert(base != -1);\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \    }\n    array<long long, 3> get_hash(int u) {\n        assert(base != -1);\n\
    \        assert(0 <= u && u < n);\n        build();\n        return hs[u];\n \
    \   }\nprivate:\n    int n, root;\n    vector<vector<int>> g;\n    vector<array<long\
    \ long, 3>> hs;\n    void build() {\n        if (hs.size()) return;\n        hs\
    \ = vector<array<long long, 3>>(n);\n        auto dfs = [&] (const auto &dfs,\
    \ int u, int p) -> int {\n            int md = 0;\n            hs[u].fill(1);\n\
    \            for (int v : g[u]) {\n                if (v != p) {\n           \
    \         int d = dfs(dfs, v, u) + 1;\n                    md = max(md, d + 1);\n\
    \                    for (int j = 0; j < 3; j++) {\n                        hs[u][j]\
    \ = (hs[u][j] * (rd(d + 1) + hs[v][j])) % mod[j];\n                    }\n   \
    \             }\n            }\n            return md;\n        };\n        dfs(dfs,\
    \ root, -1);\n    }\n    static long long rd(int d) {\n        int sz = rds.size();\n\
    \        if (d >= sz) {\n            int k = max(d + 1, 2 * sz);\n           \
    \ rds.resize(k);\n            for (int i = sz; i < k; i++) {\n               \
    \ rds[i] = rng::randint(0LL, mod[0] - 1);\n            }\n        }\n        return\
    \ rds[d];\n    }\n};\ninline long long hash_on_tree::base(-1);\ninline vector<long\
    \ long> hash_on_tree::rds(1, 1);"
  dependsOn:
  - src/random/utility.hpp
  isVerificationFile: false
  path: src/tree/hash_on_tree.hpp
  requiredBy: []
  timestamp: '2026-10-14 23:16:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/hash_on_tree.test.cpp
documentation_of: src/tree/hash_on_tree.hpp
layout: document
redirect_from:
- /library/src/tree/hash_on_tree.hpp
- /library/src/tree/hash_on_tree.hpp.html
title: src/tree/hash_on_tree.hpp
---
