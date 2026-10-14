#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "../../src/tree/hld.hpp"
#include "../../src/data_structure/segtree/segtree.hpp"
#include "../../src/data_structure/segtree/directed_range_query.hpp"
#include "../../src/modint/modint.hpp"
#include "../../src/math/affine.hpp"

using mint = modint<998244353>;

struct Monoid {
    using S = affine<mint>;
    static S op(S f, S g) { return g(f); }
    static S e() { return S(); }
};

using SegTree = directed_range_query<segtree<Monoid>>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    heavy_light_decomposition<SegTree, false, false> G(N);
    for (int i = 1, u, v; i < N; i++) {
        cin >> u >> v;
        G.add_edge(u, v);
    }
    for (int i = 0; i < N; i++) {
        G.set(i, affine<mint>(A[i], B[i]));
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int u, a, b;
            cin >> u >> a >> b;
            G.set(u, affine<mint>(a, b));
        } else {
            int u, v, x;
            cin >> u >> v >> x;
            auto f = G.prod(u, v);
            cout << f(x).val() << '\n';
        }
    }
}