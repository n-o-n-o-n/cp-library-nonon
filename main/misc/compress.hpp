#pragma once
#include <algorithm>
#include <vector>
using namespace std;

template<typename S>
vector<int> compress(const vector<S> &v) {
    int n = v.size();
    vector<S> b(v.begin(), v.end());
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = lower_bound(b.begin(), b.end(), v[i]) - b.begin();
    }
    return res;
}