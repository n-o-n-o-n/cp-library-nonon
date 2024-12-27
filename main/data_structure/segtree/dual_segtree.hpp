#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename S, typename Operator, auto mapping>
struct dual_segtree {
    using F = Operator::F;
    dual_segtree() : dual_segtree(0) {}
    dual_segtree(int _n) : dual_segtree(vector<S>(_n)) {}
    dual_segtree(const vector<S> &v) { init(v); }
    void set(int p, const S &x) {
        assert(0 <= p && p < n);
        p += sz;
        d[p] = x;
    }
    void apply(int l, int r, const F &f) {
        assert(0 <= l && l <= r && r <= n);
        l += sz, r += sz;
        inner_push(l);
        inner_push(r - 1);
        while (l < r) {
            if (l & 1) all_apply(l++, f);
            if (r & 1) all_apply(--r, f);
            l >>= 1;
            r >>= 1;
        }
    }
    S get(int p) {
        assert(0 <= p && p < n);
        inner_push(p + sz);
        return d[p];
    }
private:
    int n, log, sz;
    vector<S> d;
    vector<F> lz;
    void init(const vector<S> &v) {
        n = v.size();
        log = 1;
        while ((1 << log) < n) log++;
        sz = 1 << log;
        d = v;
        lz = vector<F>(sz, Operator::id());
    }
    void all_apply(int p, const F &f) {
        if (p < sz) {
            lz[p] = Operator::comp(f, lz[p]);
        } else {
            d[p - sz] = mapping(f, d[p - sz]);
        }
    }
    void push(int p) {
        all_apply(2 * p, lz[p]);
        all_apply(2 * p + 1, lz[p]);
        lz[p] = Operator::id();
    }
    void inner_push(int p) {
        for (int i = log; i >= 1; i--) push(p >> i);
    }
};