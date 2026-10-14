#define PROBLEM "https://yukicoder.me/problems/no/187"

#include "../../../src/math/number_theory/factorise.hpp"
#include "../../../src/math/number_theory/garner.hpp"

#include <map>
#include <algorithm>
#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const long long mod = 1e9 + 7;
    int N;
    cin >> N;
    vector<long long> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    if (count(X.begin(), X.end(), 0) == N) {
        assert(garner(X, Y, mod) == 0);
        map<int, int> fc;
        for (int i = 0; i < N; i++) {
            for (auto [p, e] : factorise(Y[i])) fc[p] = max(fc[p], e);
        }
        long long L = 1;
        for (auto [p, e] : fc) {
            while (e--) L = (L * p) % mod;
        }
        cout << L << '\n';
        return 0;
    }
    cout << garner(X, Y, mod) << endl;
}