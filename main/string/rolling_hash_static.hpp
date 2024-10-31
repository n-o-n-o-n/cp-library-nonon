#pragma once
#include <array>
#include <cassert>
#include <vector>
using namespace std;

struct rolling_hash {
    static long long base, p, q;
    static array<long long, 3> inv;
    static constexpr array<long long, 3> mod = {1000274903LL, 1000274927LL, 1000274953LL};
    static vector<array<long long, 3>> pow, inv_pow;
    static void set_base(int b) {
        assert(base == -1);
        assert(2 <= b && b <= int(1e9));
        base = b;
        p = (b + (b >> 5)) % 2749;
        q = (b + (b >> 9)) % 274;
        for (int j = 0; j < 3; j++) {
            inv[j] = mod_inv(base, mod[j]);
        }
    }
    rolling_hash(const string &s) {
        assert(base != -1);
        int n = s.size();
        init(n);
        d.resize(n + 1);
        d[0].fill(0);
        for (int i = 0; i < n; i++) {
            long long hs = inner_hash(s[i]);
            for (int j = 0; j < 3; j++) {
                d[i + 1][j] = (d[i][j] + pow[i][j] * hs) % mod[j];
            }
        }
    }
    array<long long, 3> prod(int l, int r) {
        array<long long, 3> res;
        for (int j = 0; j < 3; j++) {
            res[j] = d[r][j] - d[l][j];
            if (res[j] < 0) res[j] += mod[j];
            res[j] = (res[j] * inv_pow[l][j]) % mod[j];
        }
        return res;
    }
private:
    vector<array<long long, 3>> d;
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
                inv_pow[i][j] = (inv_pow[i - 1][j] * inv[j]) % mod[j];
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
vector<array<long long, 3>> rolling_hash::inv_pow(1, {1, 1, 1});