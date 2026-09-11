#pragma once
#include <numeric>
#include <vector>
using namespace std;

template<typename T>
vector<int> hungarian(const vector<vector<T>> &a) {
    if (a.empty()) return {};
    const T inf = numeric_limits<T>::max();
    int h = a.size(), w = a[0].size();
    vector<int> p(w), way(w);
    vector<T> u(h, T(0)), v(w, T(0)), min_v;
    vector<bool> used;
    for (int r = 1; r < h; r++) {
        p[0] = r;
        min_v = vector<T>(w, inf);
        used = vector<bool>(w, false);
        int j = 0;
        while (p[j] != 0) {
            int i = p[j], k = 0;
            used[j] = true;
            T d = inf;
            for (int c = 1; c < w; c++) {
                if (used[c]) continue;
                T cur = a[i][c] - u[i] - v[c];
                if (cur < min_v[c]) min_v[c] = cur, way[c] = j;
                if (min_v[c] < d) d = min_v[c], k = c;
            }
            for (int c = 0; c < w; c++) {
                if (used[c]) u[p[c]] += d, v[c] -= d;
                else min_v[c] -= d;
            }
            j = k;
        }
        do {
            p[j] = p[way[j]];
            j = way[j];
        } while (j != 0);
    }
    vector<int> res(w - 1);
    for (int i = 0; i < w - 1; i++) res[i] = p[i + 1] - 1;
    return res;
}

template<typename T>
vector<int> assignment(const vector<vector<T>> &a) {
    int h = a.size(), w = a[0].size();
    vector<vector<T>> b(h + 1, vector<T>(w + 1, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) b[i + 1][j + 1] = a[i][j];
    }
    return hungarian(b);
}