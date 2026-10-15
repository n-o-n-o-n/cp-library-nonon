---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/data_structure/segtree/reversible_segtree.hpp
    title: src/data_structure/segtree/reversible_segtree.hpp
  - icon: ':heavy_check_mark:'
    path: src/random/graph.hpp
    title: src/random/graph.hpp
  - icon: ':heavy_check_mark:'
    path: src/random/sequence.hpp
    title: src/random/sequence.hpp
  - icon: ':heavy_check_mark:'
    path: src/tree/hash_on_tree.hpp
    title: src/tree/hash_on_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_div_sparse.test.cpp
    title: test/fps/fps_div_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/power_projection.test.cpp
    title: test/fps/power_projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/discrete_logarithm.test.cpp
    title: test/math/number_theory/discrete_logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/mod_inv.test.cpp
    title: test/math/number_theory/mod_inv.test.cpp
  - icon: ':x:'
    path: test/math/number_theory/mod_pow.test.cpp
    title: test/math/number_theory/mod_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/prime_factor.test.cpp
    title: test/math/number_theory/prime_factor.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/totient_function.test.cpp
    title: test/math/number_theory/totient_function.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/centroid_decomposition.test.cpp
    title: test/tree/centroid_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/hash_on_tree.test.cpp
    title: test/tree/hash_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/level_ancestor_offline.test.cpp
    title: test/tree/level_ancestor_offline.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/prufer_code.test.cpp
    title: test/tree/prufer_code.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/static_tree.auxiliary_tree.test.cpp
    title: test/tree/static_tree.auxiliary_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/random/utility.hpp\"\n#include <cassert>\n#include <concepts>\n\
    #include <random>\nusing namespace std;\n\nnamespace rng {\n\ninline random_device\
    \ seed;\ninline mt19937 eng(seed());\n\ntemplate<typename T>\nvoid set_seed(const\
    \ T &sd) {\n    eng.seed(sd);\n}\n\ntemplate<integral T>\ninline T randint(T lo,\
    \ T hi) {\n    assert(lo <= hi);\n    uniform_int_distribution<T> dist(lo, hi);\n\
    \    return dist(eng);\n}\n\ntemplate<integral T>\ninline pair<T, T> randpair(T\
    \ lo, T hi, bool strict = false) {\n    assert(lo + strict <= hi);\n    T l =\
    \ randint(lo, hi - strict);\n    T r = randint(l + strict, hi);\n    return make_pair(l,\
    \ r);\n}\n\n} // namespace rng\n"
  code: "#pragma once\n#include <cassert>\n#include <concepts>\n#include <random>\n\
    using namespace std;\n\nnamespace rng {\n\ninline random_device seed;\ninline\
    \ mt19937 eng(seed());\n\ntemplate<typename T>\nvoid set_seed(const T &sd) {\n\
    \    eng.seed(sd);\n}\n\ntemplate<integral T>\ninline T randint(T lo, T hi) {\n\
    \    assert(lo <= hi);\n    uniform_int_distribution<T> dist(lo, hi);\n    return\
    \ dist(eng);\n}\n\ntemplate<integral T>\ninline pair<T, T> randpair(T lo, T hi,\
    \ bool strict = false) {\n    assert(lo + strict <= hi);\n    T l = randint(lo,\
    \ hi - strict);\n    T r = randint(l + strict, hi);\n    return make_pair(l, r);\n\
    }\n\n} // namespace rng"
  dependsOn: []
  isVerificationFile: false
  path: src/random/utility.hpp
  requiredBy:
  - src/data_structure/segtree/reversible_segtree.hpp
  - src/random/sequence.hpp
  - src/random/graph.hpp
  - src/tree/hash_on_tree.hpp
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/fps/power_projection.test.cpp
  - test/fps/fps_div_sparse.test.cpp
  - test/math/number_theory/discrete_logarithm.test.cpp
  - test/math/number_theory/prime_factor.test.cpp
  - test/math/number_theory/totient_function.test.cpp
  - test/math/number_theory/mod_inv.test.cpp
  - test/math/number_theory/mod_pow.test.cpp
  - test/tree/hash_on_tree.test.cpp
  - test/tree/level_ancestor_offline.test.cpp
  - test/tree/prufer_code.test.cpp
  - test/tree/centroid_decomposition.test.cpp
  - test/tree/static_tree.auxiliary_tree.test.cpp
documentation_of: src/random/utility.hpp
layout: document
redirect_from:
- /library/src/random/utility.hpp
- /library/src/random/utility.hpp.html
title: src/random/utility.hpp
---
