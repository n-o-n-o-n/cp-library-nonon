---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/data_structure/segtree/fenwick_tree.hpp
    title: src/data_structure/segtree/fenwick_tree.hpp
  - icon: ':warning:'
    path: src/misc/compress.hpp
    title: src/misc/compress.hpp
  - icon: ':warning:'
    path: src/misc/merge_and_unique.hpp
    title: src/misc/merge_and_unique.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/misc/inversion_number.hpp\"\n#include <vector>\n#line\
    \ 2 \"src/data_structure/segtree/fenwick_tree.hpp\"\n#include <cassert>\n#line\
    \ 4 \"src/data_structure/segtree/fenwick_tree.hpp\"\nusing namespace std;\n\n\
    template<typename T>\nstruct fenwick_tree {\n    fenwick_tree() = default;\n \
    \   fenwick_tree(int _n) : fenwick_tree(vector<T>(_n, 0)) {}\n    fenwick_tree(const\
    \ vector<T> &_v) : n(_v.size()) {\n        d = vector<T>(n, 0);\n        v = vector<T>(n,\
    \ 0);\n        for (int i = 1; i <= n; i++) {\n            v[i - 1] = _v[i - 1];\n\
    \            d[i - 1] += v[i - 1];\n            int j = i + (i & -i);\n      \
    \      if (j <= n) d[j - 1] += d[i - 1];\n        }\n    }\n    void add(int p,\
    \ T x) {\n        assert(0 <= p && p < n);\n        v[p] += x;\n        for (p++;\
    \ p <= n; p += p & -p) {\n            d[p - 1] += x;\n        }\n    }\n    void\
    \ update(int p, T x) {\n        assert(0 <= p && p < n);\n        add(p, x - v[p]);\n\
    \    }\n    T get(int p) const {\n        assert(0 <= p && p < n);\n        return\
    \ v[p];\n    }\n    T sum(int l, int r) const {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        return sum(r) - sum(l);\n    }\n    // max{ r | sum(r)\
    \ < x }\n    int lower_bound(T x) const {\n        int r = 0, p = 1;\n       \
    \ while ((p << 1) <= n) p <<= 1;\n        while (p > 0) {\n            if (r +\
    \ p <= n && d[r + p - 1] < x) {\n                r += p;\n                x -=\
    \ d[r - 1];\n            }\n            p >>= 1;\n        }\n        return r;\n\
    \    }\nprivate:\n    int n;\n    vector<T> d, v;\n    T sum(int p) const {\n\
    \        T res = 0;\n        for (; p > 0; p -= p & -p) {\n            res +=\
    \ d[p - 1];\n        }\n        return res;\n    }\n};\n#line 2 \"src/misc/compress.hpp\"\
    \n#include <algorithm>\n#line 4 \"src/misc/merge_and_unique.hpp\"\nusing namespace\
    \ std;\n\ntemplate<typename T, typename... Ts>\nvector<T> merge_and_unique(const\
    \ vector<T> &a, const Ts &...z) {\n    vector<T> res = a;\n    (res.insert(res.end(),\
    \ z.begin(), z.end()), ...);\n    sort(res.begin(), res.end());\n    res.erase(unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n#line 5 \"src/misc/compress.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T>\nvector<int> compress(const vector<T>\
    \ &v) {\n    auto zip = merge_and_unique(v);\n    vector<int> res;\n    res.reserve(v.size());\n\
    \    for (const T &e : v) {\n        res.push_back(lower_bound(zip.begin(), zip.end(),\
    \ e) - zip.begin());\n    }\n    return res;\n}\n\ntemplate<typename T, typename...\
    \ Ts>\nauto compress(const vector<T> &a, const Ts &...z) {\n    auto zip = merge_and_unique(a,\
    \ z...);\n    auto f = [&] (const vector<T> &v) -> vector<int> {\n        vector<int>\
    \ res;\n        res.reserve(v.size());\n        for (const T &e : v) {\n     \
    \       res.push_back(lower_bound(zip.begin(), zip.end(), e) - zip.begin());\n\
    \        }\n        return res;\n    };\n    return make_tuple(f(a), f(z)...);\n\
    }\n\ntemplate<typename T, typename... Ts>\nint compress_inplace(vector<T> &a,\
    \ Ts &...z) {\n    auto zip = merge_and_unique(a, z...);\n    auto f = [&] (vector<T>\
    \ &v) -> void {\n        for (T &e : v) {\n            e = lower_bound(zip.begin(),\
    \ zip.end(), e) - zip.begin();\n        }\n    };\n    (f(a), ..., f(z));\n  \
    \  return (int)zip.size();\n}\n#line 5 \"src/misc/inversion_number.hpp\"\n\ntemplate<typename\
    \ S>\nlong long inversion_number(const vector<S> &v) {\n    int n = v.size();\n\
    \    vector<int> a = compress(v);\n    fenwick_tree<int> fw(n);\n    long long\
    \ res = 0;\n    for (int i = 0; i < n; i++) {\n        res += fw.sum(a[i] + 1,\
    \ n);\n        fw.add(a[i], 1);\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"../data_structure/segtree/fenwick_tree.hpp\"\
    \n#include \"compress.hpp\"\n\ntemplate<typename S>\nlong long inversion_number(const\
    \ vector<S> &v) {\n    int n = v.size();\n    vector<int> a = compress(v);\n \
    \   fenwick_tree<int> fw(n);\n    long long res = 0;\n    for (int i = 0; i <\
    \ n; i++) {\n        res += fw.sum(a[i] + 1, n);\n        fw.add(a[i], 1);\n \
    \   }\n    return res;\n}"
  dependsOn:
  - src/data_structure/segtree/fenwick_tree.hpp
  - src/misc/compress.hpp
  - src/misc/merge_and_unique.hpp
  isVerificationFile: false
  path: src/misc/inversion_number.hpp
  requiredBy: []
  timestamp: '2025-08-12 07:19:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/inversion_number.hpp
layout: document
redirect_from:
- /library/src/misc/inversion_number.hpp
- /library/src/misc/inversion_number.hpp.html
title: src/misc/inversion_number.hpp
---
