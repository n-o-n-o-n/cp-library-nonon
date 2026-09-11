#pragma once
#include <vector>
#include "../../fps/fps.hpp"
using namespace std;

// for k=0,...,K calculate sum[a in A] a^k 
template<typename mint>
vector<mint> enumerate_powers_of_sums(const vector<int> &A, int K) {
    using FPS = fps<mint>;
    auto rec = [&](const auto &rec, int l, int r) -> FPS {
        if (l + 1 == r) return FPS{1, -A[l]};
        int m = (l + r) / 2;
        return rec(rec, l, m) * rec(rec, m, r);
    };
    auto f = rec(rec, 0, A.size());
    f.resize(K + 1);
    f = -f.log().diff();
    f.insert(f.begin(), A.size());
    return vector<mint>(f.begin(), f.end());
}
