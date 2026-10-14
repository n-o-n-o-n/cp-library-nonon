#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <vector>
#include <array>
#include <numeric>
#include <cstdint>
#include <type_traits>
#include "../../src/modint/modint.hpp"

using mint = modint<998244353>;

namespace AC {
// https://atcoder.jp/contests/abc439/submissions/72457854 

namespace combination {

template<typename mint>
struct container {
    static vector<mint> fac, finv;
    static void init(int n) {
        int sz = fac.size();
        if (n < sz) return;
        n = clamp(n, 2 * sz, min<int>(1 << 27, mint::mod() - 1));
        fac.resize(n + 1);
        finv.resize(n + 1);
        for (int i = sz; i <= n; i++) {
            fac[i] = i * fac[i - 1];
        }
        finv[n] = fac[n].inv();
        for (int i = n; i >= sz; i--) {
            finv[i - 1] = i * finv[i];
        }
    }
};

template<typename mint>
vector<mint> container<mint>::fac(1, 1);
template<typename mint>
vector<mint> container<mint>::finv(1, 1);
template<typename mint>
mint fac(int n) {
    container<mint>::init(n);
    if (n < 0) return 0;
    return container<mint>::fac[n];
}
template<typename mint>
mint finv(int n) {
    container<mint>::init(n);
    if (n < 0) return 0;
    return container<mint>::finv[n];
}
template<typename mint>
mint mod_inv(int n) {
    assert(n > 0);
    return finv<mint>(n) * fac<mint>(n - 1);
}
template<typename mint>
mint nCk(int n, int k) {
    if (n < 0) {
        n = -n;
        return nCk<mint>(n + k - 1, n - 1);
    }
    if (n < k || k < 0) return 0;
    return fac<mint>(n) * finv<mint>(n - k) * finv<mint>(k);
}
template<typename mint>
mint multi_C(const vector<int> &v) {
    int n = 0;
    for (const int &k : v) n += k;
    mint res = fac<mint>(n);
    for (const int &k : v) res *= finv<mint>(k);
    return res;
}
template<typename mint>
mint nPk(int n, int k) {
    if (n < 0 || n < k || k < 0) return 0;
    return fac<mint>(n) * finv<mint>(n - k);
}
template<typename mint>
mint catalan(int n) {
    return fac<mint>(2 * n) * finv<mint>(n) * finv<mint>(n + 1);
}
template<typename mint>
mint grid_path(int n, int m) {
    return nCk<mint>(n + m, n);
}

} // namespace combination

struct dynamic_montgomery_modint {
    using i64 = __uint64_t;
    using i128 = __uint128_t;
    using modint = dynamic_montgomery_modint;
    dynamic_montgomery_modint() : x(0) {}
    dynamic_montgomery_modint(long long v) : x(reduce((i128(v) + MOD) * R)) {}
    static void set_mod(long long _m) {
        MOD = _m;
        R = -i128(MOD) % MOD;
        INV = get_inv_mod(); 
    }
    static long long mod() { return MOD; }
    long long val() const {
        i64 res = reduce(x);
        return res >= MOD ? res - MOD : res;
    }
    modint& operator+=(const modint &r) {
        x += r.x;
        if (x >= (MOD << 1)) x -= (MOD << 1);
        return *this;
    }
    modint& operator-=(const modint &r) {
        x += (MOD << 1) - r.x;
        if (x >= (MOD << 1)) x -= (MOD << 1);
        return *this;
    }
    modint& operator*=(const modint &r) {
        x = reduce(i128(x) * r.x);
        return *this;
    }
    modint& operator/=(const modint &r) {
        *this *= r.inv();
        return *this;
    }
    friend modint operator+(const modint &a, const modint &b) {
        return modint(a) += b;
    }
    friend modint operator-(const modint &a, const modint &b) {
        return modint(a) -= b;
    }
    friend modint operator*(const modint &a, const modint &b) {
        return modint(a) *= b;
    }
    friend modint operator/(const modint &a, const modint &b) {
        return modint(a) /= b;
    }
    friend bool operator==(const modint &a, const modint &b) {
        return a.val() == b.val();
    }
    friend bool operator!=(const modint &a, const modint &b) {
        return a.val() != b.val();
    }
    modint operator+() const { return *this; }
    modint operator-() const { return modint() - *this; }
    modint inv() const { return pow(MOD - 2); }
    modint pow(i128 k) const {
        modint a = *this;
        modint res = 1;
        while (k > 0) {
            if (k & 1) res *= a;
            a *= a;
            k >>= 1;
        }
        return res;
    }
private:
    i64 x;
    static i64 MOD, INV, R;
    static i64 get_inv_mod() {
        i64 res = MOD;
        for (int t = 0; t < 5; t++) res *= 2 - MOD * res;
        return res;
    }
    static i64 reduce(const i128 &v) {
        return (v + i128(i64(v) * i64(-INV)) * MOD) >> 64;
    }
};
typename dynamic_montgomery_modint::i64
dynamic_montgomery_modint::MOD,
dynamic_montgomery_modint::INV,
dynamic_montgomery_modint::R;

template<typename T>
struct xor_shift {
    using U = typename make_unsigned<T>::type;
    constexpr xor_shift(U seed) : x(seed == 0 ? 987139873 : seed) {}
    constexpr U operator()() {
        if constexpr (sizeof(T) <= 4) {
            x ^= x << 13;
            x ^= x >> 17;
            x ^= x << 5;
        } else {
            x ^= x << 13;
            x ^= x >> 7;
            x ^= x << 17;
        }
        return x;
    }
    constexpr T operator()(T low, T hi) {
        return low + (*this)() % (hi - low + 1);
    }
private:
    U x;
};

template<size_t size>
bool miller_rabin(long long m, const array<int, size> &ps) {
    using mint = dynamic_montgomery_modint;
    mint::set_mod(m);
    long long u = 0, v = m - 1;
    while ((v & 1) == 0) u++, v >>= 1;
    for (int p : ps) {
        if (m <= p) return true;
        mint x = mint(p).pow(v);
        if (x.val() != 1) {
            long long w;
            for (w = 0; w < u; w++) {
                if (x.val() == m - 1) break;
                x *= x;
            }
            if (w == u) return false;
        }
    }
    return true;
}

bool miller_rabin_small(long long m) {
    return miller_rabin(m, array<int, 3>{2, 7, 61});
}

bool miller_rabin_large(long long m) {
    return miller_rabin(m, array<int, 7>{2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

bool is_prime(long long m) {
    if (m <= 1) return false;
    if (m == 2) return true;
    if (m % 2 == 0) return false;
    return m < 4759123141LL ? miller_rabin_small(m) : miller_rabin_large(m);
}

template<typename T>
T rho(T n) {
    for (int p : {2, 3, 5, 7}) {
        if (n % p == 0) return p;
    }
    using mint = dynamic_montgomery_modint;
    mint::set_mod(n);
    xor_shift<T> eng(n);
    while (true) {
        mint u = eng(2, n - 1);
        mint v = u;
        mint c = eng(1, n - 1);
        T d = 1;
        while (d == 1) {
            u = u * u - c;
            v = v * v - c;
            v = v * v - c;
            d = gcd((u - v).val(), n);
        }
        if (d < n) return d;
    }
    return -1;
}

template<typename T>
vector<T> prime_factor(T n) {
    if (n <= 1) return {};
    if (is_prime(n)) return {n};
    vector<T> res;
    T d = rho(n);
    auto a = prime_factor(d);
    auto b = prime_factor(n / d);
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}

long long primitive_root(long long m) {
    assert(is_prime(m));
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    if (m == 1224736769) return 3;
    auto ps = prime_factor(m - 1);
    using mint = dynamic_montgomery_modint;
    mint::set_mod(m);
    xor_shift<unsigned long long> eng(m);
    mint a = eng(1, m - 1);
    while ([&] {
        for (auto p : ps) {
            if (a.pow((m - 1) / p) == 1) return true;
        }
        return false;
    } ()) a = eng(1, m - 1);
    return a.val();
}

template<typename mint>
struct Number_Theoretic_Transform {
    static mint get_root() {
        init();
        return root;
    }
    template<typename Vector>
    static void ntt(Vector &f) {
        init();
        int n = f.size();
        assert((n & (n - 1)) == 0);
        int h = 0;
        while ((1 << h) < n) h++;
        int len = 0;
        while (len < h) {
            if (len == h - 1) {
                int p = 1 << (h - len - 1);
                mint r = 1;
                for (int s = 0; s < 1 << len; s++) {
                    int j = s << (h - len);
                    for (int i = 0; i < p; i++) {
                        mint a = f[i + j], b = f[i + j + p] * r;
                        f[i + j] = a + b;
                        f[i + j + p] = a - b;
                    }
                    if (s + 1 != (1 << len)) {
                        r *= rt2[__builtin_ctz(~s)];
                    }
                }
                len++;
            } else {
                int p = 1 << (h - len - 2);
                mint r = 1, imag = dw[2];
                for (int s = 0; s < 1 << len; s++) {
                    mint r2 = r * r;
                    mint r3 = r * r2;
                    int j = s << (h - len);
                    for (int i = 0; i < p; i++) {
                        unsigned long long m2 = (unsigned long long)mod * mod;
                        unsigned long long a0 = (unsigned long long)f[i + j].val();
                        unsigned long long a1 = (unsigned long long)f[i + j + p].val() * r.val();
                        unsigned long long a2 = (unsigned long long)f[i + j + p + p].val() * r2.val();
                        unsigned long long a3 = (unsigned long long)f[i + j + p + p + p].val() * r3.val();
                        unsigned long long t0 = (unsigned long long)mint(m2 + a1 - a3).val() * imag.val();
                        unsigned long long t1 = m2 - a2;
                        f[i + j] = a0 + a1 + a2 + a3;
                        f[i + j + p] = a0 + a2 + (m2 + m2 - a1 - a3);
                        f[i + j + p + p] = a0 + t0 + t1;
                        f[i + j + p + p + p] = a0 + t1 + (m2 - t0);
                    }
                    if (s + 1 != (1 << len)) {
                        r *= rt3[__builtin_ctz(~s)];
                    }
                }
                len += 2;
            }
        }
    }
    template<typename Vector>
    static void intt(Vector &f) {
        init();
        int n = f.size();
        assert((n & (n - 1)) == 0);
        int h = 0;
        while ((1 << h) < n) h++;
        int len = h;
        while (len > 0) {
            if (len == 1) {
                len--;
                int p = 1 << (h - len - 1);
                mint ir = 1;
                for (int s = 0; s < 1 << len; s++) {
                    int j = s << (h - len);
                    for (int i = 0; i < p; i++) {
                        mint a = f[i + j], b = f[i + j + p];
                        f[i + j] = a + b;
                        f[i + j + p] = (a - b) * ir;
                    }
                    if (s + 1 != (1 << len)) {
                        ir *= irt2[__builtin_ctz(~s)];
                    }
                }
            } else {
                len -= 2;
                int p = 1 << (h - len - 2);
                mint ir = 1, iimag = idw[2];
                for (int s = 0; s < 1 << len; s++) {
                    mint ir2 = ir * ir;
                    mint ir3 = ir * ir2;
                    int j = s << (h - len);
                    for (int i = 0; i < p; i++) {
                        unsigned long long a0 = (unsigned long long)f[i + j].val();
                        unsigned long long a1 = (unsigned long long)f[i + j + p].val();
                        unsigned long long a2 = (unsigned long long)f[i + j + p + p].val();
                        unsigned long long a3 = (unsigned long long)f[i + j + p + p + p].val();
                        unsigned long long t0 = (unsigned long long)(mint(mod + a2 - a3) * iimag).val();
                        f[i + j] = a0 + a1 + a2 + a3;
                        f[i + j + p] = (mod + a0 - a1 + t0) * ir.val();
                        f[i + j + p + p] = (mod + mod + a0 + a1 - a2 - a3) * ir2.val();
                        f[i + j + p + p + p] = (mod + mod + a0 - a1 - t0) * ir3.val();
                    }
                    if (s + 1 != (1 << len)) {
                        ir *= irt3[__builtin_ctz(~s)];
                    }
                }
            }
        }
        const mint invn = mint::raw(n).inv();
        for (auto &e : f) e *= invn;
    }
    // f must be ntt-ed
    template<typename Vector>
    static void doubling(Vector &f) {
        init();
        int n = f.size();
        if (n == 0) return;
        assert((n & (n - 1)) == 0);
        auto g = f;
        intt(g);
        mint w = root.pow((mint::mod() - 1) / (2 * n)), pw = mint::raw(1);
        for (int i = 0; i < n; i++) g[i] *= pw, pw *= w;
        ntt(g);
        f.resize(2 * n);
        for (int i = 0; i < n; i++) f[i + n] = g[i];
    }
private:
    Number_Theoretic_Transform() = default;
    static int log, mod;
    static mint root;
    static vector<mint> dw, idw;
    static vector<mint> rt2, irt2;
    static vector<mint> rt3, irt3;
    static void init() {
        if (mod != -1) return;
        mod = mint::mod();
        root = primitive_root(mod);
        while (!((mod - 1) >> log & 1)) log++;
        dw = idw = rt2 = irt2 = rt3 = irt3 = vector<mint>(log + 1);
        dw[log] = root.pow((mod - 1) >> log);
        idw[log] = dw[log].inv();
        for (int i = log - 1; i >= 0; i--) {
            dw[i] = dw[i + 1] * dw[i + 1];
            idw[i] = idw[i + 1] * idw[i + 1];
        }
        mint pd = 1, ipd = 1;
        for (int i = 0; i < log - 1; i++) {
            rt2[i] = pd * dw[i + 2];
            irt2[i] = ipd * idw[i + 2];
            pd *= idw[i + 2];
            ipd *= dw[i + 2];
        }
        pd = ipd = 1;
        for (int i = 0; i < log - 2; i++) {
            rt3[i] = pd * dw[i + 3];
            irt3[i] = ipd * idw[i + 3];
            pd *= idw[i + 3];
            ipd *= dw[i + 3];
        }
    }
};
template<typename mint>
int Number_Theoretic_Transform<mint>::log = 0;
template<typename mint>
int Number_Theoretic_Transform<mint>::mod = -1;
template<typename mint>
mint Number_Theoretic_Transform<mint>::root = -1;
template<typename mint>
vector<mint> Number_Theoretic_Transform<mint>::dw = vector<mint>();
template<typename mint>
vector<mint> Number_Theoretic_Transform<mint>::idw = vector<mint>();
template<typename mint>
vector<mint> Number_Theoretic_Transform<mint>::rt2 = vector<mint>();
template<typename mint>
vector<mint> Number_Theoretic_Transform<mint>::irt2 = vector<mint>();
template<typename mint>
vector<mint> Number_Theoretic_Transform<mint>::rt3 = vector<mint>();
template<typename mint>
vector<mint> Number_Theoretic_Transform<mint>::irt3 = vector<mint>();

template<typename mint>
struct fps : vector<mint> {
    using vector<mint>::vector;
    using NTT = Number_Theoretic_Transform<mint>;
    void ntt() { NTT::ntt(*this); }
    void intt() { NTT::intt(*this); }
    fps(const vector<mint> &v) : vector<mint>(v) {}
    fps &operator+=(const mint &r) {
        if (this->empty()) this->resize(1);
        (*this)[0] += r;
        return *this;
    }
    fps &operator-=(const mint &r) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= r;
        return *this;
    }
    fps &operator*=(const mint &r) {
        for (mint &x : *this) x *= r;
        return *this;
    }
    fps &operator/=(const mint &r) {
        mint invr = r.inv();
        return *this *= invr;
    }
    fps &operator+=(const fps &f) {
        int n = this->size(), m = f.size();
        if (n < m) this->resize(m);
        for (int i = 0; i < m; i++) (*this)[i] += f[i];
        return *this;
    }
    fps &operator-=(const fps &f) {
        int n = this->size(), m = f.size();
        if (n < m) this->resize(m);
        for (int i = 0; i < m; i++) (*this)[i] -= f[i];
        return *this;
    }
    fps &operator*=(fps f) {
        int n = this->size(), m = f.size();
        if (n == 0 || m == 0) {
            this->clear();
            return *this;
        }
        int sz = 1;
        while (sz < n + m - 1) sz <<= 1;
        this->resize(sz);
        this->ntt();
        f.resize(sz);
        f.ntt();
        for (int i = 0; i < sz; i++) (*this)[i] *= f[i];
        this->intt();
        this->resize(n + m - 1);
        return *this;
    }
    fps &operator/=(const fps &f) {
        return *this *= f.inv();
    }
    fps &operator%=(const fps &f) {
        *this -= div(f) * f;
        this->shrink();
        return *this;
    }
    fps div(const fps &f) const {
        if (this->size() < f.size()) return fps{};
        int n = this->size() - f.size() + 1;
        return (rev().pre(n) * f.rev().inv(n)).pre(n).rev(n);
    }
    fps operator+(const mint &r) const { return fps(*this) += r; }
    fps operator-(const mint &r) const { return fps(*this) -= r; }
    fps operator*(const mint &r) const { return fps(*this) *= r; }
    fps operator/(const mint &r) const { return fps(*this) /= r; }
    friend fps operator+(const mint &r, const fps &f) { return f + r; }
    friend fps operator-(const mint &r, const fps &f) { return (-f) + r; }
    friend fps operator*(const mint &r, const fps &f) { return f * r; }
    fps operator+(const fps &f) const { return fps(*this) += f; }
    fps operator-(const fps &f) const { return fps(*this) -= f; }
    fps operator*(const fps &f) const { return fps(*this) *= f; }
    fps operator/(const fps &f) const { return fps(*this) /= f; }
    fps operator%(const fps &f) const { return fps(*this) %= f; }
    fps operator-() const {
        return fps{} - *this;
    }
    fps operator<<(int n) const {
        fps res(*this);
        res.insert(res.begin(), n, mint());
        return res;
    }
    fps operator>>(int n) const {
        if (int(this->size()) <= n) return fps{};
        fps res(*this);
        res.erase(res.begin(), res.begin() + n);
        return res;
    }
    fps &operator<<=(int n) {
        return *this = (*this) << n;
    }
    fps &operator>>=(int n) {
        return *this = (*this) >> n;
    }
    fps pre(int n) const {
        n = min(n, int(this->size()));
        return fps(this->begin(), this->begin() + n);
    }
    fps rev(int deg = -1) const {
        fps res(*this);
        if (deg != -1) res.resize(deg, 0);
        reverse(res.begin(), res.end());
        return res;
    }
    fps dot(const fps &f) const {
        int n = min(this->size(), f.size());
        fps res(n);
        for (int i = 0; i < n; i++) res[i] = (*this)[i] * f[i];
        return res;
    }
    void shrink() {
        while (this->size() && this->back() == 0) {
            this->pop_back();
        }
    }
    mint operator()(const mint &x) const {
        mint res = 0, powx = 1;
        for (const mint &a : *this) {
            res += a * powx;
            powx *= x;
        }
        return res;
    }
    fps diff() const {
        int n = this->size();
        if (n == 0) return fps{};
        fps res(n - 1);
        for (int i = 1; i < n; i++) {
            res[i - 1] = i * (*this)[i];
        }
        return res;
    }
    fps integral() const {
        int n = this->size();
        fps res(n + 1);
        res[0] = 0;
        for (int i = 0; i < n; i++) {
            res[i + 1] = (*this)[i] * combination::mod_inv<mint>(i + 1);
        }
        return res;
    }
    fps inv(int deg = -1) const;
    fps exp(int deg = -1) const;
    fps log(int deg = -1) const;
    fps pow(long long k, int deg = -1) const;
    fps operator()(fps f, int deg = -1) const;
    fps compositional_inverse(int deg = -1) const;
    fps taylor_shift(mint c) const;
};

template<typename mint>
fps<mint> fps<mint>::inv(int deg) const {
    int n = this->size();
    assert(n > 0);
    mint c = (*this)[0];
    assert(c != 0);
    if (deg == -1) deg = n;
    fps res(deg);
    res[0] = c.inv();
    for (int d = 1; d < deg; d <<= 1) {
        fps f(d << 1), g(d << 1);
        for (int i = 0; i < n && i < d << 1; i++) f[i] = (*this)[i];
        for (int i = 0; i < d; i++) g[i] = res[i];
        f.ntt();
        g.ntt();
        for (int i = 0; i < d << 1; i++) f[i] *= g[i];
        f.intt();
        for (int i = 0; i < d; i++) f[i] = 0;
        f.ntt();
        for (int i = 0; i < d << 1; i++) f[i] *= g[i];
        f.intt();
        for (int i = d; i < deg && i < d << 1; i++) res[i] -= f[i];
    }
    return res;
}

// enumerate [x^n](f^k)g for k = 0,1,...,m-1
template<typename mint>
fps<mint> power_projection(fps<mint> f, fps<mint> g, int n, int m) {
    f.resize(n + 1);
    g.resize(n + 1);
    int k = 1, len = 1;
    while (len <= n) len *= 2;
    fps<mint> p(n + 1), q(n + 1), np, nq, bf;
    for (int i = 0; i <= n; i++) p[i] = g[i], q[i] = -f[i];
    q[0]++;
    const mint inv2 = mint::raw(2).inv();
    for (; n > 0; n /= 2, len /= 2, k *= 2) {
        np.clear();
        nq.clear();
        for (int i = 0; i <= n; i++) {
            bf.resize(k);
            copy(p.begin() + i * k, p.begin() + i * k + k, bf.begin());
            fps<mint>::NTT::doubling(bf);
            copy(bf.begin(), bf.end(), back_inserter(np));
            bf.resize(k);
            copy(q.begin() + i * k, q.begin() + i * k + k, bf.begin());
            if (i == 0) {
                for (int j = 0; j < k; j++) bf[j]--;
                fps<mint>::NTT::doubling(bf);
                for (int j = 0; j < k; j++) bf[j]++, bf[j + k]--;
            } else {
                fps<mint>::NTT::doubling(bf);
            }
            copy(bf.begin(), bf.end(), back_inserter(nq));
        }
        np.resize(4 * len * k);
        nq.resize(4 * len * k);
        fps<mint> tp(2 * len), tq(2 * len);
        mint w = fps<mint>::NTT::get_root().pow((mint::mod() - 1) / (2 * len));
        mint iw = w.inv();
        vector<int> btr;
        if (n & 1) {
            btr.resize(len);
            int lg = __builtin_ctz(len) - 1;
            for (int i = 0; i < len; i++) btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << lg);
        }
        for (int j = 0; j < 2 * k; j++) {
            tp.assign(2 * len, mint::raw(0));
            tq.assign(2 * len, mint::raw(0));
            for (int i = 0; i < len; i++) {
                tp[i] = np[2 * i * k + j];
                tq[i] = nq[2 * i * k + j];
            }
            tp.ntt();
            tq.ntt();
            for (int i = 0; i < 2 * len; i++) {
                if (!(i & 1)) swap(tq[i], tq[i + 1]);
                tp[i] *= tq[i];
            }
            for (int i = 0; i < len; i++) tq[i] = tq[2 * i] * tq[2 * i + 1];
            if (n & 1) {
                mint c = inv2;
                bf.resize(len);
                for (int i : btr) {
                    bf[i] = (tp[2 * i] - tp[2 * i + 1]) * c;
                    c *= iw;
                }
                swap(tp, bf);
            } else {
                for (int i = 0; i < len; i++) tp[i] = (tp[2 * i] + tp[2 * i + 1]) * inv2;
            }
            tp.resize(len);
            tq.resize(len);
            tp.intt();
            tq.intt();
            for (int i = 0; i < len; i++) {
                np[2 * i * k + j] = tp[i];
                nq[2 * i * k + j] = tq[i];
            }
        }
        np.resize(2 * k * (n / 2 + 1));
        nq.resize(2 * k * (n / 2 + 1));
        swap(p, np);
        swap(q, nq);
    }
    fps<mint> s(p.begin(), p.begin() + k), t(q.begin(), q.begin() + k);
    s.intt();
    t.intt();
    t[0]--;
    if (t[0] == 0) return s.rev().pre(m);
    auto F = (t + (fps<mint>{1} << k)).rev();
    return (s.rev() * (t + (fps<mint>{1} << k)).rev().inv(m)).pre(m);
}

template<typename mint>
fps<mint> rational_sum(const vector<fps<mint>> &ps, const vector<fps<mint>> &qs, int deg = -1) {
    assert(ps.size() == qs.size());
    if (ps.empty()) return {};
    auto rec = [&] (const auto &rec, int l, int r) -> pair<fps<mint>, fps<mint>> {
        if (l + 1 == r) return {ps[l], qs[l]};
        int m = (l + r) / 2;
        auto [pl, ql] = rec(rec, l, m);
        auto [pr, qr] = rec(rec, m, r);
        int sz_p = max(pl.size() + qr.size(), pr.size() + ql.size()) - 1;
        int sz_q = ql.size() + qr.size() - 1;
        int sz = 1;
        while (sz < max(sz_p, sz_q)) sz <<= 1;
        if (sz < 64) {
            fps<mint> p(sz_p), q(sz_q);
            for (int i = 0; i < ssize(pl); i++) {
                for (int j = 0; j < ssize(qr); j++) p[i + j] += pl[i] * qr[j];
            }
            for (int i = 0; i < ssize(pr); i++) {
                for (int j = 0; j < ssize(ql); j++) p[i + j] += pr[i] * ql[j];
            }
            for (int i = 0; i < ssize(ql); i++) {
                for (int j = 0; j < ssize(qr); j++) q[i + j] += ql[i] * qr[j];
            }
            return {p, q};
        } else {
            pl.resize(sz);
            ql.resize(sz);
            pr.resize(sz);
            qr.resize(sz);
            pl.ntt();
            ql.ntt();
            pr.ntt();
            qr.ntt();
            for (int i = 0; i < sz; i++) {
                pl[i] = pl[i] * qr[i] + pr[i] * ql[i];
                ql[i] = ql[i] * qr[i];
            }
            pl.intt();
            ql.intt();
            pl.resize(min(deg == -1 ? numeric_limits<int>::max() : deg, sz_p));
            ql.resize(min(deg == -1 ? numeric_limits<int>::max() : deg, sz_q));
        }
        return {pl, ql};
    };
    auto [p, q] = rec(rec, 0, ps.size());
    if (deg != -1) {
        p.resize(deg);
        q.resize(deg);
    }
    return p /= q;
}

vector<mint> solve(int N, int M, int L, vector<int> oriA) {
    vector<mint> P;
    {
        fps<mint> f(N + 1), g(N + 1, mint::raw(1));
        const mint invM = mint::raw(M).inv();
        for (int i = 0; i < M; i++) {
            f[oriA[i]] = invM;
        }
        g[0] = mint();
        P = power_projection<mint>(f, g, N, N);
        P.push_back(mint());
    }
    vector<fps<mint>> A, B;
    A.reserve(N), B.reserve(N);
    for (int i = 0; i <= N; i++) {
        if (P[i] == 0) break;
        A.push_back({P[i].pow(L - 1) * (P[i] - P[i + 1])});
        B.push_back({1, -P[i + 1] / P[i]});
    }
    auto ans = rational_sum(A, B, L);
    return vector<mint> (ans.begin(), ans.begin() + L);
}

} // namespace AC

#include "../../src/fps/power_projection.hpp"
#include "../../src/fps/rational_sum.hpp"
#include "../../src/random/sequence.hpp"
#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    {
        int A, B;
        cin >> A >> B;
        cout << A + B << '\n';
    }
    for (int t = 0; t < 20; t++) {
        auto [M, N] = rng::randpair(1, (int)1e5);
        int L = rng::randint(2, (int)1e5);
        auto oriA = rng::random_increasing_sequence(M, 1, N, true);
        vector<mint> P;
        {
            fps<mint> f(N + 1), g(N + 1, mint::raw(1));
            const mint invM = mint::raw(M).inv();
            for (int i = 0; i < M; i++) {
                f[oriA[i]] = invM;
            }
            g[0] = mint();
            P = power_projection<mint>(f, g, N, N);
            P.push_back(mint());
        }
        vector<fps<mint>> A, B;
        A.reserve(N), B.reserve(N);
        for (int i = 0; i <= N; i++) {
            if (P[i] == 0) break;
            A.push_back({P[i].pow(L - 1) * (P[i] - P[i + 1])});
            B.push_back({1, -P[i + 1] / P[i]});
        }
        auto ans = rational_sum(A, B, L);
        assert(vector<mint>(ans.begin(), ans.begin() + L) == AC::solve(N, M, L, oriA));
    }
}