#pragma once
#include <vector>
#include "../data_structure/segtree/fenwick_tree.hpp"
#include "compress.hpp"

template<typename S>
long long inversion_number(const vector<S> &v) {
    int n = v.size();
    vector<int> a = compress(v);
    fenwick_tree<int> fw(n);
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += fw.sum(a[i] + 1, n);
        fw.add(a[i], 1);
    }
    return res;
}