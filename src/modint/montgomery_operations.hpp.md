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
  bundledCode: "#line 2 \"src/modint/montgomery_operations.hpp\"\n#include <cstdint>\n\
    using namespace std;\n\nstruct montgomery_operation {\n    using i64 = uint64_t;\n\
    \    using i128 = __uint128_t;\n    constexpr montgomery_operation() = default;\n\
    \    constexpr montgomery_operation(i64 m) : mod(m), inv(m), r(-i128(m) % m) {\n\
    \        inv *= 2 - mod * inv;\n        inv *= 2 - mod * inv;\n        inv *=\
    \ 2 - mod * inv;\n        inv *= 2 - mod * inv;\n        inv *= 2 - mod * inv;\n\
    \    }\n    constexpr long long val(i128 x) {\n        i64 res = reduce(x);\n\
    \        return res >= mod ? res - mod : res;\n    }\n    constexpr i64 map(long\
    \ long x) {\n        return reduce((i128(x) + mod) * r);\n    }\n    constexpr\
    \ i64 add(i64 a, i64 b) {\n        a += b;\n        if (a >= (mod << 1)) a -=\
    \ mod << 1;\n        return a;\n    }\n    constexpr i64 mul(i64 a, i64 b) {\n\
    \        return reduce(i128(a) * b);\n    }\n    constexpr i64 pow(i64 a, long\
    \ long k) {\n        i64 res = map(1);\n        while (k > 0) {\n            if\
    \ (k & 1) res = mul(res, a);\n            a = mul(a, a);\n            k >>= 1;\n\
    \        }\n        return res;\n    }\nprivate:\n    i64 mod, inv, r;\n    constexpr\
    \ i64 reduce(i128 x) {\n        return (x + i128(i64(x) * i64(-inv)) * mod) >>\
    \ 64;\n    }\n};\n"
  code: "#pragma once\n#include <cstdint>\nusing namespace std;\n\nstruct montgomery_operation\
    \ {\n    using i64 = uint64_t;\n    using i128 = __uint128_t;\n    constexpr montgomery_operation()\
    \ = default;\n    constexpr montgomery_operation(i64 m) : mod(m), inv(m), r(-i128(m)\
    \ % m) {\n        inv *= 2 - mod * inv;\n        inv *= 2 - mod * inv;\n     \
    \   inv *= 2 - mod * inv;\n        inv *= 2 - mod * inv;\n        inv *= 2 - mod\
    \ * inv;\n    }\n    constexpr long long val(i128 x) {\n        i64 res = reduce(x);\n\
    \        return res >= mod ? res - mod : res;\n    }\n    constexpr i64 map(long\
    \ long x) {\n        return reduce((i128(x) + mod) * r);\n    }\n    constexpr\
    \ i64 add(i64 a, i64 b) {\n        a += b;\n        if (a >= (mod << 1)) a -=\
    \ mod << 1;\n        return a;\n    }\n    constexpr i64 mul(i64 a, i64 b) {\n\
    \        return reduce(i128(a) * b);\n    }\n    constexpr i64 pow(i64 a, long\
    \ long k) {\n        i64 res = map(1);\n        while (k > 0) {\n            if\
    \ (k & 1) res = mul(res, a);\n            a = mul(a, a);\n            k >>= 1;\n\
    \        }\n        return res;\n    }\nprivate:\n    i64 mod, inv, r;\n    constexpr\
    \ i64 reduce(i128 x) {\n        return (x + i128(i64(x) * i64(-inv)) * mod) >>\
    \ 64;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/modint/montgomery_operations.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/modint/montgomery_operations.hpp
layout: document
redirect_from:
- /library/src/modint/montgomery_operations.hpp
- /library/src/modint/montgomery_operations.hpp.html
title: src/modint/montgomery_operations.hpp
---
