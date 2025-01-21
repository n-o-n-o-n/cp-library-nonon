#pragma once
#include <stack>
#include <vector>
using namespace std;

template<typename T>
vector<int> cartesian_tree(const vector<T> &a) {
    int n = a.size();
    vector<int> p(n, -1);
    stack<int> st;
    for (int i = 0, j; i < n; i++) {
        j = -1;
        while (st.size() && a[st.top()] >= a[i]) {
            j = st.top();
            st.pop();
        }
        if (st.size()) p[i] = st.top();
        if (j != -1) p[j] = i;
        st.push(i);
    }
    return p;
}