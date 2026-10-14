---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/geometry/real/base.hpp
    title: src/geometry/real/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/real/closest_pair.hpp\"\n#include <algorithm>\n\
    #include <vector>\nusing namespace std;\n#line 2 \"src/geometry/real/base.hpp\"\
    \n#include <cassert>\n#include <cmath>\n#include <iostream>\n#include <numbers>\n\
    #include <numeric>\nusing namespace std;\n\n// \u66F8\u304D\u304B\u3051\u306E\u5E7E\
    \u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\n// \u30D0\u30B0\u304C\u3042\u308B\u304B\u3082\
    \n\nnamespace geometry {\n\nusing Real = long double;\nconstexpr Real eps = 1e-12;\n\
    constexpr Real PI = 3.141592653589793238462643383279502884;\nconstexpr Real INF_REAL\
    \ = numeric_limits<Real>::max();\n\ninline bool equal_eps(Real a, Real b) {\n\
    \    return abs(a - b) < eps;\n}\n\ninline int sgn(Real a) {\n    return equal_eps(a,\
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
    \    return is;\n}\n\n} // namespace geometry\n#line 6 \"src/geometry/real/closest_pair.hpp\"\
    \n\nnamespace geometry {\n\nReal closest_pair(vector<Point> pts) {\n    sort(pts.begin(),\
    \ pts.end(), [] (const Point &p, const Point &q) {\n        return p.x < q.x;\n\
    \    });\n    auto rec = [&] (const auto &rec, int l, int r) -> Real {\n     \
    \   if (r - l <= 1) return INF_REAL;\n        int m = (l + r) / 2;\n        Real\
    \ x = pts[m].x;\n        Real res = min(rec(rec, l, m), rec(rec, m, r));\n   \
    \     inplace_merge(pts.begin() + l, pts.begin() + m, pts.begin() + r, [] (const\
    \ Point &p, const Point &q) {\n            return p.y < q.y;\n        });\n  \
    \      vector<Point> pts2;\n        for (int i = l; i < r; i++) {\n          \
    \  if (res - abs(pts[i].x - x) <= eps) continue;\n            for (int j = ssize(pts2)\
    \ - 1; j >= 0; j--) {\n                if (res - abs(pts[i].y - pts2[j].y) <=\
    \ eps) break;\n                res = min(res, metric(pts[i] - pts2[j]));\n   \
    \         }\n            pts2.push_back(pts[i]);\n        }\n        return res;\n\
    \    };\n    return rec(rec, 0, ssize(pts));\n}\n\n} // namespace geometry\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\nusing namespace std;\n\
    #include \"base.hpp\"\n\nnamespace geometry {\n\nReal closest_pair(vector<Point>\
    \ pts) {\n    sort(pts.begin(), pts.end(), [] (const Point &p, const Point &q)\
    \ {\n        return p.x < q.x;\n    });\n    auto rec = [&] (const auto &rec,\
    \ int l, int r) -> Real {\n        if (r - l <= 1) return INF_REAL;\n        int\
    \ m = (l + r) / 2;\n        Real x = pts[m].x;\n        Real res = min(rec(rec,\
    \ l, m), rec(rec, m, r));\n        inplace_merge(pts.begin() + l, pts.begin()\
    \ + m, pts.begin() + r, [] (const Point &p, const Point &q) {\n            return\
    \ p.y < q.y;\n        });\n        vector<Point> pts2;\n        for (int i = l;\
    \ i < r; i++) {\n            if (res - abs(pts[i].x - x) <= eps) continue;\n \
    \           for (int j = ssize(pts2) - 1; j >= 0; j--) {\n                if (res\
    \ - abs(pts[i].y - pts2[j].y) <= eps) break;\n                res = min(res, metric(pts[i]\
    \ - pts2[j]));\n            }\n            pts2.push_back(pts[i]);\n        }\n\
    \        return res;\n    };\n    return rec(rec, 0, ssize(pts));\n}\n\n} // namespace\
    \ geometry"
  dependsOn:
  - src/geometry/real/base.hpp
  isVerificationFile: false
  path: src/geometry/real/closest_pair.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/real/closest_pair.hpp
layout: document
redirect_from:
- /library/src/geometry/real/closest_pair.hpp
- /library/src/geometry/real/closest_pair.hpp.html
title: src/geometry/real/closest_pair.hpp
---
