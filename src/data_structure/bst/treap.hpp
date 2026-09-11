#pragma once
#include <cassert>
#include <vector>
#include "../../random/xor_shift.hpp"
using namespace std;

template<typename T>
struct treap {
    treap() : eng(19835715), root(-1) {}
    treap(const vector<T> &v) : eng(v.size() + 1) {
        d.reserve(v.size());
        root = build(v, 0, v.size());
    }
    void insert(int p, const T &x) {
        assert(0 <= p && p <= size(root));
        root = insert(root, p, x);
    }
    void erase(int p) { erase(p, p + 1); }
    void erase(int l, int r) {
        assert(0 <= l && l <= r && r <= size(root));
        auto [ll, _, rr] = split(root, l, r);
        root = merge(ll, rr);
    }
    void reverse(int l, int r) {
        assert(0 <= l && l <= r && r <= size(root));
        root = reverse(root, l, r);
    }
    void set(int p, const T &x) {
        assert(0 <= p && p < size(root));
        auto [l, m, r] = split(root, p, p + 1);
        d[m].x = x;
        update(m); 
        root = merge(l, m, r);
    }
    // a <- (a[k], a[k+1], ..., a[n-1], a[0], ..., a[k-1])
    void shift(int k) {
        int n = size(root);
        if (n == 0) return;
        k %= n;
        if (k < 0) k += n;
        auto [l, r] = split(root, k);
        root = merge(r, l);
    }
    T get(int p) {
        assert(0 <= p && p < size(root));
        auto [l, m, r] = split(root, p, p + 1);
        T res = d[m].x;
        root = merge(l, m, r);
        return res;
    }
private:
    xor_shift<int> eng;
    struct node {
        int l,  r;
        T x;
        int sz;
        bool rev;
        unsigned int pri;
        node(const T &_x, unsigned int _pri) : l(-1), r(-1), x(_x), sz(1), rev(false), pri(_pri) {}
    };
    int root;
    vector<node> d;
    int make_node(const T &x) {
        int res = d.size();
        d.emplace_back(x, eng());
        return res;
    }
    int build(const vector<T> &v, int l, int r) {
        if (l == r) return -1;
        if (l + 1 == r) return make_node(v[l]);
        int m = (l + r) / 2;
        return merge(build(v, l, m), build(v, m, r));
    }
    int size(int p) { return 0 <= p && p < ssize(d) ? d[p].sz : 0; }
    void update(int p) {
        if (p < 0 || p >= ssize(d)) return;
        d[p].sz = size(d[p].l) + 1 + size(d[p].r);
    }
    void push(int p) {
        if (p < 0 || p >= ssize(d)) return;
        if (d[p].rev) {
            swap(d[p].l, d[p].r);
            if (d[p].l != -1) d[d[p].l].rev ^= true;
            if (d[p].r != -1) d[d[p].r].rev ^= true;
            d[p].rev = false;
        }
    }
    int merge(int p, int q) {
        if (p == -1) return q;
        if (q == -1) return p;
        push(p);
        push(q);
        if (d[p].pri > d[q].pri) {
            d[p].r = merge(d[p].r, q);
            update(p);
            return p;
        } else {
            d[q].l = merge(p, d[q].l);
            update(q);
            return q;
        }
    }
    int merge(int p, int q, int r) {
        return merge(p, merge(q, r));
    }
    pair<int, int> split(int p, int k) {
        if (p == -1) return {-1, -1};
        push(p);
        if (k <= size(d[p].l)) {
            auto [ll, rr] = split(d[p].l, k);
            d[p].l = rr;
            update(p);
            return {ll, p};
        } else {
            auto [ll, rr] = split(d[p].r, k - size(d[p].l) - 1);
            d[p].r = ll;
            update(p);
            return {p, rr};
        }
    }
    tuple<int, int, int> split(int p, int l, int r) {
        auto [m, rr] = split(p, r);
        auto [ll, mm] = split(m, l);
        return {ll, mm, rr};
    }
    int insert(int p, int k, const T &x) {
        auto [l, r] = split(p, k);
        return merge(l, make_node(x), r);
    }
    int reverse(int root, int l, int r) {
        auto [pl, pm, pr] = split(root, l, r);
        if (pm != -1) d[pm].rev ^= true;
        return merge(pl, pm, pr);
    }
};