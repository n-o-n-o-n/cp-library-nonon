#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include "../../src/tree/static_tree.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    static_tree G(N);
    for (int i = 1, u, v; i < N; i++) {
        cin >> u >> v;
        G.add_edge(u, v);
    }
    for (int u, v, k; Q--; ) {
        cin >> u >> v >> k;
        cout << G.jump(u, v, k) << '\n';
    }
}