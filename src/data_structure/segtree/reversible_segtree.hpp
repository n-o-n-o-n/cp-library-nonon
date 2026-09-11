#pragma once
#include <cassert>
#include <memory>
#include <tuple>
#include "../../random/utility.hpp"
using namespace std;

template<typename Monoid>
struct reversible_segtree {
    using M = Monoid;
    using S = typename M::S;
    reversible_segtree() = default;
    reversible_segtree(const vector<S> &v) {
        root = nullptr;
        for (const auto &e : v) {
            auto new_node = make_unique<node>(e);
            root = merge(root, new_node);
        }
    }
    void set(int p, const S &x) {
        assert(0 <= p && p < size(root));
        auto [pl, pm, pr] = split(root, p, p + 1);
        pm->x = x;
        update(pm);
        root = merge(pl, pm, pr);
    }
    void reverse(int l, int r) {
        assert(0 <= l && l <= r && r <= size(root));
        auto [pl, pm, pr] = split(root, l, r);
        if (pm) pm->rev ^= true;
        root = merge(pl, pm, pr);
    }
    void insert(int p, const S &x) {
        assert(0 <= p && p <= size(root));
        auto [pl, pr] = split(root, p);
        auto pm = make_unique<node>(x);
        root = merge(pl, pm, pr);
    }
    void erase(int p) {
        assert(0 <= p && p < size(root));
        auto [pl, pm, pr] = split(root, p, p + 1);
        root = merge(pl, pr);
    }
    void push_back(const S &x) {
        auto pb = make_unique<node>(x);
        root = merge(root, pb);
    }
    void push_front(const S &x) {
        auto pf = make_unique<node>(x);
        root = merge(pf, root);
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
        auto res = val(pm);
        root = merge(pl, pm, pr);
        return res;
    }
    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= size(root));
        auto [pl, pm, pr] = split(root, l, r);
        auto res = sum(pm);
        root = merge(pl, pm, pr);
        return res;
    }
private:
    struct node {
        unique_ptr<node> l, r;
        S x, sum, mus;
        int sz, pri;
        bool rev;
        node() : node(M::e()) {}
        node(const S &_x) : l(nullptr), r(nullptr), x(_x), sum(_x), mus(_x), sz(1), rev(false) {
            pri = rng::randint(0, numeric_limits<int>::max());
        }
    };
    using node_ptr = unique_ptr<node>;
    node_ptr root;
    int size(const node_ptr &t) const { return t ? t->sz : 0; }
    S val(const node_ptr &t) const { return t ? t->x : M::e(); }
    S sum(const node_ptr &t) const { return t ? t->rev ? t->mus : t->sum : M::e(); }
    S mus(const node_ptr &t) const { return t ? t->rev ? t->sum : t->mus : M::e(); }
    void update(node_ptr &t) {
        if (!t) return;
        t->sz = 1 + size(t->l) + size(t->r);
        t->sum = M::op(sum(t->l), M::op(t->x, sum(t->r)));
        t->mus = M::op(mus(t->r), M::op(t->x, mus(t->l)));
    }
    void push(node_ptr &t) {
        if (!t) return;
        if (t->rev) {
            swap(t->l, t->r);
            swap(t->sum, t->mus);
            if (t->l) t->l->rev ^= true;
            if (t->r) t->r->rev ^= true;
            t->rev = false;
        }
    }
    node_ptr merge(node_ptr &pl, node_ptr &pr) {
        push(pl);
        push(pr);
        if (!pl) return move(pr);
        if (!pr) return move(pl);
        if (pl->pri > pr->pri) {
            pl->r = merge(pl->r, pr);
            update(pl);
            return move(pl);
        } else {
            pr->l = merge(pl, pr->l);
            update(pr);
            return move(pr);
        }
    }
    node_ptr merge(node_ptr &pl, node_ptr &pm, node_ptr &pr) {
        auto p = merge(pl, pm);
        p = merge(p, pr);
        return move(p);
    }
    pair<node_ptr, node_ptr> split(node_ptr &t, int k) {
        node_ptr pl = nullptr, pr = nullptr;
        if (!t) return {move(pl), move(pr)};
        push(t);
        int ls = size(t->l);
        if (k <= ls) {
            tie(pl, t->l) = split(t->l, k);
            update(t);
            pr = move(t);
        } else {
            tie(t->r, pr) = split(t->r, k - ls - 1);
            update(t);
            pl = move(t);
        }
        return {move(pl), move(pr)};
    }
    tuple<node_ptr, node_ptr, node_ptr> split(node_ptr &t, int l, int r) {
        auto [plm, pr] = split(t, r);
        auto [pl, pm] = split(plm, l);
        return {move(pl), move(pm), move(pr)};
    }
};