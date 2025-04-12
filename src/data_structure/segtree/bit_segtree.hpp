#pragma once
#include <cassert>
#include <numeric>
#include <vector>
#include "fenwick_tree.hpp"
using namespace std;

struct bit_segtree {
    struct M {
        using S = int;
        static S op(S a, S b) {
            return a + b;
        }
        static S e() {
            return 0;
        }
    };
    bit_segtree() : bit_segtree(0) {}
    bit_segtree(int _n) : n(_n) {
    }
    template<typename T>
    bit_segtree(const vector<T> &v) : n(v.size()) {
        sz = (n + 63) / 64;
        d = vector<unsigned long long>(sz, 0);
        for (int p = 0; p < n; p++) {
            if (v[p]) {
                int i = p >> 6, j = p & 63;
                d[i] |= 1ULL << j;
            }
        }
        fw = fenwick_tree<int>([&]{
            vector<int> ppc(sz);
            for (int i = 0; i < sz; i++) {
                ppc[i] = __builtin_popcountll(d[i]);
            }
            return ppc;
        }());
    }
    void set(int p) {
        assert(0 <= p && p < n);
        int i = p >> 6, j = p & 63;
        if ((d[i] >> j & 1) == 0) {
            d[i] |= 1ULL << j;
            update(i);
        }
    }
    void reset(int p) {
        assert(0 <= p && p < n);
        int i = p >> 6, j = p & 63;
        if (d[i] >> j & 1) {
            d[i] &= ~(1uLL << j);
            update(i);
        }
    }
    void set(int p, bool x) {
        assert(0 <= p && p < n);
        x ? set(p) : reset(p);
    }
    void flip(int p) {
        assert(0 <= p && p < n);
        int i = p >> 6, j = p & 63;
        d[i] ^= 1ULL << j;
        update(i);
    }
    bool test(int p) const {
        assert(0 <= p && p < n);
        return d[p >> 6] >> (p & 63) & 1;
    }
    bool get(int p) const {
        return test(p);
    }
    int count(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return 0;
        int il = l >> 6, jl = l & 63;
        int ir = r >> 6, jr = r & 63;
        if (il == ir) {
            return __builtin_popcountll((d[il] >> jl) & ((1ULL << (jr - jl)) - 1));
        }
        int res = fw.sum(il, ir);
        res -= __builtin_popcountll(d[il] & ((1ULL << jl) - 1));
        res += __builtin_popcountll(d[ir] & ((1ULL << jr) - 1));
        return res;
    }
    int prod(int l, int r) const {
        return count(l, r);
    }
    bool all(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return count(l, r) == r - l;
    }
    bool any(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return count(l, r) > 0;
    }
    bool none(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return count(l, r) == 0;
    }
private:
    int n, sz;
    vector<unsigned long long> d;
    fenwick_tree<int> fw;
    void update(int p) {
        fw.update(p, __builtin_popcountll(d[p]));
    }
};