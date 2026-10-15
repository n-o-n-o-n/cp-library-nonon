---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/fps/fps_pow_sparse.hpp
    title: src/fps/fps_pow_sparse.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse
    links:
    - https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse
  bundledCode: "#line 1 \"test/fps/fps_pow_sparse.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse\"\
    \n\n#line 2 \"src/fps/fps_pow_sparse.hpp\"\n#include <cassert>\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename mint>\nvector<mint> fps_pow_sparse(const\
    \ vector<pair<int, mint>> &f_sub, int n, long long k) {\n    vector<mint> g(n);\n\
    \    if(f_sub.empty()) {\n        if (k == 0) g[0] = mint::raw(1);\n        return\
    \ g;\n    }\n    auto [a0, c0] = f_sub[0];\n    if(0 < a0) {\n        if(k > (n\
    \ - 1) / a0) return g;\n        vector<pair<int, mint>> g_sub = f_sub;\n     \
    \   for (auto &[a,c] : g_sub) a -= a0;\n        auto h = fps_pow_sparse(g_sub,\
    \ n - k * a0, k);\n        for (int i = 0; i < n - k * a0; i++) {\n          \
    \  g[i + k * a0] = h[i];\n        }\n        return g;\n    }\n    const int mod\
    \ = mint::mod();\n    vector<mint> inv(n);\n    if (n >= 2) inv[1] = 1;\n    g[0]\
    \ = c0.pow(k);\n    mint cef = c0.inv();\n    for (int i = 1; i < n; i++) {\n\
    \        for (auto [a, c] : f_sub) {\n            if(0 < a && a <= i) {\n    \
    \            g[i] += c * g[i - a] * (mint(k + 1) * a - i);\n            }\n  \
    \      }\n        if(i >= 2) {\n            inv[i] = -inv[mod % i] * (mod / i);\n\
    \        }\n        g[i] *= inv[i] * cef;\n    }\n    return g;\n}\n#line 2 \"\
    src/modint/modint.hpp\"\n#include <algorithm>\n#line 4 \"src/modint/modint.hpp\"\
    \nusing namespace std;\n\ntemplate<int MOD>\nstruct modint {\n    constexpr modint()\
    \ : x(0) {}\n    constexpr modint(long long v) {\n        long long y = v % m();\n\
    \        if (y < 0) y += m();\n        x = (unsigned int)(y);\n    }\n    static\
    \ constexpr modint raw(int v) {\n        modint a;\n        a.x = v;\n       \
    \ return a;\n    }\n    static constexpr int mod() { return m(); }\n    constexpr\
    \ unsigned int val() const { return x; }\n    constexpr modint& operator++() {\n\
    \        x++;\n        if (x == m()) x = 0;\n        return *this;\n    }\n  \
    \  constexpr modint& operator--() {\n        if (x == 0) x = m();\n        x--;\n\
    \        return *this;\n    }\n    constexpr modint operator++(int) {\n      \
    \  modint res = *this;\n        ++*this;\n        return res;\n    }\n    constexpr\
    \ modint operator--(int) {\n        modint res = *this;\n        --*this;\n  \
    \      return res;\n    }\n    constexpr modint& operator+=(const modint &r) {\n\
    \        x += r.x;\n        if (x >= m()) x -= m();\n        return *this;\n \
    \   }\n    constexpr modint& operator-=(const modint &r) {\n        x -= r.x;\n\
    \        if (x >= m()) x += m();\n        return *this;\n    }\n    constexpr\
    \ modint& operator*=(const modint &r) {\n        unsigned long long y = x;\n \
    \       y *= r.x;\n        x = (unsigned int)(y % m());\n        return *this;\n\
    \    }\n    constexpr modint &operator/=(const modint &r) {\n        return *this\
    \ = *this * r.inv();\n    }\n    friend constexpr modint operator+(const modint\
    \ &a, const modint &b) {\n        return modint(a) += b;\n    }\n    friend constexpr\
    \ modint operator-(const modint &a, const modint &b) {\n        return modint(a)\
    \ -= b;\n    }\n    friend constexpr modint operator*(const modint &a, const modint\
    \ &b) {\n        return modint(a) *= b;\n    }\n    friend constexpr modint operator/(const\
    \ modint &a, const modint &b) {\n        return modint(a) /= b;\n    }\n    friend\
    \ constexpr bool operator==(const modint &a, const modint &b) {\n        return\
    \ a.x == b.x;\n    }\n    friend constexpr bool operator!=(const modint &a, const\
    \ modint &b) {\n        return a.x != b.x;\n    }\n    constexpr modint operator+()\
    \ const { return *this; }\n    constexpr modint operator-() const { return modint()\
    \ - *this; }\n    constexpr modint pow(long long k) const {\n        assert(k\
    \ >= 0);\n        modint a = *this;\n        modint res = 1;\n        while (k\
    \ > 0) {\n            if (k & 1) res *= a;\n            a *= a;\n            k\
    \ >>= 1;\n        }\n        return res;\n    }\n    constexpr modint inv() const\
    \ {\n        long long a = x, b = m(), u = 1, v = 0;\n        while (b > 0) {\n\
    \            long long t = a / b;\n            a -= t * b;\n            swap(a,\
    \ b);\n            u -= t * v;\n            swap(u, v);\n        }\n        return\
    \ modint(u);\n    }\nprivate:\n    unsigned int x;\n    static constexpr unsigned\
    \ int m() { return MOD; }\n};\n#line 5 \"test/fps/fps_pow_sparse.test.cpp\"\n\n\
    using mint = modint<998244353>;\n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    int N, K;\n    long long M;\n    cin >> N >> K >>\
    \ M;\n    vector<pair<int, mint>> f_sub(K);\n    for (int i = 0; i < K; i++) {\n\
    \        int a, b;\n        cin >> a >> b;\n        f_sub[i] = {a, mint::raw(b)};\n\
    \    }\n    auto f = fps_pow_sparse(f_sub, N, M);\n    for (int i = 0; i < N;\
    \ i++) cout << f[i].val() << \" \\n\"[i + 1 == N];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse\"\
    \n\n#include \"../../src/fps/fps_pow_sparse.hpp\"\n#include \"../../src/modint/modint.hpp\"\
    \n\nusing mint = modint<998244353>;\n\n#include <iostream>\n\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N, K;\n    long\
    \ long M;\n    cin >> N >> K >> M;\n    vector<pair<int, mint>> f_sub(K);\n  \
    \  for (int i = 0; i < K; i++) {\n        int a, b;\n        cin >> a >> b;\n\
    \        f_sub[i] = {a, mint::raw(b)};\n    }\n    auto f = fps_pow_sparse(f_sub,\
    \ N, M);\n    for (int i = 0; i < N; i++) cout << f[i].val() << \" \\n\"[i + 1\
    \ == N];\n}"
  dependsOn:
  - src/fps/fps_pow_sparse.hpp
  - src/modint/modint.hpp
  isVerificationFile: true
  path: test/fps/fps_pow_sparse.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:06:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/fps/fps_pow_sparse.test.cpp
layout: document
redirect_from:
- /verify/test/fps/fps_pow_sparse.test.cpp
- /verify/test/fps/fps_pow_sparse.test.cpp.html
title: test/fps/fps_pow_sparse.test.cpp
---
