#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename Abelian_Group>
struct weighted_dsu {
    using S = Abelian_Group::S;
    weighted_dsu(int _n) : n(_n), p(n, -1), d(n, Abelian_Group::e()) {}
    int leader(int u) {
        assert(0 <= u && u < n);
        if (p[u] < 0) return u;
        int r = leader(p[u]);
        d[u] = Abelian_Group::op(d[u], d[p[u]]);
        return p[u] = r;
    }
    S weight(int u) {
        assert(0 <= u && u < n);
        leader(u);
        return d[u];
    }
    bool same(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        return leader(u) == leader(v);
    }
    bool merge(int u, int v, S w) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        if (same(u, v)) {
            return diff(u, v) == w;
        }
        w = Abelian_Group::op(w, weight(u));
        w = Abelian_Group::op(w, Abelian_Group::inv(weight(v)));
        u = leader(u);
        v = leader(v);
        assert(u != v);
        if (p[u] > p[v]) {
            swap(u, v);
            w = Abelian_Group::inv(w);
        }
        p[u] += p[v];
        p[v] = u;
        d[v] = w;
        return true;
    }
    S diff(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        return Abelian_Group::op(Abelian_Group::inv(weight(u)), weight(v));
    }
    int size(int u) {
        assert(0 <= u && u < n);
        return -p[leader(u)];
    }
private:
    int n;
    vector<int> p;
    vector<S> d;
};
