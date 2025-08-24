#pragma once
#include <algorithm>
#include <cassert>
#include <limits>
#include <memory>
#include <vector>
using namespace std;

template<typename T>
struct li_chao_tree {
    li_chao_tree() : li_chao_tree(-inf / 4, inf / 4) {}
    li_chao_tree(T _x_min, T _x_max, int q = 0) : x_min(_x_min), x_max(_x_max) {
        n = x_max - x_min;
        log = 1;
        while ((T(1) << log) < n) log++;
        sz = T(1) << log;
        d.reserve(q * log);
        new_node();
    }
    static constexpr T max() {
        return inf;
    }
    // add y = ax + b for x in (-inf, inf)
    void add_line(T a, T b) {
        update(0, line(a, b), 0, sz);
    }
    // add y = ax + b for x in [l, r)
    void add_segment(T xl, T xr, T a, T b) {
        assert(x_min <= xl && xl <= xr && xr <= x_max);
        add_segment(0, line(a, b), 0, sz, xl - x_min, xr - x_min);
    }
    T get_min(T x) {
        assert(x_min <= x && x <= x_max);
        return get_min(0, 0, sz, x - x_min);
    }
private:
    struct line {
        T a, b;
        line(T _a, T _b) : a(_a), b(_b) {}
        T operator()(T x) const {
            return a * x + b;
        }
    };
    struct node {
        line f;
        int l, r;
        node() : node(e()) {}
        node(const line &_f) : f(_f), l(-1), r(-1) {}
    };
    static constexpr T inf = numeric_limits<T>::max();
    static constexpr line e() {
        return line(0, inf);
    }
    T x_min, x_max, n, sz;
    int log;
    vector<node> d;
    int new_node() {
        int res = d.size();
        d.emplace_back(node());
        return res;
    }
    void update(int p, line f, T l, T r) {
        auto &g = d[p].f;
        T m = midpoint(l, r);
        T xl = l + x_min, xm = m + x_min, xr = r + x_min;
        bool pl = f(xl) < g(xl);
        bool pm = f(xm) < g(xm);
        bool pr = f(xr) < g(xr);
        if (!pl && !pr) return;
        if (pl && pr) {
            g = f;
            return;
        }
        if (pm) swap(f, g);
        if (l + 1 == r) return;
        if (pl ^ pm) {
            if (d[p].l == -1) d[p].l = new_node();
            update(d[p].l, f, l, m);
        } else {
            if (d[p].r == -1) d[p].r = new_node();
            update(d[p].r, f, m, r);
        }
    }
    void add_segment(int p, const line &f, T l, T r, T xl, T xr) {
        if (r <= xl || xr <= l) return;
        if (xl <= l && r <= xr) {
            update(p, f, l, r);
            return;
        }
        if (l + 1 == r) return;
        T m = midpoint(l, r);
        if (l < xr && xl < m) {
            if (d[p].l == -1) d[p].l = new_node();
            add_segment(d[p].l, f, l, m, xl, xr);
        }
        if (m < xr && xl < r) {
            if (d[p].r == -1) d[p].r = new_node();
            add_segment(d[p].r, f, m, r, xl, xr);
        }
    }
    T get_min(int p, T l, T r, T x) {
        if (p == -1) return inf;
        auto &t = d[p];
        T val = t.f(x + x_min);
        if (l + 1 == r) return val;
        T m = midpoint(l, r);
        return min(val, x < m ? get_min(t.l, l, m, x) : get_min(t.r, m, r, x));
    }
};