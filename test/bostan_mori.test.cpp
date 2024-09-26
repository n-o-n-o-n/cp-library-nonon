#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include "../main/modint/modint.hpp"
#include "../main/fps/fps.hpp"
#include "../main/math/bostan_mori.hpp"

using mint = modint<998244353>;
using FPS = Formal_Power_Series<mint>;

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    long long K;
    cin >> N >> K;
    FPS A(N), C(N);
    for (mint &a : A) {int e; cin >> e; a = e; }
    for (mint &c : C) {int e; cin >> e; c = e; }
    cout << linear_recurrence(A, C, K).val() << endl;
}