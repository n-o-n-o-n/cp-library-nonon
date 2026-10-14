# Enumerate Quotients
```
vector<tuple<T, T, T>> enumerate_quotients(T n)
```
- $n$ の商を列挙する
- 返り値は $(l,r,m)$ の配列で $\forall m \in [l, r); \lfloor n/m \rfloor = q$ を満たすものが $l$ の昇順に並んだもの
- 計算量は $O(\sqrt{n})$
