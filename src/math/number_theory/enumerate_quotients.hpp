#pragma once
#include <vector>
using namespace std;

template<typename T>
vector<tuple<T, T, T>> enumerate_quotients(T n) {
    vector<tuple<T, T, T>> res;
    for (T l = 1, r, q; l <= n; l = r) {
        q = n / l;
        r = n / q + 1;
        res.emplace_back(l, r, q);
    }
    return res;
}