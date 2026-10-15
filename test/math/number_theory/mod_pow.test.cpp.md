---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/math/number_theory/mod_pow.hpp
    title: src/math/number_theory/mod_pow.hpp
  - icon: ':question:'
    path: src/random/utility.hpp
    title: src/random/utility.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "#line 1 \"test/math/number_theory/mod_pow.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"src/math/number_theory/mod_pow.hpp\"\
    \nusing namespace std;\n\nlong long mod_pow(long long a, long long n, long long\
    \ mod) {\n    a %= mod;\n    long long res = 1;\n    while (n > 0) {\n       \
    \ if (n & 1) res = __int128_t(res) * a % mod;\n        a = __int128_t(a) * a %\
    \ mod;\n        n >>= 1;\n    }\n    return res;\n}\n#line 2 \"src/random/utility.hpp\"\
    \n#include <cassert>\n#include <concepts>\n#include <random>\nusing namespace\
    \ std;\n\nnamespace rng {\n\ninline random_device seed;\ninline mt19937 eng(seed());\n\
    \ntemplate<typename T>\nvoid set_seed(const T &sd) {\n    eng.seed(sd);\n}\n\n\
    template<integral T>\ninline T randint(T lo, T hi) {\n    assert(lo <= hi);\n\
    \    uniform_int_distribution<T> dist(lo, hi);\n    return dist(eng);\n}\n\ntemplate<integral\
    \ T>\ninline pair<T, T> randpair(T lo, T hi, bool strict = false) {\n    assert(lo\
    \ + strict <= hi);\n    T l = randint(lo, hi - strict);\n    T r = randint(l +\
    \ strict, hi);\n    return make_pair(l, r);\n}\n\n} // namespace rng\n#line 5\
    \ \"test/math/number_theory/mod_pow.test.cpp\"\n\n#include <iostream>\n#include\
    \ <atcoder/math>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    {\n        int A, B;\n        cin >> A >> B;\n        cout << A + B << '\\\
    n';\n    }\n    for (int t = 0; t < (int)1e5; t++) {\n        long long mod =\
    \ rng::randint(2LL, (long long)1e9);\n        long long a = rng::randint(0LL,\
    \ mod - 1);\n        long long k = rng::randint(0LL, (long long)1e18);\n     \
    \   assert(mod_pow(a, k, mod) == atcoder::pow_mod(a, k, mod));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../src/math/number_theory/mod_pow.hpp\"\n#include \"../../../src/random/utility.hpp\"\
    \n\n#include <iostream>\n#include <atcoder/math>\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    {\n        int A, B;\n        cin >> A >> B;\n   \
    \     cout << A + B << '\\n';\n    }\n    for (int t = 0; t < (int)1e5; t++) {\n\
    \        long long mod = rng::randint(2LL, (long long)1e9);\n        long long\
    \ a = rng::randint(0LL, mod - 1);\n        long long k = rng::randint(0LL, (long\
    \ long)1e18);\n        assert(mod_pow(a, k, mod) == atcoder::pow_mod(a, k, mod));\n\
    \    }\n}"
  dependsOn:
  - src/math/number_theory/mod_pow.hpp
  - src/random/utility.hpp
  isVerificationFile: true
  path: test/math/number_theory/mod_pow.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:06:06+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/number_theory/mod_pow.test.cpp
layout: document
redirect_from:
- /verify/test/math/number_theory/mod_pow.test.cpp
- /verify/test/math/number_theory/mod_pow.test.cpp.html
title: test/math/number_theory/mod_pow.test.cpp
---
