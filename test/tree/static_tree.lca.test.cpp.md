---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/segtree/static_rmq.hpp
    title: src/data_structure/segtree/static_rmq.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/sparse_table/sparse_table.hpp
    title: src/data_structure/sparse_table/sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: src/tree/static_tree.hpp
    title: src/tree/static_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/tree/static_tree.lca.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/lca\"\n\n#line 2 \"src/tree/static_tree.hpp\"\n\
    #include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <stack>\n\
    #include <vector>\nusing namespace std;\n#line 2 \"src/data_structure/sparse_table/sparse_table.hpp\"\
    \n#include <bit>\n#line 5 \"src/data_structure/sparse_table/sparse_table.hpp\"\
    \nusing namespace std;\n\ntemplate<typename Monoid>\nstruct sparse_table {\n \
    \   using M = Monoid;\n    using S = typename M::S;\n    sparse_table() = default;\n\
    \    sparse_table(const vector<S> &v) : n(v.size()), b(0), d(1, v) { build();\
    \ }\n    S prod(int l, int r) const {\n        assert(0 <= l && l <= r && r <=n);\n\
    \        if (l == r) return M::e();\n        int i = bit_width(unsigned(r - l))\
    \ - 1;\n        return M::op(d[i][l], d[i][r - (1 << i)]);\n    }\nprivate:\n\
    \    int n, b, e;\n    vector<vector<S>> d;\n    void build() {\n        b = bit_width(unsigned(n));\n\
    \        d.resize(b, vector<S>(n, M::e()));\n        for (int i = 1; i < b; i++)\
    \ {\n            for (int j = 0; j + (1 << i) <=n; j++) {\n                d[i][j]\
    \ = M::op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);\n            }\n       \
    \ }\n    }\n};\n#line 5 \"src/data_structure/segtree/static_rmq.hpp\"\nusing namespace\
    \ std;\n\n// \u53C2\u8003: https://judge.yosupo.jp/submission/200540\ntemplate<typename\
    \ Monoid>\nstruct static_rmq {\n    using M = Monoid;\n    using S = typename\
    \ M::S;\n    static_rmq() = default;\n    static_rmq(const vector<S> &_v) : n(_v.size()),\
    \ v(_v), pref(_v), suf(_v) { build(); }\n    S prod(int l, int r) const {\n  \
    \      assert(0 <= l && l <= r && r <= n);\n        if (l == r) return M::e();\n\
    \        r--;\n        int bl = l >> log, br = r >> log;\n        if (bl < br)\
    \ {\n            return M::op(M::op(pref[r], suf[l]), st.prod(bl + 1, br));\n\
    \        }\n        S p = M::e();\n        for (int i = l; i <= r; i++) p = M::op(p,\
    \ v[i]);\n        return p;\n    }\nprivate:\n    int n;\n    static constexpr\
    \ int log = 4, mask = 15;\n    vector<S> v, pref, suf;\n    sparse_table<M> st;\n\
    \    void build() {\n        for (int i = 1; i < n; i++) {\n            if (i\
    \ & mask) pref[i] = M::op(pref[i - 1], v[i]);\n        }\n        for (int i =\
    \ n - 1; i > 0; i--) {\n            if (i & mask) suf[i - 1] = M::op(suf[i], v[i\
    \ - 1]);\n        }\n        st = sparse_table<M>([&]{\n            vector<S>\
    \ a(n >> log);\n            for (int i = 0; i < (n >> log); i++) {\n         \
    \       a[i] = suf[i << log];\n            }\n            return a;\n        }());\n\
    \    }\n};\n#line 9 \"src/tree/static_tree.hpp\"\n\nstruct static_tree {\n   \
    \ static_tree() = default;\n    static_tree(int _n, int r = 0) : n(_n), e(0),\
    \ root(r), g(_n), built(false) {\n        if (n <= 1) build();\n    }\n    void\
    \ set_root(int r) {\n        assert(0 <= r && r < n);\n        root = r;\n   \
    \     built = false;\n        build();\n    }\n    void add_edge(int u, int v)\
    \ {\n        assert(!built);\n        assert(e < n - 1);\n        assert(0 <=\
    \ u && u < n);\n        assert(0 <= v && v < n);\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n        if (++e == n - 1) build();\n    }\n    void\
    \ read_edges(bool idx = 1) {\n        for (int i = 1, u, v; i < n; i++) {\n  \
    \          cin >> u >> v;\n            u -= idx;\n            v -= idx;\n    \
    \        g[u].push_back(v);\n            g[v].push_back(u);\n        }\n     \
    \   build();\n    }\n    vector<int> &operator[](int u) {\n        assert(0 <=\
    \ u && u < n);\n        return g[u];\n    }\n    int depth(int u) const {\n  \
    \      assert(built);\n        assert(0 <= u && u < n);\n        return d[u];\n\
    \    }\n    int lca(int u, int v, int r = -1) const {\n        assert(built);\n\
    \        assert(0 <= u && u < n);\n        if (r == -1) {\n            auto [kl,\
    \ kr] = minmax(in[u], in[v]);\n            return get<2>(st.prod(kl, kr + 1));\n\
    \        }\n        assert(0 <= r && r < n);\n        return lca(u, v) ^ lca(v,\
    \ r) ^ lca(r, u);\n    }\n    int dist(int u, int v) const {\n        assert(built);\n\
    \        int w = lca(u, v);\n        return d[u] + d[v] - 2 * d[w];\n    }\n \
    \   int jump(int u, int v, int k) const {\n        assert(built);\n        int\
    \ w = lca(u, v);\n        if (d[u] + d[v] - 2 * d[w] < k) return -1;\n       \
    \ if (d[u] - d[w] < k) {\n            swap(u, v);\n            k = d[u] + d[v]\
    \ - 2 * d[w] - k;\n        }\n        k = d[u] - k;\n        return *prev(upper_bound(list[k].begin(),\
    \ list[k].end(), u, [&] (int i, int j) {\n            return in[i] < in[j];\n\
    \        }));\n    }\n    bool is_on_path(int w, int u, int v) const {\n     \
    \   assert(built);\n        assert(0 <= w && w < n);\n        assert(0 <= u &&\
    \ u < n);\n        assert(0 <= v && v < n);\n        return lca(u, v, w) == w;\n\
    \    }\n    int sub_size(int u, int r = -1) const {\n        assert(built);\n\
    \        assert(0 <= u && u < n);\n        if (r == -1) r = root;\n        assert(0\
    \ <= r && r < n);\n        if (r == u) return n;\n        if (lca(u, r) != u)\
    \ return sz[u];\n        auto [kl, kr] = minmax(in[u], in[r]);\n        return\
    \ n - sz[ord[1 - get<1>(st.prod(kl, kr + 1))]];\n    }\n    vector<int> path(int\
    \ u, int v) const {\n        assert(built);\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        int w = lca(u, v);\n        vector<int>\
    \ pu, pv;\n        while (u != w) {\n            pu.push_back(u);\n          \
    \  u = ord[in[u] - 1];\n        }\n        while (v != w) {\n            pv.push_back(v);\n\
    \            v = ord[in[v] - 1];\n        }\n        reverse(pv.begin(), pv.end());\n\
    \        pu.push_back(w);\n        pu.insert(pu.end(), pv.begin(), pv.end());\n\
    \        return pu;\n    }\n    vector<pair<int, int>> auxiliary_tree(vector<int>\
    \ vs) const {\n        if (vs.empty()) return {};\n        sort(vs.begin(), vs.end(),\
    \ [&] (int u, int v) {\n            return in[u] < in[v];\n        });\n     \
    \   vs.erase(unique(vs.begin(), vs.end()), vs.end());\n        vector<pair<int,\
    \ int>> res;\n        stack<int> st;\n        st.push(vs[0]);\n        for (int\
    \ i = 1; i < ssize(vs); i++) {\n            int w = lca(vs[i - 1], vs[i]);\n \
    \           if (w != vs[i - 1]) {\n                int u = st.top();\n       \
    \         st.pop();\n                while (st.size() && d[w] < d[st.top()]) {\n\
    \                    res.emplace_back(u, st.top());\n                    u = st.top();\n\
    \                    st.pop();\n                }\n                res.emplace_back(u,\
    \ w);\n                if (st.empty() || st.top() != w) st.push(w);\n        \
    \    }\n            st.push(vs[i]);\n        }\n        while (st.size() > 1)\
    \ {\n            int u = st.top();\n            st.pop();\n            res.emplace_back(u,\
    \ st.top());\n        }\n        return res;\n    }\nprivate:\n    struct Monoid\
    \ {\n        using S = tuple<int, int, int>;\n        static S op(S a, S b) {\n\
    \            return min(a, b);\n        }\n        static S e() {\n          \
    \  return make_tuple(1 << 30, 1 << 30, -1);\n        }\n    };\n    int n, e,\
    \ root;\n    vector<vector<int>> g, list;\n    bool built;\n    vector<int> d,\
    \ ord, in, sz;\n    static_rmq<Monoid> st;\n    int dfs(int u, int p) {\n    \
    \    ord.push_back(u);\n        list[d[u]].push_back(u);\n        for (int v :\
    \ g[u]) {\n            if (v != p) {\n                d[v] = d[u] + 1;\n     \
    \           sz[u] += dfs(v, u);\n                ord.push_back(u);\n         \
    \   }\n        }\n        return ++sz[u];\n    }\n    void build() {\n       \
    \ if (built) return;\n        d = vector<int>(n, 0);\n        sz = vector<int>(n,\
    \ 0);\n        ord.reserve(2 * n);\n        list = vector<vector<int>>(n);\n \
    \       dfs(root, root);\n        in = vector<int>(n, -1);\n        st = static_rmq<Monoid>([&]{\n\
    \            vector<Monoid::S> a(ord.size());\n            for (int i = 0; i <\
    \ ssize(ord); i++) {\n                int u = ord[i];\n                if (in[u]\
    \ == -1) in[u] = i;\n                a[i] = make_tuple(d[u], -i, u);\n       \
    \     }\n            return a;\n        }());\n        built = true;\n    }\n\
    };\n#line 4 \"test/tree/static_tree.lca.test.cpp\"\n\n#line 6 \"test/tree/static_tree.lca.test.cpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n  \
    \  int N, Q;\n    cin >> N >> Q;\n    static_tree G(N);\n    for (int i = 1, p;\
    \ i < N; i++) {\n        cin >> p;\n        G.add_edge(i, p);\n    }\n    for\
    \ (int u, v; Q--; ) {\n        cin >> u >> v;\n        cout << G.lca(u, v) <<\
    \ '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../src/tree/static_tree.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    static_tree G(N);\n\
    \    for (int i = 1, p; i < N; i++) {\n        cin >> p;\n        G.add_edge(i,\
    \ p);\n    }\n    for (int u, v; Q--; ) {\n        cin >> u >> v;\n        cout\
    \ << G.lca(u, v) << '\\n';\n    }\n}"
  dependsOn:
  - src/tree/static_tree.hpp
  - src/data_structure/segtree/static_rmq.hpp
  - src/data_structure/sparse_table/sparse_table.hpp
  isVerificationFile: true
  path: test/tree/static_tree.lca.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:16:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/static_tree.lca.test.cpp
layout: document
redirect_from:
- /verify/test/tree/static_tree.lca.test.cpp
- /verify/test/tree/static_tree.lca.test.cpp.html
title: test/tree/static_tree.lca.test.cpp
---
