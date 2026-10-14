#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree"

#include "../../src/tree/range_contour_aggregator.hpp"
#include "../../src/data_structure/segtree/segtree.hpp"
#include "../../src/monoid/add.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto &e : A) cin >> e;
    range_contour_aggregator<segtree<add_monoid<long long>>> RCA(N);
    for (int i = 1, u, v; i < N; i++) {
        cin >> u >> v;
        RCA.add_edge(u, v);
    }
    for (int i = 0; i < N; i++) {
        RCA.set(i, A[i]);
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            RCA.set(p, RCA.get(p) + x);
        } else {
            int p, l, r;
            cin >> p >> l >> r;
            cout << RCA.prod(p, l, r) << '\n';
        }
    }
}