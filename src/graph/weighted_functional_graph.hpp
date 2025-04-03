#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename Monoid>
struct weighted_functional_graph {
    using S = Monoid::S;
    weighted_functional_graph(int _n, bool e) : weighted_functional_graph(vector<int>(_n, -1), vector<S>(_n, Monoid::e()), e) {}
    weighted_functional_graph(const vector<int> &a, const vector<S> &w, bool e) : n(a.size()), f(1, a), d(1, w), edge(e) {}
    void add_edge(int u, int v, const S &w) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(f[0][u] == -1);
        f[0][u] = v;
        d[0][u] = w;
    }
    pair<int, S> steps(int u, long long k) {
        assert(0 <= u && u < n);
        if (!edge) k++;
        doubling(k);
        S p = Monoid::e();
        for (int i = 0; (1LL << i) <= k; i++) {
            if (k >> i & 1) {
                p = Monoid::op(p, d[i][u]);
                u = f[i][u];
            }
        }
        return make_pair(u, p);
    }
private:
    int n;
    vector<vector<int>> f;
    vector<vector<S>> d;
    bool edge;
    void doubling(long long k) {
        while (1LL << int(f.size()) <= k) {
            vector<int> tf(n);
            vector<S> td(n);
            const vector<int> &g = f.back();
            const vector<S> &w = d.back();
            for (int j = 0; j < n; j++) {
                tf[j] = g[g[j]];
                td[j] = Monoid::op(w[j], w[g[j]]);
            }
            f.push_back(tf);
            d.push_back(td);
        }
    }
};