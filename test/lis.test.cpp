#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include "../main/dp/lis.hpp"

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    auto idx = longest_increasing_subsequence(A);
    cout << idx.size() << '\n';
    for (int i = 0; i < idx.size(); i++) {
        cout << idx[i] << " \n"[i + 1 == idx.size()];
    }
}