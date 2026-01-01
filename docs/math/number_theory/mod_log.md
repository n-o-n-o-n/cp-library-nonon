# Mod Log
```
int mod_log(int a, int b, int p)
```

- $a^k \equiv b \;\bmod p$ をみたす最小の非負整数 $k$ を返す
    - 存在しない場合は $-1$ が返る
- 計算量は $O(\sqrt{p})$
