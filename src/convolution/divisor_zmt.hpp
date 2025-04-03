#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename mint>
void divisor_zmt(vector<mint> &f, bool moebius = false) {
    int n = f.size();
    vector<bool> sieve(n, true);
    for (int i = 2; i < n; i++) {
        if (sieve[i]) {
            if (moebius) {
                for (int j = (n - 1) / i; j > 0; j--) {
                    sieve[i * j] = false;
                    f[i * j] -= f[j];
                }
            } else {
                for (int j = 1; i * j < n; j++) {
                    sieve[i * j] = false;
                    f[i * j] += f[j];
                }
            }
        }
    }
}
