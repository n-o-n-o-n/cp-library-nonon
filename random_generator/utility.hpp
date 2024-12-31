#pragma once
#include <cassert>
#include <random>
using namespace std;

random_device seed;
mt19937 rng(seed());
mt19937_64 rng_64(seed());

int randint(int low, int hi) {
    assert(low <= hi);
    uniform_int_distribution<int> dist(low, hi);
    return dist(rng);
}

long long randint_64(long long low, long long hi) {
    assert(low <= hi);
    uniform_int_distribution<long long> dist(low, hi);
    return dist(rng_64);
}

pair<int, int> randpair(int low, int hi, bool strict = false) {
    assert(low + strict <= hi);
    int L = randint(low, hi - strict);
    int R = randint(L + strict, hi);
    return make_pair(L, R);
}

pair<long long, long long> randpair_ll(long long low, long long hi, bool strict = false) {
    assert(low + strict <= hi);
    long long L = randint_64(low, hi - strict);
    long long R = randint_64(L + strict, hi);
    return make_pair(L, R);
}