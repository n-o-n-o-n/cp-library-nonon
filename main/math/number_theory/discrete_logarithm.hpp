#pragma once
#include <unordered_set>
using namespace std;

template<typename ActSet>
struct discrete_logarithm {
    using S = typename ActSet::S;
    using F = typename ActSet::F;
    template<typename H>
    static long long solve(F f, S s, S t, long long p, const H &h) {
        long long ht = h(t);
        long long m = 1;
        do {
            m++;
        } while (m * m <= p);
        unordered_set<long long> a;
        a.reserve(m);
        for (int k = 0; k < m; k++) {
            t = ActSet::mapping(f, t);
            a.insert(h(t));
        }
        F g = ActSet::id();
        {
            long long mm = m;
            F ff = f;
            while (m > 0) {
                if (m & 1) g = ActSet::comp(g, f);
                f = ActSet::comp(f, f);
                m >>= 1;
            }
            m = mm;
            f = ff;
        }
        for (int k = 0, flag = 0; k <= m; k++) {
            t = ActSet::mapping(g, s);
            if (a.count(h(t))) {
                for (int i = 0; i < m; i++) {
                    if (h(s) == ht) {
                        return m * k + i;
                    }
                    s = ActSet::mapping(f, s);
                }
                if (flag) return -1;
                flag = 1;
            }
            s = t;
        }
        return -1;
    }
};