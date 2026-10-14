---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://noimi.hatenablog.com/entry/2021/05/02/195143?_ga=2.186800042.36757101.1619952706-2024379568.1619952706
  bundledCode: "#line 2 \"src/data_structure/set/interval_map.hpp\"\n#include <cassert>\n\
    #include <numeric>\n#include <iostream>\n#include <set>\n#include <vector>\nusing\
    \ namespace std;\n\n// https://noimi.hatenablog.com/entry/2021/05/02/195143?_ga=2.186800042.36757101.1619952706-2024379568.1619952706\n\
    \ntemplate<typename T, typename S>\nstruct interval_map {\n    interval_map(const\
    \ S &_e = S()) : e(_e) {\n        s.emplace(node(-inf, -inf, e));\n        s.emplace(node(inf,\
    \ inf, e));\n    }\n    // for i in [l, r): a[i] <- x\n    // when s.insert(node(l,\
    \ r, x)), call add(l, r, x)\n    // when s.erase(node(l, r, x)), call del(l, r,\
    \ x)\n    template<typename A, typename D>\n    void update(T l, T r, const S\
    \ &x, const A &add, const D &del) {\n        auto it = s.lower_bound(node(l, 0,\
    \ x));\n        while (it != s.end() && it->l <= r) {\n            if (it->l ==\
    \ r) {\n                if (it->x == x) {\n                    del(r, it->r, x);\n\
    \                    r = it->r;\n                    it = s.erase(it);\n     \
    \           }\n                break;\n            }\n            if (it->r <=\
    \ r) {\n                del(it->l, it->r, it->x);\n                it = s.erase(it);\n\
    \            } else {\n                if (it->x == x) {\n                   \
    \ r = it->r;\n                    del(it->l, it->r, it->x);\n                \
    \    it = s.erase(it);\n                } else {\n                    del(it->l,\
    \ r, it->x);\n                    auto a = *it;\n                    it = s.erase(it);\n\
    \                    it = s.emplace_hint(it, r, a.r, a.x);\n                }\n\
    \            }\n        }\n        if (it != s.begin()) {\n            it = prev(it);\n\
    \            if (it->r == l) {\n                if (it->x == x) {\n          \
    \          del(it->l, it->r, it->x);\n                    l = it->l;\n       \
    \             it = s.erase(it);\n                }\n            } else if (l <\
    \ it->r) {\n                if (it->x == x) {\n                    del(it->l,\
    \ it->r, it->x);\n                    l = min(l, it->l);\n                   \
    \ r = max(r, it->r);\n                    it = s.erase(it);\n                }\
    \ else {\n                    if (r < it->r) {\n                        it = s.emplace_hint(next(it),\
    \ r, it->r, it->x);\n                        it = prev(it);\n                \
    \    }\n                    del(l, min(r, it->r), it->x);\n                  \
    \  auto a = *it;\n                    it = s.erase(it);\n                    it\
    \ = s.emplace_hint(it, a.l, l, a.x);\n                }\n            }\n     \
    \       if (it != s.end()) it = next(it);\n            add(l, r, x);\n       \
    \     s.emplace_hint(it, l, r, x);\n        }\n    }\n    void update(T l, T r,\
    \ const S &x) {\n        update(l, r, x, [] (T, T, S) {}, [] (T, T, S) {});\n\
    \    }\n    template<typename A, typename D>\n    void update(T k, const S &x,\
    \ const A &add, const D &del) {\n        update(k, k + 1, x, add, del);\n    }\n\
    \    void update(T k, const S &x) {\n        update(k, k + 1, x);\n    }\n   \
    \ // return (left, right, val) s.t. left <= k < right\n    tuple<T, T, S> get(T\
    \ k) const {\n        auto it = key(k);\n        return it->l <= k && k < it->r\
    \ ? make_tuple(it->l, it->r, it->x) : make_tuple(k, k + 1, e);\n    }\n    //\
    \ val at k\n    S operator[](T k) const {\n        return key(k)->x;\n    }\n\
    \    // return (left, right, val) s.t. r = min(k < r)\n    tuple<T, T, S> mex(T\
    \ k) const {\n        auto it = key(k);\n        return make_tuple(it->l, it->r,\
    \ it->x);\n    }\n    vector<tuple<T, T, S>> intervals() const {\n        vector<tuple<T,\
    \ T, S>> res;\n        res.reserve(s.size());\n        for (auto [l, r, x] : s)\
    \ {\n            if (abs(l) != inf && abs(r) != inf) res.emplace_back(l, r, x);\n\
    \        }\n        return res;\n    }\n    void debug() const {\n        for\
    \ (auto [l, r, x] : intervals()) {\n            cout << '(' << l << ',' << r <<\
    \ ',' << x << ')';\n        }\n        cout << endl;\n    }\nprivate:\n    static\
    \ constexpr T inf = numeric_limits<T>::max();\n    struct node {\n        T l,\
    \ r;\n        S x;\n        node(S e) : node(-inf, -inf, e) {}\n        node(T\
    \ _l, T _r, const S &_x) : l(_l), r(_r), x(_x) {}\n        constexpr bool operator<(const\
    \ node &a) const {\n            return l == a.l ? r < a.r : l < a.l;\n       \
    \ }\n    };\n    const S e;\n    set<node> s;\n    typename set<node>::iterator\
    \ key(T k) const {\n        return prev(s.upper_bound(node(k, inf, e)));\n   \
    \ }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <numeric>\n#include <iostream>\n\
    #include <set>\n#include <vector>\nusing namespace std;\n\n// https://noimi.hatenablog.com/entry/2021/05/02/195143?_ga=2.186800042.36757101.1619952706-2024379568.1619952706\n\
    \ntemplate<typename T, typename S>\nstruct interval_map {\n    interval_map(const\
    \ S &_e = S()) : e(_e) {\n        s.emplace(node(-inf, -inf, e));\n        s.emplace(node(inf,\
    \ inf, e));\n    }\n    // for i in [l, r): a[i] <- x\n    // when s.insert(node(l,\
    \ r, x)), call add(l, r, x)\n    // when s.erase(node(l, r, x)), call del(l, r,\
    \ x)\n    template<typename A, typename D>\n    void update(T l, T r, const S\
    \ &x, const A &add, const D &del) {\n        auto it = s.lower_bound(node(l, 0,\
    \ x));\n        while (it != s.end() && it->l <= r) {\n            if (it->l ==\
    \ r) {\n                if (it->x == x) {\n                    del(r, it->r, x);\n\
    \                    r = it->r;\n                    it = s.erase(it);\n     \
    \           }\n                break;\n            }\n            if (it->r <=\
    \ r) {\n                del(it->l, it->r, it->x);\n                it = s.erase(it);\n\
    \            } else {\n                if (it->x == x) {\n                   \
    \ r = it->r;\n                    del(it->l, it->r, it->x);\n                \
    \    it = s.erase(it);\n                } else {\n                    del(it->l,\
    \ r, it->x);\n                    auto a = *it;\n                    it = s.erase(it);\n\
    \                    it = s.emplace_hint(it, r, a.r, a.x);\n                }\n\
    \            }\n        }\n        if (it != s.begin()) {\n            it = prev(it);\n\
    \            if (it->r == l) {\n                if (it->x == x) {\n          \
    \          del(it->l, it->r, it->x);\n                    l = it->l;\n       \
    \             it = s.erase(it);\n                }\n            } else if (l <\
    \ it->r) {\n                if (it->x == x) {\n                    del(it->l,\
    \ it->r, it->x);\n                    l = min(l, it->l);\n                   \
    \ r = max(r, it->r);\n                    it = s.erase(it);\n                }\
    \ else {\n                    if (r < it->r) {\n                        it = s.emplace_hint(next(it),\
    \ r, it->r, it->x);\n                        it = prev(it);\n                \
    \    }\n                    del(l, min(r, it->r), it->x);\n                  \
    \  auto a = *it;\n                    it = s.erase(it);\n                    it\
    \ = s.emplace_hint(it, a.l, l, a.x);\n                }\n            }\n     \
    \       if (it != s.end()) it = next(it);\n            add(l, r, x);\n       \
    \     s.emplace_hint(it, l, r, x);\n        }\n    }\n    void update(T l, T r,\
    \ const S &x) {\n        update(l, r, x, [] (T, T, S) {}, [] (T, T, S) {});\n\
    \    }\n    template<typename A, typename D>\n    void update(T k, const S &x,\
    \ const A &add, const D &del) {\n        update(k, k + 1, x, add, del);\n    }\n\
    \    void update(T k, const S &x) {\n        update(k, k + 1, x);\n    }\n   \
    \ // return (left, right, val) s.t. left <= k < right\n    tuple<T, T, S> get(T\
    \ k) const {\n        auto it = key(k);\n        return it->l <= k && k < it->r\
    \ ? make_tuple(it->l, it->r, it->x) : make_tuple(k, k + 1, e);\n    }\n    //\
    \ val at k\n    S operator[](T k) const {\n        return key(k)->x;\n    }\n\
    \    // return (left, right, val) s.t. r = min(k < r)\n    tuple<T, T, S> mex(T\
    \ k) const {\n        auto it = key(k);\n        return make_tuple(it->l, it->r,\
    \ it->x);\n    }\n    vector<tuple<T, T, S>> intervals() const {\n        vector<tuple<T,\
    \ T, S>> res;\n        res.reserve(s.size());\n        for (auto [l, r, x] : s)\
    \ {\n            if (abs(l) != inf && abs(r) != inf) res.emplace_back(l, r, x);\n\
    \        }\n        return res;\n    }\n    void debug() const {\n        for\
    \ (auto [l, r, x] : intervals()) {\n            cout << '(' << l << ',' << r <<\
    \ ',' << x << ')';\n        }\n        cout << endl;\n    }\nprivate:\n    static\
    \ constexpr T inf = numeric_limits<T>::max();\n    struct node {\n        T l,\
    \ r;\n        S x;\n        node(S e) : node(-inf, -inf, e) {}\n        node(T\
    \ _l, T _r, const S &_x) : l(_l), r(_r), x(_x) {}\n        constexpr bool operator<(const\
    \ node &a) const {\n            return l == a.l ? r < a.r : l < a.l;\n       \
    \ }\n    };\n    const S e;\n    set<node> s;\n    typename set<node>::iterator\
    \ key(T k) const {\n        return prev(s.upper_bound(node(k, inf, e)));\n   \
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/set/interval_map.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/set/interval_map.hpp
layout: document
redirect_from:
- /library/src/data_structure/set/interval_map.hpp
- /library/src/data_structure/set/interval_map.hpp.html
title: src/data_structure/set/interval_map.hpp
---
