#pragma once
#include <cassert>
#include <concepts>
#include <random>
using namespace std;

namespace rng {

inline random_device seed;
inline mt19937 eng(seed());

template<typename T>
void set_seed(const T &sd) {
    eng.seed(sd);
}

template<integral T>
inline T randint(T lo, T hi) {
    assert(lo <= hi);
    uniform_int_distribution<T> dist(lo, hi);
    return dist(eng);
}

template<integral T>
inline pair<T, T> randpair(T lo, T hi, bool strict = false) {
    assert(lo + strict <= hi);
    T l = randint(lo, hi - strict);
    T r = randint(l + strict, hi);
    return make_pair(l, r);
}

} // namespace rng