#pragma once
#include <cassert>
#include <set>
using namespace std;

template<typename T1, typename T2 = long long, typename Compare = less<T1>>
struct top_k_set {
    top_k_set(int _k) : k(_k), lower_sum(0) {}
    void insert(T1 x) {
        if ((int)lower.size() < k || Compare()(x, *prev(lower.end()))) {
            lower_sum += x;
            lower.insert(x);
        } else {
            upper.insert(x);
        }
        normalize();
    }
    void erase(T1 x) {
        auto it = lower.find(x);
        if (it != lower.end()) {
            lower_sum -= *it;
            lower.erase(it);
        } else {
            it = upper.find(x);
            assert(it != upper.end());
            upper.erase(it);
        }
        normalize();
    }
    T1 kth_val() const {
        assert((int)lower.size() == k);
        return *prev(lower.end());
    }
    T2 sum() const {
        assert((int)lower.size() == k);
        return lower_sum;
    }
private:
    int k;
    multiset<T1, Compare> lower, upper;
    T2 lower_sum;
    void normalize() {
        while ((int)lower.size() > k) {
            auto it = prev(lower.end());
            upper.insert(*it);
            lower_sum -= *it;
            lower.erase(it);
        }
        while ((int)lower.size() < k && upper.size()) {
            auto it = upper.begin();
            lower_sum += *it;
            lower.insert(*it);
            upper.erase(it);
        }
    }
};