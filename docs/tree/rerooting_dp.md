# 全方位木 DP

以下の擬似コードの木 DP を考える:

```
dfs(u):
    res = e
    for v in child(u):
        res = res * f(dfs(v))
    return g(res)
```
`dfs(0)`, `dfs(1)`, ..., `dfs(n)` を高速に求めるライブラリ. ここで, `f`, `g` はそれぞれ

- 辺を通る際の作用
- 頂点を通る際の作用

である. 例えば辺重み付き木において最遠頂点を求めるならば, `f` は辺の重みを加える関数, `g` はその値を返す関数となる.

## Constructor
```
rerootin_dp<Monoid> G(int n)
```
- `n` 頂点の木を構築する
- `Monoid` は可換である必要がある

## add_edge
```
void add_edge(int u, int v)
```
- 頂点 `u` と頂点 `v` を結ぶ辺を追加する
- `i` 回目に追加された辺を辺 $i$ とする

## run
```
run(vertex_apply, edge_apply)
```
- 全方位木 DP を実行する
- 上の疑似コードの `f`, `g` を, それぞれ `apply_edge`, `apply_vertex` としてラムダ式などで渡してあげる必要がある
    - `apply_vertex`, `edge_apply` はともに $S \times \mathbb{N} \to S$ であり, 頂点 $u$ を通る際の作用, 辺 $i$ を通る際の作用を表す
- 計算量は $O(N)$

# verify
- https://atcoder.jp/contests/dp/submissions/59707139 
- https://atcoder.jp/contests/abc348/submissions/59707754
- https://judge.yosupo.jp/submission/248692