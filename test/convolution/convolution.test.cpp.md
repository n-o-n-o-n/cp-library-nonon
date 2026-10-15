---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/convolution/convolution.hpp
    title: src/convolution/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: src/convolution/ntt.hpp
    title: src/convolution/ntt.hpp
  - icon: ':question:'
    path: src/math/number_theory/primality_test.hpp
    title: src/math/number_theory/primality_test.hpp
  - icon: ':question:'
    path: src/math/number_theory/prime_factor.hpp
    title: src/math/number_theory/prime_factor.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/number_theory/primitive_root.hpp
    title: src/math/number_theory/primitive_root.hpp
  - icon: ':question:'
    path: src/modint/dynamic_montgomery_modint.hpp
    title: src/modint/dynamic_montgomery_modint.hpp
  - icon: ':question:'
    path: src/modint/modint.hpp
    title: src/modint/modint.hpp
  - icon: ':question:'
    path: src/random/xor_shift.hpp
    title: src/random/xor_shift.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/convolution/convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#line 2 \"src/convolution/convolution.hpp\"\
    \n#include <vector>\n#line 2 \"src/modint/dynamic_montgomery_modint.hpp\"\n#include\
    \ <algorithm>\n#include <cassert>\nusing namespace std;\n\nstruct dynamic_montgomery_modint\
    \ {\n    using i64 = __uint64_t;\n    using i128 = __uint128_t;\n    using modint\
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
    #line 2 \"src/math/number_theory/prime_factor.hpp\"\n#include <numeric>\n#line\
    \ 2 \"src/random/xor_shift.hpp\"\n#include <cstdint>\n#include <type_traits>\n\
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
    \ res.end()), res.end());\n    return res;\n}\n#line 5 \"src/math/number_theory/primitive_root.hpp\"\
    \nusing namespace std;\n\nlong long primitive_root(long long m) {\n    assert(is_prime(m));\n\
    \    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    if (m == 1224736769) return 3;\n    auto ps = prime_factor(m - 1);\n\
    \    using mint = dynamic_montgomery_modint;\n    mint::set_mod(m);\n    xor_shift<unsigned\
    \ long long> eng(m);\n    mint a = eng(1, m - 1);\n    while ([&] {\n        for\
    \ (auto p : ps) {\n            if (a.pow((m - 1) / p) == 1) return true;\n   \
    \     }\n        return false;\n    } ()) a = eng(1, m - 1);\n    return a.val();\n\
    }\n#line 4 \"src/convolution/ntt.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ mint>\nstruct Number_Theoretic_Transform {\n    static mint get_root() {\n \
    \       init();\n        return root;\n    }\n    template<typename Vector>\n\
    \    static void ntt(Vector &f) {\n        init();\n        int n = f.size();\n\
    \        assert((n & (n - 1)) == 0);\n        int h = 0;\n        while ((1 <<\
    \ h) < n) h++;\n        int len = 0;\n        while (len < h) {\n            if\
    \ (len == h - 1) {\n                int p = 1 << (h - len - 1);\n            \
    \    mint r = 1;\n                for (int s = 0; s < 1 << len; s++) {\n     \
    \               int j = s << (h - len);\n                    for (int i = 0; i\
    \ < p; i++) {\n                        mint a = f[i + j], b = f[i + j + p] * r;\n\
    \                        f[i + j] = a + b;\n                        f[i + j +\
    \ p] = a - b;\n                    }\n                    if (s + 1 != (1 << len))\
    \ {\n                        r *= rt2[__builtin_ctz(~s)];\n                  \
    \  }\n                }\n                len++;\n            } else {\n      \
    \          int p = 1 << (h - len - 2);\n                mint r = 1, imag = dw[2];\n\
    \                for (int s = 0; s < 1 << len; s++) {\n                    mint\
    \ r2 = r * r;\n                    mint r3 = r * r2;\n                    int\
    \ j = s << (h - len);\n                    for (int i = 0; i < p; i++) {\n   \
    \                     unsigned long long m2 = (unsigned long long)mod * mod;\n\
    \                        unsigned long long a0 = (unsigned long long)f[i + j].val();\n\
    \                        unsigned long long a1 = (unsigned long long)f[i + j +\
    \ p].val() * r.val();\n                        unsigned long long a2 = (unsigned\
    \ long long)f[i + j + p + p].val() * r2.val();\n                        unsigned\
    \ long long a3 = (unsigned long long)f[i + j + p + p + p].val() * r3.val();\n\
    \                        unsigned long long t0 = (unsigned long long)mint(m2 +\
    \ a1 - a3).val() * imag.val();\n                        unsigned long long t1\
    \ = m2 - a2;\n                        f[i + j] = a0 + a1 + a2 + a3;\n        \
    \                f[i + j + p] = a0 + a2 + (m2 + m2 - a1 - a3);\n             \
    \           f[i + j + p + p] = a0 + t0 + t1;\n                        f[i + j\
    \ + p + p + p] = a0 + t1 + (m2 - t0);\n                    }\n               \
    \     if (s + 1 != (1 << len)) {\n                        r *= rt3[__builtin_ctz(~s)];\n\
    \                    }\n                }\n                len += 2;\n       \
    \     }\n        }\n    }\n    template<typename Vector>\n    static void intt(Vector\
    \ &f) {\n        init();\n        int n = f.size();\n        assert((n & (n -\
    \ 1)) == 0);\n        int h = 0;\n        while ((1 << h) < n) h++;\n        int\
    \ len = h;\n        while (len > 0) {\n            if (len == 1) {\n         \
    \       len--;\n                int p = 1 << (h - len - 1);\n                mint\
    \ ir = 1;\n                for (int s = 0; s < 1 << len; s++) {\n            \
    \        int j = s << (h - len);\n                    for (int i = 0; i < p; i++)\
    \ {\n                        mint a = f[i + j], b = f[i + j + p];\n          \
    \              f[i + j] = a + b;\n                        f[i + j + p] = (a -\
    \ b) * ir;\n                    }\n                    if (s + 1 != (1 << len))\
    \ {\n                        ir *= irt2[__builtin_ctz(~s)];\n                \
    \    }\n                }\n            } else {\n                len -= 2;\n \
    \               int p = 1 << (h - len - 2);\n                mint ir = 1, iimag\
    \ = idw[2];\n                for (int s = 0; s < 1 << len; s++) {\n          \
    \          mint ir2 = ir * ir;\n                    mint ir3 = ir * ir2;\n   \
    \                 int j = s << (h - len);\n                    for (int i = 0;\
    \ i < p; i++) {\n                        unsigned long long a0 = (unsigned long\
    \ long)f[i + j].val();\n                        unsigned long long a1 = (unsigned\
    \ long long)f[i + j + p].val();\n                        unsigned long long a2\
    \ = (unsigned long long)f[i + j + p + p].val();\n                        unsigned\
    \ long long a3 = (unsigned long long)f[i + j + p + p + p].val();\n           \
    \             unsigned long long t0 = (unsigned long long)(mint(mod + a2 - a3)\
    \ * iimag).val();\n                        f[i + j] = a0 + a1 + a2 + a3;\n   \
    \                     f[i + j + p] = (mod + a0 - a1 + t0) * ir.val();\n      \
    \                  f[i + j + p + p] = (mod + mod + a0 + a1 - a2 - a3) * ir2.val();\n\
    \                        f[i + j + p + p + p] = (mod + mod + a0 - a1 - t0) * ir3.val();\n\
    \                    }\n                    if (s + 1 != (1 << len)) {\n     \
    \                   ir *= irt3[__builtin_ctz(~s)];\n                    }\n  \
    \              }\n            }\n        }\n        const mint invn = mint::raw(n).inv();\n\
    \        for (auto &e : f) e *= invn;\n    }\n    // f must be ntt-ed\n    template<typename\
    \ Vector>\n    static void doubling(Vector &f) {\n        init();\n        int\
    \ n = f.size();\n        if (n == 0) return;\n        assert((n & (n - 1)) ==\
    \ 0);\n        auto g = f;\n        intt(g);\n        mint w = root.pow((mint::mod()\
    \ - 1) / (2 * n)), pw = mint::raw(1);\n        for (int i = 0; i < n; i++) g[i]\
    \ *= pw, pw *= w;\n        ntt(g);\n        f.resize(2 * n);\n        for (int\
    \ i = 0; i < n; i++) f[i + n] = g[i];\n    }\nprivate:\n    Number_Theoretic_Transform()\
    \ = default;\n    static int log, mod;\n    static mint root;\n    static vector<mint>\
    \ dw, idw;\n    static vector<mint> rt2, irt2;\n    static vector<mint> rt3, irt3;\n\
    \    static void init() {\n        if (mod != -1) return;\n        mod = mint::mod();\n\
    \        root = primitive_root(mod);\n        while (!((mod - 1) >> log & 1))\
    \ log++;\n        dw = idw = rt2 = irt2 = rt3 = irt3 = vector<mint>(log + 1);\n\
    \        dw[log] = root.pow((mod - 1) >> log);\n        idw[log] = dw[log].inv();\n\
    \        for (int i = log - 1; i >= 0; i--) {\n            dw[i] = dw[i + 1] *\
    \ dw[i + 1];\n            idw[i] = idw[i + 1] * idw[i + 1];\n        }\n     \
    \   mint pd = 1, ipd = 1;\n        for (int i = 0; i < log - 1; i++) {\n     \
    \       rt2[i] = pd * dw[i + 2];\n            irt2[i] = ipd * idw[i + 2];\n  \
    \          pd *= idw[i + 2];\n            ipd *= dw[i + 2];\n        }\n     \
    \   pd = ipd = 1;\n        for (int i = 0; i < log - 2; i++) {\n            rt3[i]\
    \ = pd * dw[i + 3];\n            irt3[i] = ipd * idw[i + 3];\n            pd *=\
    \ idw[i + 3];\n            ipd *= dw[i + 3];\n        }\n    }\n};\ntemplate<typename\
    \ mint>\nint Number_Theoretic_Transform<mint>::log = 0;\ntemplate<typename mint>\n\
    int Number_Theoretic_Transform<mint>::mod = -1;\ntemplate<typename mint>\nmint\
    \ Number_Theoretic_Transform<mint>::root = -1;\ntemplate<typename mint>\nvector<mint>\
    \ Number_Theoretic_Transform<mint>::dw = vector<mint>();\ntemplate<typename mint>\n\
    vector<mint> Number_Theoretic_Transform<mint>::idw = vector<mint>();\ntemplate<typename\
    \ mint>\nvector<mint> Number_Theoretic_Transform<mint>::rt2 = vector<mint>();\n\
    template<typename mint>\nvector<mint> Number_Theoretic_Transform<mint>::irt2 =\
    \ vector<mint>();\ntemplate<typename mint>\nvector<mint> Number_Theoretic_Transform<mint>::rt3\
    \ = vector<mint>();\ntemplate<typename mint>\nvector<mint> Number_Theoretic_Transform<mint>::irt3\
    \ = vector<mint>();\n#line 4 \"src/convolution/convolution.hpp\"\nusing namespace\
    \ std;\n\ntemplate<typename mint>\nvector<mint> convolution(vector<mint> f, vector<mint>\
    \ g, int deg = -1) {\n    using NTT = Number_Theoretic_Transform<mint>;\n    int\
    \ n = f.size(), m = g.size();\n    if (n == 0 || m == 0) return {};\n    int sz\
    \ = 1;\n    while (sz < n + m - 1) sz <<= 1;\n    f.resize(sz);\n    NTT::ntt(f);\n\
    \    g.resize(sz);\n    NTT::ntt(g);\n    for (int i = 0; i < sz; i++) f[i] *=\
    \ g[i];\n    NTT::intt(f);\n    if (deg == -1) deg = n + m - 1;\n    f.resize(deg);\n\
    \    return f;\n}\n#line 4 \"src/modint/modint.hpp\"\nusing namespace std;\n\n\
    template<int MOD>\nstruct modint {\n    constexpr modint() : x(0) {}\n    constexpr\
    \ modint(long long v) {\n        long long y = v % m();\n        if (y < 0) y\
    \ += m();\n        x = (unsigned int)(y);\n    }\n    static constexpr modint\
    \ raw(int v) {\n        modint a;\n        a.x = v;\n        return a;\n    }\n\
    \    static constexpr int mod() { return m(); }\n    constexpr unsigned int val()\
    \ const { return x; }\n    constexpr modint& operator++() {\n        x++;\n  \
    \      if (x == m()) x = 0;\n        return *this;\n    }\n    constexpr modint&\
    \ operator--() {\n        if (x == 0) x = m();\n        x--;\n        return *this;\n\
    \    }\n    constexpr modint operator++(int) {\n        modint res = *this;\n\
    \        ++*this;\n        return res;\n    }\n    constexpr modint operator--(int)\
    \ {\n        modint res = *this;\n        --*this;\n        return res;\n    }\n\
    \    constexpr modint& operator+=(const modint &r) {\n        x += r.x;\n    \
    \    if (x >= m()) x -= m();\n        return *this;\n    }\n    constexpr modint&\
    \ operator-=(const modint &r) {\n        x -= r.x;\n        if (x >= m()) x +=\
    \ m();\n        return *this;\n    }\n    constexpr modint& operator*=(const modint\
    \ &r) {\n        unsigned long long y = x;\n        y *= r.x;\n        x = (unsigned\
    \ int)(y % m());\n        return *this;\n    }\n    constexpr modint &operator/=(const\
    \ modint &r) {\n        return *this = *this * r.inv();\n    }\n    friend constexpr\
    \ modint operator+(const modint &a, const modint &b) {\n        return modint(a)\
    \ += b;\n    }\n    friend constexpr modint operator-(const modint &a, const modint\
    \ &b) {\n        return modint(a) -= b;\n    }\n    friend constexpr modint operator*(const\
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
    };\n#line 5 \"test/convolution/convolution.test.cpp\"\n\nusing mint = modint<998244353>;\n\
    \n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N, M;\n    cin >> N >> M;\n    vector<mint> A(N), B(M);\n    for (auto\
    \ &e : A) { int x; cin >> x; e = x; }\n    for (auto &e : B) { int x; cin >> x;\
    \ e = x; }\n    auto C = convolution(A, B);\n    for (int i = 0; i < ssize(C);\
    \ i++) cout << C[i].val() << \" \\n\"[i + 1 == ssize(C)];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ \"../../src/convolution/convolution.hpp\"\n#include \"../../src/modint/modint.hpp\"\
    \n\nusing mint = modint<998244353>;\n\n#include <iostream>\n\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N, M;\n    cin\
    \ >> N >> M;\n    vector<mint> A(N), B(M);\n    for (auto &e : A) { int x; cin\
    \ >> x; e = x; }\n    for (auto &e : B) { int x; cin >> x; e = x; }\n    auto\
    \ C = convolution(A, B);\n    for (int i = 0; i < ssize(C); i++) cout << C[i].val()\
    \ << \" \\n\"[i + 1 == ssize(C)];\n}"
  dependsOn:
  - src/convolution/convolution.hpp
  - src/convolution/ntt.hpp
  - src/math/number_theory/primitive_root.hpp
  - src/modint/dynamic_montgomery_modint.hpp
  - src/math/number_theory/prime_factor.hpp
  - src/random/xor_shift.hpp
  - src/math/number_theory/primality_test.hpp
  - src/modint/modint.hpp
  isVerificationFile: true
  path: test/convolution/convolution.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:16:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/convolution/convolution.test.cpp
layout: document
redirect_from:
- /verify/test/convolution/convolution.test.cpp
- /verify/test/convolution/convolution.test.cpp.html
title: test/convolution/convolution.test.cpp
---
