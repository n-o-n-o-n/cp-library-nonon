#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../../src/tree/diameter.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<pair<int, long long>>> G(N);
    for (int i = 1, a, b, c; i < N; i++) {
        cin >> a >> b >> c;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
    auto [W, P] = diameter(G);
    cout << W << ' ' << P.size() << '\n';
    for (int i = 0; i < ssize(P); i++) cout << P[i] << " \n"[i + 1 == ssize(P)];
}