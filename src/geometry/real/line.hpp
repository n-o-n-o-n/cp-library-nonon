#pragma once
#include <cassert>
#include "base.hpp"
using namespace std;

namespace geometry {

struct Line {
    // Line : ax + by = c
    Real a, b, c;
    constexpr Line() = default;
    constexpr Line(Real _a, Real _b, Real _c) : a(_a), b(_b), c(_c) {}
    constexpr Line(const Point &p, const Point &q) : a(q.y - p.y), b(p.x - q.x), c(p.x * q.y - p.y * q.x) {}
    constexpr Line(Real _a, const Point &p) : a(_a), b(-1), c(_a * p.x - p.y) {}
    bool online(const Point &p) const {
        return is_same(a * p.x + b * p.y, c);
    }
    Real get_x(Real y) const {
        if (is_same(a, 0)) return INF_REAL;
        return (c - b * y) / a;
    }
    Real get_y(Real x) const {
        if (is_same(b, 0)) return INF_REAL;
        return (c - a * x) / b;
    }
    Line perpendicular(const Point &p) const {
        if (is_same(a, 0)) return Line(1, 0, p.x);
        if (is_same(0, b)) return Line(0, 1, p.y);
        return Line(b / a, p);
    }
    Point crossppoint(const Line &l) const {
        if (is_same(a * l.b, l.a * b)) return INF_POINT;
        Real d = a * l.b - l.a * b;
        return Point(l.b * c - b * l.c, l.c * a - c * l.a) / d;
    }
    Point projection(const Point &p) const {
        return crossppoint(perpendicular(p));
    }
    Point reflection(const Point &p) const {
        Point q = projection(p);
        return 2 * q - p;
    }
    bool is_orthogonal(const Line &l) const {
        return is_same(a * l.a + b * l.b, 0);
    }
    bool is_parallel(const Line &l) const {
        return is_same(a * l.b, l.a * b);
    }
    Real dist(const Point &p) const {
        Point q = projection(p);
        return abs(p - q);
    }
};

bool is_orthogonal(const Line &l1, const Line &l2) {
    return l1.is_orthogonal(l2);
}
bool is_parallel(const Line &l1, const Line &l2) {
    return l1.is_parallel(l2);
}
Point crosspoint(const Line &l1, const Line &l2) {
    return l1.crossppoint(l2);
}

} // namespace geometry