#pragma once
#include <cassert>
#include <memory>
using namespace std;

template<typename ActMonoid, typename T = int>
struct dynamic_lazysegtree {
    using M = ActMonoid;
    using S = typename M::S;
    using F = typename M::F;
    dynamic_lazysegtree() : dynamic_lazysegtree(0) {}
    dynamic_lazysegtree(T _n) : n(_n) {
        log = 1;
        while ((T(1) << log) < n) log++;
        sz = T(1) << log;
    }
    struct node {
        S x;
        F f;
        unique_ptr<node> l, r;
        node() : node(M::e()) {}
        node(const S &_x) : x(_x), f(M::id()), l(nullptr), r(nullptr) {}
        void update() {
            S pl = l ? l->x : M::e();
            S pr = r ? r->x : M::e();
            x = M::op(pl, pr);
        }
        void apply(const F &g) {
            f = M::comp(g, f);
        }
        void push(const F &g) {
            f = M::id();
        }
    };
    T n, sz;
    int log;
    unique_ptr<node> root;
    void push(unique_ptr<node> &t, T l, T r, T p) {
        /*
        autp update = [&] (T i) -> void {
            d[i] = M::op(d[2 * i], d[2 * i + 1]);
        };
        p += sz;
        for (int i = log; i >= 1; i--) {
            update(p >> i);
        }
        */
        if (!t) return;
    }
    void set(T p, const S &x) {
        assert(0 <= p && p < n);
        push(root, 0, sz, p);
        set(root, 0, sz, p, x);
        update(root, 0, sz, p);
    }
    void apply(T p, const F &f) {
        apply(p, p + 1, f);
        update(root, 0, sz, p);
    }
    void apply(T l, T r, const F &f) {
        push(root, 0, sz, l, r);
        apply(root, 0, sz, l, r, f);
        update(root, 0, sz, l, r);
    }
    S get(T p) {
        assert(0 <= p && p < n);
        push(root, 0, sz, p);
        return get(root, 0, sz, p);
    }
    S prod(T l, T r) {
        push(root, 0, sz, l, r);
        return prod(root, 0, sz, l, r);
    }
};
