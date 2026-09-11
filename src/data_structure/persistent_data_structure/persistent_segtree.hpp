#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename Monoid>
struct persistent_segtree {
    using M = Monoid;
    using S = typename M::S;
    persistent_segtree() : persistent_segtree(0) {}
    persistent_segtree(int _n) : persistent_segtree(vector<S>(_n, M::e())) {}
    persistent_segtree(const vector<S> &v) : n(v.size()), roots(1, 1) {
        log = 0;
        while ((1 << log) < n) log++;
        sz = 1 << log;
        make_node(-1, -1);
        make_node(-1, -1);
        for (int i = 2; i < 2 * sz; i++) {
            make_node(i / 2, !(i & 1), sz <= i && i < sz + n ? v[i - sz] : M::e());
        }
    }
    void reserve(int q) {
        d.reserve(q * log);
        roots.reserve(q);
    }
    int set(int k, int p, const S &x) {
        assert(0 <= k && k < ssize(roots));
        assert(0 <= p && p < n);
        int res = roots.size();
        int i = make_node(-1, -1);
        roots.emplace_back(i);
        d[i] = d[roots[k]];
        set(i, roots[k], p, x, 0, sz);
        return res;
    }
    S prod(int k, int l, int r) const {
        assert(0 <= k && k < ssize(roots));
        assert(0 <= l && l <= r && r <= n);
        return prod(roots[k], l, r, 0, sz);
    }
private:
    int n, log, sz;
    struct node {
        node(const S &_x = M::e(), int p = -1) : x(_x), par(p), l(-1), r(-1) {}
        S x;
        int par, l, r;
    };
    vector<int> roots;
    vector<node> d;
    S val(int p) const { return p == -1 ? M::e() : d[p].x; }
    int make_node(int par, bool is_left, const S &x = M::e()) {
        int p = d.size();
        d.emplace_back(x, par);
        d[p].par = par;
        if (par != -1) (is_left ? d[par].l : d[par].r) = p;
        return p;
    }
    void update(int p) { d[p].x = M::op(val(d[p].l), val(d[p].r)); }
    void set(int i, int j, int p, const S &x, int l, int r) {
        if (l + 1 == r) {
            d[i].x = x;
            return;
        }
        int m = (l + r) / 2;
        if (p < m) {
            int ni = make_node(i, true);
            d[i].r = d[j].r;
            set(ni, d[j].l, p, x, l, m);
        } else {
            int ni = make_node(i, false);
            d[i].l = d[j].l;
            set(ni, d[j].r, p, x, m, r);
        }
        update(i);
    }
    S prod(int i, int ql, int qr, int l, int r) const {
        if (i == -1 || qr <= l || ql >= r) return M::e();
        if (ql <= l && r <= qr) return val(i);
        int m = (l + r) / 2;
        return M::op(prod(d[i].l, ql, qr, l, m), prod(d[i].r, ql, qr, m, r));
    }
};