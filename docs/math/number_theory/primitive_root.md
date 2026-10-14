# Primitive Root
```
long long primitive_root(long long m)
```

- $m$ の原始根を $1$ つ返す
- 計算量は $O(n^{1/4})$
    - いくつかの NTT-Friendly 素数は埋め込んであるので $O(1)$ (詳細はコード参照)
