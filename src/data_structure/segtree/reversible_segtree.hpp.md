---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/random/utility.hpp
    title: src/random/utility.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/segtree/reversible_segtree.hpp\"\n#include\
    \ <cassert>\n#include <memory>\n#include <tuple>\n#line 3 \"src/random/utility.hpp\"\
    \n#include <concepts>\n#include <random>\nusing namespace std;\n\nnamespace rng\
    \ {\n\ninline random_device seed;\ninline mt19937 eng(seed());\n\ntemplate<typename\
    \ T>\nvoid set_seed(const T &sd) {\n    eng.seed(sd);\n}\n\ntemplate<integral\
    \ T>\ninline T randint(T lo, T hi) {\n    assert(lo <= hi);\n    uniform_int_distribution<T>\
    \ dist(lo, hi);\n    return dist(eng);\n}\n\ntemplate<integral T>\ninline pair<T,\
    \ T> randpair(T lo, T hi, bool strict = false) {\n    assert(lo + strict <= hi);\n\
    \    T l = randint(lo, hi - strict);\n    T r = randint(l + strict, hi);\n   \
    \ return make_pair(l, r);\n}\n\n} // namespace rng\n#line 6 \"src/data_structure/segtree/reversible_segtree.hpp\"\
    \nusing namespace std;\n\ntemplate<typename Monoid>\nstruct reversible_segtree\
    \ {\n    using M = Monoid;\n    using S = typename M::S;\n    reversible_segtree()\
    \ = default;\n    reversible_segtree(const vector<S> &v) {\n        root = nullptr;\n\
    \        for (const auto &e : v) {\n            auto new_node = make_unique<node>(e);\n\
    \            root = merge(root, new_node);\n        }\n    }\n    void set(int\
    \ p, const S &x) {\n        assert(0 <= p && p < size(root));\n        auto [pl,\
    \ pm, pr] = split(root, p, p + 1);\n        pm->x = x;\n        update(pm);\n\
    \        root = merge(pl, pm, pr);\n    }\n    void reverse(int l, int r) {\n\
    \        assert(0 <= l && l <= r && r <= size(root));\n        auto [pl, pm, pr]\
    \ = split(root, l, r);\n        if (pm) pm->rev ^= true;\n        root = merge(pl,\
    \ pm, pr);\n    }\n    void insert(int p, const S &x) {\n        assert(0 <= p\
    \ && p <= size(root));\n        auto [pl, pr] = split(root, p);\n        auto\
    \ pm = make_unique<node>(x);\n        root = merge(pl, pm, pr);\n    }\n    void\
    \ erase(int p) {\n        assert(0 <= p && p < size(root));\n        auto [pl,\
    \ pm, pr] = split(root, p, p + 1);\n        root = merge(pl, pr);\n    }\n   \
    \ void push_back(const S &x) {\n        auto pb = make_unique<node>(x);\n    \
    \    root = merge(root, pb);\n    }\n    void push_front(const S &x) {\n     \
    \   auto pf = make_unique<node>(x);\n        root = merge(pf, root);\n    }\n\
    \    void pop_back() {\n        assert(size(root));\n        erase(size(root)\
    \ - 1);\n    }\n    void pop_front() {\n        assert(size(root));\n        erase(0);\n\
    \    }\n    S get(int p) {\n        assert(0 <= p && p < size(root)); \n     \
    \   auto [pl, pm, pr] = split(root, p, p + 1);\n        auto res = val(pm);\n\
    \        root = merge(pl, pm, pr);\n        return res;\n    }\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= size(root));\n        auto\
    \ [pl, pm, pr] = split(root, l, r);\n        auto res = sum(pm);\n        root\
    \ = merge(pl, pm, pr);\n        return res;\n    }\nprivate:\n    struct node\
    \ {\n        unique_ptr<node> l, r;\n        S x, sum, mus;\n        int sz, pri;\n\
    \        bool rev;\n        node() : node(M::e()) {}\n        node(const S &_x)\
    \ : l(nullptr), r(nullptr), x(_x), sum(_x), mus(_x), sz(1), rev(false) {\n   \
    \         pri = rng::randint(0, numeric_limits<int>::max());\n        }\n    };\n\
    \    using node_ptr = unique_ptr<node>;\n    node_ptr root;\n    int size(const\
    \ node_ptr &t) const { return t ? t->sz : 0; }\n    S val(const node_ptr &t) const\
    \ { return t ? t->x : M::e(); }\n    S sum(const node_ptr &t) const { return t\
    \ ? t->rev ? t->mus : t->sum : M::e(); }\n    S mus(const node_ptr &t) const {\
    \ return t ? t->rev ? t->sum : t->mus : M::e(); }\n    void update(node_ptr &t)\
    \ {\n        if (!t) return;\n        t->sz = 1 + size(t->l) + size(t->r);\n \
    \       t->sum = M::op(sum(t->l), M::op(t->x, sum(t->r)));\n        t->mus = M::op(mus(t->r),\
    \ M::op(t->x, mus(t->l)));\n    }\n    void push(node_ptr &t) {\n        if (!t)\
    \ return;\n        if (t->rev) {\n            swap(t->l, t->r);\n            swap(t->sum,\
    \ t->mus);\n            if (t->l) t->l->rev ^= true;\n            if (t->r) t->r->rev\
    \ ^= true;\n            t->rev = false;\n        }\n    }\n    node_ptr merge(node_ptr\
    \ &pl, node_ptr &pr) {\n        push(pl);\n        push(pr);\n        if (!pl)\
    \ return move(pr);\n        if (!pr) return move(pl);\n        if (pl->pri > pr->pri)\
    \ {\n            pl->r = merge(pl->r, pr);\n            update(pl);\n        \
    \    return move(pl);\n        } else {\n            pr->l = merge(pl, pr->l);\n\
    \            update(pr);\n            return move(pr);\n        }\n    }\n   \
    \ node_ptr merge(node_ptr &pl, node_ptr &pm, node_ptr &pr) {\n        auto p =\
    \ merge(pl, pm);\n        p = merge(p, pr);\n        return move(p);\n    }\n\
    \    pair<node_ptr, node_ptr> split(node_ptr &t, int k) {\n        node_ptr pl\
    \ = nullptr, pr = nullptr;\n        if (!t) return {move(pl), move(pr)};\n   \
    \     push(t);\n        int ls = size(t->l);\n        if (k <= ls) {\n       \
    \     tie(pl, t->l) = split(t->l, k);\n            update(t);\n            pr\
    \ = move(t);\n        } else {\n            tie(t->r, pr) = split(t->r, k - ls\
    \ - 1);\n            update(t);\n            pl = move(t);\n        }\n      \
    \  return {move(pl), move(pr)};\n    }\n    tuple<node_ptr, node_ptr, node_ptr>\
    \ split(node_ptr &t, int l, int r) {\n        auto [plm, pr] = split(t, r);\n\
    \        auto [pl, pm] = split(plm, l);\n        return {move(pl), move(pm), move(pr)};\n\
    \    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <memory>\n#include <tuple>\n#include\
    \ \"../../random/utility.hpp\"\nusing namespace std;\n\ntemplate<typename Monoid>\n\
    struct reversible_segtree {\n    using M = Monoid;\n    using S = typename M::S;\n\
    \    reversible_segtree() = default;\n    reversible_segtree(const vector<S> &v)\
    \ {\n        root = nullptr;\n        for (const auto &e : v) {\n            auto\
    \ new_node = make_unique<node>(e);\n            root = merge(root, new_node);\n\
    \        }\n    }\n    void set(int p, const S &x) {\n        assert(0 <= p &&\
    \ p < size(root));\n        auto [pl, pm, pr] = split(root, p, p + 1);\n     \
    \   pm->x = x;\n        update(pm);\n        root = merge(pl, pm, pr);\n    }\n\
    \    void reverse(int l, int r) {\n        assert(0 <= l && l <= r && r <= size(root));\n\
    \        auto [pl, pm, pr] = split(root, l, r);\n        if (pm) pm->rev ^= true;\n\
    \        root = merge(pl, pm, pr);\n    }\n    void insert(int p, const S &x)\
    \ {\n        assert(0 <= p && p <= size(root));\n        auto [pl, pr] = split(root,\
    \ p);\n        auto pm = make_unique<node>(x);\n        root = merge(pl, pm, pr);\n\
    \    }\n    void erase(int p) {\n        assert(0 <= p && p < size(root));\n \
    \       auto [pl, pm, pr] = split(root, p, p + 1);\n        root = merge(pl, pr);\n\
    \    }\n    void push_back(const S &x) {\n        auto pb = make_unique<node>(x);\n\
    \        root = merge(root, pb);\n    }\n    void push_front(const S &x) {\n \
    \       auto pf = make_unique<node>(x);\n        root = merge(pf, root);\n   \
    \ }\n    void pop_back() {\n        assert(size(root));\n        erase(size(root)\
    \ - 1);\n    }\n    void pop_front() {\n        assert(size(root));\n        erase(0);\n\
    \    }\n    S get(int p) {\n        assert(0 <= p && p < size(root)); \n     \
    \   auto [pl, pm, pr] = split(root, p, p + 1);\n        auto res = val(pm);\n\
    \        root = merge(pl, pm, pr);\n        return res;\n    }\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= size(root));\n        auto\
    \ [pl, pm, pr] = split(root, l, r);\n        auto res = sum(pm);\n        root\
    \ = merge(pl, pm, pr);\n        return res;\n    }\nprivate:\n    struct node\
    \ {\n        unique_ptr<node> l, r;\n        S x, sum, mus;\n        int sz, pri;\n\
    \        bool rev;\n        node() : node(M::e()) {}\n        node(const S &_x)\
    \ : l(nullptr), r(nullptr), x(_x), sum(_x), mus(_x), sz(1), rev(false) {\n   \
    \         pri = rng::randint(0, numeric_limits<int>::max());\n        }\n    };\n\
    \    using node_ptr = unique_ptr<node>;\n    node_ptr root;\n    int size(const\
    \ node_ptr &t) const { return t ? t->sz : 0; }\n    S val(const node_ptr &t) const\
    \ { return t ? t->x : M::e(); }\n    S sum(const node_ptr &t) const { return t\
    \ ? t->rev ? t->mus : t->sum : M::e(); }\n    S mus(const node_ptr &t) const {\
    \ return t ? t->rev ? t->sum : t->mus : M::e(); }\n    void update(node_ptr &t)\
    \ {\n        if (!t) return;\n        t->sz = 1 + size(t->l) + size(t->r);\n \
    \       t->sum = M::op(sum(t->l), M::op(t->x, sum(t->r)));\n        t->mus = M::op(mus(t->r),\
    \ M::op(t->x, mus(t->l)));\n    }\n    void push(node_ptr &t) {\n        if (!t)\
    \ return;\n        if (t->rev) {\n            swap(t->l, t->r);\n            swap(t->sum,\
    \ t->mus);\n            if (t->l) t->l->rev ^= true;\n            if (t->r) t->r->rev\
    \ ^= true;\n            t->rev = false;\n        }\n    }\n    node_ptr merge(node_ptr\
    \ &pl, node_ptr &pr) {\n        push(pl);\n        push(pr);\n        if (!pl)\
    \ return move(pr);\n        if (!pr) return move(pl);\n        if (pl->pri > pr->pri)\
    \ {\n            pl->r = merge(pl->r, pr);\n            update(pl);\n        \
    \    return move(pl);\n        } else {\n            pr->l = merge(pl, pr->l);\n\
    \            update(pr);\n            return move(pr);\n        }\n    }\n   \
    \ node_ptr merge(node_ptr &pl, node_ptr &pm, node_ptr &pr) {\n        auto p =\
    \ merge(pl, pm);\n        p = merge(p, pr);\n        return move(p);\n    }\n\
    \    pair<node_ptr, node_ptr> split(node_ptr &t, int k) {\n        node_ptr pl\
    \ = nullptr, pr = nullptr;\n        if (!t) return {move(pl), move(pr)};\n   \
    \     push(t);\n        int ls = size(t->l);\n        if (k <= ls) {\n       \
    \     tie(pl, t->l) = split(t->l, k);\n            update(t);\n            pr\
    \ = move(t);\n        } else {\n            tie(t->r, pr) = split(t->r, k - ls\
    \ - 1);\n            update(t);\n            pl = move(t);\n        }\n      \
    \  return {move(pl), move(pr)};\n    }\n    tuple<node_ptr, node_ptr, node_ptr>\
    \ split(node_ptr &t, int l, int r) {\n        auto [plm, pr] = split(t, r);\n\
    \        auto [pl, pm] = split(plm, l);\n        return {move(pl), move(pm), move(pr)};\n\
    \    }\n};"
  dependsOn:
  - src/random/utility.hpp
  isVerificationFile: false
  path: src/data_structure/segtree/reversible_segtree.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/segtree/reversible_segtree.hpp
layout: document
redirect_from:
- /library/src/data_structure/segtree/reversible_segtree.hpp
- /library/src/data_structure/segtree/reversible_segtree.hpp.html
title: src/data_structure/segtree/reversible_segtree.hpp
---
