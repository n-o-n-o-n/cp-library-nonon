#pragma once
#include <vector>
#include "../../data_structure/segtree/lazysegtree.hpp"
#include "hld_template.hpp"
using namespace std;

template<typename OpMonoid>
struct heavy_light_decomposition {
    using S = OpMonoid::S;
    using F = OpMonoid::F;
    heavy_light_decomposition() = default;
    heavy_light_decomposition(int n, bool e, int r = 0) : g(n, e, r) {}
    void add_edge(int u, int v, const S &w = OpMonoid::e()) {
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
    void apply(int u, int v, const F &f) {
        g.apply(u, v, f);
    }
    void subtree_apply(int u, const F &f) {
        g.subtree_apply(u, f);
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
    hld_template<lazy_segtree, OpMonoid> g;
};