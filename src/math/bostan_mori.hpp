#pragma once
#include <cassert>
#include <vector>
#include "../fps/fps.hpp"
using namespace std;

template<typename mint>
mint Bostan_Mori(Formal_Power_Series<mint> p, Formal_Power_Series<mint> q, long long k) {
    using fps = Formal_Power_Series<mint>;
    mint res = 0;
    if (p.size() >= q.size()) {
        fps r = p.div(q);
        p -= q * r;
        p.shrink();
        if (k < int(r.size())) res += r[k];
    }
    if (p.empty()) return res;
    p.resize(q.size() - 1);
    auto sub = [&](const fps &f, bool odd = false) -> fps {
        int n = (f.size() + !odd) / 2;
        fps g(n);
        for (int i = odd; i < int(f.size()); i += 2) {
            g[i / 2] = f[i];
        }
        return g;
    };
    while (k > 0) {
        fps q2 = q;
        for (int i = 1; i < int(q2.size()); i += 2) {
            q2[i] = -q2[i];
        }
        p = sub(p * q2, k & 1);
        q = sub(q * q2);
        k >>= 1;
    }
    return res + p[0];
}

template<typename mint>
mint linear_recurrence(const vector<mint> &a, const vector<mint>& c, long long k) {
    using fps = Formal_Power_Series<mint>;
    assert(a.size() == c.size());
    auto fa = fps(a.begin(), a.end()), fc = fps(c.begin(), c.end());
    fc = fps{1} - (fc << 1);
    return Bostan_Mori((fa * fc).pre(a.size()), fc, k);
}