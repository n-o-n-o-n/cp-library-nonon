#pragma once
#include <vector>
using namespace std;

template<typename S>
struct fenwick_tree {
    fenwick_tree() : n(0), d(0) {}
    fenwick_tree(int _n) : n(_n), d(_n) {}
    void add(int p, S x) {
        p++;
        while (p <= n) {
            d[p - 1] += x;
            p += p & -p;
        }
    }
    S sum(int l, int r) const { return sum(r) - sum(l); }
private:
    int n;
    vector<S> d;
    S sum(int p) const {
        S res = 0;
        while (p) {
            res += d[p - 1];
            p -= p & -p;
        }
        return res;
    }
};