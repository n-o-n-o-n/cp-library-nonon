#pragma once
#include "../../modint/montgomery_modint.hpp"
#include "prime_factor.hpp"
#include "../../random/utility.hpp"
using namespace std;

long long primitive_root(long long m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    if (m == 1224736769) return 3;
    auto ps = prime_factor(m - 1);
    using mint = montgomery_modint;
    mint::set_mod(m);
    mint a = rng::randint_64(1, m - 1);
    while ([&] {
        for (auto p : ps) {
            if (a.pow((m - 1) / p) == 1) return true;
        }
        return false;
    } ()) a = rng::randint_64(1, m - 1);
    return a.val();
}