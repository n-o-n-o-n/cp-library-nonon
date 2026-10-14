# Bit Segtree

01 列に対するクエリを高速に行う. $1/64$ の高速化をしているが (手元計測で) fenwick tree を使ったときとそんなに変わらない (悲しい).

「Bit Segtree」という命名は適当. 関数名は `bitset` に合わせてある. 

計算量は書いてあるものに $1/64$ される.

## Constructor
```
bit_segtree bs(int n)
```
- 長さ $n$ の Bit セグ木を作る
- 計算量は $O(n)$

## set
```
void set(int p)
```
- $p$ 番目の要素を $1$ に変更する
- 計算量は $O(\log n)$

## reset
```
void reset(int p)
```
- $p$ 番目の要素を $0$ に変更する
- 計算量は $O(\log n)$

## flip
```
void flip(int p)
```
- $p$ 番目の要素を flip する
- 計算量は $O(\log n)$

## test
```
bool test(int p)
```
- $p$ 番目の要素を返す
- 計算量は $O(1)$

## count
```
int count(int l, int r)
```
- 半開区間 $[l, r)$ に対する総和を計算する
- 計算量は $O(\log n)$

## all
```
bool all(int l, int r)
```
- 開区間 $[l, r)$ 内の要素が全て $1$ であるかをチェックする
- 計算量は $O(\log n)$

## any
```
bool any(int l, int r)
```
- 開区間 $[l, r)$ 内の要素のいずれかが $1$ であるかをチェックする
- 計算量は $O(\log n)$

## none
```
bool none(int l, int r)
```
- 開区間 $[l, r)$ 内の要素が全て $0$ であるかをチェックする
- 計算量は $O(\log n)$

## lower_bound
```
int lower_bound(int x)
```
- $\text{count}(0, r) < x$ なる最大の $r$ を返す
- $\text{count}(0, n) < x$ のときは $n$ が返る
- 計算量は $O(\log n)$