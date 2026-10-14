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
  bundledCode: "#line 2 \"src/data_structure/persistent_data_structure/persistent_array.hpp\"\
    \n#include <array>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ T, int ary = 2>\nstruct persistent_array {\n    static_assert((ary & (ary -\
    \ 1)) == 0, \"k must be pow of 2\");\n    persistent_array() {}\n    persistent_array(int\
    \ n, const T &x) : persistent_array(vector<T>(n, x)) {}\n    persistent_array(const\
    \ vector<T> &a) {\n        int n = a.size();\n    }\n    int set(int k, int p,\
    \ const T &x) {}\nprivate:\n    static constexpr int mask = ary - 1;\n    struct\
    \ node {\n        node() : x(-1), par(-1) { ch.fill(-1); }\n        int x, par;\n\
    \        array<int, ary> ch;\n    };\n    vector<node> d;\n    vector<int> roots;\n\
    \    vector<T> vals;\n    T val(int p) { return d[p].x == -1 ? T() : vals[d[p].x];\
    \ }\n};\n"
  code: "#pragma once\n#include <array>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename T, int ary = 2>\nstruct persistent_array {\n    static_assert((ary\
    \ & (ary - 1)) == 0, \"k must be pow of 2\");\n    persistent_array() {}\n   \
    \ persistent_array(int n, const T &x) : persistent_array(vector<T>(n, x)) {}\n\
    \    persistent_array(const vector<T> &a) {\n        int n = a.size();\n    }\n\
    \    int set(int k, int p, const T &x) {}\nprivate:\n    static constexpr int\
    \ mask = ary - 1;\n    struct node {\n        node() : x(-1), par(-1) { ch.fill(-1);\
    \ }\n        int x, par;\n        array<int, ary> ch;\n    };\n    vector<node>\
    \ d;\n    vector<int> roots;\n    vector<T> vals;\n    T val(int p) { return d[p].x\
    \ == -1 ? T() : vals[d[p].x]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/persistent_data_structure/persistent_array.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/persistent_data_structure/persistent_array.hpp
layout: document
redirect_from:
- /library/src/data_structure/persistent_data_structure/persistent_array.hpp
- /library/src/data_structure/persistent_data_structure/persistent_array.hpp.html
title: src/data_structure/persistent_data_structure/persistent_array.hpp
---
