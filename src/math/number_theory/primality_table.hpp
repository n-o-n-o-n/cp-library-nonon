#pragma once
#include <vector>
using namespace std;

vector<bool> primality_table(int n) {
    vector<bool> res(n + 1, true);
    res[0] = res[1] = false;
    for (int i = 2; i <= n; i++) {
        if (res[i]) {
            for (int j = i + i; j <= n; j += i) res[j] = false;
        }
    }
    return res;
}