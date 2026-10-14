---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree/hld.commutative.test.cpp
    title: test/tree/hld.commutative.test.cpp
  - icon: ':x:'
    path: test/tree/hld.test.cpp
    title: test/tree/hld.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/hld.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n\ntemplate<typename SegTree, bool edge,\
    \ bool commutative>\nstruct heavy_light_decomposition {\n    using M = typename\
    \ SegTree::M;\n    using S = typename M::S;\n    heavy_light_decomposition() =\
    \ default;\n    heavy_light_decomposition(int _n, int _r = 0) : n(_n), r(_r),\
    \ id(0), built(false) {\n        edges.reserve(n - 1);\n        if (n <= 1) build();\n\
    \    }\n    void add_edge(int u, int v, const S &w = M::e()) {\n        assert(!built);\n\
    \        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        assert(u\
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
    \ res;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename SegTree, bool edge, bool commutative>\n\
    struct heavy_light_decomposition {\n    using M = typename SegTree::M;\n    using\
    \ S = typename M::S;\n    heavy_light_decomposition() = default;\n    heavy_light_decomposition(int\
    \ _n, int _r = 0) : n(_n), r(_r), id(0), built(false) {\n        edges.reserve(n\
    \ - 1);\n        if (n <= 1) build();\n    }\n    void add_edge(int u, int v,\
    \ const S &w = M::e()) {\n        assert(!built);\n        assert(0 <= u && u\
    \ < n);\n        assert(0 <= v && v < n);\n        assert(u != v);\n        edges.emplace_back(u,\
    \ v, w);\n        if (ssize(edges) + 1 == n) build();\n    }\n    int lca(int\
    \ u, int v) {\n        assert(built);\n        assert(0 <= u && u < n);\n    \
    \    assert(0 <= v && v < n);\n        while (true) {\n            if (in[u] >\
    \ in[v]) swap(u, v);\n            if (head[u] == head[v]) return u;\n        \
    \    v = par[head[v]];\n        }\n        return -1;\n    }\n    void set(int\
    \ u, const S &w) {\n        assert(built);\n        assert(0 <= u && u < n);\n\
    \        seg.set(idx(u), w);\n    }\n    void set(int u, int v, const S &w) {\n\
    \        assert(built);\n        assert(0 <= u && u < n);\n        assert(0 <=\
    \ v && v < n);\n        assert(u != v);\n        seg.set(idx(u, v), w);\n    }\n\
    \    template<typename F>\n    void apply(int u, int v, const F &f) {\n      \
    \  assert(built);\n        assert(0 <= u && u < n);\n        assert(0 <= v &&\
    \ v < n);\n        for (auto [l, r] : path_decompose(u, v)) {\n            if\
    \ (l > r) swap(l, r);\n            seg.apply(l, r, f);\n        }\n    }\n   \
    \ template<typename F>\n    void subtree_apply(int u, const F &f) {\n        assert(built);\n\
    \        assert(0 <= u && u < n);\n        seg.apply(in[u] + edge, out[u], f);\n\
    \    }\n    S get(int u) {\n        assert(built);\n        assert(0 <= u && u\
    \ < n);\n        return seg.get(idx(u));\n    }\n    S get(int u, int v) {\n \
    \       assert(built);\n        assert(0 <= u && u < n);\n        assert(0 <=\
    \ v && v < n);\n        assert(u != v);\n        return seg.get(idx(u, v));\n\
    \    }\n    S prod(int u, int v) {\n        assert(built);\n        assert(0 <=\
    \ u && u < n);\n        assert(0 <= v && v < n);\n        S p = M::e();\n    \
    \    for (auto [l, r] : path_decompose(u, v)) {\n            p = M::op(p, inner_prod(l,\
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
    \ res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/hld.hpp
  requiredBy: []
  timestamp: '2025-06-26 18:48:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree/hld.test.cpp
  - test/tree/hld.commutative.test.cpp
documentation_of: src/tree/hld.hpp
layout: document
redirect_from:
- /library/src/tree/hld.hpp
- /library/src/tree/hld.hpp.html
title: src/tree/hld.hpp
---
