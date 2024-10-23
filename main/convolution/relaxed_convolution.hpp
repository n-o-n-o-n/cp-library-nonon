#pragma once
#include <cassert>
#include <vector>
using namespace std;

#include "../cp-library-nonon/main/convolution/ntt.hpp"

template<typename mint>
struct relaxed_convolution {
    using NTT = Number_Theoretic_Transform<mint>;
    relaxed_convolution(int _n) : n(_n), i(0) {
        a = vector<mint>(n + 1);
        b = vector<mint>(n + 1);
        c = vector<mint>(n + 1);
    }
    mint get(mint x, mint y) {
        assert(i <= n);
        a[i] = x;
        b[i] = y;
        c[i] += a[i] * b[0] + (i > 0 ? b[i] * a[0]: mint(0));
        i++;
        if (i > n) return c[i - 1];
        for(int d = 1, k = 0; d <= i; d <<= 1, k++) {
            if (i % (d << 1) != d) continue;
            vector<mint> f(d << 1), g(d << 1);
            if (i == d) {
                for (int j = 0; j < d; j++) {
                    f[j] = a[j];
                    g[j] = b[j];
                }
                NTT::ntt(f);
                NTT::ntt(g);
                for (int j = 0; j < d << 1; j++) f[j] *= g[j];
            } else {
                calc(k);
                for (int j = 0; j < d; j++) {
                    f[j] = a[i - d + j];
                    g[j] = b[i - d + j];
                }
                NTT::ntt(f);
                NTT::ntt(g);
                for (int j = 0; j < d << 1; j++) f[j] = f[j] * bs[k][j] + g[j] * as[k][j];
            }
            NTT::intt(f);
            for (int j = i; j < i + d && j <= n; j++) c[j] += f[d + j - i];
        }
        return c[i - 1];
    }
private:
    int n, i;
    vector<mint> a, b, c;
    vector<vector<mint>> as, bs;
    void calc(int k) {
        if (int(as.size()) <= k) {
            as.resize(k + 1);
            bs.resize(k + 1);
        }
        if (as[k].size()) return;
        int d = 1 << k;
        vector<mint> s(a.begin(), a.begin() + (d << 1));
        vector<mint> t(b.begin(), b.begin() + (d << 1));
        NTT::ntt(s);
        NTT::ntt(t);
        as[k] = s;
        bs[k] = t;
    }
};