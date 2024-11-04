#pragma once
#include <vector>
using namespace std;

template<typename T>
struct fenwick_tree {
    fenwick_tree() = default;
    fenwick_tree(int _n) : n(_n), d(_n, 0) {}
    void add(int p, T x) {
        p++;
        while (p <= n) {
            d[p - 1] += x;
            p += p & -p;
        }
    }
    T sum(int l, int r) const {
        return sum(r) - sum(l);
    }
private:
    int n;
    vector<T> d;
    T sum(int p) const {
        T res = 0;
        while (p) {
            res += d[p - 1];
            p -= p & -p;
        }
        return res;
    }
};