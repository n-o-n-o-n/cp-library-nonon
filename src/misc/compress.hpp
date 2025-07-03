#pragma once
#include <algorithm>
#include <vector>
#include "merge_and_unique.hpp"
using namespace std;

template<typename T, typename... Ts>
int compress(vector<T> &a, Ts &...z) {
    auto zip = merge_and_unique(a, z...);
    auto f = [&] (vector<T> &v) -> void {
        for (T &e : v) {
            e = lower_bound(zip.begin(), zip.end(), e) - zip.begin();
        }
    };
    (f(a), ..., f(z));
    return (int)zip.size();
}