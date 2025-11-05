#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename mint>
vector<mint> fps_inv_sparse(const vector<pair<int, mint>> &f_sub, int n) {
    assert(f_sub.size() && f_sub[0].first == 0 && f_sub[0].second != 0);
    mint cef = f_sub[0].second.inv();
    vector<mint> g(n);
    g[0] = 1;
    for (int i = 0; i < n; i++) {
        if (g[i] != 0) {
            g[i] *= cef;
            for (auto [a,c] : f_sub) {
                if (0 < a && i + a < n) {
                    g[i + a] -= g[i] * c;
                }
            }
        }
    }
    return g;
}