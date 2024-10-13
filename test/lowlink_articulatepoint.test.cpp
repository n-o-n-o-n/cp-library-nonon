#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A"
#include "../main/graph/lowlink.hpp"

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    LowLink G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G.add_edge(u, v);
    }
    vector<int> ans = G.Articulation_Point();
    sort(ans.begin(), ans.end());
    for (int a : ans) {
        cout << a << '\n';
    }
}