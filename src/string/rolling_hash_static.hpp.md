---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/rolling_hash_static.hpp\"\n#include <array>\n\
    #include <cassert>\n#include <vector>\nusing namespace std;\n\nstruct rolling_hash\
    \ {\n    static long long base, p, q;\n    static array<long long, 3> inv;\n \
    \   static constexpr array<long long, 3> mod = {1000274903LL, 1000274927LL, 1000274953LL};\n\
    \    static vector<array<long long, 3>> pow, inv_pow;\n    static void set_base(int\
    \ b) {\n        assert(base == -1);\n        assert(2 <= b && b <= int(1e9));\n\
    \        base = b;\n        p = (b + (b >> 5)) % 2749;\n        q = (b + (b >>\
    \ 9)) % 274;\n        for (int j = 0; j < 3; j++) {\n            inv[j] = mod_inv(base,\
    \ mod[j]);\n        }\n    }\n    rolling_hash(const string &s) {\n        assert(base\
    \ != -1);\n        int n = s.size();\n        init(n);\n        d.resize(n + 1);\n\
    \        d[0].fill(0);\n        for (int i = 0; i < n; i++) {\n            long\
    \ long hs = inner_hash(s[i]);\n            for (int j = 0; j < 3; j++) {\n   \
    \             d[i + 1][j] = (d[i][j] + pow[i][j] * hs) % mod[j];\n           \
    \ }\n        }\n    }\n    array<long long, 3> prod(int l, int r) {\n        array<long\
    \ long, 3> res;\n        for (int j = 0; j < 3; j++) {\n            res[j] = d[r][j]\
    \ - d[l][j];\n            if (res[j] < 0) res[j] += mod[j];\n            res[j]\
    \ = (res[j] * inv_pow[l][j]) % mod[j];\n        }\n        return res;\n    }\n\
    private:\n    vector<array<long long, 3>> d;\n    static long long mod_inv(long\
    \ long x, long long m) {\n        long long a = x, r = 1, k = m - 2;\n       \
    \ while (k > 0) {\n            if (k & 1) r = (r * a) % m;\n            a = (a\
    \ * a) % m;\n            k >>= 1;\n        }\n        return r;\n    }\n    static\
    \ void init(int n) {\n        int sz = pow.size();\n        if (n + 1 < sz) return;\n\
    \        n = max(n + 1, 2 * sz);\n        pow.resize(n);\n        inv_pow.resize(n);\n\
    \        for (int i = sz; i < n; i++) {\n            for (int j = 0; j < 3; j++)\
    \ {\n                pow[i][j] = (pow[i - 1][j] * base) % mod[j];\n          \
    \      inv_pow[i][j] = (inv_pow[i - 1][j] * inv[j]) % mod[j];\n            }\n\
    \        }\n    }\n    long long inner_hash(const char &c) const {\n        int\
    \ res = static_cast<int>(c);\n        res = (res + (res << 4)) + p;\n        res\
    \ = ((res << 2) ^ (res >> 3)) * q;\n        return res;\n    }\n};\nlong long\
    \ rolling_hash::base(-1);\nlong long rolling_hash::p(-1);\nlong long rolling_hash::q(-1);\n\
    array<long long, 3> rolling_hash::inv({1, 1, 1});\nvector<array<long long, 3>>\
    \ rolling_hash::pow(1, {1, 1, 1});\nvector<array<long long, 3>> rolling_hash::inv_pow(1,\
    \ {1, 1, 1});\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <vector>\nusing\
    \ namespace std;\n\nstruct rolling_hash {\n    static long long base, p, q;\n\
    \    static array<long long, 3> inv;\n    static constexpr array<long long, 3>\
    \ mod = {1000274903LL, 1000274927LL, 1000274953LL};\n    static vector<array<long\
    \ long, 3>> pow, inv_pow;\n    static void set_base(int b) {\n        assert(base\
    \ == -1);\n        assert(2 <= b && b <= int(1e9));\n        base = b;\n     \
    \   p = (b + (b >> 5)) % 2749;\n        q = (b + (b >> 9)) % 274;\n        for\
    \ (int j = 0; j < 3; j++) {\n            inv[j] = mod_inv(base, mod[j]);\n   \
    \     }\n    }\n    rolling_hash(const string &s) {\n        assert(base != -1);\n\
    \        int n = s.size();\n        init(n);\n        d.resize(n + 1);\n     \
    \   d[0].fill(0);\n        for (int i = 0; i < n; i++) {\n            long long\
    \ hs = inner_hash(s[i]);\n            for (int j = 0; j < 3; j++) {\n        \
    \        d[i + 1][j] = (d[i][j] + pow[i][j] * hs) % mod[j];\n            }\n \
    \       }\n    }\n    array<long long, 3> prod(int l, int r) {\n        array<long\
    \ long, 3> res;\n        for (int j = 0; j < 3; j++) {\n            res[j] = d[r][j]\
    \ - d[l][j];\n            if (res[j] < 0) res[j] += mod[j];\n            res[j]\
    \ = (res[j] * inv_pow[l][j]) % mod[j];\n        }\n        return res;\n    }\n\
    private:\n    vector<array<long long, 3>> d;\n    static long long mod_inv(long\
    \ long x, long long m) {\n        long long a = x, r = 1, k = m - 2;\n       \
    \ while (k > 0) {\n            if (k & 1) r = (r * a) % m;\n            a = (a\
    \ * a) % m;\n            k >>= 1;\n        }\n        return r;\n    }\n    static\
    \ void init(int n) {\n        int sz = pow.size();\n        if (n + 1 < sz) return;\n\
    \        n = max(n + 1, 2 * sz);\n        pow.resize(n);\n        inv_pow.resize(n);\n\
    \        for (int i = sz; i < n; i++) {\n            for (int j = 0; j < 3; j++)\
    \ {\n                pow[i][j] = (pow[i - 1][j] * base) % mod[j];\n          \
    \      inv_pow[i][j] = (inv_pow[i - 1][j] * inv[j]) % mod[j];\n            }\n\
    \        }\n    }\n    long long inner_hash(const char &c) const {\n        int\
    \ res = static_cast<int>(c);\n        res = (res + (res << 4)) + p;\n        res\
    \ = ((res << 2) ^ (res >> 3)) * q;\n        return res;\n    }\n};\nlong long\
    \ rolling_hash::base(-1);\nlong long rolling_hash::p(-1);\nlong long rolling_hash::q(-1);\n\
    array<long long, 3> rolling_hash::inv({1, 1, 1});\nvector<array<long long, 3>>\
    \ rolling_hash::pow(1, {1, 1, 1});\nvector<array<long long, 3>> rolling_hash::inv_pow(1,\
    \ {1, 1, 1});"
  dependsOn: []
  isVerificationFile: false
  path: src/string/rolling_hash_static.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/rolling_hash_static.hpp
layout: document
redirect_from:
- /library/src/string/rolling_hash_static.hpp
- /library/src/string/rolling_hash_static.hpp.html
title: src/string/rolling_hash_static.hpp
---
