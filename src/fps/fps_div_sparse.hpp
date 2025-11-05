#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename mint>
vector<mint> fps_div_sparse(vector<mint> f, const vector<pair<int, mint>> &g_sub) {
    assert(g_sub.size() && g_sub[0].first == 0 && g_sub[0].second != 0);
    int n = f.size();
    mint cef = g_sub[0].second.inv();
    for (int i = 0; i < n; i++) {
        f[i] *= cef;
        for (auto [a, c] : g_sub) {
            if (0 < a && i + a < n) {
                f[i + a] -= f[i] * c;
            }
        }
    }
    return f;
}
