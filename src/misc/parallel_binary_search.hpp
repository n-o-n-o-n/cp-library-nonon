#pragma once
#include <vector>
using namespace std;

// 使い方はこれを参照: https://atcoder.jp/contests/past20-open/submissions/71648427 
template<typename A, typename Q, typename R>
vector<int> parallel_binary_search(int t, int q, const A &act, const Q &query, const R &reset) {
    vector<int> l(q, -1), r(q, t);
    for (int p = 1; p <= t; p *= 2) {
        reset();
        vector<int> m(q);
        vector<vector<int>> qs(t);
        for (int j = 0; j < q; j++) {
            m[j] = (l[j] + r[j]) / 2;
            qs[m[j]].push_back(j);
        }
        for (int i = 0; i < t; i++) {
            act(i);
            for (int j : qs[i]) (query(j) ? r[j] : l[j]) = m[j];
        }
    }
    return r;
}