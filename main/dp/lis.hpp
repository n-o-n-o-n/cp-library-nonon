#pragma once
#include <algorithm>
#include <vector>
#include "../misc/compress.hpp"
using namespace std;

template<typename S>
vector<int> longest_increasing_subsequence(const vector<S> &v, bool strict = true) {
    vector<int> a = compress(v);
    int n = v.size();
    vector<int> dp(n, 1 << 30), idx(n, -1);
    for (int i = 0; i < n; i++) {
        int j;
        if (strict) {
            j = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        } else {
            j = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        }
        dp[j] = a[i];
        idx[i] = j;
    }
    int m = *max_element(idx.begin(), idx.end());
    vector<int> res(m + 1);
    for (int i = n - 1; i >= 0; i--) {
        if (idx[i] == m) {
            res[m] = i;
            m--;
        }
    }
    return res;
}