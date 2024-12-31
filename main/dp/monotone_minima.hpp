#pragma once
#include <vector>
using namespace std;

template<typename F, typename C>
vector<int> monotone_minima(int h, int w, const F &f, const C &comp) {
    vector<int> id(h, -1);
    auto rec = [&](const auto &rec, int il, int jl, int ir, int jr) -> void {
        if (il > ir) return;
        int im = (il + ir) / 2;
        auto min_val = f(im, jl);
        id[im] = jl;
        for (int j = jl + 1; j <= jr; j++) {
            auto v = f(im, j);
            if (comp(v, min_val)) {
                min_val = v;
                id[im] = j;
            }
        }
        rec(rec, il, jl, im - 1, id[im]);
        rec(rec, im + 1, id[im], ir, jr);
    };
    rec(rec, 0, 0, h - 1, w - 1);
    return id;
}