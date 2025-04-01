#pragma once
#include <cassert>
#include <vector>
using namespace std;

struct bit_vector {
    bit_vector() = default;
    bit_vector(const vector<bool> &v) {
        int n = v.size();
        int m = n / b + 1;
        d = vector<unsigned>(m);
        sum = vector<int>(m + 1);
        for (int i = 0; i < n; i++) {
            d[i / b] |= v[i] << (i % b);
        }
        for (int i = 0; i < m; i++) {
            sum[i + 1] = sum[i] + __builtin_popcount(d[i]);
        }
    }
    bool operator[](int i) const { return d[i / b] >> (i % b) & 1; }
    int rank(int i, bool flag = false) const {
        int mask = (1U << (i % b)) - 1;
        int r = sum[i / b] + __builtin_popcount(d[i / b] & mask);
        return flag ? r : i - r;
    }
    int select(int i, bool flag) const {
        int l = 0, r = d.size();
        while (r - l > 1) {
            int m = (l + r) >> 1;
            (rank(i, flag) < i ? l : r) = m;
        }
        return l;
    }
private:
    static constexpr int b = 32;
    vector<unsigned> d;
    vector<int> sum;
};