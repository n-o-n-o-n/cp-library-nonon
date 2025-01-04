#pragma once
#include <vector>
using namespace std;

vector<int> enumerate_primes(int n) {
    vector<bool> prime(n + 1, true);
    vector<int> res;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            res.push_back(i);
            for (int j = i + i; j <= n; j += i) prime[j] = false;
        }
    }
    return res;
}