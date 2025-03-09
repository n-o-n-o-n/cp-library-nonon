#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename mint>
void fwht(vector<mint> &f, bool inv = false) {
    int n = f.size();
    assert((n & (n - 1)) == 0);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if (i & j) continue;
            mint s = f[j], t = f[i | j];
            f[j] = s + t, f[i | j] = s - t;
        }
    }
    if (inv) {
        mint cef = mint(n).inv();
        for (mint &c : f) c *= cef;
    }
}