#pragma once
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// S[ sa[i-1] : N] < S[ sa[i] : N]
// O(N log N)
template<typename S>
vector<int> suffix_array(const vector<S> &v) {
    int n = v.size();
    vector<int> sa(n);
    for (int i = 0; i < n; i++) sa[i] = i;
    sort(sa.begin(), sa.end(), [&](int i, int j) {
        return v[i] == v[j] ? i > j : v[i] < v[j];
    });
    vector<int> cls(n), c(n), cnt(n);
    for (int i = 0; i < n; i++) c[i] = v[i];
    for (int k = 1; k < n; k <<= 1) {
        cls[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            cls[sa[i]] = ([&] {
                if (c[ sa[i - 1] ] != c[ sa[i] ]) return false;
                if (sa[i - 1] + k >= n) return false;
                if (c[ sa[i - 1] + k / 2 ] != c[ sa[i] + k / 2 ]) return false;
                return true;
            }()) ? cls[ sa[i - 1] ] : i;
        }
        for (int i = 0; i < n; i++) {
            cnt[i] = i;
            c[i] = sa[i];
        }
        for (int i = 0; i < n; i++) {
            int j = c[i] - k;
            if (j >= 0) sa[ cnt[ cls[j] ]++ ] = j;
        }
        swap(c, cls);
    }
    return sa;
}

vector<int> suffix_array(const string &s) {
    return suffix_array(vector<char>(s.begin(), s.end()));
}