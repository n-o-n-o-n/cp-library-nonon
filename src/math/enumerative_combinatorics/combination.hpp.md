---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/fps/fps.hpp
    title: src/fps/fps.hpp
  - icon: ':warning:'
    path: src/fps/fps_all.hpp
    title: src/fps/fps_all.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/fps_compositional_inverse.hpp
    title: src/fps/fps_compositional_inverse.hpp
  - icon: ':x:'
    path: src/fps/fps_composotion.hpp
    title: src/fps/fps_composotion.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/fps_exp.hpp
    title: src/fps/fps_exp.hpp
  - icon: ':question:'
    path: src/fps/fps_inv.hpp
    title: src/fps/fps_inv.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/fps_log.hpp
    title: src/fps/fps_log.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/fps_pow.hpp
    title: src/fps/fps_pow.hpp
  - icon: ':warning:'
    path: src/fps/fps_product.hpp
    title: src/fps/fps_product.hpp
  - icon: ':x:'
    path: src/fps/multipoint_evaluation.hpp
    title: src/fps/multipoint_evaluation.hpp
  - icon: ':warning:'
    path: src/fps/multipoint_evaluation_geometric.hpp
    title: src/fps/multipoint_evaluation_geometric.hpp
  - icon: ':x:'
    path: src/fps/polynomial_interpolation.hpp
    title: src/fps/polynomial_interpolation.hpp
  - icon: ':heavy_check_mark:'
    path: src/fps/polynomial_taylor_shift.hpp
    title: src/fps/polynomial_taylor_shift.hpp
  - icon: ':question:'
    path: src/fps/power_projection.hpp
    title: src/fps/power_projection.hpp
  - icon: ':x:'
    path: src/fps/rational_sum.hpp
    title: src/fps/rational_sum.hpp
  - icon: ':x:'
    path: src/fps/subprod_tree.hpp
    title: src/fps/subprod_tree.hpp
  - icon: ':warning:'
    path: src/graph/best_theorem.hpp
    title: src/graph/best_theorem.hpp
  - icon: ':warning:'
    path: src/graph/count_eulerian_trail.hpp
    title: src/graph/count_eulerian_trail.hpp
  - icon: ':warning:'
    path: src/math/bmbm.hpp
    title: src/math/bmbm.hpp
  - icon: ':warning:'
    path: src/math/bostan_mori.hpp
    title: src/math/bostan_mori.hpp
  - icon: ':warning:'
    path: src/math/enumerative_combinatorics/enumerate_powers_of_sums.hpp
    title: src/math/enumerative_combinatorics/enumerate_powers_of_sums.hpp
  - icon: ':warning:'
    path: src/math/enumerative_combinatorics/partition.hpp
    title: src/math/enumerative_combinatorics/partition.hpp
  - icon: ':warning:'
    path: src/math/enumerative_combinatorics/power_sum.hpp
    title: src/math/enumerative_combinatorics/power_sum.hpp
  - icon: ':warning:'
    path: src/math/enumerative_combinatorics/prefix_binomial_sum_online.hpp
    title: src/math/enumerative_combinatorics/prefix_binomial_sum_online.hpp
  - icon: ':warning:'
    path: src/math/enumerative_combinatorics/stirling2_k_fixed.hpp
    title: src/math/enumerative_combinatorics/stirling2_k_fixed.hpp
  - icon: ':warning:'
    path: src/math/enumerative_combinatorics/stirling2_n_fixed.hpp
    title: src/math/enumerative_combinatorics/stirling2_n_fixed.hpp
  - icon: ':warning:'
    path: src/math/enumerative_combinatorics/subset_sum.hpp
    title: src/math/enumerative_combinatorics/subset_sum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_compositional_inverse.test.cpp
    title: test/fps/fps_compositional_inverse.test.cpp
  - icon: ':x:'
    path: test/fps/fps_composotion.test.cpp
    title: test/fps/fps_composotion.test.cpp
  - icon: ':x:'
    path: test/fps/fps_div_sparse.test.cpp
    title: test/fps/fps_div_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_exp.test.cpp
    title: test/fps/fps_exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_inv.test.cpp
    title: test/fps/fps_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_log.test.cpp
    title: test/fps/fps_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_pow.test.cpp
    title: test/fps/fps_pow.test.cpp
  - icon: ':x:'
    path: test/fps/multipoint_evaluation.test.cpp
    title: test/fps/multipoint_evaluation.test.cpp
  - icon: ':x:'
    path: test/fps/polynomial_interpolation.test.cpp
    title: test/fps/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/polynomial_taylor_shift.test.cpp
    title: test/fps/polynomial_taylor_shift.test.cpp
  - icon: ':x:'
    path: test/fps/power_projection.test.cpp
    title: test/fps/power_projection.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/enumerative_combinatorics/combination.hpp\"\n#include\
    \ <algorithm>\n#include <cassert>\n#include <vector>\nusing namespace std;\n\n\
    namespace combination {\n\ntemplate<typename mint>\nstruct container {\n    static\
    \ vector<mint> fac, finv;\n    static void init(int n) {\n        int sz = fac.size();\n\
    \        if (n < sz) return;\n        n = clamp(n, 2 * sz, min<int>(1 << 27, mint::mod()\
    \ - 1));\n        fac.resize(n + 1);\n        finv.resize(n + 1);\n        for\
    \ (int i = sz; i <= n; i++) {\n            fac[i] = i * fac[i - 1];\n        }\n\
    \        finv[n] = fac[n].inv();\n        for (int i = n; i >= sz; i--) {\n  \
    \          finv[i - 1] = i * finv[i];\n        }\n    }\n};\n\ntemplate<typename\
    \ mint>\nvector<mint> container<mint>::fac(1, 1);\ntemplate<typename mint>\nvector<mint>\
    \ container<mint>::finv(1, 1);\ntemplate<typename mint>\nmint fac(int n) {\n \
    \   container<mint>::init(n);\n    if (n < 0) return 0;\n    return container<mint>::fac[n];\n\
    }\ntemplate<typename mint>\nmint finv(int n) {\n    container<mint>::init(n);\n\
    \    if (n < 0) return 0;\n    return container<mint>::finv[n];\n}\ntemplate<typename\
    \ mint>\nmint mod_inv(int n) {\n    assert(n > 0);\n    return finv<mint>(n) *\
    \ fac<mint>(n - 1);\n}\ntemplate<typename mint>\nmint nCk(int n, int k) {\n  \
    \  if (n < 0) {\n        n = -n;\n        return nCk<mint>(n + k - 1, n - 1);\n\
    \    }\n    if (n < k || k < 0) return 0;\n    return fac<mint>(n) * finv<mint>(n\
    \ - k) * finv<mint>(k);\n}\ntemplate<typename mint>\nmint multi_C(const vector<int>\
    \ &v) {\n    int n = 0;\n    for (const int &k : v) n += k;\n    mint res = fac<mint>(n);\n\
    \    for (const int &k : v) res *= finv<mint>(k);\n    return res;\n}\ntemplate<typename\
    \ mint>\nmint nPk(int n, int k) {\n    if (n < 0 || n < k || k < 0) return 0;\n\
    \    return fac<mint>(n) * finv<mint>(n - k);\n}\ntemplate<typename mint>\nmint\
    \ catalan(int n) {\n    return fac<mint>(2 * n) * finv<mint>(n) * finv<mint>(n\
    \ + 1);\n}\ntemplate<typename mint>\nmint grid_path(int n, int m) {\n    return\
    \ nCk<mint>(n + m, n);\n}\n\n} // namespace combination\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    using namespace std;\n\nnamespace combination {\n\ntemplate<typename mint>\nstruct\
    \ container {\n    static vector<mint> fac, finv;\n    static void init(int n)\
    \ {\n        int sz = fac.size();\n        if (n < sz) return;\n        n = clamp(n,\
    \ 2 * sz, min<int>(1 << 27, mint::mod() - 1));\n        fac.resize(n + 1);\n \
    \       finv.resize(n + 1);\n        for (int i = sz; i <= n; i++) {\n       \
    \     fac[i] = i * fac[i - 1];\n        }\n        finv[n] = fac[n].inv();\n \
    \       for (int i = n; i >= sz; i--) {\n            finv[i - 1] = i * finv[i];\n\
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
    \ n, int m) {\n    return nCk<mint>(n + m, n);\n}\n\n} // namespace combination"
  dependsOn: []
  isVerificationFile: false
  path: src/math/enumerative_combinatorics/combination.hpp
  requiredBy:
  - src/fps/fps_product.hpp
  - src/fps/fps.hpp
  - src/fps/fps_exp.hpp
  - src/fps/fps_composotion.hpp
  - src/fps/multipoint_evaluation_geometric.hpp
  - src/fps/fps_all.hpp
  - src/fps/fps_inv.hpp
  - src/fps/subprod_tree.hpp
  - src/fps/polynomial_interpolation.hpp
  - src/fps/power_projection.hpp
  - src/fps/multipoint_evaluation.hpp
  - src/fps/polynomial_taylor_shift.hpp
  - src/fps/fps_log.hpp
  - src/fps/fps_pow.hpp
  - src/fps/fps_compositional_inverse.hpp
  - src/fps/rational_sum.hpp
  - src/graph/best_theorem.hpp
  - src/graph/count_eulerian_trail.hpp
  - src/math/bmbm.hpp
  - src/math/bostan_mori.hpp
  - src/math/enumerative_combinatorics/prefix_binomial_sum_online.hpp
  - src/math/enumerative_combinatorics/subset_sum.hpp
  - src/math/enumerative_combinatorics/stirling2_n_fixed.hpp
  - src/math/enumerative_combinatorics/power_sum.hpp
  - src/math/enumerative_combinatorics/partition.hpp
  - src/math/enumerative_combinatorics/stirling2_k_fixed.hpp
  - src/math/enumerative_combinatorics/enumerate_powers_of_sums.hpp
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/fps/fps_log.test.cpp
  - test/fps/multipoint_evaluation.test.cpp
  - test/fps/fps_pow.test.cpp
  - test/fps/fps_composotion.test.cpp
  - test/fps/power_projection.test.cpp
  - test/fps/polynomial_interpolation.test.cpp
  - test/fps/fps_inv.test.cpp
  - test/fps/fps_div_sparse.test.cpp
  - test/fps/fps_compositional_inverse.test.cpp
  - test/fps/fps_exp.test.cpp
  - test/fps/polynomial_taylor_shift.test.cpp
documentation_of: src/math/enumerative_combinatorics/combination.hpp
layout: document
redirect_from:
- /library/src/math/enumerative_combinatorics/combination.hpp
- /library/src/math/enumerative_combinatorics/combination.hpp.html
title: src/math/enumerative_combinatorics/combination.hpp
---
