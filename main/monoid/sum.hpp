#pragma once
using namespace std;

template <typename T>
struct add_monoid {
    using S = T;
    static S op(const S &a, const S &b) {
        return a + b;
    }
    static S e() { return 0; }
};