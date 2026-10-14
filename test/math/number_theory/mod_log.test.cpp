#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include "../../../src/math/number_theory/mod_log.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int X, Y, M; T--; ) {
        cin >> X >> Y >> M;
        cout << mod_log(X, Y, M) << '\n';
    }
}