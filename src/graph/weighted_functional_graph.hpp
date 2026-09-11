#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename Monoid, bool edge>
struct weighted_functional_graph {
    using M = Monoid;
    using S = typename M::S;
    weighted_functional_graph(int _n) : weighted_functional_graph(vector<int>(_n, -1), vector<S>(_n, M::e())) {}
    weighted_functional_graph(const vector<int> &a, const vector<S> &w) : n(a.size()), f(1, a), d(1, w) {}
    void add_edge(int u, int v, const S &w = M::e()) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(f[0][u] == -1);
        f[0][u] = v;
        if (edge) d[0][u] = w;
    }
    void set(int u, S x) {
        assert(!edge);
        assert(0 <= u && u < n);
        d[0][u] = x;
    }
    pair<int, S> steps(int u, long long k) {
        assert(0 <= u && u < n);
        doubling(k);
        S p = M::e();
        for (int i = 0; (1LL << i) <= k; i++) {
            if (k >> i & 1) {
                p = M::op(p, d[i][u]);
                u = f[i][u];
            }
        }
        if (!edge) p = M::op(p, d[0][u]);
        return make_pair(u, p);
    }
    template<typename C>
    pair<int, S> binary_search(int u, long long k, const C &check) {
        assert(0 <= u && u < n);
        assert(check(M::e()));
        doubling(k);
        int r = 0;
        while ((1LL << r) <= k) r++;
        S p = M::e();
        for (r-- ; r >= 0; r--) {
            S np = M::op(p, d[r][u]);
            if ((1LL << r) <= k && check(np)) {
                u = f[r][u];
                p = np;
                k -= 1LL << r;
            }
        }
        return make_pair(u, p);
    }
private:
    int n;
    vector<vector<int>> f;
    vector<vector<S>> d;
    void doubling(long long k) {
        while (1LL << int(f.size()) <= k) {
            vector<int> tf(n);
            vector<S> td(n);
            const vector<int> &g = f.back();
            const vector<S> &w = d.back();
            for (int j = 0; j < n; j++) {
                tf[j] = g[g[j]];
                td[j] = M::op(w[j], w[g[j]]);
            }
            f.push_back(tf);
            d.push_back(td);
        }
    }
};