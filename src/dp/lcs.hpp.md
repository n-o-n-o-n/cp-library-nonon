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
  bundledCode: "#line 2 \"src/dp/lcs.hpp\"\n#include <vector>\n#include <string>\n\
    using namespace std;\n\ntemplate<typename T>\nvector<T> longest_common_subsequence(const\
    \ vector<T> &s, const vector<T> &t) {\n    int n = s.size(), m = t.size();\n \
    \   vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));\n    for (int i = 0;\
    \ i < n; i++) {\n        for (int j = 0; j < m; j++) {\n            dp[i + 1][j\
    \ + 1] = max(dp[i][j + 1], dp[i + 1][j]);\n            if (s[i] == t[j]) {\n \
    \               dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);\n    \
    \        }\n        }\n    }\n    vector<T> res;\n    int i = n - 1, j = m - 1;\n\
    \    while (i >= 0 && j >= 0) {\n        if (s[i] == t[j]) {\n            res.push_back(s[i]);\n\
    \            i--, j--;\n        } else {\n            (dp[i][j] == dp[i + 1][j]\
    \ ? i-- : j--);\n        }\n    }\n    reverse(res.begin(), res.end());\n    return\
    \ res;\n}\n\nstring longest_common_subsequence(const string &s, const string &t)\
    \ {\n    vector<char> a(s.begin(), s.end()), b(t.begin(), t.end());\n    vector<char>\
    \ c = longest_common_subsequence(a, b);\n    return string(c.begin(), c.end());\n\
    }\n"
  code: "#pragma once\n#include <vector>\n#include <string>\nusing namespace std;\n\
    \ntemplate<typename T>\nvector<T> longest_common_subsequence(const vector<T> &s,\
    \ const vector<T> &t) {\n    int n = s.size(), m = t.size();\n    vector<vector<int>>\
    \ dp(n + 1, vector<int>(m + 1, 0));\n    for (int i = 0; i < n; i++) {\n     \
    \   for (int j = 0; j < m; j++) {\n            dp[i + 1][j + 1] = max(dp[i][j\
    \ + 1], dp[i + 1][j]);\n            if (s[i] == t[j]) {\n                dp[i\
    \ + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);\n            }\n        }\n\
    \    }\n    vector<T> res;\n    int i = n - 1, j = m - 1;\n    while (i >= 0 &&\
    \ j >= 0) {\n        if (s[i] == t[j]) {\n            res.push_back(s[i]);\n \
    \           i--, j--;\n        } else {\n            (dp[i][j] == dp[i + 1][j]\
    \ ? i-- : j--);\n        }\n    }\n    reverse(res.begin(), res.end());\n    return\
    \ res;\n}\n\nstring longest_common_subsequence(const string &s, const string &t)\
    \ {\n    vector<char> a(s.begin(), s.end()), b(t.begin(), t.end());\n    vector<char>\
    \ c = longest_common_subsequence(a, b);\n    return string(c.begin(), c.end());\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/lcs.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/dp/lcs.hpp
layout: document
redirect_from:
- /library/src/dp/lcs.hpp
- /library/src/dp/lcs.hpp.html
title: src/dp/lcs.hpp
---
