#pragma once
#include <cassert>
#include <vector>
using namespace std;

template<typename T>
struct persistent_stack {
    persistent_stack() : sz(1, 0), roots(1, -1) {}
    // n: the number of 'push' query
    // q: the number of 'pop' query
    void reserve(int n, int q = 0) {
        d.reserve(n);
        prev.reserve(n);
        sz.reserve(n + q + 1);
        roots.reserve(n + q + 1);
    }
    int size(int k) const {
        assert(0 <= k && k < ssize(roots));
        return sz[k];
    }
    T top(int k) const {
        assert(0 <= k && k < ssize(roots));
        assert(roots[k] != -1);
        return d[roots[k]];
    }
    int pop(int k) {
        assert(0 <= k && k < ssize(roots));
        int res = roots.size();
        if (roots[k] == -1) {
            sz.push_back(0);
            roots.push_back(-1);
        } else {
            sz.push_back(sz[k] - 1);
            roots.push_back(prev[roots[k]]);
        }
        return res;
    }
    int push(int k, const T &x) {
        assert(0 <= k && k < ssize(roots));
        int res = roots.size();
        roots.push_back(d.size());
        prev.push_back(roots[k]);
        sz.push_back(sz[k] + 1);
        d.push_back(x);
        return res;
    }
private:
    vector<int> prev, sz, roots;
    vector<T> d;
};