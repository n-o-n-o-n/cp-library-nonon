#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
#include "../data_structure/segtree/segtree.hpp"

template<typename Monoid, typename T = int>
struct triangular_transition {
    using S = typename Monoid::S;
    triangular_transition(int _n = 0) : n(_n) {
        ts.reserve(n);
        xs.reserve(n);
    }
    void add_point(T t, T x) {
        ts.emplace_back(t);
        xs.emplace_back(x);
    }
    template<typename L>
    vector<S> run(const L &f, bool variable_start = false) {
        if (variable_start) {
            T x_max = 0;
            for (auto x : xs) x_max = max(x_max, abs(x));
            for (auto &t : ts) t += x_max;
        }
        n = ts.size();
        vector<T> us(n), vs(n);
        vector<int> ord(n);
        for (int i = 0; i < n; i++) {
            us[i] = ts[i] - xs[i];
            vs[i] = ts[i] + xs[i]; 
            ord[i] = i;
        }
        sort(ord.begin(), ord.end(), [&](int i, int j) {
            return us[i] == us[j] ? vs[i] < vs[j] : us[i] < us[j];
        });
        vector<T> b = vs;
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        vector<S> dp(n, Monoid::e());
        segtree<Monoid> seg(b.size() + 1);
        seg.set(0, f(-1, Monoid::e()));
        for (int i : ord) {
            T u = us[i], v = vs[i];
            if (u < 0 || v < 0) continue;
            int j = lower_bound(b.begin(), b.end(), v) - b.begin();
            dp[i] = f(i, seg.prod(0, j + 1));
            seg.set(j, dp[i]);
        }
        return dp;
    }
private:
    int n;
    vector<T> ts, xs;
};