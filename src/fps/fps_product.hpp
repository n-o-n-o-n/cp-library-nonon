#pragma once
#include "fps.hpp"
#include <vector>

template<typename mint>
struct fps_product {
    fps_product() : fs(0), g(1, 1) {}
    void push_back(const fps<mint> &f) {
        fs.push_back(f);
    }
    fps<mint> prod() {
        if (fs.empty()) return g;
        auto rec = [&](const auto &rec, int l, int r) -> fps<mint> {
            if (l + 1 == r) return fs[l];
            int m = (l + r) / 2;
            return rec(rec, l, m) * rec(rec, m, r);
        };
        g *= rec(rec, 0, int(fs.size()));
        fs.clear();
        return g;
    }
private:
    vector<fps<mint>> fs;
    fps<mint> g;
};