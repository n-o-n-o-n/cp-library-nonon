#pragma once
#include "fps_exp.hpp"
#include "fps_log.hpp"

template<typename mint>
fps<mint> fps<mint>::pow(long long k, int deg) const {
    if (deg == -1) deg = this->size();
    if (k == 0) {
        fps res(deg);
        res[0] = 1;
        return res;
    }
    fps<mint> res(*this);
    int p = 0;
    while (p < int(res.size()) && res[p] == 0) p++;
    if (p > (deg - 1) / k) return fps<mint>(deg);
    res >>= p;
    deg -= p * k;
    mint c = res[0];
    res = ((res / c).log(deg) * k).exp(deg) * c.pow(k);
    res <<= p * k;
    return res;
}