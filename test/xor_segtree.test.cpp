#define PROBLEM "https://yukicoder.me/problems/no/2265"

#include "../main/data_structure/segtree/xor_segtree.hpp"
#include "../main/modint/modint.hpp"

using mint = modint<998244353>;

#include <iostream>
using namespace std;

mint p2[1 << 18], p11[1 << 18];

struct Monoid {
    struct S {
        mint x;
        int size;
    };
    static S op(S a, S b) {
        mint x = a.x * p11[b.size] + b.x * p2[a.size];
        int size = a.size + b.size;
        return S{x, size};
    }
    static S e() {
        return S{0, 0};
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    string S;
    cin >> N >> S;
    N = 1 << N;
    p2[0] = p11[0] = 1;
    for (int i = 1; i < N; i++) {
        p2[i] = 2 * p2[i - 1];
        p11[i] = 11 * p11[i - 1];
    }
    vector<Monoid::S> A(N);
    for (int i = 0; i < N; i++) A[i] = Monoid::S{S[i] - '0', 1};
    xor_segtree<Monoid> seg(A);
    int Q;
    cin >> Q;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            seg.set(p, Monoid::S{x, 1});
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            cout << seg.prod(l, r + 1, x).x.val() << '\n';
        }
    }
}