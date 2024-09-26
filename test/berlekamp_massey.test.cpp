#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include "../main/modint/modint.hpp"
#include "../main/math/berlekamp_massey.hpp"

using mint = modint<998244353>;

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<mint> A(N);
    for (mint &a : A) { int e; cin >> e; a = e; }
    auto C = Berlekamp_Massey(A);
    C.erase(C.begin());
    cout << C.size() << '\n';
    for (int i = 0; i < C.size(); i++) {
        if (i) cout << ' ';
        cout << C[i].val();
    }
    cout << '\n';
}