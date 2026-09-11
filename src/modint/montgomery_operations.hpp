#pragma once
#include <cstdint>
using namespace std;

struct montgomery_operation {
    using i64 = uint64_t;
    using i128 = __uint128_t;
    constexpr montgomery_operation() = default;
    constexpr montgomery_operation(i64 m) : mod(m), inv(m), r(-i128(m) % m) {
        inv *= 2 - mod * inv;
        inv *= 2 - mod * inv;
        inv *= 2 - mod * inv;
        inv *= 2 - mod * inv;
        inv *= 2 - mod * inv;
    }
    constexpr long long val(i128 x) {
        i64 res = reduce(x);
        return res >= mod ? res - mod : res;
    }
    constexpr i64 map(long long x) {
        return reduce((i128(x) + mod) * r);
    }
    constexpr i64 add(i64 a, i64 b) {
        a += b;
        if (a >= (mod << 1)) a -= mod << 1;
        return a;
    }
    constexpr i64 mul(i64 a, i64 b) {
        return reduce(i128(a) * b);
    }
    constexpr i64 pow(i64 a, long long k) {
        i64 res = map(1);
        while (k > 0) {
            if (k & 1) res = mul(res, a);
            a = mul(a, a);
            k >>= 1;
        }
        return res;
    }
private:
    i64 mod, inv, r;
    constexpr i64 reduce(i128 x) {
        return (x + i128(i64(x) * i64(-inv)) * mod) >> 64;
    }
};