#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../../src/tree/hld.hpp"
#include "../../src/data_structure/segtree/segtree.hpp"
#include "../../src/monoid/add.hpp"

using SegTree = segtree<add_monoid<long long>>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    heavy_light_decomposition<SegTree, false, true> G(N);
    for (int i = 1, u, v; i < N; i++) {
        cin >> u >> v;
        G.add_edge(u, v);
    }
    for (int i = 0; i < N; i++) {
        G.set(i, A[i]);
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int u, x;
            cin >> u >> x;
            G.set(u, G.get(u) + x);
        } else {
            int u, v;
            cin >> u >> v;
            cout << G.prod(u, v) << '\n';
        }
    }
}