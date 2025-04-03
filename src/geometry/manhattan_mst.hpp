#pragma once
#include <algorithm>
#include <map>
#include <numeric>
#include <vector>
using namespace std;

template<typename T>
vector<tuple<T, int, int>> manhattan_mst(vector<T> xs, vector<T> ys) {
    int n = xs.size();
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    vector<tuple<T, int, int>> res;
    res.reserve(4 * n);
    for (auto _ : {0, 1}) {
        for (auto _ : {0, 1}) {
            sort(ord.begin(), ord.end(), [&](int i, int j) {
                return xs[i] + ys[i] < xs[j] + ys[j];
            });
            map<T, int, greater<T>> mp;
            for (int i : ord) {
                for (auto it = mp.lower_bound(ys[i]); it != mp.end(); it = mp.erase(it)) {
                    int j = it->second;
                    T dx = xs[i] - xs[j], dy = ys[i] - ys[j];
                    if (dx < dy) break;
                    res.emplace_back(dx + dy, i, j);
                }
                mp[ys[i]] = i;
            }
            for (T &x : xs) x = -x;
        }
        swap(xs, ys);
    }
    sort(res.begin(), res.end());
    return res;
}