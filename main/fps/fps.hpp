#pragma once
#include <vector>
#include "../math/combination.hpp"
#include "../convolution/ntt.hpp"
using namespace std;

template<typename mint>
struct Formal_Power_Series : vector<mint> {
    using FPS = Formal_Power_Series;
    using vector<mint>::vector;
    using NTT = Number_Theoretic_Transform<mint>;
    void ntt() { NTT::ntt(*this); }
    void intt() { NTT::intt(*this); }
    FPS &operator+=(const mint &r) {
        if (this->empty()) this->resize(1);
        (*this)[0] += r;
        return *this;
    }
    FPS &operator-=(const mint &r) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= r;
        return *this;
    }
    FPS &operator*=(const mint &r) {
        for (mint &x : *this) x *= r;
        return *this;
    }
    FPS &operator/=(const mint &r) {
        mint invr = r.inv();
        return *this *= invr;
    }
    FPS &operator+=(const FPS &f) {
        int n = this->size(), m = f.size();
        if (n < m) this->resize(m);
        for (int i = 0; i < m; i++) (*this)[i] += f[i];
        return *this;
    }
    FPS &operator-=(const FPS &f) {
        int n = this->size(), m = f.size();
        if (n < m) this->resize(m);
        for (int i = 0; i < m; i++) (*this)[i] -= f[i];
        return *this;
    }
    FPS &operator*=(const FPS &f) {
        *this = convolution(*this, f);
        return *this;
    }
    FPS &operator/=(const FPS &f) {
        return *this *= f.inv();
    }
    FPS &operator%=(const FPS &f) {
        *this -= div(f) * f;
        this->shrink();
        return *this;
    }
    FPS div(const FPS &f) const {
        if (this->size() < f.size()) return FPS{};
        int n = this->size() - f.size() + 1;
        return (rev().pre(n) * f.rev().inv(n)).pre(n).rev(n);
    }
    FPS operator+(const mint &r) const { return FPS(*this) += r; }
    FPS operator-(const mint &r) const { return FPS(*this) -= r; }
    FPS operator*(const mint &r) const { return FPS(*this) *= r; }
    FPS operator/(const mint &r) const { return FPS(*this) /= r; }
    FPS operator+(const FPS &f) const { return FPS(*this) += f; }
    FPS operator-(const FPS &f) const { return FPS(*this) -= f; }
    FPS operator*(const FPS &f) const { return FPS(*this) *= f; }
    FPS operator/(const FPS &f) const { return FPS(*this) /= f; }
    FPS operator%(const FPS &f) const { return FPS(*this) %= f; }

    FPS operator-() const {
        return FPS{} - *this;
    }
    FPS operator<<(int n) const {
        FPS res(*this);
        res.insert(res.begin(), n, mint());
        return res;
    }
    FPS operator>>(int n) const {
        if (int(this->size()) <= n) return FPS{};
        FPS res(*this);
        res.erase(res.begin(), res.begin() + n);
        return res;
    }
    FPS &operator<<=(int n) {
        return *this = (*this) << n;
    }
    FPS &operator>>=(int n) {
        return *this = (*this) >> n;
    }
    FPS pre(int n) const {
        n = min(n, int(this->size()));
        return FPS(this->begin(), this->begin() + n);
    }
    FPS rev(int deg = -1) const {
        FPS res(*this);
        if (deg != -1) res.resize(deg, 0);
        reverse(res.begin(), res.end());
        return res;
    }
    FPS dot(const FPS &f) const {
        int n = min(this->size(), f.size());
        FPS res(n);
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
    FPS diff() const {
        int n = this->size();
        if (n == 0) return FPS{};
        FPS res(n - 1);
        for (int i = 1; i < n; i++) {
            res[i - 1] = i * (*this)[i];
        }
        return res;
    }
    FPS integral() const {
        int n = this->size();
        FPS res(n + 1);
        res[0] = 0;
        for (int i = 0; i < n; i++) {
            res[i + 1] = (*this)[i] * C.inv(i + 1);
        }
        return res;
    }
    FPS inv(int deg = -1) const {
        int n = this->size();
        assert(n > 0);
        mint c = (*this)[0];
        assert(c != 0);
        if (deg == -1) deg = n;
        FPS res(deg);
        res[0] = c.inv();
        for (int d = 1; d < deg; d <<= 1) {
            FPS f(d << 1), g(d << 1);
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
    FPS exp(int deg = -1) const {
        int n = this->size();
        if (deg == -1) deg = n;
        if (n == 0) {
            FPS res(deg);
            res[0] = 1;
            return res;
        }
        assert((*this)[0] == 0);
        auto inplace_diff = [](FPS &f) -> void {
            if (f.empty()) return;
            f.erase(f.begin());
            for (int i = 0; i < int(f.size()); i++) f[i] *= i + 1;
        };
        auto inplace_integral = [&](FPS &f) -> void {
            f.insert(f.begin(), 0);
            for (int i = 1; i < int(f.size()); i++) f[i] *= C.inv(i);
        };
        FPS b = {1, 1 < n ? (*this)[1] : 0};
        FPS c = {1}, z1, z2 = {1, 1};
        for (int d = 2; d < deg; d <<= 1) {
            FPS  y = b;
            y.resize(d << 1);
            y.ntt();
            z1 = z2;
            FPS z = y.dot(z1);
            z.intt();
            fill(z.begin(), z.begin() + (d >> 1), 0);
            z.ntt();
            z = z.dot(-z1);
            z.intt();
            c.insert(c.end(), z.begin() + (d >> 1), z.end());
            z2 = c;
            z2.resize(d << 1);
            z2.ntt();
            FPS x(this->begin(), this->begin() + min(n, d));
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
        return FPS(b.begin(), b.begin() + deg);
    }
    FPS log(int deg = -1) const {
        assert((*this)[0] == 1);
        if (deg == -1) deg = this->size();
        return (diff() * inv()).integral().pre(deg);
    }
    FPS pow(long long k, int deg = -1) const {
        if (deg == -1) deg = this->size();
        if (k == 0) {
            FPS res(deg);
            res[0] = 1;
            return res;
        }
        FPS res(*this);
        int p = 0;
        while (p < int(res.size()) && res[p] == 0) p++;
        if (p > (deg - 1) / k) return FPS(deg);
        res >>= p;
        deg -= p * k;
        mint c = res[0];
        res = ((res / c).log(deg) * k).exp(deg) * c.pow(k);
        res <<= p * k;
        return res;
    }
    FPS taylor_shift(mint c) const {
        int n = this->size();
        FPS f = *this;
        for (int i = 0; i < n; i++) f[i] *= C.fac(i);
        reverse(f.begin(), f.end());
        FPS g(n);
        mint pw = 1;
        for (int i = 0; i < n; i++) {
            g[i] = pw * C.finv(i);
            pw *= c;
        }
        f = convolution(f, g, n);
        reverse(f.begin(), f.end());
        for (int i = 0; i < n; i++) f[i] *= C.finv(i);
        return f;
    }
private:
    static combination<mint> C;
    static FPS convolution(FPS f, FPS g, int deg = -1) {
        int n = f.size(), m = g.size();
        if (n == 0 || m == 0) return FPS{};
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
};