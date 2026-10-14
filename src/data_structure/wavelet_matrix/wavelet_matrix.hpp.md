---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/data_structure/wavelet_matrix/bit_vector.hpp
    title: src/data_structure/wavelet_matrix/bit_vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/wavelet_matrix/wavelet_matrix.hpp\"\n\
    #include <cassert>\n#include <numeric>\n#include <unordered_map>\n#include <vector>\n\
    #line 4 \"src/data_structure/wavelet_matrix/bit_vector.hpp\"\nusing namespace\
    \ std;\n\nstruct bit_vector {\n    bit_vector() = default;\n    bit_vector(const\
    \ vector<bool> &v) {\n        int n = v.size();\n        int m = n / b + 1;\n\
    \        d = vector<unsigned>(m);\n        sum = vector<int>(m + 1);\n       \
    \ for (int i = 0; i < n; i++) {\n            d[i / b] |= v[i] << (i % b);\n  \
    \      }\n        for (int i = 0; i < m; i++) {\n            sum[i + 1] = sum[i]\
    \ + __builtin_popcount(d[i]);\n        }\n    }\n    bool operator[](int i) const\
    \ { return d[i / b] >> (i % b) & 1; }\n    int rank(int i, bool flag = false)\
    \ const {\n        int mask = (1U << (i % b)) - 1;\n        int r = sum[i / b]\
    \ + __builtin_popcount(d[i / b] & mask);\n        return flag ? r : i - r;\n \
    \   }\n    int select(int i, bool flag) const {\n        int l = 0, r = d.size();\n\
    \        while (r - l > 1) {\n            int m = (l + r) >> 1;\n            (rank(i,\
    \ flag) < i ? l : r) = m;\n        }\n        return l;\n    }\nprivate:\n   \
    \ static constexpr int b = 32;\n    vector<unsigned> d;\n    vector<int> sum;\n\
    };\n#line 7 \"src/data_structure/wavelet_matrix/wavelet_matrix.hpp\"\nusing namespace\
    \ std;\n\ntemplate<typename T, int LOG = __builtin_popcountll(numeric_limits<T>::max())>\n\
    struct wavelet_matrix {\n    wavelet_matrix() : wavelet_matrix(0) {}\n    wavelet_matrix(int\
    \ _n) : n(_n), d(_n), built(false) {}\n    wavelet_matrix(const vector<T> &v)\
    \ : n(v.size()), d(v), built(false) {}\n    void set(int p, const T &x) {\n  \
    \      assert(0 <= p && p < n);\n        d[p] = x;\n    }\n    T get(int p) {\n\
    \        assert(0 <= p && p < n);\n        build();\n        T res = 0;\n    \
    \    for (int i = LOG - 1; i >= 0; i--) {\n            bool flag = mat[i][p];\n\
    \            res |= T(flag) << i;\n            p = id(p, i, flag);\n        }\n\
    \        return res;\n    }\n    T range_kth_smallest(int l, int r, int k) {\n\
    \        assert(0 <= l && l <= r && r <= n);\n        assert(0 <= k && k < r -\
    \ l);\n        build();\n        T res = 0;\n        for (int i = LOG - 1; i >=\
    \ 0; i--) {\n            int m = mat[i].rank(r) - mat[i].rank(l);\n          \
    \  if (k < m) {\n                l = mat[i].rank(l);\n                r = mat[i].rank(r);\n\
    \            } else {\n                res += T(1) << i;\n                l =\
    \ id(l, i, true);\n                r = id(r, i, true);\n                k -= m;\n\
    \            }\n        }\n        return res;\n    }\n    T prev_val(int l, int\
    \ r, T upper) {\n        assert(0 <= l && l <= r && r <= n);\n        build();\n\
    \        int cnt = range_freq(l, r, 0, upper);\n        return cnt == 0 ? -1 :\
    \ range_kth_smallest(l, r, cnt - 1);\n    }\n    T next_val(int l, int r, T lower)\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        build();\n        int\
    \ cnt = range_freq(l, r, 0, lower);\n        return cnt == r - l ? -1 : range_kth_smallest(l,\
    \ r, cnt);\n    }\n    int rank(int l, int r, T x) {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        build();\n        auto f = [&](int k) -> int {\n\
    \            for (int i = LOG - 1; i >= 0; i--) {\n                bool flag =\
    \ x >> i & 1;\n                k = id(k, i, flag);\n            }\n          \
    \  return k - st[x];\n        };\n        return f(r) - f(l);\n    }\n    int\
    \ range_freq(int l, int r, T lower, T upper) {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        build();\n        auto f = [&](T x) -> int {\n      \
    \      int res = 0;\n            int ll = l, rr = r;\n            for (int i =\
    \ LOG - 1; i >= 0; i--) {\n                bool flag = x >> i & 1;\n         \
    \       res += flag * (mat[i].rank(r) - mat[i].rank(l));\n                l =\
    \ id(l, i, flag);\n                r = id(r, i, flag);\n            }\n      \
    \      l = ll, r = rr;\n            return res;\n        };\n        return f(upper)\
    \ - f(lower);\n    }\nprivate:\n    int n;\n    vector<T> d;\n    vector<bit_vector>\
    \ mat;\n    vector<int> cnt;\n    unordered_map<T, int> st;\n    bool built;\n\
    \    void build() {\n        if (built) return;\n        mat = vector<bit_vector>(LOG);\n\
    \        cnt = vector<int>(LOG);\n        for (auto &x : d) assert(x >= 0);\n\
    \        for (int i = LOG - 1; i >= 0; i--) {\n            vector<bool> bit(n);\n\
    \            for (int j = 0; j < n; j++) {\n                bit[j] = d[j] >> i\
    \ & 1;\n            }\n            mat[i] = bit_vector(bit);\n            int\
    \ c0 = 0, c1 = n;\n            for (int j = 0; j < n; j++) {\n               \
    \ if (!bit[j]) c0++;\n            }\n            cnt[i] = c0;\n            vector<T>\
    \ d2(n);\n            for (int j = n - 1; j >= 0; j--) {\n                d2[--(bit[j]\
    \ ? c1 : c0)] = d[j];\n            }\n            d = d2;\n        }\n       \
    \ for (int i = 0; i < n; i++) {\n            if (st.find(d[i]) == st.end()) st[d[i]]\
    \ = i;\n        }\n        built = true;\n    }\n    int id(int p, int i, bool\
    \ flag) {\n        return cnt[i] * flag + mat[i].rank(p, flag);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <numeric>\n#include <unordered_map>\n\
    #include <vector>\n#include \"bit_vector.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ T, int LOG = __builtin_popcountll(numeric_limits<T>::max())>\nstruct wavelet_matrix\
    \ {\n    wavelet_matrix() : wavelet_matrix(0) {}\n    wavelet_matrix(int _n) :\
    \ n(_n), d(_n), built(false) {}\n    wavelet_matrix(const vector<T> &v) : n(v.size()),\
    \ d(v), built(false) {}\n    void set(int p, const T &x) {\n        assert(0 <=\
    \ p && p < n);\n        d[p] = x;\n    }\n    T get(int p) {\n        assert(0\
    \ <= p && p < n);\n        build();\n        T res = 0;\n        for (int i =\
    \ LOG - 1; i >= 0; i--) {\n            bool flag = mat[i][p];\n            res\
    \ |= T(flag) << i;\n            p = id(p, i, flag);\n        }\n        return\
    \ res;\n    }\n    T range_kth_smallest(int l, int r, int k) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        assert(0 <= k && k < r - l);\n        build();\n\
    \        T res = 0;\n        for (int i = LOG - 1; i >= 0; i--) {\n          \
    \  int m = mat[i].rank(r) - mat[i].rank(l);\n            if (k < m) {\n      \
    \          l = mat[i].rank(l);\n                r = mat[i].rank(r);\n        \
    \    } else {\n                res += T(1) << i;\n                l = id(l, i,\
    \ true);\n                r = id(r, i, true);\n                k -= m;\n     \
    \       }\n        }\n        return res;\n    }\n    T prev_val(int l, int r,\
    \ T upper) {\n        assert(0 <= l && l <= r && r <= n);\n        build();\n\
    \        int cnt = range_freq(l, r, 0, upper);\n        return cnt == 0 ? -1 :\
    \ range_kth_smallest(l, r, cnt - 1);\n    }\n    T next_val(int l, int r, T lower)\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        build();\n        int\
    \ cnt = range_freq(l, r, 0, lower);\n        return cnt == r - l ? -1 : range_kth_smallest(l,\
    \ r, cnt);\n    }\n    int rank(int l, int r, T x) {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        build();\n        auto f = [&](int k) -> int {\n\
    \            for (int i = LOG - 1; i >= 0; i--) {\n                bool flag =\
    \ x >> i & 1;\n                k = id(k, i, flag);\n            }\n          \
    \  return k - st[x];\n        };\n        return f(r) - f(l);\n    }\n    int\
    \ range_freq(int l, int r, T lower, T upper) {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        build();\n        auto f = [&](T x) -> int {\n      \
    \      int res = 0;\n            int ll = l, rr = r;\n            for (int i =\
    \ LOG - 1; i >= 0; i--) {\n                bool flag = x >> i & 1;\n         \
    \       res += flag * (mat[i].rank(r) - mat[i].rank(l));\n                l =\
    \ id(l, i, flag);\n                r = id(r, i, flag);\n            }\n      \
    \      l = ll, r = rr;\n            return res;\n        };\n        return f(upper)\
    \ - f(lower);\n    }\nprivate:\n    int n;\n    vector<T> d;\n    vector<bit_vector>\
    \ mat;\n    vector<int> cnt;\n    unordered_map<T, int> st;\n    bool built;\n\
    \    void build() {\n        if (built) return;\n        mat = vector<bit_vector>(LOG);\n\
    \        cnt = vector<int>(LOG);\n        for (auto &x : d) assert(x >= 0);\n\
    \        for (int i = LOG - 1; i >= 0; i--) {\n            vector<bool> bit(n);\n\
    \            for (int j = 0; j < n; j++) {\n                bit[j] = d[j] >> i\
    \ & 1;\n            }\n            mat[i] = bit_vector(bit);\n            int\
    \ c0 = 0, c1 = n;\n            for (int j = 0; j < n; j++) {\n               \
    \ if (!bit[j]) c0++;\n            }\n            cnt[i] = c0;\n            vector<T>\
    \ d2(n);\n            for (int j = n - 1; j >= 0; j--) {\n                d2[--(bit[j]\
    \ ? c1 : c0)] = d[j];\n            }\n            d = d2;\n        }\n       \
    \ for (int i = 0; i < n; i++) {\n            if (st.find(d[i]) == st.end()) st[d[i]]\
    \ = i;\n        }\n        built = true;\n    }\n    int id(int p, int i, bool\
    \ flag) {\n        return cnt[i] * flag + mat[i].rank(p, flag);\n    }\n};"
  dependsOn:
  - src/data_structure/wavelet_matrix/bit_vector.hpp
  isVerificationFile: false
  path: src/data_structure/wavelet_matrix/wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/wavelet_matrix/wavelet_matrix.hpp
layout: document
redirect_from:
- /library/src/data_structure/wavelet_matrix/wavelet_matrix.hpp
- /library/src/data_structure/wavelet_matrix/wavelet_matrix.hpp.html
title: src/data_structure/wavelet_matrix/wavelet_matrix.hpp
---
