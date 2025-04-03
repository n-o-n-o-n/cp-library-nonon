#pragma once
#include <vector>
#include "../../data_structure/segtree/lazysegtree.hpp"
#include "hld_template.hpp"
using namespace std;

template<typename ActMonoid>
struct heavy_light_decomposition {
    using inner_S = typename ActMonoid::S;
    using inner_F = typename ActMonoid::F;
    heavy_light_decomposition() = default;
    heavy_light_decomposition(int n, bool e, int r = 0) : g(n, e, r) {}
    void add_edge(int u, int v, const inner_S &w = ActMonoid::e()) {
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
    template<typename C>
    int binary_search(int u, int v, const C &check) {
        return g.binary_search(u, v, [&](const pair<inner_S, inner_S> &x) {
            return check(x.first);
        }, [&](const pair<inner_S, inner_S> &x) {
            return make_pair(x.second, x.first)
        });
    }
private:
    struct pair_ActMonoid {
        using S = pair<inner_S, inner_S>;
        static S op(const S &a, const S &b) {
            return make_pair(ActMonoid::op(a.first, b.first), ActMonoid::op(b.second, a.second));
        }
        static S e() {
            return make_pair(ActMonoid::e(), ActMonoid::e());
        }
        using F = inner_F;
        static F comp(const F &f, const F &g) {
            return ActMonoid::comp(f, g);
        }
        static F id() {
            return ActMonoid::id();
        }
        static S mapping(const F &f, const S &x) {
            return make_pair(ActMonoid::mapping(f, x.first), ActMonoid::mapping(f, x.second));
        }
    };
    hld_template<lazy_segtree, pair_ActMonoid> g;
};