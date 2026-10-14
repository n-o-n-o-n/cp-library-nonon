---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/geometry/real/base.hpp
    title: src/geometry/real/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/geometry/real/circle.hpp
    title: src/geometry/real/circle.hpp
  - icon: ':warning:'
    path: src/geometry/real/circumcircle_of_triangle.hpp
    title: src/geometry/real/circumcircle_of_triangle.hpp
  - icon: ':warning:'
    path: src/geometry/real/convex_hull.hpp
    title: src/geometry/real/convex_hull.hpp
  - icon: ':warning:'
    path: src/geometry/real/incircle_of_triangle.hpp
    title: src/geometry/real/incircle_of_triangle.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/real/polygon.hpp\"\n#include <algorithm>\n\
    #include <vector>\n#line 2 \"src/geometry/real/base.hpp\"\n#include <cassert>\n\
    #include <cmath>\n#include <iostream>\n#include <numbers>\n#include <numeric>\n\
    using namespace std;\n\n// \u66F8\u304D\u304B\u3051\u306E\u5E7E\u4F55\u30E9\u30A4\
    \u30D6\u30E9\u30EA\n// \u30D0\u30B0\u304C\u3042\u308B\u304B\u3082\n\nnamespace\
    \ geometry {\n\nusing Real = long double;\nconstexpr Real eps = 1e-12;\nconstexpr\
    \ Real PI = 3.141592653589793238462643383279502884;\nconstexpr Real INF_REAL =\
    \ numeric_limits<Real>::max();\n\ninline bool equal_eps(Real a, Real b) {\n  \
    \  return abs(a - b) < eps;\n}\n\ninline int sgn(Real a) {\n    return equal_eps(a,\
    \ 0) ? 0 : a > 0 ? 1 : -1;\n}\n\nstruct Point {\n    Real x, y;\n    constexpr\
    \ Point() : Point(0, 0) {}\n    constexpr Point(Real _x, Real _y) : x(_x), y(_y)\
    \ {}\n    constexpr Point(const pair<Real, Real> &p) : x(p.first), y(p.second)\
    \ {}\n    Point &operator+=(const Point &p) {\n        x += p.x;\n        y +=\
    \ p.y;\n        return *this;\n    }\n    Point &operator-=(const Point &p) {\n\
    \        x -= p.x;\n        y -= p.y;\n        return *this;\n    }\n    Point\
    \ &operator*=(const Real &r) {\n        x *= r;\n        y *= r;\n        return\
    \ *this;\n    }\n    Point &operator/=(const Real &r) {\n        assert(!equal_eps(r,\
    \ 0));\n        x /= r;\n        y /= r;\n        return *this;\n    }\n    Point\
    \ operator+(const Point &p) const { return Point(*this) += p; }\n    Point operator-(const\
    \ Point &p) const { return Point(*this) -= p; }\n    Point operator*(const Real\
    \ &r) const { return Point(*this) *= r; }\n    Point operator/(const Real &r)\
    \ const { return Point(*this) /= r; }\n    Point operator-() const { return Point()\
    \ - *this; }\n    bool operator==(const Point &p) const {\n        return equal_eps(x,\
    \ p.x) && equal_eps(y, p.y);\n    }\n    bool operator!=(const Point &p) const\
    \ {\n        return !equal_eps(x, p.x) || !equal_eps(y, p.y);\n    }\n    Point\
    \ rotate(Real rad) const {\n        Real c = cosl(rad), s = sinl(rad);\n     \
    \   Real tx = x * c - y * s;\n        Real ty = x * s + y * c;\n        return\
    \ Point(tx, ty);\n    }\n    Point unit() const {\n        return (*this) / metric();\n\
    \    }\n    Real Re() const { return x; }\n    Real Im() const { return y; }\n\
    \    Real norm() const { return x * x + y * y; }\n    Real metric() const { return\
    \ sqrtl(norm()); }\n    Real arg() const { return atan2l(y, x); }\n    Real arg(Point\
    \ q1, Point q2) const {\n        q1 -= *this, q2 -= *this;\n        return abs(q1.arg()\
    \ - q2.arg());\n    }\n    friend Point operator*(Real r, const Point &p) {\n\
    \        return p * r;\n    }\n    friend Point operator/(Real r, const Point\
    \ &p) {\n        return p / r;\n    }\n};\n\ninline Real Re(const Point &p) {\
    \ return p.Re(); }\ninline Real Im(const Point &p) { return p.Im(); }\ninline\
    \ Real dot(const Point &p, const Point &q) { return p.x * q.x + p.y * q.y; }\n\
    inline Real cross(const Point &p, const Point &q) { return p.x * q.y - p.y * q.x;\
    \ }\ninline Real norm(const Point &p) { return p.norm(); }\ninline Real metric(const\
    \ Point &p) { return p.metric(); }\ninline Real metric(const Point &p, const Point\
    \ &q) { return metric(p - q); }\ninline Real arg(const Point &p) { return p.arg();\
    \ }\ninline Real angle(Point o, Point p, Point q) {\n    p -= o, q -= o;\n   \
    \ return atan2l(cross(p, q), dot(p, q));\n}\ninline bool equal_point(const Point\
    \ &p, const Point &q) {\n    return equal_eps(p.x, q.x) && equal_eps(p.y, q.y);\n\
    }\n\nconstexpr Point INF_POINT = Point(INF_REAL, INF_REAL);\n\n// a \u3092\u57FA\
    \u6E96\u306B\u3057\u305F b \u3068 c \u306E\u4F4D\u7F6E\u95A2\u4FC2\ninline int\
    \ ccw(const Point &a, const Point &b, const Point &c) {\n    Point p = b - a,\
    \ q = c - a;\n    if (cross(p, q) > eps) return 1; // a, b, c \u306E\u9806\u3067\
    \u53CD\u6642\u8A08\u56DE\u308A\n    if (cross(p, q) < -eps) return -1; // a, b,\
    \ c \u306E\u9806\u3067\u6642\u8A08\u56DE\u308A\n    if (min(norm(p), norm(q))\
    \ < eps * eps) return 0; // a = c or b = c\n    if (dot(p, q) < eps) return 2;\
    \ // c, a, b \u306E\u9806\u3067\u4E00\u76F4\u7DDA\n    if (norm(p) < norm(q))\
    \ return -2; // a, b, c \u306E\u9806\u3067\u4E00\u76F4\u7DDA\n    return 0; //\
    \ a, c, b \u306E\u9806\u3067\u4E00\u76F4\u7DDA\n}\n\ninline istream &operator>>(istream\
    \ &is, Point& p) {\n    Real x, y;\n    is >> x >> y;\n    p = Point(x, y);\n\
    \    return is;\n}\n\n} // namespace geometry\n#line 5 \"src/geometry/real/polygon.hpp\"\
    \nusing namespace std;\n\nnamespace geometry {\n\nstruct Polygon : vector<Point>\
    \ {\n    using vector<Point>::vector;\n    Polygon(const vector<Point>& pts) :\
    \ vector<Point>(pts) {}\n    int contain(const Point &p) const {\n        int\
    \ n = this->size();\n        bool in = false;\n        for (int i = 0; i < n;\
    \ i++) {\n            Point a = (*this)[i] - p;\n            Point b = (*this)[i\
    \ == n - 1 ? 0 : i + 1] - p;\n            // need std::\n            if (Im(a)\
    \ > Im(b)) std::swap(a, b);\n            if (sgn(Im(a)) <= 0 && 0 < sgn(Im(b))\
    \ && sgn(cross(a, b)) < 0) in = !in;\n            if (equal_eps(cross(a, b), 0)\
    \ && sgn(dot(a, b)) <= 0) return 1;\n        }\n        return in ? 2 : 0;\n \
    \   }\n    Real area() const {\n        int n = this->size();\n        Real S\
    \ = 0;\n        for (int i = 0; i < n; i++) {\n            Point a = (*this)[i];\n\
    \            Point b = (*this)[i == n - 1 ? 0 : i + 1];\n            S += cross(a,\
    \ b);\n        }\n        return S * 0.5;\n    }\n    tuple<Real, Point, Point>\
    \ diam() const {\n        int n = this->size();\n        int ii = 0, jj = 0;\n\
    \        for (int i = 1; i < n; i++) {\n            if ((*this)[i].y > (*this)[ii].y)\
    \ ii = i;\n            if ((*this)[i].y < (*this)[jj].y) jj = i;\n        }\n\
    \        Real res = metric((*this)[ii] - (*this)[jj]);\n        int i = ii, j\
    \ = jj;\n        Point resp, resq;\n        do {\n            Point p = (*this)[i\
    \ + 1 == n ? 0 : i + 1] - (*this)[i];\n            Point q = (*this)[j + 1 ==\
    \ n ? 0 : j + 1] - (*this)[j];\n            if (cross(p, q) > eps) j = (j + 1\
    \ == n ? 0 : j + 1);\n            else i = (i + 1 == n ? 0 : i + 1);\n       \
    \     if (metric((*this)[i] - (*this)[j]) > res) {\n                res = metric((*this)[i]\
    \ - (*this)[j]);\n                resp = (*this)[i], resq = (*this)[j];\n    \
    \        }\n        } while (i != ii || j != jj);\n        return make_tuple(res,\
    \ resp, resq);\n    }\n    bool is_convex() const {\n        int n = this->size();\n\
    \        if (n <= 2) return false;\n        for (int i = 0, j = 1, k = 2; i <\
    \ n; i++, j++, k++) {\n            if (j == n) j = 0;\n            if (k == n)\
    \ k = 0;\n            if (ccw((*this)[i], (*this)[j], (*this)[k]) == -1) return\
    \ false;\n        }\n        return true;\n    }\n    void relabeling() {\n  \
    \      Real x_min = INF_REAL, y_min = INF_REAL;\n        int idx = 0, n = this->size();\n\
    \        for (int i = 0; i < n; i++) {\n            Real x = (*this)[i].x, y =\
    \ (*this)[i].y;\n            if (y < y_min || (equal_eps(y, y_min) && x < x_min))\
    \ {\n                x_min = x;\n                y_min = y;\n                idx\
    \ = i;\n            }\n        }\n        Polygon tmp(n);\n        int pre = (idx\
    \ + n - 1) % n, nxt = (idx + 1) % n;\n        if (ccw((*this)[idx], (*this)[pre],\
    \ (*this)[nxt]) == -1) {\n            for (int i = 0; i < n; i++) {\n        \
    \        tmp[i] = (*this)[(idx + i) % n];\n            }\n        } else {\n \
    \           for (int i = 0; i < n; i++) {\n                tmp[i] = (*this)[(idx\
    \ + n - i) % n];\n            }\n        }\n        *this = tmp;\n    }\n};\n\n\
    } // namespace geometry\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include \"base.hpp\"\
    \nusing namespace std;\n\nnamespace geometry {\n\nstruct Polygon : vector<Point>\
    \ {\n    using vector<Point>::vector;\n    Polygon(const vector<Point>& pts) :\
    \ vector<Point>(pts) {}\n    int contain(const Point &p) const {\n        int\
    \ n = this->size();\n        bool in = false;\n        for (int i = 0; i < n;\
    \ i++) {\n            Point a = (*this)[i] - p;\n            Point b = (*this)[i\
    \ == n - 1 ? 0 : i + 1] - p;\n            // need std::\n            if (Im(a)\
    \ > Im(b)) std::swap(a, b);\n            if (sgn(Im(a)) <= 0 && 0 < sgn(Im(b))\
    \ && sgn(cross(a, b)) < 0) in = !in;\n            if (equal_eps(cross(a, b), 0)\
    \ && sgn(dot(a, b)) <= 0) return 1;\n        }\n        return in ? 2 : 0;\n \
    \   }\n    Real area() const {\n        int n = this->size();\n        Real S\
    \ = 0;\n        for (int i = 0; i < n; i++) {\n            Point a = (*this)[i];\n\
    \            Point b = (*this)[i == n - 1 ? 0 : i + 1];\n            S += cross(a,\
    \ b);\n        }\n        return S * 0.5;\n    }\n    tuple<Real, Point, Point>\
    \ diam() const {\n        int n = this->size();\n        int ii = 0, jj = 0;\n\
    \        for (int i = 1; i < n; i++) {\n            if ((*this)[i].y > (*this)[ii].y)\
    \ ii = i;\n            if ((*this)[i].y < (*this)[jj].y) jj = i;\n        }\n\
    \        Real res = metric((*this)[ii] - (*this)[jj]);\n        int i = ii, j\
    \ = jj;\n        Point resp, resq;\n        do {\n            Point p = (*this)[i\
    \ + 1 == n ? 0 : i + 1] - (*this)[i];\n            Point q = (*this)[j + 1 ==\
    \ n ? 0 : j + 1] - (*this)[j];\n            if (cross(p, q) > eps) j = (j + 1\
    \ == n ? 0 : j + 1);\n            else i = (i + 1 == n ? 0 : i + 1);\n       \
    \     if (metric((*this)[i] - (*this)[j]) > res) {\n                res = metric((*this)[i]\
    \ - (*this)[j]);\n                resp = (*this)[i], resq = (*this)[j];\n    \
    \        }\n        } while (i != ii || j != jj);\n        return make_tuple(res,\
    \ resp, resq);\n    }\n    bool is_convex() const {\n        int n = this->size();\n\
    \        if (n <= 2) return false;\n        for (int i = 0, j = 1, k = 2; i <\
    \ n; i++, j++, k++) {\n            if (j == n) j = 0;\n            if (k == n)\
    \ k = 0;\n            if (ccw((*this)[i], (*this)[j], (*this)[k]) == -1) return\
    \ false;\n        }\n        return true;\n    }\n    void relabeling() {\n  \
    \      Real x_min = INF_REAL, y_min = INF_REAL;\n        int idx = 0, n = this->size();\n\
    \        for (int i = 0; i < n; i++) {\n            Real x = (*this)[i].x, y =\
    \ (*this)[i].y;\n            if (y < y_min || (equal_eps(y, y_min) && x < x_min))\
    \ {\n                x_min = x;\n                y_min = y;\n                idx\
    \ = i;\n            }\n        }\n        Polygon tmp(n);\n        int pre = (idx\
    \ + n - 1) % n, nxt = (idx + 1) % n;\n        if (ccw((*this)[idx], (*this)[pre],\
    \ (*this)[nxt]) == -1) {\n            for (int i = 0; i < n; i++) {\n        \
    \        tmp[i] = (*this)[(idx + i) % n];\n            }\n        } else {\n \
    \           for (int i = 0; i < n; i++) {\n                tmp[i] = (*this)[(idx\
    \ + n - i) % n];\n            }\n        }\n        *this = tmp;\n    }\n};\n\n\
    } // namespace geometry"
  dependsOn:
  - src/geometry/real/base.hpp
  isVerificationFile: false
  path: src/geometry/real/polygon.hpp
  requiredBy:
  - src/geometry/real/incircle_of_triangle.hpp
  - src/geometry/real/convex_hull.hpp
  - src/geometry/real/circumcircle_of_triangle.hpp
  - src/geometry/real/circle.hpp
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/real/polygon.hpp
layout: document
redirect_from:
- /library/src/geometry/real/polygon.hpp
- /library/src/geometry/real/polygon.hpp.html
title: src/geometry/real/polygon.hpp
---
