#pragma once
#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>
using namespace std;

template<typename T>
struct li_chao_tree {
    li_chao_tree() : built(false) {}
    li_chao_tree(const vector<T> &_xs) : xs(_xs), built(false) {
        build();
    }
    void add_point(T x) {
        xs.push_back(x);
    }
    void add_line(T a, T b) {
        build();
        update(line(a, b), 1, 0, sz);
    }
    void add_segmrnt(T xl, T xr, T a, T b) {
        build();
        int l = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();
        int r = lower_bound(xs.begin(), xs.end(), xr) - xs.begin();
        line f(a, b);
        int len = 1, ll = l, rr = r;
        l += sz, r += sz;
        while (l < r) {
            if (l & 1) {
                update(f, l++, ll, ll + len);
                ll += len;
            }
            if (r & 1) {
                rr -= len;
                update(f, --r, rr, rr + len);
            }
            l >>= 1;
            r >>= 1;
            len <<= 1;
        }
    }
    T get_min(T x) {
        build();
        int p = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        assert(xs[p] == x);
        p += sz;
        T res = inf;
        for (int i = 0; i <= log; i++) {
            res = min(res, d[p >> i](x));
        }
        return res;
    }
private:
    struct line {
        T a, b;
        line(T _a, T _b) : a(_a), b(_b) {}
        T operator()(T x) const {
            return a * x + b;
        }
    };
    int n, log, sz;
    vector<T> xs;
    vector<line> d;
    bool built;
    static constexpr T inf = numeric_limits<T>::max();
    static constexpr line e() {
        return line(0, inf);
    }
    void build() {
        if (built) return;
        if (xs.empty()) xs.push_back(0);
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        n = xs.size();
        log = 1;
        while ((1 << log) < n) log++;
        sz = 1 << log;
        d = vector<line>(2 * sz, e());
        while ((int)xs.size() <= sz) xs.push_back(xs.back() + 1);
        built = true;
    }
    void update(line f, int p, int l, int r) {
        auto &g = d[p];
        int m = (l + r) / 2;
        bool pl = f(xs[l]) < g(xs[l]);
        bool pm = f(xs[m]) < g(xs[m]);
        bool pr = f(xs[r]) < g(xs[r]);
        if (!pl && !pr) return;
        if (pl && pr) {
            g = f;
            return;
        }
        if (pm) swap(f, g);
        if (l + 1 == r) return;
        if (pl ^ pm) {
            update(f, 2 * p, l, m);
        } else {
            update(f, 2 * p + 1, m, r);
        }
    }
};