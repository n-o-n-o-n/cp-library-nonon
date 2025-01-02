#pragma once
#include <vector>
#include "../../data_structure/segtree/lazysegtree.hpp"
#include "hld_template.hpp"
using namespace std;

template<typename OpMonoid>
struct heavy_light_decomposition {
    using inner_S = typename OpMonoid::S;
    using inner_F = typename OpMonoid::F;
    heavy_light_decomposition() = default;
    heavy_light_decomposition(int n, bool e, int r = 0) : g(n, e, r) {}
    void add_edge(int u, int v, const inner_S &w = OpMonoid::e()) {
        g.add_edge(u, v, make_pair(w, w));
    }
    int lca(int u, int v) {
        return g.lca(u, v);
    }
    void set(int u, const inner_S &w) {
        g.set(u, make_pair(w, w));
    }
    void set(int u, int v, const inner_S &w) {
        g.set(u, v, make_pair(w, w));
    }
    void apply(int u, int v, const inner_F &f) {
        g.apply(u, v, f);
    }
    void subtree_apply(int u, const inner_F &f) {
        g.subtree_apply(u, f);
    }
    inner_S get(int u) {
        return g.get(u).first;
    }
    inner_S get(int u, int v) {
        return g.get(u, v).first;
    }
    inner_S prod(int u, int v) {
        return g.prod(u, v, [&](const pair<inner_S, inner_S> &x) {
            return make_pair(x.second, x.first);
        }).first;
    }
private:
    struct pair_OpMonoid {
        using S = pair<inner_S, inner_S>;
        static S op(const S &a, const S &b) {
            return make_pair(OpMonoid::op(a.first, b.first), OpMonoid::op(b.second, a.second));
        }
        static S e() {
            return make_pair(OpMonoid::e(), OpMonoid::e());
        }
        using F = inner_F;
        static F comp(const F &f, const F &g) {
            return OpMonoid::comp(f, g);
        }
        static F id() {
            return OpMonoid::id();
        }
        static S mapping(const F &f, const S &x) {
            return make_pair(OpMonoid::mapping(f, x.first), OpMonoid::mapping(f, x.second));
        }
    };
    hld_template<lazy_segtree, pair_OpMonoid> g;
};