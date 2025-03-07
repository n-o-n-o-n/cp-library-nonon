#pragma once
#include <algorithm>
#include <vector>
#include "merge_and_unique.hpp"
using namespace std;

template<typename T>
vector<int> compress(const vector<T> &v) {
    int n = v.size();
    auto b = merge_and_unique(v);
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = lower_bound(b.begin(), b.end(), v[i]) - b.begin();
    }
    return res;
}