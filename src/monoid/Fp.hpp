#pragma once
using namespace std;

struct Fp_64 {
    using S = long long;
    using F = long long;
    static long long m;
    static void set_mod(long long _m) { m = _m; }
    static F comp(F f, F g) {
        return (__int128_t(f) * g) % m;
    }
    static F id() {
        return m == 1 ? 0 : 1;
    }
    static S mapping(F f, S x) {
        return (__int128_t(f) * x) % m;
    }
};
long long Fp_64::m = 0;