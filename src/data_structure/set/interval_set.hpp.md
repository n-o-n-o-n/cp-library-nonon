---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/set/interval_set.hpp\"\n#include <cassert>\n\
    #include <iostream>\n#include <numeric>\n#include <set>\n#include <vector>\nusing\
    \ namespace std;\n\ntemplate<typename T>\nstruct interval_set {\n    interval_set()\
    \ {\n        s.emplace(-inf, -inf);\n        s.emplace(inf, inf);\n    }\n   \
    \ template<typename A, typename D>\n    void insert(T l, T r, const A &add, const\
    \ D &del) {\n        if (l == r) return;\n        auto it = key(l);\n        if\
    \ (it->l <= l && r <= it->r) return;\n        if (it->l <= l && l <= it->r) {\n\
    \            del(it->l, it->r);\n            l = it->l;\n            it = s.erase(it);\n\
    \        } else {\n            it = next(it);\n        }\n        while (it->r\
    \ < r) {\n            del(it->l, it->r);\n            it = s.erase(it);\n    \
    \    }\n        if (it->l <= r) {\n            del(it->l, it->r);\n          \
    \  r = it->r;\n            s.erase(it);\n        }\n        add(l, r);\n     \
    \   s.emplace(node(l, r));\n    }\n    void insert(T l, T r) {\n        insert(l,\
    \ r, [] (T, T) {}, [] (T, T) {});\n    }\n    template<typename A, typename D>\n\
    \    void insert(T k, const A &add, const D &del) {\n        insert(k, k + 1,\
    \ add, del);\n    }\n    void insert(T k) {\n        insert(k, k + 1);\n    }\n\
    \    template<typename A, typename D>\n    void erase(T l, T r, const A &add,\
    \ const D &del) {\n        if (l == r) return;\n        auto it = key(l);\n  \
    \      if (it->l <= l && r <= it->r) {\n            if (it->l < l) {\n       \
    \         add(it->l, l);\n                s.emplace(node(it->l, l));\n       \
    \     }\n            if (r < it->r) {\n                add(r, it->r);\n      \
    \          s.emplace(node(r, it->r));\n            }\n            del(it->l, it->r);\n\
    \            s.erase(it);\n            return;\n        }\n        if (it->l <=\
    \ l && l < it->r) {\n            if (it->l < l) {\n                add(it->l,\
    \ l);\n                s.emplace(it->l, l);\n            }\n            del(it->l,\
    \ it->r);\n            it = s.erase(it);\n        } else {\n            it = next(it);\n\
    \        }\n        while (it->r <= r) {\n            del(it->l, it->r);\n   \
    \         it = s.erase(it);\n        }\n        if (it->l < r) {\n           \
    \ add(r, it->r);\n            s.emplace(r, it->r);\n            del(it->l, it->r);\n\
    \            s.erase(it);\n        }\n    }\n    void erase(T l, T r) {\n    \
    \    erase(l, r, [] (T, T) {}, [] (T, T) {});\n    }\n    template<typename A,\
    \ typename D>\n    void erase(T k, const A &add, const D &del) {\n        erase(k,\
    \ k + 1, add, del);\n    }\n    void erase(T k) {\n        erase(k, k + 1);\n\
    \    }\n    T mex(T k = 0) const {\n        auto it = key(k);\n        return\
    \ it->l <= k && k < it->r ? it->r : k;\n    }\n    bool covered(T l, T r) const\
    \ {\n        if (l == r) return true;\n        auto it = key(l);\n        return\
    \ it->l <= l && r <= it->r;\n    }\n    bool covered(T k) const {\n        return\
    \ covered(k, k + 1);\n    }\n    pair<T, T> get(T k) const {\n        auto it\
    \ = key(k);\n        return it->l <= k && k < it->r ? make_pair(it->l, it->r)\
    \ : make_pair(-inf, -inf);\n    }\n    vector<pair<T, T>> intervals() const {\n\
    \        vector<pair<T, T>> res;\n        res.reserve(s.size());\n        for\
    \ (auto [l, r] : s) {\n            if (abs(l) != inf && abs(r) != inf) res.emplace_back(l,\
    \ r);\n        }\n        return res;\n    }\n    void clear() {\n        s =\
    \ set<node>();\n        s.emplace(-inf, -inf);\n        s.emplace(inf, inf);\n\
    \    }\n    void debug() const {\n        for (auto [l, r] : intervals()) {\n\
    \            cout << '(' << l << ',' << r << ')';\n        }\n        cout <<\
    \ endl;\n    }\nprivate:\n    static constexpr T inf = numeric_limits<T>::max();\n\
    \    struct node {\n        T l, r;\n        node() : node(-inf, -inf) {}\n  \
    \      node(T _l, T _r) : l(_l), r(_r) {}\n        constexpr bool operator<(const\
    \ node &a) const {\n            return l == a.l ? r < a.r : l < a.l;\n       \
    \ }\n    };\n    set<node> s;\n    typename set<node>::iterator key(T k) const\
    \ {\n        return prev(s.upper_bound(node(k, inf)));\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <iostream>\n#include <numeric>\n\
    #include <set>\n#include <vector>\nusing namespace std;\n\ntemplate<typename T>\n\
    struct interval_set {\n    interval_set() {\n        s.emplace(-inf, -inf);\n\
    \        s.emplace(inf, inf);\n    }\n    template<typename A, typename D>\n \
    \   void insert(T l, T r, const A &add, const D &del) {\n        if (l == r) return;\n\
    \        auto it = key(l);\n        if (it->l <= l && r <= it->r) return;\n  \
    \      if (it->l <= l && l <= it->r) {\n            del(it->l, it->r);\n     \
    \       l = it->l;\n            it = s.erase(it);\n        } else {\n        \
    \    it = next(it);\n        }\n        while (it->r < r) {\n            del(it->l,\
    \ it->r);\n            it = s.erase(it);\n        }\n        if (it->l <= r) {\n\
    \            del(it->l, it->r);\n            r = it->r;\n            s.erase(it);\n\
    \        }\n        add(l, r);\n        s.emplace(node(l, r));\n    }\n    void\
    \ insert(T l, T r) {\n        insert(l, r, [] (T, T) {}, [] (T, T) {});\n    }\n\
    \    template<typename A, typename D>\n    void insert(T k, const A &add, const\
    \ D &del) {\n        insert(k, k + 1, add, del);\n    }\n    void insert(T k)\
    \ {\n        insert(k, k + 1);\n    }\n    template<typename A, typename D>\n\
    \    void erase(T l, T r, const A &add, const D &del) {\n        if (l == r) return;\n\
    \        auto it = key(l);\n        if (it->l <= l && r <= it->r) {\n        \
    \    if (it->l < l) {\n                add(it->l, l);\n                s.emplace(node(it->l,\
    \ l));\n            }\n            if (r < it->r) {\n                add(r, it->r);\n\
    \                s.emplace(node(r, it->r));\n            }\n            del(it->l,\
    \ it->r);\n            s.erase(it);\n            return;\n        }\n        if\
    \ (it->l <= l && l < it->r) {\n            if (it->l < l) {\n                add(it->l,\
    \ l);\n                s.emplace(it->l, l);\n            }\n            del(it->l,\
    \ it->r);\n            it = s.erase(it);\n        } else {\n            it = next(it);\n\
    \        }\n        while (it->r <= r) {\n            del(it->l, it->r);\n   \
    \         it = s.erase(it);\n        }\n        if (it->l < r) {\n           \
    \ add(r, it->r);\n            s.emplace(r, it->r);\n            del(it->l, it->r);\n\
    \            s.erase(it);\n        }\n    }\n    void erase(T l, T r) {\n    \
    \    erase(l, r, [] (T, T) {}, [] (T, T) {});\n    }\n    template<typename A,\
    \ typename D>\n    void erase(T k, const A &add, const D &del) {\n        erase(k,\
    \ k + 1, add, del);\n    }\n    void erase(T k) {\n        erase(k, k + 1);\n\
    \    }\n    T mex(T k = 0) const {\n        auto it = key(k);\n        return\
    \ it->l <= k && k < it->r ? it->r : k;\n    }\n    bool covered(T l, T r) const\
    \ {\n        if (l == r) return true;\n        auto it = key(l);\n        return\
    \ it->l <= l && r <= it->r;\n    }\n    bool covered(T k) const {\n        return\
    \ covered(k, k + 1);\n    }\n    pair<T, T> get(T k) const {\n        auto it\
    \ = key(k);\n        return it->l <= k && k < it->r ? make_pair(it->l, it->r)\
    \ : make_pair(-inf, -inf);\n    }\n    vector<pair<T, T>> intervals() const {\n\
    \        vector<pair<T, T>> res;\n        res.reserve(s.size());\n        for\
    \ (auto [l, r] : s) {\n            if (abs(l) != inf && abs(r) != inf) res.emplace_back(l,\
    \ r);\n        }\n        return res;\n    }\n    void clear() {\n        s =\
    \ set<node>();\n        s.emplace(-inf, -inf);\n        s.emplace(inf, inf);\n\
    \    }\n    void debug() const {\n        for (auto [l, r] : intervals()) {\n\
    \            cout << '(' << l << ',' << r << ')';\n        }\n        cout <<\
    \ endl;\n    }\nprivate:\n    static constexpr T inf = numeric_limits<T>::max();\n\
    \    struct node {\n        T l, r;\n        node() : node(-inf, -inf) {}\n  \
    \      node(T _l, T _r) : l(_l), r(_r) {}\n        constexpr bool operator<(const\
    \ node &a) const {\n            return l == a.l ? r < a.r : l < a.l;\n       \
    \ }\n    };\n    set<node> s;\n    typename set<node>::iterator key(T k) const\
    \ {\n        return prev(s.upper_bound(node(k, inf)));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/set/interval_set.hpp
  requiredBy: []
  timestamp: '2025-07-03 14:51:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/set/interval_set.hpp
layout: document
redirect_from:
- /library/src/data_structure/set/interval_set.hpp
- /library/src/data_structure/set/interval_set.hpp.html
title: src/data_structure/set/interval_set.hpp
---
