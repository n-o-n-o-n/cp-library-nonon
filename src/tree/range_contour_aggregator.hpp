#pragma once
#include <array>
#include <cassert>
#include <queue>
#include <vector>
using namespace std;

template<typename SegTree>
struct range_contour_aggregator {
    using M = typename SegTree::M;
    using S = typename M::S;
    range_contour_aggregator() = default;
    range_contour_aggregator(int _n) : n(_n), e(0), built(false), g(_n) {
        par = vector<int>(n, -1);
        seen = vector<bool>(n, false);
        d = vector<S>(n, M::e());
        dats = vector<vector<tuple<int, int, int>>>(n);
        seps = vector<array<vector<int>, 2>>(n);
        segs = vector<array<SegTree, 2>>(n);
        par.reserve(2 * n);
        if (n == 1) build();
    }
    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(!built);
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        if (++e == n - 1) build();
    }
    void set(int u, const S &x) {
        assert(0 <= u && u < n);
        assert(built);
        d[u] = x;
        int v = par[u];
        for (const auto &[i, c, _] : dats[u]) {
            segs[v][c].set(i, x);
            v = par[v];
        }
    }
    S get(int u) const {
        assert(0 <= u && u < n);
        assert(built);
        return d[u];
    }
    S prod(int u, int l, int r) const {
        assert(0 <= u && u < n);
        assert(0 <= l && l <= r && r <= n);
        S res = (l == 0 && 0 < r ? d[u] : M::e());
        res = M::op(res, inner_prod(u, 0, l - 1, r - 1));
        res = M::op(res, inner_prod(u, 1, l - 1, r - 1));
        int v = par[u];
        for (const auto &[_, c, dist] : dats[u]) {
            int tl = l - dist - 2, tr = r - dist - 2;
            if (v < n && tl <= -1 && -1 < tr) {
                res = M::op(res, d[v]);
            }
            res = M::op(res, inner_prod(v, c ^ 1, tl, tr));
            v = par[v];
        }
        return res;
    }
private:
    int n, e;
    bool built;
    vector<vector<int>> g;
    vector<int> par;
    vector<bool> seen;
    vector<S> d;
    vector<vector<tuple<int, int, int>>> dats;
    vector<array<vector<int>, 2>> seps;
    vector<array<SegTree, 2>> segs;
    void make_node(int p, int c, const vector<int> &roots, int sz) {
        vector<S> new_d(sz, M::e());
        auto &sep = seps[p][c];
        auto &seg = segs[p][c];
        sep.push_back(0);
        queue<tuple<int, int, int>> q;
        for (int r : roots) {
            q.emplace(r, -1, 0);
        }
        int dist = 0, cnt = 0;
        while (q.size()) {
            auto [u, pu, du] = q.front();
            q.pop();
            if (du == dist + 1) {
                sep.push_back(cnt);
                dist = du;
            }
            dats[u].emplace_back(cnt, c, du);
            new_d[cnt++] = d[u];
            for (int v : g[u]) {
                if (v != pu && !seen[v]) {
                    q.emplace(v, u, du + 1);
                }
            }
        }
        sep.push_back(cnt);
        seg = SegTree(new_d);
    }
    vector<int>&& merge(vector<int> &&a, vector<int> &&b) {
        if (a.size() > b.size()) swap(a, b);
        for (int e : a) {
            b.push_back(e);
        }
        return move(b);
    }
    void build() {
        vector<int> sub(n, 0), ctr(n, -1);
        vector<vector<int>> children(n);
        sub.reserve(2 * n);
        ctr.reserve(2 * n);
        children.reserve(2 * n);
        auto dfs = [&](const auto &dfs, int root, int sz) -> int {
            int c = -1;
            auto centroid = [&](auto centroid, int u, int p) -> void {
                sub[u] = 1;
                for (int v : g[u]) {
                    if (v != p && !seen[v]) {
                        centroid(centroid, v, u);
                        if (v == c) {
                            sub[u] = sz - sub[c];
                            break;
                        }
                        sub[u] += sub[v];
                    }
                }
                if (c < 0 && 2 * sub[u] > sz) c = u;
            };
            centroid(centroid, root, -1);
            seen[c] = true;
            for (int v : g[c]) {
                if (!seen[v]) {
                    int s = sub[v];
                    ctr[v] = dfs(dfs, v, s);
                    sub[v] = s;
                }
            }
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
            for (int v : g[c]) {
                if (!seen[v]) {
                    children[v] = {v};
                    q.emplace(sub[v], v);
                }
            }
            while (q.size() >= 2) {
                int u = q.top().second;
                q.pop();
                int v = q.top().second;
                q.pop();
                if (q.empty()) {
                    par[ctr[u]] = par[ctr[v]] = c;
                    make_node(c, 0, children[u], sub[u]);
                    make_node(c, 1, children[v], sub[v]);
                } else {
                    int w = sub.size();
                    sub.push_back(sub[u] + sub[v]);
                    ctr.push_back(w);
                    par.push_back(-1);
                    par[ctr[u]] = par[ctr[v]] = w;
                    seps.emplace_back();
                    segs.emplace_back();
                    make_node(w, 0, children[u], sub[u]);
                    make_node(w, 1, children[v], sub[v]);
                    children.push_back(merge(move(children[u]), move(children[v])));
                    children[u].clear();
                    children[u].shrink_to_fit();
                    children[v].clear();
                    children[v].shrink_to_fit();
                    q.emplace(sub[w], w);
                }
            }
            if (q.size()) {
                int u = q.top().second;
                q.pop();
                par[ctr[u]] = c;
                make_node(c, 0, children[u], sub[u]);
            }
            seen[c] = false;
            return c;
        };
        dfs(dfs, 0, n);
        built = true;
    }
    S inner_prod(int u, int c, int l, int r) const {
        l = max(l, 0);
        r = min(r, (int)seps[u][c].size() - 1);
        return l < r ? segs[u][c].prod(seps[u][c][l], seps[u][c][r]) : M::e();
    }
};