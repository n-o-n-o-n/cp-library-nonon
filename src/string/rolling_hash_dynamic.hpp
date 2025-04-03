#pragma once
#include <array>
#include <cassert>
#include <vector>
#include "../data_structure/segtree/segtree.hpp"
using namespace std;

struct rolling_hash {
    static long long base, p, q;
    static array<long long, 3> inv;
    static constexpr array<long long, 3> mod = {1000274903LL, 1000274927LL, 1000274953LL};
    static vector<array<long long, 3>> pow;
    static void set_base(int b) {
        assert(base == -1);
        assert(2 <= b && b <= int(1e9));
        base = b;
        p = (b + (b >> 5)) % 2749;
        q = (b + (b >> 9)) % 274;
    }
    rolling_hash(const string &s) {
        assert(base != -1);
        int n = s.size();
        init(n);
        vector<pair<array<long long, 3>, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i].first.fill(inner_hash(s[i]));
            v[i].second = 1;
        }
        d = segtree<Monoid>(v);
    }
    void set(int p, char c) {
        array<long long, 3> x;
        x.fill(inner_hash(c));
        d.set(p, make_pair(x, 1));
    }
    array<long long, 3> prod(int l, int r) {
        return d.prod(l, r).first;
    }
private:
    struct Monoid {
        using S = pair<array<long long, 3>, int>;
        static S op(const S &a, const S &b) {
            S c;
            for (int j = 0; j < 3; j++) {
                c.first[j] = (a.first[j] + b.first[j] * pow[a.second][j]) % mod[j];
            }
            c.second = a.second + b.second;
            return c;
        }
        static S e() {
            return make_pair(array<long long, 3>{0, 0, 0,}, 0);
        }
    };
    segtree<Monoid> d;
    static long long mod_inv(long long x, long long m) {
        long long a = x, r = 1, k = m - 2;
        while (k > 0) {
            if (k & 1) r = (r * a) % m;
            a = (a * a) % m;
            k >>= 1;
        }
        return r;
    }
    static void init(int n) {
        int sz = pow.size();
        if (n + 1 < sz) return;
        n = max(n + 1, 2 * sz);
        pow.resize(n);
        for (int i = sz; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                pow[i][j] = (pow[i - 1][j] * base) % mod[j];
            }
        }
    }
    long long inner_hash(const char &c) const {
        int res = static_cast<int>(c);
        res = (res + (res << 4)) + p;
        res = ((res << 2) ^ (res >> 3)) * q;
        return res;
    }
};
long long rolling_hash::base(-1);
long long rolling_hash::p(-1);
long long rolling_hash::q(-1);
array<long long, 3> rolling_hash::inv({1, 1, 1});
vector<array<long long, 3>> rolling_hash::pow(1, {1, 1, 1});