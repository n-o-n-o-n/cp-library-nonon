#define PROBLEM "https://yukicoder.me/problems/no/1891"

#include "../main/data_structure/segtree/xor_segtree_static.hpp"
#include "../main/modint/modint.hpp"

using mint = modint<998244353>;

#include <iostream>
using namespace std;

#include "../cp-library-nonon/main/math/affine.hpp"

struct Monoid {
    using S = affine<mint>;
    static S op(S f, S g) {
        return g(f);
    }
    static S e() { return S(); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<Monoid::S> F(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        F[i] = Monoid::S(a, b);
    }
    xor_segtree<Monoid> seg(F);
    while (Q--) {
        int l, r, x, a;
        cin >> l >> r >> x >> a;
        auto f = seg.prod(l, r, x);
        cout << f(a).val() << '\n';
    }
}