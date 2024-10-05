#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C"

#include "../main/tree/lca.hpp"

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    lowest_common_ancestor G(N);
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            int c;
            cin >> c;
            G.add_edge(i, c);
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        cout << G.lca(u, v) << '\n';
    }
}