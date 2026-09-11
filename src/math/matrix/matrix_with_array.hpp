#pragma once
#include <array>
#include <cassert>
using namespace std;

template<typename  mint, size_t sz>
struct matrix : array<array<mint, sz>, sz> {
    using array<array<mint, sz>, sz>::array;
    static constexpr matrix O() {
        matrix res;
        constexpr mint zero = 0;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j <sz; j++) res[i][j] = zero;
        }
        return res;
    }
    static constexpr matrix I() {
        matrix res;
        constexpr mint zero = 0;
        constexpr mint one = 1;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j <sz; j++) res[i][j] = i == j ? one : zero;
        }
        return res;
    }
    matrix &operator*=(const mint &r) {
        for (array<mint, sz> &v : *this) {
            for (mint &a : v) a *= r;
        }
        return *this;
    }
    matrix &operator/=(const mint &r) {
        mint invr = r.inv();
        return *this *= invr;
    }
    matrix &operator+=(const matrix& a) {
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                (*this)[i][j] += a[i][j];
            }
        }
        return *this;
    }
    matrix &operator-=(const matrix& a) {
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                (*this)[i][j] -= a[i][j];
            }
        }
        return *this;
    }
    matrix &operator*=(const matrix &a) {
        matrix res = O();
        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                for (int j = 0; j < sz; j++) {
                    res[i][j] += (*this)[i][k] * a[k][j];
                }
            }
        }
        return *this = res;
    }
    matrix operator*(const mint &r) const { return matrix(*this) *= r; }
    matrix operator/(const mint &r) const { return matrix(*this) /= r; }
    matrix operator+(const matrix &a) const { return matrix(*this) += a; }
    matrix operator-(const matrix &a) const { return matrix(*this) -= a; }
    matrix operator*(const matrix &a) const { return matrix(*this) *= a; }
    matrix pow(long long k) const {
        matrix res = I(this->size()), a = *this;
        while (k > 0) {
            if (k & 1) res *= a;
            a *= a;
            k >>= 1;
        }
        return res;
    }
    mint det() const {
        mint res = 1;
        matrix a = *this;
        for (int i = 0; i < sz; i++) {
            for (int j = i; j < sz; j++) {
                if (a[j][i] != 0) {
                    if (i != j) res = -res;
                    swap(a[i], a[j]);
                    break;
                }
            }
            if (a[i][i] != 0) {
                for (int j = i + 1; j < sz; j++) {
                    mint inv = a[j][i] * a[i][i].inv();
                    for (int k = i + 1; k < sz; k++) {
                        a[j][k] -= a[i][k] * inv;
                    }
                }
            }
        }
        for (int i = 0; i < sz; i++) {
            res *= a[i][i];
        }
        return res;
    }
    matrix inv() const {
        matrix a = *this, res = I();
        for (int i = 0; i < sz; i++) {
            if (a[i][i] == 0) {
                for (int j = i + 1; j < sz; j++) {
                    if (a[j][i] != 0) {
                        swap(a[i], a[j]);
                        swap(res[i], res[j]);
                        break;
                    }
                }
            }
            assert(a[i][i] != 0);
            mint cef = a[i][i].inv();
            for (int j = 0; j < sz; j++) {
                a[i][j] *= cef;
                res[i][j] *= cef;
            }
            for (int j = 0; j < sz; j++) {
                if (j != i) {
                    cef = a[j][i];
                    for (int k = 0; k < sz; k++) {
                        a[j][k] -= a[i][k] * cef;
                        res[j][k] -= res[i][k] * cef;
                    }
                }
            }
        }
        return res;
    }
    int rank() const {
        matrix a = *this;
        int r = 0;
        for (int j = 0; j < sz && r < sz; j++) {
            int i = r;
            while (i < sz && a[i][j] == 0) i++;
            if (i == sz) continue;
            swap(a[r], a[i]);
            mint inv = a[r][j].inv();
            for (i = r + 1; i < sz; i++) {
                mint cef = a[i][j] * inv;
                for (int k = j; k < sz; k++) {
                    a[i][k] -= a[r][k] * cef;
                }
            }
            r++;
        }
        return r;
    }
};