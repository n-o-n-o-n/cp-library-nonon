#pragma once
#include <algorithm>
#include <array>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <vector>
using namespace std;

// https://judge.yosupo.jp/submission/212769
namespace fastio {

static constexpr int buf_size = 1 << 17;

struct fast_read {
    fast_read() : fast_read(stdin) {}
    fast_read(const filesystem::path &p) : fast_read(fopen(p.c_str(), "r")) {}
    fast_read(FILE *_stream) : stream(_stream), start(buf.data()), end(start + buf_size), ptr(end) { load(); }
    ~fast_read() { if (stream != stdin) fclose(stream); }
    fast_read(const fast_read &) = default;
    fast_read &operator=(const fast_read &) = default;
    template<unsigned_integral T>
    void operator()(T &x) {
        skip_space();
        load<64>();
        parse(x);
    }
    template<signed_integral T>
    void operator()(T &x) {
        skip_space();
        load<64>();
        make_unsigned_t<T> y;
        if (*ptr == '-') {
            ptr++;
            parse(y);
            y = -y;
        } else {
            parse(y);
        }
        x = y;
    }
    void operator()(char &c) {
        skip_space();
        load<64>();
        c = *ptr++;
    }
    void operator()(string &s) {
        s = "";
        skip_space();
        load<64>();
        while (*ptr > ' ' && *ptr != '\0') {
            s.push_back(*ptr++);
        }
        ptr++;
    }
    template<typename T>
    void operator()(vector<T> &v) {
        for (auto &e : v) (*this)(e);
    }
    template<typename... Ts> requires(sizeof...(Ts) != 1)
    void operator() (Ts &... xs) {
        ((*this)(xs), ...);
    }
private:
    FILE *stream;
    array<char, buf_size> buf{};
    char *start, *end, *ptr;
    void skip_space() {
        while (*ptr <= ' ') ptr++;
    }
    template<int n = 0> void load() {
        const auto i = end - ptr;
        if (i <= n) {
            ignore = fread(copy_n(ptr, i, start), 1, buf_size - i, stream);
            ptr = start;
        }
    }
    template<unsigned_integral T>
    void parse(T &x) {
        typename common_type<T, uint64_t>::type y = 0;
        while (true) {
            uint64_t z;
            memcpy(&z, ptr, 8);
            if (!((z -= 0x3030303030303030) & 0x8080808080808080)) {
                z = (z * 10 + (z >> 8)) & 0xff00ff00ff00ff;
                z = (z * 100 + (z >> 16)) & 0xffff0000ffff;
                z = (z * 10000 + (z >> 32)) & 0xffffffff;
                y = 100000000 * y + z;
                ptr += 8;
            } else {
                break;
            }
        }
        {
            uint32_t z;
            memcpy(&z, ptr, 4);
            if (!((z -= 0x30303030) & 0x80808080)) {
                z = (z * 10 + (z >> 8)) & 0xff00ff;
                z = (z * 100 + (z >> 16)) & 0xffff;
                y = 10000 * y + z;
                ptr += 4;
            }
        }
        {
            uint16_t z;
            memcpy(&z, ptr, 2);
            if (!((z -= 0x3030) & 0x8080)) {
                z = (z * 10 + (z >> 8)) & 0xff;
                y = 100 * y + z;
                ptr += 2;
            }
        }
        if (' ' < *ptr) {
            y *= 10;
            y += *ptr++ - '0';
        }
        ptr++;
        x = static_cast<T>(y);
    }
} Read;

struct fast_write {
    fast_write() : fast_write(stdout) {}
    fast_write(const filesystem::path &p) : fast_write(fopen(p.c_str(), "w")) {}
    fast_write(FILE *_stream) : stream(_stream), start(buf.data()), end(start + buf_size), ptr(start) {}
    ~fast_write() {
        flush();
        if (stream != stdout) fclose(stream);
    }
    fast_write(const fast_write &) = default;
    fast_write &operator=(const fast_write &) = default;
    template<unsigned_integral T>
    void operator()(T x) {
        flush<digits<T>>();
        write(x);
    }
    template<signed_integral T>
    void operator()(T x) {
        flush<1 + digits<T>>();
        make_unsigned_t<T> y = x;
        if (x < 0) {
            *ptr++ = '-';
            write(static_cast<make_unsigned_t<T>>(-y));
        } else {
            write(y);
        }
    }
    void operator()(char c) {
        flush<1>();
        *ptr++ = c;
    }
    void operator()(string_view s) {
        while (!s.empty()) {
            flush<0>();
            const auto n = min(ssize(s), end - ptr);
            if (n == buf_size) {
                fwrite(s.data(), 1, buf_size, stream);
            } else {
                ptr = copy_n(s.data(), n, ptr);
            }
            s.remove_prefix(n);
        }
        flush<0>();
    }
    template<typename T>
    void operator()(vector<T> v) {
        int n = v.size();
        for (int i = 0; i < n; i++) {
            (*this)(v[i]);
            if (i < n - 1) (*this)(' ');
        }
    }
    template<typename T, typename... Ts>
    void operator()(T &&x, Ts &&...xs) {
        (*this)(forward<T>(x));
        (*this)(forward<Ts>(xs)...);
    }
    template<char End = '\n', char Sep = ' ', typename T, typename... Ts>
    void ln(T &&x, Ts &&...xs) {
        (*this)(forward<T>(x));
        if constexpr (sizeof...(Ts) == 0) {
            *ptr++ = End;
        } else {
            *ptr++ = Sep;
            ln<End, Sep>(forward<Ts>(xs)...);
        }
    }
private:
    FILE *stream;
    array<char, buf_size> buf{};
    char *start, *end, *ptr;
    template<typename T>
    static constexpr int digits = numeric_limits<T>::digits10 + 1;
    template<typename T>
    static constexpr auto pow10 = [] {
        array<T, digits<T>> res;
        res[0] = 1;
        for (int i = 1; i < digits<T>; i++) {
            res[i] = 10 * res[i - 1];
        }
        return res;
    } ();
    static constexpr auto lut = [] {
        array<char, 40000> res;
        char *p = res.data();
        char a, b, c, d;
        a = b = c = d = '0';
        do {
            *p++ = a;
            *p++ = b;
            *p++ = c;
            *p++ = d;
        } while (d++ < '9' || (d = '0', c++ < '9' || (c = '0', b++ < '9' || (b = '0', a++ < '9'))));
        return res;
    } ();
    template<int n = buf_size>
    void flush() {
        if (end - ptr <= n) {
            fwrite(start, 1, ptr - start, stream);
            ptr = start;
        }
    }
    template<int n = 4>
    void le4(uint64_t x) {
        if constexpr (1 < n) {
            if (x < pow10<uint64_t>[n - 1]) {
                le4<n - 1>(x);
                return;
            }
        }
        ptr = copy_n(&lut[x * 4 + (4 - n)], n, ptr);
    }
    template<int n>
    void w4(uint64_t x) {
        if constexpr (0 < n) {
            ptr = copy_n(&lut[x / pow10<uint64_t>[n - 4] * 4], 4, ptr);
            w4<n - 4>(x % pow10<uint64_t>[n - 4]);
        }
    }
    template<int n>
    void write(uint64_t x) {
        if constexpr (n < digits<uint64_t>) {
            if (pow10<uint64_t>[n] <= static_cast<uint64_t>(x)) {
                write<n + 4>(x);
                return;
            }
        }
        le4(x / pow10<uint64_t>[n - 4]);
        w4<n - 4>(x % pow10<uint64_t>[n - 4]);
    }
    void write(unsigned_integral auto x) {
        write<4>(x);
    }
    void write(__uint128_t x) {
        if (x < pow10<__uint128_t>[16]) {
            write(static_cast<uint64_t>(x));
        } else if (x < pow10<__uint128_t>[32]) {
            write(static_cast<uint64_t>(x / pow10<__uint128_t>[16]));
            w4<16>(static_cast<uint64_t>(x % pow10<__uint128_t>[16]));
        } else {
            write(static_cast<uint64_t>(x / pow10<__uint128_t>[32]));
            x %= pow10<__uint128_t>[32];
            w4<16>(static_cast<uint64_t>(x / pow10<__uint128_t>[16]));
            w4<16>(static_cast<uint64_t>(x % pow10<__uint128_t>[16]));
        }
    }
} Write;

template<typename T, typename... Ts>
void Writeln(T &&x, Ts &&... xs) {
    Write.ln(x, forward<Ts>(xs)...);
}

} // namespace fast_io