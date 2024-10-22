#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../main/data_structure/fenwicktree.hpp"

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    fenwick_tree<long long> BIT(N);
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        BIT.add(i, A);
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            BIT.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << BIT.sum(l, r) << '\n';
        }
    }
}