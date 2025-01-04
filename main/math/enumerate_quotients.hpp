#pragma once
#include <vector>
using namespace std;

template<typename T>
vector<T> enumerate_quotients(T n) {
    vector<T> res;
    for (T l = 1, r, q; l <= n; l = r + 1) {
        q = n / l;
        r = n / q;
        res.push_back(q);
    }
    reverse(res.begin(), res.end());
    return res;
}