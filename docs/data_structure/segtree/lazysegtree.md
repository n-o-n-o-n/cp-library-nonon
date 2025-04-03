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

## get
```
S get(int p)
```
- $p$ 番目の要素を返す
- 計算量は $O(\log n)$

## prod
```
S prod(int l, int r)
```
- 開区間 $[l, r)$ に対する総積を計算する
- 計算量は $O(\log n)$

## max_right
```
int max_right(int l, const C &check, int r)
```
- 右側へのセグ木上の二分探索を行う
- $check(\prod_{l \leq i \lt k})$ なる $k$ の最大値を $r^\prime$ として $\min(r, r^\prime)$ が返る
- $check(e)$ が `true` である必要がある
- $r$ は指定しなければ $n$
- 計算量は $O(\log n)$

## min_left
```
int min_left(int r, const C &check, int l)
```
- 左側へのセグ木上の二分探索を行う
- $check(\prod_{k \leq i \lt r})$ なる $k$ の最小値を $l^\prime$ として $\max(l, l^\prime)$ が返る
- $check(e)$ が `true` である必要がある
- $l$ は指定しなければ $0$
- 計算量は $O(\log n)$