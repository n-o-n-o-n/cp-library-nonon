#pragma once
#include <vector>
using namespace std;

template<typename Monoid>
struct rerooting_dp {
    using S = Monoid::S;
    rerooting_dp(int n) : g(n), pos(0) {}
    void add_edge(int u, int v) {
        g[u].emplace_back(v, pos);
        g[v].emplace_back(u, pos);
        pos++;
    }
    template<typename L1, typename L2>
    vector<S> run(const L1 &apply_vertex, const L2 &apply_edge) {
        vector<S> memo(g.size(), Monoid::e()), dp(g.size(), Monoid::e());
        auto dfs = [&](const auto &dfs, int u, int p) -> void {
            for (const auto &[v, i] : g[u]) {
                if (v != p) {
                    dfs(dfs, v, u);
                    memo[u] = Monoid::op(memo[u], apply_edge(memo[v], i));
                }
            }
            memo[u] = apply_vertex(memo[u], u);
        };
        auto reroot = [&](const auto &reroot, int u, int p, const S &x) -> void {
            vector<S> d = {x};
            for (const auto &[v, i] : g[u]) {
                if (v != p) {
                    d.push_back(apply_edge(memo[v], i));
                }
            }
            int n = d.size();
            vector<S> pre(n + 1, Monoid::e()), suf(n + 1, Monoid::e());
            for (int i = 0; i < n; i++) {
                pre[i + 1] = Monoid::op(pre[i], d[i]);
            }
            for (int i = n; i > 0; i--) {
                suf[i - 1] = Monoid::op(suf[i], d[i - 1]);
            }
            dp[u] = apply_vertex(pre[n], u);
            int k = 1;
            for (const auto &[v, i] : g[u]) {
                if (v != p) {
                    S y = Monoid::op(pre[k], suf[k + 1]);
                    reroot(reroot, v, u, apply_edge(apply_vertex(y, u), i));
                    k++;
                }
            }
        };
        dfs(dfs, 0, -1);
        reroot(reroot, 0, -1, Monoid::e());
        return dp;
    }
private:
    vector<vector<pair<int, int>>> g;
    int pos;
};