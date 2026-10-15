---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/data_structure/segtree/directed_range_query.hpp
    title: src/data_structure/segtree/directed_range_query.hpp
  - icon: ':question:'
    path: src/data_structure/segtree/segtree.hpp
    title: src/data_structure/segtree/segtree.hpp
  - icon: ':question:'
    path: src/math/affine.hpp
    title: src/math/affine.hpp
  - icon: ':question:'
    path: src/modint/modint.hpp
    title: src/modint/modint.hpp
  - icon: ':x:'
    path: src/tree/hld.hpp
    title: src/tree/hld.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/tree/hld.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#line 2 \"src/tree/hld.hpp\"\n#include <algorithm>\n#include <cassert>\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate<typename SegTree, bool edge, bool\
    \ commutative>\nstruct heavy_light_decomposition {\n    using M = typename SegTree::M;\n\
    \    using S = typename M::S;\n    heavy_light_decomposition() = default;\n  \
    \  heavy_light_decomposition(int _n, int _r = 0) : n(_n), r(_r), id(0), built(false)\
    \ {\n        edges.reserve(n - 1);\n        if (n <= 1) build();\n    }\n    void\
    \ add_edge(int u, int v, const S &w = M::e()) {\n        assert(!built);\n   \
    \     assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        assert(u\
    \ != v);\n        edges.emplace_back(u, v, w);\n        if (ssize(edges) + 1 ==\
    \ n) build();\n    }\n    int lca(int u, int v) {\n        assert(built);\n  \
    \      assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        while\
    \ (true) {\n            if (in[u] > in[v]) swap(u, v);\n            if (head[u]\
    \ == head[v]) return u;\n            v = par[head[v]];\n        }\n        return\
    \ -1;\n    }\n    void set(int u, const S &w) {\n        assert(built);\n    \
    \    assert(0 <= u && u < n);\n        seg.set(idx(u), w);\n    }\n    void set(int\
    \ u, int v, const S &w) {\n        assert(built);\n        assert(0 <= u && u\
    \ < n);\n        assert(0 <= v && v < n);\n        assert(u != v);\n        seg.set(idx(u,\
    \ v), w);\n    }\n    template<typename F>\n    void apply(int u, int v, const\
    \ F &f) {\n        assert(built);\n        assert(0 <= u && u < n);\n        assert(0\
    \ <= v && v < n);\n        for (auto [l, r] : path_decompose(u, v)) {\n      \
    \      if (l > r) swap(l, r);\n            seg.apply(l, r, f);\n        }\n  \
    \  }\n    template<typename F>\n    void subtree_apply(int u, const F &f) {\n\
    \        assert(built);\n        assert(0 <= u && u < n);\n        seg.apply(in[u]\
    \ + edge, out[u], f);\n    }\n    S get(int u) {\n        assert(built);\n   \
    \     assert(0 <= u && u < n);\n        return seg.get(idx(u));\n    }\n    S\
    \ get(int u, int v) {\n        assert(built);\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        assert(u != v);\n        return seg.get(idx(u,\
    \ v));\n    }\n    S prod(int u, int v) {\n        assert(built);\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        S p = M::e();\n \
    \       for (auto [l, r] : path_decompose(u, v)) {\n            p = M::op(p, inner_prod(l,\
    \ r));\n        }\n        return p;\n    }\n    S subtree_prod(int u) {\n   \
    \     assert(built);\n        assert(0 <= u && u < n);\n        return seg.prod(in[u]\
    \ + edge, out[u]);\n    }\n    template<typename C>\n    int binary_search(int\
    \ u, int v, const C &check) {\n        assert(built);\n        assert(0 <= u &&\
    \ u < n);\n        assert(0 <= v && v < n);\n        S p = M::e();\n        for\
    \ (auto [l, r] : path_decompose(u, v)) {\n            S np = M::op(p, inner_prod(l,\
    \ r));\n            if (l < r) {\n                if (!check(np)) {\n        \
    \            return check(M::op(p, seg.get(l))) ? inv[\n                     \
    \   (commutative ? seg.max_right(l, [&](const S &x) {\n                      \
    \      return check(M::op(p, x));\n                        }) : seg.max_right(l,\
    \ false, [&](const S &x) {\n                            return check(M::op(p,\
    \ x));\n                        })) - 1\n                    ] : u;\n        \
    \        }\n                p = np;\n                u = inv[r - 1];\n       \
    \     } else {\n                swap(l, r);\n                if (!check(np)) {\n\
    \                    return check(M::op(p, seg.get(r - 1))) ? inv[\n         \
    \               commutative ? seg.min_left(r, [&](const S &x) {\n            \
    \                return check(M::op(p, x));\n                        }) : seg.min_left(r,\
    \ true, [&](const S &x) {\n                            return check(M::op(p, x));\n\
    \                        })\n                    ] : u;\n                }\n \
    \               p = np;\n                u = inv[l];\n            }\n        }\n\
    \        return v;\n    }\nprivate:\n    int n, r, id;\n    bool built;\n    SegTree\
    \ seg;\n    vector<vector<int>> g;\n    vector<int> sub, depth, par, in, out,\
    \ inv, head, heavy;\n    vector<tuple<int, int, S>> edges;\n    int idx(int u)\
    \ const {\n        assert(built);\n        return in[u];\n    }\n    int idx(int\
    \ u, int v) const {\n        assert(built);\n        return max(in[u], in[v]);\n\
    \    }\n    S inner_prod(int l, int r) {\n        if (commutative && l > r) swap(l,\
    \ r);\n        return seg.prod(l, r);\n    }\n    void dfs(int u, int p) {\n \
    \       par[u] = p;\n        sub[u] = 1;\n        int sub_max = 0;\n        for\
    \ (int v : g[u]) {\n            if (v != p) {\n                dfs(v, u);\n  \
    \              sub[u] += sub[v];\n                if (sub[v] > sub_max) {\n  \
    \                  sub_max = sub[v];\n                    heavy[u] = v;\n    \
    \            }\n            }\n        }\n    }\n    void decompose(int u, int\
    \ h) {\n        head[u] = h;\n        in[u] = id++;\n        inv[in[u]] = u;\n\
    \        if (heavy[u] != -1) decompose(heavy[u], h);\n        for (int v : g[u])\
    \ {\n            if (v != par[u] && v != heavy[u]) {\n                decompose(v,\
    \ v);\n            }\n        }\n        out[u] = id;\n    }\n    void build()\
    \ {\n        g = vector<vector<int>>(n);\n        sub = depth = in = inv = out\
    \ = head = vector<int>(n);\n        par = heavy = vector<int>(n, -1);\n      \
    \  for (const auto &[u, v, _] : edges) {\n            g[u].emplace_back(v);\n\
    \            g[v].emplace_back(u);\n        }\n        dfs(r, r);\n        decompose(r,\
    \ r);\n        built = true;\n        if (edge) {\n            vector<S> a(n,\
    \ M::e());\n            for (const auto &[u, v, w] : edges) {\n              \
    \  a[idx(u, v)] = w;\n            }\n            seg = SegTree(a);\n        }\
    \ else {\n            seg = SegTree(n);\n        }\n    }\n    vector<pair<int,\
    \ int>> path_decompose(int u, int v) const {\n        assert(built);\n       \
    \ assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        int hu =\
    \ head[u], hv = head[v];\n        vector<pair<int, int>> resl, resr;\n       \
    \ bool flip = true;\n        while (hu != hv) {\n            if (in[hu] > in[hv])\
    \ {\n                flip = !flip;\n                swap(u, v);\n            \
    \    swap(hu, hv);\n                swap(resl, resr);\n            }\n       \
    \     resl.emplace_back(in[hv], in[v] + 1);\n            v = par[hv];\n      \
    \      hu = head[u];\n            hv = head[v];\n        }\n        if (in[u]\
    \ > in[v]) {\n            flip = !flip;\n            swap(u, v);\n           \
    \ swap(resl, resr);\n        }\n        resl.emplace_back(in[u] + edge, in[v]\
    \ + 1);\n        if (flip) swap(resl, resr);\n        reverse(resr.begin(), resr.end());\n\
    \        vector<pair<int, int>> res;\n        for (auto [l, r] : resl) res.emplace_back(r,\
    \ l);\n        for (auto [l, r] : resr) res.emplace_back(l, r);\n        return\
    \ res;\n    }\n};\n#line 4 \"src/data_structure/segtree/segtree.hpp\"\nusing namespace\
    \ std;\n\ntemplate <typename Monoid>\nstruct segtree {\n    using M = Monoid;\n\
    \    using S = typename M::S;\n    segtree() : segtree(0) {}\n    segtree(int\
    \ _n) : segtree(vector<S>(_n, M::e())) {}\n    segtree(const vector<S> &v) : n(v.size())\
    \ {\n        log = 1;\n        while ((1 << log) < n) log++;\n        sz = 1 <<\
    \ log;\n        d = vector<S>(2 * sz, M::e());\n        for (int i = 0; i < n;\
    \ i++) d[i + sz] = v[i];\n        for (int i = sz - 1; i >= 1; i--) update(i);\n\
    \    }\n    void set(int p, const S &x) {\n        assert(0 <= p && p < n);\n\
    \        p += sz;\n        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n    void apply(int p, const S &x) {\n        assert(0 <= p &&\
    \ p < n);\n        set(p, M::op(x, d[p + sz]));\n    }\n    S get(int p) const\
    \ {\n        assert(0 <= p && p < n);\n        return d[p + sz];\n    }\n    S\
    \ prod(int l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n  \
    \      l += sz;\n        r += sz;\n        S pl = M::e(), pr = M::e();\n     \
    \   while (l < r) {\n            if (l & 1) pl = M::op(pl, d[l++]);\n        \
    \    if (r & 1) pr = M::op(d[--r], pr);\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n        return M::op(pl, pr);\n    }\n    S all_prod() const\
    \ { return d[1]; }\n    template<typename C>\n    int max_right(int l, const C\
    \ &check) const {\n        assert(0 <= l && l <= n);\n        assert(check(M::e()));\n\
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
    \ {\n        d[p] = M::op(d[2 * p], d[2 * p + 1]);\n    }\n};\n#line 3 \"src/data_structure/segtree/directed_range_query.hpp\"\
    \n#include <ranges>\n#line 5 \"src/data_structure/segtree/directed_range_query.hpp\"\
    \nusing namespace std;\n\ntemplate<typename SegTree>\nstruct directed_range_query\
    \ {\n    using M = typename SegTree::M;\n    using S = typename M::S;\n    directed_range_query()\
    \ = default;\n    directed_range_query(int _n) : n(_n), seg(_n), ges(_n) {}\n\
    \    directed_range_query(const vector<S> &v) : n(v.size()), seg(v), ges(vector<S>(v.rbegin(),\
    \ v.rend())) {}\n    void set(int p, const S &x) {\n        assert(0 <= p && p\
    \ < n);\n        seg.set(p, x);\n        ges.set(n - 1 - p, x);\n    }\n    template<typename\
    \ F>\n    void apply(int l, int r, const F &f) {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        seg.apply(l, r, f);\n        ges.apply(n - r, n - l,\
    \ f);\n    }\n    S get(int p) {\n        assert(0 <= p && p < n);\n        return\
    \ seg.get(p);\n    }\n    S prod(int l, int r) {\n        return l < r ? seg.prod(l,\
    \ r) : ges.prod(n - l, n - r);\n    }\n    template<typename C>\n    int max_right(int\
    \ l, bool rev, const C &check) {\n        return rev ? n - ges.min_left(n - l,\
    \ check) : seg.max_right(l, check);\n    }\n    template<typename C>\n    int\
    \ min_left(int r, bool rev, const C &check) {\n        return rev ? n - ges.max_right(n\
    \ - r, check) : seg.min_left(r, check);\n    }\nprivate:\n    int n;\n    SegTree\
    \ seg, ges;\n};\n#line 4 \"src/modint/modint.hpp\"\nusing namespace std;\n\ntemplate<int\
    \ MOD>\nstruct modint {\n    constexpr modint() : x(0) {}\n    constexpr modint(long\
    \ long v) {\n        long long y = v % m();\n        if (y < 0) y += m();\n  \
    \      x = (unsigned int)(y);\n    }\n    static constexpr modint raw(int v) {\n\
    \        modint a;\n        a.x = v;\n        return a;\n    }\n    static constexpr\
    \ int mod() { return m(); }\n    constexpr unsigned int val() const { return x;\
    \ }\n    constexpr modint& operator++() {\n        x++;\n        if (x == m())\
    \ x = 0;\n        return *this;\n    }\n    constexpr modint& operator--() {\n\
    \        if (x == 0) x = m();\n        x--;\n        return *this;\n    }\n  \
    \  constexpr modint operator++(int) {\n        modint res = *this;\n        ++*this;\n\
    \        return res;\n    }\n    constexpr modint operator--(int) {\n        modint\
    \ res = *this;\n        --*this;\n        return res;\n    }\n    constexpr modint&\
    \ operator+=(const modint &r) {\n        x += r.x;\n        if (x >= m()) x -=\
    \ m();\n        return *this;\n    }\n    constexpr modint& operator-=(const modint\
    \ &r) {\n        x -= r.x;\n        if (x >= m()) x += m();\n        return *this;\n\
    \    }\n    constexpr modint& operator*=(const modint &r) {\n        unsigned\
    \ long long y = x;\n        y *= r.x;\n        x = (unsigned int)(y % m());\n\
    \        return *this;\n    }\n    constexpr modint &operator/=(const modint &r)\
    \ {\n        return *this = *this * r.inv();\n    }\n    friend constexpr modint\
    \ operator+(const modint &a, const modint &b) {\n        return modint(a) += b;\n\
    \    }\n    friend constexpr modint operator-(const modint &a, const modint &b)\
    \ {\n        return modint(a) -= b;\n    }\n    friend constexpr modint operator*(const\
    \ modint &a, const modint &b) {\n        return modint(a) *= b;\n    }\n    friend\
    \ constexpr modint operator/(const modint &a, const modint &b) {\n        return\
    \ modint(a) /= b;\n    }\n    friend constexpr bool operator==(const modint &a,\
    \ const modint &b) {\n        return a.x == b.x;\n    }\n    friend constexpr\
    \ bool operator!=(const modint &a, const modint &b) {\n        return a.x != b.x;\n\
    \    }\n    constexpr modint operator+() const { return *this; }\n    constexpr\
    \ modint operator-() const { return modint() - *this; }\n    constexpr modint\
    \ pow(long long k) const {\n        assert(k >= 0);\n        modint a = *this;\n\
    \        modint res = 1;\n        while (k > 0) {\n            if (k & 1) res\
    \ *= a;\n            a *= a;\n            k >>= 1;\n        }\n        return\
    \ res;\n    }\n    constexpr modint inv() const {\n        long long a = x, b\
    \ = m(), u = 1, v = 0;\n        while (b > 0) {\n            long long t = a /\
    \ b;\n            a -= t * b;\n            swap(a, b);\n            u -= t * v;\n\
    \            swap(u, v);\n        }\n        return modint(u);\n    }\nprivate:\n\
    \    unsigned int x;\n    static constexpr unsigned int m() { return MOD; }\n\
    };\n#line 2 \"src/math/affine.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ mint>\nstruct affine {\n    mint a, b;\n    affine() : a(1), b(0) {}\n    affine(const\
    \ mint &_a, const mint &_b) : a(_a), b(_b) {}\n    mint operator()(const mint\
    \ &x) const {\n        return a * x + b;\n    }\n    affine operator()(const affine\
    \ &f) const {\n        mint c = a * f.a;\n        mint d = a * f.b + b;\n    \
    \    return affine(c, d);\n    }\n};\n#line 8 \"test/tree/hld.test.cpp\"\n\nusing\
    \ mint = modint<998244353>;\n\nstruct Monoid {\n    using S = affine<mint>;\n\
    \    static S op(S f, S g) { return g(f); }\n    static S e() { return S(); }\n\
    };\n\nusing SegTree = directed_range_query<segtree<Monoid>>;\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    vector<int> A(N), B(N);\n    for (int i = 0;\
    \ i < N; i++) cin >> A[i] >> B[i];\n    heavy_light_decomposition<SegTree, false,\
    \ false> G(N);\n    for (int i = 1, u, v; i < N; i++) {\n        cin >> u >> v;\n\
    \        G.add_edge(u, v);\n    }\n    for (int i = 0; i < N; i++) {\n       \
    \ G.set(i, affine<mint>(A[i], B[i]));\n    }\n    while (Q--) {\n        int t;\n\
    \        cin >> t;\n        if (t == 0) {\n            int u, a, b;\n        \
    \    cin >> u >> a >> b;\n            G.set(u, affine<mint>(a, b));\n        }\
    \ else {\n            int u, v, x;\n            cin >> u >> v >> x;\n        \
    \    auto f = G.prod(u, v);\n            cout << f(x).val() << '\\n';\n      \
    \  }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"../../src/tree/hld.hpp\"\n#include \"../../src/data_structure/segtree/segtree.hpp\"\
    \n#include \"../../src/data_structure/segtree/directed_range_query.hpp\"\n#include\
    \ \"../../src/modint/modint.hpp\"\n#include \"../../src/math/affine.hpp\"\n\n\
    using mint = modint<998244353>;\n\nstruct Monoid {\n    using S = affine<mint>;\n\
    \    static S op(S f, S g) { return g(f); }\n    static S e() { return S(); }\n\
    };\n\nusing SegTree = directed_range_query<segtree<Monoid>>;\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    vector<int> A(N), B(N);\n    for (int i = 0;\
    \ i < N; i++) cin >> A[i] >> B[i];\n    heavy_light_decomposition<SegTree, false,\
    \ false> G(N);\n    for (int i = 1, u, v; i < N; i++) {\n        cin >> u >> v;\n\
    \        G.add_edge(u, v);\n    }\n    for (int i = 0; i < N; i++) {\n       \
    \ G.set(i, affine<mint>(A[i], B[i]));\n    }\n    while (Q--) {\n        int t;\n\
    \        cin >> t;\n        if (t == 0) {\n            int u, a, b;\n        \
    \    cin >> u >> a >> b;\n            G.set(u, affine<mint>(a, b));\n        }\
    \ else {\n            int u, v, x;\n            cin >> u >> v >> x;\n        \
    \    auto f = G.prod(u, v);\n            cout << f(x).val() << '\\n';\n      \
    \  }\n    }\n}"
  dependsOn:
  - src/tree/hld.hpp
  - src/data_structure/segtree/segtree.hpp
  - src/data_structure/segtree/directed_range_query.hpp
  - src/modint/modint.hpp
  - src/math/affine.hpp
  isVerificationFile: true
  path: test/tree/hld.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:06:06+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/tree/hld.test.cpp
layout: document
redirect_from:
- /verify/test/tree/hld.test.cpp
- /verify/test/tree/hld.test.cpp.html
title: test/tree/hld.test.cpp
---
