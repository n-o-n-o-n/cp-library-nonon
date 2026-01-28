#pragma once
#include "fps_inv.hpp"

template<typename mint>
fps<mint> fps<mint>::log(int deg) const {
    assert((*this)[0] == 1);
    if (deg == -1) deg = this->size();
    return (diff() * inv()).integral().pre(deg);
}