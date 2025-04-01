#pragma once
#include <numeric>
#include <vector>
#include "../../misc/merge_and_unique.hpp"
#include "../segtree/lazysegtree.hpp"
using namespace std;

template<typename T>
struct ActMonoid {
    using S = pair<T, T>;
    static S op(const S &a, const S &b) {
        if (a.first == b.first) {
            return make_pair(a.first, a.second + b.second);
        }
        return min(a, b);
    }
    static constexpr S e() {
        return make_pair(numeric_limits<T>::max(), 0);
    }
    using F = T;
    static F comp(F f, F g) {
        return f + g;
    }
    static F id() {
        return 0;
    }
    static S mapping(F f, S x) {
        x.first += f;
        return x;
    }
};

template<typename T>
T area_of_union_of_rectangles(const vector<tuple<T, T, T, T>> &rectangles) {
    int n = rectangles.size();
    if (n == 0) return 0;
    vector<T> xs, ys;
    xs.reserve(2 * n);
    ys.reserve(2 * n);
    for (auto [l, d, r, u] : rectangles) {
        xs.emplace_back(l);
        xs.emplace_back(r);
        ys.emplace_back(d);
        ys.emplace_back(u);
    }
    xs = merge_and_unique(xs);
    ys = merge_and_unique(ys);
    int w = xs.size(), h = ys.size();
    vector<vector<tuple<int, int, int>>> range(w);
    for (auto [l, d, r, u] : rectangles) {
        int il = lower_bound(xs.begin(), xs.end(), l) - xs.begin();
        int ir = lower_bound(xs.begin(), xs.end(), r) - xs.begin();
        int id = lower_bound(ys.begin(), ys.end(), d) - ys.begin();
        int iu = lower_bound(ys.begin(), ys.end(), u) - ys.begin();
        range[il].emplace_back(id, iu, 1);
        range[ir].emplace_back(id, iu, -1);
    }
    lazy_segtree<ActMonoid<T>> seg(h - 1);
    for (int i = 0; i + 1 < h; i++) {
        seg.set(i, make_pair(0, ys[i + 1] - ys[i]));
    }
    T range_y = ys.back() - ys.front();
    T res = 0;
    for (int i = 0; i + 1 < w; i++) {
        for (auto [d, u, t] : range[i]) {
            seg.apply(d, u, t);
        }
        auto [val, cnt] = seg.all_prod();
        T x = xs[i + 1] - xs[i];
        T y = range_y - (val == 0 ? cnt : 0);
        res += x * y;
    }
    return res;
}