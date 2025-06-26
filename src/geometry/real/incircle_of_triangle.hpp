#pragma once
#include "line.hpp"
#include "circle.hpp"
using namespace std;

namespace geometry {

circle incircle_of_triangle(const Point &p1, const Point &p2, const Point &p3) {
    Real a1 = metric(p2 - p3), a2 = metric(p3 - p1), a3 = metric(p1 - p2);
    Point p = a1 * p1 + a2 * p2 + a3 * p3;
    p /= a1 + a2 + a3;
    Real r = Line(p1, p2).dist(p);
    return circle(p, r);
}

} // namespace geometry