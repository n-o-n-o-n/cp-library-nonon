#pragma once
#include "line.hpp"
using namespace std;

namespace geometry {

struct Segment {
    Line l;
    Point p, q;
    Segment() = default;
    Segment(const Point &_p, const Point &_q) : l(_p, _q), p(_p), q(_q) {}
    bool cross(const Segment &s) const {
        bool f1 = ccw(p, q, s.p) * ccw(p, q, s.q) <= 0;
        bool f2 = ccw(s.p, s.q, p) * ccw(s.p, s.q, q) <= 0;
        return f1 && f2;
    }
    Point crosspoint(const Segment &s) const {
        if (cross(s)) return l.crossppoint(s.l);
        return INF_POINT;
    }
    Real dist(const Point &r) const {
        if (dot(q - p, r - p) < eps) return (r - p).metric();
        if (dot(p - q, r - q) < eps) return (r - q).metric();
        return l.dist(r);
    }
    Real dist(const Segment &s) const {
        if (cross(s)) return 0;
        Real res = INF_REAL;
        res = min(res, dist(s.p));
        res = min(res, dist(s.q));
        res = min(res, s.dist(p));
        res = min(res, s.dist(q));
        return res;
    }
};

bool cross(const Segment &s, const Segment &t) {
    return s.cross(t);
}

Point crosspoint(const Segment &s, const Segment &t) {
    return s.crosspoint(t);
}

Real dist(const Segment &s, const Segment &t) {
    return s.dist(t);
}

} // nemespace geometry