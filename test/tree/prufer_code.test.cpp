#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../src/tree/prufer_code.hpp"
#include "../../src/random/graph.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    {
        int A, B;
        cin >> A >> B;
        cout << A + B << '\n';
    }
    for (int t = 0; t < 20; t++) {
        // code -> tree -> code
        int N = rng::randint(3, (int)2e5);
        vector<int> A(N - 2);
        for (auto &e : A) e = rng::randint(0, N - 1);
        assert(A == prufer_code_compress(prufer_code_expansion(A)));
    }
}