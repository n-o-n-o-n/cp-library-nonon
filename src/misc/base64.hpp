#pragma once
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// https://nyaannyaan.github.io/library/misc/base64.hpp
namespace base64 {

constexpr char base[66] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/.";

inline int ibase(char c) {
    if ('A' <= c && c <= 'Z') return c - 'A';
    if ('a' <= c && c <= 'z') return c - 'a' + 26;
    if ('0' <= c && c <= '9') return c - '0' + 52;
    if (c == '+') return 62;
    if (c == '/') return 63;
    return 64;
}

template<typename T>
string encode(const vector<T> &v) {
    int n = v.size();
    if (n == 0) return "";
    T x = v[0], y = v[0];
    for (const auto &e : v) x = min(x, e), y = max(y, e);
    int b = max<int>(6, x < 0 ? sizeof(T) * 8 : (y == 0 ? 0 : 64 - __builtin_clzll(y)));
    string s((b * n + 11) / 6, 0);
    s[0] = b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b; j++) {
            if ((v[i] >> j) & 1) s[(i * b + j) / 6 + 1] |= 1 << ((i * b + j) % 6);
        }
    }
    for (auto &c : s) c = base[(int)c];
    return s;
}

template<typename T = long long>
vector<T> decode(const string &s) {
    if (s.empty()) return {};
    int b = ibase(s[0]);
    if (b == 0) return {};
    int n = s.size() - 1;
    vector<T> v(n * 6 / b, 0);
    for (int i = 0; i < n; i++) {
        int c = ibase(s[i + 1]);
        for (int j = 0; j < 6; j++) {
            if ((c >> j) & 1) {
                v[(i * 6 + j) / b] |= T(1) << ((i * 6 + j) % b);
            }
        }
    }
    return v;
}

};