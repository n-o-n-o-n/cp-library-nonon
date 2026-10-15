---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/number_theory/mod_log.hpp
    title: src/math/number_theory/mod_log.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/discrete_logarithm.test.cpp
    title: test/math/number_theory/discrete_logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/mod_log.test.cpp
    title: test/math/number_theory/mod_log.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/number_theory/discrete_logarithm.hpp\"\n#include\
    \ <unordered_set>\nusing namespace std;\n\ntemplate<typename ActSet>\nstruct discrete_logarithm\
    \ {\n    using S = typename ActSet::S;\n    using F = typename ActSet::F;\n  \
    \  template<typename H>\n    static long long solve(F f, S s, S t, long long p,\
    \ const H &h) {\n        long long ht = h(t);\n        long long m = 1;\n    \
    \    do {\n            m++;\n        } while (m * m <= p);\n        unordered_set<long\
    \ long> a;\n        a.reserve(m);\n        for (int k = 0; k < m; k++) {\n   \
    \         t = ActSet::mapping(f, t);\n            a.insert(h(t));\n        }\n\
    \        F g = ActSet::id();\n        {\n            long long mm = m;\n     \
    \       F ff = f;\n            while (m > 0) {\n                if (m & 1) g =\
    \ ActSet::comp(g, f);\n                f = ActSet::comp(f, f);\n             \
    \   m >>= 1;\n            }\n            m = mm;\n            f = ff;\n      \
    \  }\n        for (int k = 0, flag = 0; k <= m; k++) {\n            t = ActSet::mapping(g,\
    \ s);\n            if (a.count(h(t))) {\n                for (int i = 0; i < m;\
    \ i++) {\n                    if (h(s) == ht) {\n                        return\
    \ m * k + i;\n                    }\n                    s = ActSet::mapping(f,\
    \ s);\n                }\n                if (flag) return -1;\n             \
    \   flag = 1;\n            }\n            s = t;\n        }\n        return -1;\n\
    \    }\n};\n"
  code: "#pragma once\n#include <unordered_set>\nusing namespace std;\n\ntemplate<typename\
    \ ActSet>\nstruct discrete_logarithm {\n    using S = typename ActSet::S;\n  \
    \  using F = typename ActSet::F;\n    template<typename H>\n    static long long\
    \ solve(F f, S s, S t, long long p, const H &h) {\n        long long ht = h(t);\n\
    \        long long m = 1;\n        do {\n            m++;\n        } while (m\
    \ * m <= p);\n        unordered_set<long long> a;\n        a.reserve(m);\n   \
    \     for (int k = 0; k < m; k++) {\n            t = ActSet::mapping(f, t);\n\
    \            a.insert(h(t));\n        }\n        F g = ActSet::id();\n       \
    \ {\n            long long mm = m;\n            F ff = f;\n            while (m\
    \ > 0) {\n                if (m & 1) g = ActSet::comp(g, f);\n               \
    \ f = ActSet::comp(f, f);\n                m >>= 1;\n            }\n         \
    \   m = mm;\n            f = ff;\n        }\n        for (int k = 0, flag = 0;\
    \ k <= m; k++) {\n            t = ActSet::mapping(g, s);\n            if (a.count(h(t)))\
    \ {\n                for (int i = 0; i < m; i++) {\n                    if (h(s)\
    \ == ht) {\n                        return m * k + i;\n                    }\n\
    \                    s = ActSet::mapping(f, s);\n                }\n         \
    \       if (flag) return -1;\n                flag = 1;\n            }\n     \
    \       s = t;\n        }\n        return -1;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/math/number_theory/discrete_logarithm.hpp
  requiredBy:
  - src/math/number_theory/mod_log.hpp
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/number_theory/discrete_logarithm.test.cpp
  - test/math/number_theory/mod_log.test.cpp
documentation_of: src/math/number_theory/discrete_logarithm.hpp
layout: document
redirect_from:
- /library/src/math/number_theory/discrete_logarithm.hpp
- /library/src/math/number_theory/discrete_logarithm.hpp.html
title: src/math/number_theory/discrete_logarithm.hpp
---
