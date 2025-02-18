# top_k_set

整数の集合の下から $K$ 個の値を管理する `set`. 

## Constructor
```
top_k_set<T1, T2, Compare> S(int K)
```
- `top_k_set` を作る
- `T1` は要素の型
- `T2` は総和の型, 指定しなければ `long long`
- `Compare` は比較関数, 指定しなければ `less<T1>`
    - 降順管理にしたいときは `greater<T1>` にすればよい

## insert
```
void insert(T1 x)
```
- $S$ に $x$ を挿入する
- 計算量は $O(\log \lvert S \rvert)$

## erase
```
void erase(T1 x)
```
- $S$ から $x$ を削除する
- $x \in S$ である必要がある
- 計算量は $O(\log \lvert S \rvert)$

## kth_val
```
T1 kth_val()
```
- $S$ の小さい方から $K$ 番目を返す
- 計算量は $O(1)$

## sum
```
T2 sum()
```
- $S$ の小さい方から $K$ 個の和を返す
- 計算量は $O(1)$

# verify
- https://atcoder.jp/contests/abc234/submissions/62880056
- https://atcoder.jp/contests/abc281/submissions/62879934