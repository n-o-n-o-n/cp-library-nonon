#pragma once
#include "prime_factor.hpp"

template<typename T>
T totient(T n) {
    auto ps = prime_factor(n);
    for (auto p : ps) n -= n / p;
    return n;
}