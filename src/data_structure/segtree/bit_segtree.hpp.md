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
  bundledCode: "#line 2 \"src/data_structure/segtree/bit_segtree.hpp\"\n#include <cassert>\n\
    #include <numeric>\n#include <vector>\nusing namespace std;\n\nstruct bit_segtree\
    \ {\n    bit_segtree() : bit_segtree(0) {}\n    bit_segtree(int _n) : bit_segtree(vector<int>(_n,\
    \ 0)) {}\n    template<typename T>\n    bit_segtree(const vector<T> &_v) : n(_v.size())\
    \ {\n        sz = (n + 63) >> 6;\n        bit = vector<unsigned long long>(sz,\
    \ 0);\n        d = v = vector<int>(sz, 0);\n        for (int p = 0; p < n; p++)\
    \ {\n            if (_v[p]) {\n                int i = p >> 6, j = p & 63;\n \
    \               bit[i] |= 1ULL << j;\n            }\n        }\n        for (int\
    \ i = 1; i <= sz; i++) {\n            v[i - 1] = __builtin_popcountll(bit[i -\
    \ 1]);\n            d[i - 1] += v[i - 1];\n            int j = i + (i & -i);\n\
    \            if (j <= sz) d[j - 1] += d[i - 1];\n        }\n    }\n    void set(int\
    \ p) {\n        assert(0 <= p && p < n);\n        int i = p >> 6, j = p & 63;\n\
    \        if ((bit[i] >> j & 1) == 0) {\n            bit[i] |= 1ULL << j;\n   \
    \         fw_update(i);\n        }\n    }\n    void reset(int p) {\n        assert(0\
    \ <= p && p < n);\n        int i = p >> 6, j = p & 63;\n        if (bit[i] >>\
    \ j & 1) {\n            bit[i] &= ~(1uLL << j);\n            fw_update(i);\n \
    \       }\n    }\n    void flip(int p) {\n        assert(0 <= p && p < n);\n \
    \       int i = p >> 6, j = p & 63;\n        bit[i] ^= 1ULL << j;\n        fw_update(i);\n\
    \    }\n    bool test(int p) const {\n        assert(0 <= p && p < n);\n     \
    \   return bit[p >> 6] >> (p & 63) & 1;\n    }\n    int count(int l, int r) const\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return 0;\n\
    \        int il = l >> 6, jl = l & 63;\n        int ir = r >> 6, jr = r & 63;\n\
    \        if (il == ir) {\n            return __builtin_popcountll((bit[il] >>\
    \ jl) & mask(jr - jl));\n        }\n        int res = fw_sum(ir) - fw_sum(il);\n\
    \        res -= __builtin_popcountll(bit[il] & mask(jl));\n        res += __builtin_popcountll(bit[ir]\
    \ & mask(jr));\n        return res;\n    }\n    bool all(int l, int r) const {\n\
    \        assert(0 <= l && l <= r && r <= n);\n        return count(l, r) == r\
    \ - l;\n    }\n    bool any(int l, int r) const {\n        assert(0 <= l && l\
    \ <= r && r <= n);\n        return count(l, r) > 0;\n    }\n    bool none(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n        return\
    \ count(l, r) == 0;\n    }\n    int lower_bound(int x) const {\n        int p\
    \ = fw_lower_bound(x);\n        if (p == sz) return n;\n        int l = 0, r =\
    \ 64;\n        while (r - l > 1) {\n            int m = (l + r) >> 1;\n      \
    \      (__builtin_popcountll(bit[p] & mask(m)) < x ? l : r) = m;\n        }\n\
    \        return (p << 6) ^ l;\n    }\nprivate:\n    int n, sz;\n    vector<unsigned\
    \ long long> bit;\n    vector<int> d, v;\n    static constexpr unsigned long long\
    \ mask(int m) {\n        return (1ULL << m) - 1;\n    }\n    void fw_update(int\
    \ p) {\n        int x = __builtin_popcountll(bit[p]) - v[p];\n        v[p] +=\
    \ x;\n        for (p++; p <= sz; p += p & -p) {\n            d[p - 1] += x;\n\
    \        }\n    }\n    int fw_sum(int p) const {\n        int res = 0;\n     \
    \   while (p > 0) {\n            res += d[p - 1];\n            p -= p & -p;\n\
    \        }\n        return res;\n    }\n    int fw_lower_bound(int &x) const {\n\
    \        int r = 0, p = 1;\n        while ((p << 1) <= sz) p <<= 1;\n        while\
    \ (p > 0) {\n            if (r + p <= sz && d[r + p - 1] < x) {\n            \
    \    r += p;\n                x -= d[r - 1];\n            }\n            p >>=\
    \ 1;\n        }\n        return r;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <numeric>\n#include <vector>\n\
    using namespace std;\n\nstruct bit_segtree {\n    bit_segtree() : bit_segtree(0)\
    \ {}\n    bit_segtree(int _n) : bit_segtree(vector<int>(_n, 0)) {}\n    template<typename\
    \ T>\n    bit_segtree(const vector<T> &_v) : n(_v.size()) {\n        sz = (n +\
    \ 63) >> 6;\n        bit = vector<unsigned long long>(sz, 0);\n        d = v =\
    \ vector<int>(sz, 0);\n        for (int p = 0; p < n; p++) {\n            if (_v[p])\
    \ {\n                int i = p >> 6, j = p & 63;\n                bit[i] |= 1ULL\
    \ << j;\n            }\n        }\n        for (int i = 1; i <= sz; i++) {\n \
    \           v[i - 1] = __builtin_popcountll(bit[i - 1]);\n            d[i - 1]\
    \ += v[i - 1];\n            int j = i + (i & -i);\n            if (j <= sz) d[j\
    \ - 1] += d[i - 1];\n        }\n    }\n    void set(int p) {\n        assert(0\
    \ <= p && p < n);\n        int i = p >> 6, j = p & 63;\n        if ((bit[i] >>\
    \ j & 1) == 0) {\n            bit[i] |= 1ULL << j;\n            fw_update(i);\n\
    \        }\n    }\n    void reset(int p) {\n        assert(0 <= p && p < n);\n\
    \        int i = p >> 6, j = p & 63;\n        if (bit[i] >> j & 1) {\n       \
    \     bit[i] &= ~(1uLL << j);\n            fw_update(i);\n        }\n    }\n \
    \   void flip(int p) {\n        assert(0 <= p && p < n);\n        int i = p >>\
    \ 6, j = p & 63;\n        bit[i] ^= 1ULL << j;\n        fw_update(i);\n    }\n\
    \    bool test(int p) const {\n        assert(0 <= p && p < n);\n        return\
    \ bit[p >> 6] >> (p & 63) & 1;\n    }\n    int count(int l, int r) const {\n \
    \       assert(0 <= l && l <= r && r <= n);\n        if (l == r) return 0;\n \
    \       int il = l >> 6, jl = l & 63;\n        int ir = r >> 6, jr = r & 63;\n\
    \        if (il == ir) {\n            return __builtin_popcountll((bit[il] >>\
    \ jl) & mask(jr - jl));\n        }\n        int res = fw_sum(ir) - fw_sum(il);\n\
    \        res -= __builtin_popcountll(bit[il] & mask(jl));\n        res += __builtin_popcountll(bit[ir]\
    \ & mask(jr));\n        return res;\n    }\n    bool all(int l, int r) const {\n\
    \        assert(0 <= l && l <= r && r <= n);\n        return count(l, r) == r\
    \ - l;\n    }\n    bool any(int l, int r) const {\n        assert(0 <= l && l\
    \ <= r && r <= n);\n        return count(l, r) > 0;\n    }\n    bool none(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n        return\
    \ count(l, r) == 0;\n    }\n    int lower_bound(int x) const {\n        int p\
    \ = fw_lower_bound(x);\n        if (p == sz) return n;\n        int l = 0, r =\
    \ 64;\n        while (r - l > 1) {\n            int m = (l + r) >> 1;\n      \
    \      (__builtin_popcountll(bit[p] & mask(m)) < x ? l : r) = m;\n        }\n\
    \        return (p << 6) ^ l;\n    }\nprivate:\n    int n, sz;\n    vector<unsigned\
    \ long long> bit;\n    vector<int> d, v;\n    static constexpr unsigned long long\
    \ mask(int m) {\n        return (1ULL << m) - 1;\n    }\n    void fw_update(int\
    \ p) {\n        int x = __builtin_popcountll(bit[p]) - v[p];\n        v[p] +=\
    \ x;\n        for (p++; p <= sz; p += p & -p) {\n            d[p - 1] += x;\n\
    \        }\n    }\n    int fw_sum(int p) const {\n        int res = 0;\n     \
    \   while (p > 0) {\n            res += d[p - 1];\n            p -= p & -p;\n\
    \        }\n        return res;\n    }\n    int fw_lower_bound(int &x) const {\n\
    \        int r = 0, p = 1;\n        while ((p << 1) <= sz) p <<= 1;\n        while\
    \ (p > 0) {\n            if (r + p <= sz && d[r + p - 1] < x) {\n            \
    \    r += p;\n                x -= d[r - 1];\n            }\n            p >>=\
    \ 1;\n        }\n        return r;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/segtree/bit_segtree.hpp
  requiredBy: []
  timestamp: '2025-06-26 18:44:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/segtree/bit_segtree.hpp
layout: document
redirect_from:
- /library/src/data_structure/segtree/bit_segtree.hpp
- /library/src/data_structure/segtree/bit_segtree.hpp.html
title: src/data_structure/segtree/bit_segtree.hpp
---
