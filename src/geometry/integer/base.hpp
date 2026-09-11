#pragma once
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
#include "../../misc/fraction.hpp"
using namespace std;

namespace geometry {

using T = int;
using U = long long;
using F = fraction<U>;
constexpr T INF_T = numeric_limits<T>::max();

int sgn(const T &t) {
    return t == 0 ? 0 : t > 0 ? 1 : -1;
}

int sgn(const F &a) {
    U n = a.numerator();
    return n == 0 ? 0 : n > 0 ? 1 : -1;
}

struct Point {
    F x, y;
    constexpr Point() : Point(0, 0) {}
    constexpr Point(F _x, F _y) : x(_x), y(_y) {}
    constexpr Point(const pair<F, F> &p) : x(p.first), y(p.second) {}
    Point &operator+=(const Point &p) {
        x += p.x;
        y += p.y;
        return *this;
    }
    Point &operator-=(const Point &p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }
    Point operator*=(const F &r) {
        x *= r;
        y *= r;
    }
};

};