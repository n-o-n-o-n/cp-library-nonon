# Mod Inv
```
long long mod_inv(long long a, long long mod)
```

- $ax \equiv 1 \;\bmod mod$ なる $x \in [0,mod)$ を返す
    - $\gcd(a, mod) = 1$ が要求される
- 計算量は $O(\log mod)$
