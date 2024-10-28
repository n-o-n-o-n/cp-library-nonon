#pragma once
#include <array>
#include <vector>
using namespace std;

template<int size, char base>
struct trie {
    int idx;
    vector<int> par, chr, cnt, last;
    vector<array<int, size>> child;
    vector<vector<int>> tail;
    constexpr array<int, size> e() {
        array<int, size> x;
        x.fill(-1);
        return x;
    }
    trie() : idx(0), par(1, -1), chr(1, -1), cnt(1, 0), last(0), child(1, e()), tail(1) { child[0].fill(-1); }
    vector<int> insert(const string &s) {
        int n = s.size(), pos = 0;
        vector<int> res(n);
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
            res[i] = pos;
        }
        tail[pos].push_back(idx++);
        last.push_back(pos);
        return res;
    }
};