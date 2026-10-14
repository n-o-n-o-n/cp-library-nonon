# Extended Gcd
```
T extended_gcd(T a, T b, T &x, T &y)
```

- $ax+by = \gcd(a,b)$ なる $x,y$ を求め, $\gcd(a,b)$ を返す
    - 特に $\lvert x \rvert + \lvert y \rvert$ が最小のもの, さらにそのようなものが複数あれば $x$ が最小のものが返る
- 計算量は $O(\log (a+b))$
