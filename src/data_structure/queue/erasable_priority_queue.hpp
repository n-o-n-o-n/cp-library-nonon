#pragma once
#include <cassert>
#include <queue>
#include <vector>
using namespace std;

template<typename T, typename Container = vector<T>, typename Compare = less<T>>
struct erasable_priority_queue {
    erasable_priority_queue() = default;
    void push(const T &x) {
        pq.push(make_pair(x, time++));
    }
    void erase(const T &x) {
        del.push(make_pair(x, time++));
    }
    T top() {
        normalize();
        assert(pq.size());
        return pq.top().first;
    }
    void pop() {
        normalize();
        assert(pq.size());
        pq.pop();
    }
private:
    using P = pair<T, int>;
    struct PairCompare {
        Compare comp;
        bool operator()(const P &p, const P &q) const {
            return comp(q.first, p.first) || (p.first == q.first && p.first > q.first);
        }
    };
    int time;
    priority_queue<P, vector<P>, PairCompare> pq, del;
    void normalize() {
        while (pq.size() && del.size()) {
            auto [qv, qt] = pq.top();
            auto [dv, dt] = del.top();
            if (qv == dv) {
                del.pop();
                if (qt < dt) pq.pop();
            } else if (Compare()(dv, dv)) {
                del.pop();
            } else {
                break;
            }
        }
    }
};