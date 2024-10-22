#pragma once
#include <cassert>
#include <vector>

#include "../../data_structure/segtree/lazysegtree.hpp"
#include "hld_template.hpp"

using namespace std;
template<typename Monoid, typename Operator, auto mapping>
struct heavy_light_decomposition {
    using S = typename Monoid::S;
    using F = typename Operator::F;
    heavy_light_decomposition(int n, int e, int r = 0) : g(n, e, r), d(n), built(false) {}
    void add_edge(int u, int v, const S &w = Monoid::e()) {
        g.add_edge(u, v, make_pair(w, w));
    }
    void set(int u, const S &w) {
        build();
        d.set(g.idx(u), make_pair(w, w));
    }
    void set(int u, int v, const S &w) {
        build();
        d.set(g.idx(u, v), make_pair(w, w));
    }
    void set(const vector<S> &v) {
        build(v);
    }
    void apply(int u, int v, const F &f) {
        for (const auto &[l, r, _] : g.path_decompose(u, v)) {
            d.apply(l, r, f);
        }
    }
    S get(int u) {
        build();
        return d.get(g.idx(u)).first;
    }
    S get(int u, int v) {
        build();
        return d.get(g.idx(u, v)).first;
    }
    S prod(int u, int v) {
        build();
        typename inner_Monoid::S pl = inner_Monoid::e(), pr = inner_Monoid::e();
        bool flip = false;
        for (const auto &[l, r, f] : g.path_decompose(u, v)) {
            if (f) {
                flip = !flip;
                swap(pl ,pr);
            }
            pr = inner_Monoid::op(d.prod(l, r), pr);
        }
        pr = inner_Monoid::op(rev(pl), pr);
        return (flip ? pr.second : pr.first);
    }
private:
    struct inner_Monoid {
        using S = pair<typename Monoid::S, typename Monoid::S>;
        static S op(const S &a, const S &b) {
            return make_pair(Monoid::op(a.first, b.first), Monoid::op(b.second, a.second));
        }
        static S e() { return make_pair(Monoid::e(), Monoid::e()); }
    };
    struct inner_Operator {
        using F = typename Operator::F;
        static F comp(const F &f, const F &g) {
            return Operator::comp(f, g);
        }
        static F id() { return Operator::id(); }
    };
    typename inner_Monoid::S rev(const typename inner_Monoid::S &a) {
        return make_pair(a.second, a.first);
    }
    hld_template<inner_Monoid> g;
    lazy_segtree<inner_Monoid, inner_Operator, [](const typename inner_Operator::F &f, const typename inner_Monoid::S &x) -> typename inner_Monoid::S {
        return make_pair(mapping(f, x.first), mapping(f, x.second));
    }> d;
    bool built;
    void build(const vector<S> &v = {}) {
        if (built) return;
        vector<typename inner_Monoid::S> pv(v.size(), inner_Monoid::e());
        for (int i = 0; i < int(v.size()); i++) {
            pv[i] = make_pair(v[i], v[i]);
        }
        d.set(g.rearrange(pv));
        built = true;
    }
};