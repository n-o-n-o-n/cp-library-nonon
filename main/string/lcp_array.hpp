#pragma once
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template<typename S>
vector<int> lcp_array(const vector<S> &v, const vector<int> &sa) {
    int n = v.size();
    vector<int> lcp(n), rank(n);
    for (int i = 0; i < n; i++) rank[ sa[i] ] = i;
    for(int i = 0, h = 0; i < n; i++) {
        if(rank[i] + 1 < n) {
            int j = sa[ rank[i] + 1 ];
            while (i + h < n && j + h < n && v[i + h] == v[j + h]) h++;
            lcp[ rank[i] + 1 ] = h;
            if (h > 0) h--;
        }
    }
    return lcp;
}

vector<int> lcp_array(const string &s, const vector<int> &sa) {
    return lcp_array(vector<char>(s.begin(), s.end()), sa);
}