#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"

#include "../../../src/math/number_theory/enumerate_quotients.hpp"

#include <algorithm>
#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N;
    cin >> N;
    vector<long long> ans;
    for (auto [_, __, q] : enumerate_quotients(N)) ans.push_back(q);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i = 0; i < ssize(ans); i++) cout << ans[i] << " \n"[i + 1 == ssize(ans)];
}