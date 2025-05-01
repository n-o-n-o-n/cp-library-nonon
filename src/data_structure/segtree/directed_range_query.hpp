#pragma once
#include <cassert>
#include <ranges>
#include <vector>
using namespace std;

template<typename SegTree>
struct directed_range_query {
    using M = typename SegTree::M;
    using S = typename M::S;
    directed_range_query() = default;
    directed_range_query(int _n) : n(_n), seg(_n), ges(_n) {}
    directed_range_query(const vector<S> &v) : n(v.size()), seg(v), ges(vector<S>(v.rbegin(), v.rend())) {}
    void set(int p, const S &x) {
        assert(0 <= p && p < n);
        seg.set(p, x);
        ges.set(n - 1 - p, x);
    }
    template<typename F>
    void apply(int l, int r, const F &f) {
        assert(0 <= l && l <= r && r <= n);
        seg.apply(l, r, f);
        ges.apply(n - r, n - l, f);
    }
    S get(int p) {
        assert(0 <= p && p < n);
        return seg.get(p);
    }
    S prod(int l, int r) {
        return l < r ? seg.prod(l, r) : ges.prod(n - l, n - r);
    }
    template<typename C>
    int max_right(int l, bool rev, const C &check) {
        return rev ? n - ges.min_left(n - l, check) : seg.max_right(l, check);
    }
    template<typename C>
    int min_left(int r, bool rev, const C &check) {
        return rev ? n - ges.max_right(n - r, check) : seg.min_left(r, check);
    }
private:
    int n;
    SegTree seg, ges;
};