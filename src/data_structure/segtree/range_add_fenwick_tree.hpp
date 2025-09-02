#pragma once
#include "fenwick_tree.hpp"

template<typename T>
struct range_add_fenwick_tree {
    range_add_fenwick_tree() = default;
    range_add_fenwick_tree(int n) : fw1(n + 1), fw2(n + 1) {}
    void add(int p, T x) {
        add(p, p + 1, x);
    }
    void add(int l, int r, T x) {
        fw1.add(l, -1 * x * l);
        fw1.add(r, x * r);
        fw2.add(l, x);
        fw2.add(r, -1 * x);
    }
    T sum(int l, int r) const {
        return sum(r) - sum(l);
    }
private:
    fenwick_tree<T> fw1, fw2;
    T sum(int p) const {
        return fw1.sum(0, p) + p * fw2.sum(0, p);
    }
};