#pragma once
#include <cassert>
#include <vector>
#include "../sparse_table/sparse_table.hpp"
using namespace std;

// https://judge.yosupo.jp/submission/200540
// 小さい部分は愚直が速いらしい(?)
template<typename Monoid>
struct static_rmq {
    using M = Monoid;
    using S = typename M::S;
    static_rmq() = default;
    static_rmq(const vector<S> &_v) : n(_v.size()), v(_v), pref(_v), suf(_v) { build(); }
    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return M::e();
        r--;
        int bl = l >> log, br = r >> log;
        if (bl < br) {
            return M::op(M::op(pref[r], suf[l]), st.prod(bl + 1, br));
        }
        S p = M::e();
        for (int i = l; i <= r; i++) p = M::op(p, v[i]);
        return p;
    }
private:
    int n;
    static constexpr int log = 4, mask = 15;
    vector<S> v, pref, suf;
    sparse_table<M> st;
    void build() {
        for (int i = 1; i < n; i++) {
            if (i & mask) pref[i] = min(pref[i - 1], v[i]);
        }
        for (int i = n - 1; i > 0; i--) {
            if (i & mask) suf[i - 1] = min(suf[i], v[i - 1]);
        }
        st = sparse_table<M>([&]{
            vector<S> a(n >> log);
            for (int i = 0; i < (n >> log); i++) {
                a[i] = suf[i << log];
            }
            return a;
        }());
    }
};