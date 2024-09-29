#define PROBLEM "https://yukicoder.me/problems/no/2206"

#include "../main/modint/modint.hpp"
#include "../main/math/prefix_binomial_sum_online.hpp"
using mint = modint<998244353>;

#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    prefix_binomial_sum<mint> C(200000);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        mint ans = mint(2).pow(N) - 1;
        ans *= C.get(N - 1, M - 1);
        cout << ans.val() << '\n';
    }
}