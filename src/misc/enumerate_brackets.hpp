#pragma once
#include <vector>
using namespace std;

// n <= 15 が限界かな
vector<string> enumerate_brackets(int n) {
    vector<string> res;
    auto dfs = [&] (const auto &dfs, int x, int y, string s) -> void {
        if (x == n && y == n) {
            res.push_back(s);
            return;
        }
        if (x < n) dfs(dfs, x + 1, y, s + "(");
        if (y < x) dfs(dfs, x, y + 1, s + ")");
    };
    dfs(dfs, 0, 0, "");
    return res;
}