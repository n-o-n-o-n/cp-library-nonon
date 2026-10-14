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
  bundledCode: "#line 2 \"src/data_structure/set/median_set.hpp\"\n#include <cassert>\n\
    #include <set>\nusing namespace std;\n\ntemplate<typename T1, typename T2 = long\
    \ long>\nstruct median_set {\n    median_set() : upper_sum(0), lower_sum(0) {}\n\
    \    void insert(T1 x) {\n        if (lower.empty() || x <= *prev(lower.end()))\
    \ {\n            lower_sum += x;\n            lower.insert(x);\n        } else\
    \ {\n            upper_sum += x;\n            upper.insert(x);\n        }\n  \
    \      normalize();\n    }\n    void erase(T1 x) {\n        auto it = lower.find(x);\n\
    \        if (it != lower.end()) {\n            lower_sum -= *it;\n           \
    \ lower.erase(it);\n        } else {\n            it = upper.find(x);\n      \
    \      assert(it != upper.end());\n            upper_sum -= *it;\n           \
    \ upper.erase(it);\n        }\n        normalize();\n    }\n    T1 median() const\
    \ {\n        assert(lower.size());\n        return *prev(lower.end());\n    }\n\
    \    T2 min_cost() const {\n        T2 med = median();\n        return (upper_sum\
    \ - med * upper.size()) + (med * lower.size() - lower_sum);\n    }\nprivate:\n\
    \    multiset<T1> upper, lower;\n    T2 upper_sum, lower_sum;\n    void normalize()\
    \ {\n        while (lower.size() > upper.size() + 1) {\n            auto it =\
    \ prev(lower.end());\n            upper_sum += *it;\n            upper.insert(*it);\n\
    \            lower_sum -= *it;\n            lower.erase(it);\n        }\n    \
    \    while (lower.size() < upper.size()) {\n            auto it = upper.begin();\n\
    \            lower_sum += *it;\n            lower.insert(*it);\n            upper_sum\
    \ -= *it;\n            upper.erase(it);\n        }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <set>\nusing namespace std;\n\n\
    template<typename T1, typename T2 = long long>\nstruct median_set {\n    median_set()\
    \ : upper_sum(0), lower_sum(0) {}\n    void insert(T1 x) {\n        if (lower.empty()\
    \ || x <= *prev(lower.end())) {\n            lower_sum += x;\n            lower.insert(x);\n\
    \        } else {\n            upper_sum += x;\n            upper.insert(x);\n\
    \        }\n        normalize();\n    }\n    void erase(T1 x) {\n        auto\
    \ it = lower.find(x);\n        if (it != lower.end()) {\n            lower_sum\
    \ -= *it;\n            lower.erase(it);\n        } else {\n            it = upper.find(x);\n\
    \            assert(it != upper.end());\n            upper_sum -= *it;\n     \
    \       upper.erase(it);\n        }\n        normalize();\n    }\n    T1 median()\
    \ const {\n        assert(lower.size());\n        return *prev(lower.end());\n\
    \    }\n    T2 min_cost() const {\n        T2 med = median();\n        return\
    \ (upper_sum - med * upper.size()) + (med * lower.size() - lower_sum);\n    }\n\
    private:\n    multiset<T1> upper, lower;\n    T2 upper_sum, lower_sum;\n    void\
    \ normalize() {\n        while (lower.size() > upper.size() + 1) {\n         \
    \   auto it = prev(lower.end());\n            upper_sum += *it;\n            upper.insert(*it);\n\
    \            lower_sum -= *it;\n            lower.erase(it);\n        }\n    \
    \    while (lower.size() < upper.size()) {\n            auto it = upper.begin();\n\
    \            lower_sum += *it;\n            lower.insert(*it);\n            upper_sum\
    \ -= *it;\n            upper.erase(it);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/set/median_set.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/set/median_set.hpp
layout: document
redirect_from:
- /library/src/data_structure/set/median_set.hpp
- /library/src/data_structure/set/median_set.hpp.html
title: src/data_structure/set/median_set.hpp
---
