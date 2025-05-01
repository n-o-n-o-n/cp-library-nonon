#pragma once
#include <random>
#include <vector>
#include "../../modint/montgomery_modint.hpp"
#include "primality_test.hpp"
using namespace std;

template<typename T>
T rho(T n) {
    for (int p : {2, 3, 5, 7}) {
        if (n % p == 0) return p;
    }
    auto randint_64 = [&](T low, T hi) -> T {
        random_device seed;
        mt19937_64 rng(seed());
        uniform_int_distribution<T> dist(low, hi);
        return dist(rng);
    };
    using mint = montgomery_modint;
    mint::set_mod(n);
    while (true) {
        mint u = randint_64(2, n - 1);
        mint v = u;
        mint c = randint_64(1, n - 1);
        T d = 1;
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

template<typename T>
vector<T> prime_factor(T n) {
    if (n <= 1) return {};
    if (is_prime(n)) return {n};
    vector<T> res;
    T d = rho(n);
    auto a = prime_factor(d);
    auto b = prime_factor(n / d);
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}