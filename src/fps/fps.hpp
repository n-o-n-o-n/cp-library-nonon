#pragma once
#include <vector>
#include "../math/enumerative_combinatorics/combination.hpp"
#include "../convolution/ntt.hpp"
using namespace std;

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