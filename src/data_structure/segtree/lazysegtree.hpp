#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename ActMonoid>
struct lazy_segtree {
    using M = ActMonoid;
    using S = typename M::S;
    using F = typename M::F;
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int _n) : lazy_segtree(vector<S>(_n, M::e())) {}
    lazy_segtree(const vector<S> &v) { init(v); }
    void set(const vector<S> &v) { init(v); }
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
        d[p] = M::mapping(f, d[p]);
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
        S pl = M::e(), pr = M::e();
        while (l < r) {
            if (l & 1) pl = M::op(pl, d[l++]);
            if (r & 1) pr = M::op(d[--r], pr);
            l >>= 1;
            r >>= 1;
        }
        return M::op(pl, pr);
    }
    S all_prod() const { return d[1]; }
    template<typename C>
    int max_right(int l, const C &check) {
        assert(0 <= l && l <= n);
        assert(check(M::e()));
        if (l == n) return l;
        l += sz;
        inner_push(l);
        S p = M::e();
        do {
            while (!(l & 1)) l >>= 1;
            S np = M::op(p, d[l]);
            if (!check(np)) {
                while (l < sz) {
                    l <<= 1;
                    np = M::op(p, d[l]);
                    if (check(np)) {
                        p = np;
                        l++;
                    }
                }
                return l - sz;
            }
            p = np;
            l++;
        } while ((l & -l) != l);
        return n;
    }
    template<typename C>
    int max_right(const C &check) {
        return max_right(0, check);
    }
    template<typename C>
    int min_left(int r, int l, const C &check) {
        assert(0 <= r && r <= n);
        assert(check(M::e()));
        if (r == 0) return l;
        r += sz;
        inner_push(r - 1);
        S p = M::e();
        do {
            r--;
            while (r > 1 && r & 1) r >>= 1;
            S np = M::op(d[r], p);
            if (!check(np)) {
                while (r < sz) {
                    push(r);
                    (r <<= 1)++;
                    np = M::op(d[r], p);
                    if (check(np)) {
                        p = np;
                        r--;
                    }
                }
                return r + 1 - sz;
            }
            p = np;
        } while ((r & -r) != r);
        return 0;
    }
    template<typename C>
    int min_left(const C &check) {
        return min_left(n, check);
    }
private:
    int n, log, sz;
    vector<S> d;
    vector<F> lz;
    void init(const vector<S> &v) {
        n = v.size();
        log = 1;
        while ((1 << log) < n) log++;
        sz = 1 << log;
        d = vector<S>(2 * sz, M::e());
        lz = vector<F>(sz, M::id());
        for (int i = 0; i < n; i++) d[i + sz] = v[i];
        for (int i = sz - 1; i >= 1; i--) update(i);
    }
    void update(int p) {
        d[p] = M::op(d[2 * p], d[2 * p + 1]);
    }
    void all_apply(int p, const F &f) {
        d[p] = M::mapping(f, d[p]);
        if (p < sz) lz[p] = M::comp(f, lz[p]);
    }
    void push(int p) {
        all_apply(2 * p, lz[p]);
        all_apply(2 * p + 1, lz[p]);
        lz[p] = M::id();
    }
    void inner_update(int p) {
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void inner_push(int p) {
        for (int i = log; i >= 1; i--) push(p >> i);
    }
};