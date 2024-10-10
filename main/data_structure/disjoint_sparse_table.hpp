#pragma once
#include <bit>
#include <cassert>
#include <vector>
using namespace std;

template<typename Monoid>
struct disjoint_sparse_table {
    using S = typename Monoid::S;
    disjoint_sparse_table() = default;
    disjoint_sparse_table(int _n) : n(_n), b(0), d(1, vector<S>(_n, Monoid::e())) {}
    disjoint_sparse_table(const vector<S> &v) : n(v.size()), b(0), d(1, v) { build(); }
    void set(int p, S x) {
        assert(0 <= p && p < n);
        assert(d[0][p] == Monoid::e());
        d[0][p] = x;
    }
    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <=n);
        build();
        if (l == r) return Monoid::e();
        if (l + 1 == r) return d[0][l];
        int i = bit_width(unsigned(l ^ (r - 1)));
        return Monoid::op(d[i][l], d[i][r - 1]);
    }
private:
    int n, b;
    vector<vector<S>> d;
    void build() {
        if (b > 0) return;
        b = bit_width(unsigned(n));
        d.resize(b + 1, vector<S>(n, Monoid::e()));
        for (int i = 1; i <= b; i++) {
            int len = 1 << i;
            int l = len >> 1;
            for (int k = 0; l < n; k += len, l += len) {
                d[i][l - 1] = d[0][l - 1];
                for (int j = l - 2; j >= k; j--) {
                    d[i][j] = Monoid::op(d[i][j + 1], d[0][j]);
                }
                d[i][l] = d[0][l];
                for (int j = l + 1; j < n && j < k + len; j++) {
                    d[i][j] = Monoid::op(d[i][j - 1], d[0][j]);
                }
            }
        }
    }
};