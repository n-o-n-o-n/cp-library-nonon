#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../main/modint/modint.hpp"
#include "../main/math/affine.hpp"
#include "../main/data_structure/segtree/lazysegtree.hpp"

#include <iostream>
#include <vector>
using namespace std;
using mint = modint<998244353>;

struct S {
    mint x;
    int sz;
    S(mint v, int n) : x(v), sz(n) {}
};

using F = affine<mint>;

S op(S a, S b) { return S(a.x + b.x, a.sz + b.sz); }
S e() { return S(0, 0); }
S mp(F f, S x) { return S(f.a * x.x + f.b * x.sz, x.sz); }
F cmp(F f, F g) { return f(g); }
F id() { return F(); }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<S> A(N, e());
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[i] = S(a, 1);
    }
    lazy_segtree<S, op, e, F, mp, cmp, id> seg(A);
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, a, b;
            cin >> l >> r >> a >> b;
            seg.apply(l, r, F(a, b));
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l, r).x.val() << '\n';
        }
    }
}