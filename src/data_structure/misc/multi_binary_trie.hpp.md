---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/misc/multi_binary_trie.hpp\"\n#include\
    \ <array>\n#include <cassert>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ T>\nstruct multi_binary_trie {\n    multi_binary_trie(int _log = numeric_limits<T>::digits)\
    \ : log(_log), all(0), sub(1, 0), cnt(1, 0), child(1, e()) {}\n    int size()\
    \ const { return all; }\n    vector<int> track(T x) const {\n        int pos =\
    \ 0;\n        vector<int> res(log, -1);\n        for (int i = log - 1; i >= 0;\
    \ i--) {\n            int c = x >> i & 1;\n            int nxt = child[pos][c];\n\
    \            if (nxt == -1) break;\n            pos = nxt;\n            res[log\
    \ - 1 - i] = pos;\n        }\n        return res;\n    }\n    vector<int> insert(T\
    \ x) {\n        int pos = 0;\n        for (int i = log - 1; i >= 0; i--) {\n \
    \           int c = x >> i & 1;\n            int nxt = child[pos][c];\n      \
    \      if (nxt == -1) {\n                nxt = sub.size();\n                sub.push_back(0);\n\
    \                cnt.push_back(0);\n                child.push_back(e());\n  \
    \          }\n            child[pos][c] = nxt;\n            pos = nxt;\n     \
    \   }\n        vector<int> tr = track(x);\n        int p = tr.back();\n      \
    \  for (int i : tr) cnt[i]++;\n        all++;\n        if (sub[p] == 0) {\n  \
    \          for (int i : tr) sub[i]++;\n        }\n        return tr;\n    }\n\
    \    void erase(T x) {\n        vector<int> tr = track(x);\n        int p = tr.back();\n\
    \        if (p == -1 || sub[p] == 0) return;\n        for (int i : tr) cnt[i]--;\n\
    \        all--;\n        if (cnt[p] == 0) {\n            for (int i : tr) sub[i]--;\n\
    \        }\n    }\n    bool constains(T x) const {\n        int p = track(x).back();\n\
    \        return (p != -1) && (sub[p] > 0);\n    }\n    T kth_smallest(int k, T\
    \ xor_val = 0) const {\n        assert(0 <= k && k < size());\n        int pos\
    \ = 0;\n        T res = 0;\n        for (int i = log - 1; i >= 0; i--) {\n   \
    \         res *= 2;\n            int c = xor_val >> i & 1;\n            int nxt\
    \ = child[pos][c];\n            if (nxt != -1) {\n                if (0 <= k &&\
    \ k < cnt[nxt]) {\n                    pos = nxt;\n                    continue;\n\
    \                }\n                k -= cnt[nxt];\n            }\n          \
    \  pos = child[pos][1 - c];\n            res++;\n        }\n        return res;\n\
    \    }\n    T kth_largest(int k, T xor_val = 0) const {\n        assert(0 <= k\
    \ && k < size());\n        return kth_smallest(size() - 1 - k, xor_val);\n   \
    \ }\n    T min(T xor_val = 0) const {\n        assert(size());\n        return\
    \ kth_smallest(0, xor_val);\n    }\n    T max(T xor_val = 0) const {\n       \
    \ assert(size());\n        return kth_largest(0, xor_val);\n    }\n    T mex(T\
    \ xor_val = 0) const {\n        if (size() == 0) return T(0);\n        int pos\
    \ = 0;\n        T res = 0;\n        for (int i = log - 1; i >= 0; i--) {\n   \
    \         res *= 2;\n            int c = xor_val >> i & 1;\n            int nxt\
    \ = child[pos][c];\n            if (nxt == -1) return res << i;\n            if\
    \ (sub[nxt] < (T(1) << i)) {\n                pos = nxt;\n                continue;\n\
    \            }\n            res++;\n            if (child[pos][1 - c] == -1) return\
    \ res << i;\n            pos = child[pos][1 - c];\n        }\n        return res;\n\
    \    }\n    // #{ x in S | x ^ xor_val < k }\n    int lower_count(T k, T xor_val\
    \ = 0) const {\n        int pos = 0, res = 0;\n        for (int i = log - 1; i\
    \ >= 0; i--) {\n            if (pos == -1) break;\n            int t = k >> i\
    \ & 1;\n            int c = xor_val >> i & 1;\n            if (t == 1) {\n   \
    \             int nxt = child[pos][c];\n                if (nxt != -1) res +=\
    \ cnt[nxt];\n                pos = child[pos][1 - c];\n            } else {\n\
    \                pos = child[pos][c];\n            }\n        }\n        return\
    \ res;\n    }\nprivate:\n    int log, all;\n    vector<int> sub, cnt;\n    vector<array<int,\
    \ 2>> child;\n    constexpr array<int, 2> e() {\n        return {-1, -1};\n  \
    \  }\n};\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <vector>\nusing\
    \ namespace std;\n\ntemplate<typename T>\nstruct multi_binary_trie {\n    multi_binary_trie(int\
    \ _log = numeric_limits<T>::digits) : log(_log), all(0), sub(1, 0), cnt(1, 0),\
    \ child(1, e()) {}\n    int size() const { return all; }\n    vector<int> track(T\
    \ x) const {\n        int pos = 0;\n        vector<int> res(log, -1);\n      \
    \  for (int i = log - 1; i >= 0; i--) {\n            int c = x >> i & 1;\n   \
    \         int nxt = child[pos][c];\n            if (nxt == -1) break;\n      \
    \      pos = nxt;\n            res[log - 1 - i] = pos;\n        }\n        return\
    \ res;\n    }\n    vector<int> insert(T x) {\n        int pos = 0;\n        for\
    \ (int i = log - 1; i >= 0; i--) {\n            int c = x >> i & 1;\n        \
    \    int nxt = child[pos][c];\n            if (nxt == -1) {\n                nxt\
    \ = sub.size();\n                sub.push_back(0);\n                cnt.push_back(0);\n\
    \                child.push_back(e());\n            }\n            child[pos][c]\
    \ = nxt;\n            pos = nxt;\n        }\n        vector<int> tr = track(x);\n\
    \        int p = tr.back();\n        for (int i : tr) cnt[i]++;\n        all++;\n\
    \        if (sub[p] == 0) {\n            for (int i : tr) sub[i]++;\n        }\n\
    \        return tr;\n    }\n    void erase(T x) {\n        vector<int> tr = track(x);\n\
    \        int p = tr.back();\n        if (p == -1 || sub[p] == 0) return;\n   \
    \     for (int i : tr) cnt[i]--;\n        all--;\n        if (cnt[p] == 0) {\n\
    \            for (int i : tr) sub[i]--;\n        }\n    }\n    bool constains(T\
    \ x) const {\n        int p = track(x).back();\n        return (p != -1) && (sub[p]\
    \ > 0);\n    }\n    T kth_smallest(int k, T xor_val = 0) const {\n        assert(0\
    \ <= k && k < size());\n        int pos = 0;\n        T res = 0;\n        for\
    \ (int i = log - 1; i >= 0; i--) {\n            res *= 2;\n            int c =\
    \ xor_val >> i & 1;\n            int nxt = child[pos][c];\n            if (nxt\
    \ != -1) {\n                if (0 <= k && k < cnt[nxt]) {\n                  \
    \  pos = nxt;\n                    continue;\n                }\n            \
    \    k -= cnt[nxt];\n            }\n            pos = child[pos][1 - c];\n   \
    \         res++;\n        }\n        return res;\n    }\n    T kth_largest(int\
    \ k, T xor_val = 0) const {\n        assert(0 <= k && k < size());\n        return\
    \ kth_smallest(size() - 1 - k, xor_val);\n    }\n    T min(T xor_val = 0) const\
    \ {\n        assert(size());\n        return kth_smallest(0, xor_val);\n    }\n\
    \    T max(T xor_val = 0) const {\n        assert(size());\n        return kth_largest(0,\
    \ xor_val);\n    }\n    T mex(T xor_val = 0) const {\n        if (size() == 0)\
    \ return T(0);\n        int pos = 0;\n        T res = 0;\n        for (int i =\
    \ log - 1; i >= 0; i--) {\n            res *= 2;\n            int c = xor_val\
    \ >> i & 1;\n            int nxt = child[pos][c];\n            if (nxt == -1)\
    \ return res << i;\n            if (sub[nxt] < (T(1) << i)) {\n              \
    \  pos = nxt;\n                continue;\n            }\n            res++;\n\
    \            if (child[pos][1 - c] == -1) return res << i;\n            pos =\
    \ child[pos][1 - c];\n        }\n        return res;\n    }\n    // #{ x in S\
    \ | x ^ xor_val < k }\n    int lower_count(T k, T xor_val = 0) const {\n     \
    \   int pos = 0, res = 0;\n        for (int i = log - 1; i >= 0; i--) {\n    \
    \        if (pos == -1) break;\n            int t = k >> i & 1;\n            int\
    \ c = xor_val >> i & 1;\n            if (t == 1) {\n                int nxt =\
    \ child[pos][c];\n                if (nxt != -1) res += cnt[nxt];\n          \
    \      pos = child[pos][1 - c];\n            } else {\n                pos = child[pos][c];\n\
    \            }\n        }\n        return res;\n    }\nprivate:\n    int log,\
    \ all;\n    vector<int> sub, cnt;\n    vector<array<int, 2>> child;\n    constexpr\
    \ array<int, 2> e() {\n        return {-1, -1};\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/misc/multi_binary_trie.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/misc/multi_binary_trie.hpp
layout: document
redirect_from:
- /library/src/data_structure/misc/multi_binary_trie.hpp
- /library/src/data_structure/misc/multi_binary_trie.hpp.html
title: src/data_structure/misc/multi_binary_trie.hpp
---
