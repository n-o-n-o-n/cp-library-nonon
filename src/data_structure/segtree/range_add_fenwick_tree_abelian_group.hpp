#pragma once
#include "fenwick_tree_abelian_group.hpp"

template<typename Abelian_Group>
struct range_add_fenwick_tree {
    using M = Abelian_Group;
    using S = typename M::S;
    range_add_fenwick_tree() = default;
    range_add_fenwick_tree(int n) : fw1(n + 1), fw2(n + 1) {}
    void add(int p, const S &x) {
        add(p, p + 1, x);
    }
    void add(int l, int r, const S &x) {
        fw1.add(l, M::inv(M::pow(x, l)));
        fw1.add(r, M::pow(x, r));
        fw2.add(l, x);
        fw2.add(r, M::inv(x));
    }
    S prod(int l, int r) const {
        return M::op(prod(r), M::inv(prod(l)));
    }
private:
    fenwick_tree<Abelian_Group> fw1, fw2;
    S prod(int p) const {
        S res1 = fw1.prod(0, p);
        S res2 = fw2.prod(0, p);
        return M::op(res1, M::pow(res2, p));
    }
};