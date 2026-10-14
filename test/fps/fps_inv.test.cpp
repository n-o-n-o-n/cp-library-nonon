#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include "../../src/fps/fps_inv.hpp"
#include "../../src/modint/modint.hpp"
using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    fps<mint> f(N);
    for (auto &e : f) { int x; cin >> x; e = x; }
    f = f.inv();
    for (int i = 0; i < N; i++) cout << f[i].val() << " \n"[i + 1 == N];
}