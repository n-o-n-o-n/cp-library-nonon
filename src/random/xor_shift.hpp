#pragma once
#include <cstdint>
#include <type_traits>
using namespace std;

template<typename T>
struct xor_shift {
    using U = typename make_unsigned<T>::type;
    constexpr xor_shift(U seed) : x(seed == 0 ? 987139873 : seed) {}
    constexpr U operator()() {
        if constexpr (sizeof(T) <= 4) {
            x ^= x << 13;
            x ^= x >> 17;
            x ^= x << 5;
        } else {
            x ^= x << 13;
            x ^= x >> 7;
            x ^= x << 17;
        }
        return x;
    }
    constexpr T operator()(T low, T hi) {
        return low + (*this)() % (hi - low + 1);
    }
private:
    U x;
};