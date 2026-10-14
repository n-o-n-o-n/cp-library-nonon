#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include "../../../src/math/number_theory/enumerate_primes.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, A, B;
    cin >> N >> A >> B;
    auto P = enumerate_primes(N);
    vector<int> ans;
    ans.reserve((int)1e6);
    for (int i = B; i < ssize(P); i += A) ans.push_back(P[i]);
    cout << P.size() << ' ' << ans.size() << '\n';
    for (int i = 0; i < ssize(ans); i++) cout << ans[i] << " \n"[i + 1 == ssize(ans)];
}