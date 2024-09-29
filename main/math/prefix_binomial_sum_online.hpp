#pragma once
#include <vector>
using namespace std;

template<typename mint>
struct prefix_binomial_sum {
    prefix_binomial_sum(int n) : size(n), b(0) {}
    mint get(int n, int k) {
        assert(0 <= n && n <= size);
        build();
        int tn = (n + b / 2) / b;
        int tk = (k + b / 2) / b;
        mint res = table[tn][tk];
        tn *= b;
        tk *= b;
        while (tn < n) res = 2 * res - binom(tn++, tk);
        while (tn > n) res = (res + binom(--tn, tk)) * inv2;
        while (tk < k) res = res + binom(tn, ++tk);
        while (tk > k) res = res - binom(tn, tk--);
        return res;
    }
private:
    int size, b;
    mint inv2;
    vector<mint> fac, finv;
    vector<vector<mint>> table;
    mint binom(int n, int k) {
        if (n < k) return 0;
        return fac[n] * finv[n - k] * finv[k];
    }
    void build() {
        if (b > 0) return;
        b = 400;
        size += b;
        inv2 = mint(2).inv();
        int n = (size + b - 1) / b;
        fac.resize(size + 1);
        finv.resize(size + 1);
        table.resize(n + 1);
        fac[0] = 1;
        for (int i = 1; i <= size; i++) {
            fac[i] = i * fac[i - 1];
        }
        finv[size] = fac[size].inv();
        for (int i = size; i >= 1; i--) {
            finv[i - 1] = i * finv[i];
        }
        for (int i = 0; i <= n; i++) {
            table[i].resize(n + 1);
            table[i][0] = 1;
            mint cur = 1;
            for (int j = 1; j <= n * b; j++) {
                cur += binom(b * i, j);
                if (j % b == 0) {
                    table[i][j / b] = cur;
                }
            }
        }
    }
};