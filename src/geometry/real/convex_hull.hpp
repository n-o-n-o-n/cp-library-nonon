#pragma once
#include <cassert>
#include <vector>
#include "base.hpp"
#include "polygon.hpp"
using namespace std;

namespace geometry {

Polygon convex_hull(vector<Point> pts, bool exclude_collinear = true) {
    int n = pts.size(), k = 0;
    sort(pts.begin(), pts.end(), [](const Point &p, const Point &q){
        return equal_eps(Re(p), Re(q)) ? Im(p) < Im(q) : Re(p) < Re(q);
    });
    vector<Point> ch(2 * n);
    for (int i = 0; i < n; ch[k++] = pts[i++]) {
        while ((k >= 2 && [&] {
            Real d = cross(ch[k - 1] - ch[k - 2], pts[i] - ch[k - 1]);
            return exclude_collinear ? d < eps : d < -eps;
        }()) || (k >= 1 && ch[k - 1] == pts[i])) k--;
    }
    for (int i = n - 2, j = k + 1; i >= 0; ch[k++] = pts[i--]) {
        while ((k >= j && k >= 2 && [&] {
            Real d = cross(ch[k - 1] - ch[k - 2], pts[i] - ch[k - 1]);
            return exclude_collinear ? d < eps : d < -eps;
        }()) || (k >= 1 && ch[k - 1] == pts[i])) k--;
    }
    ch.resize(k - 1);
    return Polygon(ch);
}

} // namespace geometry