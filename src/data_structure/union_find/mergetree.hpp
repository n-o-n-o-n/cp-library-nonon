#pragma once
#include <vector>
using namespace std;

template<typename Monoid>
struct merge_tree {
    using S = Monoid::S;
    merge_tree(int n) : p(n, -1), d(n, Monoid::e()) {}
    merge_tree(const vector<S> &v) : p(v.size(), -1), d(v) {}
    void set(int u, const S &x) { d[u] = x; }
    int leader(int u) const { return p[u] < 0 ? u : leader(p[u]); }
    bool same(int u, int v) const { return leader(u) == leader(v); }
    int size(int u) const { return -p[leader(u)]; }
    S get(int u) const { return d[leader(u)]; }
    void merge(int u, int v) {
        u = leader(u);
        v = leader(v);
        if (u == v) return;
        if (size(u) < size(v)) swap(u, v);
        p[u] += p[v];
        p[v] = u;
        d[u] = Monoid::op(d[u], d[v]);
        d[v] = Monoid::e();
    }
private:
    vector<int> p;
    vector<S> d;
};