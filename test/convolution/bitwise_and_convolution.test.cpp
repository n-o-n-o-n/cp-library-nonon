#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include "../../src/convolution/bitwise_and_convolution.hpp"
#include "../../src/modint/modint.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<mint> A(1 << N), B(1 << N);
    for (auto &e : A) { int x; cin >> x; e = x; }
    for (auto &e : B) { int x; cin >> x; e = x; }
    auto C = bitwise_and_convolution(A, B);
    for (int i = 0; i < ssize(C); i++) cout << C[i].val() << " \n"[i + 1 == ssize(C)];
}