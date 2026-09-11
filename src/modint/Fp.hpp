#pragma once
#include <array>
#include <cassert>
#include <vector>
using namespace std;
#include "../modint/modint.hpp"
#include "../math/number_theory/constexpr_primality_test.hpp"

// https://maspypy.com/o1-mod-inv-mod-pow 
namespace Fp {

static constexpr int n = 1 << 10;
static constexpr int sz = 1 << 21;

template<int p>
struct container {
    static_assert(constexpr_is_prime(p));
    static_assert((int)1e8 < p && p < (1 << 30));
    using mint = modint<p>;
    inline static array<mint, sz + 1> fac, finv;
    inline static array<mint, 2 * sz + 1> inv;
    inline static array<pair<int, int>, n * n + 1> frac;
    inline static bool built = false;
    static void build_inv() {
        fac[0] = 1;
        for (int i = 1; i <= sz; i++) fac[i] = i * fac[i - 1];
        finv[sz] = fac[sz].inv();
        for (int i = sz; i >= 1; i--) finv[i - 1] = i * finv[i];
        for (int i = 1; i <= sz; i++) {
            inv[sz + i] = finv[i] * fac[i - 1];
            inv[sz - i] = -inv[sz + i];
        }
    }
    static void build_frac() {
        vector<tuple<int, int, int, int>> st;
        st.reserve(2 * n);
        st.emplace_back(0, 1, 1, 1);
        while (st.size()) {
            auto [a, b, c, d] = st.back();
            st.pop_back();
            if (b + d < 2 * n) {
                st.emplace_back(a + c, b + d, c, d);
                st.emplace_back(a, b, a + c, b + d);
            } else {
                int l = (long long)a * p / (b << 10);
                int r = (long long)c * p / (d << 10);
                frac[l] = {a, b};
                frac[r] = {c, d};
                a = min(a, c);
                b = min(b, d);
                for (int i = l + 1; i < r; i++) frac[i] = {a, b};
            }
        }
    }
    static void build() {
        if (built) return;
        built = true;
        build_inv();
        build_frac();
    }
};

template<int p>
int inv(int x) {
    container<p>::build();
    assert(0 < x && x < p);
    auto [c, b] = container<p>::frac[x >> 10];
    int a = (long long)b * x - (long long)c * p;
    return (container<p>::inv[sz + a] * b).val();
}

} // namespace Fp