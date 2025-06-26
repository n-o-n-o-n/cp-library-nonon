#pragma once
#include <algorithm>
#include <vector>
using namespace std;
#include "base.hpp"

namespace geometry {

Real closest_pair(vector<Point> pts) {
    sort(pts.begin(), pts.end(), [] (const Point &p, const Point &q) {
        return p.x < q.x;
    });
    auto rec = [&] (const auto &rec, int l, int r) -> Real {
        if (r - l <= 1) return INF_REAL;
        int m = (l + r) / 2;
        Real x = pts[m].x;
        Real res = min(rec(rec, l, m), rec(rec, m, r));
        inplace_merge(pts.begin() + l, pts.begin() + m, pts.begin() + r, [] (const Point &p, const Point &q) {
            return p.y < q.y;
        });
        vector<Point> pts2;
        for (int i = l; i < r; i++) {
            if (res - abs(pts[i].x - x) <= eps) continue;
            for (int j = ssize(pts2) - 1; j >= 0; j--) {
                if (res - abs(pts[i].y - pts2[j].y) <= eps) break;
                res = min(res, metric(pts[i] - pts2[j]));
            }
            pts2.push_back(pts[i]);
        }
        return res;
    };
    return rec(rec, 0, ssize(pts));
}

} // namespace geometry