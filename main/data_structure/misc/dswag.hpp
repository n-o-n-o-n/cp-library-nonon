#pragma once
#include <algorithm>
#include <cassert>
#include <stack>
#include <vector>
using namespace std;

template<typename Monoid>
struct dswag {
    using S = typename Monoid::S;
    dswag() = default;
    size_t size() const { return f1.size() + b1.size(); }
    bool empty() const { return size() == 0; }
    S get() const { return Monoid::op(get_f(), get_b()); }
    void push_front(const S &x) { push_f(x); }
    void push_back(const S &x) { push_b(x); }
    void pop_front() {
        assert(size());
        if (f1.empty()) normalize();
        pop_f();
    }
    void pop_back() {
        assert(size());
        if (b1.empty()) normalize();
        pop_b();
    }
private:
    stack<S> f1, f2, b1, b2;
    void normalize() {
        int n = size();
        int m = n / 2 + (f1.size() ? 0 : n & 1);
        vector<S> f, b;
        while (f1.size()) {
            f.push_back(f1.top());
            pop_f();
        }
        while (b1.size()) {
            b.push_back(b1.top());
            pop_b();
        }
        reverse(b.begin(), b.end());
        copy(b.begin(), b.end(), back_inserter(f));
        for (int i = m - 1; i >= 0; i--) push_f(f[i]);
        for (int i = m; i < n; i++) push_b(f[i]);
    }
    S get_f() const { return f2.size() ? f2.top() : Monoid::e(); }
    S get_b() const { return b2.size() ? b2.top() : Monoid::e(); }
    void push_f(const S &x) {
        auto y = get_f();
        f1.push(x);
        f2.push(Monoid::op(x, y));
    }
    void push_b(const S &x) {
        auto y = get_b();
        b1.push(x);
        b2.push(Monoid::op(y, x));
    }
    void pop_f() {
        f1.pop();
        f2.pop();
    }
    void pop_b() {
        b1.pop();
        b2.pop();
    }
};