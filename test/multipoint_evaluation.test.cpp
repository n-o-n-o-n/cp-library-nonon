#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include "../main/modint/modint.hpp"
#include "../main/fps/fps.hpp"
#include "../main/fps/multipoint_evaluation.hpp"

#include <iostream>
using namespace std;

using mint = modint<998244353>;
using FPS = Formal_Power_Series<mint>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    FPS f(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        f[i] = a;
    }
    vector<mint> xs(M);
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        xs[i] = x;
    }
    vector<mint> ys = multipoint_evaluation(f, xs);
    for (int i = 0; i < M; i++) {
        cout << ys[i].val() << " \n"[i + 1 == M];
    }
}