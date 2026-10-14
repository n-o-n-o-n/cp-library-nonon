#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../src/tree/level_ancestor_offline.hpp"
#include "../../src/tree/static_tree.hpp"

#include <iostream>

#include "../../src/random/graph.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    {
        int A, B;
        cin >> A >> B;
        cout << A + B << '\n';
    }
    for (int t = 0; t < 20; t++) {
        int N = rng::randint(1, (int)2e5);
        level_ancestor LA(N);
        static_tree T(N);
        for (auto [u, v] : rng::random_tree(N, true)) {
            LA.add_edge(u, v);
            T.add_edge(u, v);
        }
        int Q = 2e5;
        vector<int> ans(Q);
        for (int i = 0; i < Q; i++) {
            int u = rng::randint(0, N - 1);
            int k = rng::randint(1, N);
            LA.add_query(u, k);
            ans[i] = T.jump(u, 0, k);
        }
        assert(LA.solve() == ans);
    }
}