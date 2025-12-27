#pragma once
#include <vector>
#include "../math/enumerative_combinatorics/combination.hpp"
#include "../convolution/ntt.hpp"
using namespace std;

template<typename mint>
struct Formal_Power_Series : vector<mint> {
    using fps = Formal_Power_Series;
    using vector<mint>::vector;
    using NTT = Number_Theoretic_Transform<mint>;
    void ntt() { NTT::ntt(*this); }
    void intt() { NTT::intt(*this); }
    Formal_Power_Series(const vector<mint> &v) : vector<mint>(v) {}
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
    fps &operator*=(const fps &f) {
        *this = convolution(*this, f);
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
    fps inv(int deg = -1) const {
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
            f = f.dot(g);
            f.intt();
            for (int i = 0; i < d; i++) f[i] = 0;
            f.ntt();
            f = f.dot(g);
            f.intt();
            for (int i = d; i < deg && i < d << 1; i++) res[i] -= f[i];
        }
        return res;
    }
    fps exp(int deg = -1) const {
        int n = this->size();
        if (deg == -1) deg = n;
        if (n == 0) {
            fps res(deg);
            res[0] = 1;
            return res;
        }
        assert((*this)[0] == 0);
        auto inplace_diff = [](fps &f) -> void {
            if (f.empty()) return;
            f.erase(f.begin());
            for (int i = 0; i < int(f.size()); i++) f[i] *= i + 1;
        };
        auto inplace_integral = [&](fps &f) -> void {
            f.insert(f.begin(), 0);
            for (int i = 1; i < int(f.size()); i++) f[i] *= combination::mod_inv<mint>(i);
        };
        fps b = {1, 1 < n ? (*this)[1] : 0};
        fps c = {1}, z1, z2 = {1, 1};
        for (int d = 2; d < deg; d <<= 1) {
            fps y = b;
            y.resize(d << 1);
            y.ntt();
            z1 = z2;
            fps z = y.dot(z1);
            z.intt();
            fill(z.begin(), z.begin() + (d >> 1), 0);
            z.ntt();
            z = z.dot(-z1);
            z.intt();
            c.insert(c.end(), z.begin() + (d >> 1), z.end());
            z2 = c;
            z2.resize(d << 1);
            z2.ntt();
            fps x(this->begin(), this->begin() + min(n, d));
            inplace_diff(x);
            x.push_back(0);
            x.ntt();
            x = x.dot(y);
            x.intt();
            x -= b.diff();
            x.resize(d << 1);
            for (int i = 0; i < d - 1; i++) x[i + d] = x[i], x[i] = 0;
            x.ntt();
            x = x.dot(z2);
            x.intt();
            x.pop_back();
            inplace_integral(x);
            for (int i = d; i < min(n, d << 1); i++) x[i] += (*this)[i];
            fill(x.begin(), x.begin() + d, 0);
            x.ntt();
            x = x.dot(y);
            x.intt();
            b.insert(b.end(), x.begin() + d, x.end());
        }
        return fps(b.begin(), b.begin() + deg);
    }
    fps log(int deg = -1) const {
        assert((*this)[0] == 1);
        if (deg == -1) deg = this->size();
        return (diff() * inv()).integral().pre(deg);
    }
    fps pow(long long k, int deg = -1) const {
        if (deg == -1) deg = this->size();
        if (k == 0) {
            fps res(deg);
            res[0] = 1;
            return res;
        }
        fps res(*this);
        int p = 0;
        while (p < int(res.size()) && res[p] == 0) p++;
        if (p > (deg - 1) / k) return fps(deg);
        res >>= p;
        deg -= p * k;
        mint c = res[0];
        res = ((res / c).log(deg) * k).exp(deg) * c.pow(k);
        res <<= p * k;
        return res;
    }
    fps taylor_shift(mint c) const {
        int n = this->size();
        fps f = *this;
        for (int i = 0; i < n; i++) f[i] *= combination::fac<mint>(i);
        reverse(f.begin(), f.end());
        fps g(n);
        mint pw = 1;
        for (int i = 0; i < n; i++) {
            g[i] = pw * combination::finv<mint>(i);
            pw *= c;
        }
        f = convolution(f, g, n);
        reverse(f.begin(), f.end());
        for (int i = 0; i < n; i++) f[i] *= combination::finv<mint>(i);
        return f;
    }
    // https://judge.yosupo.jp/submission/307408
    fps operator()(fps f, int deg = -1) const {
        assert(f[0] == 0);
        auto g = *this;
        auto rec = [&] (const auto &rec, fps q, int n, int m, int k) -> fps {
            if (n == 0) {
                fps t(q.begin(), q.begin() + k);
                t.emplace_back(1);
                auto u = g * t.rev().inv().rev();
                fps p(m * k);
                for (int i = 0; i < ssize(g); i++) p[k - i - 1] = u[i + k];
                return p;
            }
            fps nq(4 * m * k), nr(2 * m * k);
            for (int i = 0; i < k; i++) {
                copy(q.begin() + i * m, q.begin() + i * m + n + 1, nq.begin() + 2 * i * m);
            }
            nq[2 * m * k]++;
            nq.ntt();
            for (int i = 0; i < 2 * m * k; i++) {
                swap(nq[2 * i], nq[2 * i + 1]);
                nr[i] = nq[2 * i] * nq[2 * i + 1];
            }
            nr.intt();
            nr[0]--;
            q.assign(m * k, mint());
            for (int i = 0; i < 2 * k; i++) {
                for (int j = 0; j <= n / 2; j++) {
                    q[i * m / 2 + j] = nr[i * m + j];
                }
            }
            auto p = rec(rec, q, n / 2, m / 2, 2 * k);
            fps np(4 * m * k);
            for (int i = 0; i < 2 * k; i++) {
                for (int j = 0; j <= n / 2; j++) {
                    np[2 * i * m + 2 * j + (n & 1)] = p[i * m / 2 + j];
                }
            }
            np.ntt();
            for (int i = 1; i < 4 * m * k; i <<= 1) reverse(nq.begin() + i, nq.begin() + (i << 1));
            for (int i = 0; i < 4 * m * k; i++) np[i] *= nq[i];
            np.intt();
            p.assign(m * k, mint());
            for (int i = 0; i < k; i++) {
                copy(np.begin() + 2 * i * m, np.begin() + 2 * i * m + n + 1, p.begin() + i * m);
            }
            return p;
        };
        if (deg == -1) deg = max(f.size(), g.size());
        f.resize(deg);
        g.resize(deg);
        int n = deg - 1, m = 1, k = 1;
        while (m < deg) m <<= 1;
        fps q(m);
        for (int i = 0; i <= n; i++) q[i] = -f[i];
        auto p = rec(rec, q, n, m, k);
        return p.pre(deg).rev();
    }
    // https://judge.yosupo.jp/submission/307652
    fps compositional_inverse(int deg = -1) const {
        auto f = *this;
        assert(f.size() >= 2 && f[1] != 0);
        if (deg == -1) deg = f.size();
        if (deg < 2) return fps{0, f[1].inv()}.pre(deg);
        int n = deg - 1;
        auto h = power_projection(f) * n;
        for (int k = 1; k <= n; k++) h[k] *= combination::mod_inv<mint>(k);
        h = h.rev();
        h *= h[0].inv();
        auto g = (h.log() * mint(-n).inv()).exp();
        g *= f[1].inv();
        return (g << 1).pre(deg);
    }
private:
    static fps convolution(fps f, fps g, int deg = -1) {
        int n = f.size(), m = g.size();
        if (n == 0 || m == 0) return fps{};
        int sz = 1;
        while (sz < n + m - 1) sz <<= 1;
        f.resize(sz);
        f.ntt();
        g.resize(sz);
        g.ntt();
        f = f.dot(g);
        f.intt();
        if (deg == -1) deg = n + m - 1;
        f.resize(deg);
        return f;
    }
    static fps power_projection(fps f, fps g = {1}, int deg = -1) {
        int n = ssize(f) - 1, k = 1, m = 1;
        if (deg < 0) deg = n + 1;
        while (m <= n) m <<= 1;
        g.resize(n + 1);
        fps p(n + 1), q(n + 1), np, nq, bf, bf2;
        for (int i = 0; i <= n; i++) p[i * k] = g[i];
        for (int i = 0; i <= n; i++) q[i * k] = -f[i];
        q[0]++;
        const mint inv2 = mint::raw(2).inv();
        while (n > 0) {
            mint w = NTT::root.pow((mint::mod() - 1) / (2 * k));
            mint iw = w.inv();
            bf2.resize(k);
            auto ntt_doubling = [&] () -> void {
                copy(bf.begin(), bf.end(), bf2.begin());
                bf2.intt();
                mint c = 1;
                for (int i = 0; i < k; i++) {
                    bf2[i] *= c;
                    c *= w;
                }
                bf2.ntt();
                copy(bf2.begin(), bf2.end(), back_inserter(bf));
            };
            np.clear();
            nq.clear();
            for (int i = 0; i <= n; i++) {
                bf.resize(k);
                copy(p.begin() + i * k, p.begin() + i * k + k, bf.begin());
                ntt_doubling();
                copy(bf.begin(), bf.end(), back_inserter(np));
                bf.resize(k);
                copy(q.begin() + i * k, q.begin() + i * k + k, bf.begin());
                if (i == 0) {
                    for (int j = 0; j < k; j++) bf[j]--;
                    ntt_doubling();
                    for (int j = 0; j < k; j++) bf[j]++;
                    for (int j = 0; j < k; j++) bf[k + j]--;
                } else {
                    ntt_doubling();
                }
                copy(bf.begin(), bf.end(), back_inserter(nq));
            }
            np.resize(4 * m * k);
            nq.resize(4 * m * k);
            fps tp(2 * m), tq(2 * m);
            w = NTT::root.pow((mint::mod() - 1) / (2 * m));
            iw = w.inv();
            vector<int> btr;
            if (n & 1) {
                btr.resize(m);
                int lg = __builtin_ctz(m) - 1;
                for( int i = 0; i < m; i++) {
                    btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << lg);
                }
            }
            for(int j = 0; j < 2 * k; j++) {
                tp.assign(2 * m, mint());
                tq.assign(2 * m, mint());
                for (int i = 0; i < m; i++) {
                    tp[i] = np[2 * i * k + j];
                    tq[i] = nq[2 * i * k + j];
                }
                tp.ntt();
                tq.ntt();
                for (int i = 0; i < 2 * m; i++) {
                    if (!(i & 1)) swap(tq[i], tq[i + 1]);
                    tp[i] *= tq[i];
                }
                for (int i = 0; i < m; i++) tq[i] = tq[2 * i] * tq[2 * i + 1];
                if (n & 1) {
                    mint c = inv2;
                    bf.resize(m);
                    for (int i : btr) {
                        bf[i] = (tp[2 * i] - tp[2 * i + 1]) * c;
                        c *= iw;
                    }
                    swap(tp, bf);
                } else {
                    for (int i = 0; i < m; i++) {
                        tp[i] = (tp[2 * i] + tp[2 * i + 1]) * inv2;
                    }
                }
                tp.resize(m);
                tq.resize(m);
                tp.intt();
                tq.intt();
                for (int i = 0; i < m; i++) {
                    np[2 * i * k + j] = tp[i];
                    nq[2 * i * k + j] = tq[i];
                }
            }
            np.resize(2 * k * (n / 2 + 1));
            nq.resize(2 * k * (n / 2 + 1));
            swap(p, np);
            swap(q, nq);
            n /= 2;
            m /= 2;
            k *= 2;
        }
        fps s(p.begin(), p.begin() + k), t(q.begin(), q.begin() + k);
        s.intt();
        t.intt();
        t[0]--;
        if (t[0] == 0) return s.rev().pre(deg);
        return (s.rev() * (t + (fps{1} << k)).rev().inv(deg)).pre(deg);
    }
};