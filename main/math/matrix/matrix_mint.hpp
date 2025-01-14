#pragma once
#include <vector>
using namespace std;

template<typename mint>
struct matrix : vector<vector<mint>> {
    using vector<vector<mint>>::vector;
    matrix(int h, int w) : vector<vector<mint>>(h, vector<mint>(w)) {}
    matrix &operator*=(const mint &r) {
        for (vector<mint> &v : *this) {
            for (mint &a : v) a *= r;
        }
        return *this;
    }
    matrix &operator/=(const mint &r) {
        mint invr = r.inv();
        return *this *= invr;
    }
    matrix &operator+=(const matrix& a) {
        assert(this->size() == a.size());
        for (int i = 0; i < int(this->size()); i++) {
            assert((*this)[i].size() == a[i].size());
            for (int j = 0; j < int((*this)[i].size()); j++) {
                (*this)[i][j] += a[i][j];
            }
        }
        return *this;
    }
    matrix &operator-=(const matrix& a) {
        assert(this->size() == a.size());
        for (int i = 0; i < int(this->size()); i++) {
            assert((*this)[i].size() == a[i].size());
            for (int j = 0; j < int((*this)[i].size()); j++) {
                (*this)[i][j] -= a[i][j];
            }
        }
        return *this;
    }
    matrix &operator*=(const matrix &a) {
        int n = this->size(), m = a.size();
        assert(m >= 1);
        int l = a[0].size();
        matrix res(n, vector<mint>(l));
        for (int i = 0; i < n; i++) {
            assert(int((*this)[i].size()) == m);
            for (int k = 0; k < m; k++) {
                for (int j = 0; j < l; j++) {
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
    static constexpr matrix I(int n) {
        matrix res(n, n);
        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }
        return res;
    }
    static constexpr matrix O(int n) { return matrix(n, n); }
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
        int n = this->size();
        assert(n >= 1);
        assert((*this)[0].size() == this->size());
        mint res = 1;
        matrix a = *this;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (a[j][i] != 0) {
                    if (i != j) res = -res;
                    swap(a[i], a[j]);
                    break;
                }
            }
            if (a[i][i] != 0) {
                for (int j = i + 1; j < n; j++) {
                    mint inv = a[j][i] * a[i][i].inv();
                    for (int k = i + 1; k < n; k++) {
                        a[j][k] -= a[i][k] * inv;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            res *= a[i][i];
        }
        return res;
    }
    matrix inv() const {
        int n = this->size();
        matrix a = *this, res = I(n);
        for (int i = 0; i < n; i++) {
            if (a[i][i] == 0) {
                for (int j = i + 1; j < n; j++) {
                    if (a[j][i] != 0) {
                        swap(a[i], a[j]);
                        swap(res[i], res[j]);
                        break;
                    }
                }
            }
            assert(a[i][i] != 0);
            mint cef = a[i][i].inv();
            for (int j = 0; j < n; j++) {
                a[i][j] *= cef;
                res[i][j] *= cef;
            }
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    cef = a[j][i];
                    for (int k = 0; k < n; k++) {
                        a[j][k] -= a[i][k] * cef;
                        res[j][k] -= res[i][k] * cef;
                    }
                }
            }
        }
        return res;
    }
};