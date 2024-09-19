#pragma once
#include <vector>
using namespace std;

template<typename mint>
struct Number_Theoretic_Transform {
    static vector<mint> dw, dw_inv;
    static int log;
    static mint root;
    static void ntt(vector<mint> &f) {
        init();
        int n = f.size();
        for (int m = n; m >>= 1;) {
            mint w = 1;
            for (int s = 0, k = 0; s < n; s += (m << 1)) {
                for (int i = s, j = s + m; i < s + m; i++, j++) {
                    mint a = f[i], b = f[j] * w;
                    f[i] = a + b;
                    f[j] = a - b;
                }
                w *= dw[__builtin_ctz(++k)];
            }
        }
    }
    static void intt(vector<mint> &f) {
        init();
        int n = f.size();
        for (int m = 1; m < n; m <<= 1) {
            mint w = 1;
            for (int s = 0, k = 0; s < n; s += (m << 1)) {
                for (int i = s, j = s + m; i < s + m; i++, j++) {
                    mint a = f[i], b = f[j];
                    f[i] = a + b;
                    f[j] = (a - b) * w;
                }
                w *= dw_inv[__builtin_ctz(++k)];
            }
        }
        mint invn = mint(n).inv();
        for (mint &x : f) x *= invn;
    }
private:
    Number_Theoretic_Transform() = default;
    static void init() {
        if (log > 0) return;
        int mod = mint::mod();
        int tmp = mod - 1;
        log = 1;
        while (tmp % 2 == 0) {
            tmp >>= 1;
            log++;
        }
        dw.resize(log);
        dw_inv.resize(log);
        for (int i = 0; i < log; i++) {
            dw[i] = -root.pow((mod - 1) >> (i + 2));
            dw_inv[i] = dw[i].inv();
        }
    }
};
template<typename mint>
vector<mint>Number_Theoretic_Transform<mint>::dw = vector<mint>();
template<typename mint>
vector<mint>Number_Theoretic_Transform<mint>::dw_inv = vector<mint>();
template<typename mint>
int Number_Theoretic_Transform<mint>::log = 0;
template<typename mint>
mint Number_Theoretic_Transform<mint>::root = 3;