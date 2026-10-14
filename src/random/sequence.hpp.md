---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/misc/even_distribution_array.hpp
    title: src/misc/even_distribution_array.hpp
  - icon: ':x:'
    path: src/random/utility.hpp
    title: src/random/utility.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/random/graph.hpp
    title: src/random/graph.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/fps/power_projection.test.cpp
    title: test/fps/power_projection.test.cpp
  - icon: ':x:'
    path: test/tree/centroid_decomposition.test.cpp
    title: test/tree/centroid_decomposition.test.cpp
  - icon: ':x:'
    path: test/tree/level_ancestor_offline.test.cpp
    title: test/tree/level_ancestor_offline.test.cpp
  - icon: ':x:'
    path: test/tree/prufer_code.test.cpp
    title: test/tree/prufer_code.test.cpp
  - icon: ':x:'
    path: test/tree/static_tree.auxiliary_tree.test.cpp
    title: test/tree/static_tree.auxiliary_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/random/sequence.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n#line 3 \"src/random/utility.hpp\"\n#include <concepts>\n\
    #include <random>\nusing namespace std;\n\nnamespace rng {\n\ninline random_device\
    \ seed;\ninline mt19937 eng(seed());\n\ntemplate<typename T>\nvoid set_seed(const\
    \ T &sd) {\n    eng.seed(sd);\n}\n\ntemplate<integral T>\ninline T randint(T lo,\
    \ T hi) {\n    assert(lo <= hi);\n    uniform_int_distribution<T> dist(lo, hi);\n\
    \    return dist(eng);\n}\n\ntemplate<integral T>\ninline pair<T, T> randpair(T\
    \ lo, T hi, bool strict = false) {\n    assert(lo + strict <= hi);\n    T l =\
    \ randint(lo, hi - strict);\n    T r = randint(l + strict, hi);\n    return make_pair(l,\
    \ r);\n}\n\n} // namespace rng\n#line 3 \"src/misc/even_distribution_array.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T>\nvector<T> even_distribution_array(const\
    \ vector<T> &v) {\n    int n = v.size();\n    long long sum = 0;\n    for (int\
    \ i = 0; i < n; i++) {\n        sum += v[i];\n    }\n    T q = sum / n, r = sum\
    \ % n;\n    vector<T> res(n, q);\n    for (int i = n - r; i < n; i++) res[i]++;\n\
    \    return res;\n}\n#line 7 \"src/random/sequence.hpp\"\nusing namespace std;\n\
    \nnamespace rng {\n\ntemplate<typename T>\nvoid shuffle(vector<T> &v) {\n    std::shuffle(v.begin(),\
    \ v.end(), eng);\n}\n\ntemplate<integral T>\ninline vector<T> random_sequence(int\
    \ n, T lo, T hi) {\n    assert(n >= 0);\n    vector<T> res(n);\n    for (int i\
    \ = 0; i < n; i++) res[i] = randint(lo, hi);\n    return res;\n}\n\ntemplate<integral\
    \ T>\ninline vector<T> random_increasing_sequence(int n, T lo, T hi, bool strict\
    \ = false) {\n    assert(n >= 0);\n    if (n == 0) return {};\n    assert(lo +\
    \ (n - 1) * strict <= hi);\n    vector<T> res = random_sequence(n, lo, hi - (n\
    \ - 1) * strict);\n    sort(res.begin(), res.end());\n    for (int i = 0; i <\
    \ n; i++) res[i] += i * strict;\n    return res;\n}\n\ntemplate<integral T>\n\
    inline vector<T> random_decreasing_sequence(int n, T lo, T hi, bool strict = false)\
    \ {\n    vector<T> res = random_increasing_sequence(n, lo, hi, strict);\n    reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n\ntemplate<integral T>\ninline vector<T> random_permutation(int\
    \ n, T val = 0) {\n    vector<T> res(n);\n    iota(res.begin(), res.end(), val);\n\
    \    shuffle(res);\n    return res;\n}\n\ninline string random_string(int n, char\
    \ a, char z) {\n    assert(a <= z);\n    string s(n, a);\n    for (auto &c : s)\
    \ c = randint((int)a, (int)z);\n    return s;\n}\n\n} // namespace rng\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    #include \"utility.hpp\"\n#include \"../misc/even_distribution_array.hpp\"\nusing\
    \ namespace std;\n\nnamespace rng {\n\ntemplate<typename T>\nvoid shuffle(vector<T>\
    \ &v) {\n    std::shuffle(v.begin(), v.end(), eng);\n}\n\ntemplate<integral T>\n\
    inline vector<T> random_sequence(int n, T lo, T hi) {\n    assert(n >= 0);\n \
    \   vector<T> res(n);\n    for (int i = 0; i < n; i++) res[i] = randint(lo, hi);\n\
    \    return res;\n}\n\ntemplate<integral T>\ninline vector<T> random_increasing_sequence(int\
    \ n, T lo, T hi, bool strict = false) {\n    assert(n >= 0);\n    if (n == 0)\
    \ return {};\n    assert(lo + (n - 1) * strict <= hi);\n    vector<T> res = random_sequence(n,\
    \ lo, hi - (n - 1) * strict);\n    sort(res.begin(), res.end());\n    for (int\
    \ i = 0; i < n; i++) res[i] += i * strict;\n    return res;\n}\n\ntemplate<integral\
    \ T>\ninline vector<T> random_decreasing_sequence(int n, T lo, T hi, bool strict\
    \ = false) {\n    vector<T> res = random_increasing_sequence(n, lo, hi, strict);\n\
    \    reverse(res.begin(), res.end());\n    return res;\n}\n\ntemplate<integral\
    \ T>\ninline vector<T> random_permutation(int n, T val = 0) {\n    vector<T> res(n);\n\
    \    iota(res.begin(), res.end(), val);\n    shuffle(res);\n    return res;\n\
    }\n\ninline string random_string(int n, char a, char z) {\n    assert(a <= z);\n\
    \    string s(n, a);\n    for (auto &c : s) c = randint((int)a, (int)z);\n   \
    \ return s;\n}\n\n} // namespace rng"
  dependsOn:
  - src/random/utility.hpp
  - src/misc/even_distribution_array.hpp
  isVerificationFile: false
  path: src/random/sequence.hpp
  requiredBy:
  - src/random/graph.hpp
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/fps/power_projection.test.cpp
  - test/tree/level_ancestor_offline.test.cpp
  - test/tree/prufer_code.test.cpp
  - test/tree/centroid_decomposition.test.cpp
  - test/tree/static_tree.auxiliary_tree.test.cpp
documentation_of: src/random/sequence.hpp
layout: document
redirect_from:
- /library/src/random/sequence.hpp
- /library/src/random/sequence.hpp.html
title: src/random/sequence.hpp
---
