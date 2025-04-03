#pragma once
#include <cassert>
#include <cmath>
#include <numeric>
using namespace std;

// 書きかけの幾何ライブラリ
// バグがあるかも

namespace geometry {

using Real = long double;
constexpr Real eps = 1e-12;
constexpr Real PI = acosl(-1);
constexpr Real INF_REAL = numeric_limits<Real>::max();

bool is_same(Real a, Real b) {
    return abs(a - b) < eps;
}

int sgn(Real a) {
    return is_same(a, 0) ? 0 : a > 0 ? 1 : -1;
}

struct Point {
    Real x, y;
    constexpr Point() : Point(0, 0) {}
    constexpr Point(Real _x, Real _y) : x(_x), y(_y) {}
    constexpr Point(const pair<Real, Real> &p) : x(p.first), y(p.second) {}
    Point &operator+=(const Point &p) {
        x += p.x;
        y += p.y;
        return *this;
    }
    Point &operator-=(const Point &p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }
    Point &operator*=(const Real &r) {
        x *= r;
        y *= r;
        return *this;
    }
    Point &operator/=(const Real &r) {
        assert(!is_same(r, 0));
        x /= r;
        y /= r;
        return *this;
    }
    Point operator+(const Point &p) const { return Point(*this) += p; }
    Point operator-(const Point &p) const { return Point(*this) -= p; }
    Point operator*(const Real &r) const { return Point(*this) *= r; }
    Point operator/(const Real &r) const { return Point(*this) /= r; }
    Point operator-() const { return Point() - *this; }
    bool operator==(const Point &p) const {
        return is_same(x, p.x) && is_same(y, p.y);
    }
    bool operator!=(const Point &p) const {
        return !is_same(x, p.x) || !is_same(y, p.y);
    }
    Point rotate(Real rad) const {
        Real c = cosl(rad), s = sinl(rad);
        Real tx = x * c - y * s;
        Real ty = x * s + y * c;
        return Point(tx, ty);
    }
    Real Re() const { return x; }
    Real Im() const { return y; }
    Real norm() const { return x * x + y * y; }
    Real abs() const { return sqrtl(norm()); }
    Real arg() const { return atan2l(y, x); }
    friend Point operator*(Real r, const Point &p) {
        return p * r;
    }
    friend Point operator/(Real r, const Point &p) {
        return p / r;
    }
};

Real Re(const Point &p) { return p.Re(); }
Real Im(const Point &p) { return p.Im(); }
Real dot(const Point &p, const Point &q) {
    return p.x * q.x + p.y * q.y;
}
Real cross(const Point &p, const Point &q) {
    return p.x * q.y - p.y * q.x;
}
Real norm(const Point &p) {
    return p.norm();
}
Real abs(const Point &p) {
    return p.abs();
}
Real arg(const Point &p) {
    return p.arg();
}

constexpr Point INF_POINT = Point(INF_REAL, INF_REAL);

// a を基準にした b と c の位置関係
int ccw(const Point &a, const Point &b, const Point &c) {
    Point p = b - a, q = c - a;
    if (cross(p, q) > eps) return 1; // a, b, c の順で反時計回り
    if (cross(p, q) < -eps) return -1; // a, b, c の順で時計回り
    if (min(norm(p), norm(q)) < eps * eps) return 0; // a = c or b = c
    if (dot(p, q) < eps) return 2; // c, a, b の順で一直線
    if (norm(p) < norm(q)) return -2; // a, b, c の順で一直線
    return 0; // a, c, b の順で一直線
}

} // namespace geometry