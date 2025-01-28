#pragma once
#include <vector>
#include "mod_inv.hpp"
using namespace std;

long long garner(const vector<long long> &rems, vector<long long> mods, long long mod) {
    mods.push_back(mod);
    int n = mods.size();
    vector<long long> c1(n, 1), c2(n, 0);
    for (int i = 0; i < n - 1; i++) {
        long long t = (rems[i] - c2[i]) * mod_inv(c1[i], mods[i]) % mods[i];
        if (t < 0) t += mods[i];
        for (int j = i + 1; j < n; j++) {
            c2[j] = (t * c1[j] + c2[j]) % mods[j];
            c1[j] = c1[j] * mods[i] % mods[j];
        }
    }
    return c2.back();
}
