#pragma once
#include <cassert>
#include <numeric>
#include <map>
using namespace std;

// 書きかけ
template<typename T>
struct range_map {
    range_map() : sum(0) {
        s.emplace(-inf, -inf);
        s.emplace(inf, inf);
    }
    vector<pair<T, T>> ranges() const {
        vector<pair<T, T>> res;
        res.reserve(s.size());
        for (const auto &[l, r] : s) {
            if (abs(l) != inf && abs(r) != inf) res.emplace_back(l, r);
        }
        return res;
    }
    T insert(T l, T r) {
        assert(l <= r);
        if (l == r) return 0;
        auto it = key(l);
        if (it->first <= l && r <= it->second) return 0;
        T dec = 0;
        if (it->first <= l && l <= it->second) {
            l = it->first;
            dec += it->second - it->first;
            it = s.erase(it);
        } else {
            it = next(it);
        }
        while (it->second < r) {
            dec += it->second - it->first;
            it = s.erase(it);
        }
        if (it->first <= r) {
            dec += it->second - it->first;
            r = it->second;
            s.erase(it);
        }
        s.emplace(l, r);
        sum += r - l + dec;
        return r - l + dec;
    }
    T insert(T k) {
        return insert(k, k + 1);
    }
    T erase(T l, T r) {
        assert(l <= r);
        if (l == r) return 0;
        auto it = key(l);
        if (it->first <= l && r <= it->second) {
            if (it->first < l) s.emplace(it->first, l);
            if (r < it->second) s.emplace(r, it->second);
            s.erase(it);
            sum -= r - l;
            return r - l;
        }
        T dec = 0;
        if (it->first <= l && l < it->second) {
            dec += it->second - l;
            if (it->first < l) s.emplace(it->first, l);
            it = s.erase(it);
        } else {
            it = next(it);
        }
        while (it->second <= r) {
            dec += it->second - it->first;
            it = s.erase(it);
        }
        if (it->first < r) {
            dec += r - it->first;
            s.emplace(r, it->second);
            s.erase(it);
        }
        sum -= dec;
        return dec;
    }
    T erase(T k) {
        return erase(k, k + 1);
    }
    int size() const {
        return (int)s.size() - 2;
    }
    T mex(T k = 0) const {
        auto it = key(k);
        return (it->first <= k && k < it->second ? it->second : k);
    }
    bool covered(T l, T r) const {
        assert(l <= r);
        if (l == r) return true;
        auto it = key(l);
        return it->first <= l && r <= it->second;
    }
    bool covered(T k) const {
        return covered(k, k + 1);
    }
    pair<T, T> get(T l, T r) const {
        assert(l <= r);
        if (l == r) return *s.begin();
        auto it = key(l);
        return *(it->first <= l && r <= it->second ? it : s.begin());
    }
    pair<T, T> get(T k) const {
        return get(k, k + 1);
    }
private:
    static constexpr T inf = numeric_limits<T>::max();
    T sum;
    set<pair<T, T>> s;
    set<pair<T, T>>::iterator key(T k) const {
        return prev(s.upper_bound(make_pair(k, inf)));
    }
};