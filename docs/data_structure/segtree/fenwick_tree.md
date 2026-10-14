# Fenwick Tree

BIT. 一般のアーベル群を載せたいときは `fenwick_tree_abelian_group.hpp` を include すると良い. 

## Constructor
```
fenwick_tree<T> fw(int n)
```
- 長さ $n$ の BIT を作る
- `T` は整数型である必要がある
- 計算量は $O(n)$

## add
```
void add(int p, T x)
```
- $p$ 番目の要素に $x$ を加算する
- 計算量は $O(\log n)$

## update
```
void update(int p, T x)
```
- $p$ 番目の要素を $x$ に変更する
- 計算量は $O(\log n)$

## sum
```
T sum(int l, int r)
```
- $l$ 番目の要素から $r-1$ 番目の要素までの総和を返す
- 計算量は $O(\log n)$

## lower_bound
```
int lower_bound(T x)
```
- $\text{sum}(0, r) < x$ なる最大の $r$ を返す
- $\text{sum}(0, n) < x$ のときは $n$ が返る
- 計算量は $O(\log n)$