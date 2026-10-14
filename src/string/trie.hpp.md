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
  bundledCode: "#line 2 \"src/string/trie.hpp\"\n#include <array>\n#include <cassert>\n\
    #include <string>\n#include <vector>\nusing namespace std;\n\ntemplate<int size,\
    \ char base>\nstruct trie {\n    trie() : idx(0), par(1, -1), chr(1, -1), cnt(1,\
    \ 0), last(0), child(1, e()), tail(1) {}\n    vector<int> track(const string &s)\
    \ const {\n        int n = s.size(), pos = 0;\n        vector<int> res(n, -1);\n\
    \        for (int i = 0; i < n; i++) {\n            int c = s[i] - base;\n   \
    \         if (child[pos][c] == -1) break;\n            pos = child[pos][c];\n\
    \            res[i] = pos;\n        }\n        return res;\n    }\n    vector<int>\
    \ insert(const string &s) {\n        int n = s.size(), pos = 0;\n        for (int\
    \ i = 0; i < n; i++) {\n            int c = s[i] - base;\n            if (child[pos][c]\
    \ == -1) {\n                child[pos][c] = par.size();\n                par.push_back(pos);\n\
    \                chr.push_back(c);\n                cnt.push_back(0);\n      \
    \          child.push_back(e());\n                tail.push_back({});\n      \
    \      }\n            pos = child[pos][c];\n            cnt[pos]++;\n        }\n\
    \        tail[pos].push_back(idx++);\n        last.push_back(pos);\n        return\
    \ track(s);\n    }\n    string operator[](int k) const {\n        assert(0 <=\
    \ k && k < int(last.size()));\n        int pos = last[k];\n        string s =\
    \ \"\";\n        while (pos > 0) {\n            s.push_back(base + chr[pos]);\n\
    \            pos = par[pos];\n        }\n        reverse(s.begin(), s.end());\n\
    \        return s;\n    }\n    string kth_smallest(int k) const {\n        int\
    \ pos = 0;\n        string s = \"\";\n        bool fn = true;\n        while (fn)\
    \ {\n            fn = false;\n            k -= tail[pos].size();\n           \
    \ for (int i = 0; i < size; i++) {\n                int nxt = child[pos][i];\n\
    \                if (nxt != -1) {\n                    if (0 <= k && k < cnt[nxt])\
    \ {\n                        pos = nxt;\n                        s.push_back(base\
    \ + chr[pos]);\n                        fn = true;\n                        break;\n\
    \                    }\n                    k -= cnt[nxt];\n                }\n\
    \            }\n        }\n        return s;\n    }\n    int count(const string\
    \ &s) const {\n        int p = track(s).back();\n        return p == -1 ? 0 :\
    \ (int)tail[p].size();\n    }\n    // the number of strings that have s as a prefix\n\
    \    int count_prefix(const string &s) const {\n        int p = track(s).back();\n\
    \        return p == -1 ? 0 : cnt[p];\n    }\n    // the number of strings that\
    \ have s with a prefix\n    int prefix_count(const string &s) const {\n      \
    \  int res = 0;\n        for (int i : track(s)) {\n            if (i == -1) break;\n\
    \            res += tail[i].size();\n        }\n        return res;\n    }\nprivate:\n\
    \    int idx;\n    vector<int> par, chr, cnt, last;\n    vector<array<int, size>>\
    \ child;\n    vector<vector<int>> tail;\n    constexpr array<int, size> e() {\n\
    \        array<int, size> x;\n        x.fill(-1);\n        return x;\n    }\n\
    };\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <string>\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate<int size, char base>\nstruct trie\
    \ {\n    trie() : idx(0), par(1, -1), chr(1, -1), cnt(1, 0), last(0), child(1,\
    \ e()), tail(1) {}\n    vector<int> track(const string &s) const {\n        int\
    \ n = s.size(), pos = 0;\n        vector<int> res(n, -1);\n        for (int i\
    \ = 0; i < n; i++) {\n            int c = s[i] - base;\n            if (child[pos][c]\
    \ == -1) break;\n            pos = child[pos][c];\n            res[i] = pos;\n\
    \        }\n        return res;\n    }\n    vector<int> insert(const string &s)\
    \ {\n        int n = s.size(), pos = 0;\n        for (int i = 0; i < n; i++) {\n\
    \            int c = s[i] - base;\n            if (child[pos][c] == -1) {\n  \
    \              child[pos][c] = par.size();\n                par.push_back(pos);\n\
    \                chr.push_back(c);\n                cnt.push_back(0);\n      \
    \          child.push_back(e());\n                tail.push_back({});\n      \
    \      }\n            pos = child[pos][c];\n            cnt[pos]++;\n        }\n\
    \        tail[pos].push_back(idx++);\n        last.push_back(pos);\n        return\
    \ track(s);\n    }\n    string operator[](int k) const {\n        assert(0 <=\
    \ k && k < int(last.size()));\n        int pos = last[k];\n        string s =\
    \ \"\";\n        while (pos > 0) {\n            s.push_back(base + chr[pos]);\n\
    \            pos = par[pos];\n        }\n        reverse(s.begin(), s.end());\n\
    \        return s;\n    }\n    string kth_smallest(int k) const {\n        int\
    \ pos = 0;\n        string s = \"\";\n        bool fn = true;\n        while (fn)\
    \ {\n            fn = false;\n            k -= tail[pos].size();\n           \
    \ for (int i = 0; i < size; i++) {\n                int nxt = child[pos][i];\n\
    \                if (nxt != -1) {\n                    if (0 <= k && k < cnt[nxt])\
    \ {\n                        pos = nxt;\n                        s.push_back(base\
    \ + chr[pos]);\n                        fn = true;\n                        break;\n\
    \                    }\n                    k -= cnt[nxt];\n                }\n\
    \            }\n        }\n        return s;\n    }\n    int count(const string\
    \ &s) const {\n        int p = track(s).back();\n        return p == -1 ? 0 :\
    \ (int)tail[p].size();\n    }\n    // the number of strings that have s as a prefix\n\
    \    int count_prefix(const string &s) const {\n        int p = track(s).back();\n\
    \        return p == -1 ? 0 : cnt[p];\n    }\n    // the number of strings that\
    \ have s with a prefix\n    int prefix_count(const string &s) const {\n      \
    \  int res = 0;\n        for (int i : track(s)) {\n            if (i == -1) break;\n\
    \            res += tail[i].size();\n        }\n        return res;\n    }\nprivate:\n\
    \    int idx;\n    vector<int> par, chr, cnt, last;\n    vector<array<int, size>>\
    \ child;\n    vector<vector<int>> tail;\n    constexpr array<int, size> e() {\n\
    \        array<int, size> x;\n        x.fill(-1);\n        return x;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/trie.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/trie.hpp
layout: document
redirect_from:
- /library/src/string/trie.hpp
- /library/src/string/trie.hpp.html
title: src/string/trie.hpp
---
