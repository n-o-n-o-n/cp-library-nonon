#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../main/data_structure/segtree/segtree.hpp"

#include <iostream>
#include <vector>
using namespace std;

int op(int a, int b) { return min(a, b); }
int e() { return 1 << 30; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    segtree<int, op, e> seg(N);
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        seg.set(i, A);
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << seg.prod(l, r) << '\n';
    }
}