# Garner
```
long long garner(const vector<long long> &rems, vector<long long> mods, long long mod)
```

- $\forall i = 1,2,\dots,n;\; X \equiv rem_i \; \bmod mods_i$ をみたす非負整数 $X$ のうち最小のものを $mod$ で割った余りを返す
    - 存在しない場合は $-1$ が返る
- 計算量は $O(n^2 + n \log \max_i mods_i)$
