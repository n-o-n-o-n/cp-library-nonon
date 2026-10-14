---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8
  bundledCode: "#line 2 \"src/data_structure/misc/slope_trick.hpp\"\n#include <cassert>\n\
    #include <queue>\n#include <numeric>\n#include <vector>\nusing namespace std;\n\
    \n// https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8 \n\ntemplate<typename\
    \ T>\nstruct slope_trick {\n    slope_trick() : min_val(0), left_add(0), right_add(0)\
    \ {\n        left.push(-inf);\n        right.push(inf);\n    }\n    T get_min()\
    \ const { return min_val; }\n    pair<T, T> min_range() const { return make_pair(left_top(),\
    \ right_top()); }\n    // f(x) += a\n    void add_all(T a) { min_val += a; }\n\
    \    // f(x) += max(0, x - a)\n    void add_x_minus_a(T a) {\n        min_val\
    \ += max<T>(0, left_top() - a);\n        left_push(a);\n        right_push(left_pop());\n\
    \    }\n    // f(x) += max(0, a - x)\n    void add_a_minus_x(T a) {\n        min_val\
    \ += max<T>(0, a - right_top());\n        right_push(a);\n        left_push(right_pop());\n\
    \    }\n    // f(x) += |x - a|\n    void add_abs_x_minus_a(T a) {\n        add_x_minus_a(a);\n\
    \        add_a_minus_x(a);\n    }\n    // f_new(x) = f(x - c)\n    void shift(T\
    \ c) {\n        left_add += c;\n        right_add += c;\n    }\n    // f_new(x)\
    \ = min_{y in [x-l, x-r]} f_cur(y)\n    void slide_window_min(T l, T r) {\n  \
    \      assert(l >= r);\n        left_add += r;\n        right_add += l;\n    }\n\
    private:\n    static constexpr T inf = numeric_limits<T>::max() / 3;\n    T min_val,\
    \ left_add, right_add;\n    priority_queue<T, vector<T>, less<T>> left;\n    priority_queue<T,\
    \ vector<T>, greater<T>> right;\n    T left_top() const {\n        assert(left.size());\n\
    \        return left.top() + left_add;\n    }\n    T right_top() const {\n   \
    \     assert(right.size());\n        return right.top() + right_add;\n    }\n\
    \    T left_pop() {\n        T res = left_top();\n        left.pop();\n      \
    \  return res;\n    }\n    T right_pop() {\n        T res = right_top();\n   \
    \     right.pop();\n        return res;\n    }\n    void left_push(T a) { left.push(a\
    \ - left_add); }\n    void right_push(T a) { right.push(a - right_add); }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <queue>\n#include <numeric>\n\
    #include <vector>\nusing namespace std;\n\n// https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8\
    \ \n\ntemplate<typename T>\nstruct slope_trick {\n    slope_trick() : min_val(0),\
    \ left_add(0), right_add(0) {\n        left.push(-inf);\n        right.push(inf);\n\
    \    }\n    T get_min() const { return min_val; }\n    pair<T, T> min_range()\
    \ const { return make_pair(left_top(), right_top()); }\n    // f(x) += a\n   \
    \ void add_all(T a) { min_val += a; }\n    // f(x) += max(0, x - a)\n    void\
    \ add_x_minus_a(T a) {\n        min_val += max<T>(0, left_top() - a);\n      \
    \  left_push(a);\n        right_push(left_pop());\n    }\n    // f(x) += max(0,\
    \ a - x)\n    void add_a_minus_x(T a) {\n        min_val += max<T>(0, a - right_top());\n\
    \        right_push(a);\n        left_push(right_pop());\n    }\n    // f(x) +=\
    \ |x - a|\n    void add_abs_x_minus_a(T a) {\n        add_x_minus_a(a);\n    \
    \    add_a_minus_x(a);\n    }\n    // f_new(x) = f(x - c)\n    void shift(T c)\
    \ {\n        left_add += c;\n        right_add += c;\n    }\n    // f_new(x) =\
    \ min_{y in [x-l, x-r]} f_cur(y)\n    void slide_window_min(T l, T r) {\n    \
    \    assert(l >= r);\n        left_add += r;\n        right_add += l;\n    }\n\
    private:\n    static constexpr T inf = numeric_limits<T>::max() / 3;\n    T min_val,\
    \ left_add, right_add;\n    priority_queue<T, vector<T>, less<T>> left;\n    priority_queue<T,\
    \ vector<T>, greater<T>> right;\n    T left_top() const {\n        assert(left.size());\n\
    \        return left.top() + left_add;\n    }\n    T right_top() const {\n   \
    \     assert(right.size());\n        return right.top() + right_add;\n    }\n\
    \    T left_pop() {\n        T res = left_top();\n        left.pop();\n      \
    \  return res;\n    }\n    T right_pop() {\n        T res = right_top();\n   \
    \     right.pop();\n        return res;\n    }\n    void left_push(T a) { left.push(a\
    \ - left_add); }\n    void right_push(T a) { right.push(a - right_add); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/misc/slope_trick.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/misc/slope_trick.hpp
layout: document
redirect_from:
- /library/src/data_structure/misc/slope_trick.hpp
- /library/src/data_structure/misc/slope_trick.hpp.html
title: src/data_structure/misc/slope_trick.hpp
---
