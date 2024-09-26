#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_10_C"

#include "../main/dp/lcs.hpp"

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin >> test;
    while (test--) {
        string S, T;
        cin >> S >> T;
        cout << longest_common_subsequence(S, T).size() << endl;
    }
}