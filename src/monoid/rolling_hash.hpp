#pragma once
#include <array>
#include <vector>
#include "../math/number_theory/mod_inv.hpp"
using namespace std;

template<typename T>
struct rolling_hash {
    static void set_base(int b) {
        assert(base == -1);
        assert(2 <= b && b <= int(1e9));
        base = b;
        p = (b + (b >> 5)) % 2749;
        q = (b + (b >> 9)) % 274;
    }
    using S = pair<array<long long, 3>, int>;
    static S op(const S &a, const S &b) {
        init(a.second + 1);
        S c;
        for (int j = 0; j < 3; j++) {
            c.first[j] = (a.first[j] + b.first[j] * pow[a.second][j]) % mod[j];
        }
        c.second = a.second + b.second;
        return c;
    }
    constexpr static S e() {
        return make_pair(array<long long, 3>{0, 0, 0,}, 0);
    }
    static S cast(T t) {
        S x;
        x.first.fill(hash(t));
        x.second = 1;
        return x;
    }
private:
    static long long base, p, q;
    static constexpr array<long long, 3> mod = {1000274903LL, 1000274927LL, 1000274953LL};
    static array<long long, 3> inv;
    static vector<array<long long, 3>> pow;
    static void init(int n) {
        assert(base != -1);
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
    static long long hash(const T &t) {
        long long res = static_cast<long long>(t);
        res = (res + (res << 4)) + p;
        res = ((res << 2) ^ (res >> 3)) * q;
        return res;
    }
};
template<typename T>
long long rolling_hash<T>::base(-1);
template<typename T>
long long rolling_hash<T>::p(-1);
template<typename T>
long long rolling_hash<T>::q(-1);
template<typename T>
array<long long, 3> rolling_hash<T>::inv({1, 1, 1});
template<typename T>
vector<array<long long, 3>> rolling_hash<T>::pow(1, {1, 1, 1});