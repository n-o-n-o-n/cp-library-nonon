#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../src/tree/centroid_decomposition.hpp"
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
        int N = rng::randint(1, (int)2000);
        centroid_decomposition CD(N);
        static_tree T(N);
        for (auto [u, v] : rng::random_tree(N, true)) {
            CD.add_edge(u, v);
            T.add_edge(u, v);
        }
        auto P = CD.parent_vector();
        int r = min_element(P.begin(), P.end()) - P.begin();
        static_tree R(N, r);
        for (int i = 0; i < N; i++) {
            if (P[i] != -1) R.add_edge(i, P[i]);
        }
        vector<int> sub(N, 1);
        auto dfs = [&] (auto dfs, int u) -> int {
            for (int v : R[u]) if (v != P[u]) sub[u] += dfs(dfs, v);
            return sub[u];
        };
        dfs(dfs, r);
        for (int x = 0; x < N; x++) {
            for (int y = x + 1; y < N; y++) {
                int z = R.lca(x, y);
                assert(T.dist(x, y) == T.dist(x, z) + T.dist(z, y));
            }
        }
        for (int i = 0; i < N; i++) {
            if (P[i] == -1) continue;
            assert(2 * sub[i] <= sub[P[i]]);
        }
    }
}