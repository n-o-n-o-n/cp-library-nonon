#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"

#include "../../src/data_structure/segtree/segtree.hpp"
#include "../../src/monoid/add.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    segtree<add_monoid<int>> seg(N);
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            p--;
            seg.set(p, seg.get(p) + x);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << seg.prod(l, r) << '\n';
        }
    }
}