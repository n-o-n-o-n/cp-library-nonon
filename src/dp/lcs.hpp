#pragma once
#include <vector>
#include <string>
using namespace std;

template<typename T>
vector<T> longest_common_subsequence(const vector<T> &s, const vector<T> &t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            }
        }
    }
    vector<T> res;
    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0) {
        if (s[i] == t[j]) {
            res.push_back(s[i]);
            i--, j--;
        } else {
            (dp[i][j] == dp[i + 1][j] ? i-- : j--);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

string longest_common_subsequence(const string &s, const string &t) {
    vector<char> a(s.begin(), s.end()), b(t.begin(), t.end());
    vector<char> c = longest_common_subsequence(a, b);
    return string(c.begin(), c.end());
}