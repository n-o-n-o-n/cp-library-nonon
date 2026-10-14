#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../src/math/number_theory/mod_inv.hpp"
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
    for (int t = 0; t < (int)1e5; t++) {
        long long mod = rng::randint(2, (int)1e9);
        long long x = mod;
        while (gcd(x, mod) != 1) x = rng::randint(1LL, mod - 1);
        assert(x * mod_inv(x, mod) % mod == 1);
    }
}