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
  bundledCode: "#line 2 \"src/data_structure/cht/li_chao_tree.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename T>\nstruct li_chao_tree {\n    li_chao_tree() : built(false)\
    \ {}\n    li_chao_tree(const vector<T> &_xs) : xs(_xs), built(false) {\n     \
    \   build();\n    }\n    void add_point(T x) {\n        xs.push_back(x);\n   \
    \ }\n    void add_line(T a, T b) {\n        build();\n        update(line(a, b),\
    \ 1, 0, sz);\n    }\n    void add_segmrnt(T xl, T xr, T a, T b) {\n        build();\n\
    \        int l = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();\n       \
    \ int r = lower_bound(xs.begin(), xs.end(), xr) - xs.begin();\n        line f(a,\
    \ b);\n        int len = 1, ll = l, rr = r;\n        l += sz, r += sz;\n     \
    \   while (l < r) {\n            if (l & 1) {\n                update(f, l++,\
    \ ll, ll + len);\n                ll += len;\n            }\n            if (r\
    \ & 1) {\n                rr -= len;\n                update(f, --r, rr, rr +\
    \ len);\n            }\n            l >>= 1;\n            r >>= 1;\n         \
    \   len <<= 1;\n        }\n    }\n    T get_min(T x) {\n        build();\n   \
    \     int p = lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n        assert(xs[p]\
    \ == x);\n        p += sz;\n        T res = inf;\n        for (int i = 0; i <=\
    \ log; i++) {\n            res = min(res, d[p >> i](x));\n        }\n        return\
    \ res;\n    }\nprivate:\n    struct line {\n        T a, b;\n        line(T _a,\
    \ T _b) : a(_a), b(_b) {}\n        T operator()(T x) const {\n            return\
    \ a * x + b;\n        }\n    };\n    int n, log, sz;\n    vector<T> xs;\n    vector<line>\
    \ d;\n    bool built;\n    static constexpr T inf = numeric_limits<T>::max();\n\
    \    static constexpr line e() {\n        return line(0, inf);\n    }\n    void\
    \ build() {\n        if (built) return;\n        if (xs.empty()) xs.push_back(0);\n\
    \        sort(xs.begin(), xs.end());\n        xs.erase(unique(xs.begin(), xs.end()),\
    \ xs.end());\n        n = xs.size();\n        log = 1;\n        while ((1 << log)\
    \ < n) log++;\n        sz = 1 << log;\n        d = vector<line>(2 * sz, e());\n\
    \        while ((int)xs.size() <= sz) xs.push_back(xs.back() + 1);\n        built\
    \ = true;\n    }\n    void update(line f, int p, int l, int r) {\n        auto\
    \ &g = d[p];\n        int m = (l + r) / 2;\n        bool pl = f(xs[l]) < g(xs[l]);\n\
    \        bool pm = f(xs[m]) < g(xs[m]);\n        bool pr = f(xs[r]) < g(xs[r]);\n\
    \        if (!pl && !pr) return;\n        if (pl && pr) {\n            g = f;\n\
    \            return;\n        }\n        if (pm) swap(f, g);\n        if (l +\
    \ 1 == r) return;\n        if (pl ^ pm) {\n            update(f, 2 * p, l, m);\n\
    \        } else {\n            update(f, 2 * p + 1, m, r);\n        }\n    }\n\
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <limits>\n\
    #include <vector>\nusing namespace std;\n\ntemplate<typename T>\nstruct li_chao_tree\
    \ {\n    li_chao_tree() : built(false) {}\n    li_chao_tree(const vector<T> &_xs)\
    \ : xs(_xs), built(false) {\n        build();\n    }\n    void add_point(T x)\
    \ {\n        xs.push_back(x);\n    }\n    void add_line(T a, T b) {\n        build();\n\
    \        update(line(a, b), 1, 0, sz);\n    }\n    void add_segmrnt(T xl, T xr,\
    \ T a, T b) {\n        build();\n        int l = lower_bound(xs.begin(), xs.end(),\
    \ xl) - xs.begin();\n        int r = lower_bound(xs.begin(), xs.end(), xr) - xs.begin();\n\
    \        line f(a, b);\n        int len = 1, ll = l, rr = r;\n        l += sz,\
    \ r += sz;\n        while (l < r) {\n            if (l & 1) {\n              \
    \  update(f, l++, ll, ll + len);\n                ll += len;\n            }\n\
    \            if (r & 1) {\n                rr -= len;\n                update(f,\
    \ --r, rr, rr + len);\n            }\n            l >>= 1;\n            r >>=\
    \ 1;\n            len <<= 1;\n        }\n    }\n    T get_min(T x) {\n       \
    \ build();\n        int p = lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n\
    \        assert(xs[p] == x);\n        p += sz;\n        T res = inf;\n       \
    \ for (int i = 0; i <= log; i++) {\n            res = min(res, d[p >> i](x));\n\
    \        }\n        return res;\n    }\nprivate:\n    struct line {\n        T\
    \ a, b;\n        line(T _a, T _b) : a(_a), b(_b) {}\n        T operator()(T x)\
    \ const {\n            return a * x + b;\n        }\n    };\n    int n, log, sz;\n\
    \    vector<T> xs;\n    vector<line> d;\n    bool built;\n    static constexpr\
    \ T inf = numeric_limits<T>::max();\n    static constexpr line e() {\n       \
    \ return line(0, inf);\n    }\n    void build() {\n        if (built) return;\n\
    \        if (xs.empty()) xs.push_back(0);\n        sort(xs.begin(), xs.end());\n\
    \        xs.erase(unique(xs.begin(), xs.end()), xs.end());\n        n = xs.size();\n\
    \        log = 1;\n        while ((1 << log) < n) log++;\n        sz = 1 << log;\n\
    \        d = vector<line>(2 * sz, e());\n        while ((int)xs.size() <= sz)\
    \ xs.push_back(xs.back() + 1);\n        built = true;\n    }\n    void update(line\
    \ f, int p, int l, int r) {\n        auto &g = d[p];\n        int m = (l + r)\
    \ / 2;\n        bool pl = f(xs[l]) < g(xs[l]);\n        bool pm = f(xs[m]) < g(xs[m]);\n\
    \        bool pr = f(xs[r]) < g(xs[r]);\n        if (!pl && !pr) return;\n   \
    \     if (pl && pr) {\n            g = f;\n            return;\n        }\n  \
    \      if (pm) swap(f, g);\n        if (l + 1 == r) return;\n        if (pl ^\
    \ pm) {\n            update(f, 2 * p, l, m);\n        } else {\n            update(f,\
    \ 2 * p + 1, m, r);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/cht/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/cht/li_chao_tree.hpp
layout: document
redirect_from:
- /library/src/data_structure/cht/li_chao_tree.hpp
- /library/src/data_structure/cht/li_chao_tree.hpp.html
title: src/data_structure/cht/li_chao_tree.hpp
---
