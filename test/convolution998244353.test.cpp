#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../main/modint/modint.hpp"
#include "../main/convolution/convolution.hpp"

using mint = modint<998244353>;

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<mint> f(N), g(M);
    for (mint &x : f) { int a; cin >> a; x = a; }
    for (mint &x : g) { int a; cin >> a; x = a; }
    auto h = convolution(f, g);
    int K = h.size();
    for (int i = 0; i < K; i++) {
        cout << h[i].val() << " \n"[i + 1 == K];
    }
}