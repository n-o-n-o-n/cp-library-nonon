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
  bundledCode: "#line 2 \"src/data_structure/queue/erasable_priority_queue.hpp\"\n\
    #include <cassert>\n#include <queue>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename T, typename Container = vector<T>, typename Compare = less<T>>\n\
    struct erasable_priority_queue {\n    erasable_priority_queue() = default;\n \
    \   void push(const T &x) {\n        pq.push(make_pair(x, time++));\n    }\n \
    \   void erase(const T &x) {\n        del.push(make_pair(x, time++));\n    }\n\
    \    T top() {\n        normalize();\n        assert(pq.size());\n        return\
    \ pq.top().first;\n    }\n    void pop() {\n        normalize();\n        assert(pq.size());\n\
    \        pq.pop();\n    }\nprivate:\n    using P = pair<T, int>;\n    struct PairCompare\
    \ {\n        Compare comp;\n        bool operator()(const P &p, const P &q) const\
    \ {\n            return comp(q.first, p.first) || (p.first == q.first && p.first\
    \ > q.first);\n        }\n    };\n    int time;\n    priority_queue<P, vector<P>,\
    \ PairCompare> pq, del;\n    void normalize() {\n        while (pq.size() && del.size())\
    \ {\n            auto [qv, qt] = pq.top();\n            auto [dv, dt] = del.top();\n\
    \            if (qv == dv) {\n                del.pop();\n                if (qt\
    \ < dt) pq.pop();\n            } else if (Compare()(dv, dv)) {\n             \
    \   del.pop();\n            } else {\n                break;\n            }\n\
    \        }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <queue>\n#include <vector>\nusing\
    \ namespace std;\n\ntemplate<typename T, typename Container = vector<T>, typename\
    \ Compare = less<T>>\nstruct erasable_priority_queue {\n    erasable_priority_queue()\
    \ = default;\n    void push(const T &x) {\n        pq.push(make_pair(x, time++));\n\
    \    }\n    void erase(const T &x) {\n        del.push(make_pair(x, time++));\n\
    \    }\n    T top() {\n        normalize();\n        assert(pq.size());\n    \
    \    return pq.top().first;\n    }\n    void pop() {\n        normalize();\n \
    \       assert(pq.size());\n        pq.pop();\n    }\nprivate:\n    using P =\
    \ pair<T, int>;\n    struct PairCompare {\n        Compare comp;\n        bool\
    \ operator()(const P &p, const P &q) const {\n            return comp(q.first,\
    \ p.first) || (p.first == q.first && p.first > q.first);\n        }\n    };\n\
    \    int time;\n    priority_queue<P, vector<P>, PairCompare> pq, del;\n    void\
    \ normalize() {\n        while (pq.size() && del.size()) {\n            auto [qv,\
    \ qt] = pq.top();\n            auto [dv, dt] = del.top();\n            if (qv\
    \ == dv) {\n                del.pop();\n                if (qt < dt) pq.pop();\n\
    \            } else if (Compare()(dv, dv)) {\n                del.pop();\n   \
    \         } else {\n                break;\n            }\n        }\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/queue/erasable_priority_queue.hpp
  requiredBy: []
  timestamp: '2025-04-03 14:15:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/queue/erasable_priority_queue.hpp
layout: document
redirect_from:
- /library/src/data_structure/queue/erasable_priority_queue.hpp
- /library/src/data_structure/queue/erasable_priority_queue.hpp.html
title: src/data_structure/queue/erasable_priority_queue.hpp
---
