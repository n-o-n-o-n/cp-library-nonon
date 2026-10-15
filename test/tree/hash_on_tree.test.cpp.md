---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/random/utility.hpp
    title: src/random/utility.hpp
  - icon: ':heavy_check_mark:'
    path: src/tree/hash_on_tree.hpp
    title: src/tree/hash_on_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
    links:
    - https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
  bundledCode: "#line 1 \"test/tree/hash_on_tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#line 2 \"src/tree/hash_on_tree.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <cassert>\n#include <numeric>\n#include <vector>\n#line 3 \"src/random/utility.hpp\"\
    \n#include <concepts>\n#include <random>\nusing namespace std;\n\nnamespace rng\
    \ {\n\ninline random_device seed;\ninline mt19937 eng(seed());\n\ntemplate<typename\
    \ T>\nvoid set_seed(const T &sd) {\n    eng.seed(sd);\n}\n\ntemplate<integral\
    \ T>\ninline T randint(T lo, T hi) {\n    assert(lo <= hi);\n    uniform_int_distribution<T>\
    \ dist(lo, hi);\n    return dist(eng);\n}\n\ntemplate<integral T>\ninline pair<T,\
    \ T> randpair(T lo, T hi, bool strict = false) {\n    assert(lo + strict <= hi);\n\
    \    T l = randint(lo, hi - strict);\n    T r = randint(l + strict, hi);\n   \
    \ return make_pair(l, r);\n}\n\n} // namespace rng\n#line 8 \"src/tree/hash_on_tree.hpp\"\
    \nusing namespace std;\n\nstruct hash_on_tree {\n    static long long base;\n\
    \    static vector<long long> rds;\n    static constexpr array<long long, 3> mod\
    \ = {1000274903LL, 1000274927LL, 1000274953LL};\n    static void set_base(int\
    \ b) {\n        assert(base == -1);\n        assert(2 <= b && b <= int(1e9));\n\
    \        base = b;\n    }\n    hash_on_tree(int _n, int r = 0) : n(_n), root(r),\
    \ g(_n) {}\n    void add_edge(int u, int v) {\n        assert(base != -1);\n \
    \       assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n    array<long long, 3> get_hash(int u) {\n\
    \        assert(base != -1);\n        assert(0 <= u && u < n);\n        build();\n\
    \        return hs[u];\n    }\nprivate:\n    int n, root;\n    vector<vector<int>>\
    \ g;\n    vector<array<long long, 3>> hs;\n    void build() {\n        if (hs.size())\
    \ return;\n        hs = vector<array<long long, 3>>(n);\n        auto dfs = [&]\
    \ (const auto &dfs, int u, int p) -> int {\n            int md = 0;\n        \
    \    hs[u].fill(1);\n            for (int v : g[u]) {\n                if (v !=\
    \ p) {\n                    int d = dfs(dfs, v, u) + 1;\n                    md\
    \ = max(md, d + 1);\n                    for (int j = 0; j < 3; j++) {\n     \
    \                   hs[u][j] = (hs[u][j] * (rd(d + 1) + hs[v][j])) % mod[j];\n\
    \                    }\n                }\n            }\n            return md;\n\
    \        };\n        dfs(dfs, root, -1);\n    }\n    static long long rd(int d)\
    \ {\n        int sz = rds.size();\n        if (d >= sz) {\n            int k =\
    \ max(d + 1, 2 * sz);\n            rds.resize(k);\n            for (int i = sz;\
    \ i < k; i++) {\n                rds[i] = rng::randint(0LL, mod[0] - 1);\n   \
    \         }\n        }\n        return rds[d];\n    }\n};\ninline long long hash_on_tree::base(-1);\n\
    inline vector<long long> hash_on_tree::rds(1, 1);\n#line 4 \"test/tree/hash_on_tree.test.cpp\"\
    \n\n#include <iostream>\n#include <map>\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    int N;\n    cin >> N;\n    hash_on_tree::set_base(998244353);\n\
    \    hash_on_tree G(N);\n    for (int i = 1, p; i < N; i++) {\n        cin >>\
    \ p;\n        G.add_edge(i, p);\n    }\n    map<array<long long, 3>, int> mp;\n\
    \    vector<int> ans(N);\n    for (int i = 0; i < N; i++) {\n        auto ar =\
    \ G.get_hash(i);\n        if (mp.find(ar) == mp.end()) mp[ar] = ans[i] = mp.size();\n\
    \        ans[i] = mp[ar];\n    }\n    cout << mp.size() << '\\n';\n    for (int\
    \ i = 0; i < N; i++) cout << ans[i] << \" \\n\"[i + 1 == N];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#include \"../../src/tree/hash_on_tree.hpp\"\n\n#include <iostream>\n#include\
    \ <map>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N;\n    cin >> N;\n    hash_on_tree::set_base(998244353);\n    hash_on_tree\
    \ G(N);\n    for (int i = 1, p; i < N; i++) {\n        cin >> p;\n        G.add_edge(i,\
    \ p);\n    }\n    map<array<long long, 3>, int> mp;\n    vector<int> ans(N);\n\
    \    for (int i = 0; i < N; i++) {\n        auto ar = G.get_hash(i);\n       \
    \ if (mp.find(ar) == mp.end()) mp[ar] = ans[i] = mp.size();\n        ans[i] =\
    \ mp[ar];\n    }\n    cout << mp.size() << '\\n';\n    for (int i = 0; i < N;\
    \ i++) cout << ans[i] << \" \\n\"[i + 1 == N];\n}"
  dependsOn:
  - src/tree/hash_on_tree.hpp
  - src/random/utility.hpp
  isVerificationFile: true
  path: test/tree/hash_on_tree.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:16:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/hash_on_tree.test.cpp
layout: document
redirect_from:
- /verify/test/tree/hash_on_tree.test.cpp
- /verify/test/tree/hash_on_tree.test.cpp.html
title: test/tree/hash_on_tree.test.cpp
---
