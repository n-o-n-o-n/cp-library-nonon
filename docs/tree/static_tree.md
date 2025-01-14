# Static Tree
単位重み付きの木に対する三種の神器 LCA, dist, jump を一括で扱うライブラリ. 

## Constructor
```
static_tree T(int n)
```
- `n` 頂点の木を作る
- 構築に $O(n \log n)$ かかる.

## add_edge
```
void add_edge(int u, int v)
```
- 頂点 `u` と頂点 `v` を結ぶ辺を追加する
- 計算量は $O(1)$

## lca
```
int lca(int u, int v, int r)
```
- 頂点 `r` を根としたときの LCA を返す
- `r` は指定しなければ `0`
- 計算量は $O(1)$

## dist
```
int dist(int u, int v)
```
- 頂点 `u` と頂点 `v` の距離を返す
- 計算量は $O(1)$

## jump
```
int jump(int u, int v, int k)
```
- 頂点 `u` から頂点 `v` の方向に `k` 回進んだ頂点を返す
- 計算量は $O(\log n)$

# Reference
- https://x.com/noshi91/status/1336562191080726528

# verify
- LCA: https://judge.yosupo.jp/submission/261568
- jump: https://judge.yosupo.jp/submission/261567