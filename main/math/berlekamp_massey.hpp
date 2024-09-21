#pragma once
#include <algorithm>
#include <vector>
using namespace std;

template<typename mint>
vector<mint> Berlekamp_Massey(const vector<mint> &a) {
    int n = a.size();
    vector<mint> b = {1}, c = {1};
    b.reserve(n + 1);
    c.reserve(n + 1);
    mint y = 1;
    for (int d = 1; d <= n; d ++) {
        int k = b.size(), l = c.size();
        mint x = 0;
        for (int i = 0; i < l; i++) {
            x += c[i] * a[d - l + i];
        }
        b.push_back(0);
        k++;
        if (x == 0) continue;
        mint buf = x / y;
        if (l < k) {
            auto tmp = c;
            c.insert(c.begin(), k - l, 0);
            for (int i = 0; i < k; i++) {
                c[k - 1 - i] -= buf * b[k - 1 - i];
            }
            b = tmp;
            y = x;
        } else {
            for (int i = 0; i < k; i++) {
                c[l - 1 - i] -= buf * b[k - 1 - i];
            }
        }
    }
    reverse(c.begin(), c.end());
    for (mint &x : c) x = -x;
    return c;
}