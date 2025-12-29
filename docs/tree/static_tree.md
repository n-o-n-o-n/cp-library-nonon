# Static Tree
単位重み付きの木に対する諸々を一括で扱うライブラリ. 

## Constructor
```
static_tree T(int n)
```
- $n$ 頂点の木を作る
- 構築は $O(n)$
- 根を指定したい場合は `T(int n, int r)` で宣言する

## add_edge
```
void add_edge(int u, int v)
```
- 頂点 $u$ と頂点 $v$ を結ぶ辺を追加する
- 計算量は $O(1)$

## lca
```
int lca(int u, int v, int r)
```
- 頂点 $r$ を根としたときの LCA を返す
- $r$ は指定しなければ $T$ の根
- 計算量は $O(1)$

## dist
```
int dist(int u, int v)
```
- 頂点 $u$ と頂点 $v$ の距離を返す
- 計算量は $O(1)$

## jump
```
int jump(int u, int v, int k)
```
- 頂点 $u$ から頂点 $v$ の方向に $k$ 回進んだ頂点を返す
    - 存在しない場合は $-1$ が返る
- 計算量は $O(\log n)$

## auxiliary_tree
```
vector<pair<int, int>> auxiliary_tree(vector<int> vs)
```
- 与えられた頂点たちと, それらの LCA 全体からなる木の辺集合を返す
- 計算量は, 引数のサイズを $k$ として $O(k \log k)$