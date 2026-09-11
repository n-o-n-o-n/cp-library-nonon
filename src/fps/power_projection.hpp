#pragma once
#include "fps_inv.hpp"

// enumerate [x^n](f^k)g for k = 0,1,...,m-1
template<typename mint>
fps<mint> power_projection(fps<mint> f, fps<mint> g, int n, int m) {
    f.resize(n + 1);
    g.resize(n + 1);
    int k = 1, len = 1;
    while (len <= n) len *= 2;
    fps<mint> p(n + 1), q(n + 1), np, nq, bf;
    for (int i = 0; i <= n; i++) p[i] = g[i], q[i] = -f[i];
    q[0]++;
    const mint inv2 = mint::raw(2).inv();
    for (; n > 0; n /= 2, len /= 2, k *= 2) {
        np.clear();
        nq.clear();
        for (int i = 0; i <= n; i++) {
            bf.resize(k);
            copy(p.begin() + i * k, p.begin() + i * k + k, bf.begin());
            fps<mint>::NTT::doubling(bf);
            copy(bf.begin(), bf.end(), back_inserter(np));
            bf.resize(k);
            copy(q.begin() + i * k, q.begin() + i * k + k, bf.begin());
            if (i == 0) {
                for (int j = 0; j < k; j++) bf[j]--;
                fps<mint>::NTT::doubling(bf);
                for (int j = 0; j < k; j++) bf[j]++, bf[j + k]--;
            } else {
                fps<mint>::NTT::doubling(bf);
            }
            copy(bf.begin(), bf.end(), back_inserter(nq));
        }
        np.resize(4 * len * k);
        nq.resize(4 * len * k);
        fps<mint> tp(2 * len), tq(2 * len);
        mint w = fps<mint>::NTT::get_root().pow((mint::mod() - 1) / (2 * len));
        mint iw = w.inv();
        vector<int> btr;
        if (n & 1) {
            btr.resize(len);
            int lg = __builtin_ctz(len) - 1;
            for (int i = 0; i < len; i++) btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << lg);
        }
        for (int j = 0; j < 2 * k; j++) {
            tp.assign(2 * len, mint::raw(0));
            tq.assign(2 * len, mint::raw(0));
            for (int i = 0; i < len; i++) {
                tp[i] = np[2 * i * k + j];
                tq[i] = nq[2 * i * k + j];
            }
            tp.ntt();
            tq.ntt();
            for (int i = 0; i < 2 * len; i++) {
                if (!(i & 1)) swap(tq[i], tq[i + 1]);
                tp[i] *= tq[i];
            }
            for (int i = 0; i < len; i++) tq[i] = tq[2 * i] * tq[2 * i + 1];
            if (n & 1) {
                mint c = inv2;
                bf.resize(len);
                for (int i : btr) {
                    bf[i] = (tp[2 * i] - tp[2 * i + 1]) * c;
                    c *= iw;
                }
                swap(tp, bf);
            } else {
                for (int i = 0; i < len; i++) tp[i] = (tp[2 * i] + tp[2 * i + 1]) * inv2;
            }
            tp.resize(len);
            tq.resize(len);
            tp.intt();
            tq.intt();
            for (int i = 0; i < len; i++) {
                np[2 * i * k + j] = tp[i];
                nq[2 * i * k + j] = tq[i];
            }
        }
        np.resize(2 * k * (n / 2 + 1));
        nq.resize(2 * k * (n / 2 + 1));
        swap(p, np);
        swap(q, nq);
    }
    fps<mint> s(p.begin(), p.begin() + k), t(q.begin(), q.begin() + k);
    s.intt();
    t.intt();
    t[0]--;
    auto res = t[0] == 0 ? s.rev() : (s.rev() * (t + (fps<mint>{1} << k)).rev().inv(m)).pre(m);
    res.resize(m);
    return res;
}