#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

#include "../main/modint/modint.hpp"
#include "../main/fps/fps.hpp"

#include <iostream>
using namespace std;

using mint = modint<998244353>;
using FPS = Formal_Power_Series<mint>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    FPS f(N), g(M);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        f[i] = a;
    }
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        g[i] = a;
    }
    FPS p = f.div(g);
    FPS q = f % g;
    cout << p.size() << ' ' << q.size() << '\n';
    for (int i = 0; i < int(p.size()); i++) {
        if (i) cout << ' ';
        cout << p[i].val();
    } cout << '\n';
    for (int i = 0; i < int(q.size()); i++) {
        if (i) cout << ' ';
        cout << q[i].val();
    } cout << '\n';
}