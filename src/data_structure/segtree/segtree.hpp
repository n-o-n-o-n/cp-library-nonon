#pragma once
#include <vector>
#include <cassert>
using namespace std;

template <typename Monoid>
struct segtree {
    using M = Monoid;
    using S = typename M::S;
    segtree() : segtree(0) {}
    segtree(int _n) : segtree(vector<S>(_n, M::e())) {}
    segtree(const vector<S> &v) : n(v.size()) {
        log = 1;
        while ((1 << log) < n) log++;
        sz = 1 << log;
        d = vector<S>(2 * sz, M::e());
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
    int max_right(int l, const C &check) const {
        assert(0 <= l && l <= n);
        assert(check(M::e()));
        if (l == n) return l;
        l += sz;
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
    int max_right(const C &check) const {
        return max_right(0, check);
    }
    template<typename C>
    int min_left(int r, const C &check) const {
        assert(0 <= r && r <= n);
        assert(check(M::e()));
        if (r == 0) return r;
        r += sz;
        S p = M::e();
        do {
            r--;
            while (r > 1 && r & 1) r >>= 1;
            S np = M::op(d[r], p);
            if (!check(np)) {
                while (r < sz) {
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
    int min_left(const C &check) const {
        return min_left(n, check);
    }
private:
    int n, log, sz;
    vector<S> d;
    void update(int p) {
        d[p] = M::op(d[2 * p], d[2 * p + 1]);
    }
};