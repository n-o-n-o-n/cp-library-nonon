#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../src/tree/static_tree.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    static_tree G(N);
    for (int i = 1, p; i < N; i++) {
        cin >> p;
        G.add_edge(i, p);
    }
    for (int u, v; Q--; ) {
        cin >> u >> v;
        cout << G.lca(u, v) << '\n';
    }
}