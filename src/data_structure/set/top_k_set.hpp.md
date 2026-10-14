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
  bundledCode: "#line 2 \"src/data_structure/set/top_k_set.hpp\"\n#include <cassert>\n\
    #include <set>\nusing namespace std;\n\ntemplate<typename T1, typename T2 = long\
    \ long, typename Compare = less<T1>>\nstruct top_k_set {\n    top_k_set(int _k)\
    \ : k(_k), lower_sum(0) {}\n    void insert(T1 x) {\n        if (k > 0 && ((int)lower.size()\
    \ < k || Compare()(x, *prev(lower.end())))) {\n            lower_sum += x;\n \
    \           lower.insert(x);\n        } else {\n            upper.insert(x);\n\
    \        }\n        normalize();\n    }\n    void erase(T1 x) {\n        auto\
    \ it = lower.find(x);\n        if (it != lower.end()) {\n            lower_sum\
    \ -= *it;\n            lower.erase(it);\n        } else {\n            it = upper.find(x);\n\
    \            assert(it != upper.end());\n            upper.erase(it);\n      \
    \  }\n        normalize();\n    }\n    T1 kth_val() const {\n        assert((int)lower.size()\
    \ == k);\n        return *prev(lower.end());\n    }\n    T2 sum() const {\n  \
    \      return lower_sum;\n    }\nprivate:\n    int k;\n    multiset<T1, Compare>\
    \ lower, upper;\n    T2 lower_sum;\n    void normalize() {\n        while ((int)lower.size()\
    \ > k) {\n            auto it = prev(lower.end());\n            upper.insert(*it);\n\
    \            lower_sum -= *it;\n            lower.erase(it);\n        }\n    \
    \    while ((int)lower.size() < k && upper.size()) {\n            auto it = upper.begin();\n\
    \            lower_sum += *it;\n            lower.insert(*it);\n            upper.erase(it);\n\
    \        }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <set>\nusing namespace std;\n\n\
    template<typename T1, typename T2 = long long, typename Compare = less<T1>>\n\
    struct top_k_set {\n    top_k_set(int _k) : k(_k), lower_sum(0) {}\n    void insert(T1\
    \ x) {\n        if (k > 0 && ((int)lower.size() < k || Compare()(x, *prev(lower.end()))))\
    \ {\n            lower_sum += x;\n            lower.insert(x);\n        } else\
    \ {\n            upper.insert(x);\n        }\n        normalize();\n    }\n  \
    \  void erase(T1 x) {\n        auto it = lower.find(x);\n        if (it != lower.end())\
    \ {\n            lower_sum -= *it;\n            lower.erase(it);\n        } else\
    \ {\n            it = upper.find(x);\n            assert(it != upper.end());\n\
    \            upper.erase(it);\n        }\n        normalize();\n    }\n    T1\
    \ kth_val() const {\n        assert((int)lower.size() == k);\n        return *prev(lower.end());\n\
    \    }\n    T2 sum() const {\n        return lower_sum;\n    }\nprivate:\n   \
    \ int k;\n    multiset<T1, Compare> lower, upper;\n    T2 lower_sum;\n    void\
    \ normalize() {\n        while ((int)lower.size() > k) {\n            auto it\
    \ = prev(lower.end());\n            upper.insert(*it);\n            lower_sum\
    \ -= *it;\n            lower.erase(it);\n        }\n        while ((int)lower.size()\
    \ < k && upper.size()) {\n            auto it = upper.begin();\n            lower_sum\
    \ += *it;\n            lower.insert(*it);\n            upper.erase(it);\n    \
    \    }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/set/top_k_set.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/set/top_k_set.hpp
layout: document
redirect_from:
- /library/src/data_structure/set/top_k_set.hpp
- /library/src/data_structure/set/top_k_set.hpp.html
title: src/data_structure/set/top_k_set.hpp
---
