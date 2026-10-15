---
title: segtree
documentation_of: //src/data_structure/segtree/segtree.hpp
---

セグ木. 

## Constructor
```
segtree<Monoid> seg(int n)
```
- 長さ $n$ のセグ木を作る
- モノイド定義する必要がある
    - モノイドの内部で型 `S`, 二項演算 `op`, 単位元 `e` を定義する必要がある
- 計算量は $O(n)$

```
segtree<Monoid> seg(vector<S> v)
```
- `v` で初期化セグ木を作る
- 長さで初期化して 1 つずつ `set` するよりも速い
- 計算量は $O(n)$

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
- 計算量は $O(1)$

## prod
```
S set(int l, int r)
```
- 開区間 $[l, r)$ に対する総積を計算する
- 計算量は $O(\log n)$

## all_prod
```
S all_prod()
```
- 全体の総積を返す
- 計算量は $O(1)$

## max_right
```
int max_right(int l, const C &check)
```
- 右側へのセグ木上の二分探索を行う
- $\text{check}(\text{prod}(l, r))$ が `true` となる $r$ の最大値が返る
- $\text{check}(e)$ が `true` である必要がある
- 計算量は $O(\log n)$

## min_left
```
int min_left(int r, const C &check)
```
- 左側へのセグ木上の二分探索を行う
- $\text{check}(\text{prod}(l, r))$ が `true` となる $l$ の最小値が返る
- $\text{check}(e)$ が `true` である必要がある
- 計算量は $O(\log n)$