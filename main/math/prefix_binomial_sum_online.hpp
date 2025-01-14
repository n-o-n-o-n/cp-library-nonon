#pragma once
#include <vector>
using namespace std;
#include "combination.hpp"

template<typename mint>
struct prefix_binomial_sum {
    prefix_binomial_sum(int n) : size(n), b(400) { build(); }
    mint get(int n, int k) const {
        assert(0 <= n && n <= size);
        int tn = (n + b / 2) / b;
        int tk = (k + b / 2) / b;
        mint res = table[tn][tk];
        tn *= b;
        tk *= b;
        while (tk < k) res = res + combination::nCk<mint>(tn, ++tk);
        while (tk > k) res = res - combination::nCk<mint>(tn, tk--);
        while (tn < n) res = 2 * res - combination::nCk<mint>(tn++, tk);
        while (tn > n) res = (res + combination::nCk<mint>(--tn, tk)) * inv2;
        return res;
    }
private:
    int size, b;
    mint inv2;
    vector<vector<mint>> table;
    void build() {
        size += b;
        inv2 = mint::raw(2).inv();
        int n = (size + b - 1) / b;
        table.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            table[i].resize(n + 1);
            table[i][0] = 1;
            mint cur = 1;
            for (int j = 1; j <= n * b; j++) {
                cur += combination::nCk<mint>(b * i, j);
                if (j % b == 0) {
                    table[i][j / b] = cur;
                }
            }
        }
    }
};