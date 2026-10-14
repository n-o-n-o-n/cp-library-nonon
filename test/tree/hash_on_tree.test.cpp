#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include "../../src/tree/hash_on_tree.hpp"

#include <iostream>
#include <map>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    hash_on_tree::set_base(998244353);
    hash_on_tree G(N);
    for (int i = 1, p; i < N; i++) {
        cin >> p;
        G.add_edge(i, p);
    }
    map<array<long long, 3>, int> mp;
    vector<int> ans(N);
    for (int i = 0; i < N; i++) {
        auto ar = G.get_hash(i);
        if (mp.find(ar) == mp.end()) mp[ar] = ans[i] = mp.size();
        ans[i] = mp[ar];
    }
    cout << mp.size() << '\n';
    for (int i = 0; i < N; i++) cout << ans[i] << " \n"[i + 1 == N];
}