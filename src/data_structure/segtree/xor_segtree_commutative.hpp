#pragma once
#include <vector>
#include <cassert>
using namespace std;

template<typename Monoid>
struct xor_segtree {
    using S = Monoid::S;
    xor_segtree() : xor_segtree(0) {}
    xor_segtree(int _n) : xor_segtree(vector<S>(_n, Monoid::e())) {}
    xor_segtree(const vector<S> &v) : n(v.size()) {
        log = 1;
        while ((1 << log) < n) log++;
        sz = 1 << log;
        d = vector<S>(2 * sz, Monoid::e());
        for (int i = 0; i < n; i++) d[i + sz] = v[i];
        for (int i = sz - 1; i >= 1; i--) update(i);
    }
    void set(int p, const S &x) {
        assert(0 <= p && p < n);
        p += sz;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    S get(int p) const {
        assert(0 <= p && p < n);
        return d[p + sz];
    }
    S prod(int l, int r, int x) const {
        assert(0 <= l && l <= r && r <= n);
        l += sz;
        r += sz;
        S res = Monoid::e();
        while (l < r) {
            if (l & 1) res = Monoid::op(res, d[l++ ^ x]);
            if (r & 1) res = Monoid::op(d[--r ^ x], res);
            l >>= 1;
            r >>= 1;
            x >>= 1;
        }
        return res;
    }
    S all_prod() const { return d[1]; }
private:
    int n, log, sz;
    vector<S> d;
    void update(int p) {
        d[p] = Monoid::op(d[2 * p], d[2 * p + 1]);
    }
};