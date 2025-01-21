#pragma once
#include <vector>
#include "../../data_structure/sparse_table/disjoint_sparse_table.hpp"
#include "hld_template.hpp"
using namespace std;

template<typename Monoid>
struct heavy_light_decomposition {
    using inner_S = typename Monoid::S;
    heavy_light_decomposition() = default;
    heavy_light_decomposition(int n, bool e, int r = 0) : g(n, e, r) {}
    void add_edge(int u, int v, const inner_S &w = Monoid::e()) {
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
    struct pair_Monoid {
        using S = pair<inner_S, inner_S>;
        static S op(const S &a, const S &b) {
            return make_pair(Monoid::op(a.first, b.first), Monoid::op(b.second, a.second));
        }
        static S e() {
            return make_pair(Monoid::e(), Monoid::e());
        }
    };
    hld_template<disjoint_sparse_table, pair_Monoid> g;
};