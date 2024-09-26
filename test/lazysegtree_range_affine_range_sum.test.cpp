#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../main/modint/modint.hpp"
#include "../main/math/affine.hpp"
#include "../main/data_structure/segtree/lazysegtree.hpp"

#include <iostream>
#include <vector>
using namespace std;
using mint = modint<998244353>;

struct Monoid {
    using S = pair<mint, int>;
    static S op(S a, S b) {
        return make_pair(a.first + b.first, a.second + b.second);
    }
    static S e() { return make_pair(0, 0); }
};

struct Operator {
    using F = affine<mint>;
    static F comp(F f, F g) { return f(g); }
    static F id() { return F(); }
};

pair<mint, int> mapping(affine<mint> f, pair<mint, int> p) {
    auto [val, size] = p;
    return make_pair(f.a * val + f.b * size, size);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<pair<mint, int>> A(N, Monoid::e());
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[i] = make_pair(a, 1);
    }
    lazy_segtree<Monoid, Operator, mapping> seg(A);
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