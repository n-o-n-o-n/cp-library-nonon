#pragma once
#include <bit>
#include <cassert>
#include <vector>
using namespace std;

template<typename Monoid>
struct sparse_table {
    using S = typename Monoid::S;
    sparse_table(int _n) : n(_n), b(0), d(1, vector<S>(_n, Monoid::e())) {}
    sparse_table(const vector<S> &v) : d(1, v) { build(); }
    void set(int p, S x) {
        assert(0 <= p && p < n);
        assert(d[0][p] == Monoid::e());
        d[0][p] = x;
    }
    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <=n);
        build();
        if (l == r) return Monoid::e();
        int i = bit_width(unsigned(r - l)) - 1;
        return Monoid::op(d[i][l], d[i][r - (1 << i)]);
    }
private:
    int n, b;
    vector<vector<S>> d;
    void build() {
        if (b > 0) return;
        b = bit_width(unsigned(n));
        d.resize(b, vector<S>(n, Monoid::e()));
        for (int i = 1; i < b; i++) {
            for (int j = 0; j + (1 << i) <=n; j++) {
                d[i][j] = Monoid::op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
};