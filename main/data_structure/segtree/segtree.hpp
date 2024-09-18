#pragma once
#include <vector>
#include <cassert>
using namespace std;

template<typename S, auto op, auto e>
struct segtree {
    segtree() : segtree(0) {}
    segtree(int _n) : segtree(vector<S>(_n, e())) {}
    segtree(const vector<S> &v) : n(v.size()) {
        log = 1;
        while ((1 << log) < n) log++;
        sz = 1 << log;
        d = vector<S>(2 * sz, e());
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
    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        l += sz;
        r += sz;
        S pl = e(), pr = e();
        while (l < r) {
            if (l & 1) pl = op(pl, d[l++]);
            if (r & 1) pr = op(d[--r], pr);
            l >>= 1;
            r >>= 1;
        }
        return op(pl, pr);
    }
    S all_prod() const { return d[1]; }
private:
    int n, log, sz;
    vector<S> d;
    void update(int p) {
        d[p] = op(d[2 * p], d[2 * p + 1]);
    }
};