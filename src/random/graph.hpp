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

inline vector<pair<int, int>> random_star(int n) {
    assert(n >= 0);
    if (n <= 1) return {};
    if (n == 2) return {make_pair(0, 1)};
    int r = randint(0, n - 1);
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++) {
        if (r != i) res.push_back(minmax(r, i));
    }
    return res;
}

inline vector<pair<int, int>> random_path(int n) {
    assert(n >= 0);
    if (n <= 1) return {};
    if (n == 2) return {make_pair(0, 1)};
    auto p = random_permutation(n, 0);
    vector<pair<int, int>> res;
    for (int i = 1; i < n; i++) {
        res.emplace_back(minmax(p[i - 1], p[i]));
    }
    shuffle(res);
    return res;
}

inline vector<pair<int, int>> random_binary_tree(int n) {
    assert(n >= 0);
    if (n <= 1) return {};
    if (n == 2) return {make_pair(0, 1)};
    auto p = random_permutation(n, 0);
    vector<pair<int, int>> res;
    for (int i = 1; i < n; i++) {
        res.emplace_back(minmax(p[(i - 1) / 2], p[i]));
    }
    shuffle(res);
    return res;
}

inline vector<pair<int, int>> random_broom(int n) {
    assert(n >= 0);
    if (n <= 1) return {};
    if (n == 2) return {make_pair(0, 1)};
    auto p = random_permutation(n, 0);
    int m = randint(1, n);
    vector<pair<int, int>> res;
    for (int i = 1; i < n; i++) {
        res.emplace_back(minmax(p[min(m, i - 1)], p[i]));
    }
    shuffle(res);
    return res;
}

inline vector<pair<int, int>> random_caterpillar(int n) {
    assert(n >= 0);
    if (n <= 1) return {};
    if (n == 2) return {make_pair(0, 1)};
    auto p = random_permutation(n, 0);
    int m = randint(1, n);
    vector<pair<int, int>> res;
    for (int i = 1; i < n; i++) {
        if (i < m) res.emplace_back(minmax(p[i - 1], p[i]));
        else res.emplace_back(minmax(p[randint(0, m - 1)], p[i]));
    }
    shuffle(res);
    return res;
}

inline vector<pair<int, int>> random_tree(int n, bool corner = false) {
    assert(n >= 0);
    if (n <= 1) return {};
    if (n == 2) return {make_pair(0, 1)};
    if (corner) {
        int type = randint(1, 6);
        if (type == 1) return random_star(n);
        if (type == 2) return random_path(n);
        if (type == 3) return random_binary_tree(n);
        if (type == 4) return random_broom(n);
        if (type == 5) return random_caterpillar(n);
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

inline vector<pair<int, int>> random_simple_graph(int n, int m) {
    assert(n >= 0);
    assert(m >= 0);
    assert((long long)m <= (long long)n * (n - 1) / 2);
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

inline vector<pair<int, int>> random_connected_graph(int n, int m) {
    assert(n >= 0);
    assert(m >= n - 1);
    assert((long long)m <= (long long)n * (n - 1) / 2);
    auto t = random_tree(n, true);
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