---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/geometry/real/base.hpp
    title: src/geometry/real/base.hpp
  - icon: ':warning:'
    path: src/geometry/real/circle.hpp
    title: src/geometry/real/circle.hpp
  - icon: ':warning:'
    path: src/geometry/real/line.hpp
    title: src/geometry/real/line.hpp
  - icon: ':warning:'
    path: src/geometry/real/polygon.hpp
    title: src/geometry/real/polygon.hpp
  - icon: ':warning:'
    path: src/geometry/real/segmant.hpp
    title: src/geometry/real/segmant.hpp
  _extendedRequiredBy: []
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
    \ Line &l1, const Line &l2) { return l1.crossppoint(l2); }\n\n} // namespace geometry\n\
    #line 2 \"src/geometry/real/circle.hpp\"\n#include <vector>\n#line 3 \"src/geometry/real/segmant.hpp\"\
    \nusing namespace std;\n\nnamespace geometry {\n\nstruct Segment {\n    Line l;\n\
    \    Point a, b;\n    Segment() = default;\n    Segment(const Point &_a, const\
    \ Point &_b) : l(_a, _b), a(_a), b(_b) {}\n    bool has_intersection(const Segment\
    \ &s) const {\n        bool f1 = ccw(a, b, s.a) * ccw(a, b, s.b) <= 0;\n     \
    \   bool f2 = ccw(s.a, s.b, a) * ccw(s.a, s.b, b) <= 0;\n        return f1 &&\
    \ f2;\n    }\n    bool on_segment(const Point &p) const {\n        Point ab =\
    \ b - a, ap = p - a, bp = p - b;\n        if (abs(cross(ab, ap)) > eps) return\
    \ false;\n        return dot(ab, ap) >= -eps && dot(ab, bp) <= eps;\n    }\n \
    \   Point crosspoint(const Segment &s) const {\n        if (has_intersection(s))\
    \ return l.crossppoint(s.l);\n        return INF_POINT;\n    }\n    Real dist(const\
    \ Point &p) const {\n        if (dot(b - a, p - a) < eps) return (p - a).metric();\n\
    \        if (dot(a - b, p - b) < eps) return (p - b).metric();\n        return\
    \ l.dist(p);\n    }\n    Real dist(const Segment &s) const {\n        if (has_intersection(s))\
    \ return 0;\n        Real res = INF_REAL;\n        res = min(res, dist(s.a));\n\
    \        res = min(res, dist(s.b));\n        res = min(res, s.dist(a));\n    \
    \    res = min(res, s.dist(b));\n        return res;\n    }\n};\n\ninline bool\
    \ has_intersection(const Segment &s, const Segment &t) { return s.has_intersection(t);\
    \ }\ninline Point crosspoint(const Segment &s, const Segment &t) { return s.crosspoint(t);\
    \ }\ninline Real dist(const Segment &s, const Segment &t) { return s.dist(t);\
    \ }\n\n} // nemespace geometry\n#line 2 \"src/geometry/real/polygon.hpp\"\n#include\
    \ <algorithm>\n#line 5 \"src/geometry/real/polygon.hpp\"\nusing namespace std;\n\
    \nnamespace geometry {\n\nstruct Polygon : vector<Point> {\n    using vector<Point>::vector;\n\
    \    Polygon(const vector<Point>& pts) : vector<Point>(pts) {}\n    int contain(const\
    \ Point &p) const {\n        int n = this->size();\n        bool in = false;\n\
    \        for (int i = 0; i < n; i++) {\n            Point a = (*this)[i] - p;\n\
    \            Point b = (*this)[i == n - 1 ? 0 : i + 1] - p;\n            // need\
    \ std::\n            if (Im(a) > Im(b)) std::swap(a, b);\n            if (sgn(Im(a))\
    \ <= 0 && 0 < sgn(Im(b)) && sgn(cross(a, b)) < 0) in = !in;\n            if (equal_eps(cross(a,\
    \ b), 0) && sgn(dot(a, b)) <= 0) return 1;\n        }\n        return in ? 2 :\
    \ 0;\n    }\n    Real area() const {\n        int n = this->size();\n        Real\
    \ S = 0;\n        for (int i = 0; i < n; i++) {\n            Point a = (*this)[i];\n\
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
    } // namespace geometry\n#line 5 \"src/geometry/real/circle.hpp\"\nusing namespace\
    \ std;\n\nnamespace geometry {\n\n// { x in R^2 | |x - p| = r}\nstruct circle\
    \ {\n    Point p;\n    Real r;\n    circle() = default;\n    circle(const Point\
    \ _p, Real _r) : p(_p), r(_r) {}\n    int count_common_tangent(const circle &c)\
    \ const {\n        Real d = metric(p - c.p);\n        if (d > r + c.r + eps) return\
    \ 4;\n        if (equal_eps(d, r + c.r)) return 3;\n        if (equal_eps(d, abs(r\
    \ - c.r))) return 1;\n        if (d < abs(r - c.r) - eps) return 0;\n        return\
    \ 2;\n    }\n    bool contain(const Point &q) const {\n        return metric(p,\
    \ q) <= r + eps;\n    }\n    vector<Point> crosspoints(const Line &l) const {\n\
    \        Real d = l.dist(p);\n        if (d > r + eps) return {};\n        Point\
    \ q = l.projection(p);\n        if (equal_eps(d, r)) {\n            return {q};\n\
    \        }\n        Point e = l.unit();\n        Real t = sqrtl(r * r - d * d);\n\
    \        return {q - t * e, q + t * e};\n    }\n    vector<Point> crosspoints(const\
    \ Segment &s) const {\n        vector<Point> res;\n        for (Point p : crosspoints(s.l))\
    \ {\n            if (s.on_segment(p)) res.push_back(p);\n        }\n        return\
    \ res;\n    }\n    vector<Point> crosspoints(const circle &c) const {\n      \
    \  int t = count_common_tangent(c);\n        if (t == 0 || t == 4) return {};\n\
    \        Real d = metric(p - c.p);\n        if (t == 1) {\n            if (c.r\
    \ < r - eps) {\n                return {p + (c.p - p) * (r / d)};\n          \
    \  } else {\n                return {c.p + (p - c.p) * (c.r / d)};\n         \
    \   }\n        } else if (t == 3) {\n            geometry::Real s = r / (r + c.r);\n\
    \            return {p + (c.p - p) * s};\n        } else {\n            geometry::Real\
    \ la = 2 * (p.x - c.p.x);\n            geometry::Real lb = 2 * (p.y - c.p.y);\n\
    \            geometry::Real lc = (p.x + c.p.x) * (p.x - c.p.x) + (p.y + c.p.y)\
    \ * (p.y - c.p.y) + (r + c.r) * (c.r - r);\n            return crosspoints(Line(la,\
    \ lb, lc));\n        }\n    }\n    vector<Point> points_of_tangency(const Point\
    \ &q) const {\n        Real d = metric(p - q);\n        if (d < r - eps) return\
    \ {};\n        if (equal_eps(d, r)) return {q};\n        return crosspoints(circle(q,\
    \ sqrtl(d * d - r * r)));\n    }\n    vector<Point> points_of_common_tangency(const\
    \ circle &c) const {\n        Real d = metric(p - c.p);\n        if (equal_eps(d,\
    \ 0)) return {};\n        Point u = (c.p - p).unit();\n        Point v = u.rotate(PI\
    \ / 2);\n        vector<Point> res;\n        for (int s : {-1, 1}) {\n       \
    \     Real h = (r + s * c.r) / d;\n            if (equal_eps(h * h, 1)) {\n  \
    \              res.push_back(p + (h > 0 ? u : -u) * r);\n            } else if\
    \ (1 - h * h > 0) {\n                Point u2 = u * h, v2 = v * sqrtl(1 - h *\
    \ h);\n                res.push_back(p + (u2 + v2) * r);\n                res.push_back(p\
    \ + (u2 - v2) * r);\n            }\n        }\n        return res;\n    }\n  \
    \  Real area_of_intersection(const Polygon &g) const {\n        auto f = [&] (Point\
    \ a, Point b) -> Real {\n            Real res = 0;\n            auto ps = circle(Point(0,\
    \ 0), r).crosspoints(Segment(a, b));\n            if (a.norm() < r * r - eps &&\
    \ b.norm() < r * r - eps) {\n                res += cross(a, b);\n           \
    \ } else if (a.norm() < r * r - eps) {\n                assert(ps.size());\n \
    \               res += cross(a, ps[0]);\n                res += r * r * angle(Point(0,\
    \ 0), ps[0], b);\n            } else if (b.norm() < r * r - eps) {\n         \
    \       assert(ps.size());\n                res += r * r * angle(Point(0, 0),\
    \ a, ps[0]);\n                res += cross(ps[0], b);\n            } else {\n\
    \                if (ps.empty()) {\n                    res += r * r * angle(Point(0,\
    \ 0), a, b);\n                } else {\n                    Point pa = ps.front(),\
    \ pb = ps.back();\n                    if (norm(a - pa) > norm(a - pb)) swap(pa,\
    \ pb);\n                    res += r * r * angle(Point(0, 0), a, pa);\n      \
    \              res += cross(pa, pb);\n                    res += r * r * angle(Point(0,\
    \ 0), pb, b);\n                }\n            }\n            return res;\n   \
    \     };\n        int n = g.size();\n        Real S = 0;\n        for (int i =\
    \ 0; i < n; i++) {\n            Point a = g[i] - p;\n            Point b = g[i\
    \ == n - 1 ? 0 : i + 1] - p;\n            if (abs(ccw(p, a, b)) == 1) S += f(a,\
    \ b);\n        }\n        return 0.5 * S;\n    }\n};\n\n} // namespace geometry\n\
    #line 4 \"src/geometry/real/circumcircle_of_triangle.hpp\"\nusing namespace std;\n\
    \nnamespace geometry {\n\ncircle circumcircle_of_triangle(const Point &p1, const\
    \ Point &p2, const Point &p3) {\n    Point p12 = p1 - p2, p23 = p2 - p3;\n   \
    \ Real d = 2 * cross(p12, p23);\n    Real t12 = norm(p1) - norm(p2), t23 = norm(p2)\
    \ - norm(p3);\n    Point p = (t12 * p23 - t23 * p12) / d;\n    swap(p.x, p.y);\n\
    \    p.y = -p.y;\n    Real r = metric(p1 - p);\n    return circle(p, r);\n}\n\n\
    } // namespace geometry\n"
  code: "#pragma once\n#include \"line.hpp\"\n#include \"circle.hpp\"\nusing namespace\
    \ std;\n\nnamespace geometry {\n\ncircle circumcircle_of_triangle(const Point\
    \ &p1, const Point &p2, const Point &p3) {\n    Point p12 = p1 - p2, p23 = p2\
    \ - p3;\n    Real d = 2 * cross(p12, p23);\n    Real t12 = norm(p1) - norm(p2),\
    \ t23 = norm(p2) - norm(p3);\n    Point p = (t12 * p23 - t23 * p12) / d;\n   \
    \ swap(p.x, p.y);\n    p.y = -p.y;\n    Real r = metric(p1 - p);\n    return circle(p,\
    \ r);\n}\n\n} // namespace geometry"
  dependsOn:
  - src/geometry/real/line.hpp
  - src/geometry/real/base.hpp
  - src/geometry/real/circle.hpp
  - src/geometry/real/segmant.hpp
  - src/geometry/real/polygon.hpp
  isVerificationFile: false
  path: src/geometry/real/circumcircle_of_triangle.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/real/circumcircle_of_triangle.hpp
layout: document
redirect_from:
- /library/src/geometry/real/circumcircle_of_triangle.hpp
- /library/src/geometry/real/circumcircle_of_triangle.hpp.html
title: src/geometry/real/circumcircle_of_triangle.hpp
---
