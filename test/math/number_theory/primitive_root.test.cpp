#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"

#include "../../../src/math/number_theory/primitive_root.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    cin >> Q;
    for (long long P; Q--; ) {
        cin >> P;
        cout << primitive_root(P) << '\n';
    }
}