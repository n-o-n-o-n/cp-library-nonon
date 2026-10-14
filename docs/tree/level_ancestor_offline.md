# Level Ancestor Offline
Level Ancestor をオフラインで解く.

## Constructor
```
level_ancestor T(int n)
```
- $n$ 頂点の木を作る

## add_edge
```
void add_edge(int u, int v)
```
- 頂点 $u$ と頂点 $v$ を結ぶ辺を追加する
- 計算量は $O(1)$

## lca
```
void add_query(int u, int k)
```
- 頂点 $u$ から根方向に $k$ 進んだ頂点を聞くクエリを投げる
    - 存在しなければ $-1$ が返る
- 計算量は $O(1)$

## solve
```
vector<int> solve(int r)
```
- $r$ を根として Level Ancestor を解く
- 計算量は, `add_query` を呼び出した回数を $q$ として $O(n+q)$
