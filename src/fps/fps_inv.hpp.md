---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/convolution/ntt.hpp
    title: src/convolution/ntt.hpp
  - icon: ':question:'
    path: src/fps/fps.hpp
    title: src/fps/fps.hpp
  - icon: ':question:'
    path: src/math/enumerative_combinatorics/combination.hpp
    title: src/math/enumerative_combinatorics/combination.hpp
  - icon: ':question:'
    path: src/math/number_theory/primality_test.hpp
    title: src/math/number_theory/primality_test.hpp
  - icon: ':question:'
    path: src/math/number_theory/prime_factor.hpp
    title: src/math/number_theory/prime_factor.hpp
  - icon: ':question:'
    path: src/math/number_theory/primitive_root.hpp
    title: src/math/number_theory/primitive_root.hpp
  - icon: ':question:'
    path: src/modint/dynamic_montgomery_modint.hpp
    title: src/modint/dynamic_montgomery_modint.hpp
  - icon: ':question:'
    path: src/random/xor_shift.hpp
    title: src/random/xor_shift.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/fps/fps_all.hpp
    title: src/fps/fps_all.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/fps_compositional_inverse.hpp
    title: src/fps/fps_compositional_inverse.hpp
  - icon: ':x:'
    path: src/fps/fps_composotion.hpp
    title: src/fps/fps_composotion.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/fps_log.hpp
    title: src/fps/fps_log.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/fps_pow.hpp
    title: src/fps/fps_pow.hpp
  - icon: ':x:'
    path: src/fps/multipoint_evaluation.hpp
    title: src/fps/multipoint_evaluation.hpp
  - icon: ':x:'
    path: src/fps/polynomial_interpolation.hpp
    title: src/fps/polynomial_interpolation.hpp
  - icon: ':question:'
    path: src/fps/power_projection.hpp
    title: src/fps/power_projection.hpp
  - icon: ':x:'
    path: src/fps/subprod_tree.hpp
    title: src/fps/subprod_tree.hpp
  - icon: ':warning:'
    path: src/math/bmbm.hpp
    title: src/math/bmbm.hpp
  - icon: ':warning:'
    path: src/math/bostan_mori.hpp
    title: src/math/bostan_mori.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_compositional_inverse.test.cpp
    title: test/fps/fps_compositional_inverse.test.cpp
  - icon: ':x:'
    path: test/fps/fps_composotion.test.cpp
    title: test/fps/fps_composotion.test.cpp
  - icon: ':x:'
    path: test/fps/fps_div_sparse.test.cpp
    title: test/fps/fps_div_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_inv.test.cpp
    title: test/fps/fps_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_log.test.cpp
    title: test/fps/fps_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_pow.test.cpp
    title: test/fps/fps_pow.test.cpp
  - icon: ':x:'
    path: test/fps/multipoint_evaluation.test.cpp
    title: test/fps/multipoint_evaluation.test.cpp
  - icon: ':x:'
    path: test/fps/polynomial_interpolation.test.cpp
    title: test/fps/polynomial_interpolation.test.cpp
  - icon: ':x:'
    path: test/fps/power_projection.test.cpp
    title: test/fps/power_projection.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/fps/fps.hpp\"\n#include <vector>\n#line 2 \"src/math/enumerative_combinatorics/combination.hpp\"\
    \n#include <algorithm>\n#include <cassert>\n#line 5 \"src/math/enumerative_combinatorics/combination.hpp\"\
    \nusing namespace std;\n\nnamespace combination {\n\ntemplate<typename mint>\n\
    struct container {\n    static vector<mint> fac, finv;\n    static void init(int\
    \ n) {\n        int sz = fac.size();\n        if (n < sz) return;\n        n =\
    \ clamp(n, 2 * sz, min<int>(1 << 27, mint::mod() - 1));\n        fac.resize(n\
    \ + 1);\n        finv.resize(n + 1);\n        for (int i = sz; i <= n; i++) {\n\
    \            fac[i] = i * fac[i - 1];\n        }\n        finv[n] = fac[n].inv();\n\
    \        for (int i = n; i >= sz; i--) {\n            finv[i - 1] = i * finv[i];\n\
    \        }\n    }\n};\n\ntemplate<typename mint>\nvector<mint> container<mint>::fac(1,\
    \ 1);\ntemplate<typename mint>\nvector<mint> container<mint>::finv(1, 1);\ntemplate<typename\
    \ mint>\nmint fac(int n) {\n    container<mint>::init(n);\n    if (n < 0) return\
    \ 0;\n    return container<mint>::fac[n];\n}\ntemplate<typename mint>\nmint finv(int\
    \ n) {\n    container<mint>::init(n);\n    if (n < 0) return 0;\n    return container<mint>::finv[n];\n\
    }\ntemplate<typename mint>\nmint mod_inv(int n) {\n    assert(n > 0);\n    return\
    \ finv<mint>(n) * fac<mint>(n - 1);\n}\ntemplate<typename mint>\nmint nCk(int\
    \ n, int k) {\n    if (n < 0) {\n        n = -n;\n        return nCk<mint>(n +\
    \ k - 1, n - 1);\n    }\n    if (n < k || k < 0) return 0;\n    return fac<mint>(n)\
    \ * finv<mint>(n - k) * finv<mint>(k);\n}\ntemplate<typename mint>\nmint multi_C(const\
    \ vector<int> &v) {\n    int n = 0;\n    for (const int &k : v) n += k;\n    mint\
    \ res = fac<mint>(n);\n    for (const int &k : v) res *= finv<mint>(k);\n    return\
    \ res;\n}\ntemplate<typename mint>\nmint nPk(int n, int k) {\n    if (n < 0 ||\
    \ n < k || k < 0) return 0;\n    return fac<mint>(n) * finv<mint>(n - k);\n}\n\
    template<typename mint>\nmint catalan(int n) {\n    return fac<mint>(2 * n) *\
    \ finv<mint>(n) * finv<mint>(n + 1);\n}\ntemplate<typename mint>\nmint grid_path(int\
    \ n, int m) {\n    return nCk<mint>(n + m, n);\n}\n\n} // namespace combination\n\
    #line 4 \"src/modint/dynamic_montgomery_modint.hpp\"\nusing namespace std;\n\n\
    struct dynamic_montgomery_modint {\n    using i64 = __uint64_t;\n    using i128\
    \ = __uint128_t;\n    using modint = dynamic_montgomery_modint;\n    dynamic_montgomery_modint()\
    \ : x(0) {}\n    dynamic_montgomery_modint(long long v) : x(reduce((i128(v) +\
    \ MOD) * R)) {}\n    static void set_mod(long long _m) {\n        MOD = _m;\n\
    \        R = -i128(MOD) % MOD;\n        INV = get_inv_mod(); \n    }\n    static\
    \ long long mod() { return MOD; }\n    long long val() const {\n        i64 res\
    \ = reduce(x);\n        return res >= MOD ? res - MOD : res;\n    }\n    modint&\
    \ operator+=(const modint &r) {\n        x += r.x;\n        if (x >= (MOD << 1))\
    \ x -= (MOD << 1);\n        return *this;\n    }\n    modint& operator-=(const\
    \ modint &r) {\n        x += (MOD << 1) - r.x;\n        if (x >= (MOD << 1)) x\
    \ -= (MOD << 1);\n        return *this;\n    }\n    modint& operator*=(const modint\
    \ &r) {\n        x = reduce(i128(x) * r.x);\n        return *this;\n    }\n  \
    \  modint& operator/=(const modint &r) {\n        *this *= r.inv();\n        return\
    \ *this;\n    }\n    friend modint operator+(const modint &a, const modint &b)\
    \ {\n        return modint(a) += b;\n    }\n    friend modint operator-(const\
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
    dynamic_montgomery_modint::INV,\ndynamic_montgomery_modint::R;\n#line 2 \"src/math/number_theory/prime_factor.hpp\"\
    \n#include <numeric>\n#line 2 \"src/random/xor_shift.hpp\"\n#include <cstdint>\n\
    #include <type_traits>\nusing namespace std;\n\ntemplate<typename T>\nstruct xor_shift\
    \ {\n    using U = typename make_unsigned<T>::type;\n    constexpr xor_shift(U\
    \ seed) : x(seed == 0 ? 987139873 : seed) {}\n    constexpr U operator()() {\n\
    \        if constexpr (sizeof(T) <= 4) {\n            x ^= x << 13;\n        \
    \    x ^= x >> 17;\n            x ^= x << 5;\n        } else {\n            x\
    \ ^= x << 13;\n            x ^= x >> 7;\n            x ^= x << 17;\n        }\n\
    \        return x;\n    }\n    constexpr T operator()(T low, T hi) {\n       \
    \ return low + (*this)() % (hi - low + 1);\n    }\nprivate:\n    U x;\n};\n#line\
    \ 2 \"src/math/number_theory/primality_test.hpp\"\n#include <array>\n#line 4 \"\
    src/math/number_theory/primality_test.hpp\"\nusing namespace std;\n\ntemplate<size_t\
    \ size>\nbool miller_rabin(long long m, const array<int, size> &ps) {\n    using\
    \ mint = dynamic_montgomery_modint;\n    mint::set_mod(m);\n    long long u =\
    \ 0, v = m - 1;\n    while ((v & 1) == 0) u++, v >>= 1;\n    for (int p : ps)\
    \ {\n        if (m <= p) return true;\n        mint x = mint(p).pow(v);\n    \
    \    if (x.val() != 1) {\n            long long w;\n            for (w = 0; w\
    \ < u; w++) {\n                if (x.val() == m - 1) break;\n                x\
    \ *= x;\n            }\n            if (w == u) return false;\n        }\n   \
    \ }\n    return true;\n}\n\ninline bool miller_rabin_small(long long m) {\n  \
    \  return miller_rabin(m, array<int, 3>{2, 7, 61});\n}\n\ninline bool miller_rabin_large(long\
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
    \ = vector<mint>();\n#line 5 \"src/fps/fps.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ mint>\nstruct fps : vector<mint> {\n    using vector<mint>::vector;\n    using\
    \ NTT = Number_Theoretic_Transform<mint>;\n    void ntt() { NTT::ntt(*this); }\n\
    \    void intt() { NTT::intt(*this); }\n    fps(const vector<mint> &v) : vector<mint>(v)\
    \ {}\n    fps &operator+=(const mint &r) {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] += r;\n        return *this;\n    }\n    fps &operator-=(const\
    \ mint &r) {\n        if (this->empty()) this->resize(1);\n        (*this)[0]\
    \ -= r;\n        return *this;\n    }\n    fps &operator*=(const mint &r) {\n\
    \        for (mint &x : *this) x *= r;\n        return *this;\n    }\n    fps\
    \ &operator/=(const mint &r) {\n        mint invr = r.inv();\n        return *this\
    \ *= invr;\n    }\n    fps &operator+=(const fps &f) {\n        int n = this->size(),\
    \ m = f.size();\n        if (n < m) this->resize(m);\n        for (int i = 0;\
    \ i < m; i++) (*this)[i] += f[i];\n        return *this;\n    }\n    fps &operator-=(const\
    \ fps &f) {\n        int n = this->size(), m = f.size();\n        if (n < m) this->resize(m);\n\
    \        for (int i = 0; i < m; i++) (*this)[i] -= f[i];\n        return *this;\n\
    \    }\n    fps &operator*=(fps f) {\n        int n = this->size(), m = f.size();\n\
    \        if (n == 0 || m == 0) {\n            this->clear();\n            return\
    \ *this;\n        }\n        int sz = 1;\n        while (sz < n + m - 1) sz <<=\
    \ 1;\n        this->resize(sz);\n        this->ntt();\n        f.resize(sz);\n\
    \        f.ntt();\n        for (int i = 0; i < sz; i++) (*this)[i] *= f[i];\n\
    \        this->intt();\n        this->resize(n + m - 1);\n        return *this;\n\
    \    }\n    fps &operator/=(const fps &f) {\n        return *this *= f.inv();\n\
    \    }\n    fps &operator%=(const fps &f) {\n        *this -= div(f) * f;\n  \
    \      this->shrink();\n        return *this;\n    }\n    fps div(const fps &f)\
    \ const {\n        if (this->size() < f.size()) return fps{};\n        int n =\
    \ this->size() - f.size() + 1;\n        return (rev().pre(n) * f.rev().inv(n)).pre(n).rev(n);\n\
    \    }\n    fps operator+(const mint &r) const { return fps(*this) += r; }\n \
    \   fps operator-(const mint &r) const { return fps(*this) -= r; }\n    fps operator*(const\
    \ mint &r) const { return fps(*this) *= r; }\n    fps operator/(const mint &r)\
    \ const { return fps(*this) /= r; }\n    friend fps operator+(const mint &r, const\
    \ fps &f) { return f + r; }\n    friend fps operator-(const mint &r, const fps\
    \ &f) { return (-f) + r; }\n    friend fps operator*(const mint &r, const fps\
    \ &f) { return f * r; }\n    fps operator+(const fps &f) const { return fps(*this)\
    \ += f; }\n    fps operator-(const fps &f) const { return fps(*this) -= f; }\n\
    \    fps operator*(const fps &f) const { return fps(*this) *= f; }\n    fps operator/(const\
    \ fps &f) const { return fps(*this) /= f; }\n    fps operator%(const fps &f) const\
    \ { return fps(*this) %= f; }\n    fps operator-() const {\n        return fps{}\
    \ - *this;\n    }\n    fps operator<<(int n) const {\n        fps res(*this);\n\
    \        res.insert(res.begin(), n, mint());\n        return res;\n    }\n   \
    \ fps operator>>(int n) const {\n        if (int(this->size()) <= n) return fps{};\n\
    \        fps res(*this);\n        res.erase(res.begin(), res.begin() + n);\n \
    \       return res;\n    }\n    fps &operator<<=(int n) {\n        return *this\
    \ = (*this) << n;\n    }\n    fps &operator>>=(int n) {\n        return *this\
    \ = (*this) >> n;\n    }\n    fps pre(int n) const {\n        n = min(n, int(this->size()));\n\
    \        return fps(this->begin(), this->begin() + n);\n    }\n    fps rev(int\
    \ deg = -1) const {\n        fps res(*this);\n        if (deg != -1) res.resize(deg,\
    \ 0);\n        reverse(res.begin(), res.end());\n        return res;\n    }\n\
    \    fps dot(const fps &f) const {\n        int n = min(this->size(), f.size());\n\
    \        fps res(n);\n        for (int i = 0; i < n; i++) res[i] = (*this)[i]\
    \ * f[i];\n        return res;\n    }\n    void shrink() {\n        while (this->size()\
    \ && this->back() == 0) {\n            this->pop_back();\n        }\n    }\n \
    \   mint operator()(const mint &x) const {\n        mint res = 0, powx = 1;\n\
    \        for (const mint &a : *this) {\n            res += a * powx;\n       \
    \     powx *= x;\n        }\n        return res;\n    }\n    fps diff() const\
    \ {\n        int n = this->size();\n        if (n == 0) return fps{};\n      \
    \  fps res(n - 1);\n        for (int i = 1; i < n; i++) {\n            res[i -\
    \ 1] = i * (*this)[i];\n        }\n        return res;\n    }\n    fps integral()\
    \ const {\n        int n = this->size();\n        fps res(n + 1);\n        res[0]\
    \ = 0;\n        for (int i = 0; i < n; i++) {\n            res[i + 1] = (*this)[i]\
    \ * combination::mod_inv<mint>(i + 1);\n        }\n        return res;\n    }\n\
    \    fps inv(int deg = -1) const;\n    fps exp(int deg = -1) const;\n    fps log(int\
    \ deg = -1) const;\n    fps pow(long long k, int deg = -1) const;\n    fps operator()(fps\
    \ f, int deg = -1) const;\n    fps compositional_inverse(int deg = -1) const;\n\
    \    fps taylor_shift(mint c) const;\n};\n#line 3 \"src/fps/fps_inv.hpp\"\n\n\
    template<typename mint>\nfps<mint> fps<mint>::inv(int deg) const {\n    int n\
    \ = this->size();\n    assert(n > 0);\n    mint c = (*this)[0];\n    assert(c\
    \ != 0);\n    if (deg == -1) deg = n;\n    fps res(deg);\n    res[0] = c.inv();\n\
    \    for (int d = 1; d < deg; d <<= 1) {\n        fps f(d << 1), g(d << 1);\n\
    \        for (int i = 0; i < n && i < d << 1; i++) f[i] = (*this)[i];\n      \
    \  for (int i = 0; i < d; i++) g[i] = res[i];\n        f.ntt();\n        g.ntt();\n\
    \        for (int i = 0; i < d << 1; i++) f[i] *= g[i];\n        f.intt();\n \
    \       for (int i = 0; i < d; i++) f[i] = 0;\n        f.ntt();\n        for (int\
    \ i = 0; i < d << 1; i++) f[i] *= g[i];\n        f.intt();\n        for (int i\
    \ = d; i < deg && i < d << 1; i++) res[i] -= f[i];\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"fps.hpp\"\n\ntemplate<typename mint>\nfps<mint>\
    \ fps<mint>::inv(int deg) const {\n    int n = this->size();\n    assert(n > 0);\n\
    \    mint c = (*this)[0];\n    assert(c != 0);\n    if (deg == -1) deg = n;\n\
    \    fps res(deg);\n    res[0] = c.inv();\n    for (int d = 1; d < deg; d <<=\
    \ 1) {\n        fps f(d << 1), g(d << 1);\n        for (int i = 0; i < n && i\
    \ < d << 1; i++) f[i] = (*this)[i];\n        for (int i = 0; i < d; i++) g[i]\
    \ = res[i];\n        f.ntt();\n        g.ntt();\n        for (int i = 0; i < d\
    \ << 1; i++) f[i] *= g[i];\n        f.intt();\n        for (int i = 0; i < d;\
    \ i++) f[i] = 0;\n        f.ntt();\n        for (int i = 0; i < d << 1; i++) f[i]\
    \ *= g[i];\n        f.intt();\n        for (int i = d; i < deg && i < d << 1;\
    \ i++) res[i] -= f[i];\n    }\n    return res;\n}"
  dependsOn:
  - src/fps/fps.hpp
  - src/math/enumerative_combinatorics/combination.hpp
  - src/convolution/ntt.hpp
  - src/math/number_theory/primitive_root.hpp
  - src/modint/dynamic_montgomery_modint.hpp
  - src/math/number_theory/prime_factor.hpp
  - src/random/xor_shift.hpp
  - src/math/number_theory/primality_test.hpp
  isVerificationFile: false
  path: src/fps/fps_inv.hpp
  requiredBy:
  - src/fps/fps_composotion.hpp
  - src/fps/fps_all.hpp
  - src/fps/subprod_tree.hpp
  - src/fps/polynomial_interpolation.hpp
  - src/fps/power_projection.hpp
  - src/fps/multipoint_evaluation.hpp
  - src/fps/fps_log.hpp
  - src/fps/fps_pow.hpp
  - src/fps/fps_compositional_inverse.hpp
  - src/math/bmbm.hpp
  - src/math/bostan_mori.hpp
  timestamp: '2026-10-14 23:16:02+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/fps/fps_log.test.cpp
  - test/fps/multipoint_evaluation.test.cpp
  - test/fps/fps_pow.test.cpp
  - test/fps/fps_composotion.test.cpp
  - test/fps/power_projection.test.cpp
  - test/fps/polynomial_interpolation.test.cpp
  - test/fps/fps_inv.test.cpp
  - test/fps/fps_div_sparse.test.cpp
  - test/fps/fps_compositional_inverse.test.cpp
documentation_of: src/fps/fps_inv.hpp
layout: document
redirect_from:
- /library/src/fps/fps_inv.hpp
- /library/src/fps/fps_inv.hpp.html
title: src/fps/fps_inv.hpp
---
