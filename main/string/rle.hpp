#pragma once
#include <string>
#include <vector>
using namespace std;

template<typename T>
vector<pair<T, int>> run_length_encoding(const vector<T> &v) {
    vector<pair<T, int>> res;
    for (const auto &x : v) {
        if (res.empty() || res.back().first != x) {
            res.emplace_back(x, 0);
        }
        res.back().second++;
    }
    return res;
}

vector<pair<char, int>> run_length_encoding(const string &s) {
    return run_length_encoding(vector<char>(s.begin(), s.end()));
}