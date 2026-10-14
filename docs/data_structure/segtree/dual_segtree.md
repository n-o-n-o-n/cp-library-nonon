# Dual Segtree

双対セグ木. 区間作用と一点更新をする. 遅延セグ木よりも定数倍が良い.

## Constructor
```
dual_segtree<ActSet> seg(int n)
```
- 長さ $n$ の双対セグ木を作る
- 作用素つきの集合 `ActSet` を定義する必要がある
    - `ActSet` の内部で集合の型 `S`, 作用素の型 `F`, 合成 `comp`, 恒等写像 `id`, 作用 `map` を定義する必要がある
- 計算量は $O(n)$

```
dual_segtree<ActSet> seg(vector<S> v)
```
- `v` で初期化セグ木を作る
- 長さで初期化して 1 つずつ `set` するよりも速い
- 計算量は $O(n)$

## init
```
void init(vector<S> v)
```
- `seg = dual_segtree<ActSet>(v)` と同じ

## set
```
void set(int p, S x)
```
- $p$ 番目の要素を $x$ に変更する
- 計算量は $O(1)$

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
