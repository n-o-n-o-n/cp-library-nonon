#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename ActMonoid, integral T = int>
struct dynamic_lazysegtree {
    using M = ActMonoid;
    using S = typename M::S;
    using F = typename M::F;
    dynamic_lazysegtree(T _n = 0, int q = 0) : n(_n) {
        int log = 1;
        while (T(1) << log < n) log++;
        d.reserve(1 + 2 * q * log);
        root = new_node(0, n);
    }
    void set(T p, const S &x) {
        assert(0 <= p && p < n);
        set(root, 0, n, p, x);
    }
    void apply(T l, T r, const F &f) {
        assert(0 <= l && l <= r && r <= n);
        apply(root, 0, n, l, r, f);
    }
    S get(T p) {
        assert(0 <= p && p < n);
        return get(root, 0, n, p);
    }
    S prod(T l, T r) {
        assert(0 <= l && l <= r && r <= n);
        return prod(root, 0, n, l, r);
    }
    S all_prod() const {
        return d[root].x;
    }
private:
    struct node {
        S x;
        F lz;
        int l, r;
        node() : node(M::e()) {}
        node(const S &_x) : x(_x), lz(M::id()), l(-1), r(-1) {}
    };
    T n;
    int root;
    vector<node> d;
    int new_node(T l, T r) {
        int res = d.size();
        d.emplace_back(M::init(l, r));
        return res;
    }
    void update(int t) {
        int l = d[t].l, r = d[t].r;
        const S pl = l == -1 ? M::e() : d[l].x;
        const S pr = r == -1 ? M::e() : d[r].x;
        d[t].x = M::op(pl, pr);
    }
    void all_apply(int t, const F &f) {
        if (t == -1) return;
        d[t].x = M::map(f, d[t].x);
        d[t].lz = M::comp(f, d[t].lz);
    }
    void push(int t, T l, T r) {
        T m = (l + r) / 2;
        if (d[t].l == -1) d[t].l = new_node(l, m);
        if (d[t].r == -1) d[t].r = new_node(m, r);
        all_apply(d[t].l, d[t].lz);
        all_apply(d[t].r, d[t].lz);
        d[t].lz = M::id();
    }
    void set(int t, T l, T r, T p, const S &x) {
        if (l + 1 == r) {
            d[t].x = x;
            return;
        }
        push(t, l, r);
        T m = (l + r) / 2;
        p < m ? set(d[t].l, l, m, p, x) : set(d[t].r, m, r, p, x);
        update(t);
    }
    void apply(int t, T l, T r, T ql, T qr, const F &f) {
        if (r <= ql || qr <= l) return;
        if (ql <= l && r <= qr) {
            all_apply(t, f);
            return;
        }
        push(t, l, r);
        T m = (l + r) / 2;
        apply(d[t].l, l, m, ql, qr, f);
        apply(d[t].r, m, r, ql, qr, f);
        update(t);
    }
    S get(int t, T l, T r, T p) {
        if (t == -1) return M::e();
        if (l + 1 == r) return d[t].x;
        push(t, l, r);
        T m = (l + r) / 2;
        return p < m ? get(d[t].l, l, m, p) : get(d[t].r, m, r, p);
    }
    S prod(int t, T l, T r, T ql, T qr) {
        if (t == -1 || r <= ql || qr <= l) return M::e();
        if (ql <= l && r <= qr) return d[t].x;
        push(t, l, r);
        T m = (l + r) / 2;
        return M::op(prod(d[t].l, l, m, ql, qr), prod(d[t].r, m, r, ql, qr));
    }
};