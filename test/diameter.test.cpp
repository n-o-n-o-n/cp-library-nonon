#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../main/tree/diameter.hpp"

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<pair<int, long long>>> G(N);
    for (int i = 1; i < N; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    auto [diam, path] = diameter(G);
    cout << diam << ' ' << path.size() << '\n';
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " \n"[i + 1 == path.size()];
    }
}