#pragma once
#include <algorithm>
#include <cassert>
#include <set>
#include <vector>
#include "utility.hpp"
#include "sequence.hpp"
#include "../tree/prufer_code.hpp"
using namespace std;

namespace rng {

vector<pair<int, int>> random_tree(int n, bool corner = false) {
    if (n == 1) return {};
    if (n == 2) return {make_pair(0, 1)};
    if (corner) {
        // ウニ
        if (randint(1, 3) == 1) {
            int r = randint(0, n - 1);
            vector<pair<int, int>> res;
            for (int i = 0; i < n; i++) {
                if (r != i) res.push_back(minmax(r, i));
            }
            return res;
        }
        // パス
        if (randint(1, 3) == 1) {
            auto p = random_permutaion(n, 0);
            vector<pair<int, int>> res;
            for (int i = 1; i < n; i++) {
                res.emplace_back(minmax(p[i - 1], p[i]));
            }
            return res;
        }
    }
    vector<int> p(n - 2);
    for (int &e : p) e = randint(0, n - 1);
    auto t = prufer_code_expansion(p);
    vector<pair<int, int>> res;
    for (int u = 0; u < n; u++) {
        for (int v : t[u]) {
            if (u < v) res.emplace_back(u, v);
        }
    }
    return res;
}

vector<pair<int, int>> random_graph(int n, int m) {
    if (n <= 3000) {
        vector<pair<int, int>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edges.emplace_back(i, j);
            }
        }
        shuffle(edges);
        return vector<pair<int, int>>(edges.begin(), edges.begin() + m);
    }
    set<pair<int, int>> edges;
    while ((int)edges.size() < m) {
        auto [u, v] = randpair(0, n - 1, true);
        edges.emplace(u, v);
    }
    return vector<pair<int, int>>(edges.begin(), edges.end());
}

vector<pair<int, int>> random_connected_graph(int n, int m) {
    assert(n - 1 <= m);
    auto t = random_tree(n);
    if (n <= 3000) {
        vector<vector<bool>> used(n, vector<bool>(n, false));
        for (auto [u, v] : t) used[u][v] = true;
        vector<pair<int, int>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!used[i][j]) edges.emplace_back(i, j);
            }
        }
        shuffle(edges);
        m -= n - 1;
        while ((int)edges.size() > m) edges.pop_back();
        for (auto p : t) edges.push_back(p);
        return edges;
    }
    set<pair<int, int>> edges(t.begin(), t.end());
    while ((int)edges.size() < m) {
        auto [u, v] = randpair(0, n - 1, true);
        edges.emplace(u, v);
    }
    return vector<pair<int, int>>(edges.begin(), edges.end());
}

} // namespace rng