#pragma once
#include <cassert>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>
using namespace std;

template<typename T>
struct interval_set {
    interval_set() {
        s.emplace(-inf, -inf);
        s.emplace(inf, inf);
    }
    template<typename A, typename D>
    void insert(T l, T r, const A &add, const D &del) {
        if (l == r) return;
        auto it = key(l);
        if (it->l <= l && r <= it->r) return;
        if (it->l <= l && l <= it->r) {
            del(it->l, it->r);
            l = it->l;
            it = s.erase(it);
        } else {
            it = next(it);
        }
        while (it->r < r) {
            del(it->l, it->r);
            it = s.erase(it);
        }
        if (it->l <= r) {
            del(it->l, it->r);
            r = it->r;
            s.erase(it);
        }
        add(l, r);
        s.emplace(node(l, r));
    }
    void insert(T l, T r) {
        insert(l, r, [] (T, T) {}, [] (T, T) {});
    }
    template<typename A, typename D>
    void insert(T k, const A &add, const D &del) {
        insert(k, k + 1, add, del);
    }
    void insert(T k) {
        insert(k, k + 1);
    }
    template<typename A, typename D>
    void erase(T l, T r, const A &add, const D &del) {
        if (l == r) return;
        auto it = key(l);
        if (it->l <= l && r <= it->r) {
            if (it->l < l) {
                add(it->l, l);
                s.emplace(node(it->l, l));
            }
            if (r < it->r) {
                add(r, it->r);
                s.emplace(node(r, it->r));
            }
            del(it->l, it->r);
            s.erase(it);
            return;
        }
        if (it->l <= l && l < it->r) {
            if (it->l < l) {
                add(it->l, l);
                s.emplace(it->l, l);
            }
            del(it->l, it->r);
            it = s.erase(it);
        } else {
            it = next(it);
        }
        while (it->r <= r) {
            del(it->l, it->r);
            it = s.erase(it);
        }
        if (it->l < r) {
            add(r, it->r);
            s.emplace(r, it->r);
            del(it->l, it->r);
            s.erase(it);
        }
    }
    void erase(T l, T r) {
        erase(l, r, [] (T, T) {}, [] (T, T) {});
    }
    template<typename A, typename D>
    void erase(T k, const A &add, const D &del) {
        erase(k, k + 1, add, del);
    }
    void erase(T k) {
        erase(k, k + 1);
    }
    T mex(T k = 0) const {
        auto it = key(k);
        return it->l <= k && k < it->r ? it->r : k;
    }
    bool covered(T l, T r) const {
        if (l == r) return true;
        auto it = key(l);
        return it->l <= l && r <= it->r;
    }
    bool covered(T k) const {
        return covered(k, k + 1);
    }
    pair<T, T> get(T k) const {
        auto it = key(k);
        return it->l <= k && k < it->r ? make_pair(it->l, it->r) : make_pair(-inf, -inf);
    }
    vector<pair<T, T>> intervals() const {
        vector<pair<T, T>> res;
        res.reserve(s.size());
        for (auto [l, r] : s) {
            if (abs(l) != inf && abs(r) != inf) res.emplace_back(l, r);
        }
        return res;
    }
    void clear() {
        s = set<node>();
        s.emplace(-inf, -inf);
        s.emplace(inf, inf);
    }
    void debug() const {
        for (auto [l, r] : intervals()) {
            cout << '(' << l << ',' << r << ')';
        }
        cout << endl;
    }
private:
    static constexpr T inf = numeric_limits<T>::max();
    struct node {
        T l, r;
        node() : node(-inf, -inf) {}
        node(T _l, T _r) : l(_l), r(_r) {}
        constexpr bool operator<(const node &a) const {
            return l == a.l ? r < a.r : l < a.l;
        }
    };
    set<node> s;
    typename set<node>::iterator key(T k) const {
        return prev(s.upper_bound(node(k, inf)));
    }
};