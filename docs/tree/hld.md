# Heavy Light Decomposition

木に対するパスクエリを行う. 基本的な分解等は `hld_template` で行う. それ以外については以下に書いてある通りに, クエリの内容によって使い分ける.

- `hld_static_commutative` : 更新なし，可換クエリ
- `hld_static_noncommutative` : 更新なし，非可換クエリ
- `hld_point_update_commutative` : 一点更新，可換クエリ
- `hld_point_update_non_commutative` : 一点更新，非可換クエリ
- `hld_path_update_commutative` : パス更新，可換クエリ
- `hld_path_update_non_commutative` : パス更新，非可換クエリ

## Constructor
```
heavy_light_decomposition<Monoid> G(int n, bool e, int r)
```
- 頂点数 `n` の木を HL 分解する
- `e` を `false` にすると頂点クエリに, `false` にすると辺クエリに応えられる
- `r` は指定しなければ $0$ が入る
- モノイド定義する必要がある
    - モノイドの内部で型 `S`, 二項演算 `op`, 単位元 `e` を定義する必要がある
- `path_update` の場合は遅延セグ木と同様に作用素の型 `F`, 合成 `comp`, 恒等写像 `id`, 作用 `mapping` を定義する必要がある
- 計算量は $O(n)$

## add_edge
```
void add_edge(int u, int v, S w)
```
- 頂点 `u` と頂点 `v` を結ぶ重み `w` の辺を追加する
- 重みがいらないときは `add_edge(u, v)` でよい
- 計算量は $O(1)$

## set
```
void set(int u, S w)
void set(int u, int v, S w)
```
- 頂点 `u` の重みを `w` に変更する $O(\log n)$
- 頂点 `u` と頂点 `v` を結ぶ辺の重みを `w` に変更する $O(\log n)$

## apply
```
void apply(int u, int v, F f)
```
- 頂点 `u` から頂点 `v` への単純パス上の頂点 / 辺に `f` を作用させる
- 計算量は $O(\log n)$

## get
```
S get(int u)
S get(int u, int v)
```
- 頂点 `u` の重みを `w` を返す
- 頂点 `u` と頂点 `v` を結ぶ辺の重みを返す
- 計算量は `path_update` なら $O(\log n)$, それ以外なら $O(1)$

## prod
```
S set(int u, int v)
```
- 頂点 `u` から頂点 `v` への単純パス上の頂点 / 辺の総積を（この向きで）取得する
- 計算量は $O(f(n)\log n)$ （ $f(n)$ は区間取得の計算量 / `static` の場合は $O(1)$, `update` の場合は $O(\log n)$ ）
