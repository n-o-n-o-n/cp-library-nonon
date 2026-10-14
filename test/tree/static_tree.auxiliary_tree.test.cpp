#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"


#include "../../src/tree/static_tree.hpp"
#include "../../src/modint/modint.hpp"

using mint = modint<998244353>;

// https://atcoder.jp/contests/abc340/tasks/abc340_g
namespace AC {

using ll = long long;

bool chmin(auto &a, auto b) { return a > b ? a = b, true : false; }
bool chmax(auto &a, auto b) { return a < b ? a = b, true : false; }

template<typename Monoid>
struct sparse_table {
    using M = Monoid;
    using S = typename M::S;
    sparse_table() = default;
    sparse_table(const vector<S> &v) : n(v.size()), b(0), d(1, v) { build(); }
    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <=n);
        if (l == r) return M::e();
        int i = bit_width(unsigned(r - l)) - 1;
        return M::op(d[i][l], d[i][r - (1 << i)]);
    }
private:
    int n, b, e;
    vector<vector<S>> d;
    void build() {
        b = bit_width(unsigned(n));
        d.resize(b, vector<S>(n, M::e()));
        for (int i = 1; i < b; i++) {
            for (int j = 0; j + (1 << i) <=n; j++) {
                d[i][j] = M::op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
};

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

struct static_tree {
    static_tree() = default;
    static_tree(int _n, int r = 0) : n(_n), e(0), root(r), g(_n), built(false) {
        if (n <= 1) build();
    }
    void add_edge(int u, int v) {
        assert(!built);
        assert(e < n - 1);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        g[u].push_back(v);
        g[v].push_back(u);
        if (++e == n - 1) build();
    }
    vector<int> &operator[](int u) {
        return g[u];
    }
    int depth(int u) const {
        assert(built);
        return d[u];
    }
    int lca(int u, int v, int r = -1) const {
        assert(built);
        if (r == -1) {
            auto [l, r] = minmax({in[u], in[v]});
            return st.prod(l, r + 1).second;
        }
        return lca(u, v) ^ lca(v, r) ^ lca(r, u);
    }
    int dist(int u, int v) const {
        assert(built);
        int w = lca(u, v);
        return d[u] + d[v] - 2 * d[w];
    }
    int jump(int u, int v, int k) const {
        assert(built);
        int w = lca(u, v);
        if (d[u] + d[v] - 2 * d[w] < k) return -1;
        if (d[u] - d[w] < k) {
            swap(u, v);
            k = d[u] + d[v] - 2 * d[w] - k;
        }
        k = d[u] - k;
        return *prev(upper_bound(list[k].begin(), list[k].end(), u, [&](int i, int j) {
            return in[i] < in[j];
        }));
    }
    vector<pair<int, int>> auxiliary_tree(vector<int> vs) const {
        if (vs.empty()) return {};
        sort(vs.begin(), vs.end(), [&] (int u, int v) {
            return in[u] < in[v];
        });
        vector<pair<int, int>> res;
        stack<int> st;
        st.push(vs[0]);
        for (int i = 1; i < ssize(vs); i++) {
            int w = lca(vs[i - 1], vs[i]);
            if (w != vs[i - 1]) {
                int u = st.top();
                st.pop();
                while (st.size() && d[w] < d[st.top()]) {
                    res.emplace_back(u, st.top());
                    u = st.top();
                    st.pop();
                }
                res.emplace_back(u, w);
                if (st.empty() || st.top() != w) st.push(w);
            }
            st.push(vs[i]);
        }
        while (st.size() > 1) {
            int u = st.top();
            st.pop();
            res.emplace_back(u, st.top());
        }
        return res;
    }
private:
    struct Monoid {
        using S = pair<int, int>;
        static S op(S a, S b) {
            return min(a, b);
        }
        static S e() {
            return make_pair(1 << 30, -1);
        }
    };
    int n, e, root;
    vector<vector<int>> g, list;
    bool built;
    vector<int> d, ord, in;
    static_rmq<Monoid> st;
    void dfs(int u, int p) {
        ord.push_back(u);
        list[d[u]].push_back(u);
        for (int v : g[u]) {
            if (v != p) {
                d[v] = d[u] + 1;
                dfs(v, u);
                ord.push_back(u);
            }
        }
    }
    void build() {
        if (built) return;
        d = vector<int>(n, 0);
        ord.reserve(2 * n);
        list = vector<vector<int>>(n);
        dfs(root, root);
        in = vector<int>(n, -1);
        st = static_rmq<Monoid>([&]{
            vector<pair<int, int>> a(ord.size());
            for (int i = 0; i < ssize(ord); i++) {
                int u = ord[i];
                if (in[u] == -1) in[u] = i;
                a[i] = make_pair(d[u], u);
            }
            return a;
        }());
        built = true;
    }
};

mint solve(vector<int> A, vector<int> U, vector<int> V) {
    int N = A.size();
    vector<vector<int>> inv(N);
    for (int i = 0; i < N; i++) {
        inv[--A[i]].push_back(i);
    }
    static_tree G(N);
    for (int i = 0; i < N - 1; i++) {
        G.add_edge(U[i], V[i]);
    }
    mint ans = 0;
    for (int c = 0; c < N; c++) {
        // cout << "c = " << c << endl;
        vector<int> V;
        for (int v : inv[c]) V.push_back(v);
        if (V.empty()) continue;
        auto edges = G.auxiliary_tree(V);
        for (auto [u, v] : edges) {
            // cout << u + 1 << ' ' << v + 1 << endl;
            V.push_back(u);
            V.push_back(v);
        }
        sort(V.begin(), V.end());
        V.erase(unique(V.begin(), V.end()), V.end());
        vector<vector<int>> H(V.size());
        for (auto [u, v] : edges) {
            u = lower_bound(V.begin(), V.end(), u) - V.begin();
            v = lower_bound(V.begin(), V.end(), v) - V.begin();
            H[u].push_back(v);
            H[v].push_back(u);
        }
        // tree-dp
        vector<mint> dp(V.size()), ep(V.size());
        auto dfs = [&] (auto dfs, int u, int p) -> void {
            dp[u] = ep[u] = 1;
            for (int v : H[u]) {
                if (v == p) continue;
                dfs(dfs, v, u);
                dp[u] *= ep[v] + 1;
                ep[u] *= ep[v] + 1;
            }
            // cout << u << ' ' << A[V[u]] << ' ' << dp[u].val() << ' ' << ep[u].val() << endl;
            if (A[V[u]] != c) {
                for (int v : H[u]) {
                    if (v != p) dp[u] -= ep[v];
                }
                dp[u]--, ep[u]--;
            }
            // cout << u << ' ' << A[V[u]] << ' ' << dp[u].val() << ' ' << ep[u].val() << endl;
            ans += dp[u];
        };
        dfs(dfs, 0, -1);
    }
    return ans;
}


} // namespace AC


#include <iostream>
#include "../../src/random/graph.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    {
        int A, B;
        cin >> A >> B;
        cout << A + B << '\n';
    }
    for (int t = 0; t < 20; t++) {
        int N = rng::randint(1, (int)2e5);
        vector<int> A = rng::random_sequence(N, 1, N);
        vector<int> U, V;
        for (auto [u, v] : rng::random_tree(N, true)) {
            U.push_back(u);
            V.push_back(v);
        }
        auto ac = AC::solve(A, U, V);
        vector<vector<int>> inv(N);
        for (int i = 0; i < N; i++) {
            inv[--A[i]].push_back(i);
        }
        static_tree G(N);
        for (int i = 0; i < N - 1; i++) {
            G.add_edge(U[i], V[i]);
        }
        mint ans = 0;
        for (int c = 0; c < N; c++) {
            // cout << "c = " << c << endl;
            vector<int> V;
            for (int v : inv[c]) V.push_back(v);
            if (V.empty()) continue;
            auto edges = G.auxiliary_tree(V);
            for (auto [u, v] : edges) {
                // cout << u + 1 << ' ' << v + 1 << endl;
                V.push_back(u);
                V.push_back(v);
            }
            sort(V.begin(), V.end());
            V.erase(unique(V.begin(), V.end()), V.end());
            vector<vector<int>> H(V.size());
            for (auto [u, v] : edges) {
                u = lower_bound(V.begin(), V.end(), u) - V.begin();
                v = lower_bound(V.begin(), V.end(), v) - V.begin();
                H[u].push_back(v);
                H[v].push_back(u);
            }
            // tree-dp
            vector<mint> dp(V.size()), ep(V.size());
            auto dfs = [&] (auto dfs, int u, int p) -> void {
                dp[u] = ep[u] = 1;
                for (int v : H[u]) {
                    if (v == p) continue;
                    dfs(dfs, v, u);
                    dp[u] *= ep[v] + 1;
                    ep[u] *= ep[v] + 1;
                }
                // cout << u << ' ' << A[V[u]] << ' ' << dp[u].val() << ' ' << ep[u].val() << endl;
                if (A[V[u]] != c) {
                    for (int v : H[u]) {
                        if (v != p) dp[u] -= ep[v];
                    }
                    dp[u]--, ep[u]--;
                }
                // cout << u << ' ' << A[V[u]] << ' ' << dp[u].val() << ' ' << ep[u].val() << endl;
                ans += dp[u];
            };
            dfs(dfs, 0, -1);
        }
        assert(ans == ac);
    }
}