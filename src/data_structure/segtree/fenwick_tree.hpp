#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename T>
struct fenwick_tree {
    fenwick_tree() = default;
    fenwick_tree(int _n) : fenwick_tree(vector<T>(_n, 0)) {}
    fenwick_tree(const vector<T> &_v) : n(_v.size()) {
        d = vector<T>(n, 0);
        v = vector<T>(n, 0);
        for (int i = 1; i <= n; i++) {
            v[i - 1] = _v[i - 1];
            d[i - 1] += v[i - 1];
            int j = i + (i & -i);
            if (j <= n) d[j - 1] += d[i - 1];
        }
    }
    void add(int p, T x) {
        assert(0 <= p && p < n);
        v[p] += x;
        for (p++; p <= n; p += p & -p) {
            d[p - 1] += x;
        }
    }
    void update(int p, T x) {
        assert(0 <= p && p < n);
        add(p, x - v[p]);
    }
    T get(int p) const {
        assert(0 <= p && p < n);
        return v[p];
    }
    T sum(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return sum(r) - sum(l);
    }
    // max{ r | sum(r) < x }
    int lower_bound(T x) const {
        int r = 0, p = 1;
        while ((p << 1) <= n) p <<= 1;
        while (p > 0) {
            if (r + p <= n && d[r + p - 1] < x) {
                r += p;
                x -= d[r - 1];
            }
            p >>= 1;
        }
        return r;
    }
private:
    int n;
    vector<T> d, v;
    T sum(int p) const {
        T res = 0;
        for (; p > 0; p -= p & -p) {
            res += d[p - 1];
        }
        return res;
    }
};