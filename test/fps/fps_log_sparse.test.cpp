#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series_sparse"

#include "../../src/fps/fps_log_sparse.hpp"
#include "../../src/modint/modint.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<pair<int, mint>> f_sub(K);
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        f_sub[i] = {a, mint::raw(b)};
    }
    auto f = fps_log_sparse(f_sub, N);
    for (int i = 0; i < N; i++) cout << f[i].val() << " \n"[i + 1 == N];
}