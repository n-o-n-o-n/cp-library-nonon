#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../../src/convolution/relaxed_convolution.hpp"
#include "../../src/modint/modint.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    int N, M;
    cin >> N >> M;
    int L = N + M - 1;
    vector<mint> A(L), B(L);
    for (int i = 0; i < N; i++) { int e; cin >> e; A[i] = e; }
    for (int i = 0; i < M; i++) { int e; cin >> e; B[i] = e; }
    relaxed_convolution<mint> RC(L);
    for (int i = 0; i < L; i++) {
        cout << RC.get(A[i], B[i]).val() << " \n"[i + 1 == L];
    }
}