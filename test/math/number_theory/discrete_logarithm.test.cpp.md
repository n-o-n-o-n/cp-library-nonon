---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/affine.hpp
    title: src/math/affine.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/number_theory/discrete_logarithm.hpp
    title: src/math/number_theory/discrete_logarithm.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/number_theory/primality_test.hpp
    title: src/math/number_theory/primality_test.hpp
  - icon: ':heavy_check_mark:'
    path: src/modint/dynamic_modint.hpp
    title: src/modint/dynamic_modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/modint/dynamic_montgomery_modint.hpp
    title: src/modint/dynamic_montgomery_modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/random/utility.hpp
    title: src/random/utility.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/abc270/submissions/62690414
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/math/number_theory/discrete_logarithm.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"src/random/utility.hpp\"\
    \n#include <cassert>\n#include <concepts>\n#include <random>\nusing namespace\
    \ std;\n\nnamespace rng {\n\ninline random_device seed;\ninline mt19937 eng(seed());\n\
    \ntemplate<typename T>\nvoid set_seed(const T &sd) {\n    eng.seed(sd);\n}\n\n\
    template<integral T>\ninline T randint(T lo, T hi) {\n    assert(lo <= hi);\n\
    \    uniform_int_distribution<T> dist(lo, hi);\n    return dist(eng);\n}\n\ntemplate<integral\
    \ T>\ninline pair<T, T> randpair(T lo, T hi, bool strict = false) {\n    assert(lo\
    \ + strict <= hi);\n    T l = randint(lo, hi - strict);\n    T r = randint(l +\
    \ strict, hi);\n    return make_pair(l, r);\n}\n\n} // namespace rng\n#line 2\
    \ \"src/math/number_theory/primality_test.hpp\"\n#include <array>\n#line 2 \"\
    src/modint/dynamic_montgomery_modint.hpp\"\n#include <algorithm>\n#line 4 \"src/modint/dynamic_montgomery_modint.hpp\"\
    \nusing namespace std;\n\nstruct dynamic_montgomery_modint {\n    using i64 =\
    \ __uint64_t;\n    using i128 = __uint128_t;\n    using modint = dynamic_montgomery_modint;\n\
    \    dynamic_montgomery_modint() : x(0) {}\n    dynamic_montgomery_modint(long\
    \ long v) : x(reduce((i128(v) + MOD) * R)) {}\n    static void set_mod(long long\
    \ _m) {\n        MOD = _m;\n        R = -i128(MOD) % MOD;\n        INV = get_inv_mod();\
    \ \n    }\n    static long long mod() { return MOD; }\n    long long val() const\
    \ {\n        i64 res = reduce(x);\n        return res >= MOD ? res - MOD : res;\n\
    \    }\n    modint& operator+=(const modint &r) {\n        x += r.x;\n       \
    \ if (x >= (MOD << 1)) x -= (MOD << 1);\n        return *this;\n    }\n    modint&\
    \ operator-=(const modint &r) {\n        x += (MOD << 1) - r.x;\n        if (x\
    \ >= (MOD << 1)) x -= (MOD << 1);\n        return *this;\n    }\n    modint& operator*=(const\
    \ modint &r) {\n        x = reduce(i128(x) * r.x);\n        return *this;\n  \
    \  }\n    modint& operator/=(const modint &r) {\n        *this *= r.inv();\n \
    \       return *this;\n    }\n    friend modint operator+(const modint &a, const\
    \ modint &b) {\n        return modint(a) += b;\n    }\n    friend modint operator-(const\
    \ modint &a, const modint &b) {\n        return modint(a) -= b;\n    }\n    friend\
    \ modint operator*(const modint &a, const modint &b) {\n        return modint(a)\
    \ *= b;\n    }\n    friend modint operator/(const modint &a, const modint &b)\
    \ {\n        return modint(a) /= b;\n    }\n    friend bool operator==(const modint\
    \ &a, const modint &b) {\n        return a.val() == b.val();\n    }\n    friend\
    \ bool operator!=(const modint &a, const modint &b) {\n        return a.val()\
    \ != b.val();\n    }\n    modint operator+() const { return *this; }\n    modint\
    \ operator-() const { return modint() - *this; }\n    modint inv() const { return\
    \ pow(MOD - 2); }\n    modint pow(i128 k) const {\n        modint a = *this;\n\
    \        modint res = 1;\n        while (k > 0) {\n            if (k & 1) res\
    \ *= a;\n            a *= a;\n            k >>= 1;\n        }\n        return\
    \ res;\n    }\nprivate:\n    i64 x;\n    static i64 MOD, INV, R;\n    static i64\
    \ get_inv_mod() {\n        i64 res = MOD;\n        for (int t = 0; t < 5; t++)\
    \ res *= 2 - MOD * res;\n        return res;\n    }\n    static i64 reduce(const\
    \ i128 &v) {\n        return (v + i128(i64(v) * i64(-INV)) * MOD) >> 64;\n   \
    \ }\n};\ntypename dynamic_montgomery_modint::i64\ndynamic_montgomery_modint::MOD,\n\
    dynamic_montgomery_modint::INV,\ndynamic_montgomery_modint::R;\n#line 4 \"src/math/number_theory/primality_test.hpp\"\
    \nusing namespace std;\n\ntemplate<size_t size>\nbool miller_rabin(long long m,\
    \ const array<int, size> &ps) {\n    using mint = dynamic_montgomery_modint;\n\
    \    mint::set_mod(m);\n    long long u = 0, v = m - 1;\n    while ((v & 1) ==\
    \ 0) u++, v >>= 1;\n    for (int p : ps) {\n        if (m <= p) return true;\n\
    \        mint x = mint(p).pow(v);\n        if (x.val() != 1) {\n            long\
    \ long w;\n            for (w = 0; w < u; w++) {\n                if (x.val()\
    \ == m - 1) break;\n                x *= x;\n            }\n            if (w\
    \ == u) return false;\n        }\n    }\n    return true;\n}\n\ninline bool miller_rabin_small(long\
    \ long m) {\n    return miller_rabin(m, array<int, 3>{2, 7, 61});\n}\n\ninline\
    \ bool miller_rabin_large(long long m) {\n    return miller_rabin(m, array<int,\
    \ 7>{2, 325, 9375, 28178, 450775, 9780504, 1795265022});\n}\n\ninline bool is_prime(long\
    \ long m) {\n    if (m <= 1) return false;\n    if (m == 2) return true;\n   \
    \ if (m % 2 == 0) return false;\n    return m < 4759123141LL ? miller_rabin_small(m)\
    \ : miller_rabin_large(m);\n}\n#line 4 \"src/modint/dynamic_modint.hpp\"\nusing\
    \ namespace std;\n\nstruct modint {\n    modint() : x(0) {}\n    modint(long long\
    \ v) {\n        long long y = v % m();\n        if (y < 0) y += m();\n       \
    \ x = (unsigned int)(y);\n    }\n    static void set_mod(int _m) { MOD = _m; }\n\
    \    static modint raw(int v) {\n        modint a;\n        a.x = v;\n       \
    \ return a;\n    }\n    static int mod() { return m(); }\n    unsigned int val()\
    \ const { return x; }\n    modint& operator++() {\n        x++;\n        if (x\
    \ == m()) x = 0;\n        return *this;\n    }\n    modint& operator--() {\n \
    \       if (x == 0) x = m();\n        x--;\n        return *this;\n    }\n   \
    \ modint operator++(int) {\n        modint res = *this;\n        ++*this;\n  \
    \      return res;\n    }\n    modint operator--(int) {\n        modint res =\
    \ *this;\n        --*this;\n        return res;\n    }\n    modint& operator+=(const\
    \ modint &r) {\n        x += r.x;\n        if (x >= m()) x -= m();\n        return\
    \ *this;\n    }\n    modint& operator-=(const modint &r) {\n        x -= r.x;\n\
    \        if (x >= m()) x += m();\n        return *this;\n    }\n    modint& operator*=(const\
    \ modint &r) {\n        unsigned long long y = x;\n        y *= r.x;\n       \
    \ x = (unsigned int)(y % m());\n        return *this;\n    }\n    modint &operator/=(const\
    \ modint &r) {\n        return *this = *this * r.inv();\n    }\n    friend modint\
    \ operator+(const modint &a, const modint &b) {\n        return modint(a) += b;\n\
    \    }\n    friend modint operator-(const modint &a, const modint &b) {\n    \
    \    return modint(a) -= b;\n    }\n    friend modint operator*(const modint &a,\
    \ const modint &b) {\n        return modint(a) *= b;\n    }\n    friend modint\
    \ operator/(const modint &a, const modint &b) {\n        return modint(a) /= b;\n\
    \    }\n    friend bool operator==(const modint &a, const modint &b) {\n     \
    \   return a.x == b.x;\n    }\n    friend bool operator!=(const modint &a, const\
    \ modint &b) {\n        return a.x != b.x;\n    }\n    modint operator+() const\
    \ { return *this; }\n    modint operator-() const { return modint() - *this; }\n\
    \    modint pow(long long k) const {\n        assert(k >= 0);\n        modint\
    \ a = *this;\n        modint res = 1;\n        while (k > 0) {\n            if\
    \ (k & 1) res *= a;\n            a *= a;\n            k >>= 1;\n        }\n  \
    \      return res;\n    }\n    modint inv() const {\n        long long a = x,\
    \ b = m(), u = 1, v = 0;\n        while (b > 0) {\n            long long t = a\
    \ / b;\n            a -= t * b;\n            swap(a, b);\n            u -= t *\
    \ v;\n            swap(u, v);\n        }\n        return modint(u);\n    }\nprivate:\n\
    \    unsigned int x;\n    static unsigned int MOD;\n    static unsigned int m()\
    \ { return MOD; }\n};\nunsigned int modint::MOD = -1;\n#line 2 \"src/math/affine.hpp\"\
    \nusing namespace std;\n\ntemplate<typename mint>\nstruct affine {\n    mint a,\
    \ b;\n    affine() : a(1), b(0) {}\n    affine(const mint &_a, const mint &_b)\
    \ : a(_a), b(_b) {}\n    mint operator()(const mint &x) const {\n        return\
    \ a * x + b;\n    }\n    affine operator()(const affine &f) const {\n        mint\
    \ c = a * f.a;\n        mint d = a * f.b + b;\n        return affine(c, d);\n\
    \    }\n};\n#line 2 \"src/math/number_theory/discrete_logarithm.hpp\"\n#include\
    \ <unordered_set>\nusing namespace std;\n\ntemplate<typename ActSet>\nstruct discrete_logarithm\
    \ {\n    using S = typename ActSet::S;\n    using F = typename ActSet::F;\n  \
    \  template<typename H>\n    static long long solve(F f, S s, S t, long long p,\
    \ const H &h) {\n        long long ht = h(t);\n        long long m = 1;\n    \
    \    do {\n            m++;\n        } while (m * m <= p);\n        unordered_set<long\
    \ long> a;\n        a.reserve(m);\n        for (int k = 0; k < m; k++) {\n   \
    \         t = ActSet::mapping(f, t);\n            a.insert(h(t));\n        }\n\
    \        F g = ActSet::id();\n        {\n            long long mm = m;\n     \
    \       F ff = f;\n            while (m > 0) {\n                if (m & 1) g =\
    \ ActSet::comp(g, f);\n                f = ActSet::comp(f, f);\n             \
    \   m >>= 1;\n            }\n            m = mm;\n            f = ff;\n      \
    \  }\n        for (int k = 0, flag = 0; k <= m; k++) {\n            t = ActSet::mapping(g,\
    \ s);\n            if (a.count(h(t))) {\n                for (int i = 0; i < m;\
    \ i++) {\n                    if (h(s) == ht) {\n                        return\
    \ m * k + i;\n                    }\n                    s = ActSet::mapping(f,\
    \ s);\n                }\n                if (flag) return -1;\n             \
    \   flag = 1;\n            }\n            s = t;\n        }\n        return -1;\n\
    \    }\n};\n#line 8 \"test/math/number_theory/discrete_logarithm.test.cpp\"\n\n\
    using mint = modint;\n\n#include <iostream>\n\n// https://atcoder.jp/contests/abc270/submissions/62690414\n\
    namespace AC {\n\ntemplate<typename mint>\nstruct affine {\n    mint a, b;\n \
    \   affine() : a(1), b(0) {}\n    affine(const mint &_a, const mint &_b) : a(_a),\
    \ b(_b) {}\n    mint operator()(const mint &x) const {\n        return a * x +\
    \ b;\n    }\n    affine operator()(const affine &f) const {\n        mint c =\
    \ a * f.a;\n        mint d = a * f.b + b;\n        return affine(c, d);\n    }\n\
    };\n\ntemplate<typename ActSet>\nstruct discrete_logarithm {\n    using S = typename\
    \ ActSet::S;\n    using F = typename ActSet::F;\n    template<typename H>\n  \
    \  static long long solve(F f, S s, S t, long long p, const H &h) {\n        long\
    \ long ht = h(t);\n        long long m = 1;\n        do {\n            m++;\n\
    \        } while (m * m <= p);\n        unordered_set<long long> a;\n        a.reserve(m);\n\
    \        for (int k = 0; k < m; k++) {\n            t = ActSet::mapping(f, t);\n\
    \            a.insert(h(t));\n        }\n        F g = ActSet::id();\n       \
    \ {\n            long long mm = m;\n            F ff = f;\n            while (m\
    \ > 0) {\n                if (m & 1) g = ActSet::comp(g, f);\n               \
    \ f = ActSet::comp(f, f);\n                m >>= 1;\n            }\n         \
    \   m = mm;\n            f = ff;\n        }\n        for (int k = 0, flag = 0;\
    \ k <= m; k++) {\n            t = ActSet::mapping(g, s);\n            if (a.count(h(t)))\
    \ {\n                for (int i = 0; i < m; i++) {\n                    if (h(s)\
    \ == ht) {\n                        return m * k + i;\n                    }\n\
    \                    s = ActSet::mapping(f, s);\n                }\n         \
    \       if (flag) return -1;\n                flag = 1;\n            }\n     \
    \       s = t;\n        }\n        return -1;\n    }\n};\n\nstruct ActSet {\n\
    \    using S = mint;\n    using F = affine<mint>;\n    static F comp(F f, F g)\
    \ {\n        return f(g);\n    }\n    static F id() {\n        return F();\n \
    \   }\n    static S mapping(F f, S x) {\n        return f(x);\n    }\n};\n\nlong\
    \ long solve(int P, int A, int B, int S, int T) {\n    mint::set_mod(P);\n   \
    \ return discrete_logarithm<ActSet>::solve(affine<mint>(A, B), S, T, P, [&](mint\
    \ x){ return x.val(); });\n}\n\n} // namespace AC\n\nstruct ActSet {\n    using\
    \ S = mint;\n    using F = affine<mint>;\n    static F comp(F f, F g) {\n    \
    \    return f(g);\n    }\n    static F id() {\n        return F();\n    }\n  \
    \  static S mapping(F f, S x) {\n        return f(x);\n    }\n};\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    {\n        int\
    \ A, B;\n        cin >> A >> B;\n        cout << A + B << '\\n';\n    }\n    for\
    \ (int t = 0; t < 200; t++) {\n        int P = rng::randint(2, (int)1e9);\n  \
    \      while (!is_prime(P)) P = rng::randint(2, (int)1e9);\n        int A = rng::randint(0,\
    \ P - 1);\n        int B = rng::randint(0, P - 1);\n        int S = rng::randint(0,\
    \ P - 1);\n        int T = rng::randint(0, P - 1);\n        mint::set_mod(P);\n\
    \        auto ans = discrete_logarithm<ActSet>::solve(affine<mint>(A, B), S, T,\
    \ P, [&](mint x){ return x.val(); });\n        assert(ans == AC::solve(P, A, B,\
    \ S, T));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../src/random/utility.hpp\"\n#include \"../../../src/math/number_theory/primality_test.hpp\"\
    \n#include \"../../../src/modint/dynamic_modint.hpp\"\n#include \"../../../src/math/affine.hpp\"\
    \n#include \"../../../src/math/number_theory/discrete_logarithm.hpp\"\n\nusing\
    \ mint = modint;\n\n#include <iostream>\n\n// https://atcoder.jp/contests/abc270/submissions/62690414\n\
    namespace AC {\n\ntemplate<typename mint>\nstruct affine {\n    mint a, b;\n \
    \   affine() : a(1), b(0) {}\n    affine(const mint &_a, const mint &_b) : a(_a),\
    \ b(_b) {}\n    mint operator()(const mint &x) const {\n        return a * x +\
    \ b;\n    }\n    affine operator()(const affine &f) const {\n        mint c =\
    \ a * f.a;\n        mint d = a * f.b + b;\n        return affine(c, d);\n    }\n\
    };\n\ntemplate<typename ActSet>\nstruct discrete_logarithm {\n    using S = typename\
    \ ActSet::S;\n    using F = typename ActSet::F;\n    template<typename H>\n  \
    \  static long long solve(F f, S s, S t, long long p, const H &h) {\n        long\
    \ long ht = h(t);\n        long long m = 1;\n        do {\n            m++;\n\
    \        } while (m * m <= p);\n        unordered_set<long long> a;\n        a.reserve(m);\n\
    \        for (int k = 0; k < m; k++) {\n            t = ActSet::mapping(f, t);\n\
    \            a.insert(h(t));\n        }\n        F g = ActSet::id();\n       \
    \ {\n            long long mm = m;\n            F ff = f;\n            while (m\
    \ > 0) {\n                if (m & 1) g = ActSet::comp(g, f);\n               \
    \ f = ActSet::comp(f, f);\n                m >>= 1;\n            }\n         \
    \   m = mm;\n            f = ff;\n        }\n        for (int k = 0, flag = 0;\
    \ k <= m; k++) {\n            t = ActSet::mapping(g, s);\n            if (a.count(h(t)))\
    \ {\n                for (int i = 0; i < m; i++) {\n                    if (h(s)\
    \ == ht) {\n                        return m * k + i;\n                    }\n\
    \                    s = ActSet::mapping(f, s);\n                }\n         \
    \       if (flag) return -1;\n                flag = 1;\n            }\n     \
    \       s = t;\n        }\n        return -1;\n    }\n};\n\nstruct ActSet {\n\
    \    using S = mint;\n    using F = affine<mint>;\n    static F comp(F f, F g)\
    \ {\n        return f(g);\n    }\n    static F id() {\n        return F();\n \
    \   }\n    static S mapping(F f, S x) {\n        return f(x);\n    }\n};\n\nlong\
    \ long solve(int P, int A, int B, int S, int T) {\n    mint::set_mod(P);\n   \
    \ return discrete_logarithm<ActSet>::solve(affine<mint>(A, B), S, T, P, [&](mint\
    \ x){ return x.val(); });\n}\n\n} // namespace AC\n\nstruct ActSet {\n    using\
    \ S = mint;\n    using F = affine<mint>;\n    static F comp(F f, F g) {\n    \
    \    return f(g);\n    }\n    static F id() {\n        return F();\n    }\n  \
    \  static S mapping(F f, S x) {\n        return f(x);\n    }\n};\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    {\n        int\
    \ A, B;\n        cin >> A >> B;\n        cout << A + B << '\\n';\n    }\n    for\
    \ (int t = 0; t < 200; t++) {\n        int P = rng::randint(2, (int)1e9);\n  \
    \      while (!is_prime(P)) P = rng::randint(2, (int)1e9);\n        int A = rng::randint(0,\
    \ P - 1);\n        int B = rng::randint(0, P - 1);\n        int S = rng::randint(0,\
    \ P - 1);\n        int T = rng::randint(0, P - 1);\n        mint::set_mod(P);\n\
    \        auto ans = discrete_logarithm<ActSet>::solve(affine<mint>(A, B), S, T,\
    \ P, [&](mint x){ return x.val(); });\n        assert(ans == AC::solve(P, A, B,\
    \ S, T));\n    }\n}"
  dependsOn:
  - src/random/utility.hpp
  - src/math/number_theory/primality_test.hpp
  - src/modint/dynamic_montgomery_modint.hpp
  - src/modint/dynamic_modint.hpp
  - src/math/affine.hpp
  - src/math/number_theory/discrete_logarithm.hpp
  isVerificationFile: true
  path: test/math/number_theory/discrete_logarithm.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:16:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/number_theory/discrete_logarithm.test.cpp
layout: document
redirect_from:
- /verify/test/math/number_theory/discrete_logarithm.test.cpp
- /verify/test/math/number_theory/discrete_logarithm.test.cpp.html
title: test/math/number_theory/discrete_logarithm.test.cpp
---
