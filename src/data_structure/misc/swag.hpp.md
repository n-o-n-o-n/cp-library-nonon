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
  bundledCode: "#line 2 \"src/data_structure/misc/swag.hpp\"\n#include <cassert>\n\
    #include <stack>\nusing namespace std;\n\ntemplate<typename Monoid>\nstruct swag\
    \ {\n    using S = typename Monoid::S;\n    swag() = default;\n    size_t size()\
    \ const { return f1.size() + b1.size(); }\n    bool empty() const { return size()\
    \ == 0; }\n    S get() const { return Monoid::op(get_f(), get_b()); }\n    void\
    \ push(const S &x) { push_b(x); }\n    void pop() {\n        assert(size());\n\
    \        if (f1.empty()) normalize();\n        pop_f();\n    }\nprivate:\n   \
    \ stack<S> f1, f2, b1, b2;\n    void normalize() {\n        while (b1.size())\
    \ {\n            push_f(b1.top());\n            pop_b();\n        }\n    }\n \
    \   S get_f() const { return f2.size() ? f2.top() : Monoid::e(); }\n    S get_b()\
    \ const { return b2.size() ? b2.top() : Monoid::e(); }\n    void push_f(const\
    \ S &x) {\n        auto y = get_f();\n        f1.push(x);\n        f2.push(Monoid::op(x,\
    \ y));\n    }\n    void push_b(const S &x) {\n        auto y = get_b();\n    \
    \    b1.push(x);\n        b2.push(Monoid::op(y, x));\n    }\n    void pop_f()\
    \ {\n        f1.pop();\n        f2.pop();\n    }\n    void pop_b() {\n       \
    \ b1.pop();\n        b2.pop();\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <stack>\nusing namespace std;\n\
    \ntemplate<typename Monoid>\nstruct swag {\n    using S = typename Monoid::S;\n\
    \    swag() = default;\n    size_t size() const { return f1.size() + b1.size();\
    \ }\n    bool empty() const { return size() == 0; }\n    S get() const { return\
    \ Monoid::op(get_f(), get_b()); }\n    void push(const S &x) { push_b(x); }\n\
    \    void pop() {\n        assert(size());\n        if (f1.empty()) normalize();\n\
    \        pop_f();\n    }\nprivate:\n    stack<S> f1, f2, b1, b2;\n    void normalize()\
    \ {\n        while (b1.size()) {\n            push_f(b1.top());\n            pop_b();\n\
    \        }\n    }\n    S get_f() const { return f2.size() ? f2.top() : Monoid::e();\
    \ }\n    S get_b() const { return b2.size() ? b2.top() : Monoid::e(); }\n    void\
    \ push_f(const S &x) {\n        auto y = get_f();\n        f1.push(x);\n     \
    \   f2.push(Monoid::op(x, y));\n    }\n    void push_b(const S &x) {\n       \
    \ auto y = get_b();\n        b1.push(x);\n        b2.push(Monoid::op(y, x));\n\
    \    }\n    void pop_f() {\n        f1.pop();\n        f2.pop();\n    }\n    void\
    \ pop_b() {\n        b1.pop();\n        b2.pop();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/misc/swag.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/misc/swag.hpp
layout: document
redirect_from:
- /library/src/data_structure/misc/swag.hpp
- /library/src/data_structure/misc/swag.hpp.html
title: src/data_structure/misc/swag.hpp
---
