---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/modint/modint.hpp
    title: src/modint/modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/tree/rerooting_dp.hpp
    title: src/tree/rerooting_dp.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/tree_path_composite_sum
  bundledCode: "#line 1 \"test/tree/rerooting_dp.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n\n#line 2 \"src/tree/rerooting_dp.hpp\"\n#include <vector>\nusing namespace\
    \ std;\n\ntemplate<typename Monoid>\nstruct rerooting_dp {\n    using S = Monoid::S;\n\
    \    rerooting_dp(int n) : g(n), pos(0) {}\n    void add_edge(int u, int v) {\n\
    \        g[u].emplace_back(v, pos);\n        g[v].emplace_back(u, pos);\n    \
    \    pos++;\n    }\n    template<typename L1, typename L2>\n    vector<S> run(const\
    \ L1 &apply_vertex, const L2 &apply_edge) {\n        vector<S> memo(g.size(),\
    \ Monoid::e()), dp(g.size(), Monoid::e());\n        auto dfs = [&](const auto\
    \ &dfs, int u, int p) -> void {\n            for (const auto &[v, i] : g[u]) {\n\
    \                if (v != p) {\n                    dfs(dfs, v, u);\n        \
    \            memo[u] = Monoid::op(memo[u], apply_edge(memo[v], i));\n        \
    \        }\n            }\n            memo[u] = apply_vertex(memo[u], u);\n \
    \       };\n        auto reroot = [&](const auto &reroot, int u, int p, const\
    \ S &x) -> void {\n            vector<S> d = {x};\n            for (const auto\
    \ &[v, i] : g[u]) {\n                if (v != p) {\n                    d.push_back(apply_edge(memo[v],\
    \ i));\n                }\n            }\n            int n = d.size();\n    \
    \        vector<S> pre(n + 1, Monoid::e()), suf(n + 1, Monoid::e());\n       \
    \     for (int i = 0; i < n; i++) {\n                pre[i + 1] = Monoid::op(pre[i],\
    \ d[i]);\n            }\n            for (int i = n; i > 0; i--) {\n         \
    \       suf[i - 1] = Monoid::op(suf[i], d[i - 1]);\n            }\n          \
    \  dp[u] = apply_vertex(pre[n], u);\n            int k = 1;\n            for (const\
    \ auto &[v, i] : g[u]) {\n                if (v != p) {\n                    S\
    \ y = Monoid::op(pre[k], suf[k + 1]);\n                    reroot(reroot, v, u,\
    \ apply_edge(apply_vertex(y, u), i));\n                    k++;\n            \
    \    }\n            }\n        };\n        dfs(dfs, 0, -1);\n        reroot(reroot,\
    \ 0, -1, Monoid::e());\n        return dp;\n    }\nprivate:\n    vector<vector<pair<int,\
    \ int>>> g;\n    int pos;\n};\n#line 2 \"src/modint/modint.hpp\"\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate<int MOD>\nstruct modint {\n\
    \    constexpr modint() : x(0) {}\n    constexpr modint(long long v) {\n     \
    \   long long y = v % m();\n        if (y < 0) y += m();\n        x = (unsigned\
    \ int)(y);\n    }\n    static constexpr modint raw(int v) {\n        modint a;\n\
    \        a.x = v;\n        return a;\n    }\n    static constexpr int mod() {\
    \ return m(); }\n    constexpr unsigned int val() const { return x; }\n    constexpr\
    \ modint& operator++() {\n        x++;\n        if (x == m()) x = 0;\n       \
    \ return *this;\n    }\n    constexpr modint& operator--() {\n        if (x ==\
    \ 0) x = m();\n        x--;\n        return *this;\n    }\n    constexpr modint\
    \ operator++(int) {\n        modint res = *this;\n        ++*this;\n        return\
    \ res;\n    }\n    constexpr modint operator--(int) {\n        modint res = *this;\n\
    \        --*this;\n        return res;\n    }\n    constexpr modint& operator+=(const\
    \ modint &r) {\n        x += r.x;\n        if (x >= m()) x -= m();\n        return\
    \ *this;\n    }\n    constexpr modint& operator-=(const modint &r) {\n       \
    \ x -= r.x;\n        if (x >= m()) x += m();\n        return *this;\n    }\n \
    \   constexpr modint& operator*=(const modint &r) {\n        unsigned long long\
    \ y = x;\n        y *= r.x;\n        x = (unsigned int)(y % m());\n        return\
    \ *this;\n    }\n    constexpr modint &operator/=(const modint &r) {\n       \
    \ return *this = *this * r.inv();\n    }\n    friend constexpr modint operator+(const\
    \ modint &a, const modint &b) {\n        return modint(a) += b;\n    }\n    friend\
    \ constexpr modint operator-(const modint &a, const modint &b) {\n        return\
    \ modint(a) -= b;\n    }\n    friend constexpr modint operator*(const modint &a,\
    \ const modint &b) {\n        return modint(a) *= b;\n    }\n    friend constexpr\
    \ modint operator/(const modint &a, const modint &b) {\n        return modint(a)\
    \ /= b;\n    }\n    friend constexpr bool operator==(const modint &a, const modint\
    \ &b) {\n        return a.x == b.x;\n    }\n    friend constexpr bool operator!=(const\
    \ modint &a, const modint &b) {\n        return a.x != b.x;\n    }\n    constexpr\
    \ modint operator+() const { return *this; }\n    constexpr modint operator-()\
    \ const { return modint() - *this; }\n    constexpr modint pow(long long k) const\
    \ {\n        assert(k >= 0);\n        modint a = *this;\n        modint res =\
    \ 1;\n        while (k > 0) {\n            if (k & 1) res *= a;\n            a\
    \ *= a;\n            k >>= 1;\n        }\n        return res;\n    }\n    constexpr\
    \ modint inv() const {\n        long long a = x, b = m(), u = 1, v = 0;\n    \
    \    while (b > 0) {\n            long long t = a / b;\n            a -= t * b;\n\
    \            swap(a, b);\n            u -= t * v;\n            swap(u, v);\n \
    \       }\n        return modint(u);\n    }\nprivate:\n    unsigned int x;\n \
    \   static constexpr unsigned int m() { return MOD; }\n};\n#line 5 \"test/tree/rerooting_dp.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\nstruct Monoid {\n    using S = pair<mint,\
    \ int>;\n    static S op(S a, S b) { return {a.first + b.first, a.second + b.second};\
    \ }\n    static S e() { return {0, 0}; }\n};\n\n#include <iostream>\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N;\n   \
    \ cin >> N;\n    vector<int> A(N);\n    for (auto &e : A) cin >> e;\n    vector<mint>\
    \ B(N - 1), C(N - 1);\n    rerooting_dp<Monoid> RR(N);\n    for (int i = 0, u,\
    \ v, b, c; i < N - 1; i++) {\n        cin >> u >> v >> b >> c;\n        RR.add_edge(u,\
    \ v);\n        B[i] = b, C[i] = c;\n    }\n    using S = Monoid::S;\n    auto\
    \ apply_vertex = [&] (S x, int u) -> S {\n        return {x.first + A[u], x.second\
    \ + 1};\n    };\n    auto apply_edge = [&] (S x, int i) -> S {\n        return\
    \ {x.first * B[i] + x.second * C[i], x.second};\n    };\n    auto ans = RR.run(apply_vertex,\
    \ apply_edge);\n    for (int i = 0; i < N; i++) cout << ans[i].first.val() <<\
    \ \" \\n\"[i + 1 == N];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n\n#include \"../../src/tree/rerooting_dp.hpp\"\n#include \"../../src/modint/modint.hpp\"\
    \n\nusing mint = modint<998244353>;\n\nstruct Monoid {\n    using S = pair<mint,\
    \ int>;\n    static S op(S a, S b) { return {a.first + b.first, a.second + b.second};\
    \ }\n    static S e() { return {0, 0}; }\n};\n\n#include <iostream>\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N;\n   \
    \ cin >> N;\n    vector<int> A(N);\n    for (auto &e : A) cin >> e;\n    vector<mint>\
    \ B(N - 1), C(N - 1);\n    rerooting_dp<Monoid> RR(N);\n    for (int i = 0, u,\
    \ v, b, c; i < N - 1; i++) {\n        cin >> u >> v >> b >> c;\n        RR.add_edge(u,\
    \ v);\n        B[i] = b, C[i] = c;\n    }\n    using S = Monoid::S;\n    auto\
    \ apply_vertex = [&] (S x, int u) -> S {\n        return {x.first + A[u], x.second\
    \ + 1};\n    };\n    auto apply_edge = [&] (S x, int i) -> S {\n        return\
    \ {x.first * B[i] + x.second * C[i], x.second};\n    };\n    auto ans = RR.run(apply_vertex,\
    \ apply_edge);\n    for (int i = 0; i < N; i++) cout << ans[i].first.val() <<\
    \ \" \\n\"[i + 1 == N];\n}"
  dependsOn:
  - src/tree/rerooting_dp.hpp
  - src/modint/modint.hpp
  isVerificationFile: true
  path: test/tree/rerooting_dp.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:06:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/rerooting_dp.test.cpp
layout: document
redirect_from:
- /verify/test/tree/rerooting_dp.test.cpp
- /verify/test/tree/rerooting_dp.test.cpp.html
title: test/tree/rerooting_dp.test.cpp
---
