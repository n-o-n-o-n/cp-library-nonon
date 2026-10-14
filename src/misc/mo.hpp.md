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
  bundledCode: "#line 2 \"src/misc/mo.hpp\"\n#include <algorithm>\n#include <cmath>\n\
    #include <numeric>\n#include <vector>\nusing namespace std;\n\nstruct MO {\n \
    \   MO(int _n, int _q) : n(_n), q(_q) { querys.reserve(q); }\n    void add_query(int\
    \ l, int r) { querys.emplace_back(l, r); }\n    template<typename EXL, typename\
    \ EXR, typename SHL, typename SHR, typename O>\n    void run(const EXL &exl, const\
    \ EXR &exr, const SHL &shl, const SHR &shr, const O &out) {\n        const int\
    \ b = clamp(int(sqrtl(q * 0.66)), 1, n);\n        vector<int> ord(q);\n      \
    \  iota(ord.begin(), ord.end(), 0);\n        sort(ord.begin(), ord.end(), [&](int\
    \ i, int j) {\n            auto [li, ri] = querys[i];\n            auto [lj, rj]\
    \ = querys[j];\n            int bi = li / b, bj = lj / b;\n            return\
    \ bi == bj ? bi & 1 ? ri > rj : ri < rj : bi < bj;\n        });\n        int l\
    \ = 0, r = 0;\n        for (int i : ord) {\n            auto [li, ri] = querys[i];\n\
    \            while (l > li) exl(--l);\n            while (r < ri) exr(r++);\n\
    \            while (l < li) shl(l++);\n            while (r > ri) shr(--r);\n\
    \            out(i);\n        }\n    }\n    template<typename EX, typename SH,\
    \ typename O>\n    void run(const EX &ex, const SH &sh, const O &out) {\n    \
    \    run(ex, ex, sh, sh, out);\n    }\nprivate:\n    int n, q;\n    vector<pair<int,\
    \ int>> querys;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cmath>\n#include <numeric>\n\
    #include <vector>\nusing namespace std;\n\nstruct MO {\n    MO(int _n, int _q)\
    \ : n(_n), q(_q) { querys.reserve(q); }\n    void add_query(int l, int r) { querys.emplace_back(l,\
    \ r); }\n    template<typename EXL, typename EXR, typename SHL, typename SHR,\
    \ typename O>\n    void run(const EXL &exl, const EXR &exr, const SHL &shl, const\
    \ SHR &shr, const O &out) {\n        const int b = clamp(int(sqrtl(q * 0.66)),\
    \ 1, n);\n        vector<int> ord(q);\n        iota(ord.begin(), ord.end(), 0);\n\
    \        sort(ord.begin(), ord.end(), [&](int i, int j) {\n            auto [li,\
    \ ri] = querys[i];\n            auto [lj, rj] = querys[j];\n            int bi\
    \ = li / b, bj = lj / b;\n            return bi == bj ? bi & 1 ? ri > rj : ri\
    \ < rj : bi < bj;\n        });\n        int l = 0, r = 0;\n        for (int i\
    \ : ord) {\n            auto [li, ri] = querys[i];\n            while (l > li)\
    \ exl(--l);\n            while (r < ri) exr(r++);\n            while (l < li)\
    \ shl(l++);\n            while (r > ri) shr(--r);\n            out(i);\n     \
    \   }\n    }\n    template<typename EX, typename SH, typename O>\n    void run(const\
    \ EX &ex, const SH &sh, const O &out) {\n        run(ex, ex, sh, sh, out);\n \
    \   }\nprivate:\n    int n, q;\n    vector<pair<int, int>> querys;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/mo.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/mo.hpp
layout: document
redirect_from:
- /library/src/misc/mo.hpp
- /library/src/misc/mo.hpp.html
title: src/misc/mo.hpp
---
