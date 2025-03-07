#pragma once
#include <algorithm>
#include <vector>
using namespace std;

template<typename T, typename... Vs>
vector<T> merge_and_unique(const vector<T> &a, const Vs &...z) {
    vector<T> res = a;
    (res.insert(res.end(), z.begin(), z.end()), ...);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}