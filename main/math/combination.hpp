#pragma once
#include <cassert>
#include <vector>

template<typename mint>
struct combination {
    combination(int n = 0) : inner_fac(1, 1), inner_finv(1, 1) { init(n); }
    mint fac(int n) {
        init(n);
        return inner_fac[n];
    }
    mint finv(int n) {
        init(n);
        return inner_finv[n];
    }
    mint inv(int n) {
        assert(n > 0);
        init(n);
        return inner_finv[n] * inner_fac[n - 1];
    }
    mint C(int n, int k) {
        if (k < 0) return 0;
        if (n < 0) {
            int sgn = (k & 1 ? -1 : 1);
            return sgn * C(k - n - 1, k);
        }
        if (n < k) return 0;
        if (n < bound) {
            init(n);
            return inner_fac[n] * inner_finv[n - k] * inner_finv[k];
        }
        init(k);
        mint res = inner_finv[k];
        for (int i = 0; i < k; i++) res *= n - i;
        return res;
    }
    mint P(int n, int k) {
        if (n < 0 || k < 0 || n < k) return 0;
        return inner_fac[n] * inner_fac[n - k];
    }
    mint catalan(int n) {
        init(2 * n);
        return inner_fac[2 * n] * inner_finv[n] * inner_finv[n + 1];
    }
private:
    const int bound = 1 << 25;
    vector<mint> inner_fac, inner_finv;
    void init(int n) {
        assert(n < bound);
        int sz = inner_fac.size();
        if (n < sz) return;
        n = clamp(n, 2 * sz, bound);
        inner_fac.resize(n + 1);
        inner_finv.resize(n + 1);
        for (int i = sz; i <= n; i++) {
            inner_fac[i] = i * inner_fac[i - 1];
        }
        inner_finv[n] = inner_fac[n].inv();
        for (int i = n; i >= sz; i--) {
            inner_finv[i - 1] = i * inner_finv[i];
        }
    }
};