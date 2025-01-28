#pragma once
using namespace std;

long long mod_pow(long long a, long long n, long long mod) {
    a %= mod;
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = __int128_t(res) * a % mod;
        a = __int128_t(a) * a % mod;
        n >>= 1;
    }
    return res;
}