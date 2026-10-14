#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../src/fps/fps_div_sparse.hpp"
#include "../../src/fps/fps_inv.hpp"
#include "../../src/modint/modint.hpp"

using mint = modint<998244353>;

#include "../../src/random/utility.hpp"
#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    {
        int A, B;
        cin >> A >> B;
        cout << A + B << '\n';
    }
    for (int t = 0; t < 20; t++) {
        int N = rng::randint(1, (int)1e5);
        fps<mint> f(N), g(N);
        for (auto &e : f) e = rng::randint(0, 998244352);
        vector<pair<int, mint>> g_sub;
        g_sub.emplace_back(0, rng::randint(1, 998244352));
        vector<int> shl(N - 1);
        iota(shl.begin(), shl.end(), 1);
        shuffle(shl.begin(), shl.end(), rng::eng);
        int K = rng::randint(0, 10);
        for (int i = 0; i < K; i++) g_sub.emplace_back(shl[i], rng::randint(1, 998244352));
        for (auto [p, e] : g_sub) g[p] = e;
        assert((f / g).pre(N) == fps_div_sparse(f, g_sub));
    }
}