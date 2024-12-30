#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename mint>
struct combination {
    combination(int n = 0) { init(n); }
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
        if (n < 0 || k < 0 || n < k) return 0;
        if (n < min(1 << 25, mint::mod() - 1)) {
            init(n);
            return inner_fac[n] * inner_finv[n - k] * inner_finv[k];
        }
        init(k);
        mint res = inner_finv[k];
        for (int i = 0; i < k; i++) res *= n - i;
        return res;
    }
    mint multi_C(const vector<int> &v) {
        int n = 0;
        for (int c : v) n += c;
        init(n);
        mint res = inner_fac[n];
        for (int c : v) res *= inner_finv[c];
        return res;
    }
    mint P(int n, int k) {
        if (n < 0 || k < 0 || n < k) return 0;
        return inner_fac[n] * inner_finv[n - k];
    }
    mint catalan(int n) {
        init(2 * n);
        return inner_fac[2 * n] * inner_finv[n] * inner_finv[n + 1];
    }
    mint grid_path(int n, int m) {
        init(n + m);
        return inner_fac[n + m] * inner_finv[n] * inner_finv[m];
    }
private:
    static vector<mint> inner_fac, inner_finv;
    static void init(int n) {
        int sz = inner_fac.size();
        if (n < sz) return;
        n = clamp(n, 2 * sz, min(1 << 25, mint::mod() - 1));
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
template<typename mint>
vector<mint> combination<mint>::inner_fac(1, 1);
template<typename mint>
vector<mint> combination<mint>::inner_finv(1, 1);