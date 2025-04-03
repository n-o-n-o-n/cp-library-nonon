#pragma once
#include "../../modint/dynamic_modint.hpp"
#include "discrete_logarithm.hpp"
using namespace std;

int mod_log(int a, int b, int p) {
    modint::set_mod(p);
    struct Fp {
        using S = modint;
        using F = modint;
        static F comp(F f, F g) {
            return f * g;
        }
        static F id() {
            return 1;
        }
        static S mapping(F f, S x) {
            return f * x;
        }
    };
    return discrete_logarithm<Fp>::solve(a, 1, b, p, [&](modint x){
        return x.val();
    });
}