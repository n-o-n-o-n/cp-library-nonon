#pragma once
#include <cassert>
#include <set>
using namespace std;

template<typename T1, typename T2 = long long>
struct median_set {
    median_set() : upper_sum(0), lower_sum(0) {}
    void insert(T1 x) {
        if (lower.empty() || x <= *prev(lower.end())) {
            lower_sum += x;
            lower.insert(x);
        } else {
            upper_sum += x;
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
            upper_sum -= *it;
            upper.erase(it);
        }
        normalize();
    }
    T1 median() const {
        assert(lower.size());
        return *prev(lower.end());
    }
    T2 min_cost() const {
        T2 med = median();
        return (upper_sum - med * upper.size()) + (med * lower.size() - lower_sum);
    }
private:
    multiset<T1> upper, lower;
    T2 upper_sum, lower_sum;
    void normalize() {
        while (lower.size() > upper.size() + 1) {
            auto it = prev(lower.end());
            upper_sum += *it;
            upper.insert(*it);
            lower_sum -= *it;
            lower.erase(it);
        }
        while (lower.size() < upper.size()) {
            auto it = upper.begin();
            lower_sum += *it;
            lower.insert(*it);
            upper_sum -= *it;
            upper.erase(it);
        }
    }
};