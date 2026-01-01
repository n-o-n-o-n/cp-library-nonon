#pragma once
#include <vector>
#include "extended_gcd.hpp"
using namespace std;

long long garner(const vector<long long> &rems, vector<long long> mods, long long mod) {
    mods.push_back(mod);
    int n = mods.size();
    vector<long long> c1(n, 1), c2(n, 0);
    for (int i = 0; i < n - 1; i++) {
        long long m = mods[i], a = c1[i], b = (rems[i] - c2[i]) % m;
        if (b < 0) b += m;
        long long x, y;
        long long g = extended_gcd(a, m, x, y);
        if (b % g != 0) return -1;
        m /= g, b /= g;
        x %= m;
        if (x < 0) x += m;
        long long t = x * b % m;
        for (int j = i + 1; j < n; j++) {
            c2[j] = (t * c1[j] + c2[j]) % mods[j];
            c1[j] = c1[j] * m % mods[j];
        }
    }
    return c2.back();
}
