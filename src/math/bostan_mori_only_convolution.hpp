#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename mint, typename C>
mint Bostan_Mori(vector<mint> p, vector<mint> q, long long k, const C &conv) {
    assert(p.size() && q.size());
    if (k == 0) return p[0] / q[0];
    auto sub = [&] (const vector<mint> &f, bool odd = false) -> vector<mint> {
        int n = (f.size() + !odd) / 2;
        vector<mint> g(n);
        for (int i = odd; i < ssize(f); i += 2) {
            g[i / 2] = f[i];
        }
        return g;
    };
    while (k > 0) {
        auto q2 = q;
        for (int i = 1; i < ssize(q2); i += 2) {
            q2[i] = -q2[i];
        }
        p = sub(conv(p, q2), k & 1);
        q = sub(conv(q, q2));
        k >>= 1;
    }
    return p[0];
}

template<typename mint, typename C>
mint linear_recurrence(vector<mint> a, vector<mint> c, long long k, const C &conv) {
    assert(a.size() == c.size());
    int n = a.size();
    for (auto &e : c) e = -e;
    c.insert(c.begin(), 1);
    a = conv(a, c);
    a.resize(n);
    return Bostan_Mori<mint, C>(a, c, k, conv);
}