#pragma once
#include <array>
#include <cassert>
#include <queue>
#include <vector>
using namespace std;

template<int size, char base>
struct aho_corasick {
    aho_corasick() : par(1, 0), chr(1, -1), last(0), fail(1, 0), cnt(1, 0), child(1, e()), built(false) {}
    void insert(const string &s) {
        int n = s.size(), pos = 0;
        for (int i = 0; i < n; i++) {
            int c = s[i] - base;
            if (child[pos][c] == -1) {
                child[pos][c] = par.size();
                par.push_back(pos);
                chr.push_back(c);
                fail.push_back(0);
                cnt.push_back(0);
                child.push_back(e());
            }
            pos = child[pos][c];
        }
        cnt[pos]++;
        last.push_back(pos);
    }
    void build() {
        queue<int> q;
        for (int i = 0; i < size; i++) {
            int &nxt = child[0][i];
            if (nxt != -1) {
                fail[nxt] = 0;
                q.push(nxt);
            } else {
                nxt = 0;
            }
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            cnt[u] += cnt[fail[u]];
            for (int i = 0; i < size; i++) {
                int &nxt = child[u][i];
                int p = child[fail[u]][i];
                if (nxt != -1) {
                    fail[nxt] = p;
                    q.push(nxt);
                } else {
                    nxt = p;
                }
            }
        }
        built = true;
    }
    template<typename T = int>
    T match(const string &s) const {
        assert(built);
        int n = s.size(), pos = 0;
        T res = 0;
        for (int i = 0; i < n; i++) {
            int c = s[i] - base;
            pos = child[pos][c];
            res += cnt[pos];
        }
        return res;
    }
// private:
    vector<int> par, chr, last, fail, cnt;
    vector<array<int, size>> child;
    bool built;
    constexpr array<int, size> e() {
        array<int, size> x;
        x.fill(-1);
        return x;
    }
};