#pragma once
#include <cassert>
#include <stack>
using namespace std;

template<typename Monoid>
struct swag {
    using S = typename Monoid::S;
    swag() = default;
    size_t size() const { return f1.size() + b1.size(); }
    bool empty() const { return size() == 0; }
    S get() const { return Monoid::op(get_f(), get_b()); }
    void push(const S &x) { push_b(x); }
    void pop() {
        assert(size());
        if (f1.empty()) normalize();
        pop_f();
    }
private:
    stack<S> f1, f2, b1, b2;
    void normalize() {
        while (b1.size()) {
            push_f(b1.top());
            pop_b();
        }
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