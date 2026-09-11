#pragma once
#include <array>
#include <vector>
using namespace std;

template<typename T, int ary = 2>
struct persistent_array {
    static_assert((ary & (ary - 1)) == 0, "k must be pow of 2");
    persistent_array() {}
    persistent_array(int n, const T &x) : persistent_array(vector<T>(n, x)) {}
    persistent_array(const vector<T> &a) {
        int n = a.size();
    }
    int set(int k, int p, const T &x) {}
private:
    static constexpr int mask = ary - 1;
    struct node {
        node() : x(-1), par(-1) { ch.fill(-1); }
        int x, par;
        array<int, ary> ch;
    };
    vector<node> d;
    vector<int> roots;
    vector<T> vals;
    T val(int p) { return d[p].x == -1 ? T() : vals[d[p].x]; }
};