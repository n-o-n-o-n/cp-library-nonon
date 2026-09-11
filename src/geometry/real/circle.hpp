#pragma once
#include <vector>
#include "segmant.hpp"
#include "polygon.hpp"
using namespace std;

namespace geometry {

// { x in R^2 | |x - p| = r}
struct circle {
    Point p;
    Real r;
    circle() = default;
    circle(const Point _p, Real _r) : p(_p), r(_r) {}
    int count_common_tangent(const circle &c) const {
        Real d = metric(p - c.p);
        if (d > r + c.r + eps) return 4;
        if (equal_eps(d, r + c.r)) return 3;
        if (equal_eps(d, abs(r - c.r))) return 1;
        if (d < abs(r - c.r) - eps) return 0;
        return 2;
    }
    bool contain(const Point &q) const {
        return metric(p, q) <= r + eps;
    }
    vector<Point> crosspoints(const Line &l) const {
        Real d = l.dist(p);
        if (d > r + eps) return {};
        Point q = l.projection(p);
        if (equal_eps(d, r)) {
            return {q};
        }
        Point e = l.unit();
        Real t = sqrtl(r * r - d * d);
        return {q - t * e, q + t * e};
    }
    vector<Point> crosspoints(const Segment &s) const {
        vector<Point> res;
        for (Point p : crosspoints(s.l)) {
            if (s.on_segment(p)) res.push_back(p);
        }
        return res;
    }
    vector<Point> crosspoints(const circle &c) const {
        int t = count_common_tangent(c);
        if (t == 0 || t == 4) return {};
        Real d = metric(p - c.p);
        if (t == 1) {
            if (c.r < r - eps) {
                return {p + (c.p - p) * (r / d)};
            } else {
                return {c.p + (p - c.p) * (c.r / d)};
            }
        } else if (t == 3) {
            geometry::Real s = r / (r + c.r);
            return {p + (c.p - p) * s};
        } else {
            geometry::Real la = 2 * (p.x - c.p.x);
            geometry::Real lb = 2 * (p.y - c.p.y);
            geometry::Real lc = (p.x + c.p.x) * (p.x - c.p.x) + (p.y + c.p.y) * (p.y - c.p.y) + (r + c.r) * (c.r - r);
            return crosspoints(Line(la, lb, lc));
        }
    }
    vector<Point> points_of_tangency(const Point &q) const {
        Real d = metric(p - q);
        if (d < r - eps) return {};
        if (equal_eps(d, r)) return {q};
        return crosspoints(circle(q, sqrtl(d * d - r * r)));
    }
    vector<Point> points_of_common_tangency(const circle &c) const {
        Real d = metric(p - c.p);
        if (equal_eps(d, 0)) return {};
        Point u = (c.p - p).unit();
        Point v = u.rotate(PI / 2);
        vector<Point> res;
        for (int s : {-1, 1}) {
            Real h = (r + s * c.r) / d;
            if (equal_eps(h * h, 1)) {
                res.push_back(p + (h > 0 ? u : -u) * r);
            } else if (1 - h * h > 0) {
                Point u2 = u * h, v2 = v * sqrtl(1 - h * h);
                res.push_back(p + (u2 + v2) * r);
                res.push_back(p + (u2 - v2) * r);
            }
        }
        return res;
    }
    Real area_of_intersection(const Polygon &g) const {
        auto f = [&] (Point a, Point b) -> Real {
            Real res = 0;
            auto ps = circle(Point(0, 0), r).crosspoints(Segment(a, b));
            if (a.norm() < r * r - eps && b.norm() < r * r - eps) {
                res += cross(a, b);
            } else if (a.norm() < r * r - eps) {
                assert(ps.size());
                res += cross(a, ps[0]);
                res += r * r * angle(Point(0, 0), ps[0], b);
            } else if (b.norm() < r * r - eps) {
                assert(ps.size());
                res += r * r * angle(Point(0, 0), a, ps[0]);
                res += cross(ps[0], b);
            } else {
                if (ps.empty()) {
                    res += r * r * angle(Point(0, 0), a, b);
                } else {
                    Point pa = ps.front(), pb = ps.back();
                    if (norm(a - pa) > norm(a - pb)) swap(pa, pb);
                    res += r * r * angle(Point(0, 0), a, pa);
                    res += cross(pa, pb);
                    res += r * r * angle(Point(0, 0), pb, b);
                }
            }
            return res;
        };
        int n = g.size();
        Real S = 0;
        for (int i = 0; i < n; i++) {
            Point a = g[i] - p;
            Point b = g[i == n - 1 ? 0 : i + 1] - p;
            if (abs(ccw(p, a, b)) == 1) S += f(a, b);
        }
        return 0.5 * S;
    }
};

} // namespace geometry