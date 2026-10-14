---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/misc/base64.hpp
  bundledCode: "#line 2 \"src/misc/base64.hpp\"\n#include <algorithm>\n#include <vector>\n\
    #include <string>\nusing namespace std;\n\n// https://nyaannyaan.github.io/library/misc/base64.hpp\n\
    namespace base64 {\n\nconstexpr char base[66] = \"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/.\"\
    ;\n\ninline int ibase(char c) {\n    if ('A' <= c && c <= 'Z') return c - 'A';\n\
    \    if ('a' <= c && c <= 'z') return c - 'a' + 26;\n    if ('0' <= c && c <=\
    \ '9') return c - '0' + 52;\n    if (c == '+') return 62;\n    if (c == '/') return\
    \ 63;\n    return 64;\n}\n\ntemplate<typename T>\nstring encode(const vector<T>\
    \ &v) {\n    int n = v.size();\n    if (n == 0) return \"\";\n    T x = v[0],\
    \ y = v[0];\n    for (const auto &e : v) x = min(x, e), y = max(y, e);\n    int\
    \ b = max<int>(6, x < 0 ? sizeof(T) * 8 : (y == 0 ? 0 : 64 - __builtin_clzll(y)));\n\
    \    string s((b * n + 11) / 6, 0);\n    s[0] = b;\n    for (int i = 0; i < n;\
    \ i++) {\n        for (int j = 0; j < b; j++) {\n            if ((v[i] >> j) &\
    \ 1) s[(i * b + j) / 6 + 1] |= 1 << ((i * b + j) % 6);\n        }\n    }\n   \
    \ for (auto &c : s) c = base[(int)c];\n    return s;\n}\n\ntemplate<typename T\
    \ = long long>\nvector<T> decode(const string &s) {\n    if (s.empty()) return\
    \ {};\n    int b = ibase(s[0]);\n    if (b == 0) return {};\n    int n = s.size()\
    \ - 1;\n    vector<T> v(n * 6 / b, 0);\n    for (int i = 0; i < n; i++) {\n  \
    \      int c = ibase(s[i + 1]);\n        for (int j = 0; j < 6; j++) {\n     \
    \       if ((c >> j) & 1) {\n                v[(i * 6 + j) / b] |= T(1) << ((i\
    \ * 6 + j) % b);\n            }\n        }\n    }\n    return v;\n}\n\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include <string>\n\
    using namespace std;\n\n// https://nyaannyaan.github.io/library/misc/base64.hpp\n\
    namespace base64 {\n\nconstexpr char base[66] = \"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/.\"\
    ;\n\ninline int ibase(char c) {\n    if ('A' <= c && c <= 'Z') return c - 'A';\n\
    \    if ('a' <= c && c <= 'z') return c - 'a' + 26;\n    if ('0' <= c && c <=\
    \ '9') return c - '0' + 52;\n    if (c == '+') return 62;\n    if (c == '/') return\
    \ 63;\n    return 64;\n}\n\ntemplate<typename T>\nstring encode(const vector<T>\
    \ &v) {\n    int n = v.size();\n    if (n == 0) return \"\";\n    T x = v[0],\
    \ y = v[0];\n    for (const auto &e : v) x = min(x, e), y = max(y, e);\n    int\
    \ b = max<int>(6, x < 0 ? sizeof(T) * 8 : (y == 0 ? 0 : 64 - __builtin_clzll(y)));\n\
    \    string s((b * n + 11) / 6, 0);\n    s[0] = b;\n    for (int i = 0; i < n;\
    \ i++) {\n        for (int j = 0; j < b; j++) {\n            if ((v[i] >> j) &\
    \ 1) s[(i * b + j) / 6 + 1] |= 1 << ((i * b + j) % 6);\n        }\n    }\n   \
    \ for (auto &c : s) c = base[(int)c];\n    return s;\n}\n\ntemplate<typename T\
    \ = long long>\nvector<T> decode(const string &s) {\n    if (s.empty()) return\
    \ {};\n    int b = ibase(s[0]);\n    if (b == 0) return {};\n    int n = s.size()\
    \ - 1;\n    vector<T> v(n * 6 / b, 0);\n    for (int i = 0; i < n; i++) {\n  \
    \      int c = ibase(s[i + 1]);\n        for (int j = 0; j < 6; j++) {\n     \
    \       if ((c >> j) & 1) {\n                v[(i * 6 + j) / b] |= T(1) << ((i\
    \ * 6 + j) % b);\n            }\n        }\n    }\n    return v;\n}\n\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/base64.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/base64.hpp
layout: document
redirect_from:
- /library/src/misc/base64.hpp
- /library/src/misc/base64.hpp.html
title: src/misc/base64.hpp
---
