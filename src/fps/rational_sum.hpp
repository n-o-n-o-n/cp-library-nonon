#pragma once
#include "fps.hpp"

template<typename mint>
fps<mint> rational_sum(const vector<fps<mint>> &ps, const vector<fps<mint>> &qs, int deg = -1) {
    assert(ps.size() == qs.size());
    if (ps.empty()) return {};
    auto rec = [&] (const auto &rec, int l, int r) -> pair<fps<mint>, fps<mint>> {
        if (l + 1 == r) return {ps[l], qs[l]};
        int m = (l + r) / 2;
        auto [pl, ql] = rec(rec, l, m);
        auto [pr, qr] = rec(rec, m, r);
        int sz_p = max(pl.size() + qr.size(), pr.size() + ql.size()) - 1;
        int sz_q = ql.size() + qr.size() - 1;
        int sz = 1;
        while (sz < max(sz_p, sz_q)) sz <<= 1;
        if (sz < 64) {
            fps<mint> p(sz_p), q(sz_q);
            for (int i = 0; i < ssize(pl); i++) {
                for (int j = 0; j < ssize(qr); j++) p[i + j] += pl[i] * qr[j];
            }
            for (int i = 0; i < ssize(pr); i++) {
                for (int j = 0; j < ssize(ql); j++) p[i + j] += pr[i] * ql[j];
            }
            for (int i = 0; i < ssize(ql); i++) {
                for (int j = 0; j < ssize(qr); j++) q[i + j] += ql[i] * qr[j];
            }
            return {p, q};
        } else {
            pl.resize(sz);
            ql.resize(sz);
            pr.resize(sz);
            qr.resize(sz);
            pl.ntt();
            ql.ntt();
            pr.ntt();
            qr.ntt();
            for (int i = 0; i < sz; i++) {
                pl[i] = pl[i] * qr[i] + pr[i] * ql[i];
                ql[i] = ql[i] * qr[i];
            }
            pl.intt();
            ql.intt();
            pl.resize(min(deg == -1 ? numeric_limits<int>::max() : deg, sz_p));
            ql.resize(min(deg == -1 ? numeric_limits<int>::max() : deg, sz_q));
        }
        return {pl, ql};
    };
    auto [p, q] = rec(rec, 0, ps.size());
    if (deg != -1) {
        p.resize(deg);
        q.resize(deg);
    }
    return p /= q;
}