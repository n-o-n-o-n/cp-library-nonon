#pragma once
#include <cassert>
#include "extended_gcd.hpp"
using namespace std;

long long mod_inv(long long a, long long mod) {
    long long inv, y;
    assert(extended_gcd(a, mod, inv, y) == 1);
    inv %= mod;
    return inv < 0 ? inv + mod : inv;
}