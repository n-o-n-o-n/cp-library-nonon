#pragma once
#include <array>
#include <cassert>
#include <vector>
using namespace std;

template<typename T>
struct binary_trie {
    binary_trie(int _log = numeric_limits<T>::digits) : log(_log), all(0), sub(1, 0), child(1, e()) {}
    int size() const { return all; }
    vector<int> track(T x) const {
        int pos = 0;
        vector<int> res(log, -1);
        for (int i = log - 1; i >= 0; i--) {
            int c = x >> i & 1;
            int nxt = child[pos][c];
            if (nxt == -1) break;
            pos = nxt;
            res[log - 1 - i] = pos;
        }
        return res;
    }
    vector<int> insert(T x) {
        int pos = 0;
        for (int i = log - 1; i >= 0; i--) {
            int c = x >> i & 1;
            int nxt = child[pos][c];
            if (nxt == -1) {
                nxt = sub.size();
                sub.push_back(0);
                child.push_back(e());
            }
            child[pos][c] = nxt;
            pos = nxt;
        }
        vector<int> tr = track(x);
        int p = tr.back();
        if (sub[p] == 0) {
            for (int i : tr) sub[i]++;
            all++;
        }
        return tr;
    }
    void erase(T x) {
        vector<int> tr = track(x);
        int p = tr.back();
        if (p == -1 || sub[p] == 0) return;
        for (int i : tr) sub[i]--;
        all--;
    }
    // return (x in S ? true : false);
    bool constains(T x) const {
        int p = track(x).back();
        return (p != -1) && (sub[p] > 0);
    }
    T kth_smallest(int k, T xor_val = 0) const {
        assert(0 <= k && k < size());
        int pos = 0;
        T res = 0;
        for (int i = log - 1; i >= 0; i--) {
            res *= 2;
            int c = xor_val >> i & 1;
            int nxt = child[pos][c];
            if (nxt != -1) {
                if (0 <= k && k < sub[nxt]) {
                    pos = nxt;
                    continue;
                }
                k -= sub[nxt];
            }
            pos = child[pos][1 - c];
            res++;
        }
        return res;
    }
    T kth_largest(int k, T xor_val = 0) const {
        assert(0 <= k && k < size());
        return kth_smallest(size() - 1 - k, xor_val);
    }
    T min(T xor_val = 0) const {
        assert(size());
        return kth_smallest(0, xor_val);
    }
    T max(T xor_val = 0) const {
        assert(size());
        return kth_largest(0, xor_val);
    }
    T mex(T xor_val = 0) const {
        if (size() == 0) return T(0);
        int pos = 0;
        T res = 0;
        for (int i = log - 1; i >= 0; i--) {
            res *= 2;
            int c = xor_val >> i & 1;
            int nxt = child[pos][c];
            if (nxt == -1) return res << i;
            if (sub[nxt] < (T(1) << i)) {
                pos = nxt;
                continue;
            }
            res++;
            if (child[pos][1 - c] == -1) return res << i;
            pos = child[pos][1 - c];
        }
        return res;
    }
    // retrun #{y in S | y xor xor_val <= x}
    int lower_count(T x, T xor_val = 0) const {
        int pos = 0;
        int res = 0;
        for (int i = log - 1; i >= 0; i--) {
            if (pos == -1) break;
            int cx = (x >> i) & 1;
            int cxor = (xor_val >> i) & 1;
            int nxt0 = child[pos][cxor];
            int nxt1 = child[pos][1 - cxor];
            if (cx == 1) {
                if (nxt0 != -1) {
                    res += sub[nxt0];
                }
                pos = nxt1;
            } else {
                pos = nxt0;
            }
        }
        if (pos != -1) {
            res += sub[pos];
        }
        return res;
    }
    // return #{y in S | y xor xor_val >= x}
    int upper_count(T x, T xor_val = 0) const {
        int res = 0;
        int pos = 0;
        for (int i = log - 1; i >= 0; i--) {
            if (pos == -1) break;
            int cx = (x >> i) & 1;
            int cxor = (xor_val >> i) & 1;
            int nxt0 = child[pos][cxor];
            int nxt1 = child[pos][1 - cxor];
            if (cx == 0) {
                if (nxt1 != -1) {
                    res += sub[nxt1];
                }
                pos = nxt0;
            } else {
                pos = nxt1;
            }
        }
        if (pos != -1) {
            res += sub[pos];
        }
        return res;
    }
private:
    int log, all;
    vector<int> sub;
    vector<array<int, 2>> child;
    constexpr array<int, 2> e() {
        return {-1, -1};
    }
};