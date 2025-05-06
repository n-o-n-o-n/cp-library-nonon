# Dynamic Segtree

動的セグ木. 

## Constructor
```
dynamic_segtree<Monoid, T = int> seg(T n)
```
- 長さ $n$ の動的セグ木を作る
- モノイド定義する必要がある
    - モノイドの内部で型 `S`, 二項演算 `op`, 単位元 `e` を定義する必要がある
- `T` は index の型
- 計算量は $O(1)$

## set
```
void set(int p, S x)
```
- $p$ 番目の要素を $x$ に変更する
- 計算量は $O(\log n)$

## get
```
S get(int p)
```
- $p$ 番目の要素を返す
- 計算量は $O(\log n)$

## prod
```
S set(int l, int r)
```
- 半開区間 $[l, r)$ に対する総積を計算する
- 計算量は $O(\log n)$

## all_prod
```
S all_prod()
```
- 全体の総積を返す
- 計算量は $O(1)$
