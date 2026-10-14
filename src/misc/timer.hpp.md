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
  bundledCode: "#line 1 \"src/misc/timer.hpp\"\n#include <chrono>\nusing namespace\
    \ std;\n\nstruct Timer {\n    using T = chrono::high_resolution_clock::time_point;\n\
    \    Timer() : start(chrono::high_resolution_clock::now()) {}\n    double now()\
    \ {\n        T end = chrono::high_resolution_clock::now();\n        auto duration\
    \ = chrono::duration_cast<std::chrono::milliseconds>(end - start).count();\n \
    \       return static_cast<double>(duration) / 1000;\n    }\nprivate:\n    T start;\n\
    };\n"
  code: "#include <chrono>\nusing namespace std;\n\nstruct Timer {\n    using T =\
    \ chrono::high_resolution_clock::time_point;\n    Timer() : start(chrono::high_resolution_clock::now())\
    \ {}\n    double now() {\n        T end = chrono::high_resolution_clock::now();\n\
    \        auto duration = chrono::duration_cast<std::chrono::milliseconds>(end\
    \ - start).count();\n        return static_cast<double>(duration) / 1000;\n  \
    \  }\nprivate:\n    T start;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/timer.hpp
  requiredBy: []
  timestamp: '2025-06-26 18:47:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/timer.hpp
layout: document
redirect_from:
- /library/src/misc/timer.hpp
- /library/src/misc/timer.hpp.html
title: src/misc/timer.hpp
---
