#pragma once
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
T kadane(const vector<T> &v, bool empty = false) {
    int n = v.size();
    T res = empty ? T(0) : *max_element(v.begin(), v.end());
    T s = 0;
    for (int i = 0; i < n; i++) {
        s = max(s, T(0)) + v[i];
        res = max(res, s);
    } 
    return res;
}