#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../src/math/number_theory/totient_function.hpp"
#include "../../../src/random/utility.hpp"

#include <numeric>
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
        int N = rng::randint(1, (int)1e6);
        int X = totient(N);
        for (int i = 1; i <= N; i++) {
            if (gcd(i, N) == 1) X--;
        }
        assert(X == 0);
    }
}