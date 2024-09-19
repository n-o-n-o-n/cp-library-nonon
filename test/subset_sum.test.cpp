#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"

#include "../main/modint/modint.hpp"
#include "../main/math/subset_sum.hpp"

using mint = modint<998244353>;

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<mint> ans = subset_sum<mint>(A, M);
    for (int i = 1; i <= M; i++) {
        cout << ans[i].val() << " \n"[i == M];
    }
}