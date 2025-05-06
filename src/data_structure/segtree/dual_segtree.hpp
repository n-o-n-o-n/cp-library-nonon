#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename ActSet>
struct dual_segtree {
    using M = ActSet;
    using S = typename M::S;
    using F = typename M::F;
    dual_segtree() : dual_segtree(0) {}
    dual_segtree(int _n) : dual_segtree(vector<S>(_n, M::e())) {}
    dual_segtree(const vector<S> &v) { init(v); }
    void init(const vector<S> &v) {
        n = v.size();
        log = 1;
        while ((1 << log) < n) log++;
        sz = 1 << log;
        d = v;
        lz = vector<F>(sz, M::id());
    }
    void set(int p, const S &x) {
        assert(0 <= p && p < n);
        d[p] = x;
    }
    void apply(int l, int r, const F &f) {
        assert(0 <= l && l <= r && r <= n);
        l += sz, r += sz;
        inner_push(l);
        inner_push(r - 1);
        while (l < r) {
            if (l & 1) all_apply(l++, f);
            if (r & 1) all_apply(--r, f);
            l >>= 1;
            r >>= 1;
        }
    }
    S get(int p) {
        assert(0 <= p && p < n);
        inner_push(p + sz);
        return d[p];
    }
private:
    int n, log, sz;
    vector<S> d;
    vector<F> lz;
    void all_apply(int p, const F &f) {
        if (p < sz) {
            lz[p] = M::comp(f, lz[p]);
        } else {
            d[p - sz] = M::map(f, d[p - sz]);
        }
    }
    void push(int p) {
        all_apply(2 * p, lz[p]);
        all_apply(2 * p + 1, lz[p]);
        lz[p] = M::id();
    }
    void inner_push(int p) {
        for (int i = log; i >= 1; i--) push(p >> i);
    }
};