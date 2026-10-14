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
  bundledCode: "#line 2 \"src/math/matrix/matrix_with_array.hpp\"\n#include <array>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate<typename  mint, size_t sz>\n\
    struct matrix : array<array<mint, sz>, sz> {\n    using array<array<mint, sz>,\
    \ sz>::array;\n    static constexpr matrix O() {\n        matrix res;\n      \
    \  constexpr mint zero = 0;\n        for (int i = 0; i < sz; i++) {\n        \
    \    for (int j = 0; j <sz; j++) res[i][j] = zero;\n        }\n        return\
    \ res;\n    }\n    static constexpr matrix I() {\n        matrix res;\n      \
    \  constexpr mint zero = 0;\n        constexpr mint one = 1;\n        for (int\
    \ i = 0; i < sz; i++) {\n            for (int j = 0; j <sz; j++) res[i][j] = i\
    \ == j ? one : zero;\n        }\n        return res;\n    }\n    matrix &operator*=(const\
    \ mint &r) {\n        for (array<mint, sz> &v : *this) {\n            for (mint\
    \ &a : v) a *= r;\n        }\n        return *this;\n    }\n    matrix &operator/=(const\
    \ mint &r) {\n        mint invr = r.inv();\n        return *this *= invr;\n  \
    \  }\n    matrix &operator+=(const matrix& a) {\n        for (int i = 0; i < sz;\
    \ i++) {\n            for (int j = 0; j < sz; j++) {\n                (*this)[i][j]\
    \ += a[i][j];\n            }\n        }\n        return *this;\n    }\n    matrix\
    \ &operator-=(const matrix& a) {\n        for (int i = 0; i < sz; i++) {\n   \
    \         for (int j = 0; j < sz; j++) {\n                (*this)[i][j] -= a[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n    matrix &operator*=(const\
    \ matrix &a) {\n        matrix res = O();\n        for (int i = 0; i < sz; i++)\
    \ {\n            for (int k = 0; k < sz; k++) {\n                for (int j =\
    \ 0; j < sz; j++) {\n                    res[i][j] += (*this)[i][k] * a[k][j];\n\
    \                }\n            }\n        }\n        return *this = res;\n  \
    \  }\n    matrix operator*(const mint &r) const { return matrix(*this) *= r; }\n\
    \    matrix operator/(const mint &r) const { return matrix(*this) /= r; }\n  \
    \  matrix operator+(const matrix &a) const { return matrix(*this) += a; }\n  \
    \  matrix operator-(const matrix &a) const { return matrix(*this) -= a; }\n  \
    \  matrix operator*(const matrix &a) const { return matrix(*this) *= a; }\n  \
    \  matrix pow(long long k) const {\n        matrix res = I(this->size()), a =\
    \ *this;\n        while (k > 0) {\n            if (k & 1) res *= a;\n        \
    \    a *= a;\n            k >>= 1;\n        }\n        return res;\n    }\n  \
    \  mint det() const {\n        mint res = 1;\n        matrix a = *this;\n    \
    \    for (int i = 0; i < sz; i++) {\n            for (int j = i; j < sz; j++)\
    \ {\n                if (a[j][i] != 0) {\n                    if (i != j) res\
    \ = -res;\n                    swap(a[i], a[j]);\n                    break;\n\
    \                }\n            }\n            if (a[i][i] != 0) {\n         \
    \       for (int j = i + 1; j < sz; j++) {\n                    mint inv = a[j][i]\
    \ * a[i][i].inv();\n                    for (int k = i + 1; k < sz; k++) {\n \
    \                       a[j][k] -= a[i][k] * inv;\n                    }\n   \
    \             }\n            }\n        }\n        for (int i = 0; i < sz; i++)\
    \ {\n            res *= a[i][i];\n        }\n        return res;\n    }\n    matrix\
    \ inv() const {\n        matrix a = *this, res = I();\n        for (int i = 0;\
    \ i < sz; i++) {\n            if (a[i][i] == 0) {\n                for (int j\
    \ = i + 1; j < sz; j++) {\n                    if (a[j][i] != 0) {\n         \
    \               swap(a[i], a[j]);\n                        swap(res[i], res[j]);\n\
    \                        break;\n                    }\n                }\n  \
    \          }\n            assert(a[i][i] != 0);\n            mint cef = a[i][i].inv();\n\
    \            for (int j = 0; j < sz; j++) {\n                a[i][j] *= cef;\n\
    \                res[i][j] *= cef;\n            }\n            for (int j = 0;\
    \ j < sz; j++) {\n                if (j != i) {\n                    cef = a[j][i];\n\
    \                    for (int k = 0; k < sz; k++) {\n                        a[j][k]\
    \ -= a[i][k] * cef;\n                        res[j][k] -= res[i][k] * cef;\n \
    \                   }\n                }\n            }\n        }\n        return\
    \ res;\n    }\n    int rank() const {\n        matrix a = *this;\n        int\
    \ r = 0;\n        for (int j = 0; j < sz && r < sz; j++) {\n            int i\
    \ = r;\n            while (i < sz && a[i][j] == 0) i++;\n            if (i ==\
    \ sz) continue;\n            swap(a[r], a[i]);\n            mint inv = a[r][j].inv();\n\
    \            for (i = r + 1; i < sz; i++) {\n                mint cef = a[i][j]\
    \ * inv;\n                for (int k = j; k < sz; k++) {\n                   \
    \ a[i][k] -= a[r][k] * cef;\n                }\n            }\n            r++;\n\
    \        }\n        return r;\n    }\n};\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\nusing namespace std;\n\
    \ntemplate<typename  mint, size_t sz>\nstruct matrix : array<array<mint, sz>,\
    \ sz> {\n    using array<array<mint, sz>, sz>::array;\n    static constexpr matrix\
    \ O() {\n        matrix res;\n        constexpr mint zero = 0;\n        for (int\
    \ i = 0; i < sz; i++) {\n            for (int j = 0; j <sz; j++) res[i][j] = zero;\n\
    \        }\n        return res;\n    }\n    static constexpr matrix I() {\n  \
    \      matrix res;\n        constexpr mint zero = 0;\n        constexpr mint one\
    \ = 1;\n        for (int i = 0; i < sz; i++) {\n            for (int j = 0; j\
    \ <sz; j++) res[i][j] = i == j ? one : zero;\n        }\n        return res;\n\
    \    }\n    matrix &operator*=(const mint &r) {\n        for (array<mint, sz>\
    \ &v : *this) {\n            for (mint &a : v) a *= r;\n        }\n        return\
    \ *this;\n    }\n    matrix &operator/=(const mint &r) {\n        mint invr =\
    \ r.inv();\n        return *this *= invr;\n    }\n    matrix &operator+=(const\
    \ matrix& a) {\n        for (int i = 0; i < sz; i++) {\n            for (int j\
    \ = 0; j < sz; j++) {\n                (*this)[i][j] += a[i][j];\n           \
    \ }\n        }\n        return *this;\n    }\n    matrix &operator-=(const matrix&\
    \ a) {\n        for (int i = 0; i < sz; i++) {\n            for (int j = 0; j\
    \ < sz; j++) {\n                (*this)[i][j] -= a[i][j];\n            }\n   \
    \     }\n        return *this;\n    }\n    matrix &operator*=(const matrix &a)\
    \ {\n        matrix res = O();\n        for (int i = 0; i < sz; i++) {\n     \
    \       for (int k = 0; k < sz; k++) {\n                for (int j = 0; j < sz;\
    \ j++) {\n                    res[i][j] += (*this)[i][k] * a[k][j];\n        \
    \        }\n            }\n        }\n        return *this = res;\n    }\n   \
    \ matrix operator*(const mint &r) const { return matrix(*this) *= r; }\n    matrix\
    \ operator/(const mint &r) const { return matrix(*this) /= r; }\n    matrix operator+(const\
    \ matrix &a) const { return matrix(*this) += a; }\n    matrix operator-(const\
    \ matrix &a) const { return matrix(*this) -= a; }\n    matrix operator*(const\
    \ matrix &a) const { return matrix(*this) *= a; }\n    matrix pow(long long k)\
    \ const {\n        matrix res = I(this->size()), a = *this;\n        while (k\
    \ > 0) {\n            if (k & 1) res *= a;\n            a *= a;\n            k\
    \ >>= 1;\n        }\n        return res;\n    }\n    mint det() const {\n    \
    \    mint res = 1;\n        matrix a = *this;\n        for (int i = 0; i < sz;\
    \ i++) {\n            for (int j = i; j < sz; j++) {\n                if (a[j][i]\
    \ != 0) {\n                    if (i != j) res = -res;\n                    swap(a[i],\
    \ a[j]);\n                    break;\n                }\n            }\n     \
    \       if (a[i][i] != 0) {\n                for (int j = i + 1; j < sz; j++)\
    \ {\n                    mint inv = a[j][i] * a[i][i].inv();\n               \
    \     for (int k = i + 1; k < sz; k++) {\n                        a[j][k] -= a[i][k]\
    \ * inv;\n                    }\n                }\n            }\n        }\n\
    \        for (int i = 0; i < sz; i++) {\n            res *= a[i][i];\n       \
    \ }\n        return res;\n    }\n    matrix inv() const {\n        matrix a =\
    \ *this, res = I();\n        for (int i = 0; i < sz; i++) {\n            if (a[i][i]\
    \ == 0) {\n                for (int j = i + 1; j < sz; j++) {\n              \
    \      if (a[j][i] != 0) {\n                        swap(a[i], a[j]);\n      \
    \                  swap(res[i], res[j]);\n                        break;\n   \
    \                 }\n                }\n            }\n            assert(a[i][i]\
    \ != 0);\n            mint cef = a[i][i].inv();\n            for (int j = 0; j\
    \ < sz; j++) {\n                a[i][j] *= cef;\n                res[i][j] *=\
    \ cef;\n            }\n            for (int j = 0; j < sz; j++) {\n          \
    \      if (j != i) {\n                    cef = a[j][i];\n                   \
    \ for (int k = 0; k < sz; k++) {\n                        a[j][k] -= a[i][k] *\
    \ cef;\n                        res[j][k] -= res[i][k] * cef;\n              \
    \      }\n                }\n            }\n        }\n        return res;\n \
    \   }\n    int rank() const {\n        matrix a = *this;\n        int r = 0;\n\
    \        for (int j = 0; j < sz && r < sz; j++) {\n            int i = r;\n  \
    \          while (i < sz && a[i][j] == 0) i++;\n            if (i == sz) continue;\n\
    \            swap(a[r], a[i]);\n            mint inv = a[r][j].inv();\n      \
    \      for (i = r + 1; i < sz; i++) {\n                mint cef = a[i][j] * inv;\n\
    \                for (int k = j; k < sz; k++) {\n                    a[i][k] -=\
    \ a[r][k] * cef;\n                }\n            }\n            r++;\n       \
    \ }\n        return r;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/math/matrix/matrix_with_array.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/matrix/matrix_with_array.hpp
layout: document
redirect_from:
- /library/src/math/matrix/matrix_with_array.hpp
- /library/src/math/matrix/matrix_with_array.hpp.html
title: src/math/matrix/matrix_with_array.hpp
---
