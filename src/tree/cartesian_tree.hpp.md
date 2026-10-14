---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/cartesian_tree.test.cpp
    title: test/tree/cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/cartesian_tree.hpp\"\n#include <stack>\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate<typename T>\nvector<int> cartesian_tree(const\
    \ vector<T> &a) {\n    int n = a.size();\n    vector<int> p(n, -1);\n    stack<int>\
    \ st;\n    for (int i = 0, j; i < n; i++) {\n        j = -1;\n        while (st.size()\
    \ && a[st.top()] >= a[i]) {\n            j = st.top();\n            st.pop();\n\
    \        }\n        if (st.size()) p[i] = st.top();\n        if (j != -1) p[j]\
    \ = i;\n        st.push(i);\n    }\n    return p;\n}\n"
  code: "#pragma once\n#include <stack>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename T>\nvector<int> cartesian_tree(const vector<T> &a) {\n   \
    \ int n = a.size();\n    vector<int> p(n, -1);\n    stack<int> st;\n    for (int\
    \ i = 0, j; i < n; i++) {\n        j = -1;\n        while (st.size() && a[st.top()]\
    \ >= a[i]) {\n            j = st.top();\n            st.pop();\n        }\n  \
    \      if (st.size()) p[i] = st.top();\n        if (j != -1) p[j] = i;\n     \
    \   st.push(i);\n    }\n    return p;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/cartesian_tree.test.cpp
documentation_of: src/tree/cartesian_tree.hpp
layout: document
redirect_from:
- /library/src/tree/cartesian_tree.hpp
- /library/src/tree/cartesian_tree.hpp.html
title: src/tree/cartesian_tree.hpp
---
