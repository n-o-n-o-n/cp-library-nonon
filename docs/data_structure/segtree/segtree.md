# Segtree

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

## prod
```
S set(int l, int r)
```
- 開区間 $[l, r)$ に対する総積を計算する
- 計算量は $O(\log n)$
