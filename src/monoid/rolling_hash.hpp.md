---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/number_theory/extended_gcd.hpp
    title: src/math/number_theory/extended_gcd.hpp
  - icon: ':x:'
    path: src/math/number_theory/mod_inv.hpp
    title: src/math/number_theory/mod_inv.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/monoid/rolling_hash.hpp\"\n#include <array>\n#include\
    \ <vector>\n#line 2 \"src/math/number_theory/mod_inv.hpp\"\n#include <cassert>\n\
    #line 2 \"src/math/number_theory/extended_gcd.hpp\"\n#include <utility>\nusing\
    \ namespace std;\n\n// find x, y s.t. ax + by = gcd(a, b) and return gcd(a, b)\n\
    template<typename T>\nT extended_gcd(T a, T b, T &x, T &y) {\n    T g = a;\n \
    \   if (b != 0) {\n        g = extended_gcd(b, a % b, y, x);\n        y -= (a\
    \ / b) * x;\n    } else {\n        x = 1;\n        y = 0;\n    }\n    return g;\n\
    }\n#line 4 \"src/math/number_theory/mod_inv.hpp\"\nusing namespace std;\n\nlong\
    \ long mod_inv(long long a, long long mod) {\n    long long inv, y;\n    assert(extended_gcd(a,\
    \ mod, inv, y) == 1);\n    inv %= mod;\n    return inv < 0 ? inv + mod : inv;\n\
    }\n#line 5 \"src/monoid/rolling_hash.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ T>\nstruct rolling_hash {\n    static void set_base(int b) {\n        assert(base\
    \ == -1);\n        assert(2 <= b && b <= int(1e9));\n        base = b;\n     \
    \   p = (b + (b >> 5)) % 2749;\n        q = (b + (b >> 9)) % 274;\n    }\n   \
    \ using S = pair<array<long long, 3>, int>;\n    static S op(const S &a, const\
    \ S &b) {\n        init(a.second + 1);\n        S c;\n        for (int j = 0;\
    \ j < 3; j++) {\n            c.first[j] = (a.first[j] + b.first[j] * pow[a.second][j])\
    \ % mod[j];\n        }\n        c.second = a.second + b.second;\n        return\
    \ c;\n    }\n    constexpr static S e() {\n        return make_pair(array<long\
    \ long, 3>{0, 0, 0,}, 0);\n    }\n    static S cast(T t) {\n        S x;\n   \
    \     x.first.fill(hash(t));\n        x.second = 1;\n        return x;\n    }\n\
    private:\n    static long long base, p, q;\n    static constexpr array<long long,\
    \ 3> mod = {1000274903LL, 1000274927LL, 1000274953LL};\n    static array<long\
    \ long, 3> inv;\n    static vector<array<long long, 3>> pow;\n    static void\
    \ init(int n) {\n        assert(base != -1);\n        int sz = pow.size();\n \
    \       if (n + 1 < sz) return;\n        n = max(n + 1, 2 * sz);\n        pow.resize(n);\n\
    \        for (int i = sz; i < n; i++) {\n            for (int j = 0; j < 3; j++)\
    \ {\n                pow[i][j] = (pow[i - 1][j] * base) % mod[j];\n          \
    \  }\n        }\n    }\n    static long long hash(const T &t) {\n        long\
    \ long res = static_cast<long long>(t);\n        res = (res + (res << 4)) + p;\n\
    \        res = ((res << 2) ^ (res >> 3)) * q;\n        return res;\n    }\n};\n\
    template<typename T>\nlong long rolling_hash<T>::base(-1);\ntemplate<typename\
    \ T>\nlong long rolling_hash<T>::p(-1);\ntemplate<typename T>\nlong long rolling_hash<T>::q(-1);\n\
    template<typename T>\narray<long long, 3> rolling_hash<T>::inv({1, 1, 1});\ntemplate<typename\
    \ T>\nvector<array<long long, 3>> rolling_hash<T>::pow(1, {1, 1, 1});\n"
  code: "#pragma once\n#include <array>\n#include <vector>\n#include \"../math/number_theory/mod_inv.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T>\nstruct rolling_hash {\n    static\
    \ void set_base(int b) {\n        assert(base == -1);\n        assert(2 <= b &&\
    \ b <= int(1e9));\n        base = b;\n        p = (b + (b >> 5)) % 2749;\n   \
    \     q = (b + (b >> 9)) % 274;\n    }\n    using S = pair<array<long long, 3>,\
    \ int>;\n    static S op(const S &a, const S &b) {\n        init(a.second + 1);\n\
    \        S c;\n        for (int j = 0; j < 3; j++) {\n            c.first[j] =\
    \ (a.first[j] + b.first[j] * pow[a.second][j]) % mod[j];\n        }\n        c.second\
    \ = a.second + b.second;\n        return c;\n    }\n    constexpr static S e()\
    \ {\n        return make_pair(array<long long, 3>{0, 0, 0,}, 0);\n    }\n    static\
    \ S cast(T t) {\n        S x;\n        x.first.fill(hash(t));\n        x.second\
    \ = 1;\n        return x;\n    }\nprivate:\n    static long long base, p, q;\n\
    \    static constexpr array<long long, 3> mod = {1000274903LL, 1000274927LL, 1000274953LL};\n\
    \    static array<long long, 3> inv;\n    static vector<array<long long, 3>> pow;\n\
    \    static void init(int n) {\n        assert(base != -1);\n        int sz =\
    \ pow.size();\n        if (n + 1 < sz) return;\n        n = max(n + 1, 2 * sz);\n\
    \        pow.resize(n);\n        for (int i = sz; i < n; i++) {\n            for\
    \ (int j = 0; j < 3; j++) {\n                pow[i][j] = (pow[i - 1][j] * base)\
    \ % mod[j];\n            }\n        }\n    }\n    static long long hash(const\
    \ T &t) {\n        long long res = static_cast<long long>(t);\n        res = (res\
    \ + (res << 4)) + p;\n        res = ((res << 2) ^ (res >> 3)) * q;\n        return\
    \ res;\n    }\n};\ntemplate<typename T>\nlong long rolling_hash<T>::base(-1);\n\
    template<typename T>\nlong long rolling_hash<T>::p(-1);\ntemplate<typename T>\n\
    long long rolling_hash<T>::q(-1);\ntemplate<typename T>\narray<long long, 3> rolling_hash<T>::inv({1,\
    \ 1, 1});\ntemplate<typename T>\nvector<array<long long, 3>> rolling_hash<T>::pow(1,\
    \ {1, 1, 1});"
  dependsOn:
  - src/math/number_theory/mod_inv.hpp
  - src/math/number_theory/extended_gcd.hpp
  isVerificationFile: false
  path: src/monoid/rolling_hash.hpp
  requiredBy: []
  timestamp: '2025-08-07 20:30:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/monoid/rolling_hash.hpp
layout: document
redirect_from:
- /library/src/monoid/rolling_hash.hpp
- /library/src/monoid/rolling_hash.hpp.html
title: src/monoid/rolling_hash.hpp
---
