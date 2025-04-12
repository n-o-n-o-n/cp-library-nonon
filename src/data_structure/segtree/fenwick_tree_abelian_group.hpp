#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename Abelian_Group>
struct fenwick_tree {
    using M = Abelian_Group;
    using S = typename M::S;
    fenwick_tree() = default;
    fenwick_tree(int _n) : fenwick_tree(vector<S>(_n, M::e())) {}
    fenwick_tree(const vector<S> &_v) : n(_v.size()) {
        d = vector<S>(n, M::e());
        v = vector<S>(n, M::e());
        for (int i = 1; i <= n; i++) {
            v[i - 1] = _v[i - 1];
            d[i - 1] += v[i - 1];
            int j = i + (i & -i);
            if (j <= n) d[j - 1] += d[i - 1];
        }
    }
    void add(int p, S x) {
        assert(0 <= p && p < n);
        v[p] = M::op(v[p], x);
        for (p++; p <= n; p += p & -p) {
            d[p - 1] = M::op(d[p - 1], x);
        }
    }
    void set(int p, S x) {
        assert(0 <= p && p < n);
        add(p, M::op(x, M::inv(v[p])));
    }
    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return prod(r) - prod(l);
    }
private:
    int n;
    vector<S> d, v;
    S prod(int p) const {
        S res = M::e();
        for (; p > 0; p -= p & -p) {
            res = M::op(res, d[p - 1]);
        }
        return res;
    }
};