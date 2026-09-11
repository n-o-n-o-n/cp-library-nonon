#pragma once
#include <array>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

template<int size, char base>
struct trie {
    trie() : idx(0), par(1, -1), chr(1, -1), cnt(1, 0), last(0), child(1, e()), tail(1) {}
    vector<int> track(const string &s) const {
        int n = s.size(), pos = 0;
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - base;
            if (child[pos][c] == -1) break;
            pos = child[pos][c];
            res[i] = pos;
        }
        return res;
    }
    vector<int> insert(const string &s) {
        int n = s.size(), pos = 0;
        for (int i = 0; i < n; i++) {
            int c = s[i] - base;
            if (child[pos][c] == -1) {
                child[pos][c] = par.size();
                par.push_back(pos);
                chr.push_back(c);
                cnt.push_back(0);
                child.push_back(e());
                tail.push_back({});
            }
            pos = child[pos][c];
            cnt[pos]++;
        }
        tail[pos].push_back(idx++);
        last.push_back(pos);
        return track(s);
    }
    string operator[](int k) const {
        assert(0 <= k && k < int(last.size()));
        int pos = last[k];
        string s = "";
        while (pos > 0) {
            s.push_back(base + chr[pos]);
            pos = par[pos];
        }
        reverse(s.begin(), s.end());
        return s;
    }
    string kth_smallest(int k) const {
        int pos = 0;
        string s = "";
        bool fn = true;
        while (fn) {
            fn = false;
            k -= tail[pos].size();
            for (int i = 0; i < size; i++) {
                int nxt = child[pos][i];
                if (nxt != -1) {
                    if (0 <= k && k < cnt[nxt]) {
                        pos = nxt;
                        s.push_back(base + chr[pos]);
                        fn = true;
                        break;
                    }
                    k -= cnt[nxt];
                }
            }
        }
        return s;
    }
    int count(const string &s) const {
        int p = track(s).back();
        return p == -1 ? 0 : (int)tail[p].size();
    }
    // the number of strings that have s as a prefix
    int count_prefix(const string &s) const {
        int p = track(s).back();
        return p == -1 ? 0 : cnt[p];
    }
    // the number of strings that have s with a prefix
    int prefix_count(const string &s) const {
        int res = 0;
        for (int i : track(s)) {
            if (i == -1) break;
            res += tail[i].size();
        }
        return res;
    }
private:
    int idx;
    vector<int> par, chr, cnt, last;
    vector<array<int, size>> child;
    vector<vector<int>> tail;
    constexpr array<int, size> e() {
        array<int, size> x;
        x.fill(-1);
        return x;
    }
};
