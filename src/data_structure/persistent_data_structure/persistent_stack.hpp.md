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
  bundledCode: "#line 2 \"src/data_structure/persistent_data_structure/persistent_stack.hpp\"\
    \n#include <cassert>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ T>\nstruct persistent_stack {\n    persistent_stack() : sz(1, 0), roots(1, -1)\
    \ {}\n    // n: the number of 'push' query\n    // q: the number of 'pop' query\n\
    \    void reserve(int n, int q = 0) {\n        d.reserve(n);\n        prev.reserve(n);\n\
    \        sz.reserve(n + q + 1);\n        roots.reserve(n + q + 1);\n    }\n  \
    \  int size(int k) const {\n        assert(0 <= k && k < ssize(roots));\n    \
    \    return sz[k];\n    }\n    T top(int k) const {\n        assert(0 <= k &&\
    \ k < ssize(roots));\n        assert(roots[k] != -1);\n        return d[roots[k]];\n\
    \    }\n    int pop(int k) {\n        assert(0 <= k && k < ssize(roots));\n  \
    \      int res = roots.size();\n        if (roots[k] == -1) {\n            sz.push_back(0);\n\
    \            roots.push_back(-1);\n        } else {\n            sz.push_back(sz[k]\
    \ - 1);\n            roots.push_back(prev[roots[k]]);\n        }\n        return\
    \ res;\n    }\n    int push(int k, const T &x) {\n        assert(0 <= k && k <\
    \ ssize(roots));\n        int res = roots.size();\n        roots.push_back(d.size());\n\
    \        prev.push_back(roots[k]);\n        sz.push_back(sz[k] + 1);\n       \
    \ d.push_back(x);\n        return res;\n    }\nprivate:\n    vector<int> prev,\
    \ sz, roots;\n    vector<T> d;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename T>\nstruct persistent_stack {\n    persistent_stack() : sz(1,\
    \ 0), roots(1, -1) {}\n    // n: the number of 'push' query\n    // q: the number\
    \ of 'pop' query\n    void reserve(int n, int q = 0) {\n        d.reserve(n);\n\
    \        prev.reserve(n);\n        sz.reserve(n + q + 1);\n        roots.reserve(n\
    \ + q + 1);\n    }\n    int size(int k) const {\n        assert(0 <= k && k <\
    \ ssize(roots));\n        return sz[k];\n    }\n    T top(int k) const {\n   \
    \     assert(0 <= k && k < ssize(roots));\n        assert(roots[k] != -1);\n \
    \       return d[roots[k]];\n    }\n    int pop(int k) {\n        assert(0 <=\
    \ k && k < ssize(roots));\n        int res = roots.size();\n        if (roots[k]\
    \ == -1) {\n            sz.push_back(0);\n            roots.push_back(-1);\n \
    \       } else {\n            sz.push_back(sz[k] - 1);\n            roots.push_back(prev[roots[k]]);\n\
    \        }\n        return res;\n    }\n    int push(int k, const T &x) {\n  \
    \      assert(0 <= k && k < ssize(roots));\n        int res = roots.size();\n\
    \        roots.push_back(d.size());\n        prev.push_back(roots[k]);\n     \
    \   sz.push_back(sz[k] + 1);\n        d.push_back(x);\n        return res;\n \
    \   }\nprivate:\n    vector<int> prev, sz, roots;\n    vector<T> d;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/persistent_data_structure/persistent_stack.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/persistent_data_structure/persistent_stack.hpp
layout: document
redirect_from:
- /library/src/data_structure/persistent_data_structure/persistent_stack.hpp
- /library/src/data_structure/persistent_data_structure/persistent_stack.hpp.html
title: src/data_structure/persistent_data_structure/persistent_stack.hpp
---
