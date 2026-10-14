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
  bundledCode: "#line 2 \"src/string/aho_corasick.hpp\"\n#include <array>\n#include\
    \ <cassert>\n#include <queue>\n#include <vector>\nusing namespace std;\n\ntemplate<int\
    \ size, char base>\nstruct aho_corasick {\n    aho_corasick() : par(1, 0), chr(1,\
    \ -1), last(0), fail(1, 0), cnt(1, 0), child(1, e()), built(false) {}\n    void\
    \ insert(const string &s) {\n        int n = s.size(), pos = 0;\n        for (int\
    \ i = 0; i < n; i++) {\n            int c = s[i] - base;\n            if (child[pos][c]\
    \ == -1) {\n                child[pos][c] = par.size();\n                par.push_back(pos);\n\
    \                chr.push_back(c);\n                fail.push_back(0);\n     \
    \           cnt.push_back(0);\n                child.push_back(e());\n       \
    \     }\n            pos = child[pos][c];\n        }\n        cnt[pos]++;\n  \
    \      last.push_back(pos);\n    }\n    void build() {\n        queue<int> q;\n\
    \        for (int i = 0; i < size; i++) {\n            int &nxt = child[0][i];\n\
    \            if (nxt != -1) {\n                fail[nxt] = 0;\n              \
    \  q.push(nxt);\n            } else {\n                nxt = 0;\n            }\n\
    \        }\n        while (q.size()) {\n            int u = q.front();\n     \
    \       q.pop();\n            cnt[u] += cnt[fail[u]];\n            for (int i\
    \ = 0; i < size; i++) {\n                int &nxt = child[u][i];\n           \
    \     int p = child[fail[u]][i];\n                if (nxt != -1) {\n         \
    \           fail[nxt] = p;\n                    q.push(nxt);\n               \
    \ } else {\n                    nxt = p;\n                }\n            }\n \
    \       }\n        built = true;\n    }\n    template<typename T = int>\n    T\
    \ match(const string &s) const {\n        assert(built);\n        int n = s.size(),\
    \ pos = 0;\n        T res = 0;\n        for (int i = 0; i < n; i++) {\n      \
    \      int c = s[i] - base;\n            pos = child[pos][c];\n            res\
    \ += cnt[pos];\n        }\n        return res;\n    }\n// private:\n    vector<int>\
    \ par, chr, last, fail, cnt;\n    vector<array<int, size>> child;\n    bool built;\n\
    \    constexpr array<int, size> e() {\n        array<int, size> x;\n        x.fill(-1);\n\
    \        return x;\n    }\n};\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <queue>\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate<int size, char base>\nstruct aho_corasick\
    \ {\n    aho_corasick() : par(1, 0), chr(1, -1), last(0), fail(1, 0), cnt(1, 0),\
    \ child(1, e()), built(false) {}\n    void insert(const string &s) {\n       \
    \ int n = s.size(), pos = 0;\n        for (int i = 0; i < n; i++) {\n        \
    \    int c = s[i] - base;\n            if (child[pos][c] == -1) {\n          \
    \      child[pos][c] = par.size();\n                par.push_back(pos);\n    \
    \            chr.push_back(c);\n                fail.push_back(0);\n         \
    \       cnt.push_back(0);\n                child.push_back(e());\n           \
    \ }\n            pos = child[pos][c];\n        }\n        cnt[pos]++;\n      \
    \  last.push_back(pos);\n    }\n    void build() {\n        queue<int> q;\n  \
    \      for (int i = 0; i < size; i++) {\n            int &nxt = child[0][i];\n\
    \            if (nxt != -1) {\n                fail[nxt] = 0;\n              \
    \  q.push(nxt);\n            } else {\n                nxt = 0;\n            }\n\
    \        }\n        while (q.size()) {\n            int u = q.front();\n     \
    \       q.pop();\n            cnt[u] += cnt[fail[u]];\n            for (int i\
    \ = 0; i < size; i++) {\n                int &nxt = child[u][i];\n           \
    \     int p = child[fail[u]][i];\n                if (nxt != -1) {\n         \
    \           fail[nxt] = p;\n                    q.push(nxt);\n               \
    \ } else {\n                    nxt = p;\n                }\n            }\n \
    \       }\n        built = true;\n    }\n    template<typename T = int>\n    T\
    \ match(const string &s) const {\n        assert(built);\n        int n = s.size(),\
    \ pos = 0;\n        T res = 0;\n        for (int i = 0; i < n; i++) {\n      \
    \      int c = s[i] - base;\n            pos = child[pos][c];\n            res\
    \ += cnt[pos];\n        }\n        return res;\n    }\n// private:\n    vector<int>\
    \ par, chr, last, fail, cnt;\n    vector<array<int, size>> child;\n    bool built;\n\
    \    constexpr array<int, size> e() {\n        array<int, size> x;\n        x.fill(-1);\n\
    \        return x;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/string/aho_corasick.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/aho_corasick.hpp
layout: document
redirect_from:
- /library/src/string/aho_corasick.hpp
- /library/src/string/aho_corasick.hpp.html
title: src/string/aho_corasick.hpp
---
