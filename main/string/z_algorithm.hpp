#pragma once
#include <vector>
using namespace std;

#include <vector>
using namespace std;

template<typename S> 
vector<int> z_algorithm(const vector<S> &v) {
    const int n = v.size();
    int p = 0;
    vector<int> z(n);
    for (int i = 1; i < n; i++) {
        int k = i - p;
        if (i + z[k] < p + z[p]) {
            z[i] = z[k];
        } else {
            int j = max(0, p + z[p] - i);
            while (i + j < n && v[j] == v[i + j]) j++;
            z[i] = j;
            p = i;
        }
    }
    z[0] = n;
    return z;
}

vector<int> z_algorithm(const string &s) {
    return z_algorithm(vector<char>(s.begin(), s.end()));
}