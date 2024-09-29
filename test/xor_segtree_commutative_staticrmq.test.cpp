#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../main/data_structure/segtree/xor_segtree_commutative.hpp"
#include "../main/monoid/min.hpp"

#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // A+B Problem
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';

    // Xor Segtree Verify
    random_device seed;
    mt19937 eng(seed());
    int N = 1 << (eng() % 12 + 1);
    int Q = eng() % 3000 + 1;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = eng() % int(1e9) + 1;
    }
    xor_segtree<min_monoid<int>> seg(A);
    while (Q--) {
        int t = eng() % 2;
        if (t == 0) {
            // update query
            int p = eng() % N;
            A[p] = eng() % int(1e9) + 1;
            seg.set(p, A[p]);
        } else {
            int r = eng() % N + 1;
            int l = eng() % r;
            int x = eng() % N;
            int ac = 1e9;
            for (int i = l; i < r; i++) {
                ac = min(ac, A[i ^ x]);
            }
            int ans = seg.prod(l, r, x);
            assert(ac == ans);
        }
    }
}