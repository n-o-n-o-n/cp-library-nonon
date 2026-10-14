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
    - https://maspypy.com/o1-mod-inv-mod-pow
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../math/number_theory/constexpr_primality_test.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <vector>\nusing\
    \ namespace std;\n#include \"../modint/modint.hpp\"\n#include \"../math/number_theory/constexpr_primality_test.hpp\"\
    \n\n// https://maspypy.com/o1-mod-inv-mod-pow \nnamespace Fp {\n\nstatic constexpr\
    \ int n = 1 << 10;\nstatic constexpr int sz = 1 << 21;\n\ntemplate<int p>\nstruct\
    \ container {\n    static_assert(constexpr_is_prime(p));\n    static_assert((int)1e8\
    \ < p && p < (1 << 30));\n    using mint = modint<p>;\n    inline static array<mint,\
    \ sz + 1> fac, finv;\n    inline static array<mint, 2 * sz + 1> inv;\n    inline\
    \ static array<pair<int, int>, n * n + 1> frac;\n    inline static bool built\
    \ = false;\n    static void build_inv() {\n        fac[0] = 1;\n        for (int\
    \ i = 1; i <= sz; i++) fac[i] = i * fac[i - 1];\n        finv[sz] = fac[sz].inv();\n\
    \        for (int i = sz; i >= 1; i--) finv[i - 1] = i * finv[i];\n        for\
    \ (int i = 1; i <= sz; i++) {\n            inv[sz + i] = finv[i] * fac[i - 1];\n\
    \            inv[sz - i] = -inv[sz + i];\n        }\n    }\n    static void build_frac()\
    \ {\n        vector<tuple<int, int, int, int>> st;\n        st.reserve(2 * n);\n\
    \        st.emplace_back(0, 1, 1, 1);\n        while (st.size()) {\n         \
    \   auto [a, b, c, d] = st.back();\n            st.pop_back();\n            if\
    \ (b + d < 2 * n) {\n                st.emplace_back(a + c, b + d, c, d);\n  \
    \              st.emplace_back(a, b, a + c, b + d);\n            } else {\n  \
    \              int l = (long long)a * p / (b << 10);\n                int r =\
    \ (long long)c * p / (d << 10);\n                frac[l] = {a, b};\n         \
    \       frac[r] = {c, d};\n                a = min(a, c);\n                b =\
    \ min(b, d);\n                for (int i = l + 1; i < r; i++) frac[i] = {a, b};\n\
    \            }\n        }\n    }\n    static void build() {\n        if (built)\
    \ return;\n        built = true;\n        build_inv();\n        build_frac();\n\
    \    }\n};\n\ntemplate<int p>\nint inv(int x) {\n    container<p>::build();\n\
    \    assert(0 < x && x < p);\n    auto [c, b] = container<p>::frac[x >> 10];\n\
    \    int a = (long long)b * x - (long long)c * p;\n    return (container<p>::inv[sz\
    \ + a] * b).val();\n}\n\n} // namespace Fp"
  dependsOn: []
  isVerificationFile: false
  path: src/modint/Fp.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/modint/Fp.hpp
layout: document
redirect_from:
- /library/src/modint/Fp.hpp
- /library/src/modint/Fp.hpp.html
title: src/modint/Fp.hpp
---
