#pragma once
#include "subprod_tree.hpp"

template<typename mint>
fps<mint> polynomial_interpolation(const vector<mint> &xs, const vector<mint> &ys) {
    return subprod_tree<mint>(xs).polynomial_interpolation(ys);
}