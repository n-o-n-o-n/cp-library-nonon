#pragma once
#include <algorithm>
#include <vector>
#include "primality_table.hpp"
using namespace std;

vector<int> enumerate_primes(int n) {
    auto tbl = primality_table(n);
    vector<int> res;
    res.reserve(count(tbl.begin(), tbl.end(), true));
    for (int i = 2; i <= n; i++) {
        if (tbl[i]) res.emplace_back(i);
    }
    return res;
}