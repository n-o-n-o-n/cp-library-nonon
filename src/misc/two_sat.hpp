#pragma once
#include <cassert>
#include <vector>
#include "../graph/scc.hpp"
using namespace std;

struct two_sat {
    two_sat() : two_sat(0) {}
    two_sat(int _n) : n(_n), g(_n) {}
    void add_clause(int i, bool f, int j, bool g) {
        g[f * n + i].push_back((!g) * n + j);
        g[g * n + j].push_back((!f) * n + i);
    }
    vector<bool> solve() {
        
    }
    int n;
    vector<vector<int>> g;
};