#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../src/math/number_theory/mod_pow.hpp"
#include "../../../src/random/utility.hpp"

#include <iostream>
#include <atcoder/math>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    {
        int A, B;
        cin >> A >> B;
        cout << A + B << '\n';
    }
    for (int t = 0; t < (int)1e5; t++) {
        long long mod = rng::randint(2LL, (long long)1e9);
        long long a = rng::randint(0LL, mod - 1);
        long long k = rng::randint(0LL, (long long)1e18);
        assert(mod_pow(a, k, mod) == atcoder::pow_mod(a, k, mod));
    }
}