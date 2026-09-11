#pragma once
#include <cassert>
#include <numeric>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;

struct undoable_dsu {
    undoable_dsu() = default;
    undoable_dsu(int n) : p(n, -1), cyc(n) {
        iota(cyc.begin(), cyc.end(), 0);
    }
    int leader(int u) const {
        assert(0 <= u && u < ssize(p));
        return p[u] < 0 ? u : leader(p[u]);
    }
    bool same(int u, int v) const {
        assert(0 <= u && u < ssize(p));
        assert(0 <= v && v < ssize(p));
        return leader(u) == leader(v);
    }
    void merge(int u, int v) {
        assert(0 <= u && u < ssize(p));
        assert(0 <= v && v < ssize(p));
        u = leader(u);
        v = leader(v);
        his.emplace(u, p[u], cyc[u]);
        his.emplace(v, p[v], cyc[v]);
        if (u == v) return;
        if (p[u] > p[v]) swap(u, v);
        p[u] += p[v];
        p[v] = u;
        swap(cyc[u], cyc[v]);
    }
    int size(int u) const {
        assert(0 <= u && u < ssize(p));
        return -p[leader(u)];
    }
    vector<int> group(int u) const {
        vector<int> res = {u};
        int v = cyc[u];
        while (v != u) {
            res.push_back(v);
            v = cyc[v];
        }
        return res;
    }
    void undo() {
        assert(his.size());
        for (auto _ : {0, 1}) {
            auto [u, pu, cu] = his.top();
            his.pop();
            p[u] = pu;
            cyc[u] = cu;
        }
    }
private:
    vector<int> p, cyc;
    stack<tuple<int, int, int>> his;
};