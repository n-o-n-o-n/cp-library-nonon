#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

#include "../../src/fps/polynomial_interpolation.hpp"
#include "../../src/modint/modint.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<mint> x(N), y(N);
    for (auto &e : x) { int a; cin >> a; e = a; }
    for (auto &e : y) { int a; cin >> a; e = a; }
    auto f = polynomial_interpolation(x, y);
    f.resize(N);
    for (int i = 0; i < N; i++) cout << f[i].val() << " \n"[i + 1 == N];
}