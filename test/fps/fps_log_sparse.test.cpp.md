---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/fps/fps_log_sparse.hpp
    title: src/fps/fps_log_sparse.hpp
  - icon: ':heavy_check_mark:'
    path: src/modint/modint.hpp
    title: src/modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/log_of_formal_power_series_sparse
    links:
    - https://judge.yosupo.jp/problem/log_of_formal_power_series_sparse
  bundledCode: "#line 1 \"test/fps/fps_log_sparse.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/log_of_formal_power_series_sparse\"\
    \n\n#line 2 \"src/fps/fps_log_sparse.hpp\"\n#include <cassert>\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename mint>\nvector<mint> fps_log_sparse(const\
    \ vector<pair<int, mint>> &f_sub, int n) {\n    assert(f_sub.size() && f_sub[0]\
    \ == make_pair(0, mint::raw(1)));\n    const int mod = mint::mod();\n    vector<mint>\
    \ g(n), inv(n);\n    for (auto [a, c] : f_sub) {\n        if(a > 0) g[a] = c;\n\
    \    }\n    if (n > 1) inv[1] = mint::raw(1);\n    for (int i = 1; i < n; i++)\
    \ {\n        mint sum = 0;\n        for (auto [a, c] : f_sub) {\n            if(0\
    \ < a && a <= i) {\n                sum += c * (i - a) * g[i - a];\n         \
    \   }\n        }\n        if (i >= 2) {\n            inv[i] = -inv[mod % i] *\
    \ (mod / i);\n            sum *= inv[i];\n        }\n        g[i] -= sum;\n  \
    \  }\n    return g;\n}\n#line 2 \"src/modint/modint.hpp\"\n#include <algorithm>\n\
    #line 4 \"src/modint/modint.hpp\"\nusing namespace std;\n\ntemplate<int MOD>\n\
    struct modint {\n    constexpr modint() : x(0) {}\n    constexpr modint(long long\
    \ v) {\n        long long y = v % m();\n        if (y < 0) y += m();\n       \
    \ x = (unsigned int)(y);\n    }\n    static constexpr modint raw(int v) {\n  \
    \      modint a;\n        a.x = v;\n        return a;\n    }\n    static constexpr\
    \ int mod() { return m(); }\n    constexpr unsigned int val() const { return x;\
    \ }\n    constexpr modint& operator++() {\n        x++;\n        if (x == m())\
    \ x = 0;\n        return *this;\n    }\n    constexpr modint& operator--() {\n\
    \        if (x == 0) x = m();\n        x--;\n        return *this;\n    }\n  \
    \  constexpr modint operator++(int) {\n        modint res = *this;\n        ++*this;\n\
    \        return res;\n    }\n    constexpr modint operator--(int) {\n        modint\
    \ res = *this;\n        --*this;\n        return res;\n    }\n    constexpr modint&\
    \ operator+=(const modint &r) {\n        x += r.x;\n        if (x >= m()) x -=\
    \ m();\n        return *this;\n    }\n    constexpr modint& operator-=(const modint\
    \ &r) {\n        x -= r.x;\n        if (x >= m()) x += m();\n        return *this;\n\
    \    }\n    constexpr modint& operator*=(const modint &r) {\n        unsigned\
    \ long long y = x;\n        y *= r.x;\n        x = (unsigned int)(y % m());\n\
    \        return *this;\n    }\n    constexpr modint &operator/=(const modint &r)\
    \ {\n        return *this = *this * r.inv();\n    }\n    friend constexpr modint\
    \ operator+(const modint &a, const modint &b) {\n        return modint(a) += b;\n\
    \    }\n    friend constexpr modint operator-(const modint &a, const modint &b)\
    \ {\n        return modint(a) -= b;\n    }\n    friend constexpr modint operator*(const\
    \ modint &a, const modint &b) {\n        return modint(a) *= b;\n    }\n    friend\
    \ constexpr modint operator/(const modint &a, const modint &b) {\n        return\
    \ modint(a) /= b;\n    }\n    friend constexpr bool operator==(const modint &a,\
    \ const modint &b) {\n        return a.x == b.x;\n    }\n    friend constexpr\
    \ bool operator!=(const modint &a, const modint &b) {\n        return a.x != b.x;\n\
    \    }\n    constexpr modint operator+() const { return *this; }\n    constexpr\
    \ modint operator-() const { return modint() - *this; }\n    constexpr modint\
    \ pow(long long k) const {\n        assert(k >= 0);\n        modint a = *this;\n\
    \        modint res = 1;\n        while (k > 0) {\n            if (k & 1) res\
    \ *= a;\n            a *= a;\n            k >>= 1;\n        }\n        return\
    \ res;\n    }\n    constexpr modint inv() const {\n        long long a = x, b\
    \ = m(), u = 1, v = 0;\n        while (b > 0) {\n            long long t = a /\
    \ b;\n            a -= t * b;\n            swap(a, b);\n            u -= t * v;\n\
    \            swap(u, v);\n        }\n        return modint(u);\n    }\nprivate:\n\
    \    unsigned int x;\n    static constexpr unsigned int m() { return MOD; }\n\
    };\n#line 5 \"test/fps/fps_log_sparse.test.cpp\"\n\nusing mint = modint<998244353>;\n\
    \n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N, K;\n    cin >> N >> K;\n    vector<pair<int, mint>> f_sub(K);\n  \
    \  for (int i = 0; i < K; i++) {\n        int a, b;\n        cin >> a >> b;\n\
    \        f_sub[i] = {a, mint::raw(b)};\n    }\n    auto f = fps_log_sparse(f_sub,\
    \ N);\n    for (int i = 0; i < N; i++) cout << f[i].val() << \" \\n\"[i + 1 ==\
    \ N];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/log_of_formal_power_series_sparse\"\
    \n\n#include \"../../src/fps/fps_log_sparse.hpp\"\n#include \"../../src/modint/modint.hpp\"\
    \n\nusing mint = modint<998244353>;\n\n#include <iostream>\n\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N, K;\n    cin\
    \ >> N >> K;\n    vector<pair<int, mint>> f_sub(K);\n    for (int i = 0; i < K;\
    \ i++) {\n        int a, b;\n        cin >> a >> b;\n        f_sub[i] = {a, mint::raw(b)};\n\
    \    }\n    auto f = fps_log_sparse(f_sub, N);\n    for (int i = 0; i < N; i++)\
    \ cout << f[i].val() << \" \\n\"[i + 1 == N];\n}"
  dependsOn:
  - src/fps/fps_log_sparse.hpp
  - src/modint/modint.hpp
  isVerificationFile: true
  path: test/fps/fps_log_sparse.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:06:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/fps/fps_log_sparse.test.cpp
layout: document
redirect_from:
- /verify/test/fps/fps_log_sparse.test.cpp
- /verify/test/fps/fps_log_sparse.test.cpp.html
title: test/fps/fps_log_sparse.test.cpp
---
