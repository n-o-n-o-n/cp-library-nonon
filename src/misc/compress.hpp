#pragma once
#include <algorithm>
#include <vector>
#include "merge_and_unique.hpp"
using namespace std;

template<typename T>
vector<int> compress(const vector<T> &v) {
    auto zip = merge_and_unique(v);
    vector<int> res;
    res.reserve(v.size());
    for (const T &e : v) {
        res.push_back(lower_bound(zip.begin(), zip.end(), e) - zip.begin());
    }
    return res;
}

template<typename T, typename... Ts>
auto compress(const vector<T> &a, const Ts &...z) {
    auto zip = merge_and_unique(a, z...);
    auto f = [&] (const vector<T> &v) -> vector<int> {
        vector<int> res;
        res.reserve(v.size());
        for (const T &e : v) {
            res.push_back(lower_bound(zip.begin(), zip.end(), e) - zip.begin());
        }
        return res;
    };
    return make_tuple(f(a), f(z)...);
}

template<typename T, typename... Ts>
int compress_inplace(vector<T> &a, Ts &...z) {
    auto zip = merge_and_unique(a, z...);
    auto f = [&] (vector<T> &v) -> void {
        for (T &e : v) {
            e = lower_bound(zip.begin(), zip.end(), e) - zip.begin();
        }
    };
    (f(a), ..., f(z));
    return (int)zip.size();
}