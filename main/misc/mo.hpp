#pragma once
#include <algorithm>
#include <vector>
using namespace std;

struct MO {
    MO(int _n, int _q) : n(_n), q(_q) { querys.reserve(q); }
    void add(int l, int r) { querys.emplace_back(l, r); }
    template<typename EXL, typename EXR, typename SHL, typename SHR, typename O>
    void run(const EXL &exl, const EXR &exr, const SHL &shl, const SHR &shr, const O &out) {
        const int b = clamp(int(sqrtl(q * 0.66)), 1, n);
        vector<int> ord(q);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) {
            auto [li, ri] = querys[i];
            auto [lj, rj] = querys[j];
            int bi = li / b, bj = lj / b;
            return bi == bj ? bi & 1 ? ri > rj : ri < rj : bi < bj;
        });
        int l = 0, r = 0;
        for (int i : ord) {
            auto [li, ri] = querys[i];
            while (l > li) exl(--l);
            while (r < ri) exr(r++);
            while (l < li) shl(l++);
            while (r > ri) shr(--r);
            out(i);
        }
    }
private:
    int n, q;
    vector<pair<int, int>> querys;
};