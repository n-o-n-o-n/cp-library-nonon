#define PROBLEM "https://judge.yosupo.jp/problem/composition_of_formal_power_series_large"

#include "../../src/fps/fps_composotion.hpp"
#include "../../src/modint/modint.hpp"
using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    fps<mint> f(N), g(N);
    for (auto &e : f) { int x; cin >> x; e = x; }
    for (auto &e : g) { int x; cin >> x; e = x; }
    f = f(g);
    for (int i = 0; i < N; i++) cout << f[i].val() << " \n"[i + 1 == N];
}