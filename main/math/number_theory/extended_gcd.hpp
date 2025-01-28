#pragma once
#include <utility>
using namespace std;

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