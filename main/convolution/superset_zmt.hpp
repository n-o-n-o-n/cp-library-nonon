#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename mint>
void superset_zmt(vector<mint> &f, bool moebius = false) {
    int n = f.size();
    assert((n & (n - 1)) == 0);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if (i & j) continue;
            f[j] += moebius ? -f[i | j] : f[i | j];
        }
    }
}