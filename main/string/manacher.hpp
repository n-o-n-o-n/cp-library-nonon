#pragma once
#include <string>
#include <vector>
using namespace std;

template<typename S> 
vector<int> manacher(vector<S> v, const S wildcard) {
    {
        vector<S> tmp = v;
        v.clear();
        for (const S &s : tmp) {
            v.push_back(s);
            v.push_back(wildcard);
        }
        v.pop_back();
    }
    const int n = v.size();
    int i = 0, j = 0;
    vector<int> res(n);
    while (i < n) {
        while (j <= i && i + j < n && v[i - j] == v[i + j]) j++;
        res[i] = j;
        int k = 1;
        while (k <= i && i + k < n && k + res[i - k] < j) {
            res[i + k] = res[i - k];
            k++;
        }
        i += k;
        j -= k;
    }
    for (int i = 0; i < n; i++) {
        if (1 ^ ((res[i] ^ i) & 1)) res[i]--;
    }
    return res;
}

vector<int> manacher(const string &s) {
    return manacher(vector<char>(s.begin(), s.end()), '$');
}