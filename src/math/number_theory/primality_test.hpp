#pragma once
#include <array>
#include "../../modint/dynamic_montgomery_modint.hpp"
using namespace std;

template<size_t size>
bool miller_rabin(long long m, const array<int, size> &ps) {
    using mint = dynamic_montgomery_modint;
    mint::set_mod(m);
    long long u = 0, v = m - 1;
    while ((v & 1) == 0) u++, v >>= 1;
    for (int p : ps) {
        if (m <= p) return true;
        mint x = mint(p).pow(v);
        if (x.val() != 1) {
            long long w;
            for (w = 0; w < u; w++) {
                if (x.val() == m - 1) break;
                x *= x;
            }
            if (w == u) return false;
        }
    }
    return true;
}

bool miller_rabin_small(long long m) {
    return miller_rabin(m, array<int, 3>{2, 7, 61});
}

bool miller_rabin_large(long long m) {
    return miller_rabin(m, array<int, 7>{2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

bool is_prime(long long m) {
    if (m <= 1) return false;
    if (m == 2) return true;
    if (m % 2 == 0) return false;
    return m < 4759123141LL ? miller_rabin_small(m) : miller_rabin_large(m);
}