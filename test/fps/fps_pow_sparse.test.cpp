#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse"

#include "../../src/fps/fps_pow_sparse.hpp"
#include "../../src/modint/modint.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    long long M;
    cin >> N >> K >> M;
    vector<pair<int, mint>> f_sub(K);
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        f_sub[i] = {a, mint::raw(b)};
    }
    auto f = fps_pow_sparse(f_sub, N, M);
    for (int i = 0; i < N; i++) cout << f[i].val() << " \n"[i + 1 == N];
}