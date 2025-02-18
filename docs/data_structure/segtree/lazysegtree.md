# Lazy Segtree

遅延セグ木. 

## Constructor
```
segtree<Monoid, Opeartor, mapping> seg(int n)
```
- 長さ $n$ の遅延セグ木を作る
- モノイド, 演算子, 作用を定義する必要がある
    - モノイドの内部で型 `S`, 二項演算 `op`, 単位元 `e` を定義する必要がある
    - 演算子の内部で型 `F`, 合成 `comp`, 恒等写像 `id` を定義する必要がある
    - `mapping` は $S \times F \to S$ の写像
- 計算量は $O(n)$

```
lazy_segtree<Monoid, Operator, mapping> seg(vector<S> v)
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

```
void set(vector<S> v)
```
- `seg` を `v` で初期化する
- `seg = lazy_segtree<Monoid, Operator, mapping>(v)` と同じ挙動をする（はず）

## apply
```
void apply(int l, int r, F f)
```
- 開区間 $[l, r)$ に対して $f$ を作用させる
- 計算量は $O(\log n)$

## prod
```
S prod(int l, int r)
```
- 開区間 $[l, r)$ に対する総積を計算する
- 計算量は $O(\log n)$
