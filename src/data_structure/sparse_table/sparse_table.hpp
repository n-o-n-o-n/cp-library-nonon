#pragma once
#include <bit>
#include <cassert>
#include <vector>
using namespace std;

template<typename Monoid>
struct sparse_table {
    using S = typename Monoid::S;
    sparse_table() = default;
    sparse_table(int _n) : n(_n), b(0), d(1, vector<S>(_n, Monoid::e())), built(false) {}
    sparse_table(const vector<S> &v) : n(v.size()), b(0), d(1, v), built(false) { build(); }
    void set(int p, const S &x) {
        assert(!built);
        assert(0 <= p && p < n);
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
    int n, b, e;
    vector<vector<S>> d;
    bool built;
    void build() {
        if (built) return;
        b = bit_width(unsigned(n));
        d.resize(b, vector<S>(n, Monoid::e()));
        for (int i = 1; i < b; i++) {
            for (int j = 0; j + (1 << i) <=n; j++) {
                d[i][j] = Monoid::op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
            }
        }
        built = true;
    }
};