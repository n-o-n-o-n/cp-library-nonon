#pragma once
#include "fps.hpp"
#include <vector>

template<typename FPS>
struct fps_product {
    fps_product() : fs(0), g(1, 1) {}
    void push_back(const FPS &f) {
        fs.push_back(f);
    }
    FPS prod() {
        if (fs.empty()) return g;
        auto rec = [&](const auto &rec, int l, int r) -> FPS {
            if (l + 1 == r) return fs[l];
            int m = (l + r) / 2;
            return rec(rec, l, m) * rec(rec, m, r);
        };
        g *= rec(rec, 0, int(fs.size()));
        fs.clear();
        return g;
    }
private:
    vector<FPS> fs;
    FPS g;
};