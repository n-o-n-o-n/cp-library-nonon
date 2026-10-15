---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/enumerative_combinatorics/combination.hpp
    title: src/math/enumerative_combinatorics/combination.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/enumerative_combinatorics/prefix_binomial_sum_online.hpp\"\
    \n#include <vector>\nusing namespace std;\n#line 2 \"src/math/enumerative_combinatorics/combination.hpp\"\
    \n#include <algorithm>\n#include <cassert>\n#line 5 \"src/math/enumerative_combinatorics/combination.hpp\"\
    \nusing namespace std;\n\nnamespace combination {\n\ntemplate<typename mint>\n\
    struct container {\n    static vector<mint> fac, finv;\n    static void init(int\
    \ n) {\n        int sz = fac.size();\n        if (n < sz) return;\n        n =\
    \ clamp(n, 2 * sz, min<int>(1 << 27, mint::mod() - 1));\n        fac.resize(n\
    \ + 1);\n        finv.resize(n + 1);\n        for (int i = sz; i <= n; i++) {\n\
    \            fac[i] = i * fac[i - 1];\n        }\n        finv[n] = fac[n].inv();\n\
    \        for (int i = n; i >= sz; i--) {\n            finv[i - 1] = i * finv[i];\n\
    \        }\n    }\n};\n\ntemplate<typename mint>\nvector<mint> container<mint>::fac(1,\
    \ 1);\ntemplate<typename mint>\nvector<mint> container<mint>::finv(1, 1);\ntemplate<typename\
    \ mint>\nmint fac(int n) {\n    container<mint>::init(n);\n    if (n < 0) return\
    \ 0;\n    return container<mint>::fac[n];\n}\ntemplate<typename mint>\nmint finv(int\
    \ n) {\n    container<mint>::init(n);\n    if (n < 0) return 0;\n    return container<mint>::finv[n];\n\
    }\ntemplate<typename mint>\nmint mod_inv(int n) {\n    assert(n > 0);\n    return\
    \ finv<mint>(n) * fac<mint>(n - 1);\n}\ntemplate<typename mint>\nmint nCk(int\
    \ n, int k) {\n    if (n < 0) {\n        n = -n;\n        return nCk<mint>(n +\
    \ k - 1, n - 1);\n    }\n    if (n < k || k < 0) return 0;\n    return fac<mint>(n)\
    \ * finv<mint>(n - k) * finv<mint>(k);\n}\ntemplate<typename mint>\nmint multi_C(const\
    \ vector<int> &v) {\n    int n = 0;\n    for (const int &k : v) n += k;\n    mint\
    \ res = fac<mint>(n);\n    for (const int &k : v) res *= finv<mint>(k);\n    return\
    \ res;\n}\ntemplate<typename mint>\nmint nPk(int n, int k) {\n    if (n < 0 ||\
    \ n < k || k < 0) return 0;\n    return fac<mint>(n) * finv<mint>(n - k);\n}\n\
    template<typename mint>\nmint catalan(int n) {\n    return fac<mint>(2 * n) *\
    \ finv<mint>(n) * finv<mint>(n + 1);\n}\ntemplate<typename mint>\nmint grid_path(int\
    \ n, int m) {\n    return nCk<mint>(n + m, n);\n}\n\n} // namespace combination\n\
    #line 5 \"src/math/enumerative_combinatorics/prefix_binomial_sum_online.hpp\"\n\
    \ntemplate<typename mint>\nstruct prefix_binomial_sum {\n    prefix_binomial_sum(int\
    \ n) : size(n), b(400) { build(); }\n    mint get(int n, int k) const {\n    \
    \    assert(0 <= n && n <= size);\n        int tn = (n + b / 2) / b;\n       \
    \ int tk = (k + b / 2) / b;\n        mint res = table[tn][tk];\n        tn *=\
    \ b;\n        tk *= b;\n        while (tk < k) res = res + combination::nCk<mint>(tn,\
    \ ++tk);\n        while (tk > k) res = res - combination::nCk<mint>(tn, tk--);\n\
    \        while (tn < n) res = 2 * res - combination::nCk<mint>(tn++, tk);\n  \
    \      while (tn > n) res = (res + combination::nCk<mint>(--tn, tk)) * inv2;\n\
    \        return res;\n    }\nprivate:\n    int size, b;\n    mint inv2;\n    vector<vector<mint>>\
    \ table;\n    void build() {\n        size += b;\n        inv2 = mint::raw(2).inv();\n\
    \        int n = (size + b - 1) / b;\n        table.resize(n + 1);\n        for\
    \ (int i = 0; i <= n; i++) {\n            table[i].resize(n + 1);\n          \
    \  table[i][0] = 1;\n            mint cur = 1;\n            for (int j = 1; j\
    \ <= n * b; j++) {\n                cur += combination::nCk<mint>(b * i, j);\n\
    \                if (j % b == 0) {\n                    table[i][j / b] = cur;\n\
    \                }\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n#include \"combination.hpp\"\
    \n\ntemplate<typename mint>\nstruct prefix_binomial_sum {\n    prefix_binomial_sum(int\
    \ n) : size(n), b(400) { build(); }\n    mint get(int n, int k) const {\n    \
    \    assert(0 <= n && n <= size);\n        int tn = (n + b / 2) / b;\n       \
    \ int tk = (k + b / 2) / b;\n        mint res = table[tn][tk];\n        tn *=\
    \ b;\n        tk *= b;\n        while (tk < k) res = res + combination::nCk<mint>(tn,\
    \ ++tk);\n        while (tk > k) res = res - combination::nCk<mint>(tn, tk--);\n\
    \        while (tn < n) res = 2 * res - combination::nCk<mint>(tn++, tk);\n  \
    \      while (tn > n) res = (res + combination::nCk<mint>(--tn, tk)) * inv2;\n\
    \        return res;\n    }\nprivate:\n    int size, b;\n    mint inv2;\n    vector<vector<mint>>\
    \ table;\n    void build() {\n        size += b;\n        inv2 = mint::raw(2).inv();\n\
    \        int n = (size + b - 1) / b;\n        table.resize(n + 1);\n        for\
    \ (int i = 0; i <= n; i++) {\n            table[i].resize(n + 1);\n          \
    \  table[i][0] = 1;\n            mint cur = 1;\n            for (int j = 1; j\
    \ <= n * b; j++) {\n                cur += combination::nCk<mint>(b * i, j);\n\
    \                if (j % b == 0) {\n                    table[i][j / b] = cur;\n\
    \                }\n            }\n        }\n    }\n};"
  dependsOn:
  - src/math/enumerative_combinatorics/combination.hpp
  isVerificationFile: false
  path: src/math/enumerative_combinatorics/prefix_binomial_sum_online.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/enumerative_combinatorics/prefix_binomial_sum_online.hpp
layout: document
redirect_from:
- /library/src/math/enumerative_combinatorics/prefix_binomial_sum_online.hpp
- /library/src/math/enumerative_combinatorics/prefix_binomial_sum_online.hpp.html
title: src/math/enumerative_combinatorics/prefix_binomial_sum_online.hpp
---
