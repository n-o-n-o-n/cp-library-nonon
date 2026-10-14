#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include "../../src/graph/assignment.hpp"

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<long long>> A(N, vector<long long>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> A[i][j];
    }
    auto P = assignment(A);
    long long sum = 0;
    for (int i = 0; i < N; i++) sum += A[i][P[i]];
    cout << sum << '\n';
    for (int i = 0; i < N; i++) cout << A[i][P[i]] << " \n"[i + 1 == N];
}