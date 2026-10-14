#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../src/math/number_theory/prime_factor.hpp"
#include "../../../src/random/utility.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    {
        int A, B;
        cin >> A >> B;
        cout << A + B << '\n';
    }
    for (int t = 0; t < 100; t++) {
        long long N = rng::randint(1LL, (long long)1e18);
        for (auto p : prime_factor(N)) {
            assert(N % p == 0);
            while (N % p == 0) N /= p;
        }
        assert(N == 1);
    }
}