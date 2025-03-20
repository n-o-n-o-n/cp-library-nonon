#pragma once
#include <vector>
using namespace std;

template<typename ActMonoid>
struct lazy_segtree {
    using S = typename ActMonoid::S;
    using F = typename ActMonoid::F;
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int _n) : lazy_segtree(vector<S>(_n, ActMonoid::e())) {}
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
        d[p] = ActMonoid::mapping(f, d[p]);
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
        S pl = ActMonoid::e(), pr = ActMonoid::e();
        while (l < r) {
            if (l & 1) pl = ActMonoid::op(pl, d[l++]);
            if (r & 1) pr = ActMonoid::op(d[--r], pr);
            l >>= 1;
            r >>= 1;
        }
        return ActMonoid::op(pl, pr);
    }
    S all_prod() const { return d[1]; }
    template<typename C>
    int max_right(int l, const C &check, int r = -1) {
        if (r == -1) r = n;
        assert(0 <= l && l <= r && r <= n);
        assert(check(ActMonoid::e()));
        if (l == r) return l;
        l += sz;
        inner_push(l);
        S p = ActMonoid::e();
        do {
            while (!(l & 1)) l >>= 1;
            S np = ActMonoid::op(p, d[l]);
            if (!check(np)) {
                while (l < sz) {
                    l <<= 1;
                    np = ActMonoid::op(p, d[l]);
                    if (check(np)) {
                        p = np;
                        l++;
                    }
                }
                return min(r, l - sz);
            }
            p = np;
            l++;
        } while ((l & -l) != l);
        return r;
    }
    template<typename C>
    int max_right(const C &check) {
        return max_right(0, check);
    }
    template<typename C>
    int min_left(int r, const C &check, int l = -1) {
        if (l == -1) l = 0;
        assert(0 <= l && l <= r && r <= n);
        assert(check(ActMonoid::e()));
        if (l == r) return l;
        r += sz;
        inner_push(r - 1);
        S p = ActMonoid::e();
        do {
            r--;
            while (r > 1 && r & 1) r >>= 1;
            S np = ActMonoid::op(d[r], p);
            if (!check(np)) {
                while (r < sz) {
                    push(r);
                    (r <<= 1)++;
                    np = ActMonoid::op(d[r], p);
                    if (check(np)) {
                        p = np;
                        r--;
                    }
                }
                return max(l, r + 1 - sz);
            }
            p = np;
        } while ((r & -r) != r);
        return l;
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
        d = vector<S>(2 * sz, ActMonoid::e());
        lz = vector<F>(sz, ActMonoid::id());
        for (int i = 0; i < n; i++) d[i + sz] = v[i];
        for (int i = sz - 1; i >= 1; i--) update(i);
    }
    void update(int p) {
        d[p] = ActMonoid::op(d[2 * p], d[2 * p + 1]);
    }
    void all_apply(int p, const F &f) {
        d[p] = ActMonoid::mapping(f, d[p]);
        if (p < sz) lz[p] = ActMonoid::comp(f, lz[p]);
    }
    void push(int p) {
        all_apply(2 * p, lz[p]);
        all_apply(2 * p + 1, lz[p]);
        lz[p] = ActMonoid::id();
    }
    void inner_update(int p) {
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void inner_push(int p) {
        for (int i = log; i >= 1; i--) push(p >> i);
    }
};