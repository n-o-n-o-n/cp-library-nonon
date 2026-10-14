#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include "../../src/fps/multipoint_evaluation.hpp"
#include "../../src/modint/modint.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    fps<mint> f(N);
    for (auto &e : f) { int a; cin >> a; e = a; }
    vector<mint> x(M);
    for (auto &e : x) { int a; cin >> a; e = a; }
    auto y = multipoint_evaluation<mint>(f, x);
    for (int i = 0; i < M; i++) cout << y[i].val() << " \n"[i + 1 == M];
}