#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

namespace combination {

template<typename mint>
struct container {
    static vector<mint> fac, finv;
    static void init(int n) {
        int sz = fac.size();
        if (n < sz) return;
        n = clamp(n, 2 * sz, min<int>(1 << 27, mint::mod() - 1));
        fac.resize(n + 1);
        finv.resize(n + 1);
        for (int i = sz; i <= n; i++) {
            fac[i] = i * fac[i - 1];
        }
        finv[n] = fac[n].inv();
        for (int i = n; i >= sz; i--) {
            finv[i - 1] = i * finv[i];
        }
    }
};

template<typename mint>
vector<mint> container<mint>::fac(1, 1);
template<typename mint>
vector<mint> container<mint>::finv(1, 1);
template<typename mint>
mint fac(int n) {
    container<mint>::init(n);
    if (n < 0) return 0;
    return container<mint>::fac[n];
}
template<typename mint>
mint finv(int n) {
    container<mint>::init(n);
    if (n < 0) return 0;
    return container<mint>::finv[n];
}
template<typename mint>
mint mod_inv(int n) {
    assert(n > 0);
    return finv<mint>(n) * fac<mint>(n - 1);
}
template<typename mint>
mint nCk(int n, int k) {
    if (n < 0) {
        n = -n;
        return nCk<mint>(n + k - 1, n - 1);
    }
    if (n < k || k < 0) return 0;
    return fac<mint>(n) * finv<mint>(n - k) * finv<mint>(k);
}
template<typename mint>
mint multi_C(const vector<int> &v) {
    int n = 0;
    for (const int &k : v) n += k;
    mint res = fac<mint>(n);
    for (const int &k : v) res *= finv<mint>(k);
    return res;
}
template<typename mint>
mint nPk(int n, int k) {
    if (n < 0 || n < k || k < 0) return 0;
    return fac<mint>(n) * finv<mint>(n - k);
}
template<typename mint>
mint catalan(int n) {
    return fac<mint>(2 * n) * finv<mint>(n) * finv<mint>(n + 1);
}
template<typename mint>
mint grid_path(int n, int m) {
    return nCk<mint>(n + m, n);
}

} // namespace combination