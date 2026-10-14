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
  bundledCode: "#line 2 \"src/data_structure/cht/dynamic_li_chao_tree.hpp\"\n#include\
    \ <algorithm>\n#include <cassert>\n#include <limits>\n#include <memory>\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate<typename T>\nstruct li_chao_tree\
    \ {\n    li_chao_tree() : li_chao_tree(-inf / 4, inf / 4) {}\n    li_chao_tree(T\
    \ _x_min, T _x_max, int q = 0) : x_min(_x_min), x_max(_x_max) {\n        n = x_max\
    \ - x_min;\n        log = 1;\n        while ((T(1) << log) < n) log++;\n     \
    \   sz = T(1) << log;\n        d.reserve(q * log);\n        new_node();\n    }\n\
    \    static constexpr T max() {\n        return inf;\n    }\n    // add y = ax\
    \ + b for x in (-inf, inf)\n    void add_line(T a, T b) {\n        update(0, line(a,\
    \ b), 0, sz);\n    }\n    // add y = ax + b for x in [l, r)\n    void add_segment(T\
    \ xl, T xr, T a, T b) {\n        assert(x_min <= xl && xl <= xr && xr <= x_max);\n\
    \        add_segment(0, line(a, b), 0, sz, xl - x_min, xr - x_min);\n    }\n \
    \   T get_min(T x) {\n        assert(x_min <= x && x <= x_max);\n        return\
    \ get_min(0, 0, sz, x - x_min);\n    }\nprivate:\n    struct line {\n        T\
    \ a, b;\n        line(T _a, T _b) : a(_a), b(_b) {}\n        T operator()(T x)\
    \ const {\n            return a * x + b;\n        }\n    };\n    struct node {\n\
    \        line f;\n        int l, r;\n        node() : node(e()) {}\n        node(const\
    \ line &_f) : f(_f), l(-1), r(-1) {}\n    };\n    static constexpr T inf = numeric_limits<T>::max();\n\
    \    static constexpr line e() {\n        return line(0, inf);\n    }\n    T x_min,\
    \ x_max, n, sz;\n    int log;\n    vector<node> d;\n    int new_node() {\n   \
    \     int res = d.size();\n        d.emplace_back(node());\n        return res;\n\
    \    }\n    void update(int p, line f, T l, T r) {\n        auto &g = d[p].f;\n\
    \        T m = l + (r - l) / 2;\n        T xl = l + x_min, xm = m + x_min, xr\
    \ = r + x_min;\n        bool pl = f(xl) < g(xl);\n        bool pm = f(xm) < g(xm);\n\
    \        bool pr = f(xr) < g(xr);\n        if (!pl && !pr) return;\n        if\
    \ (pl && pr) {\n            g = f;\n            return;\n        }\n        if\
    \ (pm) swap(f, g);\n        if (l + 1 == r) return;\n        if (pl ^ pm) {\n\
    \            if (d[p].l == -1) d[p].l = new_node();\n            update(d[p].l,\
    \ f, l, m);\n        } else {\n            if (d[p].r == -1) d[p].r = new_node();\n\
    \            update(d[p].r, f, m, r);\n        }\n    }\n    void add_segment(int\
    \ p, const line &f, T l, T r, T xl, T xr) {\n        if (r <= xl || xr <= l) return;\n\
    \        if (xl <= l && r <= xr) {\n            update(p, f, l, r);\n        \
    \    return;\n        }\n        if (l + 1 == r) return;\n        T m = l + (r\
    \ - l) / 2;\n        if (l < xr && xl < m) {\n            if (d[p].l == -1) d[p].l\
    \ = new_node();\n            add_segment(d[p].l, f, l, m, xl, xr);\n        }\n\
    \        if (m < xr && xl < r) {\n            if (d[p].r == -1) d[p].r = new_node();\n\
    \            add_segment(d[p].r, f, m, r, xl, xr);\n        }\n    }\n    T get_min(int\
    \ p, T l, T r, T x) {\n        if (p == -1) return inf;\n        auto &t = d[p];\n\
    \        T val = t.f(x + x_min);\n        if (l + 1 == r) return val;\n      \
    \  T m = l + (r - l) / 2;\n        return min(val, x < m ? get_min(t.l, l, m,\
    \ x) : get_min(t.r, m, r, x));\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <limits>\n\
    #include <memory>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ T>\nstruct li_chao_tree {\n    li_chao_tree() : li_chao_tree(-inf / 4, inf /\
    \ 4) {}\n    li_chao_tree(T _x_min, T _x_max, int q = 0) : x_min(_x_min), x_max(_x_max)\
    \ {\n        n = x_max - x_min;\n        log = 1;\n        while ((T(1) << log)\
    \ < n) log++;\n        sz = T(1) << log;\n        d.reserve(q * log);\n      \
    \  new_node();\n    }\n    static constexpr T max() {\n        return inf;\n \
    \   }\n    // add y = ax + b for x in (-inf, inf)\n    void add_line(T a, T b)\
    \ {\n        update(0, line(a, b), 0, sz);\n    }\n    // add y = ax + b for x\
    \ in [l, r)\n    void add_segment(T xl, T xr, T a, T b) {\n        assert(x_min\
    \ <= xl && xl <= xr && xr <= x_max);\n        add_segment(0, line(a, b), 0, sz,\
    \ xl - x_min, xr - x_min);\n    }\n    T get_min(T x) {\n        assert(x_min\
    \ <= x && x <= x_max);\n        return get_min(0, 0, sz, x - x_min);\n    }\n\
    private:\n    struct line {\n        T a, b;\n        line(T _a, T _b) : a(_a),\
    \ b(_b) {}\n        T operator()(T x) const {\n            return a * x + b;\n\
    \        }\n    };\n    struct node {\n        line f;\n        int l, r;\n  \
    \      node() : node(e()) {}\n        node(const line &_f) : f(_f), l(-1), r(-1)\
    \ {}\n    };\n    static constexpr T inf = numeric_limits<T>::max();\n    static\
    \ constexpr line e() {\n        return line(0, inf);\n    }\n    T x_min, x_max,\
    \ n, sz;\n    int log;\n    vector<node> d;\n    int new_node() {\n        int\
    \ res = d.size();\n        d.emplace_back(node());\n        return res;\n    }\n\
    \    void update(int p, line f, T l, T r) {\n        auto &g = d[p].f;\n     \
    \   T m = l + (r - l) / 2;\n        T xl = l + x_min, xm = m + x_min, xr = r +\
    \ x_min;\n        bool pl = f(xl) < g(xl);\n        bool pm = f(xm) < g(xm);\n\
    \        bool pr = f(xr) < g(xr);\n        if (!pl && !pr) return;\n        if\
    \ (pl && pr) {\n            g = f;\n            return;\n        }\n        if\
    \ (pm) swap(f, g);\n        if (l + 1 == r) return;\n        if (pl ^ pm) {\n\
    \            if (d[p].l == -1) d[p].l = new_node();\n            update(d[p].l,\
    \ f, l, m);\n        } else {\n            if (d[p].r == -1) d[p].r = new_node();\n\
    \            update(d[p].r, f, m, r);\n        }\n    }\n    void add_segment(int\
    \ p, const line &f, T l, T r, T xl, T xr) {\n        if (r <= xl || xr <= l) return;\n\
    \        if (xl <= l && r <= xr) {\n            update(p, f, l, r);\n        \
    \    return;\n        }\n        if (l + 1 == r) return;\n        T m = l + (r\
    \ - l) / 2;\n        if (l < xr && xl < m) {\n            if (d[p].l == -1) d[p].l\
    \ = new_node();\n            add_segment(d[p].l, f, l, m, xl, xr);\n        }\n\
    \        if (m < xr && xl < r) {\n            if (d[p].r == -1) d[p].r = new_node();\n\
    \            add_segment(d[p].r, f, m, r, xl, xr);\n        }\n    }\n    T get_min(int\
    \ p, T l, T r, T x) {\n        if (p == -1) return inf;\n        auto &t = d[p];\n\
    \        T val = t.f(x + x_min);\n        if (l + 1 == r) return val;\n      \
    \  T m = l + (r - l) / 2;\n        return min(val, x < m ? get_min(t.l, l, m,\
    \ x) : get_min(t.r, m, r, x));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/cht/dynamic_li_chao_tree.hpp
  requiredBy: []
  timestamp: '2025-12-27 09:40:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/cht/dynamic_li_chao_tree.hpp
layout: document
redirect_from:
- /library/src/data_structure/cht/dynamic_li_chao_tree.hpp
- /library/src/data_structure/cht/dynamic_li_chao_tree.hpp.html
title: src/data_structure/cht/dynamic_li_chao_tree.hpp
---
