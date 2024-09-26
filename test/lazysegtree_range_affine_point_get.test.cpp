#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include "../main/modint/modint.hpp"
#include "../main/math/affine.hpp"
#include "../main/monoid/utility.hpp"
#include "../main/data_structure/segtree/lazysegtree.hpp"


using mint = modint<998244353>;

mint mapping(affine<mint> f, mint x) { return f(x); }
struct Operator {
    using F = affine<mint>;
    static F comp(F f, F g) { return f(g); }
    static F id() { return F(); }
};

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    lazy_segtree<add_monoid<mint>, Operator, mapping> seg(N);
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        seg.set(i, A);
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, a, b;
            cin >> l >> r >> a >> b;
            seg.apply(l, r, affine<mint>(a, b));
        } else {
            int p;
            cin >> p;
            cout << seg.get(p).val() << endl;
        }
    }
}