#pragma once
#include <cassert>
using namespace std;

template<typename FPS>
typename FPS::value_type Bostan_Mori(FPS p, FPS q, long long k) {
    using mint = typename FPS::value_type;
    mint res = 0;
    if (p.size() >= q.size()) {
        FPS r = p.div(q);
        p -= q * r;
        p.shrink();
        if (k < int(r.size())) res += r[k];
    }
    if (p.empty()) return res;
    p.resize(q.size() - 1);
    auto sub = [&](const FPS &f, bool odd = false) -> FPS {
        int n = (f.size() + !odd) / 2;
        FPS g(n);
        for (int i = odd; i < int(f.size()); i += 2) {
            g[i / 2] = f[i];
        }
        return g;
    };
    while (k > 0) {
        FPS q2 = q;
        for (int i = 1; i < int(q2.size()); i += 2) {
            q2[i] = -q2[i];
        }
        p = sub(p * q2, k & 1);
        q = sub(q * q2);
        k >>= 1;
    }
    return res + p[0];
}

template<typename FPS>
typename FPS::value_type linear_recurrence(FPS a, FPS c, long long k) {
    assert(a.size() == c.size());
    c = FPS{1} - (c << 1);
    return Bostan_Mori((a * c).pre(a.size()), c, k);
}