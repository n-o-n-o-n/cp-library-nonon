---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/data_structure/segtree/dynamic_segtree.hpp
    title: src/data_structure/segtree/dynamic_segtree.hpp
  - icon: ':x:'
    path: src/math/affine.hpp
    title: src/math/affine.hpp
  - icon: ':question:'
    path: src/modint/modint.hpp
    title: src/modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite_large_array
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite_large_array
  bundledCode: "#line 1 \"test/data_structure/segtree/dynamic_segtree.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite_large_array\"\
    \n\n#line 2 \"src/modint/modint.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    using namespace std;\n\ntemplate<int MOD>\nstruct modint {\n    constexpr modint()\
    \ : x(0) {}\n    constexpr modint(long long v) {\n        long long y = v % m();\n\
    \        if (y < 0) y += m();\n        x = (unsigned int)(y);\n    }\n    static\
    \ constexpr modint raw(int v) {\n        modint a;\n        a.x = v;\n       \
    \ return a;\n    }\n    static constexpr int mod() { return m(); }\n    constexpr\
    \ unsigned int val() const { return x; }\n    constexpr modint& operator++() {\n\
    \        x++;\n        if (x == m()) x = 0;\n        return *this;\n    }\n  \
    \  constexpr modint& operator--() {\n        if (x == 0) x = m();\n        x--;\n\
    \        return *this;\n    }\n    constexpr modint operator++(int) {\n      \
    \  modint res = *this;\n        ++*this;\n        return res;\n    }\n    constexpr\
    \ modint operator--(int) {\n        modint res = *this;\n        --*this;\n  \
    \      return res;\n    }\n    constexpr modint& operator+=(const modint &r) {\n\
    \        x += r.x;\n        if (x >= m()) x -= m();\n        return *this;\n \
    \   }\n    constexpr modint& operator-=(const modint &r) {\n        x -= r.x;\n\
    \        if (x >= m()) x += m();\n        return *this;\n    }\n    constexpr\
    \ modint& operator*=(const modint &r) {\n        unsigned long long y = x;\n \
    \       y *= r.x;\n        x = (unsigned int)(y % m());\n        return *this;\n\
    \    }\n    constexpr modint &operator/=(const modint &r) {\n        return *this\
    \ = *this * r.inv();\n    }\n    friend constexpr modint operator+(const modint\
    \ &a, const modint &b) {\n        return modint(a) += b;\n    }\n    friend constexpr\
    \ modint operator-(const modint &a, const modint &b) {\n        return modint(a)\
    \ -= b;\n    }\n    friend constexpr modint operator*(const modint &a, const modint\
    \ &b) {\n        return modint(a) *= b;\n    }\n    friend constexpr modint operator/(const\
    \ modint &a, const modint &b) {\n        return modint(a) /= b;\n    }\n    friend\
    \ constexpr bool operator==(const modint &a, const modint &b) {\n        return\
    \ a.x == b.x;\n    }\n    friend constexpr bool operator!=(const modint &a, const\
    \ modint &b) {\n        return a.x != b.x;\n    }\n    constexpr modint operator+()\
    \ const { return *this; }\n    constexpr modint operator-() const { return modint()\
    \ - *this; }\n    constexpr modint pow(long long k) const {\n        assert(k\
    \ >= 0);\n        modint a = *this;\n        modint res = 1;\n        while (k\
    \ > 0) {\n            if (k & 1) res *= a;\n            a *= a;\n            k\
    \ >>= 1;\n        }\n        return res;\n    }\n    constexpr modint inv() const\
    \ {\n        long long a = x, b = m(), u = 1, v = 0;\n        while (b > 0) {\n\
    \            long long t = a / b;\n            a -= t * b;\n            swap(a,\
    \ b);\n            u -= t * v;\n            swap(u, v);\n        }\n        return\
    \ modint(u);\n    }\nprivate:\n    unsigned int x;\n    static constexpr unsigned\
    \ int m() { return MOD; }\n};\n#line 2 \"src/math/affine.hpp\"\nusing namespace\
    \ std;\n\ntemplate<typename mint>\nstruct affine {\n    mint a, b;\n    affine()\
    \ : a(1), b(0) {}\n    affine(const mint &_a, const mint &_b) : a(_a), b(_b) {}\n\
    \    mint operator()(const mint &x) const {\n        return a * x + b;\n    }\n\
    \    affine operator()(const affine &f) const {\n        mint c = a * f.a;\n \
    \       mint d = a * f.b + b;\n        return affine(c, d);\n    }\n};\n#line\
    \ 3 \"src/data_structure/segtree/dynamic_segtree.hpp\"\n#include <vector>\nusing\
    \ namespace std;\n\ntemplate<typename Monoid, integral T = int>\nstruct dynamic_segtree\
    \ {\n    using M = Monoid;\n    using S = typename M::S;\n    dynamic_segtree(T\
    \ _n = 0, int q = 0) : n(_n) {\n        int log = 1;\n        while (T(1) << log\
    \ < n) log++;\n        d.reserve(1 + 2 * q * log);\n        root = new_node();\n\
    \    }\n    void set(T p, const S &x) {\n        assert(0 <= p && p < n);\n  \
    \      set(root, 0, n, p, x);\n    }\n    S get(T p) const {\n        assert(0\
    \ <= p && p < n);\n        return get(root, 0, n, p);\n    }\n    S prod(T l,\
    \ T r) const {\n        assert(0 <= l && l <= r && r <= n);\n        return prod(root,\
    \ 0, n, l, r);\n    }\n    S all_prod() const {\n        return d[root].x;\n \
    \   }\nprivate:\n    struct node {\n        S x;\n        int l, r;\n        node()\
    \ : x(M::e()), l(-1), r(-1) {}\n    };\n    T n;\n    int root;\n    vector<node>\
    \ d;\n    int new_node() {\n        int res = d.size();\n        d.emplace_back();\n\
    \        return res;\n    }\n    void update(int t) {\n        int l = d[t].l,\
    \ r = d[t].r;\n        const S pl = l == -1 ? M::e() : d[l].x;\n        const\
    \ S pr = r == -1 ? M::e() : d[r].x;\n        d[t].x = M::op(pl, pr);\n    }\n\
    \    void set(int t, T l, T r, T p, const S &x) {\n        if (l + 1 == r) {\n\
    \            d[t].x = x;\n            return;\n        }\n        T m = (l + r)\
    \ / 2;\n        if (p < m) {\n            if (d[t].l == -1) d[t].l = new_node();\n\
    \            set(d[t].l, l, m, p, x);\n        } else {\n            if (d[t].r\
    \ == -1) d[t].r = new_node();\n            set(d[t].r, m, r, p, x);\n        }\n\
    \        update(t);\n    }\n    S get(int t, T l, T r, T p) const {\n        if\
    \ (t == -1) return M::e();\n        if (l + 1 == r) return d[t].x;\n        T\
    \ m = (l + r) / 2;\n        return p < m ? get(d[t].l, l, m, p) : get(d[t].r,\
    \ m, r, p);\n    }\n    S prod(int t, T l, T r, T ql, T qr) const {\n        if\
    \ (t == -1 || r <= ql || qr <= l) return M::e();\n        if (ql <= l && r <=\
    \ qr) return d[t].x;\n        T m = (l + r) / 2;\n        return M::op(prod(d[t].l,\
    \ l, m, ql, qr), prod(d[t].r, m, r, ql, qr));\n    }\n};\n#line 6 \"test/data_structure/segtree/dynamic_segtree.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\nstruct Monoid {\n    using S = affine<mint>;\n\
    \    static S op(S f, S g) { return g(f); }\n    static S e() { return affine<mint>();\
    \ }\n};\n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    dynamic_segtree<Monoid>\
    \ seg(N, Q);\n    while (Q--) {\n        int t;\n        cin >> t;\n        if\
    \ (t == 0) {\n            int p, a, b;\n            cin >> p >> a >> b;\n    \
    \        seg.set(p, affine<mint>(a, b));\n        } else {\n            int l,\
    \ r, x;\n            cin >> l >> r >> x;\n            auto f = seg.prod(l, r);\n\
    \            cout << f(x).val() << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite_large_array\"\
    \n\n#include \"../../../src/modint/modint.hpp\"\n#include \"../../../src/math/affine.hpp\"\
    \n#include \"../../../src/data_structure/segtree/dynamic_segtree.hpp\"\n\nusing\
    \ mint = modint<998244353>;\n\nstruct Monoid {\n    using S = affine<mint>;\n\
    \    static S op(S f, S g) { return g(f); }\n    static S e() { return affine<mint>();\
    \ }\n};\n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    dynamic_segtree<Monoid>\
    \ seg(N, Q);\n    while (Q--) {\n        int t;\n        cin >> t;\n        if\
    \ (t == 0) {\n            int p, a, b;\n            cin >> p >> a >> b;\n    \
    \        seg.set(p, affine<mint>(a, b));\n        } else {\n            int l,\
    \ r, x;\n            cin >> l >> r >> x;\n            auto f = seg.prod(l, r);\n\
    \            cout << f(x).val() << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/modint/modint.hpp
  - src/math/affine.hpp
  - src/data_structure/segtree/dynamic_segtree.hpp
  isVerificationFile: true
  path: test/data_structure/segtree/dynamic_segtree.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:16:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data_structure/segtree/dynamic_segtree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/segtree/dynamic_segtree.test.cpp
- /verify/test/data_structure/segtree/dynamic_segtree.test.cpp.html
title: test/data_structure/segtree/dynamic_segtree.test.cpp
---
