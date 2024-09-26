#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../main/data_structure/disjoint_sparse_table.hpp"
#include "../main/monoid/utility.hpp"

#include <iostream>
using namespace std;

int op(int a, int b) { return min(a, b); }
int e() { return 1 << 30; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    disjoint_sparse_table<min_monoid<int>> st(N);
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        st.set(i, A);
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << st.prod(l, r) << '\n';
    }
}