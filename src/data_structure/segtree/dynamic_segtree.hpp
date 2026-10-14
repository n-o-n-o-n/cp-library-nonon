#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename Monoid, integral T = int>
struct dynamic_segtree {
    using M = Monoid;
    using S = typename M::S;
    dynamic_segtree(T _n = 0, int q = 0) : n(_n) {
        int log = 1;
        while (T(1) << log < n) log++;
        d.reserve(1 + 2 * q * log);
        root = new_node();
    }
    void set(T p, const S &x) {
        assert(0 <= p && p < n);
        set(root, 0, n, p, x);
    }
    S get(T p) const {
        assert(0 <= p && p < n);
        return get(root, 0, n, p);
    }
    S prod(T l, T r) const {
        assert(0 <= l && l <= r && r <= n);
        return prod(root, 0, n, l, r);
    }
    S all_prod() const {
        return d[root].x;
    }
private:
    struct node {
        S x;
        int l, r;
        node() : x(M::e()), l(-1), r(-1) {}
    };
    T n;
    int root;
    vector<node> d;
    int new_node() {
        int res = d.size();
        d.emplace_back();
        return res;
    }
    void update(int t) {
        int l = d[t].l, r = d[t].r;
        const S pl = l == -1 ? M::e() : d[l].x;
        const S pr = r == -1 ? M::e() : d[r].x;
        d[t].x = M::op(pl, pr);
    }
    void set(int t, T l, T r, T p, const S &x) {
        if (l + 1 == r) {
            d[t].x = x;
            return;
        }
        T m = (l + r) / 2;
        if (p < m) {
            if (d[t].l == -1) d[t].l = new_node();
            set(d[t].l, l, m, p, x);
        } else {
            if (d[t].r == -1) d[t].r = new_node();
            set(d[t].r, m, r, p, x);
        }
        update(t);
    }
    S get(int t, T l, T r, T p) const {
        if (t == -1) return M::e();
        if (l + 1 == r) return d[t].x;
        T m = (l + r) / 2;
        return p < m ? get(d[t].l, l, m, p) : get(d[t].r, m, r, p);
    }
    S prod(int t, T l, T r, T ql, T qr) const {
        if (t == -1 || r <= ql || qr <= l) return M::e();
        if (ql <= l && r <= qr) return d[t].x;
        T m = (l + r) / 2;
        return M::op(prod(d[t].l, l, m, ql, qr), prod(d[t].r, m, r, ql, qr));
    }
};