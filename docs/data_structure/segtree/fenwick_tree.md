# Fenwick Tree

BIT.

## Constructor
```
fenwick_tree<Monoid> fw(int n)
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
