#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include "../../src/convolution/gcd_convolution.hpp"
#include "../../src/modint/modint.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<mint> A(N), B(N);
    for (auto &e : A) { int x; cin >> x; e = x; }
    for (auto &e : B) { int x; cin >> x; e = x; }
    A.insert(A.begin(), 0), B.insert(B.begin(), 0);
    auto C = gcd_convolution(A, B);
    for (int i = 1; i < ssize(C); i++) cout << C[i].val() << " \n"[i + 1 == ssize(C)];
}