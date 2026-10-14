---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data_structure/segtree/segtree.hpp
    title: src/data_structure/segtree/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/rolling_hash_dynamic.hpp\"\n#include <array>\n\
    #include <cassert>\n#include <vector>\n#line 4 \"src/data_structure/segtree/segtree.hpp\"\
    \nusing namespace std;\n\ntemplate <typename Monoid>\nstruct segtree {\n    using\
    \ M = Monoid;\n    using S = typename M::S;\n    segtree() : segtree(0) {}\n \
    \   segtree(int _n) : segtree(vector<S>(_n, M::e())) {}\n    segtree(const vector<S>\
    \ &v) : n(v.size()) {\n        log = 1;\n        while ((1 << log) < n) log++;\n\
    \        sz = 1 << log;\n        d = vector<S>(2 * sz, M::e());\n        for (int\
    \ i = 0; i < n; i++) d[i + sz] = v[i];\n        for (int i = sz - 1; i >= 1; i--)\
    \ update(i);\n    }\n    void set(int p, const S &x) {\n        assert(0 <= p\
    \ && p < n);\n        p += sz;\n        d[p] = x;\n        for (int i = 1; i <=\
    \ log; i++) update(p >> i);\n    }\n    void apply(int p, const S &x) {\n    \
    \    assert(0 <= p && p < n);\n        set(p, M::op(x, d[p + sz]));\n    }\n \
    \   S get(int p) const {\n        assert(0 <= p && p < n);\n        return d[p\
    \ + sz];\n    }\n    S prod(int l, int r) const {\n        assert(0 <= l && l\
    \ <= r && r <= n);\n        l += sz;\n        r += sz;\n        S pl = M::e(),\
    \ pr = M::e();\n        while (l < r) {\n            if (l & 1) pl = M::op(pl,\
    \ d[l++]);\n            if (r & 1) pr = M::op(d[--r], pr);\n            l >>=\
    \ 1;\n            r >>= 1;\n        }\n        return M::op(pl, pr);\n    }\n\
    \    S all_prod() const { return d[1]; }\n    template<typename C>\n    int max_right(int\
    \ l, const C &check) const {\n        assert(0 <= l && l <= n);\n        assert(check(M::e()));\n\
    \        if (l == n) return l;\n        l += sz;\n        S p = M::e();\n    \
    \    do {\n            while (!(l & 1)) l >>= 1;\n            S np = M::op(p,\
    \ d[l]);\n            if (!check(np)) {\n                while (l < sz) {\n  \
    \                  l <<= 1;\n                    np = M::op(p, d[l]);\n      \
    \              if (check(np)) {\n                        p = np;\n           \
    \             l++;\n                    }\n                }\n               \
    \ return l - sz;\n            }\n            p = np;\n            l++;\n     \
    \   } while ((l & -l) != l);\n        return n;\n    }\n    template<typename\
    \ C>\n    int max_right(const C &check) const {\n        return max_right(0, check);\n\
    \    }\n    template<typename C>\n    int min_left(int r, const C &check) const\
    \ {\n        assert(0 <= r && r <= n);\n        assert(check(M::e()));\n     \
    \   if (r == 0) return r;\n        r += sz;\n        S p = M::e();\n        do\
    \ {\n            r--;\n            while (r > 1 && r & 1) r >>= 1;\n         \
    \   S np = M::op(d[r], p);\n            if (!check(np)) {\n                while\
    \ (r < sz) {\n                    (r <<= 1)++;\n                    np = M::op(d[r],\
    \ p);\n                    if (check(np)) {\n                        p = np;\n\
    \                        r--;\n                    }\n                }\n    \
    \            return r + 1 - sz;\n            }\n            p = np;\n        }\
    \ while ((r & -r) != r);\n        return 0;\n    }\n    template<typename C>\n\
    \    int min_left(const C &check) const {\n        return min_left(n, check);\n\
    \    }\nprivate:\n    int n, log, sz;\n    vector<S> d;\n    void update(int p)\
    \ {\n        d[p] = M::op(d[2 * p], d[2 * p + 1]);\n    }\n};\n#line 6 \"src/string/rolling_hash_dynamic.hpp\"\
    \nusing namespace std;\n\nstruct rolling_hash {\n    static long long base, p,\
    \ q;\n    static array<long long, 3> inv;\n    static constexpr array<long long,\
    \ 3> mod = {1000274903LL, 1000274927LL, 1000274953LL};\n    static vector<array<long\
    \ long, 3>> pow;\n    static void set_base(int b) {\n        assert(base == -1);\n\
    \        assert(2 <= b && b <= int(1e9));\n        base = b;\n        p = (b +\
    \ (b >> 5)) % 2749;\n        q = (b + (b >> 9)) % 274;\n    }\n    rolling_hash(const\
    \ string &s) {\n        assert(base != -1);\n        int n = s.size();\n     \
    \   init(n);\n        vector<pair<array<long long, 3>, int>> v(n);\n        for\
    \ (int i = 0; i < n; i++) {\n            v[i].first.fill(inner_hash(s[i]));\n\
    \            v[i].second = 1;\n        }\n        d = segtree<Monoid>(v);\n  \
    \  }\n    void set(int p, char c) {\n        array<long long, 3> x;\n        x.fill(inner_hash(c));\n\
    \        d.set(p, make_pair(x, 1));\n    }\n    array<long long, 3> prod(int l,\
    \ int r) {\n        return d.prod(l, r).first;\n    }\nprivate:\n    struct Monoid\
    \ {\n        using S = pair<array<long long, 3>, int>;\n        static S op(const\
    \ S &a, const S &b) {\n            S c;\n            for (int j = 0; j < 3; j++)\
    \ {\n                c.first[j] = (a.first[j] + b.first[j] * pow[a.second][j])\
    \ % mod[j];\n            }\n            c.second = a.second + b.second;\n    \
    \        return c;\n        }\n        static S e() {\n            return make_pair(array<long\
    \ long, 3>{0, 0, 0,}, 0);\n        }\n    };\n    segtree<Monoid> d;\n    static\
    \ long long mod_inv(long long x, long long m) {\n        long long a = x, r =\
    \ 1, k = m - 2;\n        while (k > 0) {\n            if (k & 1) r = (r * a) %\
    \ m;\n            a = (a * a) % m;\n            k >>= 1;\n        }\n        return\
    \ r;\n    }\n    static void init(int n) {\n        int sz = pow.size();\n   \
    \     if (n + 1 < sz) return;\n        n = max(n + 1, 2 * sz);\n        pow.resize(n);\n\
    \        for (int i = sz; i < n; i++) {\n            for (int j = 0; j < 3; j++)\
    \ {\n                pow[i][j] = (pow[i - 1][j] * base) % mod[j];\n          \
    \  }\n        }\n    }\n    long long inner_hash(const char &c) const {\n    \
    \    int res = static_cast<int>(c);\n        res = (res + (res << 4)) + p;\n \
    \       res = ((res << 2) ^ (res >> 3)) * q;\n        return res;\n    }\n};\n\
    long long rolling_hash::base(-1);\nlong long rolling_hash::p(-1);\nlong long rolling_hash::q(-1);\n\
    array<long long, 3> rolling_hash::inv({1, 1, 1});\nvector<array<long long, 3>>\
    \ rolling_hash::pow(1, {1, 1, 1});\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <vector>\n#include\
    \ \"../data_structure/segtree/segtree.hpp\"\nusing namespace std;\n\nstruct rolling_hash\
    \ {\n    static long long base, p, q;\n    static array<long long, 3> inv;\n \
    \   static constexpr array<long long, 3> mod = {1000274903LL, 1000274927LL, 1000274953LL};\n\
    \    static vector<array<long long, 3>> pow;\n    static void set_base(int b)\
    \ {\n        assert(base == -1);\n        assert(2 <= b && b <= int(1e9));\n \
    \       base = b;\n        p = (b + (b >> 5)) % 2749;\n        q = (b + (b >>\
    \ 9)) % 274;\n    }\n    rolling_hash(const string &s) {\n        assert(base\
    \ != -1);\n        int n = s.size();\n        init(n);\n        vector<pair<array<long\
    \ long, 3>, int>> v(n);\n        for (int i = 0; i < n; i++) {\n            v[i].first.fill(inner_hash(s[i]));\n\
    \            v[i].second = 1;\n        }\n        d = segtree<Monoid>(v);\n  \
    \  }\n    void set(int p, char c) {\n        array<long long, 3> x;\n        x.fill(inner_hash(c));\n\
    \        d.set(p, make_pair(x, 1));\n    }\n    array<long long, 3> prod(int l,\
    \ int r) {\n        return d.prod(l, r).first;\n    }\nprivate:\n    struct Monoid\
    \ {\n        using S = pair<array<long long, 3>, int>;\n        static S op(const\
    \ S &a, const S &b) {\n            S c;\n            for (int j = 0; j < 3; j++)\
    \ {\n                c.first[j] = (a.first[j] + b.first[j] * pow[a.second][j])\
    \ % mod[j];\n            }\n            c.second = a.second + b.second;\n    \
    \        return c;\n        }\n        static S e() {\n            return make_pair(array<long\
    \ long, 3>{0, 0, 0,}, 0);\n        }\n    };\n    segtree<Monoid> d;\n    static\
    \ long long mod_inv(long long x, long long m) {\n        long long a = x, r =\
    \ 1, k = m - 2;\n        while (k > 0) {\n            if (k & 1) r = (r * a) %\
    \ m;\n            a = (a * a) % m;\n            k >>= 1;\n        }\n        return\
    \ r;\n    }\n    static void init(int n) {\n        int sz = pow.size();\n   \
    \     if (n + 1 < sz) return;\n        n = max(n + 1, 2 * sz);\n        pow.resize(n);\n\
    \        for (int i = sz; i < n; i++) {\n            for (int j = 0; j < 3; j++)\
    \ {\n                pow[i][j] = (pow[i - 1][j] * base) % mod[j];\n          \
    \  }\n        }\n    }\n    long long inner_hash(const char &c) const {\n    \
    \    int res = static_cast<int>(c);\n        res = (res + (res << 4)) + p;\n \
    \       res = ((res << 2) ^ (res >> 3)) * q;\n        return res;\n    }\n};\n\
    long long rolling_hash::base(-1);\nlong long rolling_hash::p(-1);\nlong long rolling_hash::q(-1);\n\
    array<long long, 3> rolling_hash::inv({1, 1, 1});\nvector<array<long long, 3>>\
    \ rolling_hash::pow(1, {1, 1, 1});"
  dependsOn:
  - src/data_structure/segtree/segtree.hpp
  isVerificationFile: false
  path: src/string/rolling_hash_dynamic.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/rolling_hash_dynamic.hpp
layout: document
redirect_from:
- /library/src/string/rolling_hash_dynamic.hpp
- /library/src/string/rolling_hash_dynamic.hpp.html
title: src/string/rolling_hash_dynamic.hpp
---
