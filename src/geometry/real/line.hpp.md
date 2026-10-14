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
    path: src/geometry/real/incircle_of_triangle.hpp
    title: src/geometry/real/incircle_of_triangle.hpp
  - icon: ':warning:'
    path: src/geometry/real/segmant.hpp
    title: src/geometry/real/segmant.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/real/line.hpp\"\n#include <cassert>\n#line\
    \ 3 \"src/geometry/real/base.hpp\"\n#include <cmath>\n#include <iostream>\n#include\
    \ <numbers>\n#include <numeric>\nusing namespace std;\n\n// \u66F8\u304D\u304B\
    \u3051\u306E\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\n// \u30D0\u30B0\u304C\u3042\
    \u308B\u304B\u3082\n\nnamespace geometry {\n\nusing Real = long double;\nconstexpr\
    \ Real eps = 1e-12;\nconstexpr Real PI = 3.141592653589793238462643383279502884;\n\
    constexpr Real INF_REAL = numeric_limits<Real>::max();\n\ninline bool equal_eps(Real\
    \ a, Real b) {\n    return abs(a - b) < eps;\n}\n\ninline int sgn(Real a) {\n\
    \    return equal_eps(a, 0) ? 0 : a > 0 ? 1 : -1;\n}\n\nstruct Point {\n    Real\
    \ x, y;\n    constexpr Point() : Point(0, 0) {}\n    constexpr Point(Real _x,\
    \ Real _y) : x(_x), y(_y) {}\n    constexpr Point(const pair<Real, Real> &p) :\
    \ x(p.first), y(p.second) {}\n    Point &operator+=(const Point &p) {\n      \
    \  x += p.x;\n        y += p.y;\n        return *this;\n    }\n    Point &operator-=(const\
    \ Point &p) {\n        x -= p.x;\n        y -= p.y;\n        return *this;\n \
    \   }\n    Point &operator*=(const Real &r) {\n        x *= r;\n        y *= r;\n\
    \        return *this;\n    }\n    Point &operator/=(const Real &r) {\n      \
    \  assert(!equal_eps(r, 0));\n        x /= r;\n        y /= r;\n        return\
    \ *this;\n    }\n    Point operator+(const Point &p) const { return Point(*this)\
    \ += p; }\n    Point operator-(const Point &p) const { return Point(*this) -=\
    \ p; }\n    Point operator*(const Real &r) const { return Point(*this) *= r; }\n\
    \    Point operator/(const Real &r) const { return Point(*this) /= r; }\n    Point\
    \ operator-() const { return Point() - *this; }\n    bool operator==(const Point\
    \ &p) const {\n        return equal_eps(x, p.x) && equal_eps(y, p.y);\n    }\n\
    \    bool operator!=(const Point &p) const {\n        return !equal_eps(x, p.x)\
    \ || !equal_eps(y, p.y);\n    }\n    Point rotate(Real rad) const {\n        Real\
    \ c = cosl(rad), s = sinl(rad);\n        Real tx = x * c - y * s;\n        Real\
    \ ty = x * s + y * c;\n        return Point(tx, ty);\n    }\n    Point unit()\
    \ const {\n        return (*this) / metric();\n    }\n    Real Re() const { return\
    \ x; }\n    Real Im() const { return y; }\n    Real norm() const { return x *\
    \ x + y * y; }\n    Real metric() const { return sqrtl(norm()); }\n    Real arg()\
    \ const { return atan2l(y, x); }\n    Real arg(Point q1, Point q2) const {\n \
    \       q1 -= *this, q2 -= *this;\n        return abs(q1.arg() - q2.arg());\n\
    \    }\n    friend Point operator*(Real r, const Point &p) {\n        return p\
    \ * r;\n    }\n    friend Point operator/(Real r, const Point &p) {\n        return\
    \ p / r;\n    }\n};\n\ninline Real Re(const Point &p) { return p.Re(); }\ninline\
    \ Real Im(const Point &p) { return p.Im(); }\ninline Real dot(const Point &p,\
    \ const Point &q) { return p.x * q.x + p.y * q.y; }\ninline Real cross(const Point\
    \ &p, const Point &q) { return p.x * q.y - p.y * q.x; }\ninline Real norm(const\
    \ Point &p) { return p.norm(); }\ninline Real metric(const Point &p) { return\
    \ p.metric(); }\ninline Real metric(const Point &p, const Point &q) { return metric(p\
    \ - q); }\ninline Real arg(const Point &p) { return p.arg(); }\ninline Real angle(Point\
    \ o, Point p, Point q) {\n    p -= o, q -= o;\n    return atan2l(cross(p, q),\
    \ dot(p, q));\n}\ninline bool equal_point(const Point &p, const Point &q) {\n\
    \    return equal_eps(p.x, q.x) && equal_eps(p.y, q.y);\n}\n\nconstexpr Point\
    \ INF_POINT = Point(INF_REAL, INF_REAL);\n\n// a \u3092\u57FA\u6E96\u306B\u3057\
    \u305F b \u3068 c \u306E\u4F4D\u7F6E\u95A2\u4FC2\ninline int ccw(const Point &a,\
    \ const Point &b, const Point &c) {\n    Point p = b - a, q = c - a;\n    if (cross(p,\
    \ q) > eps) return 1; // a, b, c \u306E\u9806\u3067\u53CD\u6642\u8A08\u56DE\u308A\
    \n    if (cross(p, q) < -eps) return -1; // a, b, c \u306E\u9806\u3067\u6642\u8A08\
    \u56DE\u308A\n    if (min(norm(p), norm(q)) < eps * eps) return 0; // a = c or\
    \ b = c\n    if (dot(p, q) < eps) return 2; // c, a, b \u306E\u9806\u3067\u4E00\
    \u76F4\u7DDA\n    if (norm(p) < norm(q)) return -2; // a, b, c \u306E\u9806\u3067\
    \u4E00\u76F4\u7DDA\n    return 0; // a, c, b \u306E\u9806\u3067\u4E00\u76F4\u7DDA\
    \n}\n\ninline istream &operator>>(istream &is, Point& p) {\n    Real x, y;\n \
    \   is >> x >> y;\n    p = Point(x, y);\n    return is;\n}\n\n} // namespace geometry\n\
    #line 4 \"src/geometry/real/line.hpp\"\nusing namespace std;\n\nnamespace geometry\
    \ {\n\nstruct Line {\n    // Line : ax + by = c\n    Real a, b, c;\n    constexpr\
    \ Line() : Line(0, 0, 0) {}\n    constexpr Line(Real _a, Real _b, Real _c) : a(_a),\
    \ b(_b), c(_c) {}\n    constexpr Line(const Point &p, const Point &q) : a(q.y\
    \ - p.y), b(p.x - q.x), c(p.x * q.y - p.y * q.x) {}\n    constexpr Line(Real _a,\
    \ const Point &p) : a(_a), b(-1), c(_a * p.x - p.y) {}\n    bool online(const\
    \ Point &p) const {\n        return equal_eps(a * p.x + b * p.y, c);\n    }\n\
    \    Real get_x(Real y) const {\n        if (equal_eps(a, 0)) return INF_REAL;\n\
    \        return (c - b * y) / a;\n    }\n    Real get_y(Real x) const {\n    \
    \    if (equal_eps(b, 0)) return INF_REAL;\n        return (c - a * x) / b;\n\
    \    }\n    Line perpendicular(const Point &p) const {\n        if (equal_eps(a,\
    \ 0)) return Line(1, 0, p.x);\n        if (equal_eps(0, b)) return Line(0, 1,\
    \ p.y);\n        return Line(b / a, p);\n    }\n    Point crossppoint(const Line\
    \ &l) const {\n        if (equal_eps(a * l.b, l.a * b)) return INF_POINT;\n  \
    \      Real d = a * l.b - l.a * b;\n        return Point(l.b * c - b * l.c, l.c\
    \ * a - c * l.a) / d;\n    }\n    Point projection(const Point &p) const {\n \
    \       return crossppoint(perpendicular(p));\n    }\n    Point reflection(const\
    \ Point &p) const {\n        Point q = projection(p);\n        return 2 * q -\
    \ p;\n    }\n    Point unit() const {\n        if (equal_eps(b, 0)) {\n      \
    \      return Point(0, 1);\n        }\n        Point p(0, get_y(0)), q(1, get_y(1));\n\
    \        return (p - q) / metric(p - q);\n    }\n    bool is_orthogonal(const\
    \ Line &l) const {\n        return equal_eps(a * l.a + b * l.b, 0);\n    }\n \
    \   bool is_parallel(const Line &l) const {\n        return equal_eps(a * l.b,\
    \ l.a * b);\n    }\n    Real dist(const Point &p) const {\n        Point q = projection(p);\n\
    \        return metric(p - q);\n    }\n};\n\ninline bool is_orthogonal(const Line\
    \ &l1, const Line &l2) { return l1.is_orthogonal(l2); }\ninline bool is_parallel(const\
    \ Line &l1, const Line &l2) { return l1.is_parallel(l2); }\ninline Point crosspoint(const\
    \ Line &l1, const Line &l2) { return l1.crossppoint(l2); }\n\n} // namespace geometry\n"
  code: "#pragma once\n#include <cassert>\n#include \"base.hpp\"\nusing namespace\
    \ std;\n\nnamespace geometry {\n\nstruct Line {\n    // Line : ax + by = c\n \
    \   Real a, b, c;\n    constexpr Line() : Line(0, 0, 0) {}\n    constexpr Line(Real\
    \ _a, Real _b, Real _c) : a(_a), b(_b), c(_c) {}\n    constexpr Line(const Point\
    \ &p, const Point &q) : a(q.y - p.y), b(p.x - q.x), c(p.x * q.y - p.y * q.x) {}\n\
    \    constexpr Line(Real _a, const Point &p) : a(_a), b(-1), c(_a * p.x - p.y)\
    \ {}\n    bool online(const Point &p) const {\n        return equal_eps(a * p.x\
    \ + b * p.y, c);\n    }\n    Real get_x(Real y) const {\n        if (equal_eps(a,\
    \ 0)) return INF_REAL;\n        return (c - b * y) / a;\n    }\n    Real get_y(Real\
    \ x) const {\n        if (equal_eps(b, 0)) return INF_REAL;\n        return (c\
    \ - a * x) / b;\n    }\n    Line perpendicular(const Point &p) const {\n     \
    \   if (equal_eps(a, 0)) return Line(1, 0, p.x);\n        if (equal_eps(0, b))\
    \ return Line(0, 1, p.y);\n        return Line(b / a, p);\n    }\n    Point crossppoint(const\
    \ Line &l) const {\n        if (equal_eps(a * l.b, l.a * b)) return INF_POINT;\n\
    \        Real d = a * l.b - l.a * b;\n        return Point(l.b * c - b * l.c,\
    \ l.c * a - c * l.a) / d;\n    }\n    Point projection(const Point &p) const {\n\
    \        return crossppoint(perpendicular(p));\n    }\n    Point reflection(const\
    \ Point &p) const {\n        Point q = projection(p);\n        return 2 * q -\
    \ p;\n    }\n    Point unit() const {\n        if (equal_eps(b, 0)) {\n      \
    \      return Point(0, 1);\n        }\n        Point p(0, get_y(0)), q(1, get_y(1));\n\
    \        return (p - q) / metric(p - q);\n    }\n    bool is_orthogonal(const\
    \ Line &l) const {\n        return equal_eps(a * l.a + b * l.b, 0);\n    }\n \
    \   bool is_parallel(const Line &l) const {\n        return equal_eps(a * l.b,\
    \ l.a * b);\n    }\n    Real dist(const Point &p) const {\n        Point q = projection(p);\n\
    \        return metric(p - q);\n    }\n};\n\ninline bool is_orthogonal(const Line\
    \ &l1, const Line &l2) { return l1.is_orthogonal(l2); }\ninline bool is_parallel(const\
    \ Line &l1, const Line &l2) { return l1.is_parallel(l2); }\ninline Point crosspoint(const\
    \ Line &l1, const Line &l2) { return l1.crossppoint(l2); }\n\n} // namespace geometry"
  dependsOn:
  - src/geometry/real/base.hpp
  isVerificationFile: false
  path: src/geometry/real/line.hpp
  requiredBy:
  - src/geometry/real/incircle_of_triangle.hpp
  - src/geometry/real/segmant.hpp
  - src/geometry/real/circumcircle_of_triangle.hpp
  - src/geometry/real/circle.hpp
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/real/line.hpp
layout: document
redirect_from:
- /library/src/geometry/real/line.hpp
- /library/src/geometry/real/line.hpp.html
title: src/geometry/real/line.hpp
---
