---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/segtree/segtree.hpp
    title: src/data_structure/segtree/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dp/triangular_transition.hpp\"\n#include <algorithm>\n\
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
    \ {\n        d[p] = M::op(d[2 * p], d[2 * p + 1]);\n    }\n};\n#line 6 \"src/dp/triangular_transition.hpp\"\
    \n\ntemplate<typename Monoid, typename T = int>\nstruct triangular_transition\
    \ {\n    using S = typename Monoid::S;\n    triangular_transition(int _n = 0)\
    \ : n(_n) {\n        ts.reserve(n);\n        xs.reserve(n);\n    }\n    void add_point(T\
    \ t, T x) {\n        ts.emplace_back(t);\n        xs.emplace_back(x);\n    }\n\
    \    template<typename L>\n    vector<S> run(const L &f, bool variable_start =\
    \ false) {\n        if (variable_start) {\n            T x_max = 0;\n        \
    \    for (auto x : xs) x_max = max(x_max, abs(x));\n            for (auto &t :\
    \ ts) t += x_max;\n        }\n        n = ts.size();\n        vector<T> us(n),\
    \ vs(n);\n        vector<int> ord(n);\n        for (int i = 0; i < n; i++) {\n\
    \            us[i] = ts[i] - xs[i];\n            vs[i] = ts[i] + xs[i]; \n   \
    \         ord[i] = i;\n        }\n        sort(ord.begin(), ord.end(), [&](int\
    \ i, int j) {\n            return us[i] == us[j] ? vs[i] < vs[j] : us[i] < us[j];\n\
    \        });\n        vector<T> b = vs;\n        sort(b.begin(), b.end());\n \
    \       b.erase(unique(b.begin(), b.end()), b.end());\n        vector<S> dp(n,\
    \ Monoid::e());\n        segtree<Monoid> seg(b.size() + 1);\n        seg.set(0,\
    \ f(-1, Monoid::e()));\n        for (int i : ord) {\n            T u = us[i],\
    \ v = vs[i];\n            if (u < 0 || v < 0) continue;\n            int j = lower_bound(b.begin(),\
    \ b.end(), v) - b.begin();\n            dp[i] = f(i, seg.prod(0, j + 1));\n  \
    \          seg.set(j, dp[i]);\n        }\n        return dp;\n    }\nprivate:\n\
    \    int n;\n    vector<T> ts, xs;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    #include \"../data_structure/segtree/segtree.hpp\"\n\ntemplate<typename Monoid,\
    \ typename T = int>\nstruct triangular_transition {\n    using S = typename Monoid::S;\n\
    \    triangular_transition(int _n = 0) : n(_n) {\n        ts.reserve(n);\n   \
    \     xs.reserve(n);\n    }\n    void add_point(T t, T x) {\n        ts.emplace_back(t);\n\
    \        xs.emplace_back(x);\n    }\n    template<typename L>\n    vector<S> run(const\
    \ L &f, bool variable_start = false) {\n        if (variable_start) {\n      \
    \      T x_max = 0;\n            for (auto x : xs) x_max = max(x_max, abs(x));\n\
    \            for (auto &t : ts) t += x_max;\n        }\n        n = ts.size();\n\
    \        vector<T> us(n), vs(n);\n        vector<int> ord(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            us[i] = ts[i] - xs[i];\n            vs[i]\
    \ = ts[i] + xs[i]; \n            ord[i] = i;\n        }\n        sort(ord.begin(),\
    \ ord.end(), [&](int i, int j) {\n            return us[i] == us[j] ? vs[i] <\
    \ vs[j] : us[i] < us[j];\n        });\n        vector<T> b = vs;\n        sort(b.begin(),\
    \ b.end());\n        b.erase(unique(b.begin(), b.end()), b.end());\n        vector<S>\
    \ dp(n, Monoid::e());\n        segtree<Monoid> seg(b.size() + 1);\n        seg.set(0,\
    \ f(-1, Monoid::e()));\n        for (int i : ord) {\n            T u = us[i],\
    \ v = vs[i];\n            if (u < 0 || v < 0) continue;\n            int j = lower_bound(b.begin(),\
    \ b.end(), v) - b.begin();\n            dp[i] = f(i, seg.prod(0, j + 1));\n  \
    \          seg.set(j, dp[i]);\n        }\n        return dp;\n    }\nprivate:\n\
    \    int n;\n    vector<T> ts, xs;\n};"
  dependsOn:
  - src/data_structure/segtree/segtree.hpp
  isVerificationFile: false
  path: src/dp/triangular_transition.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/dp/triangular_transition.hpp
layout: document
redirect_from:
- /library/src/dp/triangular_transition.hpp
- /library/src/dp/triangular_transition.hpp.html
title: src/dp/triangular_transition.hpp
---
