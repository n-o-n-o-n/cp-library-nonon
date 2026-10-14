---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/convolution/bitwise_or_convolution.hpp
    title: src/convolution/bitwise_or_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: src/convolution/subset_zmt.hpp
    title: src/convolution/subset_zmt.hpp
  - icon: ':question:'
    path: src/modint/modint.hpp
    title: src/modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/convolution/bitwise_or_convolution.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"src/convolution/bitwise_or_convolution.hpp\"\
    \n#include <cassert>\n#include <vector>\nusing namespace std;\n#line 4 \"src/convolution/subset_zmt.hpp\"\
    \nusing namespace std;\n\ntemplate<typename mint>\nvoid subset_zmt(vector<mint>\
    \ &f, bool moebius = false) {\n    int n = f.size();\n    assert((n & (n - 1))\
    \ == 0);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if (i & j) continue;\n            f[i | j] += moebius ?\
    \ -f[j] : f[j];\n        }\n    }\n}\n#line 6 \"src/convolution/bitwise_or_convolution.hpp\"\
    \n\ntemplate<typename mint>\nvector<mint> bitwise_or_convolution(vector<mint>\
    \ f, vector<mint> g) {\n    assert(f.size() == g.size());\n    int n = f.size();\n\
    \    assert((n & (n - 1)) == 0);\n    if (n == 0) return {};\n    subset_zmt(f);\n\
    \    subset_zmt(g);\n    for (int i = 0; i < n; i++) f[i] *= g[i];\n    subset_zmt(f,\
    \ true);\n    return f;\n}\n#line 2 \"src/modint/modint.hpp\"\n#include <algorithm>\n\
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
    };\n#line 5 \"test/convolution/bitwise_or_convolution.test.cpp\"\n\nusing mint\
    \ = modint<998244353>;\n\n#include <iostream>\n#include <random>\n\nvector<mint>\
    \ naive(vector<mint> f, vector<mint> g) {\n    int n = f.size();\n    vector<mint>\
    \ h(n);\n    for (int i = 0; i < n; i++) {\n        for (int j = 0; j < n; j++)\
    \ h[i | j] += f[i] * g[j];\n    }\n    return h;\n}\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    {\n        int A, B;\n        cin >> A >> B;\n   \
    \     cout << A + B << '\\n';\n    }\n    mt19937 eng(353442899);\n    for (int\
    \ t = 0; t < 20; t++) {\n        int N = eng() % 11;\n        vector<mint> f(1\
    \ << N), g(1 << N);\n        for (auto &e : f) e = eng() % mint::mod();\n    \
    \    for (auto &e : g) e = eng() % mint::mod();\n        assert(naive(f, g) ==\
    \ bitwise_or_convolution(f, g));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../src/convolution/bitwise_or_convolution.hpp\"\n#include \"../../src/modint/modint.hpp\"\
    \n\nusing mint = modint<998244353>;\n\n#include <iostream>\n#include <random>\n\
    \nvector<mint> naive(vector<mint> f, vector<mint> g) {\n    int n = f.size();\n\
    \    vector<mint> h(n);\n    for (int i = 0; i < n; i++) {\n        for (int j\
    \ = 0; j < n; j++) h[i | j] += f[i] * g[j];\n    }\n    return h;\n}\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    {\n        int\
    \ A, B;\n        cin >> A >> B;\n        cout << A + B << '\\n';\n    }\n    mt19937\
    \ eng(353442899);\n    for (int t = 0; t < 20; t++) {\n        int N = eng() %\
    \ 11;\n        vector<mint> f(1 << N), g(1 << N);\n        for (auto &e : f) e\
    \ = eng() % mint::mod();\n        for (auto &e : g) e = eng() % mint::mod();\n\
    \        assert(naive(f, g) == bitwise_or_convolution(f, g));\n    }\n}"
  dependsOn:
  - src/convolution/bitwise_or_convolution.hpp
  - src/convolution/subset_zmt.hpp
  - src/modint/modint.hpp
  isVerificationFile: true
  path: test/convolution/bitwise_or_convolution.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:06:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/convolution/bitwise_or_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/convolution/bitwise_or_convolution.test.cpp
- /verify/test/convolution/bitwise_or_convolution.test.cpp.html
title: test/convolution/bitwise_or_convolution.test.cpp
---
