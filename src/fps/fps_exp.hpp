#pragma once
#include "fps.hpp"

template<typename mint>
fps<mint> fps<mint>::exp(int deg) const {
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
        for (int i = 0; i < d; i++) z[i] *= -z1[i];
        z.intt();
        c.insert(c.end(), z.begin() + (d >> 1), z.end());
        z2 = c;
        z2.resize(d << 1);
        z2.ntt();
        fps x(this->begin(), this->begin() + min(n, d));
        inplace_diff(x);
        x.reserve(d);
        x.push_back(0);
        x.ntt();
        for (int i = 0; i < d; i++) x[i] *= y[i];
        x.intt();
        x -= b.diff();
        x.resize(d << 1);
        for (int i = 0; i < d - 1; i++) x[i + d] = x[i], x[i] = 0;
        x.ntt();
        for (int i = 0; i < d << 1; i++) x[i] *= z2[i];
        x.intt();
        x.pop_back();
        inplace_integral(x);
        for (int i = d; i < min(n, d << 1); i++) x[i] += (*this)[i];
        fill(x.begin(), x.begin() + d, 0);
        x.ntt();
        for (int i = 0; i < d << 1; i++) x[i] *= y[i];
        x.intt();
        b.insert(b.end(), x.begin() + d, x.end());
    }
    return fps(b.begin(), b.begin() + deg);
}