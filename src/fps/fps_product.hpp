#pragma once
#include "fps.hpp"
#include <vector>

template<typename mint>
struct fps_product {
    using fps = Formal_Power_Series<mint>;
    fps_product() : fs(0), g(1, 1) {}
    void push_back(const fps &f) {
        fs.push_back(f);
    }
    fps prod() {
        if (fs.empty()) return g;
        auto rec = [&](const auto &rec, int l, int r) -> fps {
            if (l + 1 == r) return fs[l];
            int m = (l + r) / 2;
            return rec(rec, l, m) * rec(rec, m, r);
        };
        g *= rec(rec, 0, int(fs.size()));
        fs.clear();
        return g;
    }
private:
    vector<fps> fs;
    fps g;
};