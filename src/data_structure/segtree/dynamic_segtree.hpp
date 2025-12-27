#pragma once
#include <cassert>
#include <memory>
using namespace std;

template<typename Monoid, typename T = int>
struct dynamic_segtree {
    using M = Monoid;
    using S = M::S;
    dynamic_segtree(T _n = 0) : n(_n), root(make_unique<node>()) {
        log = 1;
        while ((T(1) << log) < n) log++;
        sz = T(1) << log;
    }
    void set(T p, const S &x) {
        assert(0 <= p && p < n);
        set(root, 0, sz, p, x);
    }
    S get(T p) const {
        assert(0 <= p && p < n);
        return get(root, 0, sz, p);
    }
    S prod(T l, T r) const {
        assert(0 <= l && l <= r && r <= n);
        return prod(root, 0, sz, l, r);
    }
    S all_prod() const {
        return root ? root->x : M::e();
    }
private:
    struct node {
        S x;
        unique_ptr<node> l, r;
        node() : node(M::e()) {}
        node(S _x) : x(_x), l(nullptr), r(nullptr) {}
        void update() {
            S pl = l ? l->x : M::e();
            S pr = r ? r->x : M::e();
            x = M::op(pl, pr);
        }
    };
    T n, sz;
    int log;
    unique_ptr<node> root;
    void set(unique_ptr<node> &t, T l, T r, T p, const S &x) {
        if (l + 1 == r) {
            t->x = x;
            return;
        }
        T m = (l + r) / 2;
        if (p < m) {
            if (!t->l) t->l = make_unique<node>();
            set(t->l, l, m, p, x);
        } else {
            if (!t->r) t->r = make_unique<node>();
            set(t->r, m, r, p, x);
        }
        t->update();
    }
    S get(const unique_ptr<node> &t, T l, T r, T p) const {
        if (!t) return M::e();
        if (l + 1 == r) return t->x;
        T m = (l + r) / 2;
        return p < m ? get(t->l, l, m, p) : get(t->r, m, r, p);
    }
    S prod(const unique_ptr<node> &t, T l, T r, T ql, T qr) const {
        if (!t || r <= ql || qr <= l) return M::e();
        if (ql <= l && r <= qr) return t->x;
        T m = (l + r) / 2;
        S pl = t->l ? prod(t->l, l, m, ql, qr) : M::e();
        S pr = t->r ? prod(t->r, m, r, ql, qr) : M::e();
        return M::op(pl, pr);
    }
};