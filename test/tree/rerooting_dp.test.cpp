#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"

#include "../../src/tree/rerooting_dp.hpp"
#include "../../src/modint/modint.hpp"

using mint = modint<998244353>;

struct Monoid {
    using S = pair<mint, int>;
    static S op(S a, S b) { return {a.first + b.first, a.second + b.second}; }
    static S e() { return {0, 0}; }
};

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &e : A) cin >> e;
    vector<mint> B(N - 1), C(N - 1);
    rerooting_dp<Monoid> RR(N);
    for (int i = 0, u, v, b, c; i < N - 1; i++) {
        cin >> u >> v >> b >> c;
        RR.add_edge(u, v);
        B[i] = b, C[i] = c;
    }
    using S = Monoid::S;
    auto apply_vertex = [&] (S x, int u) -> S {
        return {x.first + A[u], x.second + 1};
    };
    auto apply_edge = [&] (S x, int i) -> S {
        return {x.first * B[i] + x.second * C[i], x.second};
    };
    auto ans = RR.run(apply_vertex, apply_edge);
    for (int i = 0; i < N; i++) cout << ans[i].first.val() << " \n"[i + 1 == N];
}