---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/number_theory/discrete_logarithm.hpp
    title: src/math/number_theory/discrete_logarithm.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/number_theory/mod_log.hpp
    title: src/math/number_theory/mod_log.hpp
  - icon: ':question:'
    path: src/modint/dynamic_modint.hpp
    title: src/modint/dynamic_modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/math/number_theory/mod_log.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n\n#line 2 \"src/modint/dynamic_modint.hpp\"\
    \n#include <algorithm>\n#include <cassert>\nusing namespace std;\n\nstruct modint\
    \ {\n    modint() : x(0) {}\n    modint(long long v) {\n        long long y =\
    \ v % m();\n        if (y < 0) y += m();\n        x = (unsigned int)(y);\n   \
    \ }\n    static void set_mod(int _m) { MOD = _m; }\n    static modint raw(int\
    \ v) {\n        modint a;\n        a.x = v;\n        return a;\n    }\n    static\
    \ int mod() { return m(); }\n    unsigned int val() const { return x; }\n    modint&\
    \ operator++() {\n        x++;\n        if (x == m()) x = 0;\n        return *this;\n\
    \    }\n    modint& operator--() {\n        if (x == 0) x = m();\n        x--;\n\
    \        return *this;\n    }\n    modint operator++(int) {\n        modint res\
    \ = *this;\n        ++*this;\n        return res;\n    }\n    modint operator--(int)\
    \ {\n        modint res = *this;\n        --*this;\n        return res;\n    }\n\
    \    modint& operator+=(const modint &r) {\n        x += r.x;\n        if (x >=\
    \ m()) x -= m();\n        return *this;\n    }\n    modint& operator-=(const modint\
    \ &r) {\n        x -= r.x;\n        if (x >= m()) x += m();\n        return *this;\n\
    \    }\n    modint& operator*=(const modint &r) {\n        unsigned long long\
    \ y = x;\n        y *= r.x;\n        x = (unsigned int)(y % m());\n        return\
    \ *this;\n    }\n    modint &operator/=(const modint &r) {\n        return *this\
    \ = *this * r.inv();\n    }\n    friend modint operator+(const modint &a, const\
    \ modint &b) {\n        return modint(a) += b;\n    }\n    friend modint operator-(const\
    \ modint &a, const modint &b) {\n        return modint(a) -= b;\n    }\n    friend\
    \ modint operator*(const modint &a, const modint &b) {\n        return modint(a)\
    \ *= b;\n    }\n    friend modint operator/(const modint &a, const modint &b)\
    \ {\n        return modint(a) /= b;\n    }\n    friend bool operator==(const modint\
    \ &a, const modint &b) {\n        return a.x == b.x;\n    }\n    friend bool operator!=(const\
    \ modint &a, const modint &b) {\n        return a.x != b.x;\n    }\n    modint\
    \ operator+() const { return *this; }\n    modint operator-() const { return modint()\
    \ - *this; }\n    modint pow(long long k) const {\n        assert(k >= 0);\n \
    \       modint a = *this;\n        modint res = 1;\n        while (k > 0) {\n\
    \            if (k & 1) res *= a;\n            a *= a;\n            k >>= 1;\n\
    \        }\n        return res;\n    }\n    modint inv() const {\n        long\
    \ long a = x, b = m(), u = 1, v = 0;\n        while (b > 0) {\n            long\
    \ long t = a / b;\n            a -= t * b;\n            swap(a, b);\n        \
    \    u -= t * v;\n            swap(u, v);\n        }\n        return modint(u);\n\
    \    }\nprivate:\n    unsigned int x;\n    static unsigned int MOD;\n    static\
    \ unsigned int m() { return MOD; }\n};\nunsigned int modint::MOD = -1;\n#line\
    \ 2 \"src/math/number_theory/discrete_logarithm.hpp\"\n#include <unordered_set>\n\
    using namespace std;\n\ntemplate<typename ActSet>\nstruct discrete_logarithm {\n\
    \    using S = typename ActSet::S;\n    using F = typename ActSet::F;\n    template<typename\
    \ H>\n    static long long solve(F f, S s, S t, long long p, const H &h) {\n \
    \       long long ht = h(t);\n        long long m = 1;\n        do {\n       \
    \     m++;\n        } while (m * m <= p);\n        unordered_set<long long> a;\n\
    \        a.reserve(m);\n        for (int k = 0; k < m; k++) {\n            t =\
    \ ActSet::mapping(f, t);\n            a.insert(h(t));\n        }\n        F g\
    \ = ActSet::id();\n        {\n            long long mm = m;\n            F ff\
    \ = f;\n            while (m > 0) {\n                if (m & 1) g = ActSet::comp(g,\
    \ f);\n                f = ActSet::comp(f, f);\n                m >>= 1;\n   \
    \         }\n            m = mm;\n            f = ff;\n        }\n        for\
    \ (int k = 0, flag = 0; k <= m; k++) {\n            t = ActSet::mapping(g, s);\n\
    \            if (a.count(h(t))) {\n                for (int i = 0; i < m; i++)\
    \ {\n                    if (h(s) == ht) {\n                        return m *\
    \ k + i;\n                    }\n                    s = ActSet::mapping(f, s);\n\
    \                }\n                if (flag) return -1;\n                flag\
    \ = 1;\n            }\n            s = t;\n        }\n        return -1;\n   \
    \ }\n};\n#line 4 \"src/math/number_theory/mod_log.hpp\"\nusing namespace std;\n\
    \nint mod_log(int a, int b, int p) {\n    modint::set_mod(p);\n    struct Fp {\n\
    \        using S = modint;\n        using F = modint;\n        static F comp(F\
    \ f, F g) {\n            return f * g;\n        }\n        static F id() {\n \
    \           return 1;\n        }\n        static S mapping(F f, S x) {\n     \
    \       return f * x;\n        }\n    };\n    return discrete_logarithm<Fp>::solve(a,\
    \ 1, b, p, [&](modint x){\n        return x.val();\n    });\n}\n#line 4 \"test/math/number_theory/mod_log.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int T;\n    cin >> T;\n    for (int X, Y, M; T--; )\
    \ {\n        cin >> X >> Y >> M;\n        cout << mod_log(X, Y, M) << '\\n';\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include \"../../../src/math/number_theory/mod_log.hpp\"\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ T;\n    cin >> T;\n    for (int X, Y, M; T--; ) {\n        cin >> X >> Y >>\
    \ M;\n        cout << mod_log(X, Y, M) << '\\n';\n    }\n}"
  dependsOn:
  - src/math/number_theory/mod_log.hpp
  - src/modint/dynamic_modint.hpp
  - src/math/number_theory/discrete_logarithm.hpp
  isVerificationFile: true
  path: test/math/number_theory/mod_log.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:06:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/number_theory/mod_log.test.cpp
layout: document
redirect_from:
- /verify/test/math/number_theory/mod_log.test.cpp
- /verify/test/math/number_theory/mod_log.test.cpp.html
title: test/math/number_theory/mod_log.test.cpp
---
