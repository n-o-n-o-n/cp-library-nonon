---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/monotone_minima.hpp
    title: src/dp/monotone_minima.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/min_plus_convolution_convex_arbitrary.test.cpp
    title: test/convolution/min_plus_convolution_convex_arbitrary.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/convolution/min_plus_convolution_convex_arbitrary.hpp\"\
    \n#include <numeric>\n#include <vector>\n#line 3 \"src/dp/monotone_minima.hpp\"\
    \nusing namespace std;\n\ntemplate<typename F, typename C>\nvector<int> monotone_minima(int\
    \ h, int w, const F &f, const C &comp) {\n    vector<int> id(h, -1);\n    auto\
    \ rec = [&](const auto &rec, int il, int jl, int ir, int jr) -> void {\n     \
    \   if (il > ir) return;\n        int im = (il + ir) / 2;\n        auto min_val\
    \ = f(im, jl);\n        id[im] = jl;\n        for (int j = jl + 1; j <= jr; j++)\
    \ {\n            auto v = f(im, j);\n            if (comp(v, min_val)) {\n   \
    \             min_val = v;\n                id[im] = j;\n            }\n     \
    \   }\n        rec(rec, il, jl, im - 1, id[im]);\n        rec(rec, im + 1, id[im],\
    \ ir, jr);\n    };\n    rec(rec, 0, 0, h - 1, w - 1);\n    return id;\n}\n#line\
    \ 5 \"src/convolution/min_plus_convolution_convex_arbitrary.hpp\"\nusing namespace\
    \ std;\n\n// a must be convex\ntemplate<typename T>\nvector<T> min_plus_convolution(const\
    \ vector<T> &a, const vector<T> &b) {\n    static constexpr T inf = numeric_limits<T>::max();\n\
    \    auto f = [&](int i, int j) -> T {\n        return i < j || (int)a.size()\
    \ <= i - j ? inf : a[i - j] + b[j];\n    };\n    auto comp = [&](T x, T y) ->\
    \ bool {\n        return x < y;\n    };\n    int n = a.size() + b.size() - 1;\n\
    \    auto id = monotone_minima(n, b.size(), f, comp);\n    vector<T> res(n);\n\
    \    for (int i = 0; i < n; i++) res[i] = f(i, id[i]);\n    return res;\n}\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\n#include \"../dp/monotone_minima.hpp\"\
    \nusing namespace std;\n\n// a must be convex\ntemplate<typename T>\nvector<T>\
    \ min_plus_convolution(const vector<T> &a, const vector<T> &b) {\n    static constexpr\
    \ T inf = numeric_limits<T>::max();\n    auto f = [&](int i, int j) -> T {\n \
    \       return i < j || (int)a.size() <= i - j ? inf : a[i - j] + b[j];\n    };\n\
    \    auto comp = [&](T x, T y) -> bool {\n        return x < y;\n    };\n    int\
    \ n = a.size() + b.size() - 1;\n    auto id = monotone_minima(n, b.size(), f,\
    \ comp);\n    vector<T> res(n);\n    for (int i = 0; i < n; i++) res[i] = f(i,\
    \ id[i]);\n    return res;\n}"
  dependsOn:
  - src/dp/monotone_minima.hpp
  isVerificationFile: false
  path: src/convolution/min_plus_convolution_convex_arbitrary.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/min_plus_convolution_convex_arbitrary.test.cpp
documentation_of: src/convolution/min_plus_convolution_convex_arbitrary.hpp
layout: document
redirect_from:
- /library/src/convolution/min_plus_convolution_convex_arbitrary.hpp
- /library/src/convolution/min_plus_convolution_convex_arbitrary.hpp.html
title: src/convolution/min_plus_convolution_convex_arbitrary.hpp
---
