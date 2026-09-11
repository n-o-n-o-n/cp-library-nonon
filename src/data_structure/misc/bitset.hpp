#pragma once
#include <bit>
#include <cassert>
#include <vector>
using namespace std;

struct BitSet {
    using ull = unsigned long long;
    BitSet() = default;
    BitSet(int _n) : n(_n), m((_n + 63) >> 6) {
        d = vector<ull>(m);
    }
    size_t size() const { return n; }
    BitSet &operator|=(const BitSet &a) {
        assert(size() == a.size());
        for (int i = 0; i < m; i++) d[i] |= a.d[i];
        return *this;
    }
    BitSet &operator^=(const BitSet &a) {
        assert(size() == a.size());
        for (int i = 0; i < m; i++) d[i] ^= a.d[i];
        return *this;
    }
    BitSet &operator&=(const BitSet &a) {
        assert(size() == a.size());
        for (int i = 0; i < m; i++) d[i] &= a.d[i];
        return *this;
    }
    BitSet &operator<<=(int k) {
        if (k == 0) return *this;
        int q = k >> 6, r = k & 63;
        if (r == 0) {
            for (int i = m - 1; i >= q; i--) d[i] = d[i - q];
        } else {
            int s = 64 - r;
            for (int i = m - 1; i > q; i--) {
                d[i] = (d[i - q] << r) ^ (d[i - q - 1] >> s);
            }
            d[q] = d[0] << r;
        }
        d[m - 1] &= mask();
        for (int i = 0; i < q; i++) d[i] = 0;
        return *this;
    }
    BitSet &operator>>=(int k) {
        if (k == 0) return *this;
        int q = k >> 6, r = k & 63;
        if (r == 0) {
            for (int i = 0; i + q < m; i++) d[i] = d[i + q];
        } else {
            int s = 64 - r;
            for (int i = 0; i + q + 1 < m; i++) {
                d[i] = (d[i + q] >> r) ^ (d[i + q + 1] << s);
            }
            d[m - q - 1] = d[m - 1] >> r;
        }
        for (int i = m - q; i < m; i++) d[i] = 0;
        return *this;
    }
    void flip() {
        for (auto &b : d) b = ~b;
        d[m - 1] &= mask();
    }
    BitSet operator|(const BitSet &a) const { return BitSet(*this) |= a; }
    BitSet operator^(const BitSet &a) const { return BitSet(*this) ^= a; }
    BitSet operator&(const BitSet &a) const { return BitSet(*this) &= a; }
    BitSet operator<<(int k) const { return BitSet(*this) <<= k; }
    BitSet operator>>(int k) const { return BitSet(*this) >>= k; }
    BitSet operator~() const {
        BitSet r(*this);
        r.flip();
        return r;
    }
    bool operator[](int p) const {
        assert(0 <= p && p < n);
        return d[p >> 6] >> (p & 63) & 1;
    }
    bool operator==(const BitSet &a) const { return n == a.n && d == a.d; }
    bool operator!=(const BitSet &a) const { return n != a.n || d != a.d; }
    int count() const {
        int c = 0;
        for (auto b : d) c += popcount(b);
        return c;
    }
    void set(int p) {
        assert(0 <= p && p < n);
        d[p >> 6] |= 1ULL << (p & 63);
    }
    void reset(int p) {
        assert(0 <= p&& p < n);
        d[p >> 6] &= ~(1ULL << (p & 63));
    }
    bool test(int p) const {
        assert(0 <= p && p < n);
        return d[p >> 6] >> (p & 63) & 1;
    }
    bool any() const {
        for (auto b : d) {
            if (b != 0) return true;
        }
        return false;
    }
    bool all() const {
        for (int i = 0; i < m - 1; i++) {
            if (d[i] != ~0ULL) return false;
        }
        return d[m - 1] == mask();
    }
    bool none() const { return !any(); }
private:
    int n, m;
    vector<ull> d;
    ull mask() const {
        if (((n >> 6) << 6) == n) return ~0ULL;
        return (1ULL << (n & 63)) - 1;
    }
};