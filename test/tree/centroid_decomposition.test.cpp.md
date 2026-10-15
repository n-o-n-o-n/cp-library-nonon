---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/data_structure/segtree/static_rmq.hpp
    title: src/data_structure/segtree/static_rmq.hpp
  - icon: ':x:'
    path: src/data_structure/sparse_table/sparse_table.hpp
    title: src/data_structure/sparse_table/sparse_table.hpp
  - icon: ':question:'
    path: src/misc/even_distribution_array.hpp
    title: src/misc/even_distribution_array.hpp
  - icon: ':x:'
    path: src/random/graph.hpp
    title: src/random/graph.hpp
  - icon: ':question:'
    path: src/random/sequence.hpp
    title: src/random/sequence.hpp
  - icon: ':question:'
    path: src/random/utility.hpp
    title: src/random/utility.hpp
  - icon: ':x:'
    path: src/tree/centroid_decomposition.hpp
    title: src/tree/centroid_decomposition.hpp
  - icon: ':x:'
    path: src/tree/prufer_code.hpp
    title: src/tree/prufer_code.hpp
  - icon: ':x:'
    path: src/tree/static_tree.hpp
    title: src/tree/static_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/tree/centroid_decomposition.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"src/tree/centroid_decomposition.hpp\"\
    \n#include <cassert>\n#include <vector>\nusing namespace std;\n\nstruct centroid_decomposition\
    \ {\n    centroid_decomposition() = default;\n    centroid_decomposition(int _n)\
    \ : n(_n), e(0), g(_n) {\n        if (n == 1) build();\n    }\n    centroid_decomposition(const\
    \ vector<vector<int>> &_g) : n(_g.size()), g(_g) {\n        build();\n    }\n\
    \    void add_edge(int u, int v) {\n        assert(0 <= u && u < n);\n       \
    \ assert(0 <= v && v < n);\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \        if (++e == n - 1) build();\n    }\n    vector<int> operator[](int u)\
    \ const { return g[u]; }\n    int level(int u) const { return lv[u]; }\n    int\
    \ sub_size(int u) const { return sub[u]; }\n    int parent(int u) const { return\
    \ par[u]; }\n    vector<int> level_vector() const { return lv; }\n    vector<int>\
    \ sub_size_vector() const { return sub; }\n    vector<int> parent_vector() const\
    \ { return par; }\nprivate:\n    int n, e;\n    vector<vector<int>> g;\n    vector<int>\
    \ sz, lv, sub, par;\n    int dfs_size(int u, int p) {\n        sz[u] = 1;\n  \
    \      for (int v : g[u]) {\n            if (v != p && lv[v] == -1) {\n      \
    \          sz[u] += dfs_size(v, u);\n            }\n        }\n        return\
    \ sz[u];\n    }\n    int dfs_centroid(int u, int p, int s) {\n        for (int\
    \ v : g[u]) {\n            if (v != p && lv[v] == -1 && sz[v] > s / 2) {\n   \
    \             return dfs_centroid(v, u, s);\n            }\n        }\n      \
    \  return u;\n    }\n    void decompose(int u, int p, int k) {\n        int s\
    \ = dfs_size(u, -1);\n        int c = dfs_centroid(u, -1, s);\n        lv[c] =\
    \ k;\n        sub[c] = s;\n        par[c] = p;\n        for (int v : g[c]) {\n\
    \            if (lv[v] == -1) {\n                decompose(v, c, k + 1);\n   \
    \         }\n        }\n    }\n    void build() {\n        sz = lv = sub = par\
    \ = vector<int>(n, -1);\n        decompose(0, -1, 0);\n    }\n};\n#line 2 \"src/tree/static_tree.hpp\"\
    \n#include <algorithm>\n#line 4 \"src/tree/static_tree.hpp\"\n#include <iostream>\n\
    #include <stack>\n#line 7 \"src/tree/static_tree.hpp\"\nusing namespace std;\n\
    #line 2 \"src/data_structure/sparse_table/sparse_table.hpp\"\n#include <bit>\n\
    #line 5 \"src/data_structure/sparse_table/sparse_table.hpp\"\nusing namespace\
    \ std;\n\ntemplate<typename Monoid>\nstruct sparse_table {\n    using M = Monoid;\n\
    \    using S = typename M::S;\n    sparse_table() = default;\n    sparse_table(const\
    \ vector<S> &v) : n(v.size()), b(0), d(1, v) { build(); }\n    S prod(int l, int\
    \ r) const {\n        assert(0 <= l && l <= r && r <=n);\n        if (l == r)\
    \ return M::e();\n        int i = bit_width(unsigned(r - l)) - 1;\n        return\
    \ M::op(d[i][l], d[i][r - (1 << i)]);\n    }\nprivate:\n    int n, b, e;\n   \
    \ vector<vector<S>> d;\n    void build() {\n        b = bit_width(unsigned(n));\n\
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
    };\n#line 5 \"test/tree/centroid_decomposition.test.cpp\"\n\n#line 4 \"src/random/graph.hpp\"\
    \n#include <set>\n#line 3 \"src/random/utility.hpp\"\n#include <concepts>\n#include\
    \ <random>\nusing namespace std;\n\nnamespace rng {\n\ninline random_device seed;\n\
    inline mt19937 eng(seed());\n\ntemplate<typename T>\nvoid set_seed(const T &sd)\
    \ {\n    eng.seed(sd);\n}\n\ntemplate<integral T>\ninline T randint(T lo, T hi)\
    \ {\n    assert(lo <= hi);\n    uniform_int_distribution<T> dist(lo, hi);\n  \
    \  return dist(eng);\n}\n\ntemplate<integral T>\ninline pair<T, T> randpair(T\
    \ lo, T hi, bool strict = false) {\n    assert(lo + strict <= hi);\n    T l =\
    \ randint(lo, hi - strict);\n    T r = randint(l + strict, hi);\n    return make_pair(l,\
    \ r);\n}\n\n} // namespace rng\n#line 3 \"src/misc/even_distribution_array.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T>\nvector<T> even_distribution_array(const\
    \ vector<T> &v) {\n    int n = v.size();\n    long long sum = 0;\n    for (int\
    \ i = 0; i < n; i++) {\n        sum += v[i];\n    }\n    T q = sum / n, r = sum\
    \ % n;\n    vector<T> res(n, q);\n    for (int i = n - r; i < n; i++) res[i]++;\n\
    \    return res;\n}\n#line 7 \"src/random/sequence.hpp\"\nusing namespace std;\n\
    \nnamespace rng {\n\ntemplate<typename T>\nvoid shuffle(vector<T> &v) {\n    std::shuffle(v.begin(),\
    \ v.end(), eng);\n}\n\ntemplate<integral T>\ninline vector<T> random_sequence(int\
    \ n, T lo, T hi) {\n    assert(n >= 0);\n    vector<T> res(n);\n    for (int i\
    \ = 0; i < n; i++) res[i] = randint(lo, hi);\n    return res;\n}\n\ntemplate<integral\
    \ T>\ninline vector<T> random_increasing_sequence(int n, T lo, T hi, bool strict\
    \ = false) {\n    assert(n >= 0);\n    if (n == 0) return {};\n    assert(lo +\
    \ (n - 1) * strict <= hi);\n    vector<T> res = random_sequence(n, lo, hi - (n\
    \ - 1) * strict);\n    sort(res.begin(), res.end());\n    for (int i = 0; i <\
    \ n; i++) res[i] += i * strict;\n    return res;\n}\n\ntemplate<integral T>\n\
    inline vector<T> random_decreasing_sequence(int n, T lo, T hi, bool strict = false)\
    \ {\n    vector<T> res = random_increasing_sequence(n, lo, hi, strict);\n    reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n\ntemplate<integral T>\ninline vector<T> random_permutation(int\
    \ n, T val = 0) {\n    vector<T> res(n);\n    iota(res.begin(), res.end(), val);\n\
    \    shuffle(res);\n    return res;\n}\n\ninline string random_string(int n, char\
    \ a, char z) {\n    assert(a <= z);\n    string s(n, a);\n    for (auto &c : s)\
    \ c = randint((int)a, (int)z);\n    return s;\n}\n\n} // namespace rng\n#line\
    \ 2 \"src/tree/prufer_code.hpp\"\n#include <queue>\n#line 4 \"src/tree/prufer_code.hpp\"\
    \nusing namespace std;\n\nvector<int> prufer_code_compress(const vector<vector<int>>\
    \ &t) {\n    int n = t.size();\n    if (n <= 2) return {};\n    vector<int> deg(n);\n\
    \    priority_queue<int, vector<int>, greater<int>> q;\n    for (int i = 0; i\
    \ < n; i++) {\n        deg[i] = t[i].size();\n        if (deg[i] == 1) {\n   \
    \         q.push(i);\n        }\n    }\n    vector<int> p;\n    p.reserve(n -\
    \ 2);\n    while ((int)p.size() < n - 2) {\n        int u = q.top();\n       \
    \ q.pop();\n        for (int v : t[u]) {\n            if (deg[v] > 0) {\n    \
    \            p.push_back(v);\n                deg[v]--;\n                if (deg[v]\
    \ == 1) q.push(v);\n                break;\n            }\n        }\n       \
    \ deg[u]--;\n    }\n    return p;\n}\n\nvector<vector<int>> prufer_code_expansion(const\
    \ vector<int> &p) {\n    int n = p.size() + 2;\n    vector<int> deg(n, 1);\n \
    \   for (int u : p) deg[u]++;\n    priority_queue<int, vector<int>, greater<int>>\
    \ q;\n    for (int i = 0; i < n; i++) {\n        if (deg[i] == 1) q.push(i);\n\
    \    }\n    vector<vector<int>> t(n);\n    for (int i = 0; i < n - 2; i++) {\n\
    \        int u = p[i];\n        int v = q.top();\n        q.pop();\n        t[u].push_back(v);\n\
    \        t[v].push_back(u);\n        deg[u]--, deg[v]--;\n        if (deg[u] ==\
    \ 1) q.push(u);\n    }\n    for (int i = 0; i < n; i++) {\n        if (deg[i]\
    \ == 1) {\n            for (int j = 0; j < n; j++) {\n                if (j !=\
    \ i && deg[j] == 1) {\n                    t[i].push_back(j);\n              \
    \      t[j].push_back(i);\n                    deg[i]--, deg[j]--;\n         \
    \           break;\n                }\n            }\n            break;\n   \
    \     }\n    }\n    return t;\n}\n#line 9 \"src/random/graph.hpp\"\nusing namespace\
    \ std;\n\nnamespace rng {\n\ninline vector<pair<int, int>> random_star(int n)\
    \ {\n    assert(n >= 0);\n    if (n <= 1) return {};\n    if (n == 2) return {make_pair(0,\
    \ 1)};\n    int r = randint(0, n - 1);\n    vector<pair<int, int>> res;\n    for\
    \ (int i = 0; i < n; i++) {\n        if (r != i) res.push_back(minmax(r, i));\n\
    \    }\n    return res;\n}\n\ninline vector<pair<int, int>> random_path(int n)\
    \ {\n    assert(n >= 0);\n    if (n <= 1) return {};\n    if (n == 2) return {make_pair(0,\
    \ 1)};\n    auto p = random_permutation(n, 0);\n    vector<pair<int, int>> res;\n\
    \    for (int i = 1; i < n; i++) {\n        res.emplace_back(minmax(p[i - 1],\
    \ p[i]));\n    }\n    shuffle(res);\n    return res;\n}\n\ninline vector<pair<int,\
    \ int>> random_binary_tree(int n) {\n    assert(n >= 0);\n    if (n <= 1) return\
    \ {};\n    if (n == 2) return {make_pair(0, 1)};\n    auto p = random_permutation(n,\
    \ 0);\n    vector<pair<int, int>> res;\n    for (int i = 1; i < n; i++) {\n  \
    \      res.emplace_back(minmax(p[(i - 1) / 2], p[i]));\n    }\n    shuffle(res);\n\
    \    return res;\n}\n\ninline vector<pair<int, int>> random_broom(int n) {\n \
    \   assert(n >= 0);\n    if (n <= 1) return {};\n    if (n == 2) return {make_pair(0,\
    \ 1)};\n    auto p = random_permutation(n, 0);\n    int m = randint(1, n);\n \
    \   vector<pair<int, int>> res;\n    for (int i = 1; i < n; i++) {\n        res.emplace_back(minmax(p[min(m,\
    \ i - 1)], p[i]));\n    }\n    shuffle(res);\n    return res;\n}\n\ninline vector<pair<int,\
    \ int>> random_caterpillar(int n) {\n    assert(n >= 0);\n    if (n <= 1) return\
    \ {};\n    if (n == 2) return {make_pair(0, 1)};\n    auto p = random_permutation(n,\
    \ 0);\n    int m = randint(1, n);\n    vector<pair<int, int>> res;\n    for (int\
    \ i = 1; i < n; i++) {\n        if (i < m) res.emplace_back(minmax(p[i - 1], p[i]));\n\
    \        else res.emplace_back(minmax(p[randint(0, m - 1)], p[i]));\n    }\n \
    \   shuffle(res);\n    return res;\n}\n\ninline vector<pair<int, int>> random_tree(int\
    \ n, bool corner = false) {\n    assert(n >= 0);\n    if (n <= 1) return {};\n\
    \    if (n == 2) return {make_pair(0, 1)};\n    if (corner) {\n        int type\
    \ = randint(1, 6);\n        if (type == 1) return random_star(n);\n        if\
    \ (type == 2) return random_path(n);\n        if (type == 3) return random_binary_tree(n);\n\
    \        if (type == 4) return random_broom(n);\n        if (type == 5) return\
    \ random_caterpillar(n);\n    }\n    vector<int> p(n - 2);\n    for (int &e :\
    \ p) e = randint(0, n - 1);\n    auto t = prufer_code_expansion(p);\n    vector<pair<int,\
    \ int>> res;\n    for (int u = 0; u < n; u++) {\n        for (int v : t[u]) {\n\
    \            if (u < v) res.emplace_back(u, v);\n        }\n    }\n    return\
    \ res;\n}\n\ninline vector<pair<int, int>> random_simple_graph(int n, int m) {\n\
    \    assert(n >= 0);\n    assert(m >= 0);\n    assert((long long)m <= (long long)n\
    \ * (n - 1) / 2);\n    if (n <= 3000) {\n        vector<pair<int, int>> edges;\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = i + 1; j < n;\
    \ j++) {\n                edges.emplace_back(i, j);\n            }\n        }\n\
    \        shuffle(edges);\n        return vector<pair<int, int>>(edges.begin(),\
    \ edges.begin() + m);\n    }\n    set<pair<int, int>> edges;\n    while ((int)edges.size()\
    \ < m) {\n        auto [u, v] = randpair(0, n - 1, true);\n        edges.emplace(u,\
    \ v);\n    }\n    return vector<pair<int, int>>(edges.begin(), edges.end());\n\
    }\n\ninline vector<pair<int, int>> random_connected_graph(int n, int m) {\n  \
    \  assert(n >= 0);\n    assert(m >= n - 1);\n    assert((long long)m <= (long\
    \ long)n * (n - 1) / 2);\n    auto t = random_tree(n, true);\n    if (n <= 3000)\
    \ {\n        vector<vector<bool>> used(n, vector<bool>(n, false));\n        for\
    \ (auto [u, v] : t) used[u][v] = true;\n        vector<pair<int, int>> edges;\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = i + 1; j < n;\
    \ j++) {\n                if (!used[i][j]) edges.emplace_back(i, j);\n       \
    \     }\n        }\n        shuffle(edges);\n        m -= n - 1;\n        while\
    \ ((int)edges.size() > m) edges.pop_back();\n        for (auto p : t) edges.push_back(p);\n\
    \        return edges;\n    }\n    set<pair<int, int>> edges(t.begin(), t.end());\n\
    \    while ((int)edges.size() < m) {\n        auto [u, v] = randpair(0, n - 1,\
    \ true);\n        edges.emplace(u, v);\n    }\n    return vector<pair<int, int>>(edges.begin(),\
    \ edges.end());\n}\n\n} // namespace rng\n#line 8 \"test/tree/centroid_decomposition.test.cpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n  \
    \  {\n        int A, B;\n        cin >> A >> B;\n        cout << A + B << '\\\
    n';\n    }\n    for (int t = 0; t < 20; t++) {\n        int N = rng::randint(1,\
    \ (int)2000);\n        centroid_decomposition CD(N);\n        static_tree T(N);\n\
    \        for (auto [u, v] : rng::random_tree(N, true)) {\n            CD.add_edge(u,\
    \ v);\n            T.add_edge(u, v);\n        }\n        auto P = CD.parent_vector();\n\
    \        int r = min_element(P.begin(), P.end()) - P.begin();\n        static_tree\
    \ R(N, r);\n        for (int i = 0; i < N; i++) {\n            if (P[i] != -1)\
    \ R.add_edge(i, P[i]);\n        }\n        vector<int> sub(N, 1);\n        auto\
    \ dfs = [&] (auto dfs, int u) -> int {\n            for (int v : R[u]) if (v !=\
    \ P[u]) sub[u] += dfs(dfs, v);\n            return sub[u];\n        };\n     \
    \   dfs(dfs, r);\n        for (int x = 0; x < N; x++) {\n            for (int\
    \ y = x + 1; y < N; y++) {\n                int z = R.lca(x, y);\n           \
    \     assert(T.dist(x, y) == T.dist(x, z) + T.dist(z, y));\n            }\n  \
    \      }\n        for (int i = 0; i < N; i++) {\n            if (P[i] == -1) continue;\n\
    \            assert(2 * sub[i] <= sub[P[i]]);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../src/tree/centroid_decomposition.hpp\"\n#include \"../../src/tree/static_tree.hpp\"\
    \n\n#include <iostream>\n#include \"../../src/random/graph.hpp\"\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    {\n        int\
    \ A, B;\n        cin >> A >> B;\n        cout << A + B << '\\n';\n    }\n    for\
    \ (int t = 0; t < 20; t++) {\n        int N = rng::randint(1, (int)2000);\n  \
    \      centroid_decomposition CD(N);\n        static_tree T(N);\n        for (auto\
    \ [u, v] : rng::random_tree(N, true)) {\n            CD.add_edge(u, v);\n    \
    \        T.add_edge(u, v);\n        }\n        auto P = CD.parent_vector();\n\
    \        int r = min_element(P.begin(), P.end()) - P.begin();\n        static_tree\
    \ R(N, r);\n        for (int i = 0; i < N; i++) {\n            if (P[i] != -1)\
    \ R.add_edge(i, P[i]);\n        }\n        vector<int> sub(N, 1);\n        auto\
    \ dfs = [&] (auto dfs, int u) -> int {\n            for (int v : R[u]) if (v !=\
    \ P[u]) sub[u] += dfs(dfs, v);\n            return sub[u];\n        };\n     \
    \   dfs(dfs, r);\n        for (int x = 0; x < N; x++) {\n            for (int\
    \ y = x + 1; y < N; y++) {\n                int z = R.lca(x, y);\n           \
    \     assert(T.dist(x, y) == T.dist(x, z) + T.dist(z, y));\n            }\n  \
    \      }\n        for (int i = 0; i < N; i++) {\n            if (P[i] == -1) continue;\n\
    \            assert(2 * sub[i] <= sub[P[i]]);\n        }\n    }\n}"
  dependsOn:
  - src/tree/centroid_decomposition.hpp
  - src/tree/static_tree.hpp
  - src/data_structure/segtree/static_rmq.hpp
  - src/data_structure/sparse_table/sparse_table.hpp
  - src/random/graph.hpp
  - src/random/utility.hpp
  - src/random/sequence.hpp
  - src/misc/even_distribution_array.hpp
  - src/tree/prufer_code.hpp
  isVerificationFile: true
  path: test/tree/centroid_decomposition.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:16:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/tree/centroid_decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/tree/centroid_decomposition.test.cpp
- /verify/test/tree/centroid_decomposition.test.cpp.html
title: test/tree/centroid_decomposition.test.cpp
---
