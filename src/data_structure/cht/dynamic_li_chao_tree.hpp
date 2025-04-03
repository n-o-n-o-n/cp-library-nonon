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
    li_chao_tree(T _x_min, T _x_max) : x_min(_x_min), x_max(_x_max), root(make_unique<node>()) {
        n = x_max - x_min;
        log = 1;
        while ((T(1) << log) < n) log++;
        sz = T(1) << log;
    }
    static constexpr T max() { return inf; }
    void add_line(T a, T b) {
        update(root, line(a, b), 0, sz);
    }
    void add_segment(T xl, T xr, T a, T b) {
        assert(x_min <= xl && xl <= xr && xr <= x_max);
        add_segment(root, line(a, b), 0, sz, xl - x_min, xr - x_min);
    }
    T get_min(T x) {
        assert(x_min <= x && x <= x_max);
        return get_min(root, 0, sz, x - x_min);
    }
private:
    constexpr static T inf = numeric_limits<T>::max();
    struct line {
        T a, b;
        line(T _a, T _b) : a(_a), b(_b) {}
        T operator()(T x) const {
            return a * x + b;
        }
    };
    static constexpr line e() {
        return line(0, inf);
    }
    struct node {
        line f;
        unique_ptr<node> l, r;
        node() : node(e()) {}
        node(const line &_f) : f(_f), l(nullptr), r(nullptr) {}
    };
    T x_min, x_max, n, sz;
    int log;
    unique_ptr<node> root;
    void update(unique_ptr<node> &t, line f, T l, T r) {
        auto &g = t->f;
        T m = (l + r) / 2;
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
            if (!t->l) t->l = make_unique<node>();
            update(t->l, f, l, m);
        } else {
            if (!t->r) t->r = make_unique<node>();
            update(t->r, f, m, r);
        }
    }
    void add_segment(unique_ptr<node> &t, const line &f, T l, T r, T xl, T xr) {
        if (r <= xl || xr <= l) return;
        if (xl <= l && r <= xr) {
            update(t, f, l, r);
            return;
        }
        if (l + 1 == r) return;
        T m = (l + r) / 2;
        if (!t->l) t->l = make_unique<node>();
        if (!t->r) t->r = make_unique<node>();
        add_segment(t->l, f, l, m, xl, xr);
        add_segment(t->r, f, m, r, xl, xr);
    }
    T get_min(unique_ptr<node> &t, T l, T r, T x) {
        if (!t) return inf;
        T val = t->f(x + x_min);
        if (l + 1 == r) return val;
        T m = (l + r) / 2;
        return min(val, x < m ? get_min(t->l, l, m, x) : get_min(t->r, m, r, x));
    }
};