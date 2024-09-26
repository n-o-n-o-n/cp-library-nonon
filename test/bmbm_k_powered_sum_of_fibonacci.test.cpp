#define PROBLEM "https://yukicoder.me/problems/no/2883"

#include "../main/modint/modint.hpp"
#include "../main/math/bmbm.hpp"

using mint = modint<998244353>;

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N;
    int K;
    cin >> N >> K;
    int M = 4 * K;
    vector<mint> F(M), A(M);
    F[0] = F[1] = 1;
    A[0] = 1, A[1] = 2;
    for (int i = 2; i < M; i++) {
        F[i] = F[i - 1] + F[i - 2];
        A[i] = A[i - 1] + F[i].pow(K);
    }
    cout << BMBM(A, N - 1).val() << endl;
}