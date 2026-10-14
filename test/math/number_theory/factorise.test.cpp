#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "../../../src/math/number_theory/factorise.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    cin >> Q;
    for (long long A; Q--; ) {
        cin >> A;
        vector<long long> ans;
        for (auto [p, e] : factorise(A)) {
            while (e--) ans.push_back(p);
        }
        cout << ans.size();
        for (auto p : ans) cout << ' ' << p;
        cout << '\n';
    }
}