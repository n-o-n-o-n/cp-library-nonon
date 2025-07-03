#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
#include "utility.hpp"
#include "../misc/even_distribution_array.hpp"
using namespace std;

namespace rng {

template<typename T>
void shuffle(vector<T> &v) {
    shuffle(v.begin(), v.end(), eng);
}

vector<int> random_sequence(int n, int low, int hi) {
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = randint(low, hi);
    }
    return res;
}

vector<long long> random_sequence_64(int n, long long low, long long hi) {
    vector<long long> res(n);
    for (int i = 0; i < n ; i++) {
        res[i] = randint_64(low, hi);
    }
    return res;
}

vector<int> random_increasing_sequence(int n, int low, int hi, bool strict = false) {
    assert(low + (n - 1) * strict <= hi);
    vector<int> res = random_sequence(n, low, hi - (n - 1) * strict);
    sort(res.begin(), res.end());
    for (int i = 0; i < n; i++) {
        res[i] += i * strict;
    }
    return res;
}

vector<long long> random_increasing_sequence_64(int n, long long low, long long hi, bool strict = false) {
    assert(low * (n - 1) * strict <= hi);
    vector<long long> res = random_sequence_64(n, low, hi - (n - 1) * strict);
    sort(res.begin(), res.end());
    for (int i = 0; i < n; i++) {
        res[i] += i * strict;
    }
    return res;
}

vector<int> random_decreasing_sequence(int n, int low, int hi, bool strict = false) {
    vector<int> res = random_increasing_sequence(n, low, hi, strict);
    reverse(res.begin(), res.end());
    return res;
}

vector<long long> random_decreasing_sequence_64(int n, long long low, long long hi, bool strict = false) {
    vector<long long> res = random_increasing_sequence_64(n, low, hi, strict);
    reverse(res.begin(), res.end());
    return res;
}

vector<int> random_permutaion(int n, int val = 0) {
    vector<int> res(n);
    iota(res.begin(), res.end(), val);
    shuffle(res.begin(), res.end(), eng);
    return res;
}

string random_string(int n, char a, char z) {
    string s(n, a);
    for (auto &c : s) c = randint(a, z);
    return s;
}

}