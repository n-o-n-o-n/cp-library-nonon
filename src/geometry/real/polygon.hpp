#pragma once
#include <algorithm>
#include <vector>
#include "base.hpp"
using namespace std;

namespace geometry {

struct Polygon : vector<Point> {
    using vector<Point>::vector;
    Polygon(const vector<Point>& pts) : vector<Point>(pts) {}
    int contain(const Point &p) const {
        int n = this->size();
        bool in = false;
        for (int i = 0; i < n; i++) {
            Point a = (*this)[i] - p;
            Point b = (*this)[i == n - 1 ? 0 : i + 1] - p;
            // need std::
            if (Im(a) > Im(b)) std::swap(a, b);
            if (sgn(Im(a)) <= 0 && 0 < sgn(Im(b)) && sgn(cross(a, b)) < 0) in = !in;
            if (is_same(cross(a, b), 0) && sgn(dot(a, b)) <= 0) return 1;
        }
        return in ? 2 : 0;
    }
    Real area() const {
        int n = this->size();
        Real S = 0;
        for (int i = 0; i < n; i++) {
            Point a = (*this)[i];
            Point b = (*this)[i == n - 1 ? 0 : i + 1];
            S += cross(a, b);
        }
        return S * 0.5;
    }
    bool is_convex() const {
        int n = this->size();
        if (n <= 2) return false;
        for (int i = 0, j = 1, k = 2; i < n; i++, j++, k++) {
            if (j == n) j = 0;
            if (k == n) k = 0;
            if (ccw((*this)[i], (*this)[j], (*this)[k]) == -1) return false;
        }
        return true;
    }
    void relabeling() {
        Real x_min = INF_REAL, y_min = INF_REAL;
        int idx = 0, n = this->size();
        for (int i = 0; i < n; i++) {
            Real x = (*this)[i].x, y = (*this)[i].y;
            if (y < y_min || (is_same(y, y_min) && x < x_min)) {
                x_min = x;
                y_min = y;
                idx = i;
            }
        }
        Polygon tmp(n);
        int pre = (idx + n - 1) % n, nxt = (idx + 1) % n;
        if (ccw((*this)[idx], (*this)[pre], (*this)[nxt]) == -1) {
            for (int i = 0; i < n; i++) {
                tmp[i] = (*this)[(idx + i) % n];
            }
        } else {
            for (int i = 0; i < n; i++) {
                tmp[i] = (*this)[(idx + n - i) % n];
            }
        }
        *this = tmp;
    }
};

} // namespace geometry