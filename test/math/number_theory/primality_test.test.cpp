#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include "../../../src/math/number_theory/primality_test.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    cin >> Q;
    for (long long N; Q--; ) {
        cin >> N;
        cout << (is_prime(N) ? "Yes\n" : "No\n");
    }
}