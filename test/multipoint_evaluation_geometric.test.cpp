#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence"

#include "../main/modint/modint.hpp"
#include "../main/fps/fps.hpp"
#include "../main/fps/multipoint_evaluation_geometric.hpp"

#include <iostream>
using namespace std;

using mint = modint<998244353>;
using FPS = Formal_Power_Series<mint>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, a, r;
    cin >> N >> M >> a >> r;
    FPS f(N);
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        f[i] = c;
    }
    vector<mint> ans = multipoint_evaluation_geometric(f, M, mint(a), mint(r));
    for (int i = 0; i < M; i++) {
        cout << ans[i].val() << " \n"[i + 1 == M];
    }
}