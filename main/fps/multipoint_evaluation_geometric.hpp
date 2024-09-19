#pragma once
#include <vector>
using namespace std;

template<typename FPS, typename mint>
vector<mint> multipoint_evaluation_geometric(const FPS &f, int m, mint a, mint r) {
    int n = f.size();
    if (n == 0) return vector<mint>(m);
    if (m == 0) return vector<mint>(m);
    if (a == 0) return vector<mint>(m, f[0]);
    if (r == 0) {
        vector<mint> res(m, f[0]);
        res[0] = f(a);
        return res;
    }
    mint invr = r.inv();
    vector<mint> powr(n + m, 1), powrt(n + m, 1);
    vector<mint> powinvr(n + m, 1), powinvrt(n + m, 1);
    for (int i = 1; i < n + m; i++) {
        powr[i] = r * powr[i - 1];
        powrt[i] = powr[i - 1] * powrt[i - 1];
        powinvr[i] = invr * powinvr[i - 1];
        powinvrt[i] = powinvr[i - 1] * powinvrt[i - 1];
    }
    FPS p(n), q(n + m);
    vector<mint> powa(n, 1);
    for (int i = 0; i < n; i++) {
        if (i) powa[i] = a * powa[i - 1];
        p[n - 1 - i] = f[i] * powa[i] * powinvrt[i];
    }
    for (int i = 0; i < n + m; i++) {
        q[i] = powrt[i];
    }
    FPS pq = p * q;
    vector<mint> res(m);
    for (int i = 0; i < m; i++) {
        res[i] = pq[n - 1 + i] * powinvrt[i];
    }
    return res;
}