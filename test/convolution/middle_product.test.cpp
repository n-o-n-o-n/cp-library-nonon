#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../src/convolution/middle_product.hpp"
#include "../../src/modint/modint.hpp"

using mint = modint<998244353>;

#include <iostream>
#include <random>

vector<mint> naive(vector<mint> f, vector<mint> g) {
    int n = f.size(), m = g.size();
    vector<mint> h(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i && j < m; j++) h[i - j] += f[i] * g[j];
    }
    return h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    {
        int A, B;
        cin >> A >> B;
        cout << A + B << '\n';
    }
    mt19937 eng(353442899);
    for (int t = 0; t < 20; t++) {
        int N = eng() % 2000 + 1;
        int M = eng() % 2000 + 1;
        vector<mint> f(N), g(M);
        for (auto &e : f) e = eng() % mint::mod();
        for (auto &e : g) e = eng() % mint::mod();
        assert(naive(f, g) == middle_product(f, g));
    }
}