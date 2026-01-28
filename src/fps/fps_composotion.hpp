#pragma once
#include "fps_inv.hpp"

// https://judge.yosupo.jp/submission/307408
template<typename mint>
fps<mint> fps<mint>::operator()(fps<mint> f, int deg) const {
    assert(f[0] == 0);
    auto g = *this;
    auto rec = [&] (const auto &rec, fps<mint> q, int n, int m, int k) -> fps<mint> {
        if (n == 0) {
            fps<mint> t(q.begin(), q.begin() + k);
            t.emplace_back(1);
            auto u = g * t.rev().inv().rev();
            fps<mint> p(m * k);
            for (int i = 0; i < ssize(g); i++) p[k - i - 1] = u[i + k];
            return p;
        }
        fps<mint> nq(4 * m * k), nr(2 * m * k);
        for (int i = 0; i < k; i++) {
            copy(q.begin() + i * m, q.begin() + i * m + n + 1, nq.begin() + 2 * i * m);
        }
        nq[2 * m * k]++;
        nq.ntt();
        for (int i = 0; i < 2 * m * k; i++) {
            swap(nq[2 * i], nq[2 * i + 1]);
            nr[i] = nq[2 * i] * nq[2 * i + 1];
        }
        nr.intt();
        nr[0]--;
        q.assign(m * k, mint());
        for (int i = 0; i < 2 * k; i++) {
            for (int j = 0; j <= n / 2; j++) {
                q[i * m / 2 + j] = nr[i * m + j];
            }
        }
        auto p = rec(rec, q, n / 2, m / 2, 2 * k);
        fps<mint> np(4 * m * k);
        for (int i = 0; i < 2 * k; i++) {
            for (int j = 0; j <= n / 2; j++) {
                np[2 * i * m + 2 * j + (n & 1)] = p[i * m / 2 + j];
            }
        }
        np.ntt();
        for (int i = 1; i < 4 * m * k; i <<= 1) reverse(nq.begin() + i, nq.begin() + (i << 1));
        for (int i = 0; i < 4 * m * k; i++) np[i] *= nq[i];
        np.intt();
        p.assign(m * k, mint());
        for (int i = 0; i < k; i++) {
            copy(np.begin() + 2 * i * m, np.begin() + 2 * i * m + n + 1, p.begin() + i * m);
        }
        return p;
    };
    if (deg == -1) deg = max(f.size(), g.size());
    f.resize(deg);
    g.resize(deg);
    int n = deg - 1, m = 1, k = 1;
    while (m < deg) m <<= 1;
    fps<mint> q(m);
    for (int i = 0; i <= n; i++) q[i] = -f[i];
    auto p = rec(rec, q, n, m, k);
    return p.pre(deg).rev();
}