---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/segtree/segtree.hpp
    title: src/data_structure/segtree/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: src/monoid/add.hpp
    title: src/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: src/tree/range_contour_aggregator.hpp
    title: src/tree/range_contour_aggregator.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree
    links:
    - https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree
  bundledCode: "#line 1 \"test/tree/range_contour_aggregator.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree\"\n\n\
    #line 2 \"src/tree/range_contour_aggregator.hpp\"\n#include <array>\n#include\
    \ <cassert>\n#include <queue>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ SegTree>\nstruct range_contour_aggregator {\n    using M = typename SegTree::M;\n\
    \    using S = typename M::S;\n    range_contour_aggregator() = default;\n   \
    \ range_contour_aggregator(int _n) : n(_n), e(0), built(false), g(_n) {\n    \
    \    par = vector<int>(n, -1);\n        seen = vector<bool>(n, false);\n     \
    \   d = vector<S>(n, M::e());\n        dats = vector<vector<tuple<int, int, int>>>(n);\n\
    \        seps = vector<array<vector<int>, 2>>(n);\n        segs = vector<array<SegTree,\
    \ 2>>(n);\n        par.reserve(2 * n);\n        if (n == 1) build();\n    }\n\
    \    void add_edge(int u, int v) {\n        assert(0 <= u && u < n);\n       \
    \ assert(0 <= v && v < n);\n        assert(!built);\n        g[u].emplace_back(v);\n\
    \        g[v].emplace_back(u);\n        if (++e == n - 1) build();\n    }\n  \
    \  void set(int u, const S &x) {\n        assert(0 <= u && u < n);\n        assert(built);\n\
    \        d[u] = x;\n        int v = par[u];\n        for (const auto &[i, c, _]\
    \ : dats[u]) {\n            segs[v][c].set(i, x);\n            v = par[v];\n \
    \       }\n    }\n    S get(int u) const {\n        assert(0 <= u && u < n);\n\
    \        assert(built);\n        return d[u];\n    }\n    S prod(int u, int l,\
    \ int r) const {\n        assert(0 <= u && u < n);\n        assert(0 <= l && l\
    \ <= r && r <= n);\n        S res = (l == 0 && 0 < r ? d[u] : M::e());\n     \
    \   res = M::op(res, inner_prod(u, 0, l - 1, r - 1));\n        res = M::op(res,\
    \ inner_prod(u, 1, l - 1, r - 1));\n        int v = par[u];\n        for (const\
    \ auto &[_, c, dist] : dats[u]) {\n            int tl = l - dist - 2, tr = r -\
    \ dist - 2;\n            if (v < n && tl <= -1 && -1 < tr) {\n               \
    \ res = M::op(res, d[v]);\n            }\n            res = M::op(res, inner_prod(v,\
    \ c ^ 1, tl, tr));\n            v = par[v];\n        }\n        return res;\n\
    \    }\nprivate:\n    int n, e;\n    bool built;\n    vector<vector<int>> g;\n\
    \    vector<int> par;\n    vector<bool> seen;\n    vector<S> d;\n    vector<vector<tuple<int,\
    \ int, int>>> dats;\n    vector<array<vector<int>, 2>> seps;\n    vector<array<SegTree,\
    \ 2>> segs;\n    void make_node(int p, int c, const vector<int> &roots, int sz)\
    \ {\n        vector<S> new_d(sz, M::e());\n        auto &sep = seps[p][c];\n \
    \       auto &seg = segs[p][c];\n        sep.push_back(0);\n        queue<tuple<int,\
    \ int, int>> q;\n        for (int r : roots) {\n            q.emplace(r, -1, 0);\n\
    \        }\n        int dist = 0, cnt = 0;\n        while (q.size()) {\n     \
    \       auto [u, pu, du] = q.front();\n            q.pop();\n            if (du\
    \ == dist + 1) {\n                sep.push_back(cnt);\n                dist =\
    \ du;\n            }\n            dats[u].emplace_back(cnt, c, du);\n        \
    \    new_d[cnt++] = d[u];\n            for (int v : g[u]) {\n                if\
    \ (v != pu && !seen[v]) {\n                    q.emplace(v, u, du + 1);\n    \
    \            }\n            }\n        }\n        sep.push_back(cnt);\n      \
    \  seg = SegTree(new_d);\n    }\n    vector<int>&& merge(vector<int> &&a, vector<int>\
    \ &&b) {\n        if (a.size() > b.size()) swap(a, b);\n        for (int e : a)\
    \ {\n            b.push_back(e);\n        }\n        return move(b);\n    }\n\
    \    void build() {\n        vector<int> sub(n, 0), ctr(n, -1);\n        vector<vector<int>>\
    \ children(n);\n        sub.reserve(2 * n);\n        ctr.reserve(2 * n);\n   \
    \     children.reserve(2 * n);\n        auto dfs = [&](const auto &dfs, int root,\
    \ int sz) -> int {\n            int c = -1;\n            auto centroid = [&](auto\
    \ centroid, int u, int p) -> void {\n                sub[u] = 1;\n           \
    \     for (int v : g[u]) {\n                    if (v != p && !seen[v]) {\n  \
    \                      centroid(centroid, v, u);\n                        if (v\
    \ == c) {\n                            sub[u] = sz - sub[c];\n               \
    \             break;\n                        }\n                        sub[u]\
    \ += sub[v];\n                    }\n                }\n                if (c\
    \ < 0 && 2 * sub[u] > sz) c = u;\n            };\n            centroid(centroid,\
    \ root, -1);\n            seen[c] = true;\n            for (int v : g[c]) {\n\
    \                if (!seen[v]) {\n                    int s = sub[v];\n      \
    \              ctr[v] = dfs(dfs, v, s);\n                    sub[v] = s;\n   \
    \             }\n            }\n            priority_queue<pair<int, int>, vector<pair<int,\
    \ int>>, greater<pair<int, int>>> q;\n            for (int v : g[c]) {\n     \
    \           if (!seen[v]) {\n                    children[v] = {v};\n        \
    \            q.emplace(sub[v], v);\n                }\n            }\n       \
    \     while (q.size() >= 2) {\n                int u = q.top().second;\n     \
    \           q.pop();\n                int v = q.top().second;\n              \
    \  q.pop();\n                if (q.empty()) {\n                    par[ctr[u]]\
    \ = par[ctr[v]] = c;\n                    make_node(c, 0, children[u], sub[u]);\n\
    \                    make_node(c, 1, children[v], sub[v]);\n                }\
    \ else {\n                    int w = sub.size();\n                    sub.push_back(sub[u]\
    \ + sub[v]);\n                    ctr.push_back(w);\n                    par.push_back(-1);\n\
    \                    par[ctr[u]] = par[ctr[v]] = w;\n                    seps.emplace_back();\n\
    \                    segs.emplace_back();\n                    make_node(w, 0,\
    \ children[u], sub[u]);\n                    make_node(w, 1, children[v], sub[v]);\n\
    \                    children.push_back(merge(move(children[u]), move(children[v])));\n\
    \                    children[u].clear();\n                    children[u].shrink_to_fit();\n\
    \                    children[v].clear();\n                    children[v].shrink_to_fit();\n\
    \                    q.emplace(sub[w], w);\n                }\n            }\n\
    \            if (q.size()) {\n                int u = q.top().second;\n      \
    \          q.pop();\n                par[ctr[u]] = c;\n                make_node(c,\
    \ 0, children[u], sub[u]);\n            }\n            seen[c] = false;\n    \
    \        return c;\n        };\n        dfs(dfs, 0, n);\n        built = true;\n\
    \    }\n    S inner_prod(int u, int c, int l, int r) const {\n        l = max(l,\
    \ 0);\n        r = min(r, (int)seps[u][c].size() - 1);\n        return l < r ?\
    \ segs[u][c].prod(seps[u][c][l], seps[u][c][r]) : M::e();\n    }\n};\n#line 4\
    \ \"src/data_structure/segtree/segtree.hpp\"\nusing namespace std;\n\ntemplate\
    \ <typename Monoid>\nstruct segtree {\n    using M = Monoid;\n    using S = typename\
    \ M::S;\n    segtree() : segtree(0) {}\n    segtree(int _n) : segtree(vector<S>(_n,\
    \ M::e())) {}\n    segtree(const vector<S> &v) : n(v.size()) {\n        log =\
    \ 1;\n        while ((1 << log) < n) log++;\n        sz = 1 << log;\n        d\
    \ = vector<S>(2 * sz, M::e());\n        for (int i = 0; i < n; i++) d[i + sz]\
    \ = v[i];\n        for (int i = sz - 1; i >= 1; i--) update(i);\n    }\n    void\
    \ set(int p, const S &x) {\n        assert(0 <= p && p < n);\n        p += sz;\n\
    \        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n \
    \   }\n    void apply(int p, const S &x) {\n        assert(0 <= p && p < n);\n\
    \        set(p, M::op(x, d[p + sz]));\n    }\n    S get(int p) const {\n     \
    \   assert(0 <= p && p < n);\n        return d[p + sz];\n    }\n    S prod(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n        l +=\
    \ sz;\n        r += sz;\n        S pl = M::e(), pr = M::e();\n        while (l\
    \ < r) {\n            if (l & 1) pl = M::op(pl, d[l++]);\n            if (r &\
    \ 1) pr = M::op(d[--r], pr);\n            l >>= 1;\n            r >>= 1;\n   \
    \     }\n        return M::op(pl, pr);\n    }\n    S all_prod() const { return\
    \ d[1]; }\n    template<typename C>\n    int max_right(int l, const C &check)\
    \ const {\n        assert(0 <= l && l <= n);\n        assert(check(M::e()));\n\
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
    \ {\n        d[p] = M::op(d[2 * p], d[2 * p + 1]);\n    }\n};\n#line 2 \"src/monoid/add.hpp\"\
    \nusing namespace std;\n\ntemplate <typename T>\nstruct add_monoid {\n    using\
    \ S = T;\n    static S op(const S &a, const S &b) {\n        return a + b;\n \
    \   }\n    static S e() { return 0; }\n    static S inv(const S &x) {\n      \
    \  return -x;\n    }\n    static S pow(const S &x, long long k) {\n        return\
    \ x * k;\n    }\n};\n#line 6 \"test/tree/range_contour_aggregator.test.cpp\"\n\
    \n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    vector<int> A(N);\n    for (auto &e :\
    \ A) cin >> e;\n    range_contour_aggregator<segtree<add_monoid<long long>>> RCA(N);\n\
    \    for (int i = 1, u, v; i < N; i++) {\n        cin >> u >> v;\n        RCA.add_edge(u,\
    \ v);\n    }\n    for (int i = 0; i < N; i++) {\n        RCA.set(i, A[i]);\n \
    \   }\n    while (Q--) {\n        int t;\n        cin >> t;\n        if (t ==\
    \ 0) {\n            int p, x;\n            cin >> p >> x;\n            RCA.set(p,\
    \ RCA.get(p) + x);\n        } else {\n            int p, l, r;\n            cin\
    \ >> p >> l >> r;\n            cout << RCA.prod(p, l, r) << '\\n';\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree\"\
    \n\n#include \"../../src/tree/range_contour_aggregator.hpp\"\n#include \"../../src/data_structure/segtree/segtree.hpp\"\
    \n#include \"../../src/monoid/add.hpp\"\n\n#include <iostream>\n\nint main() {\n\
    \    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N, Q;\n    cin\
    \ >> N >> Q;\n    vector<int> A(N);\n    for (auto &e : A) cin >> e;\n    range_contour_aggregator<segtree<add_monoid<long\
    \ long>>> RCA(N);\n    for (int i = 1, u, v; i < N; i++) {\n        cin >> u >>\
    \ v;\n        RCA.add_edge(u, v);\n    }\n    for (int i = 0; i < N; i++) {\n\
    \        RCA.set(i, A[i]);\n    }\n    while (Q--) {\n        int t;\n       \
    \ cin >> t;\n        if (t == 0) {\n            int p, x;\n            cin >>\
    \ p >> x;\n            RCA.set(p, RCA.get(p) + x);\n        } else {\n       \
    \     int p, l, r;\n            cin >> p >> l >> r;\n            cout << RCA.prod(p,\
    \ l, r) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/tree/range_contour_aggregator.hpp
  - src/data_structure/segtree/segtree.hpp
  - src/monoid/add.hpp
  isVerificationFile: true
  path: test/tree/range_contour_aggregator.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:06:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/range_contour_aggregator.test.cpp
layout: document
redirect_from:
- /verify/test/tree/range_contour_aggregator.test.cpp
- /verify/test/tree/range_contour_aggregator.test.cpp.html
title: test/tree/range_contour_aggregator.test.cpp
---
