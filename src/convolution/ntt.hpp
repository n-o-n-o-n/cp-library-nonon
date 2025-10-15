#pragma once
#include <vector>
#include "../math/number_theory/primitive_root.hpp"
using namespace std;

template<typename mint>
struct Number_Theoretic_Transform {
    static int log, mod;
    static mint root;
    static vector<mint> dw, idw;
    static vector<mint> rt2, irt2;
    static vector<mint> rt3, irt3;
    static void ntt(vector<mint> &f) {
        init();
        int n = f.size();
        int h = 0;
        while ((1 << h) < n) h++;
        int len = 0;
        while (len < h) {
            if (len == h - 1) {
                int p = 1 << (h - len - 1);
                mint r = 1;
                for (int s = 0; s < 1 << len; s++) {
                    int j = s << (h - len);
                    for (int i = 0; i < p; i++) {
                        mint a = f[i + j], b = f[i + j + p] * r;
                        f[i + j] = a + b;
                        f[i + j + p] = a - b;
                    }
                    if (s + 1 != (1 << len)) {
                        r *= rt2[__builtin_ctz(~s)];
                    }
                }
                len++;
            } else {
                int p = 1 << (h - len - 2);
                mint r = 1, imag = dw[2];
                for (int s = 0; s < 1 << len; s++) {
                    mint r2 = r * r;
                    mint r3 = r * r2;
                    int j = s << (h - len);
                    for (int i = 0; i < p; i++) {
                        unsigned long long m2 = (unsigned long long)mod * mod;
                        unsigned long long a0 = (unsigned long long)f[i + j].val();
                        unsigned long long a1 = (unsigned long long)f[i + j + p].val() * r.val();
                        unsigned long long a2 = (unsigned long long)f[i + j + p + p].val() * r2.val();
                        unsigned long long a3 = (unsigned long long)f[i + j + p + p + p].val() * r3.val();
                        unsigned long long t0 = (unsigned long long)mint(m2 + a1 - a3).val() * imag.val();
                        unsigned long long t1 = m2 - a2;
                        f[i + j] = a0 + a1 + a2 + a3;
                        f[i + j + p] = a0 + a2 + (m2 + m2 - a1 - a3);
                        f[i + j + p + p] = a0 + t0 + t1;
                        f[i + j + p + p + p] = a0 + t1 + (m2 - t0);
                    }
                    if (s + 1 != (1 << len)) {
                        r *= rt3[__builtin_ctz(~s)];
                    }
                }
                len += 2;
            }
        }
    }
    static void intt(vector<mint> &f) {
        init();
        int n = f.size();
        int h = 0;
        while ((1 << h) < n) h++;
        int len = h;
        while (len > 0) {
            if (len == 1) {
                len--;
                int p = 1 << (h - len - 1);
                mint ir = 1;
                for (int s = 0; s < 1 << len; s++) {
                    int j = s << (h - len);
                    for (int i = 0; i < p; i++) {
                        mint a = f[i + j], b = f[i + j + p];
                        f[i + j] = a + b;
                        f[i + j + p] = (a - b) * ir;
                    }
                    if (s + 1 != (1 << len)) {
                        ir *= irt2[__builtin_ctz(~s)];
                    }
                }
            } else {
                len -= 2;
                int p = 1 << (h - len - 2);
                mint ir = 1, iimag = idw[2];
                for (int s = 0; s < 1 << len; s++) {
                    mint ir2 = ir * ir;
                    mint ir3 = ir * ir2;
                    int j = s << (h - len);
                    for (int i = 0; i < p; i++) {
                        unsigned long long a0 = (unsigned long long)f[i + j].val();
                        unsigned long long a1 = (unsigned long long)f[i + j + p].val();
                        unsigned long long a2 = (unsigned long long)f[i + j + p + p].val();
                        unsigned long long a3 = (unsigned long long)f[i + j + p + p + p].val();
                        unsigned long long t0 = (unsigned long long)(mint(mod + a2 - a3) * iimag).val();
                        f[i + j] = a0 + a1 + a2 + a3;
                        f[i + j + p] = (mod + a0 - a1 + t0) * ir.val();
                        f[i + j + p + p] = (mod + mod + a0 + a1 - a2 - a3) * ir2.val();
                        f[i + j + p + p + p] = (mod + mod + a0 - a1 - t0) * ir3.val();
                    }
                    if (s + 1 != (1 << len)) {
                        ir *= irt3[__builtin_ctz(~s)];
                    }
                }
            }
        }
        const mint invn = mint::raw(n).inv();
        for (auto &e : f) e *= invn;
    }
private:
    Number_Theoretic_Transform() = default;
    static void init() {
        if (mod != -1) return;
        mod = mint::mod();
        root = primitive_root(mod);
        while (!((mod - 1) >> log & 1)) log++;
        dw = idw = rt2 = irt2 = rt3 = irt3 = vector<mint>(log + 1);
        dw[log] = root.pow((mod - 1) >> log);
        idw[log] = dw[log].inv();
        for (int i = log - 1; i >= 0; i--) {
            dw[i] = dw[i + 1] * dw[i + 1];
            idw[i] = idw[i + 1] * idw[i + 1];
        }
        mint pd = 1, ipd = 1;
        for (int i = 0; i < log - 1; i++) {
            rt2[i] = pd * dw[i + 2];
            irt2[i] = ipd * idw[i + 2];
            pd *= idw[i + 2];
            ipd *= dw[i + 2];
        }
        pd = ipd = 1;
        for (int i = 0; i < log - 2; i++) {
            rt3[i] = pd * dw[i + 3];
            irt3[i] = ipd * idw[i + 3];
            pd *= idw[i + 3];
            ipd *= dw[i + 3];
        }
    }
};
template<typename mint>
int Number_Theoretic_Transform<mint>::log = 0;
template<typename mint>
int Number_Theoretic_Transform<mint>::mod = -1;
template<typename mint>
mint Number_Theoretic_Transform<mint>::root = -1;
template<typename mint>
vector<mint> Number_Theoretic_Transform<mint>::dw = vector<mint>();
template<typename mint>
vector<mint> Number_Theoretic_Transform<mint>::idw = vector<mint>();
template<typename mint>
vector<mint> Number_Theoretic_Transform<mint>::rt2 = vector<mint>();
template<typename mint>
vector<mint> Number_Theoretic_Transform<mint>::irt2 = vector<mint>();
template<typename mint>
vector<mint> Number_Theoretic_Transform<mint>::rt3 = vector<mint>();
template<typename mint>
vector<mint> Number_Theoretic_Transform<mint>::irt3 = vector<mint>();
