#pragma once
#include <algorithm>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
#include "suffix_array.hpp"
#include "lcp_array.hpp"

template<typename T>
tuple<int, int, int> longest_common_substring(const vector<T> &a, const vector<T> &b) {
    int n = a.size(), m = b.size();
    T q = max<T>(*max_element(a.begin(), a.end()), *max_element(b.begin(), b.end())) + 1;
    vector<T> ab;
    ab.reserve(n + m + 1);
    for (const T &e : a) ab.emplace_back(e);
    ab.emplace_back(q);
    for (const T &e : b) ab.emplace_back(e);
    auto sa = suffix_array(ab);
    auto lcp = lcp_array(ab, sa);
    tuple<int, int, int> res = make_tuple(0, 0, 0);
    int len = 0;
    for (int k = 0; k < n + m; k++) {
        int i = sa[k], j = sa[k + 1];
        if (i > j) swap(i, j);
        if (i < n && n < j && len < lcp[k + 1]) {
            len = lcp[k + 1];
            res = make_tuple(len, i, j - n - 1);
        }
    }
    return res;
}

tuple<int, int, int> longest_common_substring(const string &s, const string &t) {
    return longest_common_substring(vector<char>(s.begin(), s.end()), vector<char>(t.begin(), t.end()));
}