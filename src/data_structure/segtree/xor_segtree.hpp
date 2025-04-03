#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename Monoid>
struct xor_segtree {
    using S = Monoid::S;
    xor_segtree() : xor_segtree(0) {}
    xor_segtree(int _n) : xor_segtree(vector<S>(_n, Monoid::e())) {}
    xor_segtree(const vector<S> &v) : n(v.size()) {
        log = 1;
        while ((1 << log) < n) log++;
        mid = (log + 1) / 2;
        sz = 1 << log;
        d = vector<vector<S>>(log + 1, vector<S>(sz, Monoid::e()));
        for (int i = 0; i < n; i++) d[0][i] = v[i];
        for (int j = 0; j < log; j++) {
            for (int i = 0; i < sz; i++) update(j, i);
        }
    }
    void set(int p, const S &x) {
        assert(0 <= p && p < n);
        d[0][p] = x;
        for (int j = 0; j < mid; j++) {
            for (int i = 0; i < 1 << (j + 1); i++) update(j, p ^ i);
        }
    }
    S get(int p) const {
        assert(0 <= p && p < n);
        return d[0][p];
    }
    S prod(int l, int r, int x) const {
        assert(0 <= l && l <= r && r <= n);
        assert(0 <= x && x < sz);
        S pl = Monoid::e(), pr = Monoid::e();
        int k = 0;
        while (l < r && k < mid) {
            if (l & 1) pl = Monoid::op(pl, d[k][((l++) << k) ^ x]);
            if (r & 1) pr = Monoid::op(d[k][((--r) << k) ^ x], pr);
            l >>= 1;
            r >>= 1;
            k++;
        }
        while (l < r) pl = Monoid::op(pl, d[mid][((l++) << mid) ^ x]);
        return Monoid::op(pl, pr);
    }
private:
    int n, log, mid, sz;
    vector<vector<S>> d;
    void update(int p, int q) {
        d[p + 1][q] = Monoid::op(d[p][q], d[p][q ^ (1 << p)]);
    }
};