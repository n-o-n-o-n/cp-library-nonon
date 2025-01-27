#pragma once
#include <vector>
#include "../../modint/montgomery_modint.hpp"
#include "primality_test.hpp"
#include "../../../random_generator/utility.hpp"
using namespace std;

long long rho(long long n) {
    for (int p : {2, 3, 5, 7}) {
        if (n % p == 0) return p;
    }
    using mint = montgomery_modint;
    mint::set_mod(n);
    while (true) {
        mint u = randint_64(2, n - 1);
        mint v = u;
        mint c = randint_64(1, n - 1);
        long long d = 1;
        while (d == 1) {
            u = u * u + c;
            v = v * v + c;
            v = v * v + c;
            d = gcd((u - v).val(), n);
        }
        if (d < n) return d;
    }
    return -1;
}

vector<long long> prime_factor(long long n) {
    if (n <= 1) return {};
    if (is_prime(n)) return {n};
    vector<long long> res;
    long long d = rho(n);
    auto a = prime_factor(d);
    auto b = prime_factor(n / d);
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
    return res;
}