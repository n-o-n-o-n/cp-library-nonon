#pragma once
#include <utility>
using namespace std;

// find x, y s.t. ax + by = gcd(a, b) and return gcd(a, b)
template<typename T>
T extended_gcd(T a, T b, T &x, T &y) {
    T g = a;
    if (b != 0) {
        g = extended_gcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return g;
}