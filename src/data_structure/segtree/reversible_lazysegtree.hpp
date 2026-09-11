#pragma once
#include <cassert>
#include <tuple>
#include <vector>
using namespace std;

template<typename ActMonoid>
struct reversible_lazysegtree {
    using M = ActMonoid;
    using S = typename M::S;
    using F = typename M::F;
    reversible_lazysegtree() : reversible_lazysegtree(0) { d.emplace_back(); }
    reversible_lazysegtree(int n, int q = 0) : root(0) {
        d.reserve(n + q + 1);
        d.emplace_back();
    }
    reversible_lazysegtree(const vector<S> &v, int q = 0) : root(0) {
        d.reserve(ssize(v) + q + 1);
        d.emplace_back();
        for (const auto &e : v) {
            root = merge(root, new_node(e));
        }
    }
    void set(int p, const S &x) {
        assert(0 <= p && p < size(root));
        auto [pl, pm, pr] = split(root, p, p + 1);
        d[pm].val = x;
        update(pm);
        root = merge(pl, pm, pr);
    }
    void apply(int l, int r, const F &f) {
        assert(0 <= l && l <= r && r <= size(root));
        auto [pl, pm, pr] = split(root, l, r);
        all_apply(pm, f);
        root = merge(pl, pm, pr);
    }
    void reverse(int l, int r) {
        assert(0 <= l && l <= r && r <= size(root));
        auto [pl, pm, pr] = split(root, l, r);
        toggle(pm);
        root = merge(pl, pm, pr);
    }
    void insert(int p, const S &x) {
        assert(0 <= p && p <= size(root));
        auto [pl, pr] = split(root, p);
        root = merge(pl, new_node(x), pr);
    }
    void push_back(const S &x) {
        root = merge(root, new_node(x));
    }
    void push_front(const S &x) {
        root = merge(new_node(x), root);
    }
    void erase(int p) {
        assert(0 <= p && p < size(root));
        auto [pl, pm, pr] = split(root, p, p + 1);
        root = merge(pl, pr);
    }
    void pop_back() {
        assert(size(root));
        erase(size(root) - 1);
    }
    void pop_front() {
        assert(size(root));
        erase(0);
    }
    S get(int p) {
        assert(0 <= p && p < size(root));
        auto [pl, pm, pr] = split(root, p, p + 1);
        auto res = d[pm].val;
        root = merge(pl, pm, pr);
        return res;
    }
    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= size(root));
        auto [pl, pm, pr] = split(root, l, r);
        auto res = d[pm].sum;
        root = merge(pl, pm, pr);
        return res;
    }
private:
    struct node {
        int l, r, sz;
        S val, sum, mus;
        F f;
        bool rev;
        unsigned int pri;
        node() : l(0), r(0), sz(0), val(M::e()), sum(M::e()), mus(M::e()), f(M::id()), rev(false) {}
        node(const S &x) : l(0), r(0), sz(1), val(x), sum(x), mus(x), f(M::id()), rev(false) {
            pri = xor_shift();
        }
    };
    vector<node> d;
    int root;
    int size(int p) { return d[p].sz; }
    S val(int p) { return d[p].val; }
    S sum(int p) { return d[p].sum; }
    S mus(int p) { return d[p].mus; }
    int new_node(const S &x = M::e()) {
        int r = d.size();
        d.emplace_back(x);
        return r;
    }
    inline void toggle(int p) {
        if (!p) return;
        swap(d[p].l, d[p].r);
        swap(d[p].sum, d[p].mus);
        d[p].rev ^= true;
    }
    void all_apply(int p, const F &f) {
        if (!p) return;
        d[p].f = M::comp(f, d[p].f);
        d[p].val = M::map(f, d[p].val);
        d[p].sum = M::map(f, d[p].sum);
        d[p].mus = M::map(f, d[p].mus);
    }
    void update(int p) {
        if (!p) return;
        d[p].sz = size(d[p].l) + size(d[p].r) + 1;
        d[p].sum = M::op(d[d[p].l].sum, M::op(d[p].val, d[d[p].r].sum));
        d[p].mus = M::op(d[d[p].r].mus, M::op(d[p].val, d[d[p].l].mus));
    }
    void push(int p) {
        if (!p) return;
        all_apply(d[p].l, d[p].f);
        all_apply(d[p].r, d[p].f);
        d[p].f = M::id();
        if (d[p].rev) {
            toggle(d[p].l);
            toggle(d[p].r);
            d[p].rev = false;
        }
    }
    int merge(int l, int r) {
        if (!l) return r;
        if (!r) return l;
        if (d[l].pri > d[r].pri) {
            push(l);
            d[l].r = merge(d[l].r, r);
            update(l);
            return l;
        } else {
            push(r);
            d[r].l = merge(l, d[r].l);
            update(r);
            return r;
        }
    }
    int merge(int l, int m, int r)  {
        return merge(l, merge(m, r));
    }
    pair<int, int> split(int p, int k) {
        int pl = 0, pr = 0;
        if (!p) return {pl, pr};
        push(p);
        int ls = size(d[p].l);
        if (k <= ls) {
            tie(pl, d[p].l) = split(d[p].l, k);
            update(p);
            pr = p;
        } else {
            tie(d[p].r, pr) = split(d[p].r, k - ls - 1);
            update(p);
            pl = p;
        }
        return {pl, pr};
    }
    tuple<int, int, int> split(int p, int l, int r) {
        auto [plm, pr] = split(p, r);
        auto [pl, pm] = split(plm, l);
        return {pl, pm, pr};
    }
    static unsigned int xor_shift() {
        static unsigned int x = 123456789;
        static unsigned int y = 362436069;
        static unsigned int z = 521288629;
        static unsigned int w = 88675123;
        unsigned int t = x ^ (x << 11);
        x = y, y = z, z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }
};