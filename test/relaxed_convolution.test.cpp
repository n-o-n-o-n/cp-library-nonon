#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../main/convolution/relaxed_convolution.hpp"
#include "../main/modint/modint.hpp"

#include <iostream>
#include <vector>
using namespace std;

using mint = modint<998244353>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> A(N + M), B(N +M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    relaxed_convolution<mint> f(N + M);
    for (int i = 0; i < N + M - 1; i++) {
        cout << f.get(A[i], B[i]).val() << " \n"[i + 2 == N + M];
    }
}