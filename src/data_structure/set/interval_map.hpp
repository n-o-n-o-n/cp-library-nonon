#pragma once
#include <cassert>
#include <numeric>
#include <set>
#include <vector>
using namespace std;

// https://noimi.hatenablog.com/entry/2021/05/02/195143?_ga=2.186800042.36757101.1619952706-2024379568.1619952706

template<typename T, typename S>
struct interval_map {
    interval_map(const S &_e = S()) : e(_e) {
        s.emplace(node(-inf, -inf, e));
        s.emplace(node(inf, inf, e));
    }
    // for i in [l, r): a[i] <- x
    // when s.insert(node(l, r, x)), call add(l, r, x)
    // when s.erase(node(l, r, x)), call del(l, r, x)
    template<typename A, typename D>
    void update(T l, T r, const S &x, const A &add, const D &del) {
        auto it = s.lower_bound(node(l, 0, x));
        while (it != s.end() && it->l <= r) {
            if (it->l == r) {
                if (it->x == x) {
                    del(r, it->r, x);
                    r = it->r;
                    it = s.erase(it);
                }
                break;
            }
            if (it->r <= r) {
                del(it->l, it->r, it->x);
                it = s.erase(it);
            } else {
                if (it->x == x) {
                    r = it->r;
                    del(it->l, it->r, it->x);
                    it = s.erase(it);
                } else {
                    del(it->l, r, it->x);
                    auto a = *it;
                    it = s.erase(it);
                    it = s.emplace_hint(it, r, a.r, a.x);
                }
            }
        }
        if (it != s.begin()) {
            it = prev(it);
            if (it->r == l) {
                if (it->x == x) {
                    del(it->l, it->r, it->x);
                    l = it->l;
                    it = s.erase(it);
                }
            } else if (l < it->r) {
                if (it->x == x) {
                    del(it->l, it->r, it->x);
                    l = min(l, it->l);
                    r = max(r, it->r);
                    it = s.erase(it);
                } else {
                    if (r < it->r) {
                        it = s.emplace_hint(next(it), r, it->r, it->x);
                        it = prev(it);
                    }
                    del(l, min(r, it->r), it->x);
                    auto a = *it;
                    it = s.erase(it);
                    it = s.emplace_hint(it, a.l, l, a.x);
                }
            }
            if (it != s.end()) it = next(it);
            add(l, r, x);
            s.emplace_hint(it, l, r, x);
        }
    }
    void update(T l, T r, const S &x) {
        update(l, r, x, [] (T, T, S) {}, [] (T, T, S) {});
    }
    template<typename A, typename D>
    void update(T k, const S &x, const A &add, const D &del) {
        update(k, k + 1, x, add, del);
    }
    void update(T k, const S &x) {
        update(k, k + 1, x);
    }
    // return (left, right, val) s.t. left <= k < right
    tuple<T, T, S> get(T k) const {
        auto it = key(k);
        return it->l <= k && k < it->r ? make_tuple(it->l, it->r, it->x) : make_tuple(k, k + 1, e);
    }
    // val at k
    S operator[](T k) const {
        return key(k)->x;
    }
    // return (left, right, val) s.t. r = min(k < r)
    tuple<T, T, S> mex(T k) const {
        auto it = key(k);
        return make_tuple(it->l, it->r, it->x);
    }
    vector<tuple<T, T, S>> intervals() const {
        vector<tuple<T, T, S>> res;
        res.reserve(s.size());
        for (auto [l, r, x] : s) {
            if (abs(l) != inf && abs(r) != inf) res.emplace_back(l, r, x);
        }
        return res;
    }
    void debug() const {
        for (auto [l, r, x] : intervals()) {
            cout << '(' << l << ',' << r << ',' << x << ')';
        }
        cout << endl;
    }
private:
    static constexpr T inf = numeric_limits<T>::max();
    struct node {
        T l, r;
        S x;
        node() : node(-inf, -inf, e) {}
        node(T _l, T _r, const S &_x) : l(_l), r(_r), x(_x) {}
        constexpr bool operator<(const node &a) const {
            return l == a.l ? r < a.r : l < a.l;
        }
    };
    const S e;
    set<node> s;
    typename set<node>::iterator key(T k) const {
        return prev(s.upper_bound(node(k, inf, e)));
    }
};