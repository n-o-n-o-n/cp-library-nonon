#pragma once
#include "line.hpp"
using namespace std;

namespace geometry {

struct Segment {
    Line l;
    Point a, b;
    Segment() = default;
    Segment(const Point &_a, const Point &_b) : l(_a, _b), a(_a), b(_b) {}
    bool has_intersection(const Segment &s) const {
        bool f1 = ccw(a, b, s.a) * ccw(a, b, s.b) <= 0;
        bool f2 = ccw(s.a, s.b, a) * ccw(s.a, s.b, b) <= 0;
        return f1 && f2;
    }
    bool on_segment(const Point &p) const {
        Point ab = b - a, ap = p - a, bp = p - b;
        if (abs(cross(ab, ap)) > eps) return false;
        return dot(ab, ap) >= -eps && dot(ab, bp) <= eps;
    }
    Point crosspoint(const Segment &s) const {
        if (has_intersection(s)) return l.crossppoint(s.l);
        return INF_POINT;
    }
    Real dist(const Point &p) const {
        if (dot(b - a, p - a) < eps) return (p - a).metric();
        if (dot(a - b, p - b) < eps) return (p - b).metric();
        return l.dist(p);
    }
    Real dist(const Segment &s) const {
        if (has_intersection(s)) return 0;
        Real res = INF_REAL;
        res = min(res, dist(s.a));
        res = min(res, dist(s.b));
        res = min(res, s.dist(a));
        res = min(res, s.dist(b));
        return res;
    }
};

inline bool has_intersection(const Segment &s, const Segment &t) { return s.has_intersection(t); }
inline Point crosspoint(const Segment &s, const Segment &t) { return s.crosspoint(t); }
inline Real dist(const Segment &s, const Segment &t) { return s.dist(t); }

} // nemespace geometry