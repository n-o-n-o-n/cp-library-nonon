#pragma once
#include "line.hpp"
#include "circle.hpp"
using namespace std;

namespace geometry {

circle circumcircle_of_triangle(const Point &p1, const Point &p2, const Point &p3) {
    Point p12 = p1 - p2, p23 = p2 - p3;
    Real d = 2 * cross(p12, p23);
    Real t12 = norm(p1) - norm(p2), t23 = norm(p2) - norm(p3);
    Point p = (t12 * p23 - t23 * p12) / d;
    swap(p.x, p.y);
    p.y = -p.y;
    Real r = metric(p1 - p);
    return circle(p, r);
}

} // namespace geometry