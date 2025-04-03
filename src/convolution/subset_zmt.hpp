#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename mint>
void subset_zmt(vector<mint> &f, bool moebius = false) {
    int n = f.size();
    assert((n & (n - 1)) == 0);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if (i & j) continue;
            f[i | j] += moebius ? -f[j] : f[j];
        }
    }
}