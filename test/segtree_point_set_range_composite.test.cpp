#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../main/modint/modint.hpp"
#include "../main/math/affine.hpp"
#include "../main/data_structure/segtree/segtree.hpp"

using mint = modint<998244353>;

struct Monoid {
    using S = affine<mint>;
    static S op(S f, S g) { return g(f); }
    static S e() { return S(); }
};

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    segtree<Monoid> seg(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        seg.set(i, affine<mint>(a, b));
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, a, b;
            cin >> p >> a >> b;
            seg.set(p, affine<mint>(a, b));
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            affine<mint> f = seg.prod(l, r);
            cout << f(x).val() << '\n';
        }
    }
}