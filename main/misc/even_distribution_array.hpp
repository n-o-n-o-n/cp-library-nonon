#pragma once
#include <vector>
using namespace std;

template<typename T>
vector<T> even_distribution_array(const vector<T> &v) {
    int n = v.size();
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
    }
    T q = sum / n, r = sum % n;
    vector<T> res(n, q);
    for (int i = n - r; i < n; i++) res[i]++;
    return res;
}