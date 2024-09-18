#pragma once
#include <vector>
using namespace std;

template<typename S, auto op, auto e, typename F, auto mapping, auto composition, auto id>
struct lazy_segtree {
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int _n) : lazy_segtree(vector<S>(_n, e())) {}
    lazy_segtree(const vector<S> &v) : n(v.size()) {
        log = 1;
        while ((1 << log) < n) log++;
        sz = 1 << log;
        d = vector<S>(2 * sz, e());
        lz = vector<F>(sz, id());
        for (int i = 0; i < n; i++) d[i + sz] = v[i];
        for (int i = sz - 1; i >= 1; i--) update(i);
    }
    void set(int p, const S &x) {
        assert(0 <= p && p < n);
        p += sz;
        inner_push(p);
        d[p] = x;
        inner_update(p);
    }
    void apply(int p, const F &f) {
        assert(0 <= p && p < n);
        p += sz;
        inner_push(p);
        d[p] = mapping(f, d[p]);
        inner_update(p);
    }
    void apply(int l, int r, const F &f) {
        assert(0 <= l && l <=r && r <= n);
        l += sz;
        r += sz;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        int l2 = l, r2 = r;
        while (l < r) {
            if (l & 1) all_apply(l++, f);
            if (r & 1) all_apply(--r, f);
            l >>= 1;
            r >>= 1;
        }
        l = l2, r = r2;
        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }
    S get(int p) {
        assert(0 <= p && p < n);
        p += sz;
        inner_push(p);
        return d[p];
    }
    S prod(int l, int r) {
        assert(0 <= l && l <=r && r <= n);
        l += sz;
        r += sz;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
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
    vector<F> lz;
    void update(int p) {
        d[p] = op(d[2 * p], d[2 * p + 1]);
    }
    void all_apply(int p, const F &f) {
        d[p] = mapping(f, d[p]);
        if (p < sz) lz[p] = composition(f, lz[p]);
    }
    void push(int p) {
        all_apply(2 * p, lz[p]);
        all_apply(2 * p + 1, lz[p]);
        lz[p] = id();
    }
    void inner_push(int p) {
        for (int i = log; i >= 1; i--) push(p >> i);
    }
    void inner_update(int p) {
        for (int i = 1; i <= log; i++) update(p >> i);
    }
};