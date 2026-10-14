---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data_structure/segtree/segtree.hpp
    title: src/data_structure/segtree/segtree.hpp
  - icon: ':question:'
    path: src/monoid/add.hpp
    title: src/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
  bundledCode: "#line 1 \"test/monoid/add.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B\"\
    \n\n#line 2 \"src/data_structure/segtree/segtree.hpp\"\n#include <vector>\n#include\
    \ <cassert>\nusing namespace std;\n\ntemplate <typename Monoid>\nstruct segtree\
    \ {\n    using M = Monoid;\n    using S = typename M::S;\n    segtree() : segtree(0)\
    \ {}\n    segtree(int _n) : segtree(vector<S>(_n, M::e())) {}\n    segtree(const\
    \ vector<S> &v) : n(v.size()) {\n        log = 1;\n        while ((1 << log) <\
    \ n) log++;\n        sz = 1 << log;\n        d = vector<S>(2 * sz, M::e());\n\
    \        for (int i = 0; i < n; i++) d[i + sz] = v[i];\n        for (int i = sz\
    \ - 1; i >= 1; i--) update(i);\n    }\n    void set(int p, const S &x) {\n   \
    \     assert(0 <= p && p < n);\n        p += sz;\n        d[p] = x;\n        for\
    \ (int i = 1; i <= log; i++) update(p >> i);\n    }\n    void apply(int p, const\
    \ S &x) {\n        assert(0 <= p && p < n);\n        set(p, M::op(x, d[p + sz]));\n\
    \    }\n    S get(int p) const {\n        assert(0 <= p && p < n);\n        return\
    \ d[p + sz];\n    }\n    S prod(int l, int r) const {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        l += sz;\n        r += sz;\n        S pl = M::e(),\
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
    \ {\n        d[p] = M::op(d[2 * p], d[2 * p + 1]);\n    }\n};\n#line 2 \"src/monoid/add.hpp\"\
    \nusing namespace std;\n\ntemplate <typename T>\nstruct add_monoid {\n    using\
    \ S = T;\n    static S op(const S &a, const S &b) {\n        return a + b;\n \
    \   }\n    static S e() { return 0; }\n    static S inv(const S &x) {\n      \
    \  return -x;\n    }\n    static S pow(const S &x, long long k) {\n        return\
    \ x * k;\n    }\n};\n#line 5 \"test/monoid/add.test.cpp\"\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    segtree<add_monoid<int>> seg(N);\n    while (Q--)\
    \ {\n        int t;\n        cin >> t;\n        if (t == 0) {\n            int\
    \ p, x;\n            cin >> p >> x;\n            p--;\n            seg.set(p,\
    \ seg.get(p) + x);\n        } else {\n            int l, r;\n            cin >>\
    \ l >> r;\n            l--;\n            cout << seg.prod(l, r) << '\\n';\n  \
    \      }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B\"\
    \n\n#include \"../../src/data_structure/segtree/segtree.hpp\"\n#include \"../../src/monoid/add.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    segtree<add_monoid<int>>\
    \ seg(N);\n    while (Q--) {\n        int t;\n        cin >> t;\n        if (t\
    \ == 0) {\n            int p, x;\n            cin >> p >> x;\n            p--;\n\
    \            seg.set(p, seg.get(p) + x);\n        } else {\n            int l,\
    \ r;\n            cin >> l >> r;\n            l--;\n            cout << seg.prod(l,\
    \ r) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/data_structure/segtree/segtree.hpp
  - src/monoid/add.hpp
  isVerificationFile: true
  path: test/monoid/add.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:06:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/monoid/add.test.cpp
layout: document
redirect_from:
- /verify/test/monoid/add.test.cpp
- /verify/test/monoid/add.test.cpp.html
title: test/monoid/add.test.cpp
---
