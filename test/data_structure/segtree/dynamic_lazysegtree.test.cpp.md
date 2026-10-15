---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/segtree/dynamic_lazysegtree.hpp
    title: src/data_structure/segtree/dynamic_lazysegtree.hpp
  - icon: ':question:'
    path: src/math/affine.hpp
    title: src/math/affine.hpp
  - icon: ':question:'
    path: src/modint/modint.hpp
    title: src/modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum_large_array
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum_large_array
  bundledCode: "#line 1 \"test/data_structure/segtree/dynamic_lazysegtree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum_large_array\"\
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
    \ 3 \"src/data_structure/segtree/dynamic_lazysegtree.hpp\"\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename ActMonoid, integral T = int>\nstruct\
    \ dynamic_lazysegtree {\n    using M = ActMonoid;\n    using S = typename M::S;\n\
    \    using F = typename M::F;\n    dynamic_lazysegtree(T _n = 0, int q = 0) :\
    \ n(_n) {\n        int log = 1;\n        while (T(1) << log < n) log++;\n    \
    \    d.reserve(1 + 2 * q * log);\n        root = new_node(0, n);\n    }\n    void\
    \ set(T p, const S &x) {\n        assert(0 <= p && p < n);\n        set(root,\
    \ 0, n, p, x);\n    }\n    void apply(T l, T r, const F &f) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        apply(root, 0, n, l, r, f);\n    }\n   \
    \ S get(T p) {\n        assert(0 <= p && p < n);\n        return get(root, 0,\
    \ n, p);\n    }\n    S prod(T l, T r) {\n        assert(0 <= l && l <= r && r\
    \ <= n);\n        return prod(root, 0, n, l, r);\n    }\n    S all_prod() const\
    \ {\n        return d[root].x;\n    }\nprivate:\n    struct node {\n        S\
    \ x;\n        F lz;\n        int l, r;\n        node() : node(M::e()) {}\n   \
    \     node(const S &_x) : x(_x), lz(M::id()), l(-1), r(-1) {}\n    };\n    T n;\n\
    \    int root;\n    vector<node> d;\n    int new_node(T l, T r) {\n        int\
    \ res = d.size();\n        d.emplace_back(M::init(l, r));\n        return res;\n\
    \    }\n    void update(int t) {\n        int l = d[t].l, r = d[t].r;\n      \
    \  const S pl = l == -1 ? M::e() : d[l].x;\n        const S pr = r == -1 ? M::e()\
    \ : d[r].x;\n        d[t].x = M::op(pl, pr);\n    }\n    void all_apply(int t,\
    \ const F &f) {\n        if (t == -1) return;\n        d[t].x = M::map(f, d[t].x);\n\
    \        d[t].lz = M::comp(f, d[t].lz);\n    }\n    void push(int t, T l, T r)\
    \ {\n        T m = (l + r) / 2;\n        if (d[t].l == -1) d[t].l = new_node(l,\
    \ m);\n        if (d[t].r == -1) d[t].r = new_node(m, r);\n        all_apply(d[t].l,\
    \ d[t].lz);\n        all_apply(d[t].r, d[t].lz);\n        d[t].lz = M::id();\n\
    \    }\n    void set(int t, T l, T r, T p, const S &x) {\n        if (l + 1 ==\
    \ r) {\n            d[t].x = x;\n            return;\n        }\n        push(t,\
    \ l, r);\n        T m = (l + r) / 2;\n        p < m ? set(d[t].l, l, m, p, x)\
    \ : set(d[t].r, m, r, p, x);\n        update(t);\n    }\n    void apply(int t,\
    \ T l, T r, T ql, T qr, const F &f) {\n        if (r <= ql || qr <= l) return;\n\
    \        if (ql <= l && r <= qr) {\n            all_apply(t, f);\n           \
    \ return;\n        }\n        push(t, l, r);\n        T m = (l + r) / 2;\n   \
    \     apply(d[t].l, l, m, ql, qr, f);\n        apply(d[t].r, m, r, ql, qr, f);\n\
    \        update(t);\n    }\n    S get(int t, T l, T r, T p) {\n        if (t ==\
    \ -1) return M::e();\n        if (l + 1 == r) return d[t].x;\n        push(t,\
    \ l, r);\n        T m = (l + r) / 2;\n        return p < m ? get(d[t].l, l, m,\
    \ p) : get(d[t].r, m, r, p);\n    }\n    S prod(int t, T l, T r, T ql, T qr) {\n\
    \        if (t == -1 || r <= ql || qr <= l) return M::e();\n        if (ql <=\
    \ l && r <= qr) return d[t].x;\n        push(t, l, r);\n        T m = (l + r)\
    \ / 2;\n        return M::op(prod(d[t].l, l, m, ql, qr), prod(d[t].r, m, r, ql,\
    \ qr));\n    }\n};\n#line 6 \"test/data_structure/segtree/dynamic_lazysegtree.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\nstruct Monoid {\n    using S = affine<mint>;\n\
    \    static S op(S f, S g) { return g(f); }\n    static S e() { return affine<mint>();\
    \ }\n};\n\nusing mint = modint<998244353>;\n\nstruct ActMonoid {\n    using S\
    \ = pair<mint, int>;\n    static S op(S a, S b) {\n        return {a.first + b.first,\
    \ a.second + b.second};\n    }\n    static S e() {\n        return S{0, 0};\n\
    \    }\n    static S init(int l, int r) {\n        return S{0, r - l};\n    }\n\
    \    using F = affine<mint>;\n    static F id() { return F(); }\n    static F\
    \ comp(F f , F g) { return f(g); }\n    static S map(F f, S x) {\n        return\
    \ S{f.a * x.first + f.b * x.second, x.second};\n    }\n};\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    dynamic_lazysegtree<ActMonoid> seg(N, Q);\n \
    \   while (Q--) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n\
    \            int l, r, a, b;\n            cin >> l >> r >> a >> b;\n         \
    \   seg.apply(l, r, affine<mint>(a, b));\n        } else {\n            int l,\
    \ r;\n            cin >> l >> r;\n            cout << seg.prod(l, r).first.val()\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum_large_array\"\
    \n\n#include \"../../../src/modint/modint.hpp\"\n#include \"../../../src/math/affine.hpp\"\
    \n#include \"../../../src/data_structure/segtree/dynamic_lazysegtree.hpp\"\n\n\
    using mint = modint<998244353>;\n\nstruct Monoid {\n    using S = affine<mint>;\n\
    \    static S op(S f, S g) { return g(f); }\n    static S e() { return affine<mint>();\
    \ }\n};\n\nusing mint = modint<998244353>;\n\nstruct ActMonoid {\n    using S\
    \ = pair<mint, int>;\n    static S op(S a, S b) {\n        return {a.first + b.first,\
    \ a.second + b.second};\n    }\n    static S e() {\n        return S{0, 0};\n\
    \    }\n    static S init(int l, int r) {\n        return S{0, r - l};\n    }\n\
    \    using F = affine<mint>;\n    static F id() { return F(); }\n    static F\
    \ comp(F f , F g) { return f(g); }\n    static S map(F f, S x) {\n        return\
    \ S{f.a * x.first + f.b * x.second, x.second};\n    }\n};\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    dynamic_lazysegtree<ActMonoid> seg(N, Q);\n \
    \   while (Q--) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n\
    \            int l, r, a, b;\n            cin >> l >> r >> a >> b;\n         \
    \   seg.apply(l, r, affine<mint>(a, b));\n        } else {\n            int l,\
    \ r;\n            cin >> l >> r;\n            cout << seg.prod(l, r).first.val()\
    \ << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/modint/modint.hpp
  - src/math/affine.hpp
  - src/data_structure/segtree/dynamic_lazysegtree.hpp
  isVerificationFile: true
  path: test/data_structure/segtree/dynamic_lazysegtree.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:16:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/segtree/dynamic_lazysegtree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/segtree/dynamic_lazysegtree.test.cpp
- /verify/test/data_structure/segtree/dynamic_lazysegtree.test.cpp.html
title: test/data_structure/segtree/dynamic_lazysegtree.test.cpp
---
