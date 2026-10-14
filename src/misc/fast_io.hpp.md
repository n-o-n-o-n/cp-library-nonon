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
    - https://judge.yosupo.jp/submission/212769
  bundledCode: "#line 2 \"src/misc/fast_io.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <concepts>\n#include <cstring>\n#include <filesystem>\n#include <iostream>\n\
    #include <vector>\nusing namespace std;\n\n// https://judge.yosupo.jp/submission/212769\n\
    namespace fastio {\n\nstatic constexpr int buf_size = 1 << 21;\n\ninline struct\
    \ fast_read {\n    fast_read() : fast_read(stdin) {}\n    fast_read(const filesystem::path\
    \ &p) : fast_read(fopen(p.c_str(), \"r\")) {}\n    fast_read(FILE *_stream) :\
    \ stream(_stream), start(buf.data()), end(start + buf_size), ptr(end) { load();\
    \ }\n    ~fast_read() { if (stream != stdin) fclose(stream); }\n    fast_read(const\
    \ fast_read &) = default;\n    fast_read &operator=(const fast_read &) = default;\n\
    \    template<unsigned_integral T>\n    void operator()(T &x) {\n        skip_space();\n\
    \        load<64>();\n        parse(x);\n    }\n    template<signed_integral T>\n\
    \    void operator()(T &x) {\n        skip_space();\n        load<64>();\n   \
    \     make_unsigned_t<T> y;\n        if (*ptr == '-') {\n            ptr++;\n\
    \            parse(y);\n            y = -y;\n        } else {\n            parse(y);\n\
    \        }\n        x = y;\n    }\n    void operator()(char &c) {\n        skip_space();\n\
    \        load<64>();\n        c = *ptr++;\n    }\n    void operator()(string &s)\
    \ {\n        s = \"\";\n        skip_space();\n        load<64>();\n        while\
    \ (*ptr > ' ' && *ptr != '\\0') {\n            s.push_back(*ptr++);\n        }\n\
    \        ptr++;\n    }\n    template<typename T>\n    void operator()(vector<T>\
    \ &v) {\n        for (auto &e : v) (*this)(e);\n    }\n    template<typename...\
    \ Ts> requires(sizeof...(Ts) != 1)\n    void operator() (Ts &... xs) {\n     \
    \   ((*this)(xs), ...);\n    }\nprivate:\n    FILE *stream;\n    array<char, buf_size>\
    \ buf{};\n    char *start, *end, *ptr;\n    void skip_space() {\n        while\
    \ (*ptr <= ' ') ptr++;\n    }\n    template<int n = 0> void load() {\n       \
    \ const auto i = end - ptr;\n        if (i <= n) {\n            ignore = fread(copy_n(ptr,\
    \ i, start), 1, buf_size - i, stream);\n            ptr = start;\n        }\n\
    \    }\n    template<unsigned_integral T>\n    void parse(T &x) {\n        typename\
    \ common_type<T, uint64_t>::type y = 0;\n        while (true) {\n            uint64_t\
    \ z;\n            memcpy(&z, ptr, 8);\n            if (!((z -= 0x3030303030303030)\
    \ & 0x8080808080808080)) {\n                z = (z * 10 + (z >> 8)) & 0xff00ff00ff00ff;\n\
    \                z = (z * 100 + (z >> 16)) & 0xffff0000ffff;\n               \
    \ z = (z * 10000 + (z >> 32)) & 0xffffffff;\n                y = 100000000 * y\
    \ + z;\n                ptr += 8;\n            } else {\n                break;\n\
    \            }\n        }\n        {\n            uint32_t z;\n            memcpy(&z,\
    \ ptr, 4);\n            if (!((z -= 0x30303030) & 0x80808080)) {\n           \
    \     z = (z * 10 + (z >> 8)) & 0xff00ff;\n                z = (z * 100 + (z >>\
    \ 16)) & 0xffff;\n                y = 10000 * y + z;\n                ptr += 4;\n\
    \            }\n        }\n        {\n            uint16_t z;\n            memcpy(&z,\
    \ ptr, 2);\n            if (!((z -= 0x3030) & 0x8080)) {\n                z =\
    \ (z * 10 + (z >> 8)) & 0xff;\n                y = 100 * y + z;\n            \
    \    ptr += 2;\n            }\n        }\n        if (' ' < *ptr) {\n        \
    \    y *= 10;\n            y += *ptr++ - '0';\n        }\n        ptr++;\n   \
    \     x = static_cast<T>(y);\n    }\n} Read;\n\ninline struct fast_write {\n \
    \   fast_write() : fast_write(stdout) {}\n    fast_write(const filesystem::path\
    \ &p) : fast_write(fopen(p.c_str(), \"w\")) {}\n    fast_write(FILE *_stream)\
    \ : stream(_stream), start(buf.data()), end(start + buf_size), ptr(start) {}\n\
    \    ~fast_write() {\n        flush();\n        if (stream != stdout) fclose(stream);\n\
    \    }\n    fast_write(const fast_write &) = default;\n    fast_write &operator=(const\
    \ fast_write &) = default;\n    template<unsigned_integral T>\n    void operator()(T\
    \ x) {\n        flush<digits<T>>();\n        write(x);\n    }\n    template<signed_integral\
    \ T>\n    void operator()(T x) {\n        flush<1 + digits<T>>();\n        make_unsigned_t<T>\
    \ y = x;\n        if (x < 0) {\n            *ptr++ = '-';\n            write(static_cast<make_unsigned_t<T>>(-y));\n\
    \        } else {\n            write(y);\n        }\n    }\n    void operator()(char\
    \ c) {\n        flush<1>();\n        *ptr++ = c;\n    }\n    void operator()(string_view\
    \ s) {\n        while (!s.empty()) {\n            flush<0>();\n            const\
    \ auto n = min(ssize(s), end - ptr);\n            if (n == buf_size) {\n     \
    \           fwrite(s.data(), 1, buf_size, stream);\n            } else {\n   \
    \             ptr = copy_n(s.data(), n, ptr);\n            }\n            s.remove_prefix(n);\n\
    \        }\n        flush<0>();\n    }\n    void operator()(string s) {\n    \
    \    (*this)(string_view(s));\n    }\n    void operator()(const char* s) {\n \
    \       (*this)(string_view(s));\n    }\n    template<typename T>\n    void operator()(vector<T>\
    \ v) {\n        int n = v.size();\n        for (int i = 0; i < n; i++) {\n   \
    \         (*this)(v[i]);\n            if (i < n - 1) (*this)(' ');\n        }\n\
    \    }\n    template<typename... Ts>\n    requires(sizeof...(Ts) != 1)\n    void\
    \ operator()(Ts &&...xs) {\n        ((*this)(std::forward<Ts>(xs)), ...);\n  \
    \  }\n    template<char End = '\\n', char Sep = ' ', typename T, typename... Ts>\n\
    \    void ln(T &&x, Ts &&...xs) {\n        (*this)(std::forward<T>(x));\n    \
    \    if constexpr (sizeof...(Ts) == 0) {\n            *ptr++ = End;\n        }\
    \ else {\n            *ptr++ = Sep;\n            ln<End, Sep>(std::forward<Ts>(xs)...);\n\
    \        }\n    }\nprivate:\n    FILE *stream;\n    array<char, buf_size> buf{};\n\
    \    char *start, *end, *ptr;\n    template<typename T>\n    static constexpr\
    \ int digits = numeric_limits<T>::digits10 + 1;\n    template<typename T>\n  \
    \  static constexpr auto pow10 = [] {\n        array<T, digits<T>> res;\n    \
    \    res[0] = 1;\n        for (int i = 1; i < digits<T>; i++) {\n            res[i]\
    \ = 10 * res[i - 1];\n        }\n        return res;\n    } ();\n    static constexpr\
    \ auto lut = [] {\n        array<char, 40000> res;\n        char *p = res.data();\n\
    \        char a, b, c, d;\n        a = b = c = d = '0';\n        do {\n      \
    \      *p++ = a;\n            *p++ = b;\n            *p++ = c;\n            *p++\
    \ = d;\n        } while (d++ < '9' || (d = '0', c++ < '9' || (c = '0', b++ < '9'\
    \ || (b = '0', a++ < '9'))));\n        return res;\n    } ();\n    template<int\
    \ n = buf_size>\n    void flush() {\n        if (end - ptr <= n) {\n         \
    \   fwrite(start, 1, ptr - start, stream);\n            ptr = start;\n       \
    \ }\n    }\n    template<int n = 4>\n    void le4(uint64_t x) {\n        if constexpr\
    \ (1 < n) {\n            if (x < pow10<uint64_t>[n - 1]) {\n                le4<n\
    \ - 1>(x);\n                return;\n            }\n        }\n        ptr = copy_n(&lut[x\
    \ * 4 + (4 - n)], n, ptr);\n    }\n    template<int n>\n    void w4(uint64_t x)\
    \ {\n        if constexpr (0 < n) {\n            ptr = copy_n(&lut[x / pow10<uint64_t>[n\
    \ - 4] * 4], 4, ptr);\n            w4<n - 4>(x % pow10<uint64_t>[n - 4]);\n  \
    \      }\n    }\n    template<int n>\n    void write(uint64_t x) {\n        if\
    \ constexpr (n < digits<uint64_t>) {\n            if (pow10<uint64_t>[n] <= static_cast<uint64_t>(x))\
    \ {\n                write<n + 4>(x);\n                return;\n            }\n\
    \        }\n        le4(x / pow10<uint64_t>[n - 4]);\n        w4<n - 4>(x % pow10<uint64_t>[n\
    \ - 4]);\n    }\n    void write(unsigned_integral auto x) {\n        write<4>(x);\n\
    \    }\n    void write(__uint128_t x) {\n        if (x < pow10<__uint128_t>[16])\
    \ {\n            write(static_cast<uint64_t>(x));\n        } else if (x < pow10<__uint128_t>[32])\
    \ {\n            write(static_cast<uint64_t>(x / pow10<__uint128_t>[16]));\n \
    \           w4<16>(static_cast<uint64_t>(x % pow10<__uint128_t>[16]));\n     \
    \   } else {\n            write(static_cast<uint64_t>(x / pow10<__uint128_t>[32]));\n\
    \            x %= pow10<__uint128_t>[32];\n            w4<16>(static_cast<uint64_t>(x\
    \ / pow10<__uint128_t>[16]));\n            w4<16>(static_cast<uint64_t>(x % pow10<__uint128_t>[16]));\n\
    \        }\n    }\n} Write;\n\ntemplate<typename T, typename... Ts>\nvoid Writeln(T\
    \ &&x, Ts &&... xs) {\n    Write.ln(x, std::forward<Ts>(xs)...);\n}\n\n} // namespace\
    \ fast_io\n"
  code: "#pragma once\n#include <algorithm>\n#include <array>\n#include <concepts>\n\
    #include <cstring>\n#include <filesystem>\n#include <iostream>\n#include <vector>\n\
    using namespace std;\n\n// https://judge.yosupo.jp/submission/212769\nnamespace\
    \ fastio {\n\nstatic constexpr int buf_size = 1 << 21;\n\ninline struct fast_read\
    \ {\n    fast_read() : fast_read(stdin) {}\n    fast_read(const filesystem::path\
    \ &p) : fast_read(fopen(p.c_str(), \"r\")) {}\n    fast_read(FILE *_stream) :\
    \ stream(_stream), start(buf.data()), end(start + buf_size), ptr(end) { load();\
    \ }\n    ~fast_read() { if (stream != stdin) fclose(stream); }\n    fast_read(const\
    \ fast_read &) = default;\n    fast_read &operator=(const fast_read &) = default;\n\
    \    template<unsigned_integral T>\n    void operator()(T &x) {\n        skip_space();\n\
    \        load<64>();\n        parse(x);\n    }\n    template<signed_integral T>\n\
    \    void operator()(T &x) {\n        skip_space();\n        load<64>();\n   \
    \     make_unsigned_t<T> y;\n        if (*ptr == '-') {\n            ptr++;\n\
    \            parse(y);\n            y = -y;\n        } else {\n            parse(y);\n\
    \        }\n        x = y;\n    }\n    void operator()(char &c) {\n        skip_space();\n\
    \        load<64>();\n        c = *ptr++;\n    }\n    void operator()(string &s)\
    \ {\n        s = \"\";\n        skip_space();\n        load<64>();\n        while\
    \ (*ptr > ' ' && *ptr != '\\0') {\n            s.push_back(*ptr++);\n        }\n\
    \        ptr++;\n    }\n    template<typename T>\n    void operator()(vector<T>\
    \ &v) {\n        for (auto &e : v) (*this)(e);\n    }\n    template<typename...\
    \ Ts> requires(sizeof...(Ts) != 1)\n    void operator() (Ts &... xs) {\n     \
    \   ((*this)(xs), ...);\n    }\nprivate:\n    FILE *stream;\n    array<char, buf_size>\
    \ buf{};\n    char *start, *end, *ptr;\n    void skip_space() {\n        while\
    \ (*ptr <= ' ') ptr++;\n    }\n    template<int n = 0> void load() {\n       \
    \ const auto i = end - ptr;\n        if (i <= n) {\n            ignore = fread(copy_n(ptr,\
    \ i, start), 1, buf_size - i, stream);\n            ptr = start;\n        }\n\
    \    }\n    template<unsigned_integral T>\n    void parse(T &x) {\n        typename\
    \ common_type<T, uint64_t>::type y = 0;\n        while (true) {\n            uint64_t\
    \ z;\n            memcpy(&z, ptr, 8);\n            if (!((z -= 0x3030303030303030)\
    \ & 0x8080808080808080)) {\n                z = (z * 10 + (z >> 8)) & 0xff00ff00ff00ff;\n\
    \                z = (z * 100 + (z >> 16)) & 0xffff0000ffff;\n               \
    \ z = (z * 10000 + (z >> 32)) & 0xffffffff;\n                y = 100000000 * y\
    \ + z;\n                ptr += 8;\n            } else {\n                break;\n\
    \            }\n        }\n        {\n            uint32_t z;\n            memcpy(&z,\
    \ ptr, 4);\n            if (!((z -= 0x30303030) & 0x80808080)) {\n           \
    \     z = (z * 10 + (z >> 8)) & 0xff00ff;\n                z = (z * 100 + (z >>\
    \ 16)) & 0xffff;\n                y = 10000 * y + z;\n                ptr += 4;\n\
    \            }\n        }\n        {\n            uint16_t z;\n            memcpy(&z,\
    \ ptr, 2);\n            if (!((z -= 0x3030) & 0x8080)) {\n                z =\
    \ (z * 10 + (z >> 8)) & 0xff;\n                y = 100 * y + z;\n            \
    \    ptr += 2;\n            }\n        }\n        if (' ' < *ptr) {\n        \
    \    y *= 10;\n            y += *ptr++ - '0';\n        }\n        ptr++;\n   \
    \     x = static_cast<T>(y);\n    }\n} Read;\n\ninline struct fast_write {\n \
    \   fast_write() : fast_write(stdout) {}\n    fast_write(const filesystem::path\
    \ &p) : fast_write(fopen(p.c_str(), \"w\")) {}\n    fast_write(FILE *_stream)\
    \ : stream(_stream), start(buf.data()), end(start + buf_size), ptr(start) {}\n\
    \    ~fast_write() {\n        flush();\n        if (stream != stdout) fclose(stream);\n\
    \    }\n    fast_write(const fast_write &) = default;\n    fast_write &operator=(const\
    \ fast_write &) = default;\n    template<unsigned_integral T>\n    void operator()(T\
    \ x) {\n        flush<digits<T>>();\n        write(x);\n    }\n    template<signed_integral\
    \ T>\n    void operator()(T x) {\n        flush<1 + digits<T>>();\n        make_unsigned_t<T>\
    \ y = x;\n        if (x < 0) {\n            *ptr++ = '-';\n            write(static_cast<make_unsigned_t<T>>(-y));\n\
    \        } else {\n            write(y);\n        }\n    }\n    void operator()(char\
    \ c) {\n        flush<1>();\n        *ptr++ = c;\n    }\n    void operator()(string_view\
    \ s) {\n        while (!s.empty()) {\n            flush<0>();\n            const\
    \ auto n = min(ssize(s), end - ptr);\n            if (n == buf_size) {\n     \
    \           fwrite(s.data(), 1, buf_size, stream);\n            } else {\n   \
    \             ptr = copy_n(s.data(), n, ptr);\n            }\n            s.remove_prefix(n);\n\
    \        }\n        flush<0>();\n    }\n    void operator()(string s) {\n    \
    \    (*this)(string_view(s));\n    }\n    void operator()(const char* s) {\n \
    \       (*this)(string_view(s));\n    }\n    template<typename T>\n    void operator()(vector<T>\
    \ v) {\n        int n = v.size();\n        for (int i = 0; i < n; i++) {\n   \
    \         (*this)(v[i]);\n            if (i < n - 1) (*this)(' ');\n        }\n\
    \    }\n    template<typename... Ts>\n    requires(sizeof...(Ts) != 1)\n    void\
    \ operator()(Ts &&...xs) {\n        ((*this)(std::forward<Ts>(xs)), ...);\n  \
    \  }\n    template<char End = '\\n', char Sep = ' ', typename T, typename... Ts>\n\
    \    void ln(T &&x, Ts &&...xs) {\n        (*this)(std::forward<T>(x));\n    \
    \    if constexpr (sizeof...(Ts) == 0) {\n            *ptr++ = End;\n        }\
    \ else {\n            *ptr++ = Sep;\n            ln<End, Sep>(std::forward<Ts>(xs)...);\n\
    \        }\n    }\nprivate:\n    FILE *stream;\n    array<char, buf_size> buf{};\n\
    \    char *start, *end, *ptr;\n    template<typename T>\n    static constexpr\
    \ int digits = numeric_limits<T>::digits10 + 1;\n    template<typename T>\n  \
    \  static constexpr auto pow10 = [] {\n        array<T, digits<T>> res;\n    \
    \    res[0] = 1;\n        for (int i = 1; i < digits<T>; i++) {\n            res[i]\
    \ = 10 * res[i - 1];\n        }\n        return res;\n    } ();\n    static constexpr\
    \ auto lut = [] {\n        array<char, 40000> res;\n        char *p = res.data();\n\
    \        char a, b, c, d;\n        a = b = c = d = '0';\n        do {\n      \
    \      *p++ = a;\n            *p++ = b;\n            *p++ = c;\n            *p++\
    \ = d;\n        } while (d++ < '9' || (d = '0', c++ < '9' || (c = '0', b++ < '9'\
    \ || (b = '0', a++ < '9'))));\n        return res;\n    } ();\n    template<int\
    \ n = buf_size>\n    void flush() {\n        if (end - ptr <= n) {\n         \
    \   fwrite(start, 1, ptr - start, stream);\n            ptr = start;\n       \
    \ }\n    }\n    template<int n = 4>\n    void le4(uint64_t x) {\n        if constexpr\
    \ (1 < n) {\n            if (x < pow10<uint64_t>[n - 1]) {\n                le4<n\
    \ - 1>(x);\n                return;\n            }\n        }\n        ptr = copy_n(&lut[x\
    \ * 4 + (4 - n)], n, ptr);\n    }\n    template<int n>\n    void w4(uint64_t x)\
    \ {\n        if constexpr (0 < n) {\n            ptr = copy_n(&lut[x / pow10<uint64_t>[n\
    \ - 4] * 4], 4, ptr);\n            w4<n - 4>(x % pow10<uint64_t>[n - 4]);\n  \
    \      }\n    }\n    template<int n>\n    void write(uint64_t x) {\n        if\
    \ constexpr (n < digits<uint64_t>) {\n            if (pow10<uint64_t>[n] <= static_cast<uint64_t>(x))\
    \ {\n                write<n + 4>(x);\n                return;\n            }\n\
    \        }\n        le4(x / pow10<uint64_t>[n - 4]);\n        w4<n - 4>(x % pow10<uint64_t>[n\
    \ - 4]);\n    }\n    void write(unsigned_integral auto x) {\n        write<4>(x);\n\
    \    }\n    void write(__uint128_t x) {\n        if (x < pow10<__uint128_t>[16])\
    \ {\n            write(static_cast<uint64_t>(x));\n        } else if (x < pow10<__uint128_t>[32])\
    \ {\n            write(static_cast<uint64_t>(x / pow10<__uint128_t>[16]));\n \
    \           w4<16>(static_cast<uint64_t>(x % pow10<__uint128_t>[16]));\n     \
    \   } else {\n            write(static_cast<uint64_t>(x / pow10<__uint128_t>[32]));\n\
    \            x %= pow10<__uint128_t>[32];\n            w4<16>(static_cast<uint64_t>(x\
    \ / pow10<__uint128_t>[16]));\n            w4<16>(static_cast<uint64_t>(x % pow10<__uint128_t>[16]));\n\
    \        }\n    }\n} Write;\n\ntemplate<typename T, typename... Ts>\nvoid Writeln(T\
    \ &&x, Ts &&... xs) {\n    Write.ln(x, std::forward<Ts>(xs)...);\n}\n\n} // namespace\
    \ fast_io"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/fast_io.hpp
  requiredBy: []
  timestamp: '2026-09-11 09:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/fast_io.hpp
layout: document
redirect_from:
- /library/src/misc/fast_io.hpp
- /library/src/misc/fast_io.hpp.html
title: src/misc/fast_io.hpp
---
