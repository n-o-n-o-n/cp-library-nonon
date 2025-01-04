#pragma once
#include <array>
#include <cassert>
#include <vector>
using namespace std;

template<typename T>
struct multi_binary_trie {
    multi_binary_trie(int _log = numeric_limits<T>::digits) : log(_log), all(0), sub(1, 0), cnt(1, 0), child(1, e()) {}
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
                cnt.push_back(0);
                child.push_back(e());
            }
            child[pos][c] = nxt;
            pos = nxt;
        }
        vector<int> tr = track(x);
        int p = tr.back();
        for (int i : tr) cnt[i]++;
        all++;
        if (sub[p] == 0) {
            for (int i : tr) sub[i]++;
        }
        return tr;
    }
    void erase(T x) {
        vector<int> tr = track(x);
        int p = tr.back();
        if (p == -1 || sub[p] == 0) return;
        for (int i : tr) cnt[i]--;
        all--;
        if (cnt[p] == 0) {
            for (int i : tr) sub[i]--;
        }
    }
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
                if (0 <= k && k < cnt[nxt]) {
                    pos = nxt;
                    continue;
                }
                k -= cnt[nxt];
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
private:
    int log, all;
    vector<int> sub, cnt;
    vector<array<int, 2>> child;
    constexpr array<int, 2> e() {
        return {-1, -1};
    }
};