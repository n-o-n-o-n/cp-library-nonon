---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/math/matrix/matrix_mint.hpp
    title: src/math/matrix/matrix_mint.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/best_theorem.hpp
    title: src/graph/best_theorem.hpp
  - icon: ':warning:'
    path: src/graph/count_eulerian_trail.hpp
    title: src/graph/count_eulerian_trail.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/matrix_tree_theorem.hpp\"\n#include <vector>\n\
    #line 2 \"src/math/matrix/matrix_mint.hpp\"\n#include <cassert>\n#line 4 \"src/math/matrix/matrix_mint.hpp\"\
    \nusing namespace std;\n\ntemplate<typename mint>\nstruct matrix : vector<vector<mint>>\
    \ {\n    using vector<vector<mint>>::vector;\n    matrix(int h, int w) : vector<vector<mint>>(h,\
    \ vector<mint>(w)) {}\n    matrix &operator*=(const mint &r) {\n        for (vector<mint>\
    \ &v : *this) {\n            for (mint &a : v) a *= r;\n        }\n        return\
    \ *this;\n    }\n    matrix &operator/=(const mint &r) {\n        mint invr =\
    \ r.inv();\n        return *this *= invr;\n    }\n    matrix &operator+=(const\
    \ matrix& a) {\n        assert(this->size() == a.size());\n        for (int i\
    \ = 0; i < int(this->size()); i++) {\n            assert((*this)[i].size() ==\
    \ a[i].size());\n            for (int j = 0; j < int((*this)[i].size()); j++)\
    \ {\n                (*this)[i][j] += a[i][j];\n            }\n        }\n   \
    \     return *this;\n    }\n    matrix &operator-=(const matrix& a) {\n      \
    \  assert(this->size() == a.size());\n        for (int i = 0; i < int(this->size());\
    \ i++) {\n            assert((*this)[i].size() == a[i].size());\n            for\
    \ (int j = 0; j < int((*this)[i].size()); j++) {\n                (*this)[i][j]\
    \ -= a[i][j];\n            }\n        }\n        return *this;\n    }\n    matrix\
    \ &operator*=(const matrix &a) {\n        int n = this->size(), m = a.size();\n\
    \        assert(m >= 1);\n        int l = a[0].size();\n        matrix res(n,\
    \ vector<mint>(l));\n        for (int i = 0; i < n; i++) {\n            assert(int((*this)[i].size())\
    \ == m);\n            for (int k = 0; k < m; k++) {\n                for (int\
    \ j = 0; j < l; j++) {\n                    res[i][j] += (*this)[i][k] * a[k][j];\n\
    \                }\n            }\n        }\n        return *this = res;\n  \
    \  }\n    matrix operator*(const mint &r) const { return matrix(*this) *= r; }\n\
    \    matrix operator/(const mint &r) const { return matrix(*this) /= r; }\n  \
    \  matrix operator+(const matrix &a) const { return matrix(*this) += a; }\n  \
    \  matrix operator-(const matrix &a) const { return matrix(*this) -= a; }\n  \
    \  matrix operator*(const matrix &a) const { return matrix(*this) *= a; }\n  \
    \  static constexpr matrix I(int n) {\n        matrix res(n, n);\n        for\
    \ (int i = 0; i < n; i++) {\n            res[i][i] = 1;\n        }\n        return\
    \ res;\n    }\n    static constexpr matrix O(int n) { return matrix(n, n); }\n\
    \    matrix pow(long long k) const {\n        matrix res = I(this->size()), a\
    \ = *this;\n        while (k > 0) {\n            if (k & 1) res *= a;\n      \
    \      a *= a;\n            k >>= 1;\n        }\n        return res;\n    }\n\
    \    mint det() const {\n        int n = this->size();\n        assert(n >= 1);\n\
    \        assert((*this)[0].size() == this->size());\n        mint res = 1;\n \
    \       matrix a = *this;\n        for (int i = 0; i < n; i++) {\n           \
    \ for (int j = i; j < n; j++) {\n                if (a[j][i] != 0) {\n       \
    \             if (i != j) res = -res;\n                    swap(a[i], a[j]);\n\
    \                    break;\n                }\n            }\n            if\
    \ (a[i][i] != 0) {\n                for (int j = i + 1; j < n; j++) {\n      \
    \              mint inv = a[j][i] * a[i][i].inv();\n                    for (int\
    \ k = i + 1; k < n; k++) {\n                        a[j][k] -= a[i][k] * inv;\n\
    \                    }\n                }\n            }\n        }\n        for\
    \ (int i = 0; i < n; i++) {\n            res *= a[i][i];\n        }\n        return\
    \ res;\n    }\n    matrix inv() const {\n        int n = this->size();\n     \
    \   matrix a = *this, res = I(n);\n        for (int i = 0; i < n; i++) {\n   \
    \         if (a[i][i] == 0) {\n                for (int j = i + 1; j < n; j++)\
    \ {\n                    if (a[j][i] != 0) {\n                        swap(a[i],\
    \ a[j]);\n                        swap(res[i], res[j]);\n                    \
    \    break;\n                    }\n                }\n            }\n       \
    \     assert(a[i][i] != 0);\n            mint cef = a[i][i].inv();\n         \
    \   for (int j = 0; j < n; j++) {\n                a[i][j] *= cef;\n         \
    \       res[i][j] *= cef;\n            }\n            for (int j = 0; j < n; j++)\
    \ {\n                if (j != i) {\n                    cef = a[j][i];\n     \
    \               for (int k = 0; k < n; k++) {\n                        a[j][k]\
    \ -= a[i][k] * cef;\n                        res[j][k] -= res[i][k] * cef;\n \
    \                   }\n                }\n            }\n        }\n        return\
    \ res;\n    }\n    int rank() const {\n        matrix a = *this;\n        int\
    \ h = a.size(), w = a[0].size();\n        int r = 0;\n        for (int j = 0;\
    \ j < w && r < h; j++) {\n            int i = r;\n            while (i < h &&\
    \ a[i][j] == 0) i++;\n            if (i == h) continue;\n            swap(a[r],\
    \ a[i]);\n            mint inv = a[r][j].inv();\n            for (i = r + 1; i\
    \ < h; i++) {\n                mint cef = a[i][j] * inv;\n                for\
    \ (int k = j; k < w; k++) {\n                    a[i][k] -= a[r][k] * cef;\n \
    \               }\n            }\n            r++;\n        }\n        return\
    \ r;\n    }\n};\n#line 4 \"src/graph/matrix_tree_theorem.hpp\"\n\ntemplate<typename\
    \ mint>\nmint matrix_tree_theorem_adjacency(const vector<vector<int>> &a, int\
    \ r = 0) {\n    int n = a.size();\n    if (n == 1) return 1;\n    auto p = [&](int\
    \ u) -> int {\n        return u - (u > r);\n    };\n    matrix<mint> b(n - 1,\
    \ n - 1);\n    for (int u = 0; u < n; u++) {\n        if (u == r) continue;\n\
    \        for (int v = 0; v < n; v++) {\n            b[p(u)][p(u)] += a[u][v];\n\
    \            if (v != r) {\n                b[p(u)][p(v)] -= a[u][v];\n      \
    \      }\n        }\n    }\n    return b.det();\n}\n\ntemplate<typename mint>\n\
    mint matrix_tree_theorem(const vector<vector<int>> &g, int r = 0) {\n    int n\
    \ = g.size();\n    vector<vector<int>> a(n, vector<int>(n));\n    for (int u =\
    \ 0; u < n; u++) {\n        for (int v : g[u]) a[u][v]++;\n    }\n    return matrix_tree_theorem_adjacency<mint>(a,\
    \ r);\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"../math/matrix/matrix_mint.hpp\"\
    \n\ntemplate<typename mint>\nmint matrix_tree_theorem_adjacency(const vector<vector<int>>\
    \ &a, int r = 0) {\n    int n = a.size();\n    if (n == 1) return 1;\n    auto\
    \ p = [&](int u) -> int {\n        return u - (u > r);\n    };\n    matrix<mint>\
    \ b(n - 1, n - 1);\n    for (int u = 0; u < n; u++) {\n        if (u == r) continue;\n\
    \        for (int v = 0; v < n; v++) {\n            b[p(u)][p(u)] += a[u][v];\n\
    \            if (v != r) {\n                b[p(u)][p(v)] -= a[u][v];\n      \
    \      }\n        }\n    }\n    return b.det();\n}\n\ntemplate<typename mint>\n\
    mint matrix_tree_theorem(const vector<vector<int>> &g, int r = 0) {\n    int n\
    \ = g.size();\n    vector<vector<int>> a(n, vector<int>(n));\n    for (int u =\
    \ 0; u < n; u++) {\n        for (int v : g[u]) a[u][v]++;\n    }\n    return matrix_tree_theorem_adjacency<mint>(a,\
    \ r);\n}"
  dependsOn:
  - src/math/matrix/matrix_mint.hpp
  isVerificationFile: false
  path: src/graph/matrix_tree_theorem.hpp
  requiredBy:
  - src/graph/best_theorem.hpp
  - src/graph/count_eulerian_trail.hpp
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/matrix_tree_theorem.hpp
layout: document
redirect_from:
- /library/src/graph/matrix_tree_theorem.hpp
- /library/src/graph/matrix_tree_theorem.hpp.html
title: src/graph/matrix_tree_theorem.hpp
---
