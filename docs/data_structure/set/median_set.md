# median_set

整数の多重集合の中央値を管理する `set`. ついでに次の問題も解く:

> 集合の要素に $\pm 1$ する操作がコスト $1$ で行える. 
> 要素を全て一致させるための最小コストはいくつか.


## Constructor
```
median_set<T1, T2> S
```
- `median_set` を作る
- `T1` は要素の型
- `T2` は総和の型, 指定しなければ `long long`

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

## median
```
T1 median()
```
- $S$ の中央値を返す
- 要素数が偶数の場合は中央値の小さい方が返る
- 計算量は $O(1)$

## min_cost
```
T2 min_cost()
```
- 上に載せた問題の答えを返す
- 計算量は $O(1)$

# verify
- https://qoj.ac/submission/904337 