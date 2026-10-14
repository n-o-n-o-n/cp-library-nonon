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
  bundledCode: "#line 2 \"src/data_structure/misc/bitset.hpp\"\n#include <bit>\n#include\
    \ <cassert>\n#include <vector>\nusing namespace std;\n\nstruct BitSet {\n    using\
    \ ull = unsigned long long;\n    BitSet() = default;\n    BitSet(int _n) : n(_n),\
    \ m((_n + 63) >> 6) {\n        d = vector<ull>(m);\n    }\n    size_t size() const\
    \ { return n; }\n    BitSet &operator|=(const BitSet &a) {\n        assert(size()\
    \ == a.size());\n        for (int i = 0; i < m; i++) d[i] |= a.d[i];\n       \
    \ return *this;\n    }\n    BitSet &operator^=(const BitSet &a) {\n        assert(size()\
    \ == a.size());\n        for (int i = 0; i < m; i++) d[i] ^= a.d[i];\n       \
    \ return *this;\n    }\n    BitSet &operator&=(const BitSet &a) {\n        assert(size()\
    \ == a.size());\n        for (int i = 0; i < m; i++) d[i] &= a.d[i];\n       \
    \ return *this;\n    }\n    BitSet &operator<<=(int k) {\n        if (k == 0)\
    \ return *this;\n        int q = k >> 6, r = k & 63;\n        if (r == 0) {\n\
    \            for (int i = m - 1; i >= q; i--) d[i] = d[i - q];\n        } else\
    \ {\n            int s = 64 - r;\n            for (int i = m - 1; i > q; i--)\
    \ {\n                d[i] = (d[i - q] << r) ^ (d[i - q - 1] >> s);\n         \
    \   }\n            d[q] = d[0] << r;\n        }\n        d[m - 1] &= mask();\n\
    \        for (int i = 0; i < q; i++) d[i] = 0;\n        return *this;\n    }\n\
    \    BitSet &operator>>=(int k) {\n        if (k == 0) return *this;\n       \
    \ int q = k >> 6, r = k & 63;\n        if (r == 0) {\n            for (int i =\
    \ 0; i + q < m; i++) d[i] = d[i + q];\n        } else {\n            int s = 64\
    \ - r;\n            for (int i = 0; i + q + 1 < m; i++) {\n                d[i]\
    \ = (d[i + q] >> r) ^ (d[i + q + 1] << s);\n            }\n            d[m - q\
    \ - 1] = d[m - 1] >> r;\n        }\n        for (int i = m - q; i < m; i++) d[i]\
    \ = 0;\n        return *this;\n    }\n    void flip() {\n        for (auto &b\
    \ : d) b = ~b;\n        d[m - 1] &= mask();\n    }\n    BitSet operator|(const\
    \ BitSet &a) const { return BitSet(*this) |= a; }\n    BitSet operator^(const\
    \ BitSet &a) const { return BitSet(*this) ^= a; }\n    BitSet operator&(const\
    \ BitSet &a) const { return BitSet(*this) &= a; }\n    BitSet operator<<(int k)\
    \ const { return BitSet(*this) <<= k; }\n    BitSet operator>>(int k) const {\
    \ return BitSet(*this) >>= k; }\n    BitSet operator~() const {\n        BitSet\
    \ r(*this);\n        r.flip();\n        return r;\n    }\n    bool operator[](int\
    \ p) const {\n        assert(0 <= p && p < n);\n        return d[p >> 6] >> (p\
    \ & 63) & 1;\n    }\n    bool operator==(const BitSet &a) const { return n ==\
    \ a.n && d == a.d; }\n    bool operator!=(const BitSet &a) const { return n !=\
    \ a.n || d != a.d; }\n    int count() const {\n        int c = 0;\n        for\
    \ (auto b : d) c += popcount(b);\n        return c;\n    }\n    void set(int p)\
    \ {\n        assert(0 <= p && p < n);\n        d[p >> 6] |= 1ULL << (p & 63);\n\
    \    }\n    void reset(int p) {\n        assert(0 <= p&& p < n);\n        d[p\
    \ >> 6] &= ~(1ULL << (p & 63));\n    }\n    bool test(int p) const {\n       \
    \ assert(0 <= p && p < n);\n        return d[p >> 6] >> (p & 63) & 1;\n    }\n\
    \    bool any() const {\n        for (auto b : d) {\n            if (b != 0) return\
    \ true;\n        }\n        return false;\n    }\n    bool all() const {\n   \
    \     for (int i = 0; i < m - 1; i++) {\n            if (d[i] != ~0ULL) return\
    \ false;\n        }\n        return d[m - 1] == mask();\n    }\n    bool none()\
    \ const { return !any(); }\nprivate:\n    int n, m;\n    vector<ull> d;\n    ull\
    \ mask() const {\n        if (((n >> 6) << 6) == n) return ~0ULL;\n        return\
    \ (1ULL << (n & 63)) - 1;\n    }\n};\n"
  code: "#pragma once\n#include <bit>\n#include <cassert>\n#include <vector>\nusing\
    \ namespace std;\n\nstruct BitSet {\n    using ull = unsigned long long;\n   \
    \ BitSet() = default;\n    BitSet(int _n) : n(_n), m((_n + 63) >> 6) {\n     \
    \   d = vector<ull>(m);\n    }\n    size_t size() const { return n; }\n    BitSet\
    \ &operator|=(const BitSet &a) {\n        assert(size() == a.size());\n      \
    \  for (int i = 0; i < m; i++) d[i] |= a.d[i];\n        return *this;\n    }\n\
    \    BitSet &operator^=(const BitSet &a) {\n        assert(size() == a.size());\n\
    \        for (int i = 0; i < m; i++) d[i] ^= a.d[i];\n        return *this;\n\
    \    }\n    BitSet &operator&=(const BitSet &a) {\n        assert(size() == a.size());\n\
    \        for (int i = 0; i < m; i++) d[i] &= a.d[i];\n        return *this;\n\
    \    }\n    BitSet &operator<<=(int k) {\n        if (k == 0) return *this;\n\
    \        int q = k >> 6, r = k & 63;\n        if (r == 0) {\n            for (int\
    \ i = m - 1; i >= q; i--) d[i] = d[i - q];\n        } else {\n            int\
    \ s = 64 - r;\n            for (int i = m - 1; i > q; i--) {\n               \
    \ d[i] = (d[i - q] << r) ^ (d[i - q - 1] >> s);\n            }\n            d[q]\
    \ = d[0] << r;\n        }\n        d[m - 1] &= mask();\n        for (int i = 0;\
    \ i < q; i++) d[i] = 0;\n        return *this;\n    }\n    BitSet &operator>>=(int\
    \ k) {\n        if (k == 0) return *this;\n        int q = k >> 6, r = k & 63;\n\
    \        if (r == 0) {\n            for (int i = 0; i + q < m; i++) d[i] = d[i\
    \ + q];\n        } else {\n            int s = 64 - r;\n            for (int i\
    \ = 0; i + q + 1 < m; i++) {\n                d[i] = (d[i + q] >> r) ^ (d[i +\
    \ q + 1] << s);\n            }\n            d[m - q - 1] = d[m - 1] >> r;\n  \
    \      }\n        for (int i = m - q; i < m; i++) d[i] = 0;\n        return *this;\n\
    \    }\n    void flip() {\n        for (auto &b : d) b = ~b;\n        d[m - 1]\
    \ &= mask();\n    }\n    BitSet operator|(const BitSet &a) const { return BitSet(*this)\
    \ |= a; }\n    BitSet operator^(const BitSet &a) const { return BitSet(*this)\
    \ ^= a; }\n    BitSet operator&(const BitSet &a) const { return BitSet(*this)\
    \ &= a; }\n    BitSet operator<<(int k) const { return BitSet(*this) <<= k; }\n\
    \    BitSet operator>>(int k) const { return BitSet(*this) >>= k; }\n    BitSet\
    \ operator~() const {\n        BitSet r(*this);\n        r.flip();\n        return\
    \ r;\n    }\n    bool operator[](int p) const {\n        assert(0 <= p && p <\
    \ n);\n        return d[p >> 6] >> (p & 63) & 1;\n    }\n    bool operator==(const\
    \ BitSet &a) const { return n == a.n && d == a.d; }\n    bool operator!=(const\
    \ BitSet &a) const { return n != a.n || d != a.d; }\n    int count() const {\n\
    \        int c = 0;\n        for (auto b : d) c += popcount(b);\n        return\
    \ c;\n    }\n    void set(int p) {\n        assert(0 <= p && p < n);\n       \
    \ d[p >> 6] |= 1ULL << (p & 63);\n    }\n    void reset(int p) {\n        assert(0\
    \ <= p&& p < n);\n        d[p >> 6] &= ~(1ULL << (p & 63));\n    }\n    bool test(int\
    \ p) const {\n        assert(0 <= p && p < n);\n        return d[p >> 6] >> (p\
    \ & 63) & 1;\n    }\n    bool any() const {\n        for (auto b : d) {\n    \
    \        if (b != 0) return true;\n        }\n        return false;\n    }\n \
    \   bool all() const {\n        for (int i = 0; i < m - 1; i++) {\n          \
    \  if (d[i] != ~0ULL) return false;\n        }\n        return d[m - 1] == mask();\n\
    \    }\n    bool none() const { return !any(); }\nprivate:\n    int n, m;\n  \
    \  vector<ull> d;\n    ull mask() const {\n        if (((n >> 6) << 6) == n) return\
    \ ~0ULL;\n        return (1ULL << (n & 63)) - 1;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/misc/bitset.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/misc/bitset.hpp
layout: document
redirect_from:
- /library/src/data_structure/misc/bitset.hpp
- /library/src/data_structure/misc/bitset.hpp.html
title: src/data_structure/misc/bitset.hpp
---
