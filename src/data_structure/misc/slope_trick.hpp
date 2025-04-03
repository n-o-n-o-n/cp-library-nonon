#pragma once
#include <cassert>
#include <queue>
#include <numeric>
#include <vector>
using namespace std;

// https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8 
// https://ei1333.github.io/library/structure/others/slope-trick.hpp.html 
// 書きかけ
template<typename T>
struct slope_trick {
    static constexpr T inf = numeric_limits<T>::max() / 3;
    T min_val, left_add, right_add;
    priority_queue<T, vector<T>, less<T>> left;
    priority_queue<T, vector<T>, greater<T>> right;
    T left_top() const {
        assert(left.size());
        return left.top() + left_add;
    }
    T right_top() const {
        assert(right.size());
        return right.top() + right_add;
    }
    T left_pop() {
        T res = left_top();
        left.pop();
        return res;
    }
    T right_pop() {
        T res = right_top();
        right.pop();
        return res;
    }
    void left_push(T a) { left.push(a - left_add); }
    void right_push(T a) { right.push(a - right_add); }
    slope_trick() : min_val(0), left_add(0), right_add(0) {
        left.push(-inf);
        right.push(inf);
    }
    T get_min() const { return min_val; }
    pair<T, T> min_range() const { return make_pair(left_top(), right_top()); }
    void add_all(T a) { min_val += a; }
    // f(x) += max(0, x - a)
    void add_x_minus_a(T a) {
        min_val += max<T>(0, left_top() - a);
        left_push(a);
        right_push(left_pop());
    }
    // f(x) += max(0, a - x)
    void add_a_minus_x(T a) {
        min_val += max<T>(0, a - right_top());
        right_push(a);
        left_push(right_pop());
    }
    // f(x) += |x - a|
    void add_abs_x_minus_a(T a) {
        add_x_minus_a(a);
        add_a_minus_x(a);
    }
};