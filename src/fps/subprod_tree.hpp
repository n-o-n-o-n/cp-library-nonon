#pragma once
#include "fps.hpp"
#include "fps_inv.hpp"

template<typename mint>
struct subprod_tree {
    subprod_tree() : subprod_tree(vector<mint>()) {}
    subprod_tree(const vector<mint> &xs) : m(xs.size()), sz(1) {
        while (sz < m) sz <<= 1;
        d = vector<fps<mint>>(2 * sz, fps<mint>{});
        deg = vector<int>(2 * sz, 0);
        mint one = mint::raw(1);
        for (int i = 0; i < m; i++) {
            d[i + sz] = fps<mint>{-xs[i] + one, -xs[i] - one};
            deg[i + sz] = 1;
        }
        for (int i = sz - 1; i >= 1; i--) {
            int n = 2 * deg[2 * i];
            d[i] = d[2 * i];
            if (int k = d[2 * i + 1].size(); k > 0) {
                for (int j = 0; j < k; j++) d[i][j] *= d[2 * i + 1][j];
            }
            fps<mint>::NTT::doubling(d[i]);
            if (2 * deg[2 * i + 1] == n) {
                for (int j = 0; j < n; j++) d[i][j + n] -= mint::raw(2);
            }
            deg[i] = deg[2 * i] + deg[2 * i + 1];
        }
        d[1].intt();
        d[1].shrink();
        reverse(d[1].begin(), d[1].end());
    }
    vector<mint> multipoint_evaluation(fps<mint> f) {
        int n = f.size();
        if (n == 0) return vector<mint>(n, mint::raw(0));
        if (m == 0) return {};
        vector<fps<mint>> t(2 * sz);
        t[1] = d[1].inv(n);
        reverse(t[1].begin(), t[1].end());
        int h = 1;
        while (h < n + m) h <<= 1;
        t[1].resize(h, mint::raw(0));
        t[1].ntt();
        t[1] = inner_middle_product(f, t[1], m, n);
        for (int i = 1; i < sz; i++) {
            if (deg[i] == 0) continue;
            if (deg[2 * i + 1] > 0) {
                t[2 * i] = inner_middle_product(t[i], d[2 * i + 1], deg[2 * i], deg[2 * i + 1] + 1);
                t[2 * i + 1] = inner_middle_product(t[i], d[2 * i], deg[2 * i + 1], deg[2 * i] + 1);
            } else {
                t[2 * i] = t[i];
            }
        }
        vector<mint> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = t[i + sz].size() ? t[i + sz][0] : mint::raw(0);
        }
        return res;
    }
    fps<mint> polynomial_interpolation(const vector<mint> &y) {
        assert(ssize(y) == m);
        fps<mint> g(m);
        for (int i = 0; i < m; i++) g[i] = mint::raw(i + 1) * d[1][m - 1 - i];
        auto a = multipoint_evaluation(g);
        vector<fps<mint>> t(2 * sz);
        for (int i = 0; i < m; i++) t[i + sz] = fps<mint>{y[i] / a[i]};
        for (int i = sz - 1; i >= 1; i--) {
            if (deg[2 * i + 1] > 0) {
                fps<mint>::NTT::doubling(t[2 * i]);
                fps<mint>::NTT::doubling(t[2 * i + 1]);
                int k = t[2 * i].size();
                t[i].resize(k);
                for (int j = 0; j < k; j++) {
                    t[i][j] = d[2 * i][j] * t[2 * i + 1][j] + d[2 * i + 1][j] * t[2 * i][j];
                }
            } else {
                t[i] = t[2 * i];
                fps<mint>::NTT::doubling(t[i]);
            }
        }
        t[1].intt();
        t[1].shrink();
        return t[1];
    }
private:
    int m, sz;
    vector<fps<mint>> d;
    vector<int> deg;
    fps<mint> inner_middle_product(fps<mint> f, const fps<mint> &g, int n, int l) {
        f.resize(g.size(), mint::raw(0));
        f.ntt();
        for (int i = 0; i < ssize(g); i++) f[i] *= g[i];
        f.intt();
        f >>= (l - 1);
        f.resize(n);
        return f;
    }
};