#pragma once
#include <vector>
#include "prime_factor.hpp"
using namespace std;

vector<pair<long long, int>> factorise(long long n) {
    auto ps = prime_factor(n);
    vector<pair<long long, int>> res;
    res.reserve(ps.size());
    for (auto p : ps) {
        res.emplace_back(p, 0);
        while (n % p == 0) {
            res.back().second++;
            n /= p;
        }
    }
    return res;
}