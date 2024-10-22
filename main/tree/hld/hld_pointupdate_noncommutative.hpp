#pragma once
#include <cassert>
#include <vector>

#include "../../data_structure/segtree/segtree.hpp"
#include "hld_template.hpp"
using namespace std;

template<typename Monoid>
struct heavy_light_decomposition {
    using S = Monoid::S;
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
    typename inner_Monoid::S rev(const typename inner_Monoid::S &a) {
        return make_pair(a.second, a.first);
    }
    hld_template<inner_Monoid> g;
    segtree<inner_Monoid> d;
    bool built;
    void build(const vector<S> &v = {}) {
        if (built) return;
        vector<typename inner_Monoid::S> pv(v.size(), inner_Monoid::e());
        for (int i = 0; i < int(v.size()); i++) {
            pv[i] = make_pair(v[i], v[i]);
        }
        d = segtree<inner_Monoid>(g.rearrange(pv));
        built = true;
    }
};