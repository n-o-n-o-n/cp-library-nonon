#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"

#include "../../../src/math/number_theory/enumerate_divisors.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B, C;
    cin >> A >> B >> C;
    int ans = 0;
    for (int d : enumerate_divisors(C)) {
        if (A <= d && d <= B) ans++;
    }
    cout << ans << endl;
}