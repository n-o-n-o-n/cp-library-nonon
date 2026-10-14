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
  bundledCode: "#line 2 \"src/data_structure/misc/dswag.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <stack>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename Monoid>\nstruct dswag {\n    using S = typename Monoid::S;\n\
    \    dswag() = default;\n    size_t size() const { return f1.size() + b1.size();\
    \ }\n    bool empty() const { return size() == 0; }\n    S get() const { return\
    \ Monoid::op(get_f(), get_b()); }\n    void push_front(const S &x) { push_f(x);\
    \ }\n    void push_back(const S &x) { push_b(x); }\n    void pop_front() {\n \
    \       assert(size());\n        if (f1.empty()) normalize();\n        pop_f();\n\
    \    }\n    void pop_back() {\n        assert(size());\n        if (b1.empty())\
    \ normalize();\n        pop_b();\n    }\nprivate:\n    stack<S> f1, f2, b1, b2;\n\
    \    void normalize() {\n        int n = size();\n        int m = n / 2 + (f1.size()\
    \ ? 0 : n & 1);\n        vector<S> f, b;\n        while (f1.size()) {\n      \
    \      f.push_back(f1.top());\n            pop_f();\n        }\n        while\
    \ (b1.size()) {\n            b.push_back(b1.top());\n            pop_b();\n  \
    \      }\n        reverse(b.begin(), b.end());\n        copy(b.begin(), b.end(),\
    \ back_inserter(f));\n        for (int i = m - 1; i >= 0; i--) push_f(f[i]);\n\
    \        for (int i = m; i < n; i++) push_b(f[i]);\n    }\n    S get_f() const\
    \ { return f2.size() ? f2.top() : Monoid::e(); }\n    S get_b() const { return\
    \ b2.size() ? b2.top() : Monoid::e(); }\n    void push_f(const S &x) {\n     \
    \   auto y = get_f();\n        f1.push(x);\n        f2.push(Monoid::op(x, y));\n\
    \    }\n    void push_b(const S &x) {\n        auto y = get_b();\n        b1.push(x);\n\
    \        b2.push(Monoid::op(y, x));\n    }\n    void pop_f() {\n        f1.pop();\n\
    \        f2.pop();\n    }\n    void pop_b() {\n        b1.pop();\n        b2.pop();\n\
    \    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <stack>\n\
    #include <vector>\nusing namespace std;\n\ntemplate<typename Monoid>\nstruct dswag\
    \ {\n    using S = typename Monoid::S;\n    dswag() = default;\n    size_t size()\
    \ const { return f1.size() + b1.size(); }\n    bool empty() const { return size()\
    \ == 0; }\n    S get() const { return Monoid::op(get_f(), get_b()); }\n    void\
    \ push_front(const S &x) { push_f(x); }\n    void push_back(const S &x) { push_b(x);\
    \ }\n    void pop_front() {\n        assert(size());\n        if (f1.empty())\
    \ normalize();\n        pop_f();\n    }\n    void pop_back() {\n        assert(size());\n\
    \        if (b1.empty()) normalize();\n        pop_b();\n    }\nprivate:\n   \
    \ stack<S> f1, f2, b1, b2;\n    void normalize() {\n        int n = size();\n\
    \        int m = n / 2 + (f1.size() ? 0 : n & 1);\n        vector<S> f, b;\n \
    \       while (f1.size()) {\n            f.push_back(f1.top());\n            pop_f();\n\
    \        }\n        while (b1.size()) {\n            b.push_back(b1.top());\n\
    \            pop_b();\n        }\n        reverse(b.begin(), b.end());\n     \
    \   copy(b.begin(), b.end(), back_inserter(f));\n        for (int i = m - 1; i\
    \ >= 0; i--) push_f(f[i]);\n        for (int i = m; i < n; i++) push_b(f[i]);\n\
    \    }\n    S get_f() const { return f2.size() ? f2.top() : Monoid::e(); }\n \
    \   S get_b() const { return b2.size() ? b2.top() : Monoid::e(); }\n    void push_f(const\
    \ S &x) {\n        auto y = get_f();\n        f1.push(x);\n        f2.push(Monoid::op(x,\
    \ y));\n    }\n    void push_b(const S &x) {\n        auto y = get_b();\n    \
    \    b1.push(x);\n        b2.push(Monoid::op(y, x));\n    }\n    void pop_f()\
    \ {\n        f1.pop();\n        f2.pop();\n    }\n    void pop_b() {\n       \
    \ b1.pop();\n        b2.pop();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/misc/dswag.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/misc/dswag.hpp
layout: document
redirect_from:
- /library/src/data_structure/misc/dswag.hpp
- /library/src/data_structure/misc/dswag.hpp.html
title: src/data_structure/misc/dswag.hpp
---
