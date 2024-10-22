#pragma once
#include <cassert>
#include <vector>

#include "../../data_structure/disjoint_sparse_table.hpp"
#include "hld_template.hpp"
using namespace std;

template<typename Monoid>
struct heavy_light_decomposition {
    using S = typename Monoid::S;
    heavy_light_decomposition(int _n, int _e, int _r = 0) : n(_n), g(_n, _e, _r), d(_n), built(false) {}
    void add_edge(int u, int v, const S &w = Monoid::e()) {
        g.add_edge(u, v, w);
    }
    void set(int u, const S &w) {
        build();
        d.set(g.idx(u), w);
    }
    void set(int u, int v, const S &w) {
        build();
        d.set(g.idx(u, v), w);
    }
    void set(const vector<S> &v) {
        build(v);
    }
    S get(int u) {
        build();
        return d.get(g.idx(u));
    }
    S get(int u, int v) {
        build();
        return d.get(g.idx(u, v));
    }
    S prod(int u, int v) {
        build();
        S res = Monoid::e();
        for (const auto &[l, r, f] : g.path_decompose(u, v)) {
            res = Monoid::op(res, d.prod(l, r));
        }
        return res;
    }
private:
    int n;
    hld_template<Monoid> g;
    disjoint_sparse_table<Monoid> d;
    bool built;
    void build(const vector<S> &v = {}) {
        if (built) return;
        d = disjoint_sparse_table<Monoid>(g.rearrange(v));
        built = true;
    }
};