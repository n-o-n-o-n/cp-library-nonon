# Segtree

領域木．二次元領域に対して一点更新と矩形領域に対する総積の取得を行う. 更新を行う点が予め分かっている必要がある. 

## Constructor
```
rage_tree<Monoid, T> rt
```
- 領域木を作る
- 可換モノイド定義する必要がある
    - モノイドの内部で型 `S`, 二項演算 `op`, 単位元 `e` を定義する必要がある
- `T` は座標の型
    - `int`, `long`, `long long` のいずれかが想定される
- 計算量は $O(1)$

## add_point
```
void add_point(T x, T y, S w)
```
- 点 $(x,y)$ に重み $w$ の点を追加する
    - $w$ を指定しない場合はモノイドの単位元が入る
- `add_point` が呼ばれる時点で `set`, `get`, `prod` のいずれも呼ばれていない必要がある
- 計算量は $O(1)$

## set
```
void set(T x, T y, S w)
```
- 点 $(x,y)$ の重みを $w$ に変更する
    - この点は `add_point` で追加されている必要がある
- 計算量は $O((\log n)^2)$

## get
```
void get(T x, T y)
```
- 点 $(x,y)$ の重みを返す
- この点が `add_point` で追加されていない場合はモノイドの単位元が返る
- 計算量は $O(\log n)$

## prod
```
S prod(T xl, T yl, T xr, T yr)
```
- 矩形領域 $[xl,xr)\times[yl,yr)$ に対する総積を計算する
- 計算量は $O((\log n)^2)$

# verify
- https://judge.yosupo.jp/submission/253420
- https://atcoder.jp/contests/abc339/submissions/60287058
