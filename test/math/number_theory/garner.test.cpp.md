---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/number_theory/extended_gcd.hpp
    title: src/math/number_theory/extended_gcd.hpp
  - icon: ':question:'
    path: src/math/number_theory/factorise.hpp
    title: src/math/number_theory/factorise.hpp
  - icon: ':question:'
    path: src/math/number_theory/garner.hpp
    title: src/math/number_theory/garner.hpp
  - icon: ':question:'
    path: src/math/number_theory/primality_test.hpp
    title: src/math/number_theory/primality_test.hpp
  - icon: ':question:'
    path: src/math/number_theory/prime_factor.hpp
    title: src/math/number_theory/prime_factor.hpp
  - icon: ':question:'
    path: src/modint/dynamic_montgomery_modint.hpp
    title: src/modint/dynamic_montgomery_modint.hpp
  - icon: ':question:'
    path: src/random/xor_shift.hpp
    title: src/random/xor_shift.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/187
    links:
    - https://yukicoder.me/problems/no/187
  bundledCode: "#line 1 \"test/math/number_theory/garner.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/187\"\n\n#line 2 \"src/math/number_theory/factorise.hpp\"\
    \n#include <vector>\n#line 2 \"src/math/number_theory/prime_factor.hpp\"\n#include\
    \ <numeric>\n#line 2 \"src/modint/dynamic_montgomery_modint.hpp\"\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\n\nstruct dynamic_montgomery_modint {\n\
    \    using i64 = __uint64_t;\n    using i128 = __uint128_t;\n    using modint\
    \ = dynamic_montgomery_modint;\n    dynamic_montgomery_modint() : x(0) {}\n  \
    \  dynamic_montgomery_modint(long long v) : x(reduce((i128(v) + MOD) * R)) {}\n\
    \    static void set_mod(long long _m) {\n        MOD = _m;\n        R = -i128(MOD)\
    \ % MOD;\n        INV = get_inv_mod(); \n    }\n    static long long mod() { return\
    \ MOD; }\n    long long val() const {\n        i64 res = reduce(x);\n        return\
    \ res >= MOD ? res - MOD : res;\n    }\n    modint& operator+=(const modint &r)\
    \ {\n        x += r.x;\n        if (x >= (MOD << 1)) x -= (MOD << 1);\n      \
    \  return *this;\n    }\n    modint& operator-=(const modint &r) {\n        x\
    \ += (MOD << 1) - r.x;\n        if (x >= (MOD << 1)) x -= (MOD << 1);\n      \
    \  return *this;\n    }\n    modint& operator*=(const modint &r) {\n        x\
    \ = reduce(i128(x) * r.x);\n        return *this;\n    }\n    modint& operator/=(const\
    \ modint &r) {\n        *this *= r.inv();\n        return *this;\n    }\n    friend\
    \ modint operator+(const modint &a, const modint &b) {\n        return modint(a)\
    \ += b;\n    }\n    friend modint operator-(const modint &a, const modint &b)\
    \ {\n        return modint(a) -= b;\n    }\n    friend modint operator*(const\
    \ modint &a, const modint &b) {\n        return modint(a) *= b;\n    }\n    friend\
    \ modint operator/(const modint &a, const modint &b) {\n        return modint(a)\
    \ /= b;\n    }\n    friend bool operator==(const modint &a, const modint &b) {\n\
    \        return a.val() == b.val();\n    }\n    friend bool operator!=(const modint\
    \ &a, const modint &b) {\n        return a.val() != b.val();\n    }\n    modint\
    \ operator+() const { return *this; }\n    modint operator-() const { return modint()\
    \ - *this; }\n    modint inv() const { return pow(MOD - 2); }\n    modint pow(i128\
    \ k) const {\n        modint a = *this;\n        modint res = 1;\n        while\
    \ (k > 0) {\n            if (k & 1) res *= a;\n            a *= a;\n         \
    \   k >>= 1;\n        }\n        return res;\n    }\nprivate:\n    i64 x;\n  \
    \  static i64 MOD, INV, R;\n    static i64 get_inv_mod() {\n        i64 res =\
    \ MOD;\n        for (int t = 0; t < 5; t++) res *= 2 - MOD * res;\n        return\
    \ res;\n    }\n    static i64 reduce(const i128 &v) {\n        return (v + i128(i64(v)\
    \ * i64(-INV)) * MOD) >> 64;\n    }\n};\ntypename dynamic_montgomery_modint::i64\n\
    dynamic_montgomery_modint::MOD,\ndynamic_montgomery_modint::INV,\ndynamic_montgomery_modint::R;\n\
    #line 2 \"src/random/xor_shift.hpp\"\n#include <cstdint>\n#include <type_traits>\n\
    using namespace std;\n\ntemplate<typename T>\nstruct xor_shift {\n    using U\
    \ = typename make_unsigned<T>::type;\n    constexpr xor_shift(U seed) : x(seed\
    \ == 0 ? 987139873 : seed) {}\n    constexpr U operator()() {\n        if constexpr\
    \ (sizeof(T) <= 4) {\n            x ^= x << 13;\n            x ^= x >> 17;\n \
    \           x ^= x << 5;\n        } else {\n            x ^= x << 13;\n      \
    \      x ^= x >> 7;\n            x ^= x << 17;\n        }\n        return x;\n\
    \    }\n    constexpr T operator()(T low, T hi) {\n        return low + (*this)()\
    \ % (hi - low + 1);\n    }\nprivate:\n    U x;\n};\n#line 2 \"src/math/number_theory/primality_test.hpp\"\
    \n#include <array>\n#line 4 \"src/math/number_theory/primality_test.hpp\"\nusing\
    \ namespace std;\n\ntemplate<size_t size>\nbool miller_rabin(long long m, const\
    \ array<int, size> &ps) {\n    using mint = dynamic_montgomery_modint;\n    mint::set_mod(m);\n\
    \    long long u = 0, v = m - 1;\n    while ((v & 1) == 0) u++, v >>= 1;\n   \
    \ for (int p : ps) {\n        if (m <= p) return true;\n        mint x = mint(p).pow(v);\n\
    \        if (x.val() != 1) {\n            long long w;\n            for (w = 0;\
    \ w < u; w++) {\n                if (x.val() == m - 1) break;\n              \
    \  x *= x;\n            }\n            if (w == u) return false;\n        }\n\
    \    }\n    return true;\n}\n\ninline bool miller_rabin_small(long long m) {\n\
    \    return miller_rabin(m, array<int, 3>{2, 7, 61});\n}\n\ninline bool miller_rabin_large(long\
    \ long m) {\n    return miller_rabin(m, array<int, 7>{2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022});\n}\n\ninline bool is_prime(long long m) {\n    if (m\
    \ <= 1) return false;\n    if (m == 2) return true;\n    if (m % 2 == 0) return\
    \ false;\n    return m < 4759123141LL ? miller_rabin_small(m) : miller_rabin_large(m);\n\
    }\n#line 7 \"src/math/number_theory/prime_factor.hpp\"\nusing namespace std;\n\
    \ntemplate<typename T>\nT rho(T n) {\n    for (int p : {2, 3, 5, 7}) {\n     \
    \   if (n % p == 0) return p;\n    }\n    using mint = dynamic_montgomery_modint;\n\
    \    mint::set_mod(n);\n    xor_shift<T> eng(n);\n    while (true) {\n       \
    \ mint u = eng(2, n - 1);\n        mint v = u;\n        mint c = eng(1, n - 1);\n\
    \        T d = 1;\n        while (d == 1) {\n            u = u * u - c;\n    \
    \        v = v * v - c;\n            v = v * v - c;\n            d = gcd((u -\
    \ v).val(), n);\n        }\n        if (d < n) return d;\n    }\n    return -1;\n\
    }\n\ntemplate<typename T>\nvector<T> prime_factor(T n) {\n    if (n <= 1) return\
    \ {};\n    if (is_prime(n)) return {n};\n    vector<T> res;\n    T d = rho(n);\n\
    \    auto a = prime_factor(d);\n    auto b = prime_factor(n / d);\n    merge(a.begin(),\
    \ a.end(), b.begin(), b.end(), back_inserter(res));\n    res.erase(unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n#line 4 \"src/math/number_theory/factorise.hpp\"\
    \nusing namespace std;\n\nvector<pair<long long, int>> factorise(long long n)\
    \ {\n    auto ps = prime_factor(n);\n    vector<pair<long long, int>> res;\n \
    \   res.reserve(ps.size());\n    for (auto p : ps) {\n        res.emplace_back(p,\
    \ 0);\n        while (n % p == 0) {\n            res.back().second++;\n      \
    \      n /= p;\n        }\n    }\n    return res;\n}\n#line 2 \"src/math/number_theory/extended_gcd.hpp\"\
    \n#include <utility>\nusing namespace std;\n\n// find x, y s.t. ax + by = gcd(a,\
    \ b) and return gcd(a, b)\ntemplate<typename T>\nT extended_gcd(T a, T b, T &x,\
    \ T &y) {\n    T g = a;\n    if (b != 0) {\n        g = extended_gcd(b, a % b,\
    \ y, x);\n        y -= (a / b) * x;\n    } else {\n        x = 1;\n        y =\
    \ 0;\n    }\n    return g;\n}\n#line 4 \"src/math/number_theory/garner.hpp\"\n\
    using namespace std;\n\nlong long garner(const vector<long long> &rems, vector<long\
    \ long> mods, long long mod) {\n    mods.push_back(mod);\n    int n = mods.size();\n\
    \    vector<long long> c1(n, 1), c2(n, 0);\n    for (int i = 0; i < n - 1; i++)\
    \ {\n        long long m = mods[i], a = c1[i], b = (rems[i] - c2[i]) % m;\n  \
    \      if (b < 0) b += m;\n        long long x, y;\n        long long g = extended_gcd(a,\
    \ m, x, y);\n        if (b % g != 0) return -1;\n        m /= g, b /= g;\n   \
    \     x %= m;\n        if (x < 0) x += m;\n        long long t = x * b % m;\n\
    \        for (int j = i + 1; j < n; j++) {\n            c2[j] = (t * c1[j] + c2[j])\
    \ % mods[j];\n            c1[j] = c1[j] * m % mods[j];\n        }\n    }\n   \
    \ return c2.back();\n}\n#line 5 \"test/math/number_theory/garner.test.cpp\"\n\n\
    #include <map>\n#line 8 \"test/math/number_theory/garner.test.cpp\"\n#include\
    \ <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    const long long mod = 1e9 + 7;\n    int N;\n    cin >> N;\n    vector<long\
    \ long> X(N), Y(N);\n    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];\n  \
    \  if (count(X.begin(), X.end(), 0) == N) {\n        assert(garner(X, Y, mod)\
    \ == 0);\n        map<int, int> fc;\n        for (int i = 0; i < N; i++) {\n \
    \           for (auto [p, e] : factorise(Y[i])) fc[p] = max(fc[p], e);\n     \
    \   }\n        long long L = 1;\n        for (auto [p, e] : fc) {\n          \
    \  while (e--) L = (L * p) % mod;\n        }\n        cout << L << '\\n';\n  \
    \      return 0;\n    }\n    cout << garner(X, Y, mod) << endl;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/187\"\n\n#include \"../../../src/math/number_theory/factorise.hpp\"\
    \n#include \"../../../src/math/number_theory/garner.hpp\"\n\n#include <map>\n\
    #include <algorithm>\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    const long long mod = 1e9 + 7;\n    int N;\n    cin\
    \ >> N;\n    vector<long long> X(N), Y(N);\n    for (int i = 0; i < N; i++) cin\
    \ >> X[i] >> Y[i];\n    if (count(X.begin(), X.end(), 0) == N) {\n        assert(garner(X,\
    \ Y, mod) == 0);\n        map<int, int> fc;\n        for (int i = 0; i < N; i++)\
    \ {\n            for (auto [p, e] : factorise(Y[i])) fc[p] = max(fc[p], e);\n\
    \        }\n        long long L = 1;\n        for (auto [p, e] : fc) {\n     \
    \       while (e--) L = (L * p) % mod;\n        }\n        cout << L << '\\n';\n\
    \        return 0;\n    }\n    cout << garner(X, Y, mod) << endl;\n}"
  dependsOn:
  - src/math/number_theory/factorise.hpp
  - src/math/number_theory/prime_factor.hpp
  - src/modint/dynamic_montgomery_modint.hpp
  - src/random/xor_shift.hpp
  - src/math/number_theory/primality_test.hpp
  - src/math/number_theory/garner.hpp
  - src/math/number_theory/extended_gcd.hpp
  isVerificationFile: true
  path: test/math/number_theory/garner.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:16:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/number_theory/garner.test.cpp
layout: document
redirect_from:
- /verify/test/math/number_theory/garner.test.cpp
- /verify/test/math/number_theory/garner.test.cpp.html
title: test/math/number_theory/garner.test.cpp
---
