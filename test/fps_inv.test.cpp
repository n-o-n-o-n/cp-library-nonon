#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include "../main/modint/modint.hpp"
#include "../main/fps/fps.hpp"

#include <iostream>
using namespace std;

using mint = modint<998244353>;
using FPS = Formal_Power_Series<mint>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    FPS f(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        f[i] = a;
    }
    f = f.inv();
    for (int i = 0; i < N; i++) {
        cout << f[i].val() << " \n"[i + 1 == N];
    }
}