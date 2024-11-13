# Level Ancestor

根付き木に対して
- 頂点 $u$ から親方向に $k$ 回たどった先の頂点番号はいくつか

というクエリに答える．オンラインは知らないのでオフラインだけ.

## Constructor
```
level_ancestor(int n)
```
- 頂点数 `n` の木を用意する

## add_edge
```
void add_edge(int u, int v)
```
- 頂点 `u` と頂点 `v` を結ぶ辺を追加する

## add_query
```
void add_query(int u, int k)
```
- 「頂点 `u` から親方向に `k` たどった先の頂点番号はいくつか」というクエリを追加する
- 答えが存在しない場合は `-1` が返される

## build
```
vector<int> build(int root = 0)
```
- 根を `root` として各クエリを処理する
- 計算量は $O(n+q)$
