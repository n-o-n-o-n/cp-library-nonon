#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=jp"

#include "../../../src/math/number_theory/extended_gcd.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B, X, Y;
    cin >> A >> B >> X >> Y;
    extended_gcd(A, B, X, Y);
    cout << X << ' ' << Y << '\n';
}