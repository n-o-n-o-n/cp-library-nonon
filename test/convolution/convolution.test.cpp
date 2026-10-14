#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../../src/convolution/convolution.hpp"
#include "../../src/modint/modint.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<mint> A(N), B(M);
    for (auto &e : A) { int x; cin >> x; e = x; }
    for (auto &e : B) { int x; cin >> x; e = x; }
    auto C = convolution(A, B);
    for (int i = 0; i < ssize(C); i++) cout << C[i].val() << " \n"[i + 1 == ssize(C)];
}