#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"

#include "../main/data_structure/union_find/weighted_union_find.hpp"
#include "../main/modint/modint.hpp"


using mint = modint<998244353>;

#include <iostream>
using namespace std;

struct G {
    using S = mint;
    static S op(S a, S b) { return a + b; }
    static S e() { return 0; }
    static S inv(S x) { return -x; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    weighted_dsu<G> uf(N);
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int u, v, w;
            cin >> u >> v >> w;
            cout << (uf.merge(v, u, w) ? 1 : 0) << '\n';
        } else {
            int u, v;
            cin >> u >> v;
            if (uf.same(u, v)) {
                cout << uf.diff(v, u).val() << '\n';
            } else {
                cout << "-1" << '\n';
            }
        }
    }
}