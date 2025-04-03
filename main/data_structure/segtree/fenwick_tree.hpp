#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename T>
struct fenwick_tree {
    fenwick_tree() = default;
    fenwick_tree(int _n) : n(_n), d(_n, 0), v(_n, 0) {}
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
    T sum(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return sum(r) - sum(l);
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