#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include "../../../src/math/number_theory/floor_kth_root.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        unsigned long long A;
        int K;
        cin >> A >> K;
        cout << floor_kth_root<unsigned long long>(A, K) << '\n';
    }
}