# discrete_logarithm

離散対数問題を解く.

## function
```
discrete_logarithm<ActSet>::solve(F f, S s, S t, long long p, H h)
```
- モノイド $F$ が $S$ に作用しているとし, $f^k(s)=t$ を満たす最小の $k$ を返す
    - 存在しない場合は $-1$
- $p$ は $\lvert F \rvert$
- $h$ は $F \to$ `long long` のハッシュ関数
- 計算量は $O(\sqrt p)$
    - `unordered_set` を `set` に変えて $\log$ がつく

# Reference
- https://maspypy.com/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89%E4%BD%9C%E7%94%A8%E3%81%AB%E9%96%A2%E3%81%99%E3%82%8B%E9%9B%A2%E6%95%A3%E5%AF%BE%E6%95%B0%E5%95%8F%E9%A1%8C 

# verify
- https://atcoder.jp/contests/abc270/submissions/62690414