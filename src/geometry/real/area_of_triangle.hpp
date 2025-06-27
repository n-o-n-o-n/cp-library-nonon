#pragma once
#include "base.hpp"
using namespace std;

namespace geometry {

Real area_of_triangle(Point p1, Point p2, Point p3) {
    p2 -= p1, p3 -= p1;
    return 0.5 * abs(cross(p2, p3));
}

} // namespace geometry