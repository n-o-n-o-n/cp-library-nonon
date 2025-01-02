#pragma once
#include <vector>
#include "../../data_structure/disjoint_sparse_table.hpp"
#include "hld_template.hpp"
using namespace std;

template<typename Monoid>
struct heavy_light_decomposition {
    using S = Monoid::S;
    heavy_light_decomposition() = default;
    heavy_light_decomposition(int n, bool e, int r = 0) : g(n, e, r) {}
    void add_edge(int u, int v, const S &w = Monoid::e()) {
        g.add_edge(u, v, w);
    }
    int lca(int u, int v) {
        return g.lca(u, v);
    }
    void set(int u, const S &w) {
        g.set(u, w);
    }
    void set(int u, int v, const S &w) {
        g.set(u, v, w);
    }
    S get(int u) {
        return g.get(u);
    }
    S get(int u, int v) {
        return g.get(u, v);
    }
    S prod(int u, int v) {
        return g.prod(u, v, [&](const S &x) {
            return x;
        });
    }
    S subtree_prod(int u) {
        return g.subtree_prod(u);
    }
private:
    hld_template<disjoint_sparse_table, Monoid> g;
};