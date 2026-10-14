#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum_large_array"

#include "../../../src/modint/modint.hpp"
#include "../../../src/math/affine.hpp"
#include "../../../src/data_structure/segtree/dynamic_lazysegtree.hpp"

using mint = modint<998244353>;

struct Monoid {
    using S = affine<mint>;
    static S op(S f, S g) { return g(f); }
    static S e() { return affine<mint>(); }
};

using mint = modint<998244353>;

struct ActMonoid {
    using S = pair<mint, int>;
    static S op(S a, S b) {
        return {a.first + b.first, a.second + b.second};
    }
    static S e() {
        return S{0, 0};
    }
    static S init(int l, int r) {
        return S{0, r - l};
    }
    using F = affine<mint>;
    static F id() { return F(); }
    static F comp(F f , F g) { return f(g); }
    static S map(F f, S x) {
        return S{f.a * x.first + f.b * x.second, x.second};
    }
};

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    dynamic_lazysegtree<ActMonoid> seg(N, Q);
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, a, b;
            cin >> l >> r >> a >> b;
            seg.apply(l, r, affine<mint>(a, b));
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l, r).first.val() << '\n';
        }
    }
}