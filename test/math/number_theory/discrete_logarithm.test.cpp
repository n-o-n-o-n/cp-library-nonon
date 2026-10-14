#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../src/random/utility.hpp"
#include "../../../src/math/number_theory/primality_test.hpp"
#include "../../../src/modint/dynamic_modint.hpp"
#include "../../../src/math/affine.hpp"
#include "../../../src/math/number_theory/discrete_logarithm.hpp"

using mint = modint;

#include <iostream>

// https://atcoder.jp/contests/abc270/submissions/62690414
namespace AC {

template<typename mint>
struct affine {
    mint a, b;
    affine() : a(1), b(0) {}
    affine(const mint &_a, const mint &_b) : a(_a), b(_b) {}
    mint operator()(const mint &x) const {
        return a * x + b;
    }
    affine operator()(const affine &f) const {
        mint c = a * f.a;
        mint d = a * f.b + b;
        return affine(c, d);
    }
};

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

struct ActSet {
    using S = mint;
    using F = affine<mint>;
    static F comp(F f, F g) {
        return f(g);
    }
    static F id() {
        return F();
    }
    static S mapping(F f, S x) {
        return f(x);
    }
};

long long solve(int P, int A, int B, int S, int T) {
    mint::set_mod(P);
    return discrete_logarithm<ActSet>::solve(affine<mint>(A, B), S, T, P, [&](mint x){ return x.val(); });
}

} // namespace AC

struct ActSet {
    using S = mint;
    using F = affine<mint>;
    static F comp(F f, F g) {
        return f(g);
    }
    static F id() {
        return F();
    }
    static S mapping(F f, S x) {
        return f(x);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    {
        int A, B;
        cin >> A >> B;
        cout << A + B << '\n';
    }
    for (int t = 0; t < 200; t++) {
        int P = rng::randint(2, (int)1e9);
        while (!is_prime(P)) P = rng::randint(2, (int)1e9);
        int A = rng::randint(0, P - 1);
        int B = rng::randint(0, P - 1);
        int S = rng::randint(0, P - 1);
        int T = rng::randint(0, P - 1);
        mint::set_mod(P);
        auto ans = discrete_logarithm<ActSet>::solve(affine<mint>(A, B), S, T, P, [&](mint x){ return x.val(); });
        assert(ans == AC::solve(P, A, B, S, T));
    }
}